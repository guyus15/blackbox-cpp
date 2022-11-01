#ifndef OUTPUT_H
#define OUTPUT_H

#include "spdlog/spdlog.h"

#if defined(OUTPUT_LEVEL_INFO)	// Shows critical, warning and info level log messages.
#define BX_LOG_INFO(msg, ...) spdlog::info(msg, ## __VA_ARGS__)
#define BX_LOG_WARNING(msg, ...) spdlog::warn(msg, ## __VA_ARGS__)
#define BX_LOG_ERROR(msg, ...) spdlog::critical(msg, ## __VA_ARGS__)
#elif defined(OUTPUT_LEVEL_WARNING) // Shows critical and warning level log messages
#define BX_LOG_INFO(msg, ...)
#define BX_LOG_WARNING(msg, ...) spdlog::warn(msg, ## __VA_ARGS__)
#define BX_LOG_ERROR(msg, ...) spdlog::critical(msg, ## __VA_ARGS__)
#else
#define BX_LOG_INFO(msg, ...)
#define BX_LOG_WARNING(msg, ...)
#define BX_LOG_ERROR(msg, ...) spdlog::critical(msg, ## __VA_ARGS__)
#endif

#endif