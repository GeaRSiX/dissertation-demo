/*!
    @file   GroveCommunication.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for abstract base class that all Grove Communcation modules inherit.

    Inherited by all Grove* classes that fall under the Communication category defined by seeed. 
    Provides the user with a common interface for all Grove Communication modules.

    @see http://wiki.seeed.cc/Communication/
*/

#ifndef GROVECOMMUNICATION
#define GROVECOMMUNICATION

#include "GroveCommon.h"
#include "GrovePinout.h"

//! Grove Communication Abstract Base Class (ABC). Inherited by all Grove Communication modules.
/*!
    ABC for any Grove Communication module. This provides the interface that users that want to use 
    any communication modules.

    @note Grove Communication modules generally use UART to communicate to the modules, consequently 
    both pin1 and pin2 need to be specified and the read/write functions use char *buffers.

    The implemented modules that use this as their ABC are:
     - GroveGPS
*/
class GroveCommunication
{
protected:
    //! GrovePinout for handling the pin logic
    GrovePinout pinout;

    //! Constructor
    /*! Creates an instance of GroveCommunication and initialised it's pinout member.
        
        @param pin1_rx The pin that will RX from the module's pin1 (yellow cable)
        @param pin2_tx The pin that will TX to the module's pin2 (white cable) 
    */
    GroveCommunication(int pin1_rx, int pin2_tx)
     : pinout(pin1_rx, pin2_tx) {};

public:
    //! Will read via UART and return a GroveCommon::ReturnCode to indicate it's success/failure
    /*!
        The read function will read a string into buffer.

        @param buffer The buffer that data read from the module will be stored in. Should have at 
        least GroveCommon::MAX_BUFF bytes allocated to it.

        @return GroveCommon::ReturnCode indicates the success of the function.

        @see @file GroveCommon.h
    */
    virtual GroveCommon::ReturnCode read(char *buffer) = 0;

    //! Will write to the module via UART and return a GroveCommon::ReturnCode to indicate it's success/failure
    /*!
        The write function will write buffer to the module.

        @param buffer The buffer of data that will be written to the module.

        @return GroveCommon::ReturnCode indicates the success of the function.

        @see @file GroveCommon.h
    */
    virtual GroveCommon::ReturnCode write(char *buffer) = 0;
};

#endif  //GROVECOMMUNICATION

