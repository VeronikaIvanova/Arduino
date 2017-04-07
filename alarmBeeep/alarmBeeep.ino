#include <TimeLib.h>
#include <DS1302RTC.h>
#include <Thread.h>

int ledR = 13;
int ledY = 12;
int ledG = 11;
int ledW = 10;
int ledYR = 9;
int sound = 3;
int photoRes = 0;
int isSleeping=true;

int do1=261, re1=293, reS1=311, mi1=329, fa1=349, faS1=369, sol1=392, la1=440, laS1=466, si1=493;
int do2=523, re2=587, reS2=622, mi2=659, fa2=698, sol2=784, la2=880, si2=987;

const int imperialLength = 18;

int imperialScore[imperialLength] = {
  sol1, sol1, sol1, reS1, laS1, sol1, reS1, laS1, sol1,
  re2, re2, re2, reS1, laS1, faS1, reS1, laS1, sol1
};

int imperialDurations[imperialLength] = {
  700, 700, 700, 500, 200, 700, 500, 200, 1400,
  700, 700, 700, 500, 200, 700, 500, 200, 1400  
};

int imperialLights[imperialLength] = {
  ledY, ledY, ledY, ledR, ledG, ledY, ledR, ledG, ledY,
  ledW, ledW, ledW, ledYR, ledG, ledY, ledR, ledG, ledY     
};

const int silenceLength = 29;

int silenceScore[silenceLength] = {
  fa2, fa2, fa2, sol2, fa2, 
  do2, do2, do2, re2, do2, mi2, do2, fa2, mi2,
  fa2, fa2, sol2, fa2,
  do2, do2, do2, re2, do2, mi2, mi2, fa2, mi2, re2, do2
};

// 1/16 = 200
int silenceDurations[silenceLength] = {
  200, 200, 400, 600, 1000, 
  200, 200, 400, 600, 1000, 1200, 800, 800, 1200,
  400, 400, 600, 1000,
  600, 600, 400, 600, 1000, 800, 400, 600, 600, 400, 800  
};

int silenceLights[silenceLength] = {
  ledW, ledW, ledW, ledYR, ledW, 
  ledR, ledR, ledR, ledY, ledR, ledG, ledR, ledW, ledG,
  ledW, ledW, ledYR, ledW,
  ledR, ledR, ledR, ledY, ledR, ledG, ledG, ledW, ledG, ledY, ledR   
};

DS1302RTC rtc(8, 7, 6);
time_t timeToWakeUp;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledYR, OUTPUT);
  pinMode(sound, OUTPUT);
  setTime(rtc.get());
  timeToWakeUp = setTimeToWakeUp();
 // photoThread.onRun(photo);
 // alarmThread.onRun(alarm);
}




time_t setTimeToWakeUp() {
  tmElements_t tm;
  tm.Year = 2017;
  tm.Month = 4;
  tm.Day = 5;
  tm.Hour = 1;
  tm.Minute = 49;
  tm.Second = 0;
  return makeTime(tm);
}

void soundAndLightMode(int score[], int durations[], int lights[], int len) {
  for (int i=0; i<len && isSleeping; i++)  {
    isSleeping= analogRead(photoRes) > 500;
    tone(sound, score[i], durations[i]);
    analogWrite(lights[i], 255);
    delay(durations[i]*4/5);
    analogWrite(lights[i], 0);
    delay(durations[i]*1/5);
  }
  delay(1000);
}
void loop() {
   if (now()>=timeToWakeUp && isSleeping) {
    soundAndLightMode(imperialScore, imperialDurations, imperialLights, imperialLength);
    soundAndLightMode(silenceScore, silenceDurations, silenceLights, silenceLength);
  }
}


