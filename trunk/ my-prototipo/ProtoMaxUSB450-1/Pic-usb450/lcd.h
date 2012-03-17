// --------------------------------------------------------------------------------------
//	Header file Lcd.h per HI-TECH C														-
//																						-
//	Funzioni disponibili:																-
//																						-
//		LcdInit(char, char, char) 	Inizializza LCD - chiamare prima di ogni cosa		-
//		LcdBusy(void) 				Attende la fine dell'ultima operazione   			-
//		LcdCommand(char)			Scrive un comando									-
//		LcdClear(void)				Invia comando Clear & Home							-
//		LcdWrite(char, char)		Scrive un byte unsigned nella DD RAM				-
//		LcdPutch(char)				Scrive un carattere nella posizione del cursore		-
//		LcdPuts(char *)				Scrive una stringa di caratteri						-
//		LcdRead(char)				Legge un byte unsigned dalla DD RAM			 	 	-
//		LcdGetch(char)				Legge il carattere nella posizione attuale cursore  -
//		LcdSetCurs(char, char) 	 	Imposta il cursore a riga, colonna					-
//		LcdGetCurs (char, char)		Ritorna la riga, colonna attuale del cursore		-
//		LcdPulse(void)				Invia un impulso di Enable 							-
//		int2ascii(int, char)	    Converte un intero in striga ASCII  				-
// --------------------------------------------------------------------------------------

#define LCD_CLR			0x01 // Clear Display
#define LCD_HOME		0x02 // Cursor to Home position

/************************************************************************/
#if (LCD_COLS==20)
	#define LCD_line1	0x80 // Line 1 position 1
	#define LCD_line2	0xC0 // Line 2 position 1
	#define LCD_line3	0x94 // Line 3 position 1 (20 char LCD)
	#define LCD_line4	0xD4 // Line 4 position 1 (20 char LCD)
#else
	#define LCD_line1	0x80 // Line 1 position 1
	#define LCD_line2	0xC0 // Line 2 position 1
	#define LCD_line3	0x90 // Line 3 position 1 (16 char LCD)
	#define LCD_line4	0xD0 // Line 4 position 1 (16 char LCD)
#endif
/************************************************************************/


// Prima di ogni cosa
#define byte signed char

extern void LCD_STROBE (void);
extern void LCD_NIBBLE_OUT (unsigned char c );
extern void LCD_WRITE (unsigned char c);
extern void LCD_CMD (char c);
extern void LCD_GOTO (char line,char pos);
extern void LCD_CLEAR (void);
extern void LCD_PUTCH (char c);
extern void LCD_PUTUN (unsigned int c);
extern void LCD_PUTSN (signed int c);
extern void LCD_PUTS (const char * s);
extern void LCD_INIT (void);

extern unsigned char DS2408LCD(unsigned char Data,unsigned char CodeDS2408[8]);


