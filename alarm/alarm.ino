#include <Thread.h>
int ledY = 8;
int ledR = 9; 
int ledG = 7;
int ledW = 6;
int p=5;

int do1=261;
int re1=293;
int mi1=329;
int fa1=349;
int sol1=392;
int la1=440;
int si1=493;
int laS=466;
int do2=523;
int re2=587;
int mi2=659;
int fa2=698;
int sol2=784;
int la2=880;
int si2=987;
int reS1=311;
int reS2=622;
int faS=369;

Thread lightThread=Thread();
Thread soundThread=Thread();

void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(p, OUTPUT);
  lightThread.onRun(imperialLight);
  soundThread.onRun(imperialSound);
}
void light(){  
  analogWrite(ledW, 255);
  delay(1000);
  analogWrite(ledG, 255);
  delay(1000);
  analogWrite(ledY, 255);
  delay(1000);
  analogWrite(ledR, 255); 

  delay(3000);
  
  analogWrite(ledR, 0);
  delay(1000);
  analogWrite(ledY, 0);
  delay(1000);
  analogWrite(ledG, 0);
  delay(1000);
  analogWrite(ledW, 0);
  delay(1000);
}
void christmasTree(){
  int d=500;//duration
  tone(p, do1,d);   delay(d); 
  tone(p, la1,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, sol1,d);  delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, fa1,d);   delay(d);
  tone(p, do1,d);   delay(d);
  tone(p, do1,d);   delay(d);

  tone(p, do1,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, laS,d);   delay(d);
  tone(p, re2,d);   delay(d);
  tone(p, do2,d);   delay(d);
  delay(d);
  tone(p, do2,d);   delay(d);
  tone(p, re1,d);   delay(d);
  tone(p, re1,d);   delay(d);
  tone(p, laS,d);   delay(d);
  tone(p, laS,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, sol1,d);  delay(d);
  tone(p, fa1,d);   delay(d);

  tone(p, do1,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, sol1,d);  delay(d);
  tone(p, la1,d);   delay(d);
  tone(p, fa1,d);   delay(d);
  delay(d*2);
}

void imperialSound(){
  int d=700;
  int pause=40;
  tone(p, sol1,d);   delay(d);    delay(pause); 
  tone(p, sol1,d);   delay(d);    delay(pause);
  tone(p, sol1,d);   delay(d);    delay(pause);
  tone(p, reS1,d);   delay(d/2);  delay(pause*2);
  tone(p, laS,d/2);  delay(d/2);  delay(pause);
  tone(p, sol1,d);   delay(d);    delay(pause);
  tone(p, reS1,d);   delay(d/2);  delay(pause*2);
  tone(p, laS,d/2);  delay(d/2);  delay(pause);
  tone(p, sol1,d);   delay(d);    delay(pause);
  delay(d);
  tone(p, re2,d);    delay(d);    delay(pause);
  tone(p, re2,d);    delay(d);    delay(pause);
  tone(p, re2,d);    delay(d);    delay(pause);
  tone(p, reS2,d);   delay(d/2);  delay(pause*2);
  tone(p, laS,d/2);  delay(d/2);  delay(pause);
  tone(p, faS,d);    delay(d);    delay(pause);
  tone(p, reS1,d);   delay(d/2);  delay(pause*2);
  tone(p, laS,d/2);  delay(d/2);  delay(pause);
  tone(p, sol1,d);   delay(d);    delay(pause);
  delay(d*2);
}

void imperialLight(){
  int d=740;
  int d2=430;
  int d3=390;
  analogWrite(ledY, 255); delay(d);  analogWrite(ledY, 0);
  analogWrite(ledY, 255); delay(d);  analogWrite(ledY, 0); 
  analogWrite(ledY, 255); delay(d);  analogWrite(ledY, 0); 
  analogWrite(ledR, 255); delay(d2); analogWrite(ledR, 0);
  analogWrite(ledG, 255); delay(d3); analogWrite(ledG, 0);
  analogWrite(ledY, 255); delay(d);  analogWrite(ledY, 0);
  analogWrite(ledR, 255); delay(d2); analogWrite(ledR, 0);
  analogWrite(ledG, 255); delay(d3); analogWrite(ledG, 0);
  analogWrite(ledY, 255); delay(d);  analogWrite(ledY, 0);

  analogWrite(ledG, 255); delay(d);  analogWrite(ledG, 0);
  analogWrite(ledG, 255); delay(d);  analogWrite(ledG, 0);  
  analogWrite(ledG, 255); delay(d);  analogWrite(ledG, 0);
  analogWrite(ledW, 255); delay(d2); analogWrite(ledW, 0);
  analogWrite(ledY, 255); delay(d3); analogWrite(ledY, 0);
  analogWrite(ledR, 255); delay(d);  analogWrite(ledR, 0);
  analogWrite(ledW, 255); delay(d2); analogWrite(ledW, 0);
  analogWrite(ledY, 255); delay(d3); analogWrite(ledY, 0);
  analogWrite(ledR, 255); delay(d);  analogWrite(ledR, 0);
  
 
}
void loop() {
 //lightThread.run();
// soundThread.run();
}
