/**
 * @file packet_types.h
 * @brief Contains concrete implementations of frequently used packets.
 * @author G. Chamberlain-Webber
 */

#ifndef PACKET_TYPES_H
#define PACKET_TYPES_H

#include "packet/writable.h"
#include "packet/readable.h"
#include "packet/packet.h"
#include "packet/content.h"

namespace Packets::Types
{
    /* Request packets */

    class PointInformationReplyMX5;

    /**
     * @brief A class representing a point information request (MX5).
     */
    class PointInformationRequestMX5 : public IWritable
    {
        public:
            PointInformationRequestMX5(int point_number);
            ~PointInformationRequestMX5();

            /**
             * @brief Writes contents of packet to a serial communication port.
             */
            void write();

            /**
             * @brief Reads contents of a packet from a serial communication port by
             * calling the underlying packet read method.
             * 
             * @return std::vector<unsigned char> The data in the form of a PointInformationReplyMX5.
             */
            PointInformationReplyMX5 *read();

        private:
            Packet *_packet;
            int _point_number;
    };

    /**
     * @brief A class representing a point information request (MX6).
     */
    class PointInformationRequestMX6 : public IWritable
    {
        public:
            PointInformationRequestMX6(int point_number);
            ~PointInformationRequestMX6();

            /** 
             * @brief Writes contents of packet to a serial communication port.
             */
            void write();

            /**
             * @brief Reads contents of a packet from a serial communication port.
             * 
             * @return std::vector<unsignedchar> The read data.
             */
            std::vector<unsigned char> read();

        private:
            Packet *_packet;
            int _point_number;
    };

    /* Reply packets */

    /**
     * @brief A class representing a point information reply (MX5).
     * 
     */
    class PointInformationReplyMX5 : public Content
    {
        public:
            PointInformationReplyMX5(std::vector<unsigned char> data);
            ~PointInformationReplyMX5() = default;
    };
}

#endif