//*****************************************************************
// one-wire.h
// Routines per protocollo 1-Wire
// By Bernardo Giovanni 
// http://www.settorezero.com
// versione 1.0
// data rilascio: 22/09/2010
//
// NOTA:
// richiede delle routine di delay precise
// in particolare è richiesta unicamente una funzione DelayUs(char)
//*****************************************************************


// modificare questi due defines per adattarli al pic utilizzato
#define	DQ  	RC5  	// Pin dati sul quale sono collegate le linee DQ dei dispositivi 1-wire
#define	TRIS_DQ	TRISC5 	// Registro TRIStato relativo alla porta usata per DQ

// comandi specifici per il bus 1-wire
#define OW_SEARCH_ROM	0xF0	// avvia la ricerca dei dispositivi sul bus 1-wire
#define	OW_READ_ROM		0x33	// da usare per leggere l'ID quando vi è un unico dispositivo sul bus
#define	OW_MATCH_ROM	0x55	// permette di comunicare con il dispositivo specifico
#define	OW_SKIP_ROM		0xCC	// permette di comunicare con tutti i dispositivi contemporaneamente	

// altro
#define	OW_PRESENCE		0x00	// livello zero se dispositivi 1wire presenti
#define OW_NO_PRESENCE	0x01	// livello 1 se nessun dispositivo 1wire presente

// prototipi funzioni

// funzioni di alto livello
unsigned char OWReset(void); // esegue il reset della linea
unsigned char OWReadByte(void); // legge un byte dalla linea
void OWWriteByte(char val); // scrive un byte sulla linea
void OWReadRom(unsigned char *ID); // memorizza nell'array ID il ROM code del SINGOLO dispositivo sulla linea

// funzioni di basso livello - da non usare nelle applicazioni
unsigned char _OWReadBit(void); // legge un singolo bit dalla linea
void _OWWriteBit(char bitval); // scrive un singolo bit sulla linea

// funzioni
#include "one-wire.c"