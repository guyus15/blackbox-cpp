/**
 * @file serial_data_transfer.cpp
 * @brief Responsible for setting up writing and reading across a serial data communication channel.
 * @author G. Chamberlain-Webber
 */

#include "packet/serial_data_transfer.h"
#include "config.h"
#include "output.h"

#include "profiling/instrumentation.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace Packets
{
    SerialDataTransfer::SerialDataTransfer()
    {
        BX_PROFILE_FUNCTION();

        const std::string& com_port = Config::get_com_port();
        const int baudrate = Config::get_baudrate();
        const enum SerialDataBits databits = Config::get_bytesize();
        const enum SerialParity parity = Config::get_parity();
        const enum SerialStopBits stopbits = Config::get_stopbits();

        if (_serial.openDevice(com_port.c_str(),
                                baudrate,
                                databits,
                                parity,
                                stopbits) != 1) 
        {
            BX_LOG_ERROR("There has been an error opening the serial device.");
            exit(EXIT_FAILURE);
        }
    }

    SerialDataTransfer::~SerialDataTransfer()
    {
        BX_PROFILE_FUNCTION();

        if (_serial.isDeviceOpen())
        {
            _serial.closeDevice();
        }
    }

    void SerialDataTransfer::write(const std::vector<unsigned char>& data)
    {
        BX_PROFILE_FUNCTION();

        for (const auto& byte : data)
        {
            _serial.writeChar(byte);
        }
    }

    void SerialDataTransfer::write_byte(const unsigned char value)
    {
        BX_PROFILE_FUNCTION();

         _serial.writeChar(value);
    }

    std::vector<unsigned char> SerialDataTransfer::read()
    {
        BX_PROFILE_FUNCTION();

        bool ack_acquired = false;
        char ack = 0;

        while (!ack_acquired)
        {
            _serial.readChar(&ack);

            if (ack)
            {
                ack_acquired = true;
            }
        }

        std::vector<unsigned char> read_data;

        char soh = 0;
        char seq = 0;
        char packet_length = 0;

        _serial.readChar(&soh, 500);

        if (soh == 0)
        {
            // If the SOH cannot be read, clearly there is no response from the packet,
            // so we'll return no data and try sending another packet with a different SEQ.
            return read_data;
        }

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
