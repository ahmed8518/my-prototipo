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

#include "PCF8563.h"



//************************************************************
//             WriteSeconds function implementation
//************************************************************
signed char set_seconds_RTCC (unsigned char seconds) {	
	
	return (EEByteWrite (WRITE_ADD,SECONDS_ADDR,seconds));
	
}


//************************************************************
//             ReadSeconds function implementation
//************************************************************
unsigned char get_seconds_RTCC (void) {	
	
	unsigned char seconds;
	
	seconds = EERandomRead (WRITE_ADD,SECONDS_ADDR);  
	
	// I set to 0 the not significant bits
	seconds = seconds & 0b01111111;	
	return (seconds);
}



//************************************************************
//             WriteMinutes function implementation
//************************************************************

signed char set_minutes_RTCC (unsigned char minutes) {	
	
	return (EEByteWrite (WRITE_ADD,MINUTES_ADDR,minutes));	
	
}


//************************************************************
//             ReadMinutes function implementation
//************************************************************
unsigned char get_minutes_RTCC (void) {	
	
	unsigned char minutes;
	minutes = EERandomRead (WRITE_ADD,MINUTES_ADDR);  
	
	// I set to 0 the not significant bits
	minutes = minutes & 0b01111111;	
	return (minutes);
}


//************************************************************
//             WriteHours function implementation
//************************************************************
signed char set_hours_RTCC (unsigned char hours) {
		
	return (EEByteWrite (WRITE_ADD,HOURS_ADDR,hours));	
}


//************************************************************
//             ReadHours function implementation
//************************************************************
unsigned char get_hours_RTCC (void)

{	unsigned char hours;
	hours = EERandomRead (WRITE_ADD,HOURS_ADDR); 
	
	// I set to 0 the not significant bits 
	hours = hours & 0b00111111;	
	return (hours);
}


//************************************************************
//             ReadTimeSeconds function implementation
//************************************************************
unsigned char* get_time_seconds_RTCC (void) {	
	
	static unsigned char time[9];
	unsigned char value;

	value = get_hours_RTCC();	
	
	// with +48 I convert the number in ASCII number
	time[1] = (value & 0b00001111)+48; 
	time[0] = (value >> 4)+48;
	
	time[2] = ':';
	
	value = get_minutes_RTCC();	
	time[4] = (value & 0b00001111)+48;
	time[3] = (value >> 4)+48;
	
	time[5] = '.';

	value = get_seconds_RTCC();	
	time[7] = (value & 0b00001111)+48;
	time[6] = (value >> 4)+48;
	
	time[8] = '\0';
		
	return (time);
	
}


//************************************************************
//             ReadTime function implementation
//************************************************************
unsigned char* get_time_RTCC (void) {	
	
	static unsigned char time[6];
	unsigned char value;

	value = get_hours_RTCC();	
	
	// with +48 I convert the number in ASCII number
	time[1] = (value & 0b00001111)+48; 
	time[0] = (value >> 4)+48;
	
	time[2] = ':';
	
	value = get_minutes_RTCC();	
	time[4] = (value & 0b00001111)+48;
	time[3] = (value >> 4)+48;
	
	
	time[5] = '\0';
		
	return (time);
	
}


//************************************************************
//             WriteDays function implementation
//************************************************************
signed char set_days_RTCC (unsigned char days) {	
	
	return (EEByteWrite (WRITE_ADD,DAYS_ADDR,days));		
}


//************************************************************
//             ReadDays function implementation
//************************************************************
unsigned char get_days_RTCC (void) {	
	
	unsigned char days;
	days = EERandomRead (WRITE_ADD,DAYS_ADDR);  
	
	// I set to 0 the not significant bits
	days = days & 0b00111111;	
	return (days);
}


//************************************************************
//             WriteWeekDays function implementation
//************************************************************
signed char set_day_of_the_week_RTCC (unsigned char day_of_the_week) {	
	
	return (EEByteWrite (WRITE_ADD,DAY_WEEK_ADDR,day_of_the_week));
}


//************************************************************
//             ReadWeekDays function implementation
//************************************************************
unsigned char get_week_days_RTCC (void){	
	
	unsigned char day_of_the_week;
	day_of_the_week = EERandomRead (WRITE_ADD,DAY_WEEK_ADDR);  
	
	// I set to 0 the not significant bits
	day_of_the_week = day_of_the_week & 0b00000111;	
	return (day_of_the_week);
}


//************************************************************
//             WriteMonths function implementation
//************************************************************
signed char set_months_RTCC (unsigned char months) {	
	
	return (EEByteWrite (WRITE_ADD,MONTHS_ADDR,months));
	
}
																				

//************************************************************
//             ReadMonths function implementation
//************************************************************
unsigned char get_months_RTCC (void) {	
	
	unsigned char months;
	months = EERandomRead (WRITE_ADD,MONTHS_ADDR);  
	
	// I set to 0 the not significant bits
	months = months & 0b00011111;	
	return (months);
}


//************************************************************
//             WriteYears function implementation
//************************************************************
signed char set_years_RTCC (unsigned char years) {	
	
	return (EEByteWrite (WRITE_ADD,YEARS_ADDR,years));		
}


//************************************************************
//             ReadYears function implementation
//************************************************************
unsigned char get_years_RTCC (void) {	
	
	unsigned char years;
	years = EERandomRead (WRITE_ADD,YEARS_ADDR);  
	return (years);
}


//************************************************************
//             ReadDate function implementation
//************************************************************
unsigned char* get_date_RTCC (void) {	
	
	static unsigned char date[9];
	unsigned char value;

	value = get_days_RTCC();	
	
	// with +48 I convert the number in ASCII number
	date[1] = (value & 0b00001111)+48; 
	date[0] = (value >> 4)+48;
	
	date[2] = '/';
	
	value = get_months_RTCC();	
	date[4] = (value & 0b00001111)+48;
	date[3] = (value >> 4)+48;
	
	date[5] = '/';


	value = get_years_RTCC();	
	date[7] = (value & 0b00001111)+48;
	date[6] = (value >> 4)+48;
	
	date[8] = '\0';
		
	return (date);
	
}


//************************************************************
//             WriteMinutesAlarm function implementation
//************************************************************
signed char set_minutes_alarm_RTCC (unsigned char minutes, unsigned char alarm_enable) {	
	
	//I activate AE if required
	minutes = minutes + alarm_enable; 
	
	return (EEByteWrite (WRITE_ADD,MINUTS_ALARM_ADDR,minutes));	
	
}


//************************************************************
//             WriteHoursAlarm function implementation
//************************************************************
signed char set_hours_alarm_RTCC (unsigned char hours, unsigned char alarm_enable) {	
	
	//I activate AE if required
	hours = hours + alarm_enable; 
	return (EEByteWrite (WRITE_ADD,HOURS_ALARM_ADDR,hours));	
}


//************************************************************
//             WriteDaysAlarm function implementation
//************************************************************
signed char set_days_alarm_RTCC (unsigned char days, unsigned char alarm_enable) {	
	
	//I activate AE if required
	days = days + alarm_enable; 
	return (EEByteWrite (WRITE_ADD,DAYS_ALARM_ADDR,days));	
	
}


//************************************************************
//             WriteWeekDaysAlarm function implementation
//************************************************************
signed char set_day_of_the_week_alarm_RTCC (unsigned char day_of_the_week_alarm, unsigned char alarm_enable) {
		
	//I activate AE if required
	day_of_the_week_alarm = day_of_the_week_alarm + alarm_enable; 
	return (EEByteWrite (WRITE_ADD,DAY_WEEK_ALARM_ADDR,day_of_the_week_alarm));	
	
}


//************************************************************
//             EnableAlarmInt function implementation
//************************************************************
signed char enable_alarm_interrupt_RTCC (void) {	
	
	return (EEByteWrite (WRITE_ADD,CONTROL_REG_2_ADDR,0x02));	
	
}


//************************************************************
//             DisableAllInt function implementation
//************************************************************
signed char disable_alarm_interrupt_RTCC (void) {	
	
	return (EEByteWrite (WRITE_ADD,CONTROL_REG_2_ADDR,0x00));	
	
}


//************************************************************
//             IsAlarmON function implementation
//************************************************************
unsigned char is_alarm_ON_RTCC (void) {	
	
	unsigned char value;
	value = EERandomRead (WRITE_ADD,CONTROL_REG_2_ADDR); 
	
	// Just AF bit is controlled 
	if (value & 0x08) {
		
		value = value & 0xF7;	
		
		// I clean AF bit without canging the other bits
		EEByteWrite (WRITE_ADD,0x01,value);
		return (1);	
	
	} else {
		return (0);	
	}
		
}


//************************************************************
//         increment_minutes_RTCC function implementation
//************************************************************
signed char increment_minutes_RTCC (void) {
	
	unsigned char minutes;
	signed char error;
	
	// Read the current minutes
	minutes = get_minutes_RTCC ();
	
	// Increment the minutes
	minutes ++;
	
	// Check the minute limits

	if ((minutes&0x0F) > (unsigned char) 9 ) {		
		minutes &= 0xF0;
		minutes += 0x10;
	}
	
	if (minutes == (unsigned char) MAX_MINUTES) {
		
		minutes = 0;
	}
	
	// Update the minutes
	error = set_minutes_RTCC (minutes); 
	
	return (error);	
	
}


//************************************************************
//           increment_hours_RTCC function implementation
//************************************************************

signed char increment_hours_RTCC (void) {
	
	unsigned char hours;
	signed char error;
	
	// Read the current hours
	hours = get_hours_RTCC ();
	
	// Increment the hours
	hours ++;
	
	// Check the hour limits
	
	if ((hours&0x0F) > (unsigned char) 9 ) {		
		hours &= 0xF0;
		hours += 0x10;
	}
	
	if (hours == (unsigned char) MAX_HOURS) {
		
		hours = 0;
	}
	
	// Update the hours
	error = set_hours_RTCC (hours); 
	
	return (error);
	
}


//************************************************************
//           increment_years_RTCC function implementation
//************************************************************

signed char increment_years_RTCC (void) {
	
	unsigned char years;
	signed char error;
	
	// Read the current years
	years = get_years_RTCC ();
	
	// Increment the years
	years ++;
	
	// Check the year limits
	
	if ((years&0x0F) > (unsigned char) 9 ) {		
		years &= 0xF0;
		years += 0x10;
	}
	
	if (years == (unsigned char) MAX_YEARS) {
		
		years = 0;
	}
	
	// Update the years
	error = set_years_RTCC (years); 
	
	return (error);
	
}


//************************************************************
//           increment_months_RTCC function implementation
//************************************************************

signed char increment_months_RTCC (void) {
	
	unsigned char months;
	signed char error;
	
	// Read the current months
	months = get_months_RTCC ();
	
	// Increment the months
	months ++;
	
	// Check the month limits
	
	if ((months&0x0F) > (unsigned char) 9 ) {		
		months &= 0xF0;
		months += 0x10;
	}
	
	if (months == (unsigned char) MAX_MONTHS) {
		
		months = 1;
	}
	
	// Update the months
	error = set_months_RTCC (months); 
	
	return (error);
	
}

//************************************************************
//           increment_days_RTCC function implementation
//************************************************************

signed char increment_days_RTCC (void) {
	
	unsigned char days;
	signed char error;
	
	// Read the current days
	days = get_days_RTCC ();
	
	// Increment the days
	days ++;
	
	// Check the day limits
	
	if ((days&0x0F) > (unsigned char) 9 ) {		
		days &= 0xF0;
		days += 0x10;
	}
	
	if (days == (unsigned char) MAX_DAYS) {
		
		days = 1;
	}
	
	// Update the days
	error = set_days_RTCC (days); 
	
	return (error);
	
}

