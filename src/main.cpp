/**
 * @file main.cpp
 * @brief The main entry point for the program.
 * @author G. Chamberlain-Webber
 */

#include "config.h"
#include "packet/packet.h"

#include <cstdio>
#include <vector>

int main()
{
    Config::get_log_dir();

    Packets::LocalHeaderMX5 header{Packets::PacketID::INVALID};
    Packets::Packet packet{header};

    packet.write();

    return 0;
}