/**
 * @file config.cpp
 * @brief Contains utlility functions for reading configuration information from the configuration file.
 * @author G. Chamberlain-Webber
 */

#include "config.h"
#include "output.h"

#include "tao/json/value.hpp"
#include "tao/json/from_file.hpp"

#include "profiling/instrumentation.h"
#include "spdlog/spdlog.h"

namespace Config
{
    const tao::json::value config = tao::json::from_file("config.json");

    bool get_log_enabled()
    {
        BX_PROFILE_FUNCTION();

        const bool enabled = config.at("logging").at("enabled").as<bool>();

        return enabled;
    }

    std::string get_log_dir()
    {
        BX_PROFILE_FUNCTION();

        std::string directory = config.at("logging").at("directory").as<std::string>();

        return directory;
    }

    std::string get_log_file()
    {
        BX_PROFILE_FUNCTION();

        std::string logfile = config.at("logging").at("logfile").as<std::string>();

        return logfile;
    }

    bool get_log_verbose_mode()
    {
        BX_PROFILE_FUNCTION();

        const bool verbose_mode = config.at("logging").at("verbose-logging").as<bool>();

        return verbose_mode;
    }

    std::string get_com_port()
    {
        BX_PROFILE_FUNCTION();

        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        std::string com_port = config.at("serial").at("com").at("windows").as<std::string>();
        #else
        std::string com_port = config.at("serial").at("com").at("linux").as<std::string>();
        #endif

        return com_port;
    }

    int get_baudrate()
    {
        BX_PROFILE_FUNCTION();

        const int baudrate = config.at("serial").at("baudrate").as<int>();

        return baudrate;
    }

    int get_timeout()
    {
        BX_PROFILE_FUNCTION();

        const int timeout = config.at("serial").at("timeout").as<int>();

        return timeout;
    }

    enum SerialDataBits get_bytesize()
    {
        BX_PROFILE_FUNCTION();

        const int bytesize = config.at("serial").at("bytesize").as<int>();

        // Set data bits size to 8 by default.
        SerialDataBits databits = SERIAL_DATABITS_8;

        switch (bytesize)
        {
            case 5:
                databits = SERIAL_DATABITS_5;
                break;
            case 6:
                databits = SERIAL_DATABITS_6;
                break;
            case 7:
                databits = SERIAL_DATABITS_7;
                break;
            case 8:
                databits = SERIAL_DATABITS_8;
                break;
            case 16:
                databits = SERIAL_DATABITS_16;
                break;
            default:
                databits = SERIAL_DATABITS_8;
        }

        return databits;
    }

    enum SerialParity get_parity()
    {
        BX_PROFILE_FUNCTION();

        const std::string parity = config.at("serial").at("parity").as<std::string>();

        // Set parity to none by default.
        SerialParity parity_value = SERIAL_PARITY_NONE;

        if (parity == "none")
        {
            parity_value = SERIAL_PARITY_NONE;
        } else if (parity == "even")
        {
            parity_value = SERIAL_PARITY_EVEN;
        } else if (parity == "odd")
        {
            parity_value = SERIAL_PARITY_ODD;
        } else if (parity == "mark")
        {
            parity_value = SERIAL_PARITY_MARK;
        } else if (parity == "space")
        {
            parity_value = SERIAL_PARITY_SPACE;
        } else
        {
            // Default to 'none' if it has not been accounted for.
            parity_value = SERIAL_PARITY_NONE;
        }

        return parity_value;
    }

    enum SerialStopBits get_stopbits()
    {
        BX_PROFILE_FUNCTION();

        const float stopbits = config.at("serial").at("stopbits").as<float>();

        // One stopbit by default.
        SerialStopBits stopbits_value = SERIAL_STOPBITS_1;

        if (stopbits == 1.0f)
        {
            stopbits_value = SERIAL_STOPBITS_1;
        } else if (stopbits == 1.5f)
        {
            stopbits_value = SERIAL_STOPBITS_1_5;
        } else if (stopbits == 2.0f)
        {
            stopbits_value = SERIAL_STOPBITS_2;
        } else 
        {
            // Default to '1' stopbit if it has not been accounted for.
            stopbits_value = SERIAL_STOPBITS_1;
        }

        return stopbits_value;
    }

    float get_poll_time_period()
    {
        BX_PROFILE_FUNCTION();

        const float polling_time_period = config.at("timing").at("poll-time-period").as<float>();

        return polling_time_period;
    }

    float get_ping_time_period()
    {
        BX_PROFILE_FUNCTION();

        const float ping_time_period = config.at("timing").at("ping-time-period").as<float>();

        return ping_time_period;
    }

    ProtocolVersion get_protocol_version()
    {
        BX_PROFILE_FUNCTION();

        const std::string protocol_version = config.at("protocol-version").as<std::string>();

        if (protocol_version == "MX5")
        {
        	return ProtocolVersion::MX5;
        }
        if (protocol_version == "MX6")
        {
            return ProtocolVersion::MX6;
        }

        BX_LOG_WARNING("Protocol version '{0}' is not recognised. Defaulting to MX Speak Version 5...", protocol_version);
        return ProtocolVersion::MX5;
    }
}
