/**
 * @file config.cpp
 * @brief Contains utlility functions for reading configuration information from the configuration file.
 * @author G. Chamberlain-Webber
 */

#include "tao/json/value.hpp"
#include "tao/json/from_file.hpp"

#include <iostream>

namespace Config
{
    const tao::json::value config = tao::json::from_file("config.json");

    std::string get_log_dir()
    {
        std::string directory = config.at("logging").at("directory").as<std::string>();

        return directory;
    }

    bool get_log_enabled()
    {
        bool enabled = config.at("logging").at("enabled").as<bool>();

        return enabled;
    }

    std::string get_com_port()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        std::string com_port = config.at("serial").at("com").at("windows").as<std::string>();
        #else
        std::string com_port = config.at("serial").at("com").at("linux").as<std::string>();
        #endif

        return com_port;
    }

    int get_baudrate()
    {
        int baudrate = config.at("serial").at("baudrate").as<int>();

        return baudrate;
    }

    int get_timeout()
    {
        int timeout = config.at("serial").at("timeout").as<int>();

        return timeout;
    }

    SerialDataBits get_bytesize()
    {
        int bytesize = config.at("serial").at("bytesize").as<int>();

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
        }
    }
}