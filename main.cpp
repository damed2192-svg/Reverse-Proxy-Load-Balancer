#include "core/Server.h"
#include "config/Config.h"
#include "utils/Logger.h"
#include "health/HealthChecker.h"

int main() {
    Logger::init(true);

    Config cfg;
    if (!cfg.load("configs/config.yaml")) {
        LOG_ERROR("Failed to load config");
        return 1;
    }

    LOG_INFO("Starting VPS Reverse Proxy on {}:{}", cfg.listen_address, cfg.listen_port);

    net::io_context ioc{std::thread::hardware_concurrency()};

    HealthChecker health(cfg, ioc);
    if (cfg.health_check_enabled) health.start();

    Server server(ioc, cfg);
    server.run();

    std::vector<std::thread> threads;
    for (unsigned i = 0; i < std::thread::hardware_concurrency(); ++i) {
        threads.emplace_back([&ioc] { ioc.run(); });
    }

    for (auto& t : threads) t.join();

    return 0;
}
