/**
 * @file packet.h
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#ifndef PACKET_H
#define PACKET_H

#include "packet/headers.h"
#include "packet/writable.h"
#include "packet/readable.h"

namespace Packets
{
	/**
	 * @brief Represents a packet sent via some communication method.
	 */
	class Packet final : public Content, public IWritable, public IReadable
	{
	public:
		static unsigned char soh;
		static unsigned char seq;

		explicit Packet(BaseHeader header, std::vector<std::pair<std::string, unsigned char>> p = std::vector<std::pair<std::string, unsigned char>>());

		Packet(const Packet& packet) = default;
		Packet(Packet&& packet) noexcept = default;

		Packet& operator=(const Packet& packet) = default;
		Packet& operator=(Packet&& packet) noexcept = default;

		~Packet() override = default;

		/**
		 * @brief Gets the object parameters as an array of bytes.
		 *
		 * @return std::vector<unsigned char>& The object as an array of bytes.
		 */
		std::vector<unsigned char>& get_byte_array() override;

		/**
		 * @brief Writes data to a serial communication port.
		 */
		void write() override;

		/**
		 * @brief Reads from a serial communication port.
		 */
		std::vector<unsigned char> read() override;

		/**
		 * @brief Increments the SEQ number.
		 */
		static void increment_seq();
	};
}

#endif