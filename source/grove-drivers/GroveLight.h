/*!
    @file   GroveLight.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Light module.

    Implementation for the Grove Light module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Light module.

    @see http://wiki.seeed.cc/Grove-Light_Sensor/
    @see GroveSensor.h
*/

#ifndef GROVELIGHT
#define GROVELIGHT

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveSensor.h"

//! Grove Light Class for the Grove Light Module.
/*!
    Provides the functionality of the Grove Light Module. Uses an analog pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for analog 
    i/o.
*/
class GroveLight : public GroveSensor
{
public:
    //! Constructor
    /*! Creates an instance of GroveLight
        
        @param analog_pin The analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for analog pinouts)
    */
    GroveLight(int analog_pin)
     : GroveSensor(analog_pin) {};

    //! Will read the analog value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        The value read is the sum of 32 reads >> 5.

        @return float The calculated light, based on the values read from the module's connected pin.
    */
    float read();
};

#endif  //GROVELIGHT

