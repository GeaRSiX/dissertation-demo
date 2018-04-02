/*!
    @file   GroveLight.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Light module.

    Implementation for the Grove Light module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Light module.

    @see http://wiki.seeed.cc/Grove-Light_Sensor/
    @see GroveLight.h
*/

#include "GroveLight.h"

float GroveLight::read()
{
    return GroveCommon::analogRead(pinout.get());
}

