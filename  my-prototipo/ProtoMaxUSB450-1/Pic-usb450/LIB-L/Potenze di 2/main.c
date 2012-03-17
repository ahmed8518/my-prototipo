// Programma di esempio che visualizza in sequenza, sul display LCD della scheda Freedom, i valori 2^n  fino a 128
// Si è fatto uso di un array monodimensionale e dell'operatore di shift
// M.P. 04/10/2011
// Tratto da un lavoro di Mauro Laurenti 

#include <p18f4550.h>

#define LCD_DEFAULT
#include "LCD_44780.h"

// Sono stati inclusi nel progetto anche i file DELAY.LIB e LCD_44780.LIB

#pragma config FOSC = HS 	
#pragma config WDT = OFF 	
#pragma config LVP = OFF 	
#pragma config PBADEN = OFF 

//OSC = HS  	Impostato per lavorare ad alta frequenza 
//WDT = OFF		Disabilito il watchdog timer
//LVP = OFF 	Disabilito programmazione LVP
//PBADEN = OFF Disabilito gli ingressi analogici

// Variabile per il numero di shift a sinistra
#define SHIFT 8

 void main (void){

	// Variabili per il Conteggio e Delay
	unsigned char i;
	
	
	// Definizione dell'Array
	unsigned char mioArray [SHIFT];
	
	// Imposto PORTA tutti ingressi 
	LATA = 0x00; 
 	TRISA = 0xFF;

	// Imposto PORTB tutti ingressi
 	LATB = 0x00; 
 	TRISB = 0xFF;

	// Imposto PORTC tutti ingressi eccetto RC1 (impostato come uscita per pilotaggio backlight lcd 
 	LATC = 0x00;    	 
 	TRISC = 0xFD;
 	
	// Imposto PORTD tutte uscite
 	LATD = 0x00;  
 	TRISD = 0x00;

	// Imposto PORTE tutti ingressi
 	LATE = 0x00;
 	TRISE = 0xFF;
	
	
	// Inizializzo il display
	OpenLCD (20);
 	
	// Accendo la retroilluminazione
 	BacklightLCD (TURN_ON);
 	
	// Posiziono il cursore prima riga primo carattere a sinistra
	HomeLCD ();
	
	//Ritardo un secondo
	delay_ms (1000);
		
	// Invio stringa
	WriteStringLCD ("Calcolo  Potenze");
	
	// Posiziono il cursore seconda riga primo carattere a sinistra
	Line2LCD ();
	
	// Invio stringa
	WriteStringLCD ("by Marcello-2011");
	
	// Ritardo totale di 4 secondi
	delay_ms (1000);
	delay_ms (1000);
	delay_ms (1000);
	delay_ms (1000);
	
	// Pulisco il display
	ClearLCD();
	
	// Posiziono il cursore prima riga primo carattere a sinistra
	HomeLCD ();
	
	// Inizializzo il mio Array
	for (i = 0; i < SHIFT; i++) 
		mioArray[i] = 1<<i;
	
	for (i=0; i < SHIFT; i++) {
	
	// Cancello il dato precedente
 	ClearLCD();
	
	// Mostro l'incremento della potenza
	WriteStringLCD ("2^");
	WriteCharLCD (i+48); //conversione in ASCII
 	WriteStringLCD ("  =");
	
	// Effetto scorrimento
 	ShiftLCD (RIGHT,1);
	
	// Riporto il valore sul display
	WriteIntLCD (mioArray[i],4);
		
	// Ritardo un secondo
	delay_ms (1000);
		
	}	
		
	// Pulisco il display
	ClearLCD();
	
	// Posiziono il cursore prima riga primo carattere a sinistra
	HomeLCD ();
	
	// Invio stringa
	WriteStringLCD (" Premi -> RESET");
		
	// Posiziono il cursore seconda riga primo carattere a sinistra
	Line2LCD ();
	
	// Invio stringa
	WriteStringLCD ("per ricominciare");
		
	// Ciclo infinito
	while (1) {
	 	 	
 	} 	
}