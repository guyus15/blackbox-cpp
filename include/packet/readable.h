/**
 * @file readable.h
 * @brief Contains the interface IReadable usd to enforce reading functionality on an object.
 * @author G. Chamberlain-Webber
 */

#include <vector>

namespace Packets
{
    class IReadable
    {
        public:
            virtual std::vector<unsigned char> read() = 0;
    };
}