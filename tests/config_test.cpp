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

    std::string expected_value = local_config.at("logging").at("directory").as<std::string>();
    std::string actual_value = Config::get_log_dir();

    CLOVE_STRING_EQ(expected_value.c_str(), actual_value.c_str());
}

// Test 2
CLOVE_TEST(test_get_log_enabled)
{
    // This test ensures that get_log_enabled() returns the expected value.

    bool expected_value = local_config.at("logging").at("enabled").as<bool>();
    bool actual_value = Config::get_log_enabled();

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

    int expected_value = local_config.at("serial").at("baudrate").as<int>();
    int actual_value = Config::get_baudrate();

    CLOVE_INT_EQ(expected_value, actual_value);
}

// Test 5
CLOVE_TEST(test_get_timeout)
{
    // This test ensures that the get_timeout() function will return the correct timeout valeu
    // specified in the configuration file.

    int expected_value = local_config.at("serial").at("timeout").as<int>();
    int actual_value = Config::get_timeout();

    CLOVE_INT_EQ(expected_value, actual_value);
}