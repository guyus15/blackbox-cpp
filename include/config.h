/**
 * @file config.h
 * @brief Contains utlility functions for reading configuration information from the configuration file.
 * @author G. Chamberlain-Webber
 */

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
}