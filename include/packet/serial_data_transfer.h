/**
 * @file serial_data_transfer.h
 * @brief Responsible for setting up writing and reading across a serial data communication channel.
 * @author G. Chamberlain-Webber
 */

#ifndef SERIAL_DATA_TRANSFER_H
#define SERIAL_DATA_TRANSFER_H

#include "serial/serialib.h"

#include <vector>

namespace Packets
{
	/**
	 * @brief Abstracts reading and writing across a serial communication port.
	 */
	class SerialDataTransfer
	{
	public:
		SerialDataTransfer();
		~SerialDataTransfer();

		SerialDataTransfer(const SerialDataTransfer& s) = default;
		SerialDataTransfer(SerialDataTransfer&& s) noexcept = default;

		SerialDataTransfer& operator=(const SerialDataTransfer& s) = default;
		SerialDataTransfer& operator=(SerialDataTransfer&& s) noexcept = default;

		/**
		 * @brief Writes data across a serial communication port.
		 *
		 * @param data The data to be written.
		 */
		void write(const std::vector<unsigned char>& data);

		/**
		 * @brief Writes a single byte of data across a serial communication port.
		 *
		 * @param value The byte of data to be written.
		 */
		void write_byte(unsigned char value);

		/**
		 * @brief Reads data from a serial communication port.
		 *
		 * @return The data (if any) read from the serial communication port.
		 */
		std::vector<unsigned char> read();

	private:
		serialib _serial;
	};
}

#endif
