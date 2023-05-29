/*----------------------------------------------------------------------------------------------
Get Data For a Pot, UltraSonic sensor, Digital Temp Sensor
A hardware Timer is set to make the value of the Pot to be 0 if the device is left idel 
-----------------------------------------------------------------------------------------------*/
#include "GetData.h"
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(tempPin);
DallasTemperature DS18B20(&oneWire);

int timeOut = 30;  //30 seconds and 30 cm for timeOuts
float distance, maxRange = 30;

volatile int interruptCounter;

hw_timer_t* timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


void IRAM_ATTR onTimer() {
  interruptCounter++;
 }

void ConfigPins(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(tempPin, INPUT);
  pinMode(potPin, INPUT);

  timer = timerBegin(0, 80, true);//timer setup
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);  //set to 1 second
  timerAlarmEnable(timer);
}

void SetTimeOut(int timeOutRec){
  timeOut = timeOutRec;
}

void SetMaxRange(){
  maxRange = distance * 1.2;//current distance + 20% 
}

float GetFlow(){
  float potVal, milimin;
  int motorSpeed;

  potVal = analogRead(potPin);
  milimin = (potVal/4095) * 100;
  motorSpeed = map(potVal, 0, 4095, 0, 255);

  if (interruptCounter >= timeOut) {milimin = 0; motorSpeed = 0;} 
  //after 50 the motor will spin properly
  if(motorSpeed > 50){analogWrite(motorPin, motorSpeed);
  }else{analogWrite(motorPin, 0);}

  return milimin;
 }

 String GetDistance(){
  const float sound = 0.0343;  //speed of sound in microseconds
  float duration;

  timerDetachInterrupt(timer);  //errors occur when timer goes off during the calc

  digitalWrite(trig, LOW);
  delayMicroseconds(2);  //clear trigger pin
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);

  timerAttachInterrupt(timer, &onTimer, true);

  distance = (duration * sound) / 2;  // /2 to and from time is double
  if (distance < maxRange) {interruptCounter = 0;}
  return String(distance);
 }


String MaxRange(){
  String maxrangeStr;
  if(maxRange != 30) {maxrangeStr = String(maxRange);
  }else{maxrangeStr = "30.00";}

  return maxrangeStr;//string for website
}


String GetTemp() {
  DS18B20.requestTemperatures();
  return String(DS18B20.getTempCByIndex(0));//get temp 
 }


