// --------------------------------------------------------------------------------------
//	Header file I2c.h per HI-TECH C														-
//																						-
//	Funzioni disponibili:																-
//																						-
//		I2cInitMaster (void)			Inizializzazione Master mode		   			-
//		I2cInitSlave (unsigned char)	Inizializzazione Slave mode   					-
//		I2cWait()						Attesa interrupt flag   						-
//		I2cWaitForIdle()				Attesa stato idle   							-
//		I2cStart()						Start operazione   								-
//		I2cRepStart()					Secondo start operazione   						-
//		I2cStop()						Stop operazione   								-
//		I2cReadMaster(unsigned char)	Lettura in Master mode   						-
//		I2cWriteMaster(unsigned char)	Scrittura per master   							-
//		I2cWriteSlave(unsigned char)	Scrittura in Slave mode   						-
//		I2cReadSlave()					Lettura in Slave mode   						-
// --------------------------------------------------------------------------------------



// Inizializzazione Master mode
extern void I2cInitMaster (void);

// Inizializzazione Slave mode
extern void I2cInitSlave (unsigned char address); 

// Attesa interrupt flag
extern void I2cWait(); 

// Attesa stato idle
extern void I2cWaitForIdle(); 

// Start operazione
extern void I2cStart(); 

// Secondo start operazione
extern void I2cRepStart();

// Stop operazione
extern void I2cStop(); 

// Lettura in Master mode
extern unsigned char I2cReadMaster(unsigned char ack);

// Scrittura in Master mode
extern unsigned char I2cWriteMaster(unsigned char I2cWriteData);

// Lettura in Slave mode
extern unsigned char I2cReadSlave();

// Scrittura in Slave mode
extern void I2cWriteSlave(unsigned char data);


