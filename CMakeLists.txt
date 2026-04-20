cmake_minimum_required(VERSION 3.24)
project(vps_reverse_proxy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system url)
find_package(yaml-cpp REQUIRED)
find_package(spdlog REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(reverse_proxy
    src/main.cpp
    src/core/Server.cpp
    src/core/Connection.cpp
    src/core/ProxyHandler.cpp
    src/proxy/Proxy.cpp
    src/load_balancer/RoundRobin.cpp
    src/load_balancer/Random.cpp
    src/load_balancer/LeastConnections.cpp
    src/health/HealthChecker.cpp
    src/config/Config.cpp
    src/utils/Logger.cpp
    src/utils/ThreadPool.cpp
)

target_include_directories(reverse_proxy PRIVATE src)
target_link_libraries(reverse_proxy PRIVATE
    Boost::system Boost::url
    yaml-cpp
    spdlog::spdlog
    OpenSSL::SSL OpenSSL::Crypto
)

# Enable Asio standalone if not using Boost.Asio full, nhưng ở đây dùng Boost
target_compile_definitions(reverse_proxy PRIVATE BOOST_ASIO_NO_DEPRECATED)
