/**
 * @file headers.cpp
 * @brief Contains a collection of headers used for packet construction.
 * @author G. Chamberlain-Webber
 */

#include "packet/headers.h"

namespace Packets
{
    BaseHeader::BaseHeader(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : Content{p}
    {
    }

    LocalHeaderMX5::LocalHeaderMX5(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : BaseHeader{packet_id, p}
    {
        std::vector<std::pair<std::string, unsigned char>> params
        {
            {"packet_length",               0x09},
            {"network_node",                0x00},
            {"channel",                     0x00},
            {"destination_channel_address", 0x00},
            {"destination_task",            0x00},
            {"source_channel_address",      0x00},
            {"source_task",                 0x00},
            {"marker",                      0x00},
            {"packet_id",                   (unsigned char)packet_id}
        };

        _params = params;
    }

    LocalHeaderMX6::LocalHeaderMX6(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : BaseHeader{packet_id, p}
    {
        std::vector<std::pair<std::string, unsigned char>> params
        {
            {"packet_length",               0x09},
            {"mx_speak_signature",          0xe4},  // 228
            {"network_node",                0x00},
            {"channel",                     0x00},
            {"destination_channel_address", 0x00},
            {"destination_task",            0x00},
            {"source_channel_address",      0x00},
            {"source_task",                 0x00},
            {"marker",                      0x00},
            {"packet_id",                   (unsigned char)packet_id},
            {"reserved",                    0x00}
        };

        _params = params;
    }
}