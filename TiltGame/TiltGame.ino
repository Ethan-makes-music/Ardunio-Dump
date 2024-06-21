int tiltPin = 13;
int ledPin = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;
int ledPin6 = 7;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(tiltPin) == LOW) {
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin, LOW);
    delay(50);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(50);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(50);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin4, LOW);
    delay(50);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin5, LOW);
    delay(50); 
  }
  else if (digitalRead(tiltPin) == HIGH) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin6, HIGH);
    delay(50);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, LOW);
    delay(50);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
    delay(50);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    delay(50);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(50);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(50); 
  }
}
