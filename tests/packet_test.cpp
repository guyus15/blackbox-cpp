/**
 * @file packet_test.cpp
 * @brief Contains tests to test the packet class and associated functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet.h"

#define CLOVE_SUITE_NAME packet_test
#include "testing/clove-unit.h"

#include <cstdio>

// Test 1
CLOVE_TEST(test_create_packet_no_parameters)
{
    // This test ensures that when a packet is constructed without any additional 
    // parameters, it will match the format of constructing the header on its own.

    Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    Packets::Packet test_packet{test_header};

    std::vector<std::pair<std::string, unsigned char>> parameters = test_packet.get_parameters();

    CLOVE_STRING_EQ(parameters[0].first.c_str(), "packet_length");
    CLOVE_STRING_EQ(parameters[1].first.c_str(), "network_node");
    CLOVE_STRING_EQ(parameters[2].first.c_str(), "channel");
    CLOVE_STRING_EQ(parameters[3].first.c_str(), "destination_channel_address");
    CLOVE_STRING_EQ(parameters[4].first.c_str(), "destination_task");
    CLOVE_STRING_EQ(parameters[5].first.c_str(), "source_channel_address");
    CLOVE_STRING_EQ(parameters[6].first.c_str(), "source_task");
    CLOVE_STRING_EQ(parameters[7].first.c_str(), "marker");
    CLOVE_STRING_EQ(parameters[8].first.c_str(), "packet_id");

    CLOVE_CHAR_EQ(parameters[0].second, '\x09');
    CLOVE_CHAR_EQ(parameters[1].second, '\x00');
    CLOVE_CHAR_EQ(parameters[2].second, '\x00');
    CLOVE_CHAR_EQ(parameters[3].second, '\x00');
    CLOVE_CHAR_EQ(parameters[4].second, '\x00');
    CLOVE_CHAR_EQ(parameters[5].second, '\x00');
    CLOVE_CHAR_EQ(parameters[6].second, '\x00');
    CLOVE_CHAR_EQ(parameters[7].second, '\x00');
    CLOVE_CHAR_EQ(parameters[8].second, '\x00');
}

// Test 2
CLOVE_TEST(test_packet_length)
{
    // This test ensures that after creating a packet, the packet length parameter has been
    // correctly set based on the header type and the given parameters.

    Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    std::vector<std::pair<std::string, unsigned char>> test_parameters
    {
        {"some_param1", '\x00'},
        {"some_param2", '\x01'},
        {"some_param3", '\x02'},
        {"some_param4", '\x03'},
        {"some_param5", '\x04'},
    };

    Packets::Packet test_packet{test_header, test_parameters};

    unsigned char packet_length = test_packet.get_parameter("packet_length");

    CLOVE_CHAR_EQ(packet_length, '\x0e');
}


// Test 3
CLOVE_TEST(test_create_packet_w_parameters)
{
    // This test ensures that when a packet is constructed with additional parameters,
    // it will contain the header contents together with the provided parameters.

    Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    std::vector<std::pair<std::string, unsigned char>> test_parameters
    {
        {"some_param1", '\x00'},
        {"some_param2", '\x01'},
        {"some_param3", '\x02'},
        {"some_param4", '\x03'},
        {"some_param5", '\x04'},
    };

    Packets::Packet test_packet{test_header, test_parameters};

    std::vector<std::pair<std::string, unsigned char>> parameters = test_packet.get_parameters();

    CLOVE_STRING_EQ(parameters[0].first.c_str(), "packet_length");
    CLOVE_STRING_EQ(parameters[1].first.c_str(), "network_node");
    CLOVE_STRING_EQ(parameters[2].first.c_str(), "channel");
    CLOVE_STRING_EQ(parameters[3].first.c_str(), "destination_channel_address");
    CLOVE_STRING_EQ(parameters[4].first.c_str(), "destination_task");
    CLOVE_STRING_EQ(parameters[5].first.c_str(), "source_channel_address");
    CLOVE_STRING_EQ(parameters[6].first.c_str(), "source_task");
    CLOVE_STRING_EQ(parameters[7].first.c_str(), "marker");
    CLOVE_STRING_EQ(parameters[8].first.c_str(), "packet_id");
    CLOVE_STRING_EQ(parameters[9].first.c_str(), "some_param1");
    CLOVE_STRING_EQ(parameters[10].first.c_str(), "some_param2");
    CLOVE_STRING_EQ(parameters[11].first.c_str(), "some_param3");
    CLOVE_STRING_EQ(parameters[12].first.c_str(), "some_param4");
    CLOVE_STRING_EQ(parameters[13].first.c_str(), "some_param5");

    CLOVE_CHAR_EQ(parameters[0].second, '\x0e');
    CLOVE_CHAR_EQ(parameters[1].second, '\x00');
    CLOVE_CHAR_EQ(parameters[2].second, '\x00');
    CLOVE_CHAR_EQ(parameters[3].second, '\x00');
    CLOVE_CHAR_EQ(parameters[4].second, '\x00');
    CLOVE_CHAR_EQ(parameters[5].second, '\x00');
    CLOVE_CHAR_EQ(parameters[6].second, '\x00');
    CLOVE_CHAR_EQ(parameters[7].second, '\x00');
    CLOVE_CHAR_EQ(parameters[8].second, '\x00');
    CLOVE_CHAR_EQ(parameters[9].second, '\x00');
    CLOVE_CHAR_EQ(parameters[10].second, '\x01');
    CLOVE_CHAR_EQ(parameters[11].second, '\x02');
    CLOVE_CHAR_EQ(parameters[12].second, '\x03');
    CLOVE_CHAR_EQ(parameters[13].second, '\x04');
}