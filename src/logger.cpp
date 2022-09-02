/**
 * @file logger.cpp
 * @brief Contains logging utility functions.
 * @author G. Chamberlain-Webber
 */

#include "logger.h"
#include "config.h"

#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

static bool check_directory_exists(const std::filesystem::path& path);

Logger::Logger()
{
    // Create the log directory if it doesn't exist.
    Logger::create_log_dir();
}

void Logger::create_log_dir()
{
    std::string configured_path = Config::get_log_dir();
    const std::filesystem::path directory_path{configured_path};

    if (!check_directory_exists(directory_path))
    {
        std::cout << "Directory does not exist. Creating..." << std::endl;
        std::filesystem::create_directory(directory_path);
    } else
    {
        std::cout << "Directory already exists." << std::endl;
    }
}

void Logger::write_log(std::string entry, std::string logfile)
{
    // Don't write to the log file if logging is has not been enabled.
    if (!Config::get_log_enabled())
    {
        return;
    }

    // Pre-pend a timestamp onto the entry.
    auto current = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(current);

    std::string time_string = std::ctime(&current_time);

    // Remove new line characters
    std::regex newline_regex{"\n"};

    entry = std::regex_replace(entry, newline_regex, "");
    time_string = std::regex_replace(time_string, newline_regex, "");

    char new_entry[128];
    sprintf(new_entry, "%s,%s\n", time_string.c_str(), entry.c_str());
    entry = new_entry;

    // Log either on Linux or Windows, depending on current platform.
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    Logger::write_log_windows(entry, logfile);
    #else
    Logger::write_log_linux(entry, logfile);
    #endif
}

void Logger::write_log_windows(const std::string& entry, const std::string logfile)
{
    std::cout << "Writing on Windows..." << std::endl;
    
    std::string log_path = Config::get_log_dir() + "/" + logfile;

    std::ofstream file;

    file.open(log_path, std::ios_base::app);
    file << entry;
    file.close();
}
    
void Logger::write_log_linux(const std::string& entry, const std::string logfile)
{
    // This is a separate implementation to reserve a different behaviour for Linux in the 
    // future. For example, we could do a check to see if the user has a USB connected, if
    // so, the logs can be written there instead.
    // Maybe something could also be done with status LEDs and other visual hardware.

    std::cout << "Writing on Linux..." << std::endl;
    
    std::string log_path = Config::get_log_dir() + "/" + logfile;

    std::ofstream file;

    file.open(log_path, std::ios_base::app);
    file << entry;
    file.close();
}

/**
 * @brief Determines if a directory exists or not.
 * 
 * @param path The path to a directory.
 * @return true If the directory exists.
 * @return false If a directory does not exist.
 */
static bool check_directory_exists(const std::filesystem::path& path)
{
    return std::filesystem::exists(path);
}
