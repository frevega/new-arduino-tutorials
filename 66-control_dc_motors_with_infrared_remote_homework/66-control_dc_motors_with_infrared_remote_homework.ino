/*
  1. When download/start program, motor should be off
  2. When press OK button start motor forward direction at full speed
  3. When press OK button and motor is on, turn it off
  4. When press RIGHT button go forward, keeping previous speed
  5. When press LEFT button go backwards, keeping previous speed
  6. When press UP button go faster
  7. When press DOWN button go slower
*/

#include <IRremote.hpp>
#include "IRRemoteCodes.h"

const int MAX_SPEED = 255, MIN_SPEED = 105, SPEED_INCREMENT = 15;

int speedPin = 5, directionPin1 = 4, directionPin2 = 3, motorSpeed = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK);
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
}

void loop() {
  if (IrReceiver.decode() && IrReceiver.decodedIRData.numberOfBits > 0) {
    handleRemoteCommand(IrReceiver.decodedIRData);
  }
  IrReceiver.resume();
  delay(50);
}

void handleRemoteCommand(IRData data) {
  switch (data.command) {
    case UP:
      handleMotor(calculateSpeed(true));
      break;
    case DOWN:
      handleMotor(calculateSpeed(false));
      break;
    case LEFT:
      handleMotor(motorSpeed > 0 ? motorSpeed *= -1 : motorSpeed);
      break;
    case RIGHT:
      handleMotor(motorSpeed < 0 ? motorSpeed *= -1 : motorSpeed);
      break;
    case OK:
      handleMotor(motorSpeed = (motorSpeed == 0 ? MAX_SPEED : 0));
      break;
  }
}

void handleMotor(int motorSpeed) {
  digitalWrite(directionPin1, motorSpeed > 0 ? LOW : HIGH);
  digitalWrite(directionPin2, motorSpeed > 0 ? HIGH : LOW);
  analogWrite(speedPin, abs(motorSpeed));
}

int calculateSpeed(bool isIncrement) {
  if (isIncrement) {
    motorSpeed = motorSpeed > 0 ? motorSpeed += SPEED_INCREMENT : motorSpeed += -SPEED_INCREMENT;
  } else {
    motorSpeed = motorSpeed > 0 ? motorSpeed -= SPEED_INCREMENT : motorSpeed -= -SPEED_INCREMENT;
  }

  if (abs(motorSpeed) < MIN_SPEED) {
    motorSpeed = 0;
  } else if (abs(motorSpeed) >= MAX_SPEED) {
    motorSpeed = motorSpeed > 0 ? MAX_SPEED : -MAX_SPEED;
  }
  Serial.println(motorSpeed);

  return motorSpeed;
}
