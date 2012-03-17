// --------------------------------------------------------------------------------------
//	Header file Ascii.h per HI-TECH C													-
//																						-
//	Funzioni disponibili:																-
//																						-
//		int2dec(int value)          Converte signed intero in striga ASCII              -
//		int2hex(int value)          Converte unsigned intero in striga ASCII esadecimale-
//		char2dec(char value)        Converte un carattere in striga ASCII               -
//		char2hex(char value)        Converte un carattere in striga ASCII esadecimale   -
// --------------------------------------------------------------------------------------


// Converte signed intero in striga ASCII. 
extern void int2dec(int value, char * string);

// Converte unsigned intero in striga ASCII esadecimale.
extern void int2hex(unsigned int value, char * string);

// Converte un carattere in striga ASCII. 
extern void char2dec(char value, char * string);

// Converte un carattere in striga ASCII esadecimale. 
extern void char2hex(char value, char * string);
