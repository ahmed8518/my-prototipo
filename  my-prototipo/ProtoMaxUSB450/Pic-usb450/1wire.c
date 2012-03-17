//****************************************************************************
//                            1wire002.c
//                          Version 2.1.3
//                         25 October 2000
//
//  Version 2 of the Dallas 1-wire Bus communications routines for Hi-Tech C
//  This Time Sat down and worked out my way of doing it!!
//
//
//  Author: Michael Pearce
//
//  Started: 29 June 1998
//
//****************************************************************************
//                      Version Information
//****************************************************************************
// Version 2.1.3 - 25 October 2000
// Changed the Reset Error Code return so you can identify what error occured
//
//****************************************************************************
// Version 2.1.2 - 7 August 2000
// Changed some of the timings to see if can improve the data integrity.
//
//****************************************************************************
// Version 2.1.1 - 19 July 2000
// Removed Fixed Port settings and added Error message to indicate if
// ports have not been set up.
// Have done this to allow use on other processors without to much hassel
//
//****************************************************************************
// Version 2.1.0 - 24 July 1998
//    - Added ReadRom and Match Rom Commands - need definition to activate
//
//****************************************************************************
// Version 2.0.0 - 29 June 1998
//  Start of Project test
//****************************************************************************

#include <p18cxxx.h>
//#include "P18F458.h"
//#include	"delay.h"
#include <usart.h>
//#include "ascii.h"
#include <delays.h>
//#define D_RiseSpace 5        // Rise Time + Minimum Space (3uS+1uS absolute min)
#define D_RiseSpace 2       // Rise Time + Minimum Space (3uS+1uS absolute min) 10
/*
#ifndef D_PIN
 #error D_PIN //Must Be Defined for 1-wire Bus I/O
#endif

#ifndef D_TRIS
 #error D_TRIS Must be defined for 1-wire Bus I/O
#endif
*/
//#define BITNUM(adr, bit)       ((unsigned)(&adr)*8+(bit))


//unsigned D_PIN    @ BITNUM(PORTB,5);


#define D_PIN   PORTBbits.RB5
#define D_TRIS  DDRBbits.RB5



unsigned  char D_Presence;
unsigned  char D_ShortCircuit;
unsigned char  D_Error;
char D_Data;


//****************************************************************************
//D_Reset  -- Resets the 1-wire bus and checks for presence & short cct
//****************************************************************************
void D_Reset(void)
{
 char count=47;
 //-- Reset the status bits
 D_Error=0;

 //-- Ensure Correct port pin settings
 D_TRIS=1;
 D_PIN=0;

 //-- Start the reset Pulse
D_TRIS=0;          //-- Pull Line Low to start reset pulse
// delay 480us
//Delay100TCYx(5); // 4MHZ
Delay100TCYx(58); // 20MHZ
D_TRIS=1;          //-- Release the line
Delay100TCYx(20);       //-- Delay to about centre of presence pulse 60
 
D_Presence=D_PIN;  //-- Get Presence status 1=None 0=something there

//Delay100TCYx(4);

D_ShortCircuit=D_PIN;  //-- Check for short circuit on bus pin.

 if(D_ShortCircuit==0)  //-- If short circuit then indicate an error
 {
  D_Error=1;
 }
else
{
  D_Error=7;

}

 if(D_Presence==1)      //-- If no device detected indicate an error
 {
  D_Error+=2;
 }
else
{
  D_Error=7;

}

 Delay10TCYx(D_RiseSpace);    //-- Rise time + Min Space

}
//******************END OF D_Reset


//****************************************************************************
// D_Write
//****************************************************************************
void D_Write(unsigned char Data)
{

 char count=8;
 for(;count>0;count--)
 {
  D_Data= Data & 0x01;    //-- Get LSB

  //-- Write the bit to the port
  D_PIN=0;
  D_TRIS=0;               //-- Lower the port
  //Delay10TCYx(1); 4MHZ            //-- Time slot start time
Delay10TCYx(4);      //20MHZ       //-- Time slot start time
  D_TRIS=D_Data;          //-- Output the data to the port
 //-- Finish Timeslot
  
 //Delay10TCYx(2); //4MHZ
  Delay10TCYx(50); //20MHZ

  D_TRIS=1;               //-- Ensure Release of Port Pin

  //-- Delay Between Bits
  Delay10TCYx(D_RiseSpace);             //-- Recovery time between Bits
 

  //-- Prep Next Bit
  Data=Data>>1;           //-- Shift next bit into place
 }
 Delay10TCYx(D_RiseSpace);    //-- Rise time + Min Space
 
}
//******************END OF D_Write

//****************************************************************************
// D_Read
//****************************************************************************
char D_Read(void)
{
 char count=8,data=0;
 for(;count>0;count--)
 {
  //-- Write the bit to the port
  D_PIN=0;
  D_TRIS=0;               //-- Lower the port
  //DelayUs(5);             //-- Time slot start time
 /*
  Delay1TCY();             //-- Time slot start tim  3
 Delay1TCY();
 Delay1TCY();
 Delay1TCY();
 Delay1TCY();
*/
    Delay10TCYx(1);        // DQ High. Release

  D_TRIS=1;               //-- Release port for reading
 //-- Get close to center of timeslot
/*

 Delay1TCY();
 Delay1TCY();
 Delay1TCY();
 Delay1TCY();
*/

  Delay10TCYx(4);
  D_Data=D_PIN;           //-- Read the data bit in
  //Delay10TCYx(25);            //-- Finish the timeslot 55
  //Delay10TCYx(4);
  //-- Put data into the byte
  data = data >> 1;        //-- Shift previous bits across
  if(D_Data==1)            //-- If data was high then add High bit to data
  {
   data +=0x80;
  }
  //-- Delay Between Bits
  //Delay10TCYx(D_RiseSpace);             //-- Recovery time between Bits
  Delay10TCYx(50); //20MHZ
 
 }
 Delay10TCYx(D_RiseSpace);    //-- Rise time + Min Space

 return(data);
}
//******************END OF D_Read


//**************************************************************************
//D_MatchRom - Matches the ROM Code to device
//**************************************************************************
//#ifdef _D_MATCHROM_
void D_MatchRom(const char address[])
{
 char count;
 D_Write(0x55);          //-- Match Rom
                         //-- Send the Address ROM Code.
 for(count=0;count<8;count++)
 {
  D_Write(address[count]);
 }
}
//#endif
//****************** END OF D_SendAddress

//**************************************************************************
//D_ReadRom - Reads the ROM Code from a device
//**************************************************************************
//#ifdef _D_READROM_
void D_ReadRom(char *address)
{
 char count;
 D_Write(0x33);          //-- Read Rom
                         //-- Read in the ROM code from the Device
 for(count=0;count<8;count++)
 {
  address[count]=D_Read();
 }
}
//#endif
//****************** END OF D_ReadRom

//**************************************************************************
//
//**************************************************************************

//****************** END OF

