/*!
    @file   GroveLED.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove LED modules.

    Implementation for the Grove LED module. Inherits the Grove Actuator ABC and provides the 
    implementation for the LED module.

    @see http://wiki.seeed.cc/Grove-LED/
    @see GroveActuator.h
*/

#ifndef GROVELED
#define GROVELED

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveActuator.h"

//! Grove LED Class for the Grove LED Module.
/*!
    Provides the functionality of the Grove LED Module. Uses a analog pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for analog 
    i/o.
*/
class GroveLED : public GroveActuator
{
public:
    //! Constructor
    /*! Creates an instance of GroveLED
        
        @param analog_pin The analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for analog pinouts)
    */
    GroveLED(int analog_pin)
     : GroveActuator(analog_pin) {};

    //! Will read the analog value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        @note Whilst this function returns a float, the value returned will always be an integer 
        since it's reading a analog pin value (it's a float for other module's sake).

        @return float The value read from the module's connected pin.
    */
    float read();

    //! Will write a analog value analog and return a GroveCommon:ReturnCode indicating success/failure
    /*!
        This write function writes a value to the pin of the LED. I'm pretty sure the module doens't 
        respond to this, but i've implemented it incase :)

        @note Pretty sure this module doesn't respond to having values written down it's pin, but it's 
        implemented here in case you're a wizard that can invest some secret functionality for the module.

        @return GroveCommon::ReturnCode indicating success/failure of the function
    */
    GroveCommon::ReturnCode write(float value);
};

#endif  //GROVELED

