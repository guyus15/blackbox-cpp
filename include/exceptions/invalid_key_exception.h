/**
 * @file invalid_key_exception.h
 * @brief Declares an InvalidKeyException class which inherits from the standard
 * exception class.
 * @author G. Chamberlain-Webber
 */

#ifndef INVALID_KEY_EXCEPTION_H
#define INVALID_KEY_EXCEPTION_H

#include <exception>

/**
 * @brief A struct representing an invalid key exception.
 */
struct InvalidKeyException final : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Invalid key exception";
	}
};

#endif