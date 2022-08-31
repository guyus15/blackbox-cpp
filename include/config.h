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
     * @brief Gets the bytesize value from the configuration file as a SerialDataBits enum value.
     * 
     * @return SerialDataBits The bytesize value from the configuration file.
     */
    enum SerialDataBits get_bytesize();

    /**
     * @brief Gets the parity value from the configuration file as a SerialParity enum value.
     * 
     * @return SerialParity The parity value from the configuration file.
     */
    enum SerialParity get_parity();

    /**
     * @brief Gets the stopbits value from the configuration file as a SerialStopBits enum value.
     * 
     * @return enum SerialStopBits The stopbits value from the configuration file.
     */
    enum SerialStopBits get_stopbits();
}