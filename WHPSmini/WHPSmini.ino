#include <Servo.h>

Servo myServo;

int buttonOne = 10;
int buttonTwo = 8;
int servoDelay = 1000;
int servoMax = 99;
int servoMin = 0;
bool going = false;

void setup() {
  myServo.attach(9);
  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonOne) == LOW) {
      myServo.write(servoMax);
  }
  if (digitalRead(buttonTwo) == LOW) {
    going = false;
    myServo.write(servoMin);
    delay(servoDelay);
  }
}
