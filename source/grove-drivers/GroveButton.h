/*!
    @file   GroveButton.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Button modules.

    Implementation for the Grove Button module. Inherits the Grove Actuator ABC and provides the 
    implementation for the Button module.

    @see http://wiki.seeed.cc/Grove-Button/
    @see GroveActuator.h
*/

#ifndef GROVEBUTTON
#define GROVEBUTTON

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveActuator.h"

//! Grove Button Class for the Grove Button Module.
/*!
    Provides the functionality of the Grove Button Module. Uses a digital pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for digital 
    i/o.

    @note I'm pretty sure the write function doesn't do anything for this module, but the function's 
    implemented incase I've missed something.
*/
class GroveButton : public GroveActuator
{
public:
    //! Constructor
    /*! Creates an instance of GroveButton
        
        @param digital_pin The digital pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for digital pinouts)
    */
    GroveButton(int digital_pin)
     : GroveActuator(digital_pin) {};

    //! Will read the digital value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        @note Whilst this function returns a float, the value returned will always be an integer 
        since it's reading a digital pin value (it's a float for other module's sake).

        @return float The value read from the module's connected pin.
    */
    float read();

    //! Will write a digital value digital and return a GroveCommon:ReturnCode indicating success/failure
    /*!
        This write function writes a value to the pin of the button. I'm pretty sure the module doens't 
        respond to this, but i've implemented it incase :)

        @note Pretty sure this module doesn't respond to having values written down it's pin, but it's 
        implemented here in case you're a wizard that can invest some secret functionality for the module.

        @return GroveCommon::ReturnCode indicating success/failure of the function
    */
    GroveCommon::ReturnCode write(float value);
};

#endif  //GROVEBUTTON

