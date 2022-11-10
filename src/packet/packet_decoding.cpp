/**
 * @file packet_decoding.cpp
 * @brief Provides functions to decode a series of bytes into a human-readable format.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet_decoding.h"
#include "packet/device_codes.h"
#include "constants.h"

#include "profiling/instrumentation.h"

#include <unordered_map>
#include <sstream>
#include <iostream>


namespace Packets::Decoding
{
    std::unordered_map<unsigned char, std::string> reply_status
    {
        {0, "Success"},
        {1, "Failure"}
    };

    std::unordered_map<unsigned char, std::string> flags
    {
        {0,  "Input Forced"},
        {1,  "Point Untested or Failed"},
        {2,  "Input Isolated"},
        {4,  "Output Isolated"},
        {8,  "Out of Compensation"},
        {16, "Point Type"},
        {32, "Loop Fault"},
        {64, "Output Under Test"}
    };

    std::unordered_map<unsigned char, std::string> channel
    {
        {0,  "MP CPU/Software Channel"},
        {1,  "RBus (Remote Bus)"},
        {2,  "COM1"},
        {3,  "COM2"},
        {4,  "COM3 (Network Port)"},
        {5,  "LNet (Local Ethernet)"},
        {6,  "Service Bus"},
        {7,  "All Channels"},
        {12, "MP Loop"},
        {13, "MP Non-Loop"},
        {14, "Comm Port Statuses"},
        {15, "Comm Nodes Statuses"}
    };

    std::unordered_map<unsigned char, std::string> channel_address
    {
        {255, "All"}
    };

    std::unordered_map<unsigned char, std::string> point_category
    {
        {0, "Real"},
        {1, "Pseudo"},
        {2, "XBus (Expansion Bus)"},
        {3, "Timer"},
        {4, "Menu"},
        {5, "Isolate"},
        {6, "User"},
        {254, "Not a Point"},
        {255, "All"}
    };

    std::unordered_map<unsigned char, std::string> point_number
    {
        {253, "No Physical Address Provided"},
        {255, "All"}
    };

    std::unordered_map<unsigned char, std::string> logical_point_zone
    {
        {254, "Zone N/A"}
    };

    std::unordered_map<unsigned char, std::string> auxiliary_point_attributes
    {
        {0,  "The point supports input"},
        {1,  "The point supports output"},
        {2,  "The point is a 'Solo' conventional detector interface"},
        {4,  "Base of split device"},
        {8,  "Part of split device"},
        {16, "Unused"},
        {32, "The point raising this event is classified as a sounder"},
        {64, "Is isolation of point allowed"}
    };

    std::unordered_map<unsigned char, std::string> sector_id
    {
        {254, "Not in Sector"}
    };

    std::unordered_map<unsigned char, std::string> loop_type 
    {
        {0, "Thorn"},
        {1, "MX Digital"},
        {2, "Not Loop"},
        {3, "Zetfas"},
        {4, "STI"}
    };

    std::unordered_map<unsigned char, std::string >lta_flags 
    {
        {0, "LTA Available"},
        {1, "Dirtiness Available"}
    };

    std::unordered_map<unsigned char, std::string> unit_of_measurement 
    {
        {0,  "Invalid"},
        {1,  "Degrees C"},
        {2,  "Degrees F"},
        {3,  "ppm (parts per million)"},
        {4,  "%/ft obscuration"},
        {5,  "%/m obscuration"},
        {6,  "Y value"},
        {7,  "Amps"},
        {8,  "Volts"},
        {9,  "Not Installed"},
        {10, "mA"}
    };

    std::unordered_map<unsigned char, std::string> instantaneous_active_state
    {
        {0, "Clear"},
        {1, "Pre-Alarm"},
        {2, "Alarm Verifying"},
        {3, "Active"},
        {4, "Resetting"},
        {5, "Test"}
    };

    std::unordered_map<unsigned char, std::string> confirmed_active_state 
    {
       { 6, "Activate Warning"}
    };

    std::unordered_map<unsigned char, std::string> output_forced_mode 
    {
        {0, "Currently Unforced"},
        {1, "Currently Forced"}
    };

    std::unordered_map<unsigned char, std::string> output_unforced_state 
    {
        {0, "Off"},
        {1, "On"},
        {2, "Pulse 1 (pulsing mode 1)"},
        {3, "Pulse 2 (pulsing mode 2)"},
        {4, "Point With No Output"}
    };

    std::unordered_map<unsigned char, std::string> output_forced_state 
    {
        {0, "Off"},
        {1, "On"},
        {2, "Pulse 1 (pulsing mode 1)"},
        {3, "Pulse 2 (pulsing mode 2)"},
        {4, "Point With No Output"}
    };

    namespace MX5
    {
        std::vector<std::string> decode_point_information_reply(const std::vector<unsigned char>& data)
        {
        	BX_PROFILE_FUNCTION();

            for (const auto& byte : data)
            {
                std::cout << static_cast<int>(byte) << ",";
            }

            std::cout << "\n";

            std::vector<std::string> new_data;

            // Reply status
            new_data.push_back(reply_status[data[Constants::PIRMX5_REPLY_STATUS_INDEX]]);

            // Flags
            new_data.push_back(flags[data[Constants::PIRMX5_FLAGS_INDEX]]);

            // Node
            std::stringstream node_stream;
            node_stream << static_cast<int>(data[Constants::PIRMX5_NODE_INDEX]);
            new_data.push_back(node_stream.str());

            // Channel
            new_data.push_back(channel[data[Constants::PIRMX5_POINT_ADDRESS_CHANNEL_INDEX]]);

            // Channel address
            auto search_channel_address = channel_address.find(data[Constants::PIRMX5_CHANNEL_ADDRESS_INDEX]);

            if (search_channel_address != channel_address.end())
            {
                new_data.push_back(channel_address[data[Constants::PIRMX5_CHANNEL_ADDRESS_INDEX]]);
            }
            else
            {
                std::stringstream channel_address_stream;
                channel_address_stream << static_cast<int>(data[Constants::PIRMX5_CHANNEL_ADDRESS_INDEX]);
                new_data.push_back(channel_address_stream.str());
            }

            // Point category
            new_data.push_back(point_category[data[Constants::PIRMX5_POINT_CATEGORY_INDEX]]); 

            // Point number (physical)
            auto search_point_number = point_number.find(data[Constants::PIRMX5_POINT_NUMBER_INDEX]);

            if (search_point_number != point_number.end())
            {
                new_data.push_back(point_number[data[Constants::PIRMX5_POINT_NUMBER_INDEX]]);
            }
            else
            {
                std::stringstream point_number_stream;
                point_number_stream << static_cast<int>(data[Constants::PIRMX5_POINT_NUMBER_INDEX]);
                new_data.push_back(point_number_stream.str());
            }
            
            // Logical point number
            std::stringstream logical_point_number_stream;
            logical_point_number_stream << static_cast<int>(data[Constants::PIRMX5_LOGICAL_POINT_NUMBER_INDEX]);
            new_data.push_back(logical_point_number_stream.str());

            // Logical point zone
            auto search_logical_point_zone = logical_point_zone.find(data[Constants::PIRMX5_LOGICAL_POINT_ZONE_INDEX]);

            if (search_logical_point_zone != logical_point_zone.end())
            {
                new_data.push_back(logical_point_zone[data[Constants::PIRMX5_LOGICAL_POINT_ZONE_INDEX]]);
            }
            else
            {
                std::stringstream logical_point_zone_stream;
                logical_point_zone_stream << static_cast<int>(data[Constants::PIRMX5_LOGICAL_POINT_ZONE_INDEX]);
                new_data.push_back(logical_point_zone_stream.str());
            }

            // Device type
            new_data.push_back(Packets::device_codes[data[Constants::PIRMX5_DEVICE_TYPE_INDEX]]);
            
            // Auxiliary point attributes
            std::stringstream auxiliary_point_attributes_stream;
            auxiliary_point_attributes_stream << static_cast<int>(data[Constants::PIRMX5_AUXILIARY_POINT_ATTRIBUTES_INDEX]);
            new_data.push_back(auxiliary_point_attributes_stream.str());

            // Group
            unsigned char group1 = data[Constants::PIRMX5_GROUP1_INDEX];
            unsigned char group2 = data[Constants::PIRMX5_GROUP2_INDEX];
            int group = (group1 << 8) + group2;

            std::stringstream group_stream;
            group_stream << group;
            new_data.push_back(group_stream.str());

            // Area type
            std::stringstream area_type_stream;
            area_type_stream << static_cast<int>(data[Constants::PIRMX5_AREA_NUMBER_INDEX]);
            new_data.push_back(area_type_stream.str());

            // Area number
            std::stringstream area_number_stream;
            area_number_stream << static_cast<int>(data[Constants::PIRMX5_AREA_NUMBER_INDEX]);
            new_data.push_back(area_number_stream.str());

            // Sector ID
            auto search_sector_id = sector_id.find(data[Constants::PIRMX5_SECTOR_ID_INDEX]);

            if (search_sector_id != sector_id.end())
            {
                new_data.push_back(sector_id[data[Constants::PIRMX5_SECTOR_ID_INDEX]]);
            }
            else
            {
                std::stringstream sector_id_stream;
                sector_id_stream << static_cast<int>(data[Constants::PIRMX5_SECTOR_ID_INDEX]);
                new_data.push_back(sector_id_stream.str());
            }
            
            // Loop type
            new_data.push_back(loop_type[data[Constants::PIRMX5_LOOP_TYPE_INDEX]]);

            // Raw identity
            std::stringstream raw_identity_stream;
            raw_identity_stream << static_cast<int>(data[Constants::PIRMX5_RAW_IDENTITY_INDEX]);
            new_data.push_back(raw_identity_stream.str());

            // Actual device type
            std::stringstream actual_device_type_stream;
            actual_device_type_stream << static_cast<int>(data[Constants::PIRMX5_ACTUAL_DEVICE_TYPE_INDEX]);
            new_data.push_back(actual_device_type_stream.str());

            // Mode & sensitivity
            std::stringstream mode_sensitivity_stream;
            mode_sensitivity_stream << static_cast<int>(data[Constants::PIRMX5_ACTUAL_DEVICE_TYPE_INDEX]);
            new_data.push_back(mode_sensitivity_stream.str());

            // Raw analogue values
            std::stringstream raw_analogue_stream1;
            raw_analogue_stream1 << static_cast<int>(data[Constants::PIRMX5_RAW_ANALOGUE_VALUES1_INDEX]);
            std::stringstream raw_analogue_stream2;
            raw_analogue_stream2 << static_cast<int>(data[Constants::PIRMX5_RAW_ANALOGUE_VALUES2_INDEX]);
            std::stringstream raw_analogue_stream3;
            raw_analogue_stream3 << static_cast<int>(data[Constants::PIRMX5_RAW_ANALOGUE_VALUES3_INDEX]);

            new_data.push_back(raw_analogue_stream1.str());
            new_data.push_back(raw_analogue_stream2.str());
            new_data.push_back(raw_analogue_stream3.str());

            // LTA flags
            auto search_lta_flags = lta_flags.find(data[Constants::PIRMX5_LTA_FLAGS_INDEX]);

            if (search_lta_flags != lta_flags.end())
            {
                new_data.push_back(lta_flags[data[Constants::PIRMX5_LTA_FLAGS_INDEX]]);
            }
            else
            {
                std::stringstream lta_flags_stream;
                lta_flags_stream << static_cast<int>(data[Constants::PIRMX5_LTA_FLAGS_INDEX]);
                new_data.push_back(lta_flags_stream.str());
            }

            // Raw LTA
            std::stringstream raw_lta_stream;
            raw_lta_stream << static_cast<int>(data[Constants::PIRMX5_RAW_LTA_INDEX]);
            new_data.push_back(raw_lta_stream.str());

            // Dirtiness
            std::stringstream dirtiness_stream;
            dirtiness_stream << static_cast<int>(data[Constants::PIRMX5_DIRTINESS_INDEX]);
            new_data.push_back(dirtiness_stream.str());

            // Units of measurement
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX5_UNITS_OF_MEASURE1_INDEX]]);
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX5_UNITS_OF_MEASURE2_INDEX]]);
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX5_UNITS_OF_MEASURE3_INDEX]]);

            // Converted values
            std::stringstream converted_values_stream1;
            converted_values_stream1 << static_cast<int>(data[Constants::PIRMX5_CONVERTED_VALUE1_INDEX]);
            std::stringstream converted_values_stream2;
            converted_values_stream2 << static_cast<int>(data[Constants::PIRMX5_CONVERTED_VALUE2_INDEX]);
            std::stringstream converted_values_stream3;
            converted_values_stream3 << static_cast<int>(data[Constants::PIRMX5_CONVERTED_VALUE3_INDEX]);

            new_data.push_back(converted_values_stream1.str());
            new_data.push_back(converted_values_stream2.str());
            new_data.push_back(converted_values_stream3.str());

            // Instantaneous states
            new_data.push_back(instantaneous_active_state[data[Constants::PIRMX5_INSTANTANEOUS_ACTIVE_STATE_INDEX]]);

            std::stringstream instantaneous_fault_state_stream;
            instantaneous_fault_state_stream << static_cast<int>(data[Constants::PIRMX5_INSTANTANEOUS_FAULT_STATE_INDEX]);
            new_data.push_back(instantaneous_fault_state_stream.str());

            // Confirmed states
            auto search_confirmed_active_state = confirmed_active_state.find(data[Constants::PIRMX5_CONFIRMED_ACTIVE_STATE_INDEX]);

            if (search_confirmed_active_state != confirmed_active_state.end())
            {
                new_data.push_back(confirmed_active_state[data[Constants::PIRMX5_CONFIRMED_ACTIVE_STATE_INDEX]]);
            }
            else
            {
                std::stringstream confirmed_states_stream;
                confirmed_states_stream << static_cast<int>(data[Constants::PIRMX5_CONFIRMED_ACTIVE_STATE_INDEX]);
                new_data.push_back(confirmed_states_stream.str());
            }

            std::stringstream confirmed_fault_state_stream;
            confirmed_fault_state_stream << static_cast<int>(data[Constants::PIRMX5_CONFIRMED_FAULT_STATE_INDEX]);
            new_data.push_back(confirmed_fault_state_stream.str());

            // Acknowledged states
            std::stringstream acknowledged_active_state_stream;
            acknowledged_active_state_stream << static_cast<int>(data[Constants::PIRMX5_ACKNOWLEDGED_ACTIVE_STATE_INDEX]);
            new_data.push_back(acknowledged_active_state_stream.str());

            std::stringstream acknowledged_fault_state_stream;
            acknowledged_fault_state_stream << static_cast<int>(data[Constants::PIRMX5_ACKNOWLEDGED_FAULT_STATE_INDEX]);
            new_data.push_back(acknowledged_fault_state_stream.str());

            // Output forced mode
            new_data.push_back(output_forced_mode[data[Constants::PIRMX5_OUTPUT_FORCED_MODE_INDEX]]);

            // Output states
            new_data.push_back(output_unforced_state[data[Constants::PIRMX5_OUTPUT_UNFORCED_STATE_INDEX]]);
            new_data.push_back(output_forced_state[data[Constants::PIRMX5_OUTPUT_FORCED_STATE_INDEX]]);

            return new_data;
        }
    }

    namespace MX6
    {
	    std::vector<std::string> decode_point_information_reply(const std::vector<unsigned char>& data)
        {
        	BX_PROFILE_FUNCTION();

            for (const auto& byte : data)
            {
                std::cout << static_cast<int>(byte) << ",";
            }

            std::cout << "\n";

            std::vector<std::string> new_data;

            // Reply status
            new_data.push_back(reply_status[data[Constants::PIRMX6_REPLY_STATUS_INDEX]]);

            // Flags
            new_data.push_back(flags[data[Constants::PIRMX6_FLAGS_INDEX]]);

            // Node
            std::stringstream node_stream;
            node_stream << static_cast<int>(data[Constants::PIRMX6_NODE_INDEX]);
            new_data.push_back(node_stream.str());

            // Channel
            new_data.push_back(channel[data[Constants::PIRMX6_POINT_ADDRESS_CHANNEL_INDEX]]);

            // Channel address
            auto search_channel_address = channel_address.find(data[Constants::PIRMX6_CHANNEL_ADDRESS_INDEX]);

            if (search_channel_address != channel_address.end())
            {
                new_data.push_back(channel_address[data[Constants::PIRMX6_CHANNEL_ADDRESS_INDEX]]);
            }
            else
            {
                std::stringstream channel_address_stream;
                channel_address_stream << static_cast<int>(data[Constants::PIRMX6_CHANNEL_ADDRESS_INDEX]);
                new_data.push_back(channel_address_stream.str());
            }

            // Point category
            new_data.push_back(point_category[data[Constants::PIRMX6_POINT_CATEGORY_INDEX]]); 

            // Point number (physical)
            auto search_point_number = point_number.find(data[Constants::PIRMX6_POINT_NUMBER_INDEX]);

            if (search_point_number != point_number.end())
            {
                new_data.push_back(point_number[data[Constants::PIRMX6_POINT_NUMBER_INDEX]]);
            }
            else
            {
                std::stringstream point_number_stream;
                point_number_stream << static_cast<int>(data[Constants::PIRMX6_POINT_NUMBER_INDEX]);
                new_data.push_back(point_number_stream.str());
            }
            
            // Logical point number
            std::stringstream logical_point_number_stream;
            logical_point_number_stream << static_cast<int>(data[Constants::PIRMX6_LOGICAL_POINT_NUMBER_INDEX]);
            new_data.push_back(logical_point_number_stream.str());

            // Logical point zone
            auto search_logical_point_zone = logical_point_zone.find(data[Constants::PIRMX6_LOGICAL_POINT_ZONE_INDEX]);

            if (search_logical_point_zone != logical_point_zone.end())
            {
                new_data.push_back(logical_point_zone[data[Constants::PIRMX6_LOGICAL_POINT_ZONE_INDEX]]);
            }
            else
            {
                std::stringstream logical_point_zone_stream;
                logical_point_zone_stream << static_cast<int>(data[Constants::PIRMX6_LOGICAL_POINT_ZONE_INDEX]);
                new_data.push_back(logical_point_zone_stream.str());
            }

            // Device type
            new_data.push_back(Packets::device_codes[data[Constants::PIRMX6_DEVICE_TYPE_INDEX]]);
            
            // Auxiliary point attributes
            std::stringstream auxiliary_point_attributes_stream;
            auxiliary_point_attributes_stream << static_cast<int>(data[Constants::PIRMX6_AUXILIARY_POINT_ATTRIBUTES_INDEX]);
            new_data.push_back(auxiliary_point_attributes_stream.str());

            // Group
            unsigned char group1 = data[Constants::PIRMX6_GROUP1_INDEX];
            unsigned char group2 = data[Constants::PIRMX6_GROUP2_INDEX];
            int group = (group1 << 8) + group2;

            std::stringstream group_stream;
            group_stream << group;
            new_data.push_back(group_stream.str());

            // Area type
            std::stringstream area_type_stream;
            area_type_stream << static_cast<int>(data[Constants::PIRMX6_AREA_NUMBER_INDEX]);
            new_data.push_back(area_type_stream.str());

            // Area number
            std::stringstream area_number_stream;
            area_number_stream << static_cast<int>(data[Constants::PIRMX6_AREA_NUMBER_INDEX]);
            new_data.push_back(area_number_stream.str());

            // Sector ID
            auto search_sector_id = sector_id.find(data[Constants::PIRMX6_SECTOR_ID_INDEX]);

            if (search_sector_id != sector_id.end())
            {
                new_data.push_back(sector_id[data[Constants::PIRMX6_SECTOR_ID_INDEX]]);
            }
            else
            {
                std::stringstream sector_id_stream;
                sector_id_stream << static_cast<int>(data[Constants::PIRMX6_SECTOR_ID_INDEX]);
                new_data.push_back(sector_id_stream.str());
            }
            
            // Loop type
            new_data.push_back(loop_type[data[Constants::PIRMX6_LOOP_TYPE_INDEX]]);

            // Raw identity
            std::stringstream raw_identity_stream;
            raw_identity_stream << static_cast<int>(data[Constants::PIRMX6_RAW_IDENTITY_INDEX]);
            new_data.push_back(raw_identity_stream.str());

            // Actual device type
            std::stringstream actual_device_type_stream;
            actual_device_type_stream << static_cast<int>(data[Constants::PIRMX6_ACTUAL_DEVICE_TYPE_INDEX]);
            new_data.push_back(actual_device_type_stream.str());

            // Mode & sensitivity
            std::stringstream mode_sensitivity_stream;
            mode_sensitivity_stream << static_cast<int>(data[Constants::PIRMX6_ACTUAL_DEVICE_TYPE_INDEX]);
            new_data.push_back(mode_sensitivity_stream.str());

            // Raw analogue values
            std::stringstream raw_analogue_stream1;
            raw_analogue_stream1 << static_cast<int>(data[Constants::PIRMX6_RAW_ANALOGUE_VALUES1_INDEX]);
            std::stringstream raw_analogue_stream2;
            raw_analogue_stream2 << static_cast<int>(data[Constants::PIRMX6_RAW_ANALOGUE_VALUES2_INDEX]);
            std::stringstream raw_analogue_stream3;
            raw_analogue_stream3 << static_cast<int>(data[Constants::PIRMX6_RAW_ANALOGUE_VALUES3_INDEX]);

            new_data.push_back(raw_analogue_stream1.str());
            new_data.push_back(raw_analogue_stream2.str());
            new_data.push_back(raw_analogue_stream3.str());

            // LTA flags
            auto search_lta_flags = lta_flags.find(data[Constants::PIRMX6_LTA_FLAGS_INDEX]);

            if (search_lta_flags != lta_flags.end())
            {
                new_data.push_back(lta_flags[data[Constants::PIRMX6_LTA_FLAGS_INDEX]]);
            }
            else
            {
                std::stringstream lta_flags_stream;
                lta_flags_stream << static_cast<int>(data[Constants::PIRMX6_LTA_FLAGS_INDEX]);
                new_data.push_back(lta_flags_stream.str());
            }

            // Raw LTA
            std::stringstream raw_lta_stream;
            raw_lta_stream << static_cast<int>(data[Constants::PIRMX6_RAW_LTA_INDEX]);
            new_data.push_back(raw_lta_stream.str());

            // Dirtiness
            std::stringstream dirtiness_stream;
            dirtiness_stream << static_cast<int>(data[Constants::PIRMX6_DIRTINESS_INDEX]);
            new_data.push_back(dirtiness_stream.str());

            // Units of measurement
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX6_UNITS_OF_MEASURE1_INDEX]]);
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX6_UNITS_OF_MEASURE2_INDEX]]);
            new_data.push_back(unit_of_measurement[data[Constants::PIRMX6_UNITS_OF_MEASURE3_INDEX]]);

            // Converted values
            std::stringstream converted_values_stream1;
            converted_values_stream1 << static_cast<int>(data[Constants::PIRMX6_CONVERTED_VALUE1_INDEX]);
            std::stringstream converted_values_stream2;
            converted_values_stream2 << static_cast<int>(data[Constants::PIRMX6_CONVERTED_VALUE2_INDEX]);
            std::stringstream converted_values_stream3;
            converted_values_stream3 << static_cast<int>(data[Constants::PIRMX6_CONVERTED_VALUE3_INDEX]);

            new_data.push_back(converted_values_stream1.str());
            new_data.push_back(converted_values_stream2.str());
            new_data.push_back(converted_values_stream3.str());

            // Instantaneous states
            new_data.push_back(instantaneous_active_state[data[Constants::PIRMX6_INSTANTANEOUS_ACTIVE_STATE_INDEX]]);

            std::stringstream instantaneous_fault_state_stream;
            instantaneous_fault_state_stream << static_cast<int>(data[Constants::PIRMX6_INSTANTANEOUS_FAULT_STATE_INDEX]);
            new_data.push_back(instantaneous_fault_state_stream.str());

            // Confirmed states
            auto search_confirmed_active_state = confirmed_active_state.find(data[Constants::PIRMX6_CONFIRMED_ACTIVE_STATE_INDEX]);

            if (search_confirmed_active_state != confirmed_active_state.end())
            {
                new_data.push_back(confirmed_active_state[data[Constants::PIRMX6_CONFIRMED_ACTIVE_STATE_INDEX]]);
            }
            else
            {
                std::stringstream confirmed_states_stream;
                confirmed_states_stream << static_cast<int>(data[Constants::PIRMX6_CONFIRMED_ACTIVE_STATE_INDEX]);
                new_data.push_back(confirmed_states_stream.str());
            }

            std::stringstream confirmed_fault_state_stream;
            confirmed_fault_state_stream << static_cast<int>(data[Constants::PIRMX6_CONFIRMED_FAULT_STATE_INDEX]);
            new_data.push_back(confirmed_fault_state_stream.str());

            // Acknowledged states
            std::stringstream acknowledged_active_state_stream;
            acknowledged_active_state_stream << static_cast<int>(data[Constants::PIRMX6_ACKNOWLEDGED_ACTIVE_STATE_INDEX]);
            new_data.push_back(acknowledged_active_state_stream.str());

            std::stringstream acknowledged_fault_state_stream;
            acknowledged_fault_state_stream << static_cast<int>(data[Constants::PIRMX6_ACKNOWLEDGED_FAULT_STATE_INDEX]);
            new_data.push_back(acknowledged_fault_state_stream.str());

            // Output forced mode
            new_data.push_back(output_forced_mode[data[Constants::PIRMX6_OUTPUT_FORCED_MODE_INDEX]]);

            // Output states
            new_data.push_back(output_unforced_state[data[Constants::PIRMX6_OUTPUT_UNFORCED_STATE_INDEX]]);
            new_data.push_back(output_forced_state[data[Constants::PIRMX6_OUTPUT_FORCED_STATE_INDEX]]);

            return new_data;
        }
    }
}
