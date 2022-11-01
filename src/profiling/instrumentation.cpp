#include "profiling/instrumentation.h"

#include <algorithm>
#include <iostream>
#include <thread>

Instrumentor::Instrumentor()
    : m_current_session{ nullptr }, m_profile_count{ 0 }
{
}

void Instrumentor::begin_session_internal(const std::string& name, const std::string& filepath)
{
    m_output_stream.open(filepath);
    write_header();
    m_current_session = new InstrumentationSession{name};
}

void Instrumentor::end_session_internal()
{
    write_footer();
    m_output_stream.close();
    delete m_current_session;
    m_current_session = nullptr;
    m_profile_count = 0;
}

void Instrumentor::write_profile_internal(const ProfileResult& result)
{
    if (m_profile_count++ > 0)
    {
        m_output_stream << ",";
    }

    std::string name = result.name;
    std::replace(name.begin(), name.end(), '"', '\'');

    m_output_stream << "{";
    m_output_stream << R"("cat":"function",)";
    m_output_stream << "\"dur\":" << (result.end - result.start) << ',';
    m_output_stream << R"("name":")" << name << "\",";
    m_output_stream << R"("ph":"X",)";
    m_output_stream << "\"pid\":0,";
    m_output_stream << R"("tid":")" << result.thread_id << "\",";
    m_output_stream << "\"ts\":" << result.start;
    m_output_stream << "}";

    m_output_stream.flush();
}

void Instrumentor::write_header_internal()
{
    m_output_stream << R"({"otherData": {},"traceEvents":[)";
    m_output_stream.flush();
}

void Instrumentor::write_footer_internal()
{
    m_output_stream << "]}";
    m_output_stream.flush();
}

// Static methods

Instrumentor& Instrumentor::get() { return s_instance; }

void Instrumentor::begin_session(const std::string& name, const std::string& filepath)
{
    get().begin_session_internal(name, filepath);
}

void Instrumentor::end_session()
{
    get().end_session_internal();
}

void Instrumentor::write_profile(const ProfileResult& result)
{
    get().write_profile_internal(result);
}

void Instrumentor::write_header()
{
    get().write_header_internal();
}

void Instrumentor::write_footer()
{
    get().write_footer_internal();
}

InstrumentationTimer::InstrumentationTimer(std::string name)
    : m_name{std::move(name)}, m_stopped{ false }
{
    m_start_timepoint = std::chrono::steady_clock::now();
}

InstrumentationTimer::~InstrumentationTimer()
{
    if (!m_stopped)
    {
        stop();
    }
}

void InstrumentationTimer::stop()
{
    const auto end_timepoint = std::chrono::high_resolution_clock::now();

    const long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_timepoint).time_since_epoch().count();
    const long long end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();

    const size_t thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());

    Instrumentor::write_profile({m_name, start, end, thread_id});

    m_stopped = true;
}