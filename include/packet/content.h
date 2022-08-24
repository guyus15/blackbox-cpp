/**
 * @file content.h
 * @brief An abstraction of the contents of a packet.
 * @author G. Chamberlain-Webber
 */

#ifndef CONTENT_H
#define CONTENT_H

#include "packet/byte_container.h"

#include <string>
#include <iostream>

namespace Packets
{
    class Content : public IByteContainer
    {
        public:
            Content(std::vector<std::pair<std::string, unsigned char>>& params);

            bool check_exists(std::string key);

            std::vector<unsigned char>& get_byte_array();
            void set_parameter(std::string key, unsigned char value);
            unsigned char get_parameter(std::string key);
            std::vector<std::pair<std::string, unsigned char>>& get_parameters();

            friend std::ostream& operator<<(std::ostream& os, Content const& v);

        protected:
            std::vector<std::pair<std::string, unsigned char>> _params;
            std::vector<unsigned char> _bytes;
    };
}

#endif