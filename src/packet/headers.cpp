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
            {"packet_length",               '\x09'},
            {"network_node",                '\x00'},
            {"channel",                     '\x00'},
            {"destination_channel_address", '\x00'},
            {"destination_task",            '\x00'},
            {"source_channel_address",      '\x00'},
            {"source_task",                 '\x00'},
            {"marker",                      '\x00'},
            {"packet_id",                   (unsigned char)packet_id}
        };

        _params = params;
    }

    LocalHeaderMX6::LocalHeaderMX6(PacketID packet_id, std::vector<std::pair<std::string, unsigned char>> p)
    : BaseHeader{packet_id, p}
    {
        std::vector<std::pair<std::string, unsigned char>> params
        {
            {"packet_length",               '\x09'},
            {"mx_speak_signature",          '\xe4'},  // 228
            {"network_node",                '\x00'},
            {"channel",                     '\x00'},
            {"destination_channel_address", '\x00'},
            {"destination_task",            '\x00'},
            {"source_channel_address",      '\x00'},
            {"source_task",                 '\x00'},
            {"marker",                      '\x00'},
            {"packet_id",                   (unsigned char)packet_id},
            {"reserved",                    '\x00'}
        };

        _params = params;
    }
}