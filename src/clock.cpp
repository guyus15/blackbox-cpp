/**
 * @file clock.cpp
 * @brief A simple clock implementation, used to manage the timing of the program.
 * @author G. Chamberlain-Webber
 */

#include "clock.h"

#include "profiling/instrumentation.h"

Clock::Clock(const bool start_true)
: _start_time{std::chrono::system_clock::now()}, _start_true{start_true}
{
}

bool Clock::time_elapsed(const float seconds)
{
    BX_PROFILE_FUNCTION();

    if (_start_true)
    {
        _start_true = false;
        return true;
    }

    const auto current_time = std::chrono::system_clock::now();
    const std::chrono::duration<float> elapsed_seconds = current_time - _start_time;

    if (elapsed_seconds.count() >= seconds)
    {
        _start_time = current_time;
        return true;
    }

    return false;
}