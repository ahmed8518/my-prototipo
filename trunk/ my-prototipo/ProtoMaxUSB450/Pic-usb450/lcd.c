/************************************************************************/
/*                POOR's (universal) LCD interface V1.4b		*/
/*	   simple and complete LCD routines by Andrea Bonzini		*/
/************************************************************************/
/*									*/
/*	  Please report any bug or suggestion at zypkin@inwind.it	*/
/*									*/
/************************************************************************/
/*									*/
/*	This code will interface to a standard LCD controller		*/
/*	like the Hitachi HD44780. 					*/
/*	It has been tested and works correctly with the followings	*/
/*	LCD types:							*/
/*		1x8, 2x8, 1x16, 2x16, 2x20, 4x16, 4x20			*/
/*									*/
/*									*/
/*			    !!! WARNINGS !!!				*/
/*									*/
/*	This routines had been written to meet minimum hardware 	*/
/*	requirements...so you can use it even when your main		*/
/*	application has left a few I/O lines not on the same port :)	*/
/*	To let this you have the following restriction and benefits:	*/
/*									*/
/*	1) LCD works only in 4 bit mode.				*/
/*	2) You can use any Output pin of your MCU, you have only	*/
/*         to change pin assignments in the define section.		*/
/*	3) R/W select is not available so you must ground LCD's R/W pin	*/
/*									*/
/*									*/
/*			      !!! NOTE !!!				*/
/*									*/
/*		       These routines use delay.c			*/
/*									*/
/************************************************************************
									
		     USER'S ROUTINES DESCRIPTION:			
									
LCD_INIT() ----------->	initilalize the LCD. 				
			You must call it the first time you use the LCD	
			and before any other LCD routines.		
									
LCD_CLEAR() ---------->	Clears and Home LCD.			
									
LCD_CMD('char')	------>	Send a command to the LCD.			
			See LCD datasheet for the complete
			list of commands.
			
LCD_GOTO(line,pos) --->	Set the Cursor to a specified Line and position.
			Lines available are from 1 to 4. Pos available 
			starts from 1 to max available on your LCD.
			
LCD_PUTCH('char') ---->	Write a character on LCD (ASCII representation).

LCD_PUTS("string") --->	Write a string on LCD.

LCD_PUTUN(number)  --->	Write an Unsigned Number on LCD.
			It works both with INT (16bit) and CHAR (8bit).
			
LCD_PUTSN(number)  --->	Write a Signed Number on LCD (with Sign if <0).
			It works both with INT (16bit) and CHAR (8bit).


/************************************************************************/
/* 									*/
/* 			   !!! ATTENTION !!!				*/
/* 	Follow these simple instructions to configure your LCD module	*/
/*									*/
/*	1) check your hardware to determine which lines to use		*/
/*	   (you need 6 output lines).					*/
/*	2) set properly TRIS registers in your main code to configure	*/
/*	   the 6 lines as outputs.					*/
/*	3) In the next step use the defines to set the 6 lines as your	*/
/*	   hardware requires.						*/
/*	4) Set LCD Rows and Columns number using the define as shown	*/
/*	5) You are ready...your LCD will work!!! :)			*/
/* 									*/
/************************************************************************/


/************************************************************************/
/* Use this includes if these files are not included in your main code	*/
/************************************************************************/
#include <p18cxxx.h>
//#include <P18F4550.h>
#include	"delays.h"
#include "HardwareProfile.h"
#include	"lcd.h"


/************************************************************************/
/* Implementazione della scrittura su display mediante DS2408 1-Wire    */
/* Collegamento DS2408 ad un LCD 44780                                  */

/* DS2408	LCD		DESCRIZIONE											*/
/* 			pin 1	Massa												*/
/* 			pin 2	Vcc													*/
/* 			pin 3	Contrasto 10 k potenziometro						*/
/* P5 =		pin 4	Reset	10k pull up									*/
/*			pin 5   Massa ( Lettura/ scrittura )						*/
/* P4 = 	pin 6   Enable	10k pull up									*/
/*			pin 7	LCD_D0 Massa  										*/
/*			pin 8	LCD_D1 Massa  										*/
/*			pin 9	LCD_D2 Massa  										*/
/*			pin 10	LCD_D3 Massa  										*/
/* P0 = 	pin 11	LCD_D4	10k pull up									*/
/* P1 = 	pin 12	LCD_D5	10k pull up									*/
/* P2 = 	pin 13	LCD_D6	10k pull up									*/
/* P3 = 	pin 14	LCD_D7	10k pull up									*/






/************************************************************************/
/* Use the following defines to set the lines as your hardware requires	*/
/* ...you can use ANY output line of the MCU, even on several ports :)	*/
/************************************************************************/
/*
#define	LCD_RS		RB4		// Register select
#define	LCD_EN		RB5		// Enable
#define	LCD_D4		RB0		// LCD data 4
#define	LCD_D5		RB1		// LCD data 5
#define	LCD_D6		RB2		// LCD data 6
#define	LCD_D7		RB3		// LCD data 7
*/
#define	LCD_RS PORTDbits.RD4		// Register select
#define LCD_EN PORTDbits.RD5 // Enable 
#define LCD_D4 PORTDbits.RD0 // LCD data 4 
#define LCD_D5 PORTDbits.RD1 // LCD data 5 a
#define LCD_D6 PORTDbits.RD2 // LCD data 6 
#define LCD_D7 PORTDbits.RD3 // LCD data 7 

/************************************************************************/
/*	Now you have only to write LCD Rows and Columns number	 	*/
/************************************************************************/
/* 				!!! NOTE !!!				*/
/*	Some 1x16 LCD works as 2x8!!! ...be sure how to configure	*/
/* 	yours, see its datasheet!!!					*/
/************************************************************************/

#define LCD_ROWS	2	// valid numbers are: 1,2 
				// (set to 2 for 2 or more rows)
#define LCD_COLS	20	// valid numbers are: 8,16,20				





/************************************************************************/
/* 									*/
/* 		    YOUR LCD IS NOW READY TO WORK!!! :)			*/
/* 		     YOU CAN IGNORE THE FOLLOWING CODE			*/
/*				 ENJOY !!!				*/
/* 									*/
/************************************************************************/





/************************************************************************/
/*	Use the following defines to send fast command			*/
/*	 to the LCD							*/
/*	EX: LCD_CMD(LCD_line2); will set the cursor on line 2		*/
/*		 You can add fast command of your own!!!		*/
/************************************************************************/
/* 									*/
/* 				!!! NOTE !!!				*/
/*		DON'T CHANGE THE DEFINES WITHIN #if-#endif		*/
/* 									*/
/************************************************************************/


/****************************************/
/* 	 Enable LCD to read data	*/
/****************************************/
void LCD_STROBE (void)
{
	LCD_EN = 1;
	
	Delay10TCYx(12);
	//Delay10TCYx(1);
	LCD_EN=0;
	

}	

      
/****************************************/
/* 	Write a nibble to the LCD	*/
/****************************************/
void LCD_NIBBLE_OUT (unsigned char c )
{
if ( c & 0b10000000 ) 
{
    LCD_D7=1;

}
else 
{
	LCD_D7=0; 	

}
if ( c & 0b01000000 ) 
{
    LCD_D6=1;		
 	
}
else 
{
	LCD_D6=0;
	
}
if ( c & 0b00100000 ) 
{
	LCD_D5=1;
	
}
else 
{
	LCD_D5=0;
	
}
if ( c & 0b00010000 ) 
{ 
    LCD_D4=1;
	
}
else 
{
	LCD_D4=0;
	
}

LCD_STROBE();
}


/****************************************/
/* Write a byte to the LCD (4 bit mode) */
/****************************************/
void LCD_WRITE (unsigned char c)
{
LCD_NIBBLE_OUT(c);
c <<= 4;
LCD_NIBBLE_OUT(c);
//Delay10TCYx(1);
Delay10TCYx(12);
}


/****************************************/
/*       send a command to the LCD      */
/****************************************/
void LCD_CMD (char c)
{
	LCD_RS = 0;	// write command
	
	LCD_WRITE(c);
}


/****************************************/
/*  GoTO specified line and position    */
/****************************************/
void LCD_GOTO (char line,char pos)
{
switch(line)
	{
	case 1: LCD_CMD((LCD_line1-1)+pos);
		break;
	case 2: LCD_CMD((LCD_line2-1)+pos);
		break;
	case 3: LCD_CMD((LCD_line3-1)+pos);
		break;
	case 4: LCD_CMD((LCD_line4-1)+pos);
	}
}


/****************************************/
/*           Clear and Home LCD         */
/****************************************/
void LCD_CLEAR (void)
{
	LCD_CMD(LCD_CLR);
	//Delay1KTCYx(3);
        Delay1KTCYx(36);
}


/****************************************/
/*     Write one character to the LCD   */
/****************************************/
void LCD_PUTCH (char c)
{
	LCD_RS = 1;	// write characters
 	
	LCD_WRITE(c);
}


/****************************************/
/*        Write numbers to the LCD      */
/****************************************/
void LCD_PUTUN (unsigned int c)
{
	unsigned char t1,i,wrote;
	unsigned int k;

	wrote=0;
	for (i=4;i>=1;i--)
		{
		switch(i){
		case 4: k=10000;
			break;
		case 3: k=1000;
			break;
		case 2: k=100;
			break;
		case 1: k=10;
		}
		t1=c/k;
		if((wrote)||(t1!=0))
			{
			LCD_PUTCH(t1+'0');
			wrote=1;
			}
		c-=(t1*k);
		}
	LCD_PUTCH(c+'0');
}
/****************************************/
void LCD_PUTSN (signed int c)
{
	if(c<0)
		{ 
			LCD_PUTCH('-');
			c*=(-1);
		}
	LCD_PUTUN(c);
}


/****************************************/
/*       Write a string to the LCD      */
/****************************************/
//void LCD_PUTS ( char stringaLCD[20])
//{
//char ttt;
//LCD_RS = 1;	// write characters
//Delay10TCYx(5);

//	for ( ttt = 0 ; ttt <=18 ; ttt ++ )
//	{
//		LCD_PUTCH(stringaLCD[ttt]);
//	}

//}



void LCD_PUTS (const char * s)
{

	
	LCD_RS = 1;	// write characters
	
	while(*s)
		LCD_PUTCH(*s++);
}



/****************************************/
/*             Initialize LCD           */
/****************************************/	
void LCD_INIT (void)
{

// codice per il DS di test su breadboard 
/*
	CodeDS2408_LCD[0] = 0x29;
	CodeDS2408_LCD[1] = 0x80;
	CodeDS2408_LCD[2] = 0x4D;
	CodeDS2408_LCD[3] = 0x08;
	CodeDS2408_LCD[4] = 0;
	CodeDS2408_LCD[5] = 0;
	CodeDS2408_LCD[6] = 0;
	CodeDS2408_LCD[7] = 0xD0;
*/






	LCD_RS = 0;		// write control bytes

	Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
        Delay1KTCYx(100);		// power on delay
                Delay1KTCYx(100);		// power on delay

LCD_D4=1;
	LCD_D5=1;
	LCD_D6=0;
	LCD_D7=0;
	
	
	LCD_STROBE();
	Delay1KTCYx(60);
        //Delay1KTCYx(5);
	LCD_STROBE();
	//Delay10TCYx(10);
	Delay10TCYx(120);
        LCD_STROBE();
	//Delay1KTCYx(5);
        Delay1KTCYx(60);
	
	LCD_D4=0;		// set 4 bit mode
	
		Delay1KTCYx(60);
	//Delay1KTCYx(5);
	LCD_STROBE();
	//Delay10TCYx(4);
        	Delay1KTCYx(48);
	
	#if (LCD_ROWS==1)
	LCD_WRITE(0b00100000);	// 4 bit mode, 1 line, 5x8 font
	#else
	LCD_WRITE(0b00101000);	// 4 bit mode, 2 or more lines, 5x8 font
	#endif
	
	LCD_WRITE(0b00001000);	// display off
	LCD_WRITE(0b00001100);	// display on, curson off, blink off
	LCD_WRITE(0b00000110);	// shift entry mode, display not shifted
	
}

/************************************************************************/
#undef LCD_ROWS
#undef LCD_COLS
/************************************************************************/
/*             		       !!! END !!!				*/
/*	   	      THANKS FOR EXAMINING MY CODE ;)			*/
/************************************************************************/
/*									*/
/*	  Please report any bug or suggestion at zypkin@inwind.it	*/
/*									*/
/************************************************************************/
