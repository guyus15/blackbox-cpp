/**
 * @file device_codes.h
 * @brief Contains a map of every device code to its respective device.
 * @author G. Chamberlain-Webber
 */


#ifndef DEVICE_CODES_H
#define DEVICE_CODES_H

#include <unordered_map>
#include <string>

namespace Packets
{
    std::unordered_map<unsigned char, std::string> device_codes;

    device_codes[0x00] = "IF800Ex IS INT"            // 0
    device_codes[0x02] = "SAM800"                    // 2
    device_codes[0x03] = "SAB800"                    // 3
    device_codes[0x04] = "S271I+"                    // 4
    device_codes[0x05] = "MS802Ex IS"                // 5
    device_codes[0x06] = "LPBD800"                   // 6
    device_codes[0x0d] = "SIO800"                    // 13
    device_codes[0x0e] = "SIO800 INT"                // 14
    device_codes[0x0f] = "BDM800"                    // 15
    device_codes[0x10] = "801F"                      // 16
    device_codes[0x11] = "801Fex IS"                 // 17
    device_codes[0x12] = "MIO800"                    // 18
    device_codes[0x13] = "MIO800 INT"                // 19
    device_codes[0x14] = "811F"                      // 20
    device_codes[0x15] = "811FEx IS"                 // 21
    device_codes[0x16] = "801PC"                     // 22
    device_codes[0x17] = "811PC"                     // 23
    device_codes[0x18] = "OR3-S1"                    // 24
    device_codes[0x19] = "W3-S1"                     // 25
    device_codes[0x1a] = "HM3-D1"                    // 26
    device_codes[0x1b] = "ADK"                       // 27
    device_codes[0x1c] = "HM-STI"                    // 28
    device_codes[0x1d] = "OW3-S1"                    // 29
    device_codes[0x1e] = "IR3-S1"                    // 30
    device_codes[0x1f] = "HLA"                       // 31
    device_codes[0x20] = "EANUE"                     // 32
    device_codes[0x21] = "EAUE A"                    // 33
    device_codes[0x22] = "EAUE E"                    // 34
    device_codes[0x23] = "LAV I"                     // 35
    device_codes[0x24] = "LAV II"                    // 36
    device_codes[0x25] = "ALANZ"                     // 37
    device_codes[0x26] = "SenSTI"                    // 38
    device_codes[0x27] = "MelSTI"                    // 39
    device_codes[0x28] = "ADKSTI"                    // 40
    device_codes[0x29] = "UEASTI"                    // 41
    device_codes[0x2a] = "HL-STI"                    // 42
    device_codes[0x2b] = "SAB 801"                   // 43
    device_codes[0x2c] = "Reserved"                  // 44
    device_codes[0x2d] = "Reserved"                  // 45
    device_codes[0x2e] = "Reserved"                  // 46
    device_codes[0x2f] = "801 PS"                    // 47
    device_codes[0x30] = "816 H"                     // 48
    device_codes[0x31] = "816 P"                     // 49
    device_codes[0x32] = "816 PH"                    // 50
    device_codes[0x33] = "TSM 800"                   // 51
    device_codes[0x34] = "TSM 800 - INT"             // 52
    device_codes[0x35] = "LPSY 800 - R/W"            // 53
    device_codes[0x36] = "LPSY 865"                  // 54
    device_codes[0x37] = "LPAV 800 - R/W"            // 55
    device_codes[0x38] = "LPAV 865"                  // 56
    device_codes[0x39] = "DDM800 LOOP"               // 57
    device_codes[0x3a] = "DDM800 SPUR"               // 58
    device_codes[0x3b] = "DDM800 SPUR"               // 59
    device_codes[0x3c] = "LPSB3000"                  // 60
    device_codes[0x3d] = "LPAV3000"                  // 61
    device_codes[0x3e] = "VIO800"                    // 62
    device_codes[0x4b] = "460 PH"                    // 75
    device_codes[0x4c] = "460 P"                     // 76
    device_codes[0x4d] = "460 H"                     // 77
    device_codes[0x4e] = "850 PH"                    // 78
    device_codes[0x4f] = "851 PH"                    // 79
    device_codes[0x50] = "856 PH"                    // 80
    device_codes[0x51] = "850 P"                     // 81
    device_codes[0x52] = "856 P"                     // 82
    device_codes[0x53] = "850 H"                     // 83
    device_codes[0x54] = "850 PC"                    // 84
    device_codes[0x55] = "851 PCN"                   // 85
    device_codes[0x56] = "801CHC"                    // 86
    device_codes[0x57] = "QIO850 2IO"                // 87
    device_codes[0x58] = "QIO850 4IO"                // 88
    device_codes[0x59] = "QIO850 4IN4OUT"            // 89
    device_codes[0x5a] = "QMO850 2IO"                // 90
    device_codes[0x5b] = "QMO850 4IO"                // 91
    device_codes[0x5c] = "Supervised Digital Input"  // 92
    device_codes[0x5d] = "851 PHN"                   // 93
    device_codes[0x5e] = "460 PC"                    // 94
    device_codes[0x5f] = "840 PH"                    // 95
    device_codes[0x60] = "840 P"                     // 96
    device_codes[0x61] = "840 H"                     // 97
    device_codes[0x62] = "840 PC"                    // 98
    device_codes[0x63] = "QRM850 2OUT"               // 99
    device_codes[0x64] = "QRM850 4OUT"               // 100
    device_codes[0x65] = "830 PH"                    // 101
    device_codes[0x66] = "830 P"                     // 102
    device_codes[0x67] = "830 H"                     // 103
    device_codes[0x68] = "830 PC"                    // 104
    device_codes[0x69] = "830 PCC"                   // 105
    device_codes[0x6a] = "850 PCC"                   // 106
    device_codes[0x6b] = "FV411F"                    // 107
    device_codes[0x6c] = "FV412F"                    // 108
    device_codes[0x6d] = "FV413F"                    // 109
    device_codes[0x6e] = "FV421i"                    // 110
    device_codes[0x6f] = "SIO 800MC"                 // 111
    device_codes[0x70] = "SIO 800MC-INT"             // 112
    device_codes[0x71] = "MCP820"                    // 113
    device_codes[0x72] = "MCP820M"                   // 114
    device_codes[0x73] = "MCP830"                    // 115
    device_codes[0x74] = "MCP830M"                   // 116
    device_codes[0x75] = "LPBS 800 - R/W"            // 117
    device_codes[0x76] = "LPBS 865 L/P"              // 118
    device_codes[0x77] = "LPBS 3000"                 // 119
    device_codes[0x79] = "MCP 820 S"                 // 120
    device_codes[0x7a] = "MCP 830 S"                 // 121
    device_codes[0x7f] = "ALL"                       // 127
    device_codes[0x80] = "NONE"                      // 128
    device_codes[0x81] = "835 PH"                    // 129
    device_codes[0x82] = "835 P"                     // 130
    device_codes[0x83] = "835 H"                     // 131
    device_codes[0x84] = "835 PC"                    // 132
    device_codes[0x85] = "855 PH"                    // 133
    device_codes[0x86] = "855 P"                     // 134
    device_codes[0x87] = "855 H"                     // 135
    device_codes[0x88] = "855 PC"                    // 136
    device_codes[0x8b] = "855 PCC"                   // 139
    device_codes[0x8c] = "P80SB"                     // 140
    device_codes[0x8d] = "P80SW/R"                   // 141
    device_codes[0x8e] = "P85SR"                     // 142
    device_codes[0x8f] = "P80AIB"                    // 143
    device_codes[0x90] = "P80AIW"                    // 144
    device_codes[0x91] = "P80AIR"                    // 145
    device_codes[0x92] = "P80AVB"                    // 146
    device_codes[0x93] = "P81AVB"                    // 147
    device_codes[0x94] = "P80AVW"                    // 148
    device_codes[0x95] = "P85AVR"                    // 149
    device_codes[0x9c] = "835PCC"                    // 156
    device_codes[0xc4] = "801H"                      // 196
    device_codes[0xc5] = "801CH"                     // 197
    device_codes[0xc6] = "801PH"                     // 198
    device_codes[0xc7] = "801I"                      // 199
    device_codes[0xc8] = "811H"                      // 200
    device_codes[0xc9] = "811CH"                     // 201
    device_codes[0xca] = "811PH"                     // 202
    device_codes[0xcb] = "812H"                      // 203
    device_codes[0xcc] = "812PH"                     // 204
    device_codes[0xcd] = "812I"                      // 205
    device_codes[0xce] = "812IA"                     // 206
    device_codes[0xd1] = "GAR800"                    // 209
    device_codes[0xd2] = "GARA800"                   // 210
    device_codes[0xd3] = "LPS800"                    // 211
    device_codes[0xd4] = "MIM800"                    // 212
    device_codes[0xd5] = "MIM800-US"                 // 213
    device_codes[0xd6] = "APM800"                    // 214
    device_codes[0xd7] = "RIM800"                    // 215
    device_codes[0xd8] = "RMS800"                    // 216
    device_codes[0xd9] = "SNM800"                    // 217
    device_codes[0xda] = "S271f+"                    // 218
    device_codes[0xdb] = "LAV800"                    // 219
    device_codes[0xdc] = "CP820"                     // 220
    device_codes[0xdd] = "CP830"                     // 221
    device_codes[0xde] = "CP820M"                    // 222
    device_codes[0xdf] = "CP830M"                    // 223
    device_codes[0xe0] = "DIN820"                    // 224
    device_codes[0xe1] = "DIN830"                    // 225
    device_codes[0xe2] = "DIM800"                    // 226
    device_codes[0xe3] = "DIM800-US"                 // 227
    device_codes[0xe4] = "DIM800-INT"                // 228
    device_codes[0xe5] = "DIM800-US_INT"             // 229
    device_codes[0xe6] = "CIM800"                    // 230
    device_codes[0xe7] = "CIM800-US"                 // 231
    device_codes[0xe8] = "CIM800-INT"                // 232
    device_codes[0xe9] = "CIM800-US-INT"             // 233
    device_codes[0xea] = "Digital Input"             // 234
    device_codes[0xeb] = "Toggling Digital Input"    // 235
    device_codes[0xec] = "Digital Output"            // 236
    device_codes[0xed] = "Digital Visual Output"     // 237
    device_codes[0xef] = "Digital Supervised Output" // 239
    device_codes[0xf2] = "812ID"                     // 242
    device_codes[0xf3] = "812PD"                     // 243
    device_codes[0xf5] = "Vesda VLC"                 // 245
    device_codes[0xf8] = "813P"                      // 248
    device_codes[0xf9] = "DIO800"                    // 249
    device_codes[0xfa] = "DIO800-INT"                // 250
    device_codes[0xfb] = "801PHEx IS"                // 251
    device_codes[0xfc] = "801CHEx IS"                // 252
    device_codes[0xfd] = "80HEx IS"                  // 253
    device_codes[0xfe] = "CP840Ex"                   // 254
    device_codes[0xff] = "IF800Ex IS"                // 255
}

#endif