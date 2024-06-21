#include "SR04.h"
#include <Servo.h>

int trig_pin = 11;
int echo_pin = 10;
int servoDelay = 1000;
int servoMax = 180;
int servoMin = 0;

SR04 sensor = SR04(echo_pin,trig_pin);
Servo myServo;

long distance;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  distance = sensor.Distance();
  Serial.println(distance);
  delay(1);

  if (distance <= 15) {
    myServo.write(servoMax);
  } else{
    myServo.write(servoMin);
    delay(servoDelay);
  }
}
