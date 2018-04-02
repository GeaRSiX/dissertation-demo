/*!
    @file   GroveRotaryAngle.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove RotaryAngle module.

    Implementation for the Grove RotaryAngle module. Inherits the Grove Sensor ABC and provides the 
    implementation for the RotaryAngle module.

    @see http://wiki.seeed.cc/Grove-RotaryAngle_Sensor/
    @see GroveRotaryAngle.h
*/

#include "GroveRotaryAngle.h"

float GroveRotaryAngle::read()
{
    int raw = GroveCommon::analogRead(pinout.get());
    float vcc = (float)raw * (ADC_REF/1023);
    float degrees = (vcc * MAX_DEGREE) / ADC_REF;

    return degrees;
}

