/**
 * @file main.cpp
 * @brief The main entry point for the program.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet_types.h"
#include "clock.h"
#include "config.h"
#include "constants.h"
#include "logger.h"

#include <iostream>
#include <vector>

void send_test_packet(Logger& logger, std::string& logfile);
std::vector<std::pair<int, int>> poll_points();

int main()
{
    Logger logger;
    Clock clock{true};

    std::string logfile = Config::get_log_file();

    send_test_packet(logger, logfile);

    std::vector<std::pair<int, int>> point_records = poll_points();

    bool should_run = true;
    float ping_time_period = Config::get_ping_time_period();

    while (should_run)
    {
        if (!clock.time_elapsed(ping_time_period))
        {
            continue;
        }

        for (const auto& point_record : point_records)
        {
            int loop_number = point_record.first;
            int point_number = point_record.second;

            std::cout << "Loop: " << loop_number << "\nPoint: " << point_number << std::endl;

            Packets::Types::PointInformationRequestMX5 packet{point_number, loop_number};

            packet.write();

            Packets::Types::PointInformationReplyMX5 *reply = packet.read();

            std::string entry = reply->get_as_csv();

            std::cout << entry << std::endl; 

            logger.write_log(entry, logfile);

            delete reply;
        }
    }

    return 0;
}

/**
 * @brief Sends a test packet to determine that the configuration file is set up correctly.
 * It will also write headers to the selected log file if they are not already there.
 * 
 */
void send_test_packet(Logger& logger, std::string& logfile)
{
    // Point informationr request for point 0.
    Packets::Types::PointInformationRequestMX5 test_packet{0, 1};

    test_packet.write();

    Packets::Types::PointInformationReplyMX5 *reply = test_packet.read();

    // Log file headers  (only added once)
    {
        std::vector<std::string> headers = reply->get_headers();

        logger.write_headers(headers, logfile);
    }
}

/**
 * @brief Looks through each of the points on the network and discovers those which actually exists.
 * 
 * @return std::vector<std::pair<int, int>> A vector of valid points on the network.
 */
std::vector<std::pair<int, int>> poll_points()
{
    std::vector<std::pair<int, int>> valid_points{};

    Clock clock{true};

    bool should_poll_points = true;

    float poll_time_period = Config::get_poll_time_period();

    int current_point_number = 0;
    int current_loop_number = 1;

    while (should_poll_points)
    {
        if (clock.time_elapsed(poll_time_period))
        {
            std::cout << "Polling point " << current_point_number << " on loop " << current_loop_number << "..." << std::endl;

            Packets::Types::PointInformationRequestMX5 packet{current_point_number, current_loop_number};

            packet.write();

            Packets::Types::PointInformationReplyMX5 *read_data = packet.read();

            if (read_data->reply_successful())
            {
                valid_points.push_back({current_loop_number, current_point_number});
            }

            current_point_number++;

            if (current_point_number > Constants::POINT_PER_LOOP)
            {
                current_point_number = 0;
                current_loop_number++;
            }

            if (current_loop_number > Constants::MX5_MAX_LOOPS)
            {
                should_poll_points = false;
            }
        }
    }

    return valid_points;
}