/**
 * @file constants.h
 * @brief Contains constants used throughout the program, and are modifiable if there isn't enough control
 * via the configuration file.
 * @author G. Chamberlain-Webber
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants
{
    constexpr unsigned char SOH          = 0x01;   // Start of header
    constexpr unsigned char SEQ          = 0x01;   // Default sequence number
    constexpr unsigned char ACK          = 0x06;   // Acknowlegement code
    constexpr unsigned char SEQ_WRAP     = 0x0f;   // Number to wrap the SEQ
    constexpr int CHECKSUM_MOD           = 0x100;  // The number to modulus the checksum by

    // Packet parameter names
    constexpr std::string PNAME_SOH                         = "soh";
    constexpr std::string PNAME_SEQ                         = "seq";
    constexpr std::string PNAME_PACKET_LENGTH               = "hpacket_length";
    constexpr std::string PNAME_MX6_SPEAKSIGNATURE          = "hmx_speak_signature";
    constexpr std::string PNAME_NETWORK_NODE                = "hnetwork_node";
    constexpr std::string PNAME_CHANNEL                     = "hchannel";
    constexpr std::string PNAME_DESTINATION_CHANNEL_ADDRESS = "hdestination_channel_address";
    constexpr std::string PNAME_DESTINATION_TASK            = "hdestination_task";
    constexpr std::string PNAME_SOURCE_CHANNEL_ADDRESS      = "hsource_channel_address";
    constexpr std::string PNAME_SOURCE_TASK                 = "hsource_task";
    constexpr std::string PNAME_MARKER                      = "hmarker";
    constexpr std::string PNAME_PACKET_ID                   = "hpacket_id";
    constexpr std::string PNAME_RESERVED                    = "hreserved";
    constexpr std::string PNAME_REPLY_STATUS                = "preply_status";
    constexpr std::string PNAME_FLAGS                       = "pflags";
    constexpr std::string PNAME_NODE                        = "pnode";
    constexpr std::string PNAME_PCHANNEL                    = "pchannel";
    constexpr std::string PNAME_CHANNEL_ADDRESS             = "pchannel_address";
    constexpr std::string PNAME_POINT_CATEGORY              = "ppoint_category";
    constexpr std::string PNAME_POINT_NUMBER                = "ppoint_number";
    constexpr std::string PNAME_LOGICAL_POINT_NUMBER        = "plogical_point_number";
    constexpr std::string PNAME_LOGICAL_POINT_ZONE          = "plogical_point_zone";
    constexpr std::string PNAME_DEVICE_TYPE                 = "pdevice_type";
    constexpr std::string PNAME_AUXILIARY_POINT_ATTRIBUTES  = "pauxiliary_point_attributes";
    constexpr std::string PNAME_GROUP1                      = "pgroup1";
    constexpr std::string PNAME_GROUP2                      = "pgroup2";
    constexpr std::string PNAME_GROUP                       = "pgroup";
    constexpr std::string PNAME_AREA_TYPE                   = "parea_type";
    constexpr std::string PNAME_AREA_NUMBER                 = "parea_number";
    constexpr std::string PNAME_SECTOR_ID                   = "psector_id";
    constexpr std::string PNAME_LOOP_TYPE                   = "ploop_type";
    constexpr std::string PNAME_RAW_IDENTITY                = "praw_identity";
    constexpr std::string PNAME_ACTUAL_DEVICE_TYPE          = "pactual_device_type";
    constexpr std::string PNAME_MODE_AND_SENSITIVITY        = "pmode_and_sensitivity";
    constexpr std::string PNAME_RAW_ANALOGUE_VALUES1        = "praw_analogue_values1";
    constexpr std::string PNAME_RAW_ANALOGUE_VALUES2        = "praw_analogue_values2";
    constexpr std::string PNAME_RAW_ANALOGUE_VALUES3        = "praw_analogue_values3";
    constexpr std::string PNAME_LTA_FLAGS                   = "plta_flags";
    constexpr std::string PNAME_RAW_LTA                     = "praw_lta";
    constexpr std::string PNAME_DIRTINESS                   = "pdirtiness";
    constexpr std::string PNAME_UNITS_OF_MEASURE1           = "punits_of_measure1";
    constexpr std::string PNAME_UNITS_OF_MEASURE2           = "punits_of_measure2";
    constexpr std::string PNAME_UNITS_OF_MEASURE3           = "punits_of_measure3";
    constexpr std::string PNAME_CONVERTED_VALUES1           = "pconverted_value1";
    constexpr std::string PNAME_CONVERTED_VALUES2           = "pconverted_value2";
    constexpr std::string PNAME_CONVERTED_VALUES3           = "pconverted_value3";
    constexpr std::string PNAME_INSTANTANEOUS_ACTIVE_STATE  = "pinstantaneous_active_state";
    constexpr std::string PNAME_INSTANTANEOUS_FAULT_STATE   = "pinstantaneous_fault_state";
    constexpr std::string PNAME_CONFIRMED_ACTIVE_STATE      = "pconfirmed_active_state";
    constexpr std::string PNAME_CONFIRMED_FAULT_STATE       = "pconfirmed_fault_state";
    constexpr std::string PNAME_ACKNOWLEDGED_ACTIVE_STATE   = "packnowledged_active_state";
    constexpr std::string PNAME_ACKNOWLEDGED_FAULT_STATE    = "packnowledged_fault_state";
    constexpr std::string PNAME_OUTPUT_FORCED_MODE          = "poutput_forced_mode";
    constexpr std::string PNAME_OUTPUT_UNFORCED_STATE       = "poutput_unforced_state";
    constexpr std::string PNAME_OUTPUT_FORCED_STATE         = "poutput_forced_state";
    constexpr std::string PNAME_CLIENTID1                   = "pclient_id1";
    constexpr std::string PNAME_CLIENTID2                   = "pclient_id2";
    constexpr std::string PNAME_POSITION_IN_POINT_TOTAL1    = "pposition_in_points_total1";
    constexpr std::string PNAME_POSITION_IN_POINT_TOTAL2    = "pposition_in_points_total2";
}

#endif