/**
 * @file content_test.cpp
 * @brief Contains tests to test the 'content' file and class.
 * @author G. Chamberlain-Webber
 */

#include "packet/content.h"
#include "exceptions/invalid_key_exception.h"

#define CLOVE_SUITE_NAME content_test
#include "testing/clove-unit.h"

#include <ostream>

// Test 1
CLOVE_TEST(test_check_exists_when_exists)
{
    // This test ensures that when a key exists in the content parameters,
    // the check_exists() method return true.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    const Packets::Content test_content{test_vector}; 

    CLOVE_INT_EQ(test_content.check_exists("some string1"), 1)
}

// Test 2
CLOVE_TEST(test_check_when_no_exist)
{
    // This test ensures that when a key does not exist in the content parameters,
    // the check_exists() method returns false.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    const Packets::Content test_content{test_vector};

	CLOVE_INT_EQ(test_content.check_exists("some non-existent value"), 0)
}

// Test 3
CLOVE_TEST(test_get_byte_array)
{
    // This test ensures that when the get_byte_array() method is called, it returns
    // the expected result, a byte array representing the content parameter values.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const std::vector<unsigned char> expected_values{'\x10', '\x20', '\x30'};
    const std::vector<unsigned char> actual_value = test_content.get_byte_array();

    for (size_t i = 0; i < expected_values.size(); i++)
    {
        CLOVE_CHAR_EQ(expected_values[i], actual_value[i])
    }
}

// Test 4
CLOVE_TEST(test_get_parameter_valid_key)
{
    // This test ensures that when the get_parameter() method is called with an existing,
    // key, the value corresponding to that key is returned.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const std::string parameter = "some string1";

    CLOVE_CHAR_EQ(test_content.get_parameter(parameter), '\x10')
}

// Test 5
CLOVE_TEST(test_get_parameter_invalid_key)
{
    // This test ensures that when the get_parameter() method is called with a
    // non-existent key, an InvalidKeyException is thrown.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const std::string parameter = "non-existent parameter";

    bool exception_thrown = false;
    try
    {
        test_content.get_parameter(parameter);
    }
    catch([[maybe_unused]] const InvalidKeyException& e)
    {
        exception_thrown = true;
    }
    
    CLOVE_INT_EQ(exception_thrown, 1)
}

// Test 6
CLOVE_TEST(test_set_parameter_valid_key)
{
    // This test ensures that when the set_parameter() method is called with a
    // existing key, the value corresponding to that key is set correctly.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const std::string parameter = "some string1";

    test_content.set_parameter(parameter, '\xee');

    CLOVE_CHAR_EQ(test_content.get_parameter(parameter), '\xee')
}

// Test 7
CLOVE_TEST(test_set_parameter_invalid_key)
{
    // This test ensures that when the set_parameter() method is called with a 
    // non-existent key, an InvalidKeyException is thrown.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const std::string parameter = "non-existent parameter";

    bool exception_thrown = false;
    try
    {
        test_content.set_parameter(parameter, '\xee');
    }
    catch([[maybe_unused]] const InvalidKeyException& e)
    {
        exception_thrown = true;
    }
    
    CLOVE_INT_EQ(exception_thrown, 1)
}

// Test 8
CLOVE_TEST(test_get_parameters)
{
    // This test ensures that when the get_parameters() method is called, it returns
    // all content parameters.

    std::vector<std::pair<std::string, unsigned char>> test_vector = 
    {
        {"some string1", '\x10'},
        {"some string2", '\x20'},
        {"some string3", '\x30'},
    };

    Packets::Content test_content{test_vector};

    const auto parameters = test_content.get_parameters();

    CLOVE_STRING_EQ(parameters[0].first.c_str(), "some string1")
    CLOVE_CHAR_EQ(parameters[0].second, '\x10')

    CLOVE_STRING_EQ(parameters[1].first.c_str(), "some string2")
    CLOVE_CHAR_EQ(parameters[1].second, '\x20')

    CLOVE_STRING_EQ(parameters[2].first.c_str(), "some string3")
    CLOVE_CHAR_EQ(parameters[2].second, '\x30')
}
