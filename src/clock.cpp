/**
 * @file clock.cpp
 * @brief A simple clock implementation, used to manage the timing of the program.
 * @author G. Chamberlain-Webber
 */

#include "clock.h"

Clock::Clock(bool start_true)
: _start_time{std::chrono::system_clock::now()}, _start_true{start_true}
{
}

bool Clock::time_elapsed(int seconds)
{
    if (_start_true)
    {
        _start_true = false;
        return true;
    }

    auto current_time = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = current_time - _start_time;

    if (elapsed_seconds.count() >= seconds)
    {
        _start_time = current_time;
        return true;
    }

    return false;
}