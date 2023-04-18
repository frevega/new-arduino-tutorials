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

const float MAX_SPEED = 255, MIN_SPEED = 105, SPEED_INCREMENT = 18.75;

int speedPin = 5, directionPin1 = 4, directionPin2 = 3;
float motorSpeed = 0;

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
    case ONE:
      handleNumberCommand(0);
      break;
    case TWO:
      handleNumberCommand(1);
      break;
    case THREE:
      handleNumberCommand(2);
      break;
    case FOUR:
      handleNumberCommand(3);
      break;
    case FIVE:
      handleNumberCommand(4);
      break;
    case SIX:
      handleNumberCommand(5);
      break;
    case SEVEN:
      handleNumberCommand(6);
      break;
    case EIGHT:
      handleNumberCommand(7);
      break;
    case NINE:
      handleNumberCommand(8);
      break;
    case ZERO:
      handleMotor(motorSpeed = 0);
      break;
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

void handleNumberCommand(int multiplier) {
  if (motorSpeed == 0) { return; }
  
  float auxMotorSpeed = MIN_SPEED + (SPEED_INCREMENT * multiplier);
  motorSpeed = (motorSpeed > 0 ? auxMotorSpeed : -auxMotorSpeed);
  handleMotor(motorSpeed);
}

void handleMotor(float motorSpeed) {
  Serial.print("hm: ");
  Serial.println(motorSpeed);
  digitalWrite(directionPin1, motorSpeed > 0 ? LOW : HIGH);
  digitalWrite(directionPin2, motorSpeed > 0 ? HIGH : LOW);
  analogWrite(speedPin, abs(motorSpeed));
}

float calculateSpeed(bool isIncrement) {
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
  Serial.print("cs: ");
  Serial.println(motorSpeed);

  return motorSpeed;
}
