/*
    @file   GroveCommon.cpp
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief  The namespace containing all the data & functions common to all Grove files (error codes
     etc).
*/

#include "GroveCommon.h"

namespace GroveCommon
{
    MicroBit *mBit;

    int analogRead(int pin)
    {
        switch(pin)
        {
            case MICROBIT_PIN_P0:   return mBit->io.P0.getAnalogValue();
            case MICROBIT_PIN_P1:   return mBit->io.P1.getAnalogValue();
            case MICROBIT_PIN_P2:   return mBit->io.P2.getAnalogValue();
            case MICROBIT_PIN_P3:   return mBit->io.P3.getAnalogValue();
            case MICROBIT_PIN_P4:   return mBit->io.P4.getAnalogValue();
            case MICROBIT_PIN_P5:   return mBit->io.P5.getAnalogValue();
            case MICROBIT_PIN_P6:   return mBit->io.P6.getAnalogValue();
            case MICROBIT_PIN_P7:   return mBit->io.P7.getAnalogValue();
            case MICROBIT_PIN_P8:   return mBit->io.P8.getAnalogValue();
            case MICROBIT_PIN_P9:   return mBit->io.P9.getAnalogValue();
            case MICROBIT_PIN_P10:  return mBit->io.P10.getAnalogValue();
            case MICROBIT_PIN_P11:  return mBit->io.P11.getAnalogValue();
            //P12 Reserved: accessibility
            case MICROBIT_PIN_P13:  return mBit->io.P13.getAnalogValue();
            case MICROBIT_PIN_P14:  return mBit->io.P14.getAnalogValue();
            case MICROBIT_PIN_P15:  return mBit->io.P15.getAnalogValue();
            case MICROBIT_PIN_P16:  return mBit->io.P16.getAnalogValue();
            //P17 +3v3
            //P18 +3v3
            case MICROBIT_PIN_P19:  return mBit->io.P19.getAnalogValue();
            case MICROBIT_PIN_P20:  return mBit->io.P20.getAnalogValue();
            //P21 GND
            //P22 GND
            default:
                return -1;
                break;
        }
    }

    int digitalRead(int pin)
    {
        switch(pin)
        {
            case MICROBIT_PIN_P0:   return mBit->io.P0.getDigitalValue();
            case MICROBIT_PIN_P1:   return mBit->io.P1.getDigitalValue();
            case MICROBIT_PIN_P2:   return mBit->io.P2.getDigitalValue();
            case MICROBIT_PIN_P3:   return mBit->io.P3.getDigitalValue();
            case MICROBIT_PIN_P4:   return mBit->io.P4.getDigitalValue();
            case MICROBIT_PIN_P5:   return mBit->io.P5.getDigitalValue();
            case MICROBIT_PIN_P6:   return mBit->io.P6.getDigitalValue();
            case MICROBIT_PIN_P7:   return mBit->io.P7.getDigitalValue();
            case MICROBIT_PIN_P8:   return mBit->io.P8.getDigitalValue();
            case MICROBIT_PIN_P9:   return mBit->io.P9.getDigitalValue();
            case MICROBIT_PIN_P10:  return mBit->io.P10.getDigitalValue();
            case MICROBIT_PIN_P11:  return mBit->io.P11.getDigitalValue();
            //P12 Reserved: accessibility
            case MICROBIT_PIN_P13:  return mBit->io.P13.getDigitalValue();
            case MICROBIT_PIN_P14:  return mBit->io.P14.getDigitalValue();
            case MICROBIT_PIN_P15:  return mBit->io.P15.getDigitalValue();
            case MICROBIT_PIN_P16:  return mBit->io.P16.getDigitalValue();
            //P17 +3v3
            //P18 +3v3
            case MICROBIT_PIN_P19:  return mBit->io.P19.getDigitalValue();
            case MICROBIT_PIN_P20:  return mBit->io.P20.getDigitalValue();
            //P21 GND
            //P22 GND
            default:
                return -1;
                break;
        }
    }

    int analogWrite(int pin, uint8_t value)
    {
        switch(pin)
        {
            case MICROBIT_PIN_P0:   return mBit->io.P0.setAnalogValue(value);
            case MICROBIT_PIN_P1:   return mBit->io.P1.setAnalogValue(value);
            case MICROBIT_PIN_P2:   return mBit->io.P2.setAnalogValue(value);
            case MICROBIT_PIN_P3:   return mBit->io.P3.setAnalogValue(value);
            case MICROBIT_PIN_P4:   return mBit->io.P4.setAnalogValue(value);
            case MICROBIT_PIN_P5:   return mBit->io.P5.setAnalogValue(value);
            case MICROBIT_PIN_P6:   return mBit->io.P6.setAnalogValue(value);
            case MICROBIT_PIN_P7:   return mBit->io.P7.setAnalogValue(value);
            case MICROBIT_PIN_P8:   return mBit->io.P8.setAnalogValue(value);
            case MICROBIT_PIN_P9:   return mBit->io.P9.setAnalogValue(value);
            case MICROBIT_PIN_P10:  return mBit->io.P10.setAnalogValue(value);
            case MICROBIT_PIN_P11:  return mBit->io.P11.setAnalogValue(value);
            //P12 Reserved: accessibility
            case MICROBIT_PIN_P13:  return mBit->io.P13.setAnalogValue(value);
            case MICROBIT_PIN_P14:  return mBit->io.P14.setAnalogValue(value);
            case MICROBIT_PIN_P15:  return mBit->io.P15.setAnalogValue(value);
            case MICROBIT_PIN_P16:  return mBit->io.P16.setAnalogValue(value);
            //P17 +3v3
            //P18 +3v3
            case MICROBIT_PIN_P19:  return mBit->io.P19.setAnalogValue(value);
            case MICROBIT_PIN_P20:  return mBit->io.P20.setAnalogValue(value);
            //P21 GND
            //P22 GND
            default:
                return -1;
                break;
        }
    }

    int digitalWrite(int pin, uint8_t value)
    {
        switch(pin)
        {
            case MICROBIT_PIN_P0:   return mBit->io.P0.setDigitalValue(value);
            case MICROBIT_PIN_P1:   return mBit->io.P1.setDigitalValue(value);
            case MICROBIT_PIN_P2:   return mBit->io.P2.setDigitalValue(value);
            case MICROBIT_PIN_P3:   return mBit->io.P3.setDigitalValue(value);
            case MICROBIT_PIN_P4:   return mBit->io.P4.setDigitalValue(value);
            case MICROBIT_PIN_P5:   return mBit->io.P5.setDigitalValue(value);
            case MICROBIT_PIN_P6:   return mBit->io.P6.setDigitalValue(value);
            case MICROBIT_PIN_P7:   return mBit->io.P7.setDigitalValue(value);
            case MICROBIT_PIN_P8:   return mBit->io.P8.setDigitalValue(value);
            case MICROBIT_PIN_P9:   return mBit->io.P9.setDigitalValue(value);
            case MICROBIT_PIN_P10:  return mBit->io.P10.setDigitalValue(value);
            case MICROBIT_PIN_P11:  return mBit->io.P11.setDigitalValue(value);
            //P12 Reserved: accessibility
            case MICROBIT_PIN_P13:  return mBit->io.P13.setDigitalValue(value);
            case MICROBIT_PIN_P14:  return mBit->io.P14.setDigitalValue(value);
            case MICROBIT_PIN_P15:  return mBit->io.P15.setDigitalValue(value);
            case MICROBIT_PIN_P16:  return mBit->io.P16.setDigitalValue(value);
            //P17 +3v3
            //P18 +3v3
            case MICROBIT_PIN_P19:  return mBit->io.P19.setDigitalValue(value);
            case MICROBIT_PIN_P20:  return mBit->io.P20.setDigitalValue(value);
            //P21 GND
            //P22 GND
            default:
                return -1;
                break;
        }
    }
 
    uint8_t uartRead(int rx_pin)
    {
        // microbit ASYNC serial reads give out 0x0C a load?
        uint8_t byte = 0x0C;
        while (byte == 0x0C)
            byte = mBit->serial.read(ASYNC);

        return byte;
    }

    uint8_t uartWrite(int tx_pin, uint8_t byte)
    {
		return mBit->serial.sendChar((char)byte);
    }
}
