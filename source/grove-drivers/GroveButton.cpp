/*!
    @file   GroveButton.cpp
    @author Alexander Collins (alexander-collins@outlook.com)
    @date   September 2017 - April 2018
    @brief  The source file for the GroveButton module

    Implementation for the Grove Button Actuator module.

    @see http:/wiki.seeed.cc/Grove-Button/
    @see GroveButton.h
*/

#include "GroveButton.h"

float GroveButton::read()
{
    return GroveCommon::digitalRead(pinout.get());
}

GroveCommon::ReturnCode GroveButton::write(float value)
{
    GroveCommon::digitalWrite(pinout.get(), (int)value);

    return GroveCommon::ReturnCode::Success;
}

