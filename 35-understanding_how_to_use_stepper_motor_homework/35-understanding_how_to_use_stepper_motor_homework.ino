#include <Stepper.h>

int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 11, 9, 10, 8);//8, 10, 9, 11);

int buttonPin = 2;
int motorStep = 0;
int stepDirection = 1;
int previousButtonValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  stepper.setSpeed(16);
}

void loop() {
  toggleDirection();
  stepper.step(motorStep);
}

int toggleDirection() {
  int buttonValue = digitalRead(buttonPin);
  if (buttonValue != previousButtonValue && buttonValue == 1) {
    stepDirection = (stepDirection + 1) % 2;
    motorStep = stepDirection == 0 ? 1 : -1;  
    Serial.println(motorStep == 1 ? "Clockwise" : "Counter clockwise");
  }
  
  previousButtonValue = buttonValue;
}
