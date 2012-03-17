// --------------------------------------------------------------------------------------
// File:			Ascii.c																-
// Autore:			Nicola Sellitto		snico_one@yahoo.it								-
// Versione:		1.0																	-
// Data:			12 Aprile 2003														-
// Descrizione:		Insime di funzioni per la conversione di:  		                    -
//					. numero intero in stringa di caratteri in formato decimale o       -
//                    esadecimale;                                                      -
//					. carattere in stringa di caratteri del suo codice ascii in formato -
//                    decimale o esadecimale.                                           -
// --------------------------------------------------------------------------------------


#include "macro.h"
#include "ascii.h"


// -------------------------------------------------------------------------------------
// Converte un signed integer in striga ASCII decimale. Es. 1000 --> "1000"
// -------------------------------------------------------------------------------------
void int2dec(int value, char * string) {
int cifra;
int sub;                                        // Sottraendo
char i = 0;                                     // Indice posizione cifra in stringa
	
	if (value == 0) {
		string[0] = 0;
		string[1] = '\0';
		return;
	}

	if (value < 0) {
	    value = -value;                         // Forza a positivo
		string[0] = '-';
		i = 1;
	}
    
	sub = 10000;
	do {
		cifra = 0;
		while (value >= sub) {                  // Ciclo determinazione valore cifra
			value -= sub; 
			cifra ++;
		}
		if ((i > 0) || (cifra != 0)) {          // Verifica validità cifra
			string[i] = '0' + cifra;
			i ++;
		} 
		sub /= 10;                              // Aggiorna posizionamento decimale
	} while (sub > 0);
	string[i] = '\0';
}



// -------------------------------------------------------------------------------------
// Converte un unsigned integer in striga ASCII esadecimale. Es. 1000 --> "3E8"
// -------------------------------------------------------------------------------------
void int2hex(unsigned int value, char * string) {
BYTE *ptr;

    ptr = ADDR_LOWBYTE(value);                  // Indirizzo least significant byte
	char2hex((*(ptr+1)), string);               // Conversione high byte prima
    char2hex(*ptr, &string[2]);                	// Conversione low byte dopo
    string[4] = '\0';							// Imposta termine stringa
}



// -------------------------------------------------------------------------------------
// Converte un carattere in striga ASCII. Es. 'A' --> "65"
// -------------------------------------------------------------------------------------
void char2dec(char value, char * string) {

	int2dec((int)(value), string);
}



// -------------------------------------------------------------------------------------
// Converte un carattere in stringa ASCII esadecimale. Es. 'A' --> "41"
// Equivale a convertire un byte (a valore esadecimale) in stringa. Es. A --> "41"
// -------------------------------------------------------------------------------------
void char2hex(char value, char * string) {

	string[0] = value >> 4;
	if (string[0] < 10) string[0] += 48;        // Cifra numerica, partire da 48         
	else string[0] += 55;                       // Cifra letterale, partire da 55

	string[1] = value & 0x0F;
	if (string[1] < 10) string[1] += 48; 
	else string[1] += 55;

    string[2] = '\0';							// Imposta termine stringa
}
