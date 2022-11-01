/**
 * @file packet.cpp
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet.h"
#include "packet/serial_data_transfer.h"

#include "constants.h"
#include "profiling/instrumentation.h"

#include <memory>


namespace Packets
{
    unsigned char Packet::soh = 0x01;
    unsigned char Packet::seq = 0x01;

    Packet::Packet(BaseHeader header, std::vector<std::pair<std::string, unsigned char>> p)
		: Content{p}
    {
        // Combine the header with the existing parameters.
        std::vector combined {header.get_parameters()};
        combined.insert(combined.end(), _params.begin(), _params.end());

        _params = combined;

        // Update the packet length parameter.
        Content::set_parameter(Constants::PNAME_PACKET_LENGTH, static_cast<unsigned char>(_params.size()));
    }

    std::vector<unsigned char>& Packet::get_byte_array()
    {
        BX_PROFILE_FUNCTION();

        _bytes.clear();

        // Add on the SOH and SEQ numbers.
        _bytes.push_back(soh);
        _bytes.push_back(seq);

        int checksum = 0;
        
        checksum += seq;

        for (const auto& [fst, snd] : _params)
        {
            unsigned char value = snd;
            _bytes.push_back(value);

            // Calculate checksum
            checksum += value;
        }

        checksum %= Constants::CHECKSUM_MOD;

        _bytes.push_back(static_cast<unsigned char>(checksum));

        return _bytes;
    }

    void Packet::write()
    {
        BX_PROFILE_FUNCTION();

        SerialDataTransfer serial;

        const std::vector<unsigned char> data = get_byte_array();
        serial.write(data);

        increment_seq();
    }

    std::vector<unsigned char> Packet::read()
    {
        BX_PROFILE_FUNCTION();

        std::unique_ptr<SerialDataTransfer> serial{new SerialDataTransfer};

        bool has_data = false;
        std::vector<unsigned char> read_data;

        while (!has_data)
        {
            read_data = serial->read();

            if (read_data.empty())
            {
                // No data could be read so try another packet.

                // Force a deletion of the SerialDataTransfer object held by the unique pointer
                // to ensure that there is not a serial port in use when we try to write the 
                // next packet.
                if (serial.release())
                {
					serial.reset();
                }

                Packet::write();

                serial = std::unique_ptr<SerialDataTransfer>{new SerialDataTransfer()};
            } else if (read_data.size() > 1)
            {
                // Data has been found.
                has_data = true;
            }
        }

        // If data has been read. We should send back an acknowledgement (ACK) byte.
        if (read_data.size() > 1)
        {
            serial->write_byte(Constants::ACK);
        }

        return read_data;
    }

    void Packet::increment_seq()
    {
        BX_PROFILE_FUNCTION();

        seq++;
                
        // Wrap round if SEQ exceeds the constant value.
        if (seq > Constants::SEQ_WRAP)
        {
            seq = Constants::SEQ;
        }
    }
}
