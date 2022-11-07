/**
 * @file headers_test.cpp
 * @brief Contains tests to test headers.
 * @author G. Chamberlain-Webber
 */

#include "packet/headers.h"
#include "packet/packet_ids.h"

#define CLOVE_SUITE_NAME headers_test
#include "testing/clove-unit.h"

#include <vector>

// Test 1
CLOVE_TEST(test_mx5_header_contents)
{
    // This test ensures that after creating an MX Speak 5 packet header,
    // it contains the expected values.

    // MX Speak 5 packet header, ID of 0.
    Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};

    const std::vector<unsigned char> expected_values {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const std::vector<unsigned char> actual_values = test_header.get_byte_array();

    for (size_t i = 0; i < expected_values.size(); i++)
    {
        CLOVE_CHAR_EQ(expected_values[i], actual_values[i])
    }
}

// Test 2
CLOVE_TEST(test_mx6_header_contents)
{
    // This test ensures that after creating an MX Speak 6 packet header,
    // it contains the expected values.

    // MX Speak 6 packet header, ID of 0.
    Packets::LocalHeaderMX6 test_header{Packets::PacketID::INVALID};

    const std::vector<unsigned char> expected_values {0x0a, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const std::vector<unsigned char> actual_values = test_header.get_byte_array();

    for (size_t i = 0; i < expected_values.size(); i++)
    {
        CLOVE_CHAR_EQ(expected_values[i], actual_values[i])
    }
}

// Test 3
CLOVE_TEST(test_mx5_header_parameters)
{
    // This test ensures that after creating an MX Speak 5 packet header,
    // it contains the expected values.

    // MX Speak 5 packet header, ID of 0.
    Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};

    const std::vector<std::pair<std::string, unsigned char>> expected_values
    {
        {"hpacket_length",               0x09},
        {"hnetwork_node",                0x00},
        {"hchannel",                     0x00},
        {"hdestination_channel_address", 0x00},
        {"hdestination_task",            0x00},
        {"hsource_channel_address",      0x00},
        {"hsource_task",                 0x00},
        {"hmarker",                      0x00},
        {"hpacket_id",                   0x00}
    };

    const std::vector<std::pair<std::string, unsigned char>> actual_values = test_header.get_parameters();

    for (size_t i = 0; i < expected_values.size(); i++)
    {
        CLOVE_STRING_EQ(expected_values[i].first.c_str(), actual_values[i].first.c_str())
        CLOVE_CHAR_EQ(expected_values[i].second, actual_values[i].second)
    }   
}

// Test 4
CLOVE_TEST(test_mx6_header_parameters)
{
    // This test ensures that after creating an MX Speak 6 packet header,
    // it contains the expected values.

    // MX Speak 6 packet header, ID of 0.
    Packets::LocalHeaderMX6 test_header{Packets::PacketID::INVALID};

    const std::vector<std::pair<std::string, unsigned char>> expected_values
    {
        {"hpacket_length",               0x0a},
        {"hmx_speak_signature",          0xe4},
        {"hnetwork_node",                0x00},
        {"hchannel",                     0x00},
        {"hdestination_channel_address", 0x00},
        {"hdestination_task",            0x00},
        {"hsource_channel_address",      0x00},
        {"hsource_task",                 0x00},
        {"hmarker",                      0x00},
        {"hpacket_id",                   0x00}
    };

    const std::vector<std::pair<std::string, unsigned char>> actual_values = test_header.get_parameters();

    for (size_t i = 0; i < expected_values.size(); i++)
    {
        CLOVE_STRING_EQ(expected_values[i].first.c_str(), actual_values[i].first.c_str())
        CLOVE_CHAR_EQ(expected_values[i].second, actual_values[i].second)
    }
}