/**
 * @file headers.h
 * @brief Contains a collection of headers used for packet construction.
 * @author G. Chamberlain-Webber
 */

#ifndef HEADERS_H
#define HEADERS_H

#include "packet/content.h"
#include "packet/packet_ids.h"

namespace Packets
{
	/**
	 * @brief General class for packet headers.
	 */
	class BaseHeader : public Content
	{
	public:
		explicit BaseHeader(PacketID packet_id = PacketID::INVALID,
			std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
	};

	/**
	 * @brief An MX Speak 5 Local Header, which is used when connected to the panel's COM2
	 * serial port.
	 */
	class LocalHeaderMX5 final : public BaseHeader
	{
	public:
		explicit LocalHeaderMX5(PacketID packet_id,
			std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
	};

	/**
	 * @brief An MX Speak 6 Local Header, which is used when connected to the panel's COM2
	 * serial port.
	 */
	class LocalHeaderMX6 final : public BaseHeader
	{
	public:
		explicit LocalHeaderMX6(PacketID packet_id,
			std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());
	};
}

#endif