/**
 * @file packet.cpp
 * @brief Contains the Packet class and utility functions.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet.h"
#include "packet/serial_data_transfer.h"

#include "constants.h"

namespace Packets
{
    unsigned char Packet::soh = 0x01;
    unsigned char Packet::seq = 0x01;

    Packet::Packet(BaseHeader header, std::vector<std::pair<std::string, unsigned char>> p)
    : Content{p}
    {
        // Combine the header with the existing parameters.
        std::vector<std::pair<std::string, unsigned char>> combined {header.get_parameters()};
        combined.insert(combined.end(), _params.begin(), _params.end());

        _params = combined;

        // Update the packet length parameter.
        set_parameter(Constants::PNAME_PACKET_LENGTH, _params.size());
    }

    Packet::~Packet() {}

    std::vector<unsigned char>& Packet::get_byte_array()
    {
        _bytes.clear();

        // Add on the SOH and SEQ numbers.
        _bytes.push_back(Packet::soh);
        _bytes.push_back(Packet::seq);

        int checksum = 0;
        
        checksum += Packet::seq;

        for (int i = 0; i < _params.size(); i++)
        {
            unsigned char value = _params[i].second;
            _bytes.push_back(value);

            // Calculate checksum
            checksum += value;
        }

        checksum %= Constants::CHECKSUM_MOD;

        _bytes.push_back((unsigned char)checksum);

        return _bytes;
    }

    void Packet::write()
    {
        SerialDataTransfer serial;

        std::vector<unsigned char> data = get_byte_array();
        serial.write(data);

        Packet::increment_seq();
    }

    std::vector<unsigned char> Packet::read()
    {
        SerialDataTransfer *serial = new SerialDataTransfer;

        bool has_data = false;
        std::vector<unsigned char> read_data;

        while (!has_data)
        {
            read_data = serial->read();

            if (read_data.size() == 0)
            {
                // No data could be read so try another packet.
                delete serial;
                Packet::write();
                serial = new SerialDataTransfer();
            } else if (read_data.size() > 1)
            {
                // Data has been found.
                has_data = true;
            }
        }

        // If data has been read. We should send back an acknowledgememt (ACK) byte.
        if (read_data.size() > 1)
        {
            serial->write_byte(Constants::ACK);
        }

        delete serial;

        return read_data;
    }

    void Packet::increment_seq()
    {
        seq++;
                
        // Wrap round if SEQ exceeds the constant value.
        if (seq > Constants::SEQ_WRAP)
        {
            seq = Constants::SEQ;
        }
    }
}