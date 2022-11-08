/**
 * @file main.cpp
 * @brief The main entry point for the program.
 * @author G. Chamberlain-Webber
 */

#include "application.h"
#include "config.h"

#include "packet/packet_types.h"

using namespace Packets::Types;

int main()
{
	const Config::ProtocolVersion protocol_version = Config::get_protocol_version();

	if (protocol_version == Config::ProtocolVersion::MX5)
	{
		BX_LOG_INFO("Protocol version: MX Speak Version 5");
		Application<PointInformationRequestMX5, PointInformationReplyMX5> application{};
		application.run();
	}
	else
	{
		BX_LOG_INFO("Protocol version: MX Speak Version 6");
		Application<PointInformationRequestMX6, PointInformationReplyMX6> application{};
		application.run();
	}

    return 0;
}