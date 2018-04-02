/*!
    @file   GroveActuator.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for abstract base class that all Grove Actuator modules inherit.

    Inherited by all Grove* classes that fall under the Actuator category defined by seeed. 
    Provides the user with a common interface for all Grove Actuator modules.

    @see http://wiki.seeed.cc/Actuator/
*/

#ifndef GROVEACTUATOR
#define GROVEACTUATOR

#include "GroveCommon.h"
#include "GrovePinout.h"

//! Grove Actuator Abstract Base Class (ABC). Inherited by all Grove Actuator modules.
/*!
    ABC for any Grove Actuator module. This provides the interface that users that want to use 
    any actuator modules.

    The implemented modules that use this as their ABC are:
     - GroveButton
     - GroveLED
     - GroveBuzzer
*/
class GroveActuator
{
protected:
    //! GrovePinout for handling the pin logic
    GrovePinout pinout;

    //! Constructor
    /*! Creates an instance of GroveActuator and initialised it's pinout member.
        
        @param pin The digital/analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for digital and analog pinouts)
    */
    GroveActuator(int pin)
     : pinout(pin) {};

public:
    //! Will read via digital/analog and return a float of the value read
    /*!
        The read function will return the value read from it's pin. Whilst it does return a float 
        this is to accomodate for the modules that require an anolog pin and analog read values. In 
        the case of any digital pin modules, the float will be an integer (although it's type will 
        still be a float).

        @return float The value read from the module's connected pin.
    */
    virtual float read() = 0;

    //! Will write a value digital/analog and return a GroveCommon:ReturnCode indicating success/failure
    /*!
        This write function writes a value to the pin of the actuator, which the module (in most cases) 
        responds to by changing it's state accordingly. 'value' is a float, however in many instances 
        only an integer will be required (it's a float in the case that you're doing an analogWrite).

        @note Not all modules make use of this functio (e.g. the Grove Button module), but it'll be 
        implemented in case you're a wizard that can invest some secret functionality for the module.

        @return GroveCommon::ReturnCode indicating success/failure of the function
    */
    virtual GroveCommon::ReturnCode write(float value) = 0;
};

#endif  //GROVEACTUATOR

