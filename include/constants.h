/**
 * @file constants.h
 * @brief Contains constants used throughout the program, and are modifiable if there isn't enough control
 * via the configuration file.
 * @author G. Chamberlain-Webber
 */

namespace Constants
{
    constexpr unsigned char SOH          = 0x01;   // Start of header
    constexpr unsigned char SEQ          = 0x01;   // Default sequence number
    constexpr unsigned char ACK          = 0x06;   // Acknowlegement code
    constexpr unsigned char SEQ_WRAP     = 0x0f;   // Number to wrap the SEQ
    constexpr int CHECKSUM_MOD           = 0x100;  // The number to modulus the checksum by
}
