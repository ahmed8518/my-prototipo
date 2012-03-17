/****************************************************************************

Author : Mauro Laurenti
Version : 1.0
Date : 19/03/2011
 
CopyRight 2006-2011 all rights are reserved



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
********************************************************/

#include "PCF8574.h"


//************************************************************
//         PCF8574_write_data function implementation
//************************************************************

signed char PCF8574_write_data(unsigned char control, unsigned char data ){
	
	
//*****************************
// Start Condition and control
// Byte are sent
//*****************************		

	// Check if the module is idle
	IdleI2C();    
	// Initiate START condition                  
	StartI2C();                     

	// Wait until start condition is over 
	while (SSPCON2bits.SEN);  
	
	// Check if Bus collition happened   
  	if (PIR2bits.BCLIF) {
	  // Return with Bus Collision error
     return (-1);                 
   }

	// Write control byte - R/W bit should be 0
	if (WriteI2C(control)){
		// Return with write Collision error		
      return (-3);             
     }
     
 
//*****************************
// Data Byte is sent
//*****************************   
 
	// Check if the module is idle
   IdleI2C(); 
       
   // Check if ACK condition has been received             
   if (!SSPCON2bits.ACKSTAT){
	    
		// Write data byte to the data port	   
      if (WriteI2C(data)) {
	      // Return with write Collision error 
         return (-3);       
        }
      } else {
      	// Return with Not Ack error condition
        	return (-2);            
      }
    
//*****************************
// Stop command is sent
//*****************************
  
	// Check if the module is idle
	IdleI2C();  
	
	// Check if ACK condition has been received                       
  	if (!SSPCON2bits.ACKSTAT) {
	
	// Send STOP condition  	
	StopI2C();
	 
	// Wait until stop condition is over                       
	while (SSPCON2bits.PEN);      
  
  } else {
  		// Return with Not Ack error condition
  		return (-2);           
   }
  
  // Test for bus collision
  if (PIR2bits.BCLIF){
	 // Return with Bus Collision error 
    return (-1);                
  }
  
  // Return with no error
  return (1);                   
}



//************************************************************
//           PCF8574_read_data function implementation
//************************************************************

signed char PCF8574_read_data(unsigned char control, unsigned char *data){
	

//*****************************
// Start Condition and control
// Byte are sent
//*****************************

	// Check if the module is idle
	IdleI2C();    
	// Initiate START condition                  
	StartI2C(); 
	
	// Wait until start condition is over 
	while (SSPCON2bits.SEN);  
	
	// Check if Bus collition happened   
	if (PIR2bits.BCLIF) {
		// Return with Bus Collision error 
		return (-1);               
	}
	
	// Write Control Byte 
	if (WriteI2C(control + 1)){
		 // Return with write collision error
      return (-3);             
	} 


//*****************************
// Data is Read
//*****************************

		// Check if the module is idle
		IdleI2C();               
       
      // Check if ACK condition has been received  
		if (!SSPCON2bits.ACKSTAT){
			
			// Enable master for 1 byte reception
			SSPCON2bits.RCEN = 1;
			       
         	// Check that receive sequence is over
         	while (SSPCON2bits.RCEN);
         
         	// Send not ACK condition 
        	 NotAckI2C(); 
            
         	// Wait until ACK sequence is over           
         	while (SSPCON2bits.ACKEN );
         
         	// Send STOP condition
         	StopI2C(); 
              
         	// Wait until stop condition is over         
         	while (SSPCON2bits.PEN); 
         
         	// Check if Bus collition happened 
         	if (PIR2bits.BCLIF) {
	         	// return with Bus Collision error 
				return (-1);        
         }         

		} else {
		// Return with Not Ack error
		return (-2);            
     }   
	
	// Data is read from the buffer	
	*data = SSPBUF;
 
	// No error occured  
	return (1);

}


