/**
 * @file packet_decoding.h
 * @brief Provides functions to decode a series of bytes into a human-readable format.
 * @author G. Chamberlain-Webber
 */

#ifndef PACKET_DECODING_H
#define PACKET_DECODING_H

#include <string>
#include <vector>

namespace Packets::Decoding
{
	namespace MX5
	{
		/**
		 * @brief Decodes an MX5 Point Information Reply packet into a human-readable format.
		 *
		 * @return std::vector<std::string> A human-readable representation of the bytes of an MX5
		 * Point Information Reply packet.
		 */
		std::vector<std::string> decode_point_information_reply(const std::vector<unsigned char>& data);
	}

	namespace MX6
	{

	}
}

#endif