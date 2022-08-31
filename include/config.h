/**
 * @file config.h
 * @brief Contains utlility functions for reading configuration information from the configuration file.
 * @author G. Chamberlain-Webber
 */

#include "serial/serialib.h"

#include <string>

namespace Config
{
    /**
     * @brief Gets the path to the log directory.
     * 
     * @return std::string The path to the log directory.
     */
    std::string get_log_dir();

    /**
     * @brief Gets the logging enabled value from the configuration file.
     * 
     * @return true If logging enabled is set to true in the configuration file.
     * @return false If logging enabled is set to false in the configuration file.
     */
    bool get_log_enabled();

    /**
     * @brief Gets the COM port value from the configuration file.
     * 
     * @return std::string The COM port from the configuration file.
     */
    std::string get_com_port();

    /**
     * @brief Gets the baudrate value from the configuration file.
     * 
     * @return int The baudrate value from the configuration file.
     */
    int get_baudrate();

    /**
     * @brief Gets the timeout value from the configuration file.
     * 
     * @return int The timeout value from the configuration file.
     */
    int get_timeout();

    /**
     * @brief Gets the bytesize valeu from the configuration file.
     * 
     * @return int The bytesize value from the configuration file.
     */
    SerialDataBits get_bytesize();
}