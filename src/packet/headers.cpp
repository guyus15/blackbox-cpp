/**
 * @file headers.cpp
 * @brief Contains a collection of headers used for packet construction.
 * @author G. Chamberlain-Webber
 */

#include "packet/headers.h"

#include "constants.h"

#include <string>
#include <utility>

namespace Packets
{
    BaseHeader::BaseHeader(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : Content{p}
    {
    }

    LocalHeaderMX5::LocalHeaderMX5(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : BaseHeader{packet_id, std::move(p)}
    {
	    const std::vector<std::pair<std::string, unsigned char>> params
        {
            {Constants::PNAME_PACKET_LENGTH,               0x09},
            {Constants::PNAME_NETWORK_NODE,                0x00},
            {Constants::PNAME_CHANNEL,                     0x00},
            {Constants::PNAME_DESTINATION_CHANNEL_ADDRESS, 0x00},
            {Constants::PNAME_DESTINATION_TASK,            0x00},
            {Constants::PNAME_SOURCE_CHANNEL_ADDRESS,      0x00},
            {Constants::PNAME_SOURCE_TASK,                 0x00},
            {Constants::PNAME_MARKER,                      0x00},
            {Constants::PNAME_PACKET_ID,                   static_cast<unsigned char>(packet_id)}
        };

        _params = params;
    }

    LocalHeaderMX6::LocalHeaderMX6(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : BaseHeader{packet_id, std::move(p)}
    {
	    const std::vector<std::pair<std::string, unsigned char>> params
        {
            {Constants::PNAME_PACKET_LENGTH,               0x0a},
            {Constants::PNAME_MX6_SPEAKSIGNATURE,          0xe4},  // 228
            {Constants::PNAME_NETWORK_NODE,                0x00},
            {Constants::PNAME_CHANNEL,                     0x00},
            {Constants::PNAME_DESTINATION_CHANNEL_ADDRESS, 0x00},
            {Constants::PNAME_DESTINATION_TASK,            0x00},
            {Constants::PNAME_SOURCE_CHANNEL_ADDRESS,      0x00},
            {Constants::PNAME_SOURCE_TASK,                 0x00},
            {Constants::PNAME_MARKER,                      0x00},
            {Constants::PNAME_PACKET_ID,                   static_cast<unsigned char>( packet_id)}
        };

        _params = params;
    }
}