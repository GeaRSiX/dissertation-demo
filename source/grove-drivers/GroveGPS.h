/*!
    @file   GroveGPS.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove GPS module.

    Implementation for the Grove GPS Communication module. Inherits the GroveCommuncation ABC and 
    provides the implementation for the GPS Sensor.

    @note This module communicates over UART at a baud rate of 9600, make sure this is set correctly 
    on your platform

    @note This module is constantly putting out a set of NMEA values (GPGGA, GPGSA, GPGSV and GPRMC), 
    this means that to read all the data sent by the module

    @see http://wiki.seeed.cc/Grove-GPS/
    @see GroveCommunication.h
*/

#ifndef GROVEGPS
#define GROVEGPS

#include "GroveCommunication.h"
#include "GrovePinout.h"
#include "GroveCommon.h"

#include <cstring>

//! Grove GPS Module class
/*!
    Provides the functionality of the Grove GPS module. It communicates to it via UART at a baud rate 
    of 9600.

    @note This module is constantly putting out a set of NMEA values (GPGGA, GPGSA, GPGSV and GPRMC), 
    this means that to read all the data sent by the module.
*/
class GroveGPS : public GroveCommunication
{
public:
    //! Constructor
    /*! Creates an instance of GroveGPS

        @param pin1_rx The pin used to RX from the GPS module, connected to pin1 on the module (yellow 
        cable).
        @param pin2_tx The pin used to TX to the GPS module, connected to pin2 on the module (white 
        cable).
    */
    GroveGPS(int pin1_rx, int pin2_tx)
     : GroveCommunication(pin1_rx, pin2_tx) {};

    //! Reads a line of data from the module via UART @ 9600 baud.
    /*!
        Throws away bytes until it hits the start-delimeter of a line ('$') and then stores bytes in 
        buffer until it hits the end-delimeter of a line ('\n'). This shouldn't result in buffer being 
        filled with more data than GroveCommon::BUFFSIZE.

        @param buffer A buffer that valid data is read into. Should be of sizze GroveCommon:BUFFSIZE

        @note There are instances (due ot the baud rate) where a end-delimeter is skipped, however this is
        compensated for. There isn't a handle for what happens if a start delimeter is skipped yet, since 
        this hasn't come up during testing. I'm assuming that this is why the function occassionally takes 
        a while to finish.

        @note This module is constantly putting out a set of NMEA values (GPGGA, GPGSA, GPGSV and GPRMC), 
        this means that to read all the data sent by the module.
    */
    GroveCommon::ReturnCode read(char *buffer);

    //! Writes a line of data from the module via UART @ 9600 baud.
    /*!
        As far as I'm aware, the Grove GPS module doesn't respond to UART input. I haven't read ALL 
        the doc though, so I might be wrong, I've implemented it here just incase.

        @param buffer The buffer of data written over UART
    */
    GroveCommon::ReturnCode write(char *buffer);
};

#endif  //GROVEGPS

