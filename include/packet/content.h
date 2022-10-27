/**
 * @file content.h
 * @brief An abstraction of the contents of a packet.
 * @author G. Chamberlain-Webber
 */

#ifndef CONTENT_H
#define CONTENT_H

#include "packet/byte_container.h"

#include <string>
#include <iostream>

namespace Packets
{
    /**
     * @brief A class specifying a packet contents object, which contains relevant functions
     * to load a packet with data, and read from it.
     */
    class Content : public IByteContainer
    {
    public:
    	Content() = default;
    	explicit Content(std::vector<std::pair<std::string, unsigned char>>& params);
		virtual ~Content() = default;

    	Content(const Content& content) = default;
    	Content(Content&& content) noexcept = default;

    	Content& operator=(const Content& content) = default;
    	Content& operator=(Content&& content) noexcept = default;

    	/**
		 * @brief Checks whether 'key' exists in the content parameters.
		 * 
		 * @param key The key to check for.
         * @return true If 'key' exists.
		 * @return false If 'key' does not exist.
		 */
    	[[nodiscard]] bool check_exists(const std::string& key) const;

    	/**
	     * @brief Gets the object parameters as an array of bytes.
		 * 
		 * @return std::vector<unsigned char>& The object as an array of bytes.
		 */
		std::vector<unsigned char>& get_byte_array() override;

		/**
		 * @brief Set the parameter contained at 'key' to 'value'.
		 * 
		 * @param key The key whose value is to be set.
		 * @param value The new value.
		 */
    	void set_parameter(std::string key, unsigned char value) override;

    	/**
		 * @brief Gets the parameter contained at 'key'.
		 * 
		 * @param key The key to whose value is to be returned.
		 * @return unsigned char The value contained at 'key'
		 */
		unsigned char get_parameter(std::string key) override;

		/**
		 * @brief Gets all the content parameters.
		 * 
		 * @return std::vector<std::pair<std::string, unsigned char>>&  The parameters of the
		 * content object.
		 */
		std::vector<std::pair<std::string, unsigned char>>& get_parameters() override;
        
		friend std::ostream& operator<<(std::ostream& os, Content const& content);

    protected:
		std::vector<std::pair<std::string, unsigned char>> _params;
		std::vector<unsigned char> _bytes;
    };
}

#endif