/**
 * @file writable.h
 * @brief Contains an interface IWritable which is used to enforce write functionality to an
 * object.
 * @author G. Chamberlain-Webber
 */

#ifndef WRITABLE_H
#define WRITABLE_H

namespace Packets
{
	/**
	 * @brief Interface for writable objects.
	 */
	class IWritable
    {
    public:
    	virtual void write() = 0;
    };
}

#endif