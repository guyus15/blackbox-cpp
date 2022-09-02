/**
 * @file content.cpp
 * @brief An abstraction of the contents of a packet.
 * @author G. Chamberlain-Webber
 */

#include "packet/content.h"
#include "exceptions/invalid_key_exception.h"

#include <cstdio>
#include <cstdlib>

namespace Packets
{
    Content::Content()
    : _params{}, _bytes{}
    {}

    Content::Content(std::vector<std::pair<std::string, unsigned char>>& params)
    : _params{params}, _bytes{}
    {
        get_byte_array();
    }

    bool Content::check_exists(std::string key)
    {
        for (const auto& pairs : _params)
        {
            std::string k = pairs.first;

            if (key == k)
            {
                return true;
            }
        }

        return false;
    }

    std::vector<unsigned char>& Content::get_byte_array()
    {
        for (const auto& pairs : _params)
        {
            unsigned char value = pairs.second;
            _bytes.push_back(value);
        }

        return _bytes;
    } 

    void Content::set_parameter(std::string key, unsigned char value)
    {
        if (!check_exists(key))
        {
            fprintf(stderr, "'%s' can not be found in the content parameters.\n", key.c_str());
            throw InvalidKeyException();
        }

        for (int i = 0; i < _params.size(); i++)
        {
            if (_params[i].first == key)
            {
                _params[i].second = value;
                break;
            }
        }
    }

    unsigned char Content::get_parameter(std::string key)
    {
        if (!check_exists(key))
        {
            fprintf(stderr, "'%s' can not be found in the content parameters.\n", key.c_str());
            throw InvalidKeyException();
        }

        unsigned char param = 0;

        for (const auto& pair : _params)
        {
            if (pair.first == key)
            {
                param = pair.second;
                break;
            }
        }

        return param;
    }

    std::vector<std::pair<std::string, unsigned char>>& Content::get_parameters()
    {
        return _params;
    }

    std::ostream& operator<<(std::ostream& os, Content const& content)
    {
        for (const auto& pair : content._params)
        {
            os << pair.first << ": " << std::hex << (int)pair.second << std::endl;
        }       

        return os;
    }
}