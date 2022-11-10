/**
 * @file application.h
 * @brief The main application run time which encapsulates the entire program loop.
 * @author G. Chamberlain-Webber
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "clock.h"
#include "config.h"
#include "logger.h"
#include "output.h"

#include "packet/packet_types.h"
#include "packet/writable.h"
#include "packet/content.h"

#include "profiling/instrumentation.h"

#include <vector>
#include <type_traits>
#include <typeinfo>

template<typename T1, typename T2>
class Application
{
    static_assert(std::is_base_of_v<Packets::IWritable, T1>&&
				  std::is_base_of_v<Packets::Content, T2>);

    using PointInformationRequest = T1;
    using PointInformationReply = T2;
    using PointRecord = std::vector<std::pair<int, int>>;

public:
    Application() { initialise(); }
    ~Application() = default;

    Application(const Application&) = delete;
    Application(Application&&) noexcept = delete;

    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) noexcept = delete;

    void run()
    {
        Clock clock{ true };

        const std::string logfile = Config::get_log_file();
        const float ping_time_period = Config::get_ping_time_period();

        // While this could be a const, there could be situations in future when we can set
        // the duration of which the logger runs, in which case this will be changed.
        bool should_run = true;

        while (should_run)
        {
	        if (!clock.time_elapsed(ping_time_period))
	        {
                continue;
	        }

            for (const auto& [fst, snd] : _point_records)
            {
                const int loop_number = fst;
                const int point_number = snd;

                BX_LOG_INFO("Loop: {0}\nPoint: {1}", loop_number, point_number);

                PointInformationRequest packet{ point_number, loop_number };
                packet.write();

                const auto reply = std::make_unique<PointInformationReply>(packet.read());

                const std::string entry = reply->get_as_csv();

                BX_LOG_INFO("{0}", entry);

                _logger.write_log(entry, logfile);
            }
        }
    }

private:
    Logger _logger;
    PointRecord _point_records;

    /**
     * @brief Initialises the application/
     */
    void initialise()
    {
        BX_PROFILE_BEGIN_SESSION("Application initialisation");

        const std::string logfile = Config::get_log_file();
        send_test_packet(logfile);

        _point_records = poll_points();

        BX_PROFILE_END_SESSION();
    }

    /**
     * @brief Sends a test packet to determine that the configuration file is set up correctly.
     * It will also write headers to the selected log file if they are not already there.
     */
    void send_test_packet(const std::string& logfile)
    {
        BX_PROFILE_FUNCTION();

        // Point information request for point 0.
        PointInformationRequest test_packet{ 0, 1 };
        test_packet.write();

        // Log file headers (only added once).
        const auto reply = std::make_unique<PointInformationReply>(test_packet.read());
        _logger.write_headers(Packets::get_headers(), logfile);
    }

    /**
     * @brief Looks through each of the points on the network and discovers those which actually exist.
     *
     * @returns std::vector<std::pair<int, int>> A vector of valid points on the network.
     */
    PointRecord poll_points()
    {
        BX_PROFILE_FUNCTION();

        PointRecord valid_points{};

        Clock clock{ true };

        const float poll_time_period = Config::get_poll_time_period();

        int current_point_number = 0;
        int current_loop_number = 1;

        const bool is_mx5 = typeid(PointInformationRequest) == typeid(Packets::Types::PointInformationRequestMX5);
        const unsigned NUMBER_LOOPS = is_mx5 ? Constants::MX5_MAX_LOOPS : Constants::MX6_MAX_LOOPS;

        BX_LOG_INFO("Protocol selected: {0}", is_mx5 ? "MX Speak Version 5" : "MX Speak Version 6");

        bool should_poll_points = true;

        while (should_poll_points)
        {
	        if (clock.time_elapsed(poll_time_period))
	        {
                BX_LOG_INFO("Polling points {0} on loop {1}...", current_point_number, current_loop_number);


                PointInformationRequest packet{ current_point_number, current_loop_number };
                packet.write();

                const auto reply = std::make_unique<PointInformationReply>(packet.read());

                if (reply->reply_successful())
                {
                    valid_points.emplace_back(current_loop_number, current_point_number);
                }

                current_point_number++;

                if (current_point_number > Constants::POINT_PER_LOOP)
                {
                    current_point_number = 0;
                    current_loop_number++;
                }

                if (current_loop_number > NUMBER_LOOPS)
                {
                    should_poll_points = false;
                }
	        }
        }

        return valid_points;
    }
};

#endif