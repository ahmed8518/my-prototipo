/****************************************************************************

Author : Mauro Laurenti
Version : 1.0
Date : 4/9/2006
 
CopyRight 2006 all rights are reserved


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

These functions allow the user to read/write inside the eeprom 
that requires 2 address bytes such as the 24LC512.

*/

/****************************************************************************/

#ifndef FLAG_I2C_EEPROM
#define FLAG_I2C_EEPROM

#include <i2c.h>
#include <delay.h>


/***************************************************
*
* Description: This function writes a byte inside 
* 					the EEPROM.  
*
* Parameters:
*
* data : byte to write
* address : Address where the byte must be written
* control : Is the address of the eeprom with 
*           the bit R/'W set to 0. (i.g 0xA0)  
*
* Return:
*
* unsigned char: 1: The byte has been properly written
*       			 -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char writeI2C_EEPROM( unsigned char control, int address, unsigned char data );


/***************************************************
*
* Description: This function writes a byte inside 
*              the EEPROM but it read back the value
*              to make sure that has been properly
*              written. It's slower than the other
*              one due to the one.
*
* Parameters:
*
* data : byte to write
* address : Address where the byte must be written
* control : Is the address of the eeprom with 
*           the bit R/'W set to 0. (i.g 0xA0)  
*
* Return:
*
* unsigned char: 1: The byte has been properly written
*       			 -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*	             -4: Readback error
*
*
*
***************************************************/
signed char writeI2C_EEPROM_check( unsigned char control, int address, unsigned char data );




/***************************************************
*
* Description: This function writes a byte inside 
* 					the EEPROM.  
*
* Parameters:
*
* data : Address of the variable where the read 
*        data will be stored 
* address : Address where the byte must be read
* control : Is the address of the eeprom with 
*           the bit R/'W set to 0. (i.g 0xA0)  
*
* Return:
*
* unsigned char: 1: The byte has been properly read
*       			 -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char readI2C_EEPROM( unsigned char control, int address, unsigned char *data );

#endif