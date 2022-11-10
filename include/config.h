/**
 * @file config.h
 * @brief Contains utlility functions for reading configuration information from the configuration file.
 * @author G. Chamberlain-Webber
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "serial/serialib.h"

#include <string>

namespace Config
{
    enum class ProtocolVersion
    {
        MX5 = 0,
        MX6
    };

    /**
     * @brief Gets the logging enabled value from the configuration file.
     *
     * @return true If logging enabled is set to true in the configuration file.
     * @return false If logging enabled is set to false in the configuration file.
     */
    bool get_log_enabled();

    /**
     * @brief Gets the path to the log directory.
     *
     * @return std::string The path to the log directory.
     */
    std::string get_log_dir();

    /**
     * @brief Gets the log file name.
     *
     * @return std::string The name the log file should take.
     */
    std::string get_log_file();

    /**
     * @brief Gets the log verbose mode.
     *
     * @return true If verbose mode has been enabled in the configuration file.
     * @return false If verbose mode has been disabled in the configuration file.
     */
    bool get_log_verbose_mode();

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

    /**
     * @brief Gets the polling time period value from the configuration file.
     *
     * @return float The polling time period value from the configuration file.
     */
    float get_poll_time_period();

    /**
     * @brief Gets the ping time period value from the configuration file.
     *
     * @return float The ping time period value from the configuration file.
     */
    float get_ping_time_period();

    /**
     * @brief Gets the target protocol version from the configuration file.
     *
     * @return ProtocolVersion The protocol version value from the configuration file. If the protocol
     * version cannot be found, MX Speak Version 5 is returned by default.
     */
    ProtocolVersion get_protocol_version();
}

#endif