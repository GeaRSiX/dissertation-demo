/*!
	@file	rn2483.c
	@author	Alexander Collins (alexander-collins@outlook.cm)
	@date	September 2017 - April 2018
	@brief	A library for embedded platforms that allows for interaction with a Microchip RN2483.

	@see rn2483.h
*/
//========
// MACROS
//========
//includes
#include "rn2483.h"

//===========
// FUNCTIONS
//===========
//PRIVATE
//! read a single byte from via UART from the RN2483
static uint8_t read(MicroBitSerial *serial)
{
    return serial->read(ASYNC);
}
//! write a string of bytes via UART to the RN2483
static void write(MicroBitSerial *serial, const char *string)
{
    serial->printf(string);
}
// Converts buff into a string representation of it hexadecimal representation
static void get_hex_string(uint8_t *buff, int buff_len, char *ret)
{
    int j;  //index of buff
    int i;  //index of string
    uint8_t nibble;
    const char hex_map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (i = 0, j = 0; i < buff_len*2; i++)
    {
        nibble = 20;    // out of bounds of hex_map

        if (i % 2 == 0)
            nibble = (buff[j] >> 4) & 0x0F;
        else
        {
            nibble = buff[j] & 0x0F;
            j++;
        }

        ret[i] = hex_map[nibble];
    }

    ret[i] = '\0';
    return;
}
// Converts string a string representation of hex characters to ascii
static void get_text_string(const char *hex, int hex_len, char *ret)
{
    char byte[3];

    for (int i = 0; i < hex_len; i+=2)
    {
        byte[0] = hex[i];
        byte[1] = hex[i+1];
        byte[2] = '\0';

        ret[i/2] = (char)strtol(byte, NULL, 16);
    }

    return;
}
// Reads from the RX buffer into response until '\n' or EOB
static int RN2483_response(MicroBitSerial *serial, uint8_t *buffer)
{
    int i;

    for (i = 0; i < RN2483_MAX_BUFF; i++)
    {
        buffer[i] = read(serial);

        if (buffer[i] == 0x0C)  //mbit gives out 0x0C a bunch?
            i--;
        else if (buffer[i] == '\n' || buffer[i] == '\0')
            break;
    }

    if (i <= 0)
        return RN2483_ERR_PANIC;
    else
        return i;
}

//PUBLIC
//system
// Resets the RN2483 by toggling the RESET pin
int RN2483_reset(MicroBitSerial *serial, MicroBitPin *RESET)
{
    RESET->setDigitalValue(1);
    RESET->setDigitalValue(0);
    RESET->setDigitalValue(1);

    uint8_t ver[RN2483_MAX_BUFF] = {'\0'};
    int ret = RN2483_response(serial, ver);   //firmware version should be in buff (RN2483...)

    if (ret != RN2483_ERR_PANIC)
        ret = RN2483_SUCCESS;

    return ret;
}

// Attempts to trigger the auto-baud detection sequence.
int RN2483_autobaud(MicroBitSerial *serial, int baudrate)
{
    int ret;
    char buff[RN2483_MAX_BUFF] = {'\0'};

    serial->send_break();
    serial->baud(baudrate);
    serial->send(0x55);

    ret = RN2483_firmware(serial, buff);
    
    return ret;
}

// Sends a command to the RN2483 and sets the resposne in buffer
int RN2483_command(MicroBitSerial *serial, const char *command, char *response)
{
	//check command ends with \r\n (easy to forget)
	int end = strlen(command);
	if (command[end-2] != '\r' || command[end-1] != '\n')
		return RN2483_ERR_PARAM;
	
	//send command
    write(serial, command);

	//recv response
    int ret = RN2483_response(serial, (uint8_t *)response);
	if (ret != RN2483_ERR_PANIC)
        return RN2483_SUCCESS;

    return ret;
}

// Retrieves the firmware version of the RN2483 module and stores it in buff.
int RN2483_firmware(MicroBitSerial *serial, char *buff)
{
	return RN2483_command(serial, "sys get ver\r\n", buff);
}

//LoRa
// Initialises all the RN2483 MAC settings required to run LoRa commands (join, tx, etc).
int RN2483_initMAC(MicroBitSerial *serial)
{
    int i = -1;
	int ret = RN2483_ERR_PANIC;
    char response[RN2483_MAX_BUFF] = {'\0'};

	do {
		i++;
        memset(response, '\0', RN2483_MAX_BUFF);
		switch(i)
		{
            case 0:	//reset MAC
                #ifdef LoRaWAN_Frequency
                    ret = RN2483_command(serial, "mac reset " LoRaWAN_Frequency "\r\n", response);
                #endif
                break;
            case 1:	//set DevAddr
                #ifdef LoRaWAN_DevAddr
                    ret = RN2483_command(serial, "mac set devaddr " LoRaWAN_DevAddr "\r\n", response);
                #endif
                break;
            case 2:	//set DevEui
                #ifdef LoRaWAN_DevEUI
                    ret = RN2483_command(serial, "mac set deveui " LoRaWAN_DevEUI "\r\n", response);
                #endif
                break;
            case 3:	//set AppEui
                #ifdef LoRaWAN_AppEUI
                    ret = RN2483_command(serial, "mac set appeui " LoRaWAN_AppEUI "\r\n", response);
                #endif
                break;
            case 4:	//set AppKey
                #ifdef LoRaWAN_AppKey
                    ret = RN2483_command(serial, "mac set appkey " LoRaWAN_AppKey "\r\n", response);
                #endif
                break;
            case 5:	//set DataRate
                #ifdef LoRaWAN_DataRate
                    ret = RN2483_command(serial, "mac set dr " LoRaWAN_DataRate "\r\n", response);
                #endif
                break;
             case 6: //set NwkSKey
                #ifdef LoRaWAN_NwkSKey
                    ret = RN2483_command(serial, "mac set nwkskey " LoRaWAN_NwkSKey "\r\n", response);
                #endif
                break;
            case 7: //set AppSkey
                #ifdef LoRaWAN_AppSKey
                    ret = RN2483_command(serial, "mac set appskey " LoRaWAN_AppSKey "\r\n", response);
                #endif
                break;
            case 8: //set ADR
                #ifdef LoRaWAN_ADR
                    ret = RN2483_command(serial, "mac set adr " LoRaWAN_ADR "\r\n", response);
                #endif
                break;
            case 9: //save
                ret = RN2483_command(serial, "mac save\r\n", response);
                break;
		}
    } while (i < 10 && ret == RN2483_SUCCESS);

	return ret;
}

// Attempts to join a LoRa network using the specified mode.
int RN2483_join(MicroBitSerial *serial, int mode)
{
	int ret = -1;
    char response[RN2483_MAX_BUFF] = {'\0'};

    // send command & recv initial response
	if (mode == RN2483_OTAA)
		ret = RN2483_command(serial, "mac join otaa\r\n", response);
	else if (mode == RN2483_ABP)
		ret = RN2483_command(serial, "mac join abp\r\n", response);
	else
		ret = RN2483_ERR_PARAM;

    if (ret == RN2483_SUCCESS)
    {
        // if initial response success, wait for network response
        if (strcmp(response, "ok\r\n") == 0)
        {
            RN2483_response(serial, (uint8_t *)response);

            if (strcmp(response, "accepted\r\n") == 0)
                ret = RN2483_SUCCESS;
            else if (strcmp(response, "denied\r\n") == 0)
                ret = RN2483_DENIED;
            else
                ret = RN2483_ERR_PANIC;
        }
        // else return err code
        else if (strcmp(response, "keys_not_init\r\n") == 0)
            ret = RN2483_ERR_KIDS;
        else if (strcmp(response, "no_free_ch\r\n") == 0)
            ret = RN2483_ERR_BUSY;
        else if (strcmp(response, "silent\r\n") == 0 || strcmp(response, "busy\r\n") == 0 || strcmp(response, "mac_paused\r\n") == 0)
            ret = RN2483_ERR_STATE;
        else
            ret = RN2483_ERR_PANIC;
	}

    return ret;
}

// Sends a confirmed/unconfirmed frame with an application payload of buff.
int RN2483_tx(MicroBitSerial *serial, const char *buff, bool confirm, char *downlink)
{
    int ret = RN2483_ERR_PANIC;
    char response[RN2483_MAX_BUFF] = {'\0'};

    // figure out max payload length based on data rate
    int max_len = 0;
    #ifdef LoRaWAN_DataRate
	if (strcmp(LoRaWAN_DataRate, "0") == 0 || strcmp(LoRaWAN_DataRate, "1") == 0 || strcmp(LoRaWAN_DataRate, "2") == 0)
		max_len = 59;
	else if (strcmp(LoRaWAN_DataRate, "3") == 0)
		max_len = 123;
	else if (strcmp(LoRaWAN_DataRate, "4") == 0 || strcmp(LoRaWAN_DataRate, "5") == 0 || strcmp(LoRaWAN_DataRate, "6") == 0 || strcmp(LoRaWAN_DataRate, "7") == 0)
		max_len = 230;
	else
		max_len = 230;
    #endif

    // get payload
    char payload[strlen(buff)*2] = {'\0'};   //1byte = 2hex
    get_hex_string((uint8_t *)buff, strlen(buff), payload); // see documentation notes on this

    // send command
    char cmd[max_len] = {'\0'};
    if (confirm)
        sprintf(cmd, "mac tx cnf " LoRaWAN_Port " %s\r\n", payload);
    else
        sprintf(cmd, "mac tx uncnf " LoRaWAN_Port " %s\r\n", payload);
    ret = RN2483_command(serial, cmd, response);

    if (ret == RN2483_SUCCESS)
    {
        // if initial response success, wait for tx success
        if (strcmp(response, "ok\r\n") == 0)
        {
            memset(response, '\0', RN2483_MAX_BUFF);
            RN2483_response(serial, (uint8_t *)response);

            if (strcmp(response, "mac_tx_ok\r\n") == 0)
                ret = RN2483_NODOWN;
            else if (strcmp(response, "mac_err\r\n") == 0 || strcmp(response, "invalid_data_len\r\n") == 0)
                ret = RN2483_ERR_PANIC;
            else //assume downlink data (mac_rx <port> <data>)
            {
            
                //convert 'hex' to 'ascii' equivalent
                get_text_string(&response[9], strlen(response)-9, downlink);
                ret = RN2483_SUCCESS;
            }
        }
        // else return err code
        else if (strcmp(response, "invalid_param\r\n") == 0)
            ret = RN2483_ERR_PARAM;
        else if (strcmp(response, "no_free_ch\r\n") == 0)
            ret = RN2483_ERR_BUSY;
        else if (strcmp(response, "not_joined\r\n") == 0 || strcmp(response, "frame_counter_err_rejoin_needed\r\n") == 0)
            ret = RN2483_ERR_JOIN;
        else if (strcmp(response, "silent\r\n") == 0 || strcmp(response, "busy\r\n") == 0 || strcmp(response, "mac_paused\r\n") == 0)
            ret = RN2483_ERR_STATE;
        else
            ret = RN2483_ERR_PANIC;
    }

    return ret;
}

