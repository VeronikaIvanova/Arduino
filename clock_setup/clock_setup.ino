#include <DS1302RTC.h>
#include <TimeLib.h>

DS1302RTC rtc(8, 7, 6);

void setup() {
  tmElements_t tm;
  tm.Year = 2017;
  tm.Month = 4;
  tm.Day = 5;
  tm.Hour = 2;
  tm.Minute = 19;
  tm.Second = 0;
  time_t t = makeTime(tm);
  rtc.set(t);
}

void loop() {

}
