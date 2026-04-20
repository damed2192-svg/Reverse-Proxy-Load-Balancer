// Logger.h
#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/async.h>

class Logger {
public:
    static void init(bool async = true);
    static std::shared_ptr<spdlog::logger> get();
};

#define LOG_INFO(...)    SPDLOG_LOGGER_INFO(Logger::get(), __VA_ARGS__)
#define LOG_ERROR(...)   SPDLOG_LOGGER_ERROR(Logger::get(), __VA_ARGS__)
#define LOG_DEBUG(...)   SPDLOG_LOGGER_DEBUG(Logger::get(), __VA_ARGS__)
