/*!
    @file   GroveLED.cpp
    @author Alexander Collins (alexander-collins@outlook.com)
    @date   September 2017 - April 2018
    @brief  The source file for the GroveLED module

    Implementation for the Grove LED Actuator module.

    @see http:/wiki.seeed.cc/Grove-LED/
    @see GroveLED.h
*/

#include "GroveLED.h"

float GroveLED::read()
{
    return (float)GroveCommon::analogRead(pinout.get());
}

GroveCommon::ReturnCode GroveLED::write(float value)
{
    GroveCommon::analogWrite(pinout.get(), (int)value);

    return GroveCommon::ReturnCode::Success;
}

