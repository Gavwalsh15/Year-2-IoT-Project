#ifndef GetData_h
#define GetData_h

#include "Arduino.h"

#define tempPin 21
#define trig 33
#define echo 32
#define potPin 34
#define motorPin 26


void SetTimeOut(int timeOut);
void ConfigPins();//configures PINS used 
void SetMaxRange();//sets range for ultrasonic timeout 
float GetFlow();//gets flow of a 100 ml/min pump
String GetDistance();//gets value from the pot
String GetTemp();
String MaxRange();//gets range for ultrasonic timeout 

#endif