/**
 * @file packet_types.h
 * @brief Contains concrete implementations of frequently used packets.
 * @author G. Chamberlain-Webber
 */

#ifndef PACKET_TYPES_H
#define PACKET_TYPES_H

#include "packet/writable.h"
#include "packet/packet.h"
#include "packet/content.h"
#include "packet/packet_decoding.h"

#include "config.h"

#include "profiling/instrumentation.h"

#include <sstream>


namespace Packets::Types
{
    /* Request packets */

    class PointInformationReplyMX5;

    /**
     * @brief A class representing a point information request (MX5).
     */
    class PointInformationRequestMX5 final : public IWritable
    {
    public:
        PointInformationRequestMX5(int point_number, int loop_number);
        virtual ~PointInformationRequestMX5();

        PointInformationRequestMX5(const PointInformationRequestMX5& p) = default;
        PointInformationRequestMX5(PointInformationRequestMX5&& p) noexcept = default;

        PointInformationRequestMX5& operator=(const PointInformationRequestMX5& p) = default;
        PointInformationRequestMX5& operator=(PointInformationRequestMX5&& p) noexcept = default;

        /**
         * @brief Writes contents of packet to a serial communication port.
         */
        void write() override;

        /**
         * @brief Reads contents of a packet from a serial communication port by
         * calling the underlying packet read method.
         *
         * @return std::vector<unsigned char> The read data.
         */
        [[nodiscard]] std::vector<unsigned char> read() const;

    private:
        Packet* _packet;
        int _point_number;
        int _loop_number;
    };

    /**
     * @brief A class representing a point information request (MX6).
     */
    class PointInformationRequestMX6 final : public IWritable
    {
    public:
        PointInformationRequestMX6(int point_number, int loop_number);
        virtual ~PointInformationRequestMX6();

        PointInformationRequestMX6(const PointInformationRequestMX6& p) = default;
        PointInformationRequestMX6(PointInformationRequestMX6&& p) noexcept = default;

        PointInformationRequestMX6& operator=(const PointInformationRequestMX6& p) = default;
        PointInformationRequestMX6& operator=(PointInformationRequestMX6&& p) noexcept = default;

        /**
         * @brief Writes contents of packet to a serial communication port.
         */
        void write() override;

        /**
         * @brief Reads contents of a packet from a serial communication port.
         *
         * @return std::vector<unsignedchar> The read data.
         */
        [[nodiscard]] std::vector<unsigned char> read() const;

    private:
        Packet* _packet;
        int _point_number;
        int _loop_number;
    };

    /* Reply packets */

    /**
     * @brief A class representing a point information reply (MX5).
     *
     */
    class PointInformationReplyMX5 final : public Content
    {
    public:
        explicit PointInformationReplyMX5(std::vector<unsigned char> data);
        ~PointInformationReplyMX5() override = default;

        PointInformationReplyMX5(const PointInformationReplyMX5& p) = default;
        PointInformationReplyMX5(PointInformationReplyMX5&& p) noexcept = default;

        PointInformationReplyMX5& operator=(const PointInformationReplyMX5& p) = default;
        PointInformationReplyMX5& operator=(PointInformationReplyMX5&& p) noexcept = default;

        /**
         * @brief Returns the reply status of the point information reply.
         *
         * @return true The reply has been successful.
         * @return false The reply has not been successful.
         */
        bool reply_successful();
    };

    /**
     * @brief A class representing a point information reply (MX6).
     */
    class PointInformationReplyMX6 final : public Content
    {
    public:
        explicit PointInformationReplyMX6(std::vector<unsigned char> data);
        ~PointInformationReplyMX6() override = default;

        PointInformationReplyMX6(const PointInformationReplyMX6& p) = default;
        PointInformationReplyMX6(PointInformationReplyMX6&& p) noexcept = default;

        PointInformationReplyMX6& operator=(const PointInformationReplyMX6& p) = default;
        PointInformationReplyMX6& operator=(PointInformationReplyMX6&& p) noexcept = default;

        /**
         * @brief Returns the reply status of the point information reply.
         *
         * @return true The reply has been successful.
         * @return false The reply has not been successful.
         */
        bool reply_successful();
    };
}

namespace Packets
{
    /**
    * @brief Gets the headers required for writing to a log file.
    *
    * @return std::vector<std::string> The headers.
    */
    std::vector<std::string> get_headers();

    /**
     * @brief Gets the point information reply in a CSV format.
     * @tparam T The type of reply.
     * @param reply The reply.
     * @return std::string The CSV format point information reply.
     */
    template <typename T>
    std::string get_as_csv(T reply)
    {
        BX_PROFILE_FUNCTION();

        std::stringstream log_stream;
        bool remove_comma = false;
        const std::vector<unsigned char> byte_array = static_cast<Content>(reply).get_byte_array();
        const Config::LogMode log_mode = Config::get_log_mode();

        if (log_mode == Config::LogMode::Normal)
        {
            // Store hexadecimal byte values in CSV file.
            for (const auto& value : byte_array)
            {
                log_stream << std::hex << static_cast<int>(value) << ",";
            }

            remove_comma = true;
        }
        else if (log_mode == Config::LogMode::Verbose)
        {
            // Store more comprehensible decoded packets in CSV file.
            const std::vector<std::string> decoded = Decoding::MX5::decode_point_information_reply(byte_array);

            for (const auto& value : decoded)
            {
                log_stream << value << ",";
            }

            remove_comma = true;

        }
        else if (log_mode == Config::LogMode::Debug)
        {
            // Store raw hexadecimal byte values in CSV file.
            for (const auto& value : byte_array)
            {
                log_stream << std::hex << static_cast<int>(value);
            }
        }

        std::string csv_string = log_stream.str();

        if (remove_comma)
        {
            // Remove last comma from end.
            csv_string = csv_string.substr(0, csv_string.size() - 1);
        }

        return csv_string;
    }
}

#endif