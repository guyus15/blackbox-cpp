/**
 * @file content.cpp
 * @brief An abstraction of the contents of a packet.
 * @author G. Chamberlain-Webber
 */

#include "packet/content.h"
#include "exceptions/invalid_key_exception.h"

#include <algorithm>
#include <iostream>

namespace Packets
{
    Content::Content(std::vector<std::pair<std::string, unsigned char>>& params)
    : _params{params}, _bytes{}
    {
	    Content::get_byte_array();
    }

    bool Content::check_exists(const std::string& key) const
    {
        return std::any_of(_params.begin(), _params.end(), 
            [key](const std::pair<std::string, unsigned char>& pairs) { return key == pairs.first; });
    }

    std::vector<unsigned char>& Content::get_byte_array()
    {
        for (const auto& [fst, snd] : _params)
        {
            unsigned char value = snd;
            _bytes.push_back(value);
        }

        return _bytes;
    } 

    void Content::set_parameter(const std::string key, const unsigned char value)
    {
        if (!check_exists(key))
        {
            std::cerr << "'" << key <<"' can not be found in the content parameters" << std::endl;
            throw InvalidKeyException();
        }

        for (auto& [fst, snd] : _params)
        {
            if (fst == key)
            {
	            snd = value;
                break;
            }
        }
    }

    unsigned char Content::get_parameter(const std::string key)
    {
        if (!check_exists(key))
        {
			std::cerr << "'" << key <<"' can not be found in the content parameters" << std::endl;
            throw InvalidKeyException();
        }

        unsigned char param = 0;

        for (const auto& [fst, snd] : _params)
        {
            if (fst == key)
            {
                param = snd;
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
        for (const auto& [fst, snd] : content._params)
        {
            os << fst << ": " << std::hex << static_cast<int>(snd) << std::endl;
        }       

        return os;
    }
}