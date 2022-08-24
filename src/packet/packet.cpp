/**
 * @file packet.cpp
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet.h"

namespace Packets
{
    Packet::Packet(BaseHeader header, std::vector<std::pair<std::string, unsigned char>> p)
    : Content{p}
    {
        // Combine the header with the existing parameters.
        std::vector<std::pair<std::string, unsigned char>> combined {header.get_parameters()};
        combined.insert(combined.end(), _params.begin(), _params.end());

        _params = combined;

        // Update the packet length parameter.
        set_parameter("packet_length", _params.size());
    }
}