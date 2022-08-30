/**
 * @file serial_data_transfer.cpp
 * @brief Responsible for setting up writing and reading across a serial data communication channel.
 * @author G. Chamberlain-Webber
 */

#include "packet/serial_data_transfer.h"

#include <cstdio>
#include <cstdlib>

namespace Packets
{
    SerialDataTransfer::SerialDataTransfer()
    {
        // Hard-coded serial setup for now, but this will later be be configurable.
        if (!_serial.openDevice("COM8", 115200)) 
        {
            fprintf(stderr, "Error: There has been an error opening serial device.\n");
            exit(EXIT_FAILURE);
        }
    }

    SerialDataTransfer::~SerialDataTransfer()
    {
        if (_serial.isDeviceOpen())
        {
            _serial.closeDevice();
        }
    }

    void SerialDataTransfer::write(std::vector<unsigned char>& data)
    {
        for (const auto& byte : data)
        {
            _serial.writeChar(byte);
        }
    }

    void SerialDataTransfer::write_byte(unsigned char value)
    {
         _serial.writeChar(value);
    }

    std::vector<unsigned char> SerialDataTransfer::read()
    {
        bool ack_acquired = false;
        char ack = 0;

        printf("Acquiring ACK...\n");

        while (!ack_acquired)
        {
            _serial.readChar(&ack);

            if (ack)
            {
                ack_acquired = true;
            }
        }

        printf("ACK acquired.\n");

        std::vector<unsigned char> read_data;

        char soh = 0;
        char seq = 0;
        char packet_length = 0;

        _serial.readChar(&soh);
        _serial.readChar(&seq);
        _serial.readChar(&packet_length);

        read_data.push_back(soh);
        read_data.push_back(seq);
        read_data.push_back(packet_length);

        char current_byte = 0;
        for (int i = 0; i < packet_length - 1; i++)
        {
            _serial.readChar(&current_byte);
            read_data.push_back(current_byte);
        }

        return read_data;
    }
}