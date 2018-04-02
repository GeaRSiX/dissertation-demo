/*!
    @file   GroveRotaryAngle.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove RotaryAngle module.

    Implementation for the Grove RotaryAngle module. Inherits the Grove Sensor ABC and provides the 
    implementation for the RotaryAngle module.

    @see http://wiki.seeed.cc/Grove-Rotary_Angle_Sensor/
    @see GroveSensor.h
*/

#ifndef GROVEROTARYANGLE
#define GROVEROTARYANGLE

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveSensor.h"

//! The ADC voltage (used to calculate the turn degrees)
/*!
    @note This value needs to be changed to 5 if the module is connected to a 5v pinout
*/
static const float ADC_REF = 3.3;

//! The value when the sensor is fully turned
static const int MAX_DEGREE = 300;

//! Grove RotaryAngle Class for the Grove RotaryAngle Module.
/*!
    Provides the functionality of the Grove RotaryAngle Module. Uses an analog pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for analog 
    i/o.
*/
class GroveRotaryAngle : public GroveSensor
{
public:
    //! Constructor
    /*! Creates an instance of GroveRotaryAngle
        
        @param analog_pin The analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for analog pinouts)
    */
    GroveRotaryAngle(int analog_pin)
     : GroveSensor(analog_pin) {};

    //! Will read the analog value being sent down pin and return a float of the value read
    /*!
        The read function will return the calculated degree of the value read from it's pin.

        The degrees the sensor has been turned is calculated based on the voltage

        @note The ADC_REF value needs to be changed to 5 if the module is connected to a 5v pinout

        @return float The calculated degree, based on the value read from the module's connected pin (should be between 0 - 300).
    */
    float read();
};

#endif  //GROVEROTARYANGLE

