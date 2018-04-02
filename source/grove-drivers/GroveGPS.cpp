/*!
    @file   GroveGPS.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The source file for the Grove GPS module.

    Implementation for the Grove GPS Communication module. Inherits the GroveCommuncation ABC and 
    provides the implementation for the GPS Sensor.

    @note This module is constantly putting out a set of NMEA values (GPGGA, GPGSA, GPGSV and GPRMC), 
    this means that to read all the data sent by the module

    @see http://wiki.seeed.cc/Grove-GPS/
    @see GroveCommunication.h
*/

#include "GroveGPS.h"

//! @todo big possibility of buffer overflow here; test & fix
GroveCommon::ReturnCode GroveGPS::read(char *buffer)
{
    // throw away until we hit start-delimeter
    while (buffer[0] != '$')
        buffer[0] = GroveCommon::uartRead(pinout.get(2));

    // fill buffer until MAX_BUFF or end-delimeter
    for (int i = 1; i < GroveCommon::MAX_BUFF; i++)
    {
        buffer[i] = GroveCommon::uartRead(pinout.get(2));

        if (buffer[i] == '$')
            buffer[i] = '\0';
        if (buffer[i] == '\0' || buffer[i] == '\n')
            break;
    }

    return GroveCommon::ReturnCode::Success;
}

//! @todo error checking; test & fix
GroveCommon::ReturnCode GroveGPS::write(char *buffer)
{
    for (int i = 0; i < strlen(buffer)-1; i++)
        GroveCommon::uartWrite(pinout.get(2), (uint8_t)buffer[i]);

    return GroveCommon::ReturnCode::Success;
}

