/**
 * @file packet.h
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/headers.h"
#include "packet/writable.h"
#include "packet/readable.h"

namespace Packets
{
    class Packet : public Content, public IWritable, public IReadable
    {
        public:
            static unsigned char soh;
            static unsigned char seq;

            Packet(BaseHeader header,
            std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
            ~Packet();

            /**
             * @brief Gets the object parameters as an array of bytes.
             * 
             * @return std::vector<unsigned char>& The object as an array of bytes.
             */
            std::vector<unsigned char>& get_byte_array();

            /**
             * @brief Writes data to a serial communication port.
             */
            void write();

            /**
             * @brief Reads from a serial communication port.
             */
            void read();

            /**
             * @brief Increments the SEQ number.
             */
            static void increment_seq();
    };
}