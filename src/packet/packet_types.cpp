/**
 * @file packet_types.cpp
 * @brief Contains concrete implementations of frequently used packets.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet_types.h"

#include "packet/headers.h"
#include "packet/packet_ids.h"
#include "packet/packet_decoding.h"

#include "constants.h"

#include <iostream>
#include <sstream>

namespace Packets::Types
{
    /*
     * PointInformationRequestMX5
     */

    PointInformationRequestMX5::PointInformationRequestMX5(int point_number)
    : _point_number{point_number}
    {
        LocalHeaderMX5 header{PacketID::POINT_INFO_REQUEST};
    
        std::vector<std::pair<std::string, unsigned char>> parameters
        {
            {"pnode",                     0x00},  // D+0
            {"pchannel",                  0x00},  // D+1
            {"pchannel_address",          0x01},  // D+2
            {"ppoint_category",           0x00},  // D+3
            {"ppoint_number",    _point_number},  // D+4
            {"plogical_point_number",     0xfd},  // D+5
            {"plogical_point_zone",       0xfe},  // D+6
            {"pdevice_category",          0x00},  // D+7
            {"pgroup0",                   0x00},  // D+8
            {"pgroup1",                   0x01},  // D+9
            {"poutput_point_state_store", 0x03},  // D+10
            {"preserved0",                0x00},  // D+11
            {"preserved1",                0x00},  // D+12
            {"pmulti_area_type",          0x03},  // D+13
            {"pareas0",                   0x00},  // D+14
            {"pareas1",                   0x00},  // D+15
            {"pareas2",                   0x00},  // D+16
            {"pareas3",                   0x00},  // D+17
            {"pareas4",                   0x00},  // D+18
            {"pareas5",                   0x00},  // D+19
            {"pareas6",                   0x00},  // D+20
            {"pareas7",                   0x00},  // D+21
            {"pareas8",                   0x00},  // D+22
            {"pareas9",                   0x00},  // D+23
            {"pareas10",                  0x00},  // D+24
            {"pareas11",                  0x00},  // D+25
            {"pareas12",                  0x00},  // D+26
            {"pareas13",                  0x00},  // D+27
            {"pareas14",                  0x00},  // D+28
            {"pareas15",                  0x00},  // D+29
            {"pareas16",                  0x00},  // D+30
            {"pareas17",                  0x00},  // D+31
            {"pareas18",                  0x00},  // D+32
            {"pareas19",                  0x00},  // D+33
            {"pareas20",                  0x00},  // D+34
            {"pareas21",                  0x00},  // D+35
            {"pareas22",                  0x00},  // D+36
            {"pareas23",                  0x00},  // D+37
            {"pareas24",                  0x00},  // D+38
            {"pareas25",                  0x00},  // D+39
            {"pareas26",                  0x00},  // D+40
            {"pareas27",                  0x00},  // D+41
            {"pareas28",                  0x00},  // D+42
            {"pareas29",                  0x00},  // D+43
            {"pareas30",                  0x00},  // D+44
            {"pdevice_type",              0x7f},  // D+45
            {"prequest_type",             0x00},  // D+46
            {"psearch_type",              0x0a}   // D+47
        };

        _packet = new Packet{header, parameters};
    }

    PointInformationRequestMX5::~PointInformationRequestMX5()
    {
        delete _packet;
    }

    void PointInformationRequestMX5::write()
    {
        _packet->write();
    }

    PointInformationReplyMX5 *PointInformationRequestMX5::read()
    {
        std::vector<unsigned char> read_data = _packet->read();

        PointInformationReplyMX5 *reply_packet = new PointInformationReplyMX5{read_data};

        return reply_packet;
    }


    /*
     * PointInformationRequestMX6
     */

    PointInformationRequestMX6::PointInformationRequestMX6(int point_number)
    : _point_number{point_number}
    {
        LocalHeaderMX6 header{PacketID::POINT_INFO_REQUEST};

        std::vector<std::pair<std::string, unsigned char>> parameters
        {
            {"pnode",                     0x00},  // D+0
            {"pchannel",                  0x00},  // D+1
            {"pchannel_address",          0x01},  // D+2
            {"ppoint_category",           0x00},  // D+3
            {"ppoint_number",    _point_number},  // D+4
            {"plogical_point_number",     0xfd},  // D+5
            {"plogical_point_zone",       0xfe},  // D+6
            {"pdevice_category",          0x00},  // D+7
            {"pgroup0",                   0x00},  // D+8
            {"pgroup1",                   0x01},  // D+9
            {"poutput_point_state_store", 0x03},  // D+10
            {"preserved0",                0x00},  // D+11
            {"preserved1",                0x00},  // D+12
            {"pmulti_area_type",          0x03},  // D+13
            {"pareas0",                   0x00},  // D+14
            {"pareas1",                   0x00},  // D+15
            {"pareas2",                   0x00},  // D+16
            {"pareas3",                   0x00},  // D+17
            {"pareas4",                   0x00},  // D+18
            {"pareas5",                   0x00},  // D+19
            {"pareas6",                   0x00},  // D+20
            {"pareas7",                   0x00},  // D+21
            {"pareas8",                   0x00},  // D+22
            {"pareas9",                   0x00},  // D+23
            {"pareas10",                  0x00},  // D+24
            {"pareas11",                  0x00},  // D+25
            {"pareas12",                  0x00},  // D+26
            {"pareas13",                  0x00},  // D+27
            {"pareas14",                  0x00},  // D+28
            {"pareas15",                  0x00},  // D+29
            {"pareas16",                  0x00},  // D+30
            {"pareas17",                  0x00},  // D+31
            {"pareas18",                  0x00},  // D+32
            {"pareas19",                  0x00},  // D+33
            {"pareas20",                  0x00},  // D+34
            {"pareas21",                  0x00},  // D+35
            {"pareas22",                  0x00},  // D+36
            {"pareas23",                  0x00},  // D+37
            {"pareas24",                  0x00},  // D+38
            {"pareas25",                  0x00},  // D+39
            {"pareas26",                  0x00},  // D+40
            {"pareas27",                  0x00},  // D+41
            {"pareas28",                  0x00},  // D+42
            {"pareas29",                  0x00},  // D+43
            {"pareas30",                  0x00},  // D+44
            {"pdevice_type",              0x7f},  // D+45
            {"prequest_type",             0x00},  // D+46
            {"psearch_type",              0x0a}   // D+47
        };

        _packet = new Packet{header, parameters};
    }

    PointInformationRequestMX6::~PointInformationRequestMX6()
    {
        delete _packet;
    }

    void PointInformationRequestMX6::write()
    {
        _packet->write();
    }

    std::vector<unsigned char> PointInformationRequestMX6::read()
    {
        return _packet->read();
    }


    /*
     * PointInformationReplyMX5
     */
    
    PointInformationReplyMX5::PointInformationReplyMX5(std::vector<unsigned char> data)
    : Content{}
    {
        _params.push_back({Constants::PNAME_SOH,                            data[Constants::PIRMX5_SOH_INDEX]});
        _params.push_back({Constants::PNAME_SEQ,                            data[Constants::PIRMX5_SEQ_INDEX]});
        _params.push_back({Constants::PNAME_PACKET_LENGTH,                  data[Constants::PIRMX5_PACKET_LENGTH_INDEX]});
        _params.push_back({Constants::PNAME_NETWORK_NODE,                   data[Constants::PIRMX5_NETWORK_NODE_INDEX]});
        _params.push_back({Constants::PNAME_CHANNEL,                        data[Constants::PIRMX5_POINT_ADDRESS_CHANNEL_INDEX]});
        _params.push_back({Constants::PNAME_DESTINATION_CHANNEL_ADDRESS,    data[Constants::PIRMX5_DESTINATION_CHANNEL_ADDRESS_INDEX]});
        _params.push_back({Constants::PNAME_DESTINATION_TASK,               data[Constants::PIRMX5_DESTINATION_TASK_INDEX]});
        _params.push_back({Constants::PNAME_SOURCE_CHANNEL_ADDRESS,         data[Constants::PIRMX5_SOURCE_CHANNEL_ADDRESS_INDEX]});
        _params.push_back({Constants::PNAME_SOURCE_TASK,                    data[Constants::PIRMX5_SOURCE_TASK_INDEX]});
        _params.push_back({Constants::PNAME_MARKER,                         data[Constants::PIRMX5_MARKER_INDEX]});
        _params.push_back({Constants::PNAME_PACKET_ID,                      data[Constants::PIRMX5_PACKET_ID_INDEX]});
        _params.push_back({Constants::PNAME_REPLY_STATUS,                   data[Constants::PIRMX5_REPLY_STATUS_INDEX]});
        _params.push_back({Constants::PNAME_FLAGS,                          data[Constants::PIRMX5_FLAGS_INDEX]});
        _params.push_back({Constants::PNAME_NODE,                           data[Constants::PIRMX5_NODE_INDEX]});
        _params.push_back({Constants::PNAME_PCHANNEL,                       data[Constants::PIRMX5_POINT_ADDRESS_CHANNEL_INDEX]});
        _params.push_back({Constants::PNAME_CHANNEL_ADDRESS,                data[Constants::PIRMX5_CHANNEL_ADDRESS_INDEX]});
        _params.push_back({Constants::PNAME_POINT_CATEGORY,                 data[Constants::PIRMX5_POINT_CATEGORY_INDEX]});
        _params.push_back({Constants::PNAME_POINT_NUMBER,                   data[Constants::PIRMX5_POINT_NUMBER_INDEX]});
        _params.push_back({Constants::PNAME_LOGICAL_POINT_NUMBER,           data[Constants::PIRMX5_LOGICAL_POINT_NUMBER_INDEX]});
        _params.push_back({Constants::PNAME_LOGICAL_POINT_ZONE,             data[Constants::PIRMX5_LOGICAL_POINT_ZONE_INDEX]});
        _params.push_back({Constants::PNAME_DEVICE_TYPE,                    data[Constants::PIRMX5_DEVICE_TYPE_INDEX]});
        _params.push_back({Constants::PNAME_AUXILIARY_POINT_ATTRIBUTES,     data[Constants::PIRMX5_AUXILIARY_POINT_ATTRIBUTES_INDEX]});
        _params.push_back({Constants::PNAME_GROUP1,                         data[Constants::PIRMX5_GROUP1_INDEX]});
        _params.push_back({Constants::PNAME_GROUP2,                         data[Constants::PIRMX5_GROUP2_INDEX]});
        _params.push_back({Constants::PNAME_AREA_TYPE,                      data[Constants::PIRMX5_AREA_TYPE_INDEX]});
        _params.push_back({Constants::PNAME_AREA_NUMBER,                    data[Constants::PIRMX5_AREA_NUMBER_INDEX]});
        _params.push_back({Constants::PNAME_SECTOR_ID,                      data[Constants::PIRMX5_SECTOR_ID_INDEX]});
        _params.push_back({Constants::PNAME_LOOP_TYPE,                      data[Constants::PIRMX5_LOOP_TYPE_INDEX]});
        _params.push_back({Constants::PNAME_RAW_IDENTITY,                   data[Constants::PIRMX5_RAW_IDENTITY_INDEX]});
        _params.push_back({Constants::PNAME_ACTUAL_DEVICE_TYPE,             data[Constants::PIRMX5_ACTUAL_DEVICE_TYPE_INDEX]});
        _params.push_back({Constants::PNAME_MODE_AND_SENSITIVITY,           data[Constants::PIRMX5_MODE_AND_SENSITIVITY_INDEX]});
        _params.push_back({Constants::PNAME_RAW_ANALOGUE_VALUES1,           data[Constants::PIRMX5_RAW_ANALOGUE_VALUES1_INDEX]});
        _params.push_back({Constants::PNAME_RAW_ANALOGUE_VALUES2,           data[Constants::PIRMX5_RAW_ANALOGUE_VALUES2_INDEX]});
        _params.push_back({Constants::PNAME_RAW_ANALOGUE_VALUES3,           data[Constants::PIRMX5_RAW_ANALOGUE_VALUES3_INDEX]});
        _params.push_back({Constants::PNAME_LTA_FLAGS,                      data[Constants::PIRMX5_LTA_FLAGS_INDEX]});
        _params.push_back({Constants::PNAME_RAW_LTA,                        data[Constants::PIRMX5_RAW_LTA_INDEX]});
        _params.push_back({Constants::PNAME_DIRTINESS,                      data[Constants::PIRMX5_DIRTINESS_INDEX]});
        _params.push_back({Constants::PNAME_UNITS_OF_MEASURE1,              data[Constants::PIRMX5_UNITS_OF_MEASURE1_INDEX]});
        _params.push_back({Constants::PNAME_UNITS_OF_MEASURE2,              data[Constants::PIRMX5_UNITS_OF_MEASURE2_INDEX]});
        _params.push_back({Constants::PNAME_UNITS_OF_MEASURE3,              data[Constants::PIRMX5_UNITS_OF_MEASURE3_INDEX]});
        _params.push_back({Constants::PNAME_CONVERTED_VALUES1,              data[Constants::PIRMX5_CONVERTED_VALUE1_INDEX]});
        _params.push_back({Constants::PNAME_CONVERTED_VALUES2,              data[Constants::PIRMX5_CONVERTED_VALUE2_INDEX]});
        _params.push_back({Constants::PNAME_CONVERTED_VALUES3,              data[Constants::PIRMX5_CONVERTED_VALUE3_INDEX]});
        _params.push_back({Constants::PNAME_INSTANTANEOUS_ACTIVE_STATE,     data[Constants::PIRMX5_INSTANTANEOUS_ACTIVE_STATE_INDEX]});
        _params.push_back({Constants::PNAME_INSTANTANEOUS_FAULT_STATE,      data[Constants::PIRMX5_INSTANTANEOUS_FAULT_STATE_INDEX]});
        _params.push_back({Constants::PNAME_CONFIRMED_ACTIVE_STATE,         data[Constants::PIRMX5_CONFIRMED_ACTIVE_STATE_INDEX]});
        _params.push_back({Constants::PNAME_CONFIRMED_FAULT_STATE,          data[Constants::PIRMX5_CONFIRMED_FAULT_STATE_INDEX]});
        _params.push_back({Constants::PNAME_ACKNOWLEDGED_ACTIVE_STATE,      data[Constants::PIRMX5_ACKNOWLEDGED_ACTIVE_STATE_INDEX]});
        _params.push_back({Constants::PNAME_ACKNOWLEDGED_FAULT_STATE,       data[Constants::PIRMX5_ACKNOWLEDGED_FAULT_STATE_INDEX]});
        _params.push_back({Constants::PNAME_OUTPUT_FORCED_MODE,             data[Constants::PIRMX5_OUTPUT_FORCED_MODE_INDEX]});
        _params.push_back({Constants::PNAME_OUTPUT_UNFORCED_STATE,          data[Constants::PIRMX5_OUTPUT_UNFORCED_STATE_INDEX]});
        _params.push_back({Constants::PNAME_OUTPUT_FORCED_STATE,            data[Constants::PIRMX5_OUTPUT_FORCED_STATE_INDEX]});
        _params.push_back({Constants::PNAME_CLIENTID1,                      data[Constants::PIRMX5_CLIENT_ID1_INDEX]});
        _params.push_back({Constants::PNAME_CLIENTID2,                      data[Constants::PIRMX5_CLIENT_ID2_INDEX]});
    }

    bool PointInformationReplyMX5::reply_successful()
    {
        return get_parameter(Constants::PNAME_REPLY_STATUS) == 0;
    }

    std::string PointInformationReplyMX5::get_as_csv()
    {
        std::stringstream csv_stream;
        
        std::vector<unsigned char> byte_array = get_byte_array();
        std::vector<std::string> decoded = Packets::Decoding::MX5::decode_point_information_reply(byte_array);

        for (const auto& value : decoded)
        {
            csv_stream << value;
            csv_stream << ",";
        }

        std::string csv_string = csv_stream.str();

        // Remove last comma from end.
        csv_string = csv_string.substr(0, csv_string.size() - 1);

        return csv_string;
    }
}