/**********************************************************************************************

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


 This library contains all the functions that are handy for controlling 			
 an LCD with a 44780 Hitachi controller.							
 	
 To use these functions for your pourpose you must set up properly 
 the following LCD constants and the pins of the PORT/s that you will use.
 You can use any pin you want!

**********************************************************************************************/

#include <p18cxxx.h>
//#include <delay.h>
#include <ctype.h>


#ifndef FLAG_LCD_44780
#define FLAG_LCD_44780

// Prototipe for itoa from ctype lib 
char *itoa (int value, char *s);

//**************************************************
// LCD constants
// All the following pin must be set as output
//**************************************************

#ifndef LCD_DEFAULT

	#warning LCD_D0 has been not defined, LATDbits.LATD4 will be used
	#warning LCD_D1 has been not defined, LATDbits.LATD5 will be used
	#warning LCD_D2 has been not defined, LATDbits.LATD6 will be used
	#warning LCD_D3 has been not defined, LATDbits.LATD7 will be used
	#warning LCD_RS has been not defined, LATDbits.LATD2 will be used
	#warning LCD_E has been not defined, LATDbits.LATD3 will be used
	#warning LCD_RW has been not defined, LATDbits.LATD1 will be used
	#warning LCD_LED has been not defined, LATCbits.LATC1 will be used
	

	#define LCD_D0 LATDbits.LATD4
	#define LCD_D1 LATDbits.LATD5
	#define LCD_D2 LATDbits.LATD6	
	#define LCD_D3 LATDbits.LATD7	
	#define LCD_RS LATDbits.LATD2
	#define LCD_E LATDbits.LATD3	
	#define LCD_RW LATDbits.LATD1	
	#define LCD_LED LATCbits.LATC1	
	
	
#endif

//**************************************************
//               Constant Definitions

#define LEFT 0
#define RIGHT 1

#define TURN_ON 1
#define TURN_OFF 0

#define BLINK_ON 1
#define BLINK_OFF 0

//**************************************************



/***************************************************
*
* Description: This function generated the Enable
*              pulse  
*
* Parameters:
*
* void
* 
* Return: 
*
* void
*
***************************************************/
void Epulse (void);


/***************************************************
*
* Description: This function send a 4 bit command out 
* 					 
*
* Parameters:
*
* bit_0: bit 0 of the data bus (4 bit modality)
* bit_1: bit 1 of the data bus (4 bit modality)
* bit_2: bit 2 of the data bus (4 bit modality)
* bit_3: bit 3 of the data bus (4 bit modality)
* 
* Return:
*
* void
*
***************************************************/
void SendCommand (unsigned char bit_3, unsigned char bit_2, unsigned char bit_1, unsigned char bit_0);


/***************************************************
*
* Description: Locate the cursor to the beginning 
*              of Line 2.
*
* Parameters:
*
* void
* 
* Return:
*
* void
*
***************************************************/
void Line2LCD(void);



/***************************************************
*
* Description: Locate the cursor at home location. 
*              First line first character
*
* Parameters:
*
* void
* 
* Return:
*
* void
*
***************************************************/
void HomeLCD(void);


/***************************************************
*
* Description: This function shift the LCD screen on 
*              the left or rigt.
*
* Parameters:
*
* shift: 0 shift on the left
*        1 shift on the right
*
* number_of_shift: Specify the number of time the 
*                  shift is executed
* 
* Return:
*
* void
*
* Note:
* You can use the LEFT RIGHT constant
*
***************************************************/
void ShiftLCD(char shift, char number_of_shift);


/***************************************************
*
* Description: This function shift the LCD cursor on  
*              the left or rigt.
*
* shift: 0 shift on the left
*        1 shift on the right
*
* number_of_shift: Specify the number of time the 
*                  shift is executed
* Return:
*
* void
*
* Note:
* You can use the LEFT RIGHT constant
*
***************************************************/
void ShiftCursorLCD(char shift, char number_of_shift);


/***************************************************
*
* Description: This function locate the LCD cursor on  
*              the selected line. 
*              Tested on 20x4 16x2 LCD displays.
*
* line: number of the line (1,2,3,4)
*       
*
* Return:
*
* void
*
* Note:
* It might not work with all the LCD Diplay
*
***************************************************/
void GotoLineLCD (char line);

/***************************************************
*
* Description: This function writes a char to the 
*              LCD display.
*
*
* Parameters:
*
* value: character to be sent
* 
* Return:
*
* void
*
***************************************************/
void WriteCharLCD (unsigned char value);


/***************************************************
*
* Description: This function write a const string  
*              to the LCD display.
*
* Parameters:
*
* buffer : Is a const string like that "Hello" 
* 
* Return:
*
* void
*
***************************************************/
void WriteStringLCD(const rom char *buffer);



/***************************************************
*
* Description: This function write an array of char  
*              to the LCD display.
*
* Parameters:
*
* buffer : It is an array of char 
* 
* Return:
*
* void
*
***************************************************/
void WriteVarLCD(unsigned char *buffer);


/***************************************************
*
* Description: This function write an array of char  
*              to the LCD display.
*
* Parameters:
*
* value : It is integer that must be written to the 
*         LCD diplay.
*
* numeber_of_digits: It specifies the number of shown 
*                    digit [0-5].
*                    0: Left Justified
*                    1-5: Right Justified with n digit 
* 
* Return:
*
* void
*
* Note:
* If you set a number of digit less than required
* the digit will be lost starting from the less
* significant digit. Minus is like a digit.
*
***************************************************/
void WriteIntLCD(int value, char number_of_digits);


/***************************************************
*
* Description: This Function clean the LCD display
*             
*
* Parameters:
*
* void
* 
* Return:
*
* void
*
***************************************************/

void ClearLCD (void);



/***************************************************
*
* Description: This function controls the cursor
*              option (blinking, active)
*
* Parameters:
*
* active: activate the cursor, showing it
*         1 : cursor is ON
*         0 : cursor is OFF
*
* blinking: let the cursor blink
*           1 : Blinking is ON
*           0 : Blinking is OFF   
* 
* Return:
*
* void
*
* Note:
* You can use the constant TURN_ON, TURN_OFF
* BLINK_ON, BLINK_OFF
*
***************************************************/
void CursorLCD(char active,char blinking);


/***************************************************
*
* Description: This function controls the back ligth
*              LED 
*
* Parameters:
*
* active: activate the cursor, showing it
*         1 : LED is ON
*         0 : LED is OFF
* 
* Return:
*
* void
*
* Note:
* You can use the constant TURN_ON, TURN_OFF
*
***************************************************/
void BacklightLCD(char active);


/***************************************************
*
* Description: This funnction initializes the LCD  
*              to work in 4 bit modality.
*
* Parameters:
*
* quartz_frequency: Quartz freq. expressed in MHz
*                   used to run the PIC.
* 
* Return:
*
* void
*
* Note:
* You must properly set the microcontroller pins
* using the TRISx registers
*
***************************************************/
void  OpenLCD(unsigned char quartz_frequency);


#endif