/**
 * @file logger.h
 * @brief Contains a class managing logging utility functions.
 * @author G. Chamberlain-Webber
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
    public:
        Logger();
        ~Logger() = default;

        /**
         * @brief Writes to a log entry within the log directory.
         * 
         * This function determines whether to log on Windows or RPi, then will call
         * the correct write log function, after pre-pending the time and date to the log
         * entry.
         * 
         * @param entry The log entry.
         * @param logfile The log file.
         */
        void write_log(std::string entry, const std::string logfile);

    private:
        /**
         * @brief Creates a log directory to store log files.
         * 
         * Looks for a directory named in the configuration file to store
         * log file in. If it can't find this, it will create one.
         */
        void create_log_dir();

        /**
         * @brief Writes a log entry within the log directory on Windows.
         * 
         * @param entry The log entry.
         * @param logfile The log file.
         */
        void write_log_windows(const std::string& entry, const std::string logfile);

        /**
         * @brief Writes a log entry within the log directory on Linux.
         * 
         * @param entry The log entry.
         * @param logfile The log file.
         */
        void write_log_linux(const std::string& entry, const std::string logfile);
};

#endif