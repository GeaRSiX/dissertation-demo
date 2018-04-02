/*!
    @file   GroveBuzzer.cpp
    @author Alexander Collins (alexander-collins@outlook.com)
    @date   September 2017 - April 2018
    @brief  The source file for the GroveBuzzer module

    Implementation for the Grove Buzzer Actuator module.

    @see http:/wiki.seeed.cc/Grove-Buzzer/
    @see GroveBuzzer.h
*/

#include "GroveBuzzer.h"

float GroveBuzzer::read()
{
    return GroveCommon::analogRead(pinout.get());
}

GroveCommon::ReturnCode GroveBuzzer::write(float value)
{
    GroveCommon::digitalWrite(pinout.get(), (int)value);

    return GroveCommon::ReturnCode::Success;
}

