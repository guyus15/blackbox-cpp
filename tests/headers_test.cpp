/**
 * @file header_test.cpp
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
    Packet::LocalHeaderMX5 test_header{Packet::PacketID::INVALID};

    std::vector<unsigned char> expected_values {'\x09', '\00', '\00', '\00', '\00', '\00', '\00', '\00', '\00'};
    std::vector<unsigned char> actual_values = test_header.get_byte_array();

    for (int i = 0; i < expected_values.size(); i++)
    {
        CLOVE_CHAR_EQ(expected_values[i], actual_values[i]);
    }
}

// Test 2
CLOVE_TEST(test_mx6_header_contents)
{
    // This test ensures that after creating an MX Speak 6 packet header,
    // it contains the expected values.

    // MX Speak 5 packet header, ID of 0.
    Packet::LocalHeaderMX6 test_header{Packet::PacketID::INVALID};

    std::vector<unsigned char> expected_values {'\x09', 228, '\x00', '\x00','\x00','\x00','\x00','\x00','\x00','\x00','\x00'};
    std::vector<unsigned char> actual_values = test_header.get_byte_array();

    for (int i = 0; i < expected_values.size(); i++)
    {
        CLOVE_CHAR_EQ(expected_values[i], actual_values[i]);
    }
}