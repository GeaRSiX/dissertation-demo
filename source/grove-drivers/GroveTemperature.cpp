/*!
    @file   GroveTemperature.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The source file for the Grove Temperature module.

    Implementation for the Grove Temperature module. Inherits the Grove Sensor ABC and provides the 
    implementation for the Temperature module.

    @see http://wiki.seeed.cc/Grove-Temperature_Sensor/
    @see http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/
    @see GroveTemperature.h
*/

#include "GroveTemperature.h"

//! B constant of thermistor
static const int B = 4275;
//! Resistance in ambient temperature T0(K) = 100k
static const long R0 = 100000;


float GroveTemperature::read()
{
    // get raw read
    float T = GroveCommon::analogRead(pinout.get());
    // calculate resistance
    float R = R0 * (1023 / T - 1.0);
    // calculate temperature
    float temperature = 1.0 / (log(R/R0) / B+1 / 298.15) - 273.15;

    return temperature;
}

