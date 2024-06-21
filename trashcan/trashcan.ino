#include "SR04.h"
#include <Servo.h>

Servo myServo;

int servoDelay = 1;
int servomax = 90;
int servomin = 0;

int trig_pin = 7;
int echo_pin = 6;
int detect = 3;

SR04 sensor = SR04(echo_pin,trig_pin);

long distance;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
  delay(1000);
  
  pinMode (detect, OUTPUT);
}

void loop() {
  digitalWrite(detect, HIGH);
  if (distance <= 7) {
    myServo.write(servomax);
  }
  else{
    myServo.write(servomin);
  }
}
