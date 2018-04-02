/*!
    @file   GroveCommon.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The namespace containing all the data & functions common to all Grove files (error codes
     etc).
     
     @see IMPORTANT! Some functions in this file act as wrappers for platform-specific functionality,
      consequently they require a unique implementation for each platform this framework is ported to.
*/

#ifndef GROVECOMMON
#define GROVECOMMON

#include <cstdint>
#include "MicroBit.h"

//! Namespace that contains all the data & functions common to files in this framework
/*!
    This namespace contains any data/functions common to this framework.

    The ReturnCode enum is used to return one of a standard set of codes for user functions by 
    default. The only instances that these ReturnCodes aren't used is in functions that aren't 
    exposed to the user or functions that need to use their return value for something else (e.g. 
    read()).

    @note The functions in this file require implementation for specific platforms as they act as wrappers.
    If these functions are not defined and you try compile the errors will trigger. Without 
    implementating these functions, the framework simply won't do anything besides take up memory.

    @note It's important that you review this file to understand the framework.
*/
namespace GroveCommon
{
    //! Pointer to the MicroBitinstance being used to communicate with hardware
    extern MicroBit *mBit;

    //! Return codes used by all Grove* classes
    enum class ReturnCode {
        Success,        /**< Successful return */
        InvalidPin,     /**< Attempted to read from an invalid pin */
        InvalidParam    /**< Invalid parameter passed to function */
    };

    //! Maximum required size of a buffer that data is read into
    const int MAX_BUFF = 250;  /**< @todo Test this */

    //! Read analog value from pin
    /*!
        The analog read function used by all Grove* classes that require analog read.

        @note This function acts as a wrapper for the analogRead function used by the specific 
        platform using this framework. Add whatever function is used to get an Analog read from 
        pin on your platform to the source code of this function.

        @return float read analog value
    */
   int analogRead(int pin);

    //! Write value to analog pin
    /*!
        The analog write function used by all Grove* classes that require analog write.

        @note This function acts as a wrapper for the analogRead function used by the specific 
        platform using this framework. Add whatever function is used to get an Analog read from 
        pin on your platform to the source code of this function.

        @return int up to the user (if unsure, return 0 or a GroveCommon::ReturnCode)
    */
   int analogWrite(int pin, uint8_t value);

    //! Read digital value from pin
    /*!
        The digital read function used by all Grove* classes that require digital read.

        @param pin The pin to read a value from

        @note This function acts as a wrapper for the digitalRead function used by the specific 
        platform using this framework. Add whatever function is used to get a Digital read from 
        your platform to the source of this function.

        @return int read digital value
    */
   int digitalRead(int pin);

    //! Write value to digital pin
    /*!
        The digital write function used by all Grove* classes that require digital write.

        @param pin The pin to write value to
        @param value The value to write to pin

        @note This function acts as a wrapper for the digitalRead function used by the specific 
        platform using this framework. Add whatever function is used to get an Analog read from 
        pin on your platform to the source code of this function.

        @return int up to the user (if unsure, return 0 or a GroveCommon::ReturnCode)
    */
   int digitalWrite(int pin, uint8_t value);

   //! Read a byte of data over UART
   /*!
        Reads a SINGLE byte of data from over UART

        @param rx_pin Pin that the module's UART RX is connected to

        @note This function acts as a wrapper for the digitalRead function used by the specific 
        platform using this framework. Add whatever function is used to get an Analog read from 
        pin on your platform to the source code of this function.

        @return uint8_t the byte of data read via uart
   */
   uint8_t uartRead(int rx_pin);

   //! Write a byte of data over UART
   /*!
        Writes a SINGLE byte of data from over UART

        @param tx_pin Pin that the module's UART TX is connected to
        @param byte The byte you want to transmit

        @note This function acts as a wrapper for the digitalRead function used by the specific 
        platform using this framework. Add whatever function is used to get an Analog read from 
        pin on your platform to the source code of this function.

        @return int up to the user (if unsure, return 0 or a GroveCommon::ReturnCode)
   */
   uint8_t uartWrite(int tx_pin, uint8_t byte);
}

#endif //GROVECOMMON

