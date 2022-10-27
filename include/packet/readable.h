/**
 * @file readable.h
 * @brief Contains the interface IReadable usd to enforce reading functionality on an object.
 * @author G. Chamberlain-Webber
 */

#ifndef READABLE_H
#define READABLE_H

#include <vector>

namespace Packets
{
	/**
	 * @bried Interface for readable objects.
	 */
	class IReadable
    {
    public:
		virtual std::vector<unsigned char> read() = 0;
    };
}

#endif