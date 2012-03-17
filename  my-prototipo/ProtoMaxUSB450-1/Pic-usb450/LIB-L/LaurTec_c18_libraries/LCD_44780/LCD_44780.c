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

**********************************************************************************************/
									

#include "LCD_44780.h"


//************************************************************
//                  Epulse  Implementation
//************************************************************
void Epulse (void) {
	
	LCD_E = 1;
	delay_ms (1);
	LCD_E = 0;
	delay_ms (1);		
}


//************************************************************
//                  SendCommand  Implementation
//************************************************************
void SendCommand (unsigned char D3, unsigned char D2, unsigned char D1, unsigned char D0) {

	LCD_D0 = D0;
	LCD_D1 = D1;
	LCD_D2 = D2;
	LCD_D3 = D3;
	Epulse ();
}


//************************************************************
//                  Line2LCD  Implementation
//************************************************************
void Line2LCD(void) {
	
	SendCommand (1,1,0,0);	
	SendCommand (0,0,0,0); 		
}


//************************************************************
//                  HomeLCD  Implementation
//************************************************************
void HomeLCD(void) {
	
	SendCommand (0,0,0,0);	
	SendCommand (0,0,1,0); 		
}


//************************************************************
//                  ShiftLCD  Implementation
//************************************************************
void ShiftLCD(char shift, char number_of_shift) {
	
	char i;
	
	for (i=0; i < number_of_shift; i++) {	
		SendCommand (0,0,0,1);	
		SendCommand (1,shift,0,0); 	
	}	
}


//************************************************************
//                  ShiftCursorLCD  Implementation
//************************************************************
void ShiftCursorLCD(char shift, char number_of_shift){
	
	char i;
	
	for (i=0; i < number_of_shift; i++) {
		SendCommand (0,0,0,1);	
		SendCommand (0,shift,0,0);
	} 		
}

//************************************************************
//                  GotoLineLCD  Implementation
//************************************************************
void GotoLineLCD (char line) {

switch(line) {

	case 1: SendCommand(1,0,0,0);
			SendCommand(0,0,0,0);
			break;

	case 2: SendCommand(1,1,0,0);
			SendCommand(0,0,0,0);
			break;

	case 3: SendCommand(1,0,0,1);
			SendCommand(0,1,0,0);
			break;

	case 4: SendCommand(1,1,0,1);
			SendCommand(0,1,0,0);
	}
}

//************************************************************
//                  WriteCharLCD  Implementation
//************************************************************
void WriteCharLCD (unsigned char value) {	
	
	unsigned char D3,D2,D1,D0;
	
	LCD_RS = 1;
		
	// Splitting of the first nibble				
	D3 = (value & 0b10000000) >> 7;	
	D2 = (value & 0b01000000) >> 6;
	D1 = (value & 0b00100000) >> 5;
	D0 = (value & 0b00010000) >> 4;
		
	SendCommand (D3,D2,D1,D0);
		
	// Splitting of the second nibble
	D3 = (value & 0b00001000) >> 3;	
	D2 = (value & 0b00000100) >> 2;
	D1 = (value & 0b00000010) >> 1;
	D0 = (value & 0b00000001);
			
	SendCommand (D3,D2,D1,D0);
		
	LCD_RS = 0;
}

//************************************************************
//                  WriteStringLCD  Implementation
//************************************************************
void WriteStringLCD(const rom char *buffer) {
	
	 // Write data to LCD up to null
    while(*buffer) {
	    
	    // Write character to LCD
	    WriteCharLCD(*buffer);  
	    // Increment buffer
	    buffer++;              
   }
}

//************************************************************
//                  WriteVarLCD  Implementation
//************************************************************
void WriteVarLCD(unsigned char *buffer) {
	
	// Write data to LCD up to null
	while(*buffer){
		
		// Write character to LCD
		WriteCharLCD(*buffer); 
		// Increment buffer
		buffer++;               
	}
}


//************************************************************
//                  WriteIntLCD  Implementation
//************************************************************
void WriteIntLCD(int value, char number_of_digits){
	
	// The array size is 5 plus end of string \0
	unsigned char convertedInt [6];
	
	// Index used to shift to the right the digit
	char index; 
	
	// Integer is converted to string
	itoa (value, (char*) convertedInt);	
	
	if (number_of_digits >0 ) {
		
		convertedInt[number_of_digits] = '\0';
		
		// Shift the digit to the right removing the empty one
		while (!isdigit(convertedInt[number_of_digits-1])) {
			
			for (index = number_of_digits-1; index > 0; index--){
				convertedInt[index] = convertedInt[index-1];
				convertedInt[index-1] = ' ';
			}							
		}	
	}

	WriteVarLCD (convertedInt);
	
}	


//************************************************************
//                  ClearLCD  Implementation
//************************************************************
void ClearLCD (void){
	
	SendCommand (0,0,0,0);	
	SendCommand (0,0,0,1);		
}

//************************************************************
//                  CursorLCD  Implementation
//************************************************************
void CursorLCD(char active,char blinking) {	
	
	SendCommand (0,0,0,0);	
	SendCommand (1,1,active,blinking);								
}

//************************************************************
//                  CursorLCD  Implementation
//************************************************************
void BacklightLCD(char active) {

	LCD_LED = active;	
}

//************************************************************
//                  OpenLCD  Implementation
//************************************************************
void  OpenLCD(unsigned char quartz_frequency) {	
	
	setQuartz (quartz_frequency);
	
	LCD_RS = 0x00;
	LCD_E = 0x00;
	LCD_RW = 0x00;

	delay_ms (100);
	SendCommand (0,0,1,1);
	delay_ms (5);	
	SendCommand (0,0,1,1);
	delay_ms (5);		
	SendCommand (0,0,1,1);
	delay_ms (5);		
	SendCommand (0,0,1,0);
	SendCommand (0,0,1,0);
	SendCommand (1,0,0,0);
	SendCommand (0,0,0,0);
	SendCommand (1,1,1,0);
	CursorLCD (0,0);
	ClearLCD ();	
}

