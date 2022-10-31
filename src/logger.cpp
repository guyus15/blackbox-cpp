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
#include <sstream>

Logger::Logger()
{
    // Create the log directory if it doesn't exist.
    Logger::create_log_dir();
}

void Logger::create_log_dir() const
{
	const std::string configured_path = Config::get_log_dir();

	if (const std::filesystem::path directory_path{configured_path}; !exists(directory_path))
    {
        std::cout << "Directory does not exist. Creating..." << std::endl;
        std::filesystem::create_directory(directory_path);
    } else
    {
        std::cout << "Directory already exists." << std::endl;
    }
}

void Logger::write_log(std::string entry, const std::string& logfile, const bool prepend_date) const
{
    // Don't write to the log file if logging is has not been enabled.
    if (!Config::get_log_enabled())
    {
        return;
    }

    // Pre-pend a timestamp onto the entry.
    if (prepend_date)
    {
	    const auto current = std::chrono::system_clock::now();
	    const std::time_t current_time = std::chrono::system_clock::to_time_t(current);

        std::string time_string = std::ctime(&current_time);

        // Remove new line characters
	    const std::regex newline_regex{"[\r\n]+"};

        entry = std::regex_replace(entry, newline_regex, "");
        time_string = std::regex_replace(time_string, newline_regex, "");

	    const std::string new_entry = time_string + "," + entry + "\n";
        entry = new_entry;
    }

    // Log either on Linux or Windows, depending on current platform.
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    Logger::write_log_windows(entry, logfile);
    #else
    Logger::write_log_linux(entry, logfile);
    #endif
}

void Logger::write_headers(const std::vector<std::string>& headers, const std::string& logfile) const
{
	// Only write header to the file if it does not exist.
    if (const std::filesystem::path file{logfile}; std::filesystem::exists(file))
    {
        std::cout << "File already exists. Not adding header." << std::endl;
        return;
    }   

    std::cout << "File does not exist. Writing header." << std::endl;

    std::stringstream csv_stream{};

    csv_stream << "datetime" << ","; 

    for (const auto& header : headers)
    {
        csv_stream << header << ",";
    }

    std::string csv_string = csv_stream.str();

    // Remove last comma from end.
    csv_string = csv_string.substr(0, csv_string.size() - 1);
    csv_string = csv_string + "\n";

    write_log(csv_string, logfile, false);
}

void Logger::write_log_windows(const std::string& entry, const std::string& logfile)
{
    std::cout << "Writing on Windows..." << std::endl;

    const std::string log_path = Config::get_log_dir() + "/" + logfile;

    std::ofstream file;

    file.open(log_path, std::ios_base::app);
    file << entry;
    file.close();
}
    
void Logger::write_log_linux(const std::string& entry, const std::string& logfile)
{
    // This is a separate implementation to reserve a different behaviour for Linux in the 
    // future. For example, we could do a check to see if the user has a USB connected, if
    // so, the logs can be written there instead.
    // Maybe something could also be done with status LEDs and other visual hardware.

    std::cout << "Writing on Linux..." << std::endl;
    
    const std::string log_path = Config::get_log_dir() + "/" + logfile;

    std::ofstream file;

    file.open(log_path, std::ios_base::app);
    file << entry;
    file.close();
}
