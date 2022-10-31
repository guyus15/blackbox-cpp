#ifndef OUTPUT_H
#define OUTPUT_H

#include "spdlog/spdlog.h"

#define OUTPUT_LEVEL_INFO

#ifdef OUTPUT_LEVEL_INFO	// Shows critical, warning and info level log messages.
#define BX_LOG_INFO(msg) spdlog::info(msg)
#define BX_LOG_WARNING(msg) spdlog::warn(msg)
#define BX_LOG_ERROR(msg) spdlog::critical(msg)
#endif

#ifdef OUTPUT_LEVEL_WARNING  // Shows critical and warning level log messages
#define BX_LOG_INFO(msg)
#define BX_LOG_WARNING(msg) spdlog::warn(msg)
#define BX_LOG_ERROR(msg) spdlog::critical(msg)
#endif

#ifdef OUTPUT_LEVEL_ERROR // Only shows error level log messages
#define BX_LOG_INFO(msg)
#define BX_LOG_WARNING(msg)
#define BX_LOG_ERROR(msg) spdlog::critical(msg)
#endif

#endif