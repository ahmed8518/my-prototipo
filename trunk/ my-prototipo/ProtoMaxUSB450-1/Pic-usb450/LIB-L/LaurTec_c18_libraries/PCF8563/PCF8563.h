
/***********************************************************************************************

Author : Mauro Laurenti
Version : 1.0
Date : 4/9/2006
 
CopyRight 2006 all rights are reserved


********************************************************
SOFTWARE LICENSE AGREEMENT
********************************************************

The usage of the supplied software imply the acceptance of the following license.

The software supplied herewith by Mauro Laurenti (the Author) 
is intended for use solely and exclusively on Microchip PIC Microcontroller (registered mark).  
The software is owned by the Author, and is protected under applicable copyright laws. 
All rights are reserved. 
Any use in violation of the foregoing restrictions may subject the 
user to criminal sanctions under applicable laws (Italian or International ones), as well as to 
civil liability for the breach of the terms and conditions of this license. 
Commercial use is forbidden without a written acknowledgment with the Author.
Personal or educational use is allowed if the application containing the following 
software doesn't aim to commercial use or monetary earning of any kind.    

THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES, 
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE AUTHOR SHALL NOT, 
IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR 
CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************
PURPOSES
********************************************************

This libary is supposed to be used to drive the PCF8563 or compatible 
devices

//**********************************************************************************************

*/

#include <i2c.h>

#ifndef FLAG_PCF8563
#define FLAG_PCF8563

//**************************************************
// you must change this addresse if
// you change the device.
//**************************************************

#define WRITE_ADD 0xA2	

//**************************************************
// Definition of Day constants (Italian, English)
//**************************************************

// Italian

#define	DO 0x00	
#define	LU 0x01
#define	MA 0x02
#define	ME 0x03
#define	GI 0x04
#define	VE 0x05
#define	SA 0x06

// English
#define	SU 0x00
#define	MO 0x01 
#define	TU 0x02 
#define	WE 0x03 
#define	TR 0x04 
#define	FR 0x05 
#define	SA 0x06 


//**************************************************
//        		Standard Constant
// enable value for the allarm bit (day,month,dayweek)
//**************************************************

#define Enable_ON  0b00000000	
#define Enable_OFF 0b10000000


//**************************************************
//           Address constants
//**************************************************

#define CONTROL_REG_2_ADDR		0x01
#define SECONDS_ADDR 			0x02
#define MINUTES_ADDR 			0x03
#define HOURS_ADDR 				0x04
#define DAYS_ADDR 				0x05
#define DAY_WEEK_ADDR 			0x06
#define MONTHS_ADDR	 			0x07
#define YEARS_ADDR	 			0x08
#define MINUTS_ALARM_ADDR	 	0x09
#define HOURS_ALARM_ADDR	 	0x0A
#define DAYS_ALARM_ADDR	 		0x0B
#define DAY_WEEK_ALARM_ADDR 	0x0C


//**************************************************
//           Limits constants
//**************************************************
#define MAX_MINUTES 	 0x60
#define MAX_HOURS 	 0x24
#define MAX_YEARS 	 0x99
#define MAX_MONTHS	 0x13
#define MAX_DAYS 		 0x32


/***************************************************
*
* Description: This function writes the seconds in 
*              the RTC.  
*
* Parameters:
*
* seconds: Seconds to write, as 2 digits BCD format.  
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
 
signed char set_seconds_RTCC (unsigned char seconds);


/***************************************************
*
* Description: This function reads the second from 
*              the RTC.  
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Second that are read back, in BCD format
*
***************************************************/
unsigned char get_seconds_RTCC (void);


/***************************************************
*
* Description: This function writes the minutes in 
*              the RTC.  
*
* Parameters:
*
* minutes: Minutes to write, as 2 digits BCD format. 
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_minutes_RTCC (unsigned char minutes);


/***************************************************
*
* Description: This function reads the minutes from 
*              the RTC.  
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Minutes that are read back, in BCD format
*
***************************************************/
unsigned char get_minutes_RTCC (void);


/***************************************************
*
* Description: This function writes the hours in 
*              the RTC. 
*
* Parameters:
*
* hours: Hours to write, as 2 digits BCD format.
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_hours_RTCC (unsigned char hours);


/***************************************************
*
* Description: This function reads the minutes from 
*              the RTC.  
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Hours that are read back, in BCD format
*
***************************************************/
unsigned char get_hours_RTCC (void);


/***************************************************
*
* Description: This function reads the time from 
*              the RTC. The format is HH:MM.ss 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Time that is read back, as ASCII string
*
***************************************************/
unsigned char* get_time_seconds_RTCC (void);


/***************************************************
*
* Description: This function reads the time from 
*              the RTC. The format is HH:MM 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Time that is read back, as ASCII string
*
***************************************************/
unsigned char* get_time_RTCC (void);


/***************************************************
*
* Description: This function writes the days in 
*              the RTC.  
*
* Parameters:
*
* days: Days to write, as 2 digits BCD format.
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_days_RTCC (unsigned char days);


/***************************************************
*
* Description: This function reads the time from 
*              the RTC. The format is HH:MM 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Days that are read back, in BCD format
*
***************************************************/
unsigned char get_days_RTCC (void);


/***************************************************
*
* Description: This function writes the WeekDay in 
*              the RTC.  
*
* Parameters:
*
* day_of_the_week: day of the week to write,
*                  as 2 digits BCD format. 
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_day_of_the_week_RTCC (unsigned char day_of_the_week);


/***************************************************
*
* Description: This function reads the Weekday from 
*              the RTC. 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Days that are read back, in BCD format
*
***************************************************/
signed char get_day_of_the_week_RTCC (void);


/***************************************************
*
* Description: This function writes the WeekDay in 
*              the RTC.  
*
* Parameters:
*
* months: Months to write, as 2 digits BCD format. 
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_months_RTCC (unsigned char months);


/***************************************************
*
* Description: This function reads the Month from 
*              the RTC. 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Manth that are read back, in BCD format
*
***************************************************/
unsigned char get_months_RTCC (void);


/***************************************************
*
* Description: This function writes the Year in 
*              the RTC.  
*
* Parameters:
*
* years: Years to write, as 2 digits BCD format.
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
***************************************************/
signed char set_years_RTCC (unsigned char years);


/***************************************************
*
* Description: This function reads the Years from 
*              the RTC. 
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Years that are read back, in BCD format
*
***************************************************/
unsigned char get_years_RTCC (void);



/***************************************************
*
* Description: This function reads the Date from 
*              the RTC. The Format DD/MM/YY
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Date in BCD format
*
***************************************************/
unsigned char* get_date_RTCC (void);


/***************************************************
*
* Description: This function writes the minutes for
*              the alarm, in the RTC.  
*             
*
* Parameters:
*
* minutes: Minutes to write, as 2 digits BCD format. 
* alarmEnable: Enable the alarm or not (for matching)
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
* Note:
* Use the constants Enable_ON and Enable_OFF
*
***************************************************/
signed char set_minutes_alarm_RTCC (unsigned char minutes, unsigned char alarm_enable);


/***************************************************
*
* Description: This function writes the hours for
*              the alarm, in the RTC.  
*             
*
* Parameters:
*
* hours: Hours to write, as 2 digits BCD format.
* alarmEnable: Enable the alarm or not (for matching)
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
* Note:
* Use the constants Enable_ON and Enable_OFF
*
***************************************************/
signed char set_hours_alarm_RTCC (unsigned char hours, unsigned char alarm_enable);


/***************************************************
*
* Description: This function writes the Days for
*              the alarm, in the RTC.  
*             
*
* Parameters:
*
* days: Days to write, as 2 digits BCD format.
* alarmEnable: Enable the alarm or not (for matching)
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
* Note:
* Use the constants Enable_ON and Enable_OFF
*
***************************************************/
signed char set_days_alarm_RTCC (unsigned char days, unsigned char alarm_enable);


/***************************************************
*
* Description: This function writes the WeekDays for
*              the alarm, in the RTC.  
*             
*
* Parameters:
*
* day_of_the_week: Day of the week to write,
*                  as 2 digits BCD format. 
* alarmEnable: Enable the alarm or not (for matching)
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
* Note:
* Use the constants Enable_ON and Enable_OFF
*
***************************************************/
signed char set_day_of_the_week_alarm_RTCC (unsigned char day_of_the_week, unsigned char alarm_enable);


/***************************************************
*
* Description: This function enable interrupt pin
*                        
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char enable_alarm_interrupt_RTCC (void);


/***************************************************
*
* Description: This function disable interrupt pin
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char disable_alarm_interrupt_RTCC (void);



/***************************************************
*
* Description: This function check if the Alarm id ON
*              
*
* Parameters:
*
* void
* 
* Return: 
*
* unsigned char: Alarm status 1: ON  0:OFF
*
* 
* Note:
* If the alarm is on, AF flag is automatically cleaned
***************************************************/
unsigned char is_alarm_ON_RTCC (void);


/***************************************************
*
* Description: This function increments the minutes
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char increment_minutes_RTCC (void);


/***************************************************
*
* Description: This function increments the hours
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char increment_hours_RTCC (void);


/***************************************************
*
* Description: This function increments the years
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char increment_years_RTCC (void);


/***************************************************
*
* Description: This function increments the month
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char increment_months_RTCC (void);


/***************************************************
*
* Description: This function increments the days
*                       
*
* Parameters:
*
* void
* 
* Return: 
*
* signed char:   1: The info has been properly written
*               -1: Bus Collision error
*               -2: Not Ack error condition
*               -3: Write collision
*
*
***************************************************/
signed char increment_days_RTCC (void);


#endif

