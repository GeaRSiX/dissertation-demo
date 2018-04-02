/*!
    @file   GrovePinout.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file included in all grove modules that handles pin stuff

    Handles all the pin stuff for GroveDrivers modules.

	@see http://wiki.seeed.cc/Grove_System/#interface-of-grove-modules
*/

#ifndef GROVEPINOUT
#define GROVEPINOUT

#include "GroveCommon.h"

//! GrovePinout class, handles all data & logic for a module's pins
/*!
    Class is inherited by all abstract Grove* classes that are inherited by any other Grove** module
    class.
*/
class GrovePinout
{
private:
    int pin1;
    int pin2;
public:
    //! Constructor
    /*! Creates an instance of GrovePinout

        Shouldn't be required by the user, this file is used by the Grove Abstract Base Classes to 
        handle pin logic.

        Not all grove modules require pin1 and pin2. For example, the Digital and Analog grove 
        modules use pin1 and pin2 for the same purpose - others, such as UART and I2C use both 
        though.
        
        @param pin The pin corresponding to pin1 (yellow cable) of the Grove module.

        @see GroveSensor.h
        @see GroveActuator.h
    */
    GrovePinout(int pin)
     : pin1(pin) {};

    //! Constructor
    /*! Creates an instance of GrovePinout

        Shouldn't be required by the user, this file is used by the Grove Abstract Base Classes to 
        handle pin logic.

        Not all grove modules require pin1 and pin2. For example, the Digital and Analog grove 
        modules use pin1 and pin2 for the same purpose - others, such as UART and I2C use both 
        though.
        
        @param pin1 The pin corresponding to pin1 (yellow cable) of the Grove module.
        @param pin2 The pin corresponding to pin2 (white cable) of the Grove module.

        @see GroveCommunication.h
    */
    GrovePinout(int pin1, int pin2)
     : pin1(pin1), pin2(pin2) {};

    //! Get pin1's value
    /*!
        This function returns the value of pin1 (it's a shorthand in the case that you used the single-
        pin constructor).

        @return The value of pin1
    */
    int get();

    //! Get a pin's value
    /*!
        If an invalid pin parameter is passed the function does nothing.

        @param pin Pin to retrieve the value of (1 or 2)

        @return The value of pin
    */
    int get(int pin);

    //! Set a pin1's value
    /*!
        @param val Value to set pin1 to
    */
    void set(int val);

    //! Set a pin's value
    /*!
        If an invalid pin value is given the function does nothing.

        @param pin Pin to set the value of (1 or 2)
        @param val Value to set pin to
    */
    void set(int pin, int val);
};

#endif //GROVEPINOUT

