// --------------------------------------------------------------------------------------
//	Header file Macro.h per HI-TECH C													-
// --------------------------------------------------------------------------------------


#ifndef __MACRO_H
#define __MACRO_H


// Valori logici
#define FALSE	                0
#define TRUE	                (!0)


// Direzione Port 
#define INPUT 					1		
#define OUTPUT 					0


// Stati hardware
#define LOW_STATE               0
#define HIGH_STATE              (!0)


// Tipi dato ram
typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;


// Byte più significativo di un WORD - unsigned int
#define HIGH_BYTE(x)			(unsigned char)(x>>8)

// Byte meno significativo di un WORD - unsigned int
#define LOW_BYTE(x)				(unsigned char)(x & 0xFF)


// Indirizzo byte memo significativo
#define ADDR_LOWBYTE(x)		    ((unsigned char *)&x)
    
  
// Accesso a singolo bit di Port
#define	PORTBIT(adr, bit)	    ((unsigned)(&adr)*8+(bit))


// Imposta singlo bit
#define BIT_SET(var, bitn)		((var) |= 1 << (bitn))
#define BIT_CLEAR(var, bitn)	((var) &= ~(1 << (bitn)))


// Imposta multipli bit secondo mask
#define BITS_ON(var, mask)		var |= mask
#define BITS_OFF(var, mask)		var &= ~0 ^ mask

// Converte microsecondi in tmr1 clock ticks
//#define US_2_TICKS(x)			(x*(PIC_CLK/4)/(TMR1_PRESCALE))		


// Converte tmr1 clock ticks in microsecondi
//#define TICKS_2_US(x)			((x*4/PIC_CLK)*(TMR1_PRESCALE))		


#endif
