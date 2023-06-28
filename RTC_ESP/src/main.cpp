#include <Arduino.h>

// RTC
#include "RTClib.h"
#include <SPI.h>

// RTC
DateTime now;
RTC_DS3231 rtc;
String jam;
String tanggal;
char daysOfTheWeek[7][12] = {"Mn", "Sn", "Sl", "Rb", "Km", "Jm", "Sb"};
char buffer[25] = "";
char buffer2[25] = "";

void setup() 
{
 
Serial.begin(115200);
 
 if (! rtc.begin()) {
    Serial.println("RTC Tidak Ditemukan");
    Serial.flush();
    abort();
  }

  // rtc.adjust(DateTime(2023, 6, 25, 16, 14, 0));
 
if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
 
delay(3000);
}
 
void loop()
{
DateTime now = rtc.now();
 
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" | ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
delay(1000);
}