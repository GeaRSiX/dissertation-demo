/*!
    @file   GroveTemperature.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Temperature module.

    Implementation for the Grove Temperature module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Temperature module.

    @see http://wiki.seeed.cc/Grove-Temperature_Sensor/
    @see http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/
    @see GroveSensor.h
*/

#ifndef GROVETEMPERATURE
#define GROVETEMPERATURE

#include <cmath>
#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveSensor.h"

//! Grove Temperature Class for the Grove Temperature Module.
/*!
    Provides the functionality of the Grove Temperature Module. Uses an analog pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for analog 
    i/o.
*/
class GroveTemperature : public GroveSensor
{
public:
    //! Constructor
    /*! Creates an instance of GroveTemperature
        
        @param analog_pin The analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for analog pinouts)
    */
    GroveTemperature(int analog_pin)
     : GroveSensor(analog_pin) {};

    //! Will read the analog value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        The celcius temperature is calulated using the reference in the link below.

            The detectable temperature range is between -40ºC to 125ºC, it's accurate within ±1.5ºC. 

        @return float The calculated temperature, based on the value read from the module's connected pin.

        @see http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/#reference for details on this implementation
    */
    float read();
};

#endif  //GROVETEMPERATURE

