/**
 * @file packet_types.h
 * @brief Contains concrete implementations of frequently used packets.
 * @author G. Chamberlain-Webber
 */

#ifndef PACKET_TYPES_H
#define PACKET_TYPES_H

#include "packet/writable.h"
#include "packet/packet.h"

namespace Packets::Types
{
    class PointInformationRequestMX5 : public IWritable
    {
        public:
            PointInformationRequestMX5(int point_number);
            ~PointInformationRequestMX5();

            void write();

        private:
            Packet *_packet;
            int _point_number;
    };
}

#endif