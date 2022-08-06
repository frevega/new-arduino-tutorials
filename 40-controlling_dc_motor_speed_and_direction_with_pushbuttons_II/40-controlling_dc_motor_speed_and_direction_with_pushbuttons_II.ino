const int MAX_SPEED = 255, MIN_SPEED = 105, SPEED_INCREMENT = 15;

int speedPin = 5, directionPin1 = 4, directionPin2 = 3, motorSpeed = 0;
int leftButtonPin = 8, leftPreviousButtonValue = 1;
int rightButtonPin = 7, rightPreviousButtonValue = 1;

struct PinModel {
  int pin;
  int mode;

  PinModel(int pin_, int mode_) {
    pin = pin_;
    mode = mode_;
  };
};

PinModel pinsArray[] = {
  PinModel(speedPin, OUTPUT),
  PinModel(directionPin1, OUTPUT),
  PinModel(directionPin2, OUTPUT),
  PinModel(leftButtonPin, INPUT_PULLUP),
  PinModel(rightButtonPin, INPUT_PULLUP)
};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pinsArray) / sizeof(PinModel); i++) {
    pinMode(pinsArray[i].pin, pinsArray[i].mode);
  }
}

void loop() {
  handleRightButton();
  handleLeftButton();
  delay(50);
}

void handleRightButton() {
  int rightButtonValue = digitalRead(rightButtonPin);
  
  if (rightButtonValue != rightPreviousButtonValue && rightButtonValue == HIGH) {
    motorSpeed = calculateMotorSpeed(MIN_SPEED, MAX_SPEED, motorSpeed, true, &calculateSpeed);
    handleMotor(motorSpeed);
    printInfo(motorSpeed);
  }
  
  rightPreviousButtonValue = rightButtonValue;
}

void handleLeftButton() {
  int leftButtonValue = digitalRead(leftButtonPin);

  if (leftButtonValue != leftPreviousButtonValue && leftButtonValue == HIGH) {
    motorSpeed = calculateMotorSpeed(-MIN_SPEED, -MAX_SPEED, motorSpeed, false, &calculateSpeed);
    handleMotor(motorSpeed);
    printInfo(motorSpeed);
  }

  leftPreviousButtonValue = leftButtonValue;
}

void printInfo(int motorSpeed) {
  Serial.print(motorSpeed > 0 ? "Right: " : "Left: ");
  Serial.println(abs(motorSpeed));
}

void handleMotor(int motorSpeed) {
  digitalWrite(directionPin1, motorSpeed > 0 ? LOW : HIGH);
  digitalWrite(directionPin2, motorSpeed > 0 ? HIGH : LOW);
  analogWrite(speedPin, abs(motorSpeed));
}

int calculateSpeed(int motorSpeed, bool isClockwise) {
  return isClockwise ? motorSpeed += SPEED_INCREMENT : motorSpeed -= SPEED_INCREMENT;
}

int calculateMotorSpeed(int minSpeed, int maxSpeed, int currentSpeed, bool isClockwise, int (*callback)(int, bool)) {
  if (abs(currentSpeed) > 0 && abs(currentSpeed) <= abs(maxSpeed)) {
    int newSpeed = callback(currentSpeed, isClockwise);
    if (abs(newSpeed) < abs(minSpeed)) {
      return newSpeed = 0;
    } else if (abs(newSpeed) >= abs(maxSpeed)) {
      return maxSpeed;
    } else {
      return newSpeed;
    }
  } else if (currentSpeed == 0) {
    return minSpeed;
  }
}
