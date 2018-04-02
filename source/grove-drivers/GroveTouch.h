/*!
    @file   GroveTouch.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Touch module.

    Implementation for the Grove Touch module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Touch module.

    @see http://wiki.seeed.cc/Grove-Touch_Sensor/
    @see GroveSensor.h
*/

#ifndef GROVETOUCH
#define GROVETOUCH

#include "GroveCommon.h"
#include "GrovePinout.h"
#include "GroveSensor.h"

//! Grove Touch Class for the Grove Touch Module.
/*!
    Provides the functionality of the Grove Touch Module. Uses an digital pin (doesn't matter if you 
    initialise with pin1 or pin2 connected (yellow/white cable) - they're interchangable for digital 
    i/o.
*/
class GroveTouch : public GroveSensor
{
public:
    //! Constructor
    /*! Creates an instance of GroveTouch
        
        @param digital_pin The digital pin that either pin1 or pin2 are connected to (yellow/white 
        cable) (doesn't matter which for digital pinouts)
    */
    GroveTouch(int digital_pin)
     : GroveSensor(digital_pin) {};

    //! Will read the digital value being sent down pin and return a float of the value read
    /*!
        The read function will return the value read from it's pin.

        @note Whilst this function returns a float, the value returned will always be an integer 
        since it's reading a digital pin value (it's a float for other module's sake).

        @return float The value read from the module's connected pin.
    */
    float read();
};

#endif  //GROVETOUCH

