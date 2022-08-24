/**
 * @file headers.h
 * @brief Contains a collection of headers used for packet construction.
 * @author G. Chamberlain-Webber
 */

#ifndef HEADERS_H
#define HEADERS_H

#include "packet/content.h"
#include "packet/packet_ids.h"

namespace Packet
{
    class LocalHeaderMX5 : public Content
    {
        public:
            LocalHeaderMX5(PacketID packet_id, 
            std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
    };

    class LocalHeaderMX6 : public Content
    {
        public:
            LocalHeaderMX6(PacketID packet_id,
            std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
    };
}

#endif