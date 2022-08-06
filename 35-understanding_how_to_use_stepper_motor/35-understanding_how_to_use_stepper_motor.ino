#include <Stepper.h>

int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  stepper.setSpeed(19);
}

void loop() {
  stepper.step(stepsPerRevolution);
  delay(500);
  stepper.step(-stepsPerRevolution);
  delay(500);
}
