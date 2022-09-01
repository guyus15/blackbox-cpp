/**
 * @file packet_types.cpp
 * @brief Contains concrete implementations of frequently used packets.
 * @author G. Chamberlain-Webber
 */

#include "packet/packet_types.h"

#include "packet/headers.h"
#include "packet/packet_ids.h"

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

    std::vector<unsigned char> PointInformationRequestMX5::read()
    {
        return _packet->read();
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
}