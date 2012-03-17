/*******************************************************
********************************************************
 
Autore : Mauro Laurenti
Versione : 1.0
Data : 14/08/2007
 
CopyRight 2007 all rights are reserved


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

This library is supposed for being used for read and 
write the PIC microcontroller internal EEPROM 
 
*******************************************************
*******************************************************/


#include "intEEPROM.h"


//************************************************************
//                     write function implementation
//************************************************************

char writeIntEEPROM (unsigned char data, unsigned char address) {	
	
	// Flag used to store the GIE value
	unsigned char flagGIE = 0;	
	
	// Flag used to store the GIEH value
	unsigned char flagGIEH = 0;	
	
	// Flag used to store the GIEL value
	unsigned char flagGIEL = 0; 

	// Set the address that will be written
	EEADR = address; 	
	
	// Set the data that will be written
	EEDATA = data;		
	
	// EEPROM memory is pointed
	EECON1bits.EEPGD = 0; 
		
	// EEPROM access enable
	EECON1bits.CFGS = 0;	
	
	// Enable write 
	EECON1bits.WREN = 0x01;	

	// Check and store the Interrupt Status
	if (INTCONbits.GIE == 1) {  
			INTCONbits.GIE = 0; 
			flagGIE = 1;
	}
	
	if (INTCONbits.GIEH == 1) {  
			INTCONbits.GIEH = 0; 
			flagGIEH = 1;
	}
	
	if (INTCONbits.GIEL == 1) {  
			INTCONbits.GIEL = 0; 
			flagGIEL = 1;
	}
	
	// Start the writing enabling sequence		
	EECON2 = 0x55;	
	EECON2 = 0xAA;

	// Initiate writing process
	EECON1bits.WR = 0x01; 	

	// Wait the end of the writing process
	while (EECON1bits.WR);	
	
	
	// Restore the previous interrupt status
	if (flagGIE == 1) {
		INTCONbits.GIE = 1; 
	}	
		
	if (flagGIEH == 1) {
		INTCONbits.GIEH = 1; 
	}
	
	if (flagGIEL == 1) {
		INTCONbits.GIEL = 1; 
	
	}
	
	// Disable the writing process
	EECON1bits.WREN = 0x00;	
	
	
	// Check if the data has been properly written,
	// a simple read back is done
	if (readIntEEPROM (address) == data) {
		
		return (1);
		
	} else {
		
		return (0);
	}

}


//************************************************************
//             Read Function  Implementation
//************************************************************

unsigned char readIntEEPROM (unsigned char address) {
	
	unsigned char data = 0;

	// Set the memory address that will be read
	EEADR = address;	
	
	// EEPROM memory is pointed	
	EECON1bits.EEPGD = 0; 
	
	// EEPROM access enable
	EECON1bits.CFGS = 0;	
	
	// Initiate reading
	EECON1bits.RD = 0x01;	
	
	// Data is read from the register
	data = EEDATA;			
	
	return (data);		
		
}

