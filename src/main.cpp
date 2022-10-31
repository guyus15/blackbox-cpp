/**
 * @file main.cpp
 * @brief The main entry point for the program.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet_types.h"
#include "profiling/instrumentation.h"
#include "clock.h"
#include "config.h"
#include "constants.h"
#include "logger.h"

#include <iostream>
#include <vector>
#include <memory>
#include <thread>

// These could be represented as an unordered_map as as the point polling does not necessarily need to be
// in order, but it makes sense from a logging perspective to put log points in order.
std::vector<std::pair<int, int>> poll_points();

void send_test_packet(const Logger& logger, const std::string& logfile);

int main()
{
    BX_PROFILE_BEGIN_SESSION("Set up");

    const Logger logger;
    Clock clock{true};

    const std::string logfile = Config::get_log_file();
    send_test_packet(logger, logfile);

    const std::vector<std::pair<int, int>> point_records = poll_points();

    // While this could be const, there could be situations in the future when we can set
    // the duration of which the logger runs, in which case this will be changed.
    bool should_run = true;
    const float ping_time_period = Config::get_ping_time_period();

    BX_PROFILE_END_SESSION();

    while (should_run)
    {
        if (!clock.time_elapsed(ping_time_period))
        {
            continue;
        }

        for (const auto& [fst, snd] : point_records)
        {
            const int loop_number = fst;
            const int point_number = snd;

            std::cout << "Loop: " << loop_number << "\nPoint: " << point_number << std::endl;

            Packets::Types::PointInformationRequestMX5 packet{point_number, loop_number};

            packet.write();

            const std::unique_ptr<Packets::Types::PointInformationReplyMX5> reply{packet.read()};

            std::string entry = reply->get_as_csv();

            std::cout << entry << std::endl; 

            logger.write_log(entry, logfile);
        }
    }

    return 0;
}

/**
 * @brief Sends a test packet to determine that the configuration file is set up correctly.
 * It will also write headers to the selected log file if they are not already there.
 * 
 */
void send_test_packet(const Logger& logger, const std::string& logfile)
{
    BX_PROFILE_FUNCTION();

    // Point information request for point 0.
    Packets::Types::PointInformationRequestMX5 test_packet{0, 1};

    test_packet.write();

    // Log file headers  (only added once)
    {
        const std::unique_ptr<Packets::Types::PointInformationReplyMX5> reply{test_packet.read()};
        const std::vector<std::string> headers = reply->get_headers();

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
    BX_PROFILE_FUNCTION();

    std::vector<std::pair<int, int>> valid_points{};

    Clock clock{true};

    bool should_poll_points = true;

    const float poll_time_period = Config::get_poll_time_period();

    int current_point_number = 0;
    int current_loop_number = 1;

    while (should_poll_points)
    {
        if (clock.time_elapsed(poll_time_period))
        {
            std::cout << "Polling point " << current_point_number << " on loop " << current_loop_number << "..." << std::endl;

            Packets::Types::PointInformationRequestMX5 packet{current_point_number, current_loop_number};

            packet.write();

            const std::unique_ptr<Packets::Types::PointInformationReplyMX5> reply{packet.read()};
            if (reply->reply_successful())
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