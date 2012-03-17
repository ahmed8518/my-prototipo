//*****************************************************************
// one-wire.c
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

  
// resetta il bus 1-wire e rileva la presenza di dispositivi
unsigned char OWReset(void)
	{
    unsigned char ow_detect; // variabile usata per rilevare la presenza di dispositivi 1wire
    TRIS_DQ=1; // avvio con linea in alta impedenza
    DQ=0; // predispongo uscita bassa
    TRIS_DQ=0; // linea in uscita
    // linea a livello basso per 500uS
	// nota: la linea deve essere tenuta a livello basso
	// minimo 480uS
	DelayUs(250);
    DelayUs(250);
	TRIS_DQ=1;  // linea in alta impedenza
    // dopo che la linea è stata posta in alta impedenza
	// bisogna attendere dai 15 ai 60uS per una risposta
	DelayUs(100); // attendo 100uS per stare tranquillo
    ow_detect=DQ; // rilevo in che stato si trova la linea
	// l'impulso di presenza dura dai 60 ai 240uS
	// attendo 430uS dopo l'impulso di presenza
	DelayUs(230);
    DelayUs(200);
	// restituisco il valore ottenuto:
	// 0 = ci sono dispositivi (OW_PRESENCE)
	// 1 = non ci sono dispositivi (OW_NO_PRESENCE)
	return ow_detect;
    }
  
// leggo un byte dalla linea
unsigned char OWReadByte(void)
	{
    unsigned char i; // counter
    unsigned char value=0; // byte letto
    for(i=0; i<8; i++) 
		{
        if(_OWReadBit()) // leggo un bit
			{
			// se la linea è a livello alto, sommo il bit
			// nella posizione giusta tramite lo shift
			value |= (0x01<<i);
			}
		// ritardo di 120uS per il resto del timeslot
		DelayUs(120);
		}
    // restituisco il byte letto
	return value;
    }   

// scrivo un byte sulla linea
void OWWriteByte(char val) 
	{
    unsigned char i; // counter
    unsigned char temp; // valore temporaneo
    for( i=0; i<8; i++) // ciclo per gli 8 bit del valore
		{
		temp=val>>i;  // sposto il byte di i posizioni per recuperare il solo bit i-esimo
        temp &= 0x01; // ottengo solo il valore 0 o 1
        _OWWriteBit(temp); // "scrivo" il bit sulla linea
        }
    // ritardo di 100uS per il resto del timeslot
	DelayUs(100);
    } 

// legge il codice del SINGOLO dispositivo sul bus
// e lo memorizza nell'array ID passato come argomento
void OWReadRom(unsigned char *ID)
	{
	OWReset(); // resetto la linea one-wire
	OWWriteByte(OW_READ_ROM); // invio il comando readrom, che si può usare solo se sulla linea c'è una sola sonda
	for(unsigned char a=0; a<8; a++)// ciclo per leggere gli 8 bytes restituiti dal dispositivo
		{
		// eseguo la lettura del byte a-esimo:
		ID[a]=OWReadByte();
		}
	}

// funzioni di basso livello

// leggo un singolo bit dalla linea
unsigned char _OWReadBit(void)
	{
    DQ=0; // predispongo uscita bassa
    TRIS_DQ=0; // pin come uscita
    DelayUs(1);
    TRIS_DQ=1; // pin in alta impedenza
    // Devo aspettare minimo 10uS
	DelayUs(14);
    return DQ; // restituisco il valore sul quale si trova la linea
    }

// scrivo un singolo bit sulla linea	
void _OWWriteBit(char bitval)
	{
    DQ=0; // predispongo uscita bassa  
    TRIS_DQ=0; // pin come uscita per avviare il timeslot
    DelayUs(1);
    // se il bit vale 1, porto la linea in alta impedenza
	if(bitval==1) 
		{
        TRIS_DQ=1;
		}
    DelayUs(100); // aspetto 100uS per la fine del timeslot
    TRIS_DQ=1; // riporto la linea come ingresso
    }
