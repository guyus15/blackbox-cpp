#ifndef PROFILE_INSTRUMENTATION_H
#define PROFILE_INSTRUMENTATION_H

#include "constants.h"

#include <chrono>
#include <fstream>
#include <string>

struct ProfileResult
{
    std::string name;
    long long start, end;
    size_t thread_id;
};

struct InstrumentationSession
{
    std::string name;
};

class Instrumentor
{
public:
    Instrumentor(const Instrumentor&) = delete;

    static Instrumentor& get();

    static void begin_session(const std::string& name, const std::string& filepath = Constants::Profiling::RESULTS_FILE);
    static void end_session();
    static void write_profile(const ProfileResult& result);
    static void write_header();
    static void write_footer();

private:
    static Instrumentor s_instance;
    InstrumentationSession* m_current_session;
    std::ofstream m_output_stream;
    int m_profile_count;

    Instrumentor();

    void begin_session_internal(const std::string&, const std::string&);
    void end_session_internal();
    void write_profile_internal(const ProfileResult&);
    void write_header_internal();
    void write_footer_internal();
};

inline Instrumentor Instrumentor::s_instance;

/**
 * @brief Manages profile-related timing functions.
 */
class InstrumentationTimer
{
public:
    explicit InstrumentationTimer(std::string name);
    ~InstrumentationTimer();

    InstrumentationTimer(const InstrumentationTimer& timer) = default;
    InstrumentationTimer(InstrumentationTimer&& timer) noexcept = default;

    InstrumentationTimer& operator=(const InstrumentationTimer& timer) = delete;
    InstrumentationTimer& operator=(InstrumentationTimer&& timer) noexcept = delete;

    /**
     * @brief Stops the timer and writes the profile to a results file.
     */
    void stop();

private:
    const std::string m_name;
    std::chrono::time_point<std::chrono::steady_clock> m_start_timepoint;
    bool m_stopped;
};

#ifdef BX_PROFILING
#define BX_PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__{name}
#define BX_PROFILE_FUNCTION() BX_PROFILE_SCOPE(__FUNCSIG__)
#define BX_PROFILE_BEGIN_SESSION(name) Instrumentor::begin_session(name)
#define BX_PROFILE_END_SESSION() Instrumentor::end_session()
#else
#define BX_PROFILE_SCOPE(name)
#define BX_PROFILE_FUNCTION()
#define BX_PROFILE_BEGIN_SESSION(name)
#define BX_PROFILE_END_SESSION()
#endif

#endif