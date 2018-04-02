/*
    DOC
*/
//========
// MACROS
//========
//includes
#include "MicroBit.h"                       //MicroBit*
#include "microimg/MicroIMG.h"              //MicroIMG*
#include "rn2483/rn2483.h"                  //RN2483_*
#include "grove-drivers/GroveDrivers.h"     //Grove*
//defines
// io
#define USBBAUD    115200
#define RN2483BAUD 57600
#define RN2483TX    MICROBIT_PIN_P12
#define RN2483RX    MICROBIT_PIN_P8
// lora
#define MAX_JOIN_ATTEMPTS   1

//=========
// GLOBALS
//=========
//microbit
MicroBit uBit;
MicroBitPin RN2483_PIN_RESET(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_DIGITAL);
//grove
GroveButton button(MICROBIT_PIN_P1);
//general
int ret = -1;
char buff_rx[RN2483_MAX_BUFF] = {'\0'};
char buff_tx[RN2483_MAX_BUFF] = {'\0'};

//============
// PROTOTYPES
//============
void configure_serial(PinName TX, PinName RX, int baud);
bool init_rn2483();
bool join_rn2483();

//======
// MAIN
//======
int main()
{
//init
    uBit.display.scroll("init", 75);
    //mbit
    uBit.init();
    //grove
    GroveCommon::mBit = &uBit;
    //rn2483
    configure_serial(RN2483TX, RN2483RX, RN2483BAUD);
    if (init_rn2483() == false)
        goto ERROR;
//----
//main
    //join
    uBit.display.scroll("join", 75);
    if (join_rn2483() == false)
        goto ERROR;

    //loop
    while (1)
    {   
        //if button pressed
        if ((bool)button.read() == true)
        {
            //get temperature
            sprintf(buff_tx, "%i", uBit.thermometer.getTemperature());
            
            //tx hello
            uBit.display.scroll("tx", 75);
            ret = RN2483_tx(&uBit.serial, buff_tx, true, buff_rx);
            
            if (ret != RN2483_SUCCESS && ret != RN2483_NODOWN)
                goto ERROR;

            uBit.display.print(MicroIMG::img_tick);
            uBit.sleep(750);
            uBit.display.clear();

            //print any downlink
            if (ret == RN2483_SUCCESS)
                uBit.display.scroll(buff_rx);
           
            //cleanup
            memset(buff_tx, '\0', strlen(buff_tx));
            memset(buff_rx, '\0', strlen(buff_rx));
            uBit.sleep(10000);
        }

        uBit.display.scrollAsync(".", 75);
    }
//----
//exit
    uBit.display.scroll("BYE");
    release_fiber();
    return 0;
ERROR:
    uBit.display.scroll("ERR");
    uBit.display.print(MicroIMG::img_cross);
    uBit.sleep(750);
    uBit.display.clear();
    release_fiber();
    return 0;
//----
}

//===========
// FUNCTIONS
//===========
void configure_serial(PinName TX, PinName RX, int baud)
{
    uBit.serial.redirect(TX, RX);
    uBit.sleep(1000);
    uBit.serial.baud(baud);
    uBit.sleep(1000);
}

bool init_rn2483()
{
    if (RN2483_reset(&uBit.serial, &RN2483_PIN_RESET) != RN2483_SUCCESS)
        return false;
    
    if (RN2483_initMAC(&uBit.serial) != RN2483_SUCCESS)
        return false;

    uBit.display.print(MicroIMG::img_tick);
    uBit.sleep(750);
    uBit.display.clear();

    return true;
}
bool join_rn2483()
{
    int attempts = 0;
    bool joined = false;

    while(!joined && attempts < MAX_JOIN_ATTEMPTS)
    {
        if (RN2483_join(&uBit.serial, RN2483_ABP) == RN2483_SUCCESS)
            joined = true;

        attempts++;
    }

    if (joined)
    {
        uBit.display.print(MicroIMG::img_tick);
        uBit.sleep(750);
        uBit.display.clear();
    }

    return joined;
}

