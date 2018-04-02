/*!
    @file   GroveTouch.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Touch module.

    Implementation for the Grove Touch module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Touch module.

    @see http://wiki.seeed.cc/Grove-Touch_Sensor/
    @see GroveTouch.h
*/

#include "GroveTouch.h"

float GroveTouch::read()
{
    return GroveCommon::digitalRead(pinout.get());
}

