/**
 * @file byte_container.h
 * @brief Contains an interface IByteContainer used to enforce the presence specific byte-related functions
 * inside a class.
 * @author G. Chamberlain-Webber
 */

#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

#include <string>
#include <vector>

namespace Packets
{
	/**
	 * @brief Interface for byte container objects.
	 */
	class IByteContainer
    {
    public:
    	virtual std::vector<unsigned char>& get_byte_array() = 0;
    	virtual void set_parameter(std::string key, unsigned char value) = 0;
    	virtual unsigned char get_parameter(std::string key) = 0;
    	virtual std::vector<std::pair<std::string, unsigned char>>& get_parameters() = 0;
    };
}

#endif