/**
 * @file clock.h
 * @brief A simple clock implementation, used to manage the timing of the program.
 * @author G. Chamberlain-Webber
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

class Clock
{
    public:
        Clock(bool start_true = false);
        ~Clock() = default;

        /**
         * @brief Checks if a number of seconds has passed since the start time.
         * 
         * @param seconds The number of seconds needed to have passed.
         * @return true If 'seconds' have passed since the start time.
         * @return false If 'seconds' have not passed since the start time.
         */
        bool time_elapsed(int seconds);

    private:
        std::chrono::time_point<std::chrono::system_clock> _start_time;
        bool _start_true;
};

#endif