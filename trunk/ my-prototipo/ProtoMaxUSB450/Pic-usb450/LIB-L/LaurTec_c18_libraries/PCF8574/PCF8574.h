/****************************************************************************

Author : Mauro Laurenti
Version : 1.0
Date : 19/03/2011
 
CopyRight 2006/2011 all rights are reserved


********************************************************
SOFTWARE LICENSE AGREEMENT
********************************************************

The usage of the supplied software imply the acceptance of the following license.

The software supplied herewith by Mauro Laurenti (the Author) 
is intended for use solely and exclusively on Microchip PIC Microcontroller (registered mark).  
The software is owned by the Author, and is protected under applicable copyright laws. 
All rights are reserved. 
Any use in violation of the foregoing restrictions may subject the 
user to criminal sanctions under applicable laws (Italian or International ones), as well as to 
civil liability for the breach of the terms and conditions of this license. 
Commercial use is forbidden without a written acknowledgment with the Author.
Personal or educational use is allowed if the application containing the following 
software doesn't aim to commercial use or monetary earning of any kind.    

THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES, 
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE AUTHOR SHALL NOT, 
IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR 
CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************
PURPOSES
********************************************************

These functions allow the user to read/write to the data
port of the I2C I/O exender PCF8574. 
Either PCF8574 or PCF8574A can be used. The user must use the 
proper address calling the functions. 

*/

/****************************************************************************/

#ifndef FLAG_PCF8574
#define FLAG_PCF8574

#include <i2c.h>

/***************************************************
*
* Description: This function writes to the data Port
* 			   of the I2C I/O expander. 
*
* Parameters:
*
* data : byte to write
* control : Is the address of the eeprom with 
*           the bit R/'W set to 0. (i.g 0x40)  
*
* Return:
*
* unsigned char: 1: The byte has been properly written
*       		 -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char PCF8574_write_data(unsigned char control, unsigned char data );


/***************************************************
*
* Description: This function read the data port 
* 			   of the I2C I/O expander. 
*
*
* Parameters:
*
* data : byte to write
* control : Is the address of the eeprom with 
*           the bit R/'W set to 0. (i.g 0x40)    
*
* Return:
*
* unsigned char: 1: The byte has been properly read
*       	    -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
*
***************************************************/
signed char PCF8574_read_data(unsigned char control, unsigned char *data);



#endif