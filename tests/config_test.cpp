/**
 * @file config_test.cpp
 * @brief Contains tests to test the config utility functions.
 * @author G. Chamberlain-Webber
 */

#include "config.h"

#define CLOVE_SUITE_NAME config_test
#include "testing/clove-unit.h"

#include "tao/json/value.hpp"
#include "tao/json/from_file.hpp"

const tao::json::value local_config = tao::json::from_file("config.json");

// Test 1
CLOVE_TEST(test_get_log_dir)
{
    // This test ensures that get_log_dir() returns the expected value.

    const std::string expected_value = local_config.at("logging").at("directory").as<std::string>();
    const std::string actual_value = Config::get_log_dir();

    CLOVE_STRING_EQ(expected_value.c_str(), actual_value.c_str());
}

// Test 2
CLOVE_TEST(test_get_log_enabled)
{
    // This test ensures that get_log_enabled() returns the expected value.

    const bool expected_value = local_config.at("logging").at("enabled").as<bool>();
    const bool actual_value = Config::get_log_enabled();

    CLOVE_INT_EQ(expected_value, actual_value);
}

// Test 3
CLOVE_TEST(test_get_com_port)
{
    // This test ensures that get_com_port() returns the expected value.

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    std::string expected_value = local_config.at("serial").at("com").at("windows").as<std::string>();
    std::string actual_value = Config::get_com_port();

    CLOVE_STRING_EQ(expected_value.c_str(), actual_value.c_str());

    #else
    std::string expected_value = local_config.at("serial").at("com").at("linux").as<std::string>();
    std::string actual_value = Config::get_com_port();

    CLOVE_STRING_EQ(expected_value.c_str(), actual_value.c_str());
    #endif
}

// Test 4
CLOVE_TEST(test_get_baudrate)
{
    // This test ensures that the get_baudrate() function will return the correct baudrate specified
    // in the configuration file.

    const int expected_value = local_config.at("serial").at("baudrate").as<int>();
    const int actual_value = Config::get_baudrate();

    CLOVE_INT_EQ(expected_value, actual_value)
}

// Test 5
CLOVE_TEST(test_get_timeout)
{
    // This test ensures that the get_timeout() function will return the correct timeout value
    // specified in the configuration file.

    const int expected_value = local_config.at("serial").at("timeout").as<int>();
    const int actual_value = Config::get_timeout();

    CLOVE_INT_EQ(expected_value, actual_value)
}

// Test 6
CLOVE_TEST(test_get_poll_time_period)
{
    // This test ensures that the get_poll_time_period() function will return the correct time period
    // value from the configuration file.

    const float expected_value = local_config.at("timing").at("poll-time-period").as<float>();
    const float actual_value = Config::get_poll_time_period();

    CLOVE_FLOAT_EQ(expected_value, actual_value)
}

// Test 7
CLOVE_TEST(test_get_ping_time_period)
{
    // This test ensures that the get_ping_time_period() function will return the correct time period
    // value from the configuration file.

    const float expected_value = local_config.at("timing").at("ping-time-period").as<float>();
    const float actual_value = Config::get_ping_time_period();

    CLOVE_FLOAT_EQ(expected_value, actual_value)
}

// Test 8
CLOVE_TEST(test_get_log_file)
{
    // This test ensures that the get_log_file() function will return the correct logfile value
    // from the configuration file.

    const std::string expected_value = local_config.at("logging").at("logfile").as<std::string>();
    const std::string actual_value = Config::get_log_file();

    CLOVE_STRING_EQ(expected_value.c_str(), actual_value.c_str())
}

// Test 9
CLOVE_TEST(test_get_log_verbose_mode)
{
    // This test ensures that the get_log_verbose_mode() function will return the correct log verbose mode
    // value from the configuration file.

    const bool expected_value = local_config.at("logging").at("verbose-logging").as<bool>();
    const bool actual_value = Config::get_log_verbose_mode();

    CLOVE_INT_EQ(expected_value, actual_value)
}

CLOVE_TEST(test_get_protocol_version)
{
	// This test ensures that the get_protocol_version() function will return the correct protocol version
    // value from the configuration file.

    constexpr auto expected_value = Config::ProtocolVersion::MX5;
    const Config::ProtocolVersion actual_value = Config::get_protocol_version();

    CLOVE_INT_EQ(static_cast<int>(expected_value), static_cast<int>(actual_value))
}