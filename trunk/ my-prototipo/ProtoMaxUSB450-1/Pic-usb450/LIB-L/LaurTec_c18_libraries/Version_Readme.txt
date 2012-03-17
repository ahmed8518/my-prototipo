*************************************************************

				   HISTORY

*************************************************************

-------------------------------------------------------------


					Version 2.2 26/03/2011

Implemente the new Library PCF8574. 
This library support both the PCF8574 and the PCF8574A versions.
It is simmply made of two functions to read and write the Device. 

-------------------------------------------------------------


					Version 2.1 23/04/2010

The LCD Library has been updated with a new function to support 20x4 LCD type.

changes:
	
	##################
	LCD_44780
	##################

	new function:

	void GotoLineLCD (char line);

	Description: This function locate the LCD cursor on  
                     the selected line. Tested on 20x4 16x2 LCD displays.

-------------------------------------------------------------

					Version 2.0 25/12/2009

The libraries have been totally reorganized to support the new book "C18 Step by Step"
All the libraries have been divided in header file and lib file and each library has its own project directory. 

changes:
	
	##################
	intEEPROM 
	##################

	It returns 0 if the writing has not properly written the address.
	internal data check has been added. if the writing is fine it returns 1.


	##################
	LCD_44780
	##################

	Function BacklightLCD has been added to control the LCD.

	These constants have been added:

	#define TURN_ON 1
	#define TURN_OFF 0

	#define BLINK_ON 1
	#define BLINK_OFF 0 

	
	##################
	eeprom
	##################

	The name has been changed to i2cEEPROM.
	The parameters addressH and anddressL has been call address.
	The low and high side of the address in then computed in the function
	New funciton have been introduced


	##################
	PCF8563
	##################

	Almost new...
	

	##################
	delay
	##################

	Finally I have written a library to handle delay considering the quartz!
	


-------------------------------------------------------------


					Version 1.2

CAN library has been added
Licence has been rewritten


-------------------------------------------------------------


					Version 1.1

The new library intEEPROM.h has been added. This library is used to read and write within the
intrenal microprocessor EEPROM.

-------------------------------------------------------------


					Version 1.0b

Preprocessor features have been added to each file, allowing multipoint library declaration 
The internal LCD delay() function has been renamed with delayLCD () to avoid name conflicts.


-------------------------------------------------------------


					Version 1.0a

The words Allarm in the library PCF8563.h have been changed with Alarm


-------------------------------------------------------------

						Version 1.0 
Initial version