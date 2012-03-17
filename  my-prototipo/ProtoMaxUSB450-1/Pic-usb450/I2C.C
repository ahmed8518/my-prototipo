// --------------------------------------------------------------------------------------
// File:			Lcd.c																-
// Autore:			Lavoro originale a cura di:											-
//					Michael Alon - michael@elina-micro.co.il							-
// 					Littleman - little_man@libero.it									-
// 					Riadattamento curato da Nicola Sellitto	- snico_one@yahoo.it		-
// Versione:		1.0																	-
// Data:			21 Settembre 2003													-
// Descrizione:		Gestione di un device generico secondo il protocollo I2C, 			-
//                  sono supportate entrambe le modalità master/slave.                  -
// --------------------------------------------------------------------------------------


#include "P18F458.h"

// ---------------------------------------------------------------------------
// Inizializzazione Master mode
// ---------------------------------------------------------------------------
void I2cInitMaster() { 

	TRISC3 = 1; 				// Impostazione linee SCL/SDA come input
	TRISC4 = 1; 
	SSP1CON2bits.PEN=1; 				// Modalita' Master, Clock=Fosc/(4*(SSPADD+1))
	SSPCON2 = 0;
	SSPADD = 9; 				// Clock a 400 Khz con Fosc a 4 Mhz
	STAT_CKE = 0;  				// Sample mode conforme a standard I2C
	STAT_SMP = 0;  				// Slewrate on (per 100Khz devono stare off)
	SSPIF = 0;					// Reset flag serial port
	BCLIF = 0;					// Reset flag del bus collision
}



// ---------------------------------------------------------------------------
// Inizializzazione Slave mode con indirizzo a 7 bit
// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------
// Attende che sia conclusa l'operazione in corso
// ---------------------------------------------------------------------------
void I2cWait() { 

	while (!SSPIF){				// Attende l'impostazione del flag di interrupt
		continue;
	}
	SSPIF=0;
}



// ---------------------------------------------------------------------------
// Attende che il bus sia in IDLE
// ---------------------------------------------------------------------------
void I2cWaitForIdle() {
 	
 	while ((SSPCON2 & 0x1F) | STAT_RW) {
 		continue;				// Attende per l'idle e trasmissione non in corso
 	}
}



// ---------------------------------------------------------------------------
// Start della trasmissione
// ---------------------------------------------------------------------------
void I2cStart() {
 	
 	I2cWaitForIdle();
 	SSPIF = 0;
 	SEN = 1;					// Avvia lo start
 	I2cWait(); 				    // Attende che sia conclusa l'operazione
}



// ---------------------------------------------------------------------------
// Start ripetuto della trasmissione
// ---------------------------------------------------------------------------
void I2cRepStart() {
	
	I2cWaitForIdle();
 	SSPIF = 0;
 	RSEN = 1;
 	I2cWait();
}



// ---------------------------------------------------------------------------
// Stop della trasmissione
// ---------------------------------------------------------------------------
void I2cStop() {
 	
 	I2cWaitForIdle();			// Attende che il bus sia in idle
 	SSPIF = 0;
 	PEN = 1; 					// Avvia lo stop
 	ACKEN = 1;
 	I2cWait(); 					// Attende che sia conclusa l'operazione
}



// ---------------------------------------------------------------------------
// Scrittura in Slave mode
// ---------------------------------------------------------------------------
void I2cWriteSlave(unsigned char data) {

	CKP = 0;      				// Tiene bloccato il clock
	SSPBUF = data;				// Carica i dati nel buffer 
	SSPIF = 0;    				// Azzera il bit di interrupt	
	CKP = 1;	    			// Sblocca il clock
	I2cWait(); 					// Attende che la trasmissione sia terminata
}



// ---------------------------------------------------------------------------
// Lettura in Slave mode, restituisce il byte letto
// ---------------------------------------------------------------------------
unsigned char I2cReadSlave() { 
char temp;
	
	I2cWait();	    			// Attende che il buffer sia pieno e l'ACK inviato
	temp = SSPBUF;        		// Legge SSPBUF per azzerare il bit BF
	return temp; 
}



// ---------------------------------------------------------------------------
// Invia il byte input e restituisce true se lo slave ha inviato l'ACK
// ---------------------------------------------------------------------------
unsigned char I2cWriteMaster(unsigned char data) {

 	I2cWaitForIdle();			// Attende l'IDLE
 	SSPBUF = data;				// Carica il buffer con il dato
 	I2cWait();					// Attende la fine della trasmissione
 	return !ACKSTAT; 			// Restituisce 1 se lo slave ha inviato l'ACK
}



// ---------------------------------------------------------------------------
// Lettura in Master mode, restituisce il byte letto
// ---------------------------------------------------------------------------
unsigned char I2cReadMaster(unsigned char ack) {
unsigned char data;

 	I2cWaitForIdle();			// Attende l'IDLE
 	RCEN = 1;					// Si mette in ricezione
 	SSPIF = 0;					// Azzera l'interrupt bit
 	I2cWait();					// Attende la fine della trasmissione
 	data = SSPBUF; 				// Legge il buffer e azzera il bit BF
 	if (ack) {
  		ACKDT = 0; 				// Invia l'ACK
  	}
 	else {
  		ACKDT = 1; 				// Non invia l'ACK
  	}
  	ACKEN = 1;               	// Avvia la routine di ACK
 	I2cWait();					// Attende che l'ACK sia completo
 	return data;	  			// Restituisce il byte ricevuto
}
