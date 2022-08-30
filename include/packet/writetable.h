/**
 * @file writetable.h
 * @brief Contains an interface IWritable which is used to enforce write functionality to an
 * object.
 * @author G. Chamberlain-Webber
 */

#ifndef WRITABLE_H
#define WRITABLE_H

namespace Packets
{
    class IWritable
    {
        public:
            virtual void write(std::vector<unsigned char>& byte_array) = 0;
    }
}

#endif