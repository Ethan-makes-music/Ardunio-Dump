#include "SR04.h"

int trig_pin = 12;
int echo_pin = 11;

int ledG = 7;
int ledR = 5;

SR04 sensor = SR04(echo_pin,trig_pin);

long distance;

int buzzerPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  Serial.println(distance);
  delay(1);

  if (distance <= 15) {
    digitalWrite(buzzerPin, HIGH);
  }
  else{
    digitalWrite(buzzerPin, LOW);
  }
  if(distance <= 15) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
  }
  else{
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  }
}
