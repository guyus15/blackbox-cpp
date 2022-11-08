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
    // Panel information
    constexpr unsigned int POINT_PER_LOOP = 250;
    constexpr unsigned int MX5_MAX_LOOPS  = 8;
    constexpr unsigned int MX6_MAX_LOOPS  = 32;

    // Packets
    constexpr unsigned char SOH          = 0x01;   // Start of header
    constexpr unsigned char SEQ          = 0x01;   // Default sequence number
    constexpr unsigned char ACK          = 0x06;   // Acknowlegement code
    constexpr unsigned char SEQ_WRAP     = 0x0f;   // Number to wrap the SEQ
    constexpr int CHECKSUM_MOD           = 0x100;  // The number to modulus the checksum by

    // Packet parameter names
    const std::string PNAME_SOH                         = "soh";
    const std::string PNAME_SEQ                         = "seq";
    const std::string PNAME_PACKET_LENGTH               = "hpacket_length";
    const std::string PNAME_MX6_SPEAKSIGNATURE          = "hmx_speak_signature";
    const std::string PNAME_NETWORK_NODE                = "hnetwork_node";
    const std::string PNAME_CHANNEL                     = "hchannel";
    const std::string PNAME_DESTINATION_CHANNEL_ADDRESS = "hdestination_channel_address";
    const std::string PNAME_DESTINATION_TASK            = "hdestination_task";
    const std::string PNAME_SOURCE_CHANNEL_ADDRESS      = "hsource_channel_address";
    const std::string PNAME_SOURCE_TASK                 = "hsource_task";
    const std::string PNAME_MARKER                      = "hmarker";
    const std::string PNAME_PACKET_ID                   = "hpacket_id";
    const std::string PNAME_RESERVED                    = "hreserved";
    const std::string PNAME_REPLY_STATUS                = "preply_status";
    const std::string PNAME_FLAGS                       = "pflags";
    const std::string PNAME_NODE                        = "pnode";
    const std::string PNAME_PCHANNEL                    = "pchannel";
    const std::string PNAME_CHANNEL_ADDRESS             = "pchannel_address";
    const std::string PNAME_POINT_CATEGORY              = "ppoint_category";
    const std::string PNAME_POINT_NUMBER                = "ppoint_number";
    const std::string PNAME_LOGICAL_POINT_NUMBER        = "plogical_point_number";
    const std::string PNAME_LOGICAL_POINT_ZONE          = "plogical_point_zone";
    const std::string PNAME_DEVICE_TYPE                 = "pdevice_type";
    const std::string PNAME_AUXILIARY_POINT_ATTRIBUTES  = "pauxiliary_point_attributes";
    const std::string PNAME_GROUP1                      = "pgroup1";
    const std::string PNAME_GROUP2                      = "pgroup2";
    const std::string PNAME_GROUP                       = "pgroup";
    const std::string PNAME_AREA_TYPE                   = "parea_type";
    const std::string PNAME_AREA_NUMBER                 = "parea_number";
    const std::string PNAME_SECTOR_ID                   = "psector_id";
    const std::string PNAME_LOOP_TYPE                   = "ploop_type";
    const std::string PNAME_RAW_IDENTITY                = "praw_identity";
    const std::string PNAME_ACTUAL_DEVICE_TYPE          = "pactual_device_type";
    const std::string PNAME_MODE_AND_SENSITIVITY        = "pmode_and_sensitivity";
    const std::string PNAME_RAW_ANALOGUE_VALUES1        = "praw_analogue_values1";
    const std::string PNAME_RAW_ANALOGUE_VALUES2        = "praw_analogue_values2";
    const std::string PNAME_RAW_ANALOGUE_VALUES3        = "praw_analogue_values3";
    const std::string PNAME_LTA_FLAGS                   = "plta_flags";
    const std::string PNAME_RAW_LTA                     = "praw_lta";
    const std::string PNAME_DIRTINESS                   = "pdirtiness";
    const std::string PNAME_UNITS_OF_MEASURE1           = "punits_of_measure1";
    const std::string PNAME_UNITS_OF_MEASURE2           = "punits_of_measure2";
    const std::string PNAME_UNITS_OF_MEASURE3           = "punits_of_measure3";
    const std::string PNAME_CONVERTED_VALUES1           = "pconverted_value1";
    const std::string PNAME_CONVERTED_VALUES2           = "pconverted_value2";
    const std::string PNAME_CONVERTED_VALUES3           = "pconverted_value3";
    const std::string PNAME_INSTANTANEOUS_ACTIVE_STATE  = "pinstantaneous_active_state";
    const std::string PNAME_INSTANTANEOUS_FAULT_STATE   = "pinstantaneous_fault_state";
    const std::string PNAME_CONFIRMED_ACTIVE_STATE      = "pconfirmed_active_state";
    const std::string PNAME_CONFIRMED_FAULT_STATE       = "pconfirmed_fault_state";
    const std::string PNAME_ACKNOWLEDGED_ACTIVE_STATE   = "packnowledged_active_state";
    const std::string PNAME_ACKNOWLEDGED_FAULT_STATE    = "packnowledged_fault_state";
    const std::string PNAME_OUTPUT_FORCED_MODE          = "poutput_forced_mode";
    const std::string PNAME_OUTPUT_UNFORCED_STATE       = "poutput_unforced_state";
    const std::string PNAME_OUTPUT_FORCED_STATE         = "poutput_forced_state";
    const std::string PNAME_CLIENTID1                   = "pclient_id1";
    const std::string PNAME_CLIENTID2                   = "pclient_id2";
    const std::string PNAME_POSITION_IN_POINT_TOTAL1    = "pposition_in_points_total1";
    const std::string PNAME_POSITION_IN_POINT_TOTAL2    = "pposition_in_points_total2";

    // PointInformationReplyMX5 indexes
    constexpr int PIRMX5_SOH_INDEX                          = 0;
    constexpr int PIRMX5_SEQ_INDEX                          = 1;
    constexpr int PIRMX5_PACKET_LENGTH_INDEX                = 2;
    constexpr int PIRMX5_NETWORK_NODE_INDEX                 = 3;
    constexpr int PIRMX5_CHANNEL_INDEX                      = 4;
    constexpr int PIRMX5_DESTINATION_CHANNEL_ADDRESS_INDEX  = 5;
    constexpr int PIRMX5_DESTINATION_TASK_INDEX             = 6;
    constexpr int PIRMX5_SOURCE_CHANNEL_ADDRESS_INDEX       = 7;
    constexpr int PIRMX5_SOURCE_TASK_INDEX                  = 8;
    constexpr int PIRMX5_MARKER_INDEX                       = 9;
    constexpr int PIRMX5_PACKET_ID_INDEX                    = 10;
    constexpr int PIRMX5_REPLY_STATUS_INDEX                 = 11;
    constexpr int PIRMX5_FLAGS_INDEX                        = 12;
    constexpr int PIRMX5_NODE_INDEX                         = 13;
    constexpr int PIRMX5_POINT_ADDRESS_CHANNEL_INDEX        = 14;
    constexpr int PIRMX5_CHANNEL_ADDRESS_INDEX              = 15;
    constexpr int PIRMX5_POINT_CATEGORY_INDEX               = 16;
    constexpr int PIRMX5_POINT_NUMBER_INDEX                 = 17;
    constexpr int PIRMX5_LOGICAL_POINT_NUMBER_INDEX         = 18;
    constexpr int PIRMX5_LOGICAL_POINT_ZONE_INDEX           = 19;
    constexpr int PIRMX5_DEVICE_TYPE_INDEX                  = 20;
    constexpr int PIRMX5_AUXILIARY_POINT_ATTRIBUTES_INDEX   = 21;
    constexpr int PIRMX5_GROUP1_INDEX                       = 22;
    constexpr int PIRMX5_GROUP2_INDEX                       = 23;
    constexpr int PIRMX5_AREA_TYPE_INDEX                    = 24;
    constexpr int PIRMX5_AREA_NUMBER_INDEX                  = 25;
    constexpr int PIRMX5_SECTOR_ID_INDEX                    = 26;
    constexpr int PIRMX5_LOOP_TYPE_INDEX                    = 27;
    constexpr int PIRMX5_RAW_IDENTITY_INDEX                 = 28;
    constexpr int PIRMX5_ACTUAL_DEVICE_TYPE_INDEX           = 29;
    constexpr int PIRMX5_MODE_AND_SENSITIVITY_INDEX         = 30;
    constexpr int PIRMX5_RAW_ANALOGUE_VALUES1_INDEX         = 31;
    constexpr int PIRMX5_RAW_ANALOGUE_VALUES2_INDEX         = 32;
    constexpr int PIRMX5_RAW_ANALOGUE_VALUES3_INDEX         = 33;
    constexpr int PIRMX5_LTA_FLAGS_INDEX                    = 34;
    constexpr int PIRMX5_RAW_LTA_INDEX                      = 35;
    constexpr int PIRMX5_DIRTINESS_INDEX                    = 36;
    constexpr int PIRMX5_UNITS_OF_MEASURE1_INDEX            = 37;
    constexpr int PIRMX5_UNITS_OF_MEASURE2_INDEX            = 38;
    constexpr int PIRMX5_UNITS_OF_MEASURE3_INDEX            = 39;
    constexpr int PIRMX5_CONVERTED_VALUE1_INDEX             = 40;
    constexpr int PIRMX5_CONVERTED_VALUE2_INDEX             = 41;
    constexpr int PIRMX5_CONVERTED_VALUE3_INDEX             = 42;
    constexpr int PIRMX5_INSTANTANEOUS_ACTIVE_STATE_INDEX   = 43;
    constexpr int PIRMX5_INSTANTANEOUS_FAULT_STATE_INDEX    = 44;
    constexpr int PIRMX5_CONFIRMED_ACTIVE_STATE_INDEX       = 45;
    constexpr int PIRMX5_CONFIRMED_FAULT_STATE_INDEX        = 46;
    constexpr int PIRMX5_ACKNOWLEDGED_ACTIVE_STATE_INDEX    = 47;
    constexpr int PIRMX5_ACKNOWLEDGED_FAULT_STATE_INDEX     = 48;
    constexpr int PIRMX5_OUTPUT_FORCED_MODE_INDEX           = 49;
    constexpr int PIRMX5_OUTPUT_UNFORCED_STATE_INDEX        = 50;
    constexpr int PIRMX5_OUTPUT_FORCED_STATE_INDEX          = 51;
    constexpr int PIRMX5_CLIENT_ID1_INDEX                   = 52;
    constexpr int PIRMX5_CLIENT_ID2_INDEX                   = 53;
    constexpr int PIRMX5_POSITION_IN_POINTS_TOTAL1_INDEX    = 54;
    constexpr int PIRMX5_POSITION_IN_POINTS_TOTAL2_INDEX    = 55;

    // PointInformationReplyMX5 indexes
    constexpr int PIRMX6_SOH_INDEX                          = 0;
    constexpr int PIRMX6_SEQ_INDEX                          = 1;
    constexpr int PIRMX6_PACKET_LENGTH_INDEX                = 2;
    constexpr int PIRMX6_MX6_SPEAKSIGNATURE_INDEX           = 3;
    constexpr int PIRMX6_NETWORK_NODE_INDEX                 = 4;
    constexpr int PIRMX6_CHANNEL_INDEX                      = 5;
    constexpr int PIRMX6_DESTINATION_CHANNEL_ADDRESS_INDEX  = 6;
    constexpr int PIRMX6_DESTINATION_TASK_INDEX             = 7;
    constexpr int PIRMX6_SOURCE_CHANNEL_ADDRESS_INDEX       = 8;
    constexpr int PIRMX6_SOURCE_TASK_INDEX                  = 9;
    constexpr int PIRMX6_MARKER_INDEX                       = 10;
    constexpr int PIRMX6_PACKET_ID_INDEX                    = 11;
    constexpr int PIRMX6_REPLY_STATUS_INDEX                 = 12;
    constexpr int PIRMX6_FLAGS_INDEX                        = 13;
    constexpr int PIRMX6_NODE_INDEX                         = 14;
    constexpr int PIRMX6_POINT_ADDRESS_CHANNEL_INDEX        = 15;
    constexpr int PIRMX6_CHANNEL_ADDRESS_INDEX              = 16;
    constexpr int PIRMX6_POINT_CATEGORY_INDEX               = 17;
    constexpr int PIRMX6_POINT_NUMBER_INDEX                 = 18;
    constexpr int PIRMX6_LOGICAL_POINT_NUMBER_INDEX         = 19;
    constexpr int PIRMX6_LOGICAL_POINT_ZONE_INDEX           = 20;
    constexpr int PIRMX6_DEVICE_TYPE_INDEX                  = 21;
    constexpr int PIRMX6_AUXILIARY_POINT_ATTRIBUTES_INDEX   = 22;
    constexpr int PIRMX6_GROUP1_INDEX                       = 23;
    constexpr int PIRMX6_GROUP2_INDEX                       = 24;
    constexpr int PIRMX6_AREA_TYPE_INDEX                    = 25;
    constexpr int PIRMX6_AREA_NUMBER_INDEX                   = 26;
    constexpr int PIRMX6_SECTOR_ID_INDEX                    = 27;
    constexpr int PIRMX6_LOOP_TYPE_INDEX                    = 28;
    constexpr int PIRMX6_RAW_IDENTITY_INDEX                 = 29;
    constexpr int PIRMX6_ACTUAL_DEVICE_TYPE_INDEX           = 30;
    constexpr int PIRMX6_MODE_AND_SENSITIVITY_INDEX         = 31;
    constexpr int PIRMX6_RAW_ANALOGUE_VALUES1_INDEX         = 32;
    constexpr int PIRMX6_RAW_ANALOGUE_VALUES2_INDEX         = 33;
    constexpr int PIRMX6_RAW_ANALOGUE_VALUES3_INDEX         = 34;
    constexpr int PIRMX6_LTA_FLAGS_INDEX                    = 35;
    constexpr int PIRMX6_RAW_LTA_INDEX                      = 36;
    constexpr int PIRMX6_DIRTINESS_INDEX                    = 37;
    constexpr int PIRMX6_UNITS_OF_MEASURE1_INDEX            = 38;
    constexpr int PIRMX6_UNITS_OF_MEASURE2_INDEX            = 39;
    constexpr int PIRMX6_UNITS_OF_MEASURE3_INDEX            = 40;
    constexpr int PIRMX6_CONVERTED_VALUE1_INDEX             = 41;
    constexpr int PIRMX6_CONVERTED_VALUE2_INDEX             = 42;
    constexpr int PIRMX6_CONVERTED_VALUE3_INDEX             = 43;
    constexpr int PIRMX6_INSTANTANEOUS_ACTIVE_STATE_INDEX   = 44;
    constexpr int PIRMX6_INSTANTANEOUS_FAULT_STATE_INDEX    = 45;
    constexpr int PIRMX6_CONFIRMED_ACTIVE_STATE_INDEX       = 46;
    constexpr int PIRMX6_CONFIRMED_FAULT_STATE_INDEX        = 47;
    constexpr int PIRMX6_ACKNOWLEDGED_ACTIVE_STATE_INDEX    = 48;
    constexpr int PIRMX6_ACKNOWLEDGED_FAULT_STATE_INDEX     = 49;
    constexpr int PIRMX6_OUTPUT_FORCED_MODE_INDEX           = 50;
    constexpr int PIRMX6_OUTPUT_UNFORCED_STATE_INDEX        = 51;
    constexpr int PIRMX6_OUTPUT_FORCED_STATE_INDEX          = 52;
    constexpr int PIRMX6_CLIENT_ID1_INDEX                   = 53;
    constexpr int PIRMX6_CLIENT_ID2_INDEX                   = 54;
    constexpr int PIRMX6_POSITION_IN_POINTS_TOTAL1_INDEX    = 55;
    constexpr int PIRMX6_POSITION_IN_POINTS_TOTAL2_INDEX    = 56;

    namespace Profiling
    {
	    const std::string RESULTS_FILE = "profile-results.json";
    }
}

#endif