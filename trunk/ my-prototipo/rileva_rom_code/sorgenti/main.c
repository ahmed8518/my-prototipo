//*************************************************
// Rileva rom code di un singolo dispositivo 1wire
// picmicro: PIC16F877A
// clock: 20MHz
// pulsante BT1 su RB4
// bus 1wire su pin RC5
//
// autore: Bernardo Giovanni
// http://www.settorezero.com
//*************************************************

#define PIC_CLK 20000000 // 20MHz, richiesto dalle routine di delay
#include <pic.h>

__CONFIG (HS & WDTDIS & PWRTEN & BORDIS & LVPDIS & DUNPROT & WRTEN & DEBUGDIS & UNPROTECT);

#include "delay.c"
#include "usart.c"
#include "one-wire.h"

unsigned char ID[8]; // verrà usato per memorizzare il rom code del dispositivo collegato al bus
unsigned char a; // counter generico
#define BT1 RB4 // pulsante 1

void main(void)
	{
	// impostazioni iniziali
	PORTC=0;
	TRISC=0b11000000; // RC6 e RC7 pin di ricetrasmissione seriale
	PORTB=0;
	TRISB=0b11110000; // RB7-RB4 pulsanti
	RBPU=0; // attivo le resistenze di pullup su porta B
	init_comms();	// Imposto l'usart a 9600/N/8/1
	
	printf("Test libreria 1Wire\n\r");
	printf("By Bernardo Giovanni\n\r");
	printf("http://www.settorezero.com\n\r");
	printf("------------------------------\n\r");
	printf("Collega un solo dispositivo 1Wire sul bus\n\r");
	printf("e premi BT1 per ottenerne il ROM code\n\r\n\r");
	
	while(1)
	{

	if (!BT1)
		{
		DelayMs(80);
		if(!BT1)
			{
			a=OWReset();
			if (a==OW_NO_PRESENCE)
				{
				printf("Nessun dispositivo 1Wire collegato\n\r\n\r");
				}
			else
				{
				OWReadRom(ID); // Eseguo la lettura della ROM, l'id sarà memorizzato nell'array ID
				printf("ROM code: ");
				for(a=0; a<8; a++)// ciclo per leggere gli 8 bytes restituiti dalla sonda
					{
					// stampo il byte ricevuto in formato esadecimale
					
					if (ID[a]<16) // per stampare lo zero davanti
						{
						printf("0x0%X",ID[a]);
						}
					else
						{
						printf("0x%X",ID[a]);
						}
					// se non sono all'ultimo byte, aggiungo una virgola
					if (a<7)
						{
						printf(",");
						}
					} // fine for
				printf ("\n\r");
				switch(ID[0])
					{
					case 0x28:
						printf("Sonda di temperatura DS18B20 (risoluzione programmabile)\n\r");
						break;
					case 0x10:
						printf("Sonda di temperatura DS18S20 (risoluzione fissa)\n\r");
						break;
					case 0x06:
						printf("iButton da 4K\n\r");
						break;
					case 0x08:
						printf("iButton da 1K\n\r");
						break;
					case 0x0A:
						printf("iButton da 16K\n\r");
						break;
					case 0x0C:
						printf("iButton da 64K\n\r");
						break;
					default:
						printf("Famiglia: ");
						if(ID[0]<16)
							{printf("0x0%X",ID[0]);}
						else
							{printf("0x%X",ID[0]);}
						printf(" vedi su: http://owfs.sourceforge.net/family.html\n\r");
					} // switch
				printf ("\n\r");
				} // fine dispositivo presente
			} // pulsante premuto (antibounce)
		} // pulsante premuto

	} // while
	} // main

	
