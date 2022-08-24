/**
 * @file packet.h
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/headers.h"

namespace Packets
{
    class Packet : public Content
    {
        public:
            Packet(BaseHeader header,
            std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
    };
}