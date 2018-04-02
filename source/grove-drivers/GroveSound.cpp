/*!
    @file   GroveSound.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The header file for the Grove Sound module.

    Implementation for the Grove Sound module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Sound module.

    @see http://wiki.seeed.cc/Grove-Sound_Sensor/
    @see GroveSound.h
*/

#include "GroveSound.h"

float GroveSound::read()
{
    long sum = 0;
    for (int i = 0; i < 32; i++)
        sum += GroveCommon::analogRead(pinout.get());
    sum >>= 5;

    return sum;
}

