#include <Stepper.h>

int buttonPin = 2, buttonValue = 0, previousButtonValue = 0;
int motorStep = -1;
Stepper stepper(2048, 11, 9, 10, 8);

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  stepper.setSpeed(16);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  if (buttonValue != previousButtonValue && buttonValue == HIGH) {
    motorStep *= -1;
    Serial.println(motorStep == HIGH ? "Clockwise" : "Counter clockwise");
  }

  previousButtonValue = buttonValue;

  stepper.step(motorStep);
}
