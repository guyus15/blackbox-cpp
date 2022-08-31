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
}