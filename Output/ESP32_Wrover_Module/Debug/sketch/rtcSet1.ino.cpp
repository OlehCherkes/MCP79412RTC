#include <Arduino.h>
#line 1 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
// Arduino MCP79412RTC Library
// https://github.com/JChristensen/MCP79412RTC
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to set the RTC date and time to a hard-coded value.
// This is just a simple demonstration of setting the RTC time.
// Note that each time the sketch is run (or the microcontroller is
// reset), the RTC will be set to the same hard-coded time, so this
// example may be of limited usefulness as an actual clock.

#include <MCP79412RTC.h>    // https://github.com/JChristensen/MCP79412RTC
#include <TimeLib.h>        // https://github.com/PaulStoffregen/Time
#include <Wire.h>           // https://www.arduino.cc/en/Reference/Wire

tmElements_t tm;
#line 17 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
MCP79412RTC& t();
#line 23 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
void setup();
#line 33 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
void loop();
#line 40 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
void printTime(time_t time);
#line 64 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
void printI00(int val, char delim);
#line 17 "C:\\Users\\Oleh\\Downloads\\MCP79412RTC-master\\examples\\rtcSet1\\rtcSet1.ino"
MCP79412RTC &t()
{
	static MCP79412RTC rtc;
	return rtc;
}

void setup()
{
	delay(1000);
	Serial.begin(115200);

	setTime(12, 00, 00, 07, 07, 2023);  // set the system time to 23h31m30s on 13Feb2009                            
	t().set(now());						// set the RTC from the system time
	setTime(20, 00, 00, 10, 10, 2000);  // set the system time to 23h31m30s on 13Feb2009 
}

void loop()
{
	printTime(now());
	delay(1000);
}

// Print time (and date) given a time_t value
void printTime(time_t time)
{
	/*	RTC	 */
	t().read(tm);
	Serial.print("\033[31mRTC \033[0m");
	printI00(tm.Day, '.');
	printI00(tm.Month, '.');
	printI00(tm.Year  + 1970, ' ');
	printI00(tm.Hour, ':');
	printI00(tm.Minute, ':');
	printI00(tm.Second, ' ');
	Serial.println();
	
	/*	ESP	 */
	Serial.print("\033[31mESP \033[0m");
	printI00(day(time), '.');
	printI00(month(time), '.');
	printI00(year(time), ' ');
	printI00(hour(time), ':');
	printI00(minute(time), ':');
	printI00(second(time), ' ');
	Serial.println('\n');
}

void printI00(int val, char delim)
{
	if (val < 10) Serial.print('0');
	Serial.print(val);
	Serial.print(delim);
	return;
}

