/**
 * @file packet_test.cpp
 * @brief Contains tests to test the packet class and associated functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet.h"

#define CLOVE_SUITE_NAME packet_test
#include "testing/clove-unit.h"

// Test 1
CLOVE_TEST(test_create_packet_no_parameters)
{
    // This test ensures that when a packet is constructed without any additional 
    // parameters, it will match the format of constructing the header on its own.

    const Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    Packets::Packet test_packet{Packets::BaseHeader(test_header)};

    const std::vector<std::pair<std::string, unsigned char>> parameters = test_packet.get_parameters();

    CLOVE_STRING_EQ(parameters[0].first.c_str(), "hpacket_length")
    CLOVE_STRING_EQ(parameters[1].first.c_str(), "hnetwork_node")
    CLOVE_STRING_EQ(parameters[2].first.c_str(), "hchannel")
    CLOVE_STRING_EQ(parameters[3].first.c_str(), "hdestination_channel_address")
    CLOVE_STRING_EQ(parameters[4].first.c_str(), "hdestination_task")
    CLOVE_STRING_EQ(parameters[5].first.c_str(), "hsource_channel_address")
    CLOVE_STRING_EQ(parameters[6].first.c_str(), "hsource_task")
    CLOVE_STRING_EQ(parameters[7].first.c_str(), "hmarker")
    CLOVE_STRING_EQ(parameters[8].first.c_str(), "hpacket_id")

    CLOVE_CHAR_EQ(parameters[0].second, 0x09)
    CLOVE_CHAR_EQ(parameters[1].second, 0x00)
    CLOVE_CHAR_EQ(parameters[2].second, 0x00)
    CLOVE_CHAR_EQ(parameters[3].second, 0x00)
    CLOVE_CHAR_EQ(parameters[4].second, 0x00)
    CLOVE_CHAR_EQ(parameters[5].second, 0x00)
    CLOVE_CHAR_EQ(parameters[6].second, 0x00)
    CLOVE_CHAR_EQ(parameters[7].second, 0x00)
    CLOVE_CHAR_EQ(parameters[8].second, 0x00)
}

// Test 2
CLOVE_TEST(test_packet_length)
{
    // This test ensures that after creating a packet, the packet length parameter has been
    // correctly set based on the header type and the given parameters.

    const Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    const std::vector<std::pair<std::string, unsigned char>> test_parameters
    {
        {"some_param1", 0x00},
        {"some_param2", 0x01},
        {"some_param3", 0x02},
        {"some_param4", 0x03},
        {"some_param5", 0x04},
    };

    Packets::Packet test_packet{Packets::BaseHeader(test_header), test_parameters};

    const unsigned char packet_length = test_packet.get_parameter("hpacket_length");

    CLOVE_CHAR_EQ(packet_length, 0x0e)
}


// Test 3
CLOVE_TEST(test_create_packet_w_parameters)
{
    // This test ensures that when a packet is constructed with additional parameters,
    // it will contain the header contents together with the provided parameters.

    const Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    const std::vector<std::pair<std::string, unsigned char>> test_parameters
    {
        {"some_param1", 0x00},
        {"some_param2", 0x01},
        {"some_param3", 0x02},
        {"some_param4", 0x03},
        {"some_param5", 0x04},
    };

    Packets::Packet test_packet{Packets::BaseHeader(test_header), test_parameters};

    const std::vector<std::pair<std::string, unsigned char>> parameters = test_packet.get_parameters();

    CLOVE_STRING_EQ(parameters[0].first.c_str(),  "hpacket_length")
    CLOVE_STRING_EQ(parameters[1].first.c_str(),  "hnetwork_node")
    CLOVE_STRING_EQ(parameters[2].first.c_str(),  "hchannel")
    CLOVE_STRING_EQ(parameters[3].first.c_str(),  "hdestination_channel_address")
    CLOVE_STRING_EQ(parameters[4].first.c_str(),  "hdestination_task")
    CLOVE_STRING_EQ(parameters[5].first.c_str(),  "hsource_channel_address")
    CLOVE_STRING_EQ(parameters[6].first.c_str(),  "hsource_task")
    CLOVE_STRING_EQ(parameters[7].first.c_str(),  "hmarker")
    CLOVE_STRING_EQ(parameters[8].first.c_str(),  "hpacket_id")
    CLOVE_STRING_EQ(parameters[9].first.c_str(),  "some_param1")
    CLOVE_STRING_EQ(parameters[10].first.c_str(), "some_param2")
    CLOVE_STRING_EQ(parameters[11].first.c_str(), "some_param3")
    CLOVE_STRING_EQ(parameters[12].first.c_str(), "some_param4")
    CLOVE_STRING_EQ(parameters[13].first.c_str(), "some_param5")

    CLOVE_CHAR_EQ(parameters[0].second, 0x0e)
    CLOVE_CHAR_EQ(parameters[1].second, 0x00)
    CLOVE_CHAR_EQ(parameters[2].second, 0x00)
    CLOVE_CHAR_EQ(parameters[3].second, 0x00)
    CLOVE_CHAR_EQ(parameters[4].second, 0x00)
    CLOVE_CHAR_EQ(parameters[5].second, 0x00)
    CLOVE_CHAR_EQ(parameters[6].second, 0x00)
    CLOVE_CHAR_EQ(parameters[7].second, 0x00)
    CLOVE_CHAR_EQ(parameters[8].second, 0x00)
    CLOVE_CHAR_EQ(parameters[9].second, 0x00)
    CLOVE_CHAR_EQ(parameters[10].second, 0x01)
    CLOVE_CHAR_EQ(parameters[11].second, 0x02)
    CLOVE_CHAR_EQ(parameters[12].second, 0x03)
    CLOVE_CHAR_EQ(parameters[13].second, 0x04)
}

// Test 4
CLOVE_TEST(test_packet_byte_array)
{
    // This test ensures that when the get_byte_array() method is called on a packet object,
    // the resulting byte array contains the correct data and the SEQ number and checksum have 
    // been appropriately set.

    const Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    Packets::Packet test_packet{Packets::BaseHeader(test_header)};

    const std::vector<unsigned char> byte_array = test_packet.get_byte_array();

    CLOVE_CHAR_EQ(byte_array[0], 0x01)  // SOH
    CLOVE_CHAR_EQ(byte_array[1], 0x01)  // SEQ
    CLOVE_CHAR_EQ(byte_array[2], 0x09)  // Packet length
    CLOVE_CHAR_EQ(byte_array[3], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[4], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[5], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[6], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[7], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[8], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[9], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[10], 0x00) // Packet header contents
    CLOVE_CHAR_EQ(byte_array[11], 0x0a) // Checksum
}

// Test 5
CLOVE_TEST(test_large_packet_byte_array)
{
    // This test ensures that when the get_byte_array() method is called on a large packet object,
    // the resulting byte array contains the correct data and the SEQ number and checksum have been
    // appropriately set.

    const Packets::LocalHeaderMX5 test_header{Packets::PacketID::INVALID};
    const std::vector<std::pair<std::string, unsigned char>> test_parameters
    {
        {"some_param1", 0x99},
        {"some_param2", 0xe4},
        {"some_param3", 0x12},
        {"some_param4", 0x39},
        {"some_param5", 0x67},
    };
    Packets::Packet test_packet{Packets::BaseHeader(test_header), test_parameters};

    const std::vector<unsigned char> byte_array = test_packet.get_byte_array();

    CLOVE_CHAR_EQ(byte_array[0], 0x01)  // SOH
    CLOVE_CHAR_EQ(byte_array[1], 0x01)  // SEQ
    CLOVE_CHAR_EQ(byte_array[2], 0x0e)  // Packet length
    CLOVE_CHAR_EQ(byte_array[3], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[4], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[5], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[6], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[7], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[8], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[9], 0x00)  // Packet header contents
    CLOVE_CHAR_EQ(byte_array[10], 0x00) // Packet header contents
    CLOVE_CHAR_EQ(byte_array[11], 0x99) // Packet contents
    CLOVE_CHAR_EQ(byte_array[12], 0xe4) // Packet contents
    CLOVE_CHAR_EQ(byte_array[13], 0x12) // Packet contents
    CLOVE_CHAR_EQ(byte_array[14], 0x39) // Packet contents
    CLOVE_CHAR_EQ(byte_array[15], 0x67) // Packet contents
    CLOVE_CHAR_EQ(byte_array[16], 0x3e) // Checksum
}