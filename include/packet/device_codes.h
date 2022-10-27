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
	inline std::unordered_map<unsigned char, std::string> device_codes
    {
        {0x00, "IF800Ex IS INT"},            // 0
        {0x02, "SAM800"},                    // 2
        {0x03, "SAB800"},                    // 3
        {0x04, "S271I+"},                    // 4
        {0x05, "MS802Ex IS"},                // 5
        {0x06, "LPBD800"},                   // 6
        {0x0d, "SIO800"},                    // 13
        {0x0e, "SIO800 INT"},                // 14
        {0x0f, "BDM800"},                    // 15
        {0x10, "801F"},                      // 16
        {0x11, "801Fex IS"},                 // 17
        {0x12, "MIO800"},                    // 18
        {0x13, "MIO800 INT"},                // 19
        {0x14, "811F"},                      // 20
        {0x15, "811FEx IS"},                 // 21
        {0x16, "801PC"},                     // 22
        {0x17, "811PC"},                     // 23
        {0x18, "OR3-S1"},                    // 24
        {0x19, "W3-S1"},                     // 25
        {0x1a, "HM3-D1"},                    // 26
        {0x1b, "ADK"},                       // 27
        {0x1c, "HM-STI"},                    // 28
        {0x1d, "OW3-S1"},                    // 29
        {0x1e, "IR3-S1"},                    // 30
        {0x1f, "HLA"},                       // 31
        {0x20, "EANUE"},                     // 32
        {0x21, "EAUE A"},                    // 33
        {0x22, "EAUE E"},                    // 34
        {0x23, "LAV I"},                     // 35
        {0x24, "LAV II"},                    // 36
        {0x25, "ALANZ"},                     // 37
        {0x26, "SenSTI"},                    // 38
        {0x27, "MelSTI"},                    // 39
        {0x28, "ADKSTI"},                    // 40
        {0x29, "UEASTI"},                    // 41
        {0x2a, "HL-STI"},                    // 42
        {0x2b, "SAB 801"},                   // 43
        {0x2c, "Reserved"},                  // 44
        {0x2d, "Reserved"},                  // 45
        {0x2e, "Reserved"},                  // 46
        {0x2f, "801 PS"},                    // 47
        {0x30, "816 H"},                     // 48
        {0x31, "816 P"},                     // 49
        {0x32, "816 PH"},                    // 50
        {0x33, "TSM 800"},                   // 51
        {0x34, "TSM 800 - INT"},             // 52
        {0x35, "LPSY 800 - R/W"},            // 53
        {0x36, "LPSY 865"},                  // 54
        {0x37, "LPAV 800 - R/W"},            // 55
        {0x38, "LPAV 865"},                  // 56
        {0x39, "DDM800 LOOP"},               // 57
        {0x3a, "DDM800 SPUR"},               // 58
        {0x3b, "DDM800 SPUR"},               // 59
        {0x3c, "LPSB3000"},                  // 60
        {0x3d, "LPAV3000"},                  // 61
        {0x3e, "VIO800"},                    // 62
        {0x4b, "460 PH"},                    // 75
        {0x4c, "460 P"},                     // 76
        {0x4d, "460 H"},                     // 77
        {0x4e, "850 PH"},                    // 78
        {0x4f, "851 PH"},                    // 79
        {0x50, "856 PH"},                    // 80
        {0x51, "850 P"},                     // 81
        {0x52, "856 P"},                     // 82
        {0x53, "850 H"},                     // 83
        {0x54, "850 PC"},                    // 84
        {0x55, "851 PCN"},                   // 85
        {0x56, "801CHC"},                    // 86
        {0x57, "QIO850 2IO"},                // 87
        {0x58, "QIO850 4IO"},                // 88
        {0x59, "QIO850 4IN4OUT"},            // 89
        {0x5a, "QMO850 2IO"},                // 90
        {0x5b, "QMO850 4IO"},                // 91
        {0x5c, "Supervised Digital Input"},  // 92
        {0x5d, "851 PHN"},                   // 93
        {0x5e, "460 PC"},                    // 94
        {0x5f, "840 PH"},                    // 95
        {0x60, "840 P"},                     // 96
        {0x61, "840 H"},                     // 97
        {0x62, "840 PC"},                    // 98
        {0x63, "QRM850 2OUT"},               // 99
        {0x64, "QRM850 4OUT"},               // 100
        {0x65, "830 PH"},                    // 101
        {0x66, "830 P"},                     // 102
        {0x67, "830 H"},                     // 103
        {0x68, "830 PC"},                    // 104
        {0x69, "830 PCC"},                   // 105
        {0x6a, "850 PCC"},                   // 106
        {0x6b, "FV411F"},                    // 107
        {0x6c, "FV412F"},                    // 108
        {0x6d, "FV413F"},                    // 109
        {0x6e, "FV421i"},                    // 110
        {0x6f, "SIO 800MC"},                 // 111
        {0x70, "SIO 800MC-INT"},             // 112
        {0x71, "MCP820"},                    // 113
        {0x72, "MCP820M"},                   // 114
        {0x73, "MCP830"},                    // 115
        {0x74, "MCP830M"},                   // 116
        {0x75, "LPBS 800 - R/W"},            // 117
        {0x76, "LPBS 865 L/P"},              // 118
        {0x77, "LPBS 3000"},                 // 119
        {0x79, "MCP 820 S"},                 // 120
        {0x7a, "MCP 830 S"},                 // 121
        {0x7f, "ALL"},                       // 127
        {0x80, "NONE"},                      // 128
        {0x81, "835 PH"},                    // 129
        {0x82, "835 P"},                     // 130
        {0x83, "835 H"},                     // 131
        {0x84, "835 PC"},                    // 132
        {0x85, "855 PH"},                    // 133
        {0x86, "855 P"},                     // 134
        {0x87, "855 H"},                     // 135
        {0x88, "855 PC"},                    // 136
        {0x8b, "855 PCC"},                   // 139
        {0x8c, "P80SB"},                     // 140
        {0x8d, "P80SW/R"},                   // 141
        {0x8e, "P85SR"},                     // 142
        {0x8f, "P80AIB"},                    // 143
        {0x90, "P80AIW"},                    // 144
        {0x91, "P80AIR"},                    // 145
        {0x92, "P80AVB"},                    // 146
        {0x93, "P81AVB"},                    // 147
        {0x94, "P80AVW"},                    // 148
        {0x95, "P85AVR"},                    // 149
        {0x9c, "835PCC"},                    // 156
        {0xc4, "801H"},                      // 196
        {0xc5, "801CH"},                     // 197
        {0xc6, "801PH"},                     // 198
        {0xc7, "801I"},                      // 199
        {0xc8, "811H"},                      // 200
        {0xc9, "811CH"},                     // 201
        {0xca, "811PH"},                     // 202
        {0xcb, "812H"},                      // 203
        {0xcc, "812PH"},                     // 204
        {0xcd, "812I"},                      // 205
        {0xce, "812IA"},                     // 206
        {0xd1, "GAR800"},                    // 209
        {0xd2, "GARA800"},                   // 210
        {0xd3, "LPS800"},                    // 211
        {0xd4, "MIM800"},                    // 212
        {0xd5, "MIM800-US"},                 // 213
        {0xd6, "APM800"},                    // 214
        {0xd7, "RIM800"},                    // 215
        {0xd8, "RMS800"},                    // 216
        {0xd9, "SNM800"},                    // 217
        {0xda, "S271f+"},                    // 218
        {0xdb, "LAV800"},                    // 219
        {0xdc, "CP820"},                     // 220
        {0xdd, "CP830"},                     // 221
        {0xde, "CP820M"},                    // 222
        {0xdf, "CP830M"},                    // 223
        {0xe0, "DIN820"},                    // 224
        {0xe1, "DIN830"},                    // 225
        {0xe2, "DIM800"},                    // 226
        {0xe3, "DIM800-US"},                 // 227
        {0xe4, "DIM800-INT"},                // 228
        {0xe5, "DIM800-US_INT"},             // 229
        {0xe6, "CIM800"},                    // 230
        {0xe7, "CIM800-US"},                 // 231
        {0xe8, "CIM800-INT"},                // 232
        {0xe9, "CIM800-US-INT"},             // 233
        {0xea, "Digital Input"},             // 234
        {0xeb, "Toggling Digital Input"},    // 235
        {0xec, "Digital Output"},            // 236
        {0xed, "Digital Visual Output"},     // 237
        {0xef, "Digital Supervised Output"}, // 239
        {0xf2, "812ID"},                     // 242
        {0xf3, "812PD"},                     // 243
        {0xf5, "Vesda VLC"},                 // 245
        {0xf8, "813P"},                      // 248
        {0xf9, "DIO800"},                    // 249
        {0xfa, "DIO800-INT"},                // 250
        {0xfb, "801PHEx IS"},                // 251
        {0xfc, "801CHEx IS"},                // 252
        {0xfd, "80HEx IS"},                  // 253
        {0xfe, "CP840Ex"},                   // 254
        {0xff, "IF800Ex IS"}                 // 255
    };
}

#endif