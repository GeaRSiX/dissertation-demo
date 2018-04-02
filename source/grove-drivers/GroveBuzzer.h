/*!
    @file   GroveBuzzer.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Buzzer modules.

    Implementation for the Grove Buzzer module. Inherits the Grove Actuator ABC and provides the 
    implementation for the Buzzer module.

    @see http://wiki.seeed.cc/Grove-Buzzer/
    @see GroveActuator.h
*/

#ifndef GROVEBUZZER
#define GROVEBUZZER

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveActuator.h"

//! Grove Buzzer Class for the Grove Buzzer Module.
/*!
    Provides the functionality of the Grove Buzzer Module. Uses a digital pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for digital 
    i/o.
*/
class GroveBuzzer : public GroveActuator
{
public:
    //! Constructor
    /*! Creates an instance of GroveBuzzer
        
        @param digital_pin The digital pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for digital pinouts)
    */
    GroveBuzzer(int digital_pin)
     : GroveActuator(digital_pin) {};

    //! Will read the digital value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        @return float The value read from the module's connected pin.
    */
    float read();

    //! Will write a digital value digital and return a GroveCommon:ReturnCode indicating success/failure
    /*!
        This write function writes a value to the pin of the buzzer.

        See what sounds you can make!

        @return GroveCommon::ReturnCode indicating success/failure of the function
    */
    GroveCommon::ReturnCode write(float value);
};

#endif  //GROVEBUZZER

