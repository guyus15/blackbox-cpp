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

            /**
             * @brief Writes contents of packet to a serial communication port.
             */
            void write();

        private:
            Packet *_packet;
            int _point_number;
    };

    class PointInformationRequestMX6 : public IWritable
    {
        public:
            PointInformationRequestMX6(int point_number);
            ~PointInformationRequestMX6();

            /** 
             * @brief Writes contents of packet to a serial communication port.
             */
            void write();

        private:
            Packet *_packet;
            int _point_number;
    };
}

#endif