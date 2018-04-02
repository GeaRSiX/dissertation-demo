/*
    @file   GrovePinout.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The source file included in all grove modules that handles pin stuff

	@see http://wiki.seeed.cc/Grove_System/#interface-of-grove-modules
*/

#include "GrovePinout.h"

int GrovePinout::get()
{
    return pin1;
}

int GrovePinout::get(int pin)
{
    switch(pin)
    {
        case 1: return pin1;    break;
        case 2: return pin2;    break;
        default:
            break;
    }
}

void GrovePinout::set(int val)
{
    pin1 = val;
}

void GrovePinout::set(int pin, int val)
{
    switch(pin)
    {
        case 1: pin1 = val;     break;
        case 2: pin2 = val;     break;
        default:
            break;
    }
}
