/**
 * @file invalid_key_exception.h
 * @brief Declares an InvalidKeyException class which inherits from the standard
 * exception class.
 * @author G. Chamberlain-Webber
 */

#ifndef INVALID_KEY_EXCEPTION_H
#define INVALID_KEY_EXCEPTION_H

#include <exception>

struct InvalidKeyException : public std::exception
{
    const char *what() const throw()
    {
        return "Invalid key exception";
    }
};

#endif