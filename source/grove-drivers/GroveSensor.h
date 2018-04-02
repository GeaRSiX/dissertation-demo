/*!
    @file   GroveSensor.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for abstract base class that all Grove Sensor modules inherit.

    Inherited by all Grove* classes that fall under the Sensor category defined by seeed. 
    Provides the user with a common interface for all Grove Sensor modules.

    @see http://wiki.seeed.cc/Sensor/
*/

#ifndef GROVESENSOR
#define GROVESENSOR

#include "GroveCommon.h"
#include "GrovePinout.h"

//! Grove Sensor Abstract Base Class (ABC). Inherited by all Grove Sensor modules.
/*!
    ABC for any Grove Sensor module. This provides the interface that users that want to use 
    any sensor modules.

    The implemented modules that use this as their ABC are:
     - GroveTemperature
     - GroveRotaryAngle
     - GroveTouch
     - GroveLight
     - GroveSound
*/
class GroveSensor
{
protected:
    //! GrovePinout for handling the pin logic
    GrovePinout pinout;

    //! Constructor
    /*! Creates an instance of GroveSensor and initialised it's pinout member.
        
        @param pin The digital/analog pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for digital and analog pinouts)
    */
    GroveSensor(int pin)
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
};

#endif  //GROVESENSOR

