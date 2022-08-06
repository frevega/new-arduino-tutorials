const int MAX_SPEED = 255;
const int MIN_SPEED = 105;
const int SPEED_INCREMENT = 15;

int speedPin = 5, directionPin1 = 4, directionPin2 = 3;
int outputPins[] = {speedPin, directionPin1, directionPin2};
int currentMotorSpeed = 0;

int leftButtonPin = 7, leftButtonValue = 0, leftPreviousButtonValue = 1;
int rightButtonPin = 8, rightButtonValue = 0, rightPreviousButtonValue = 1;
int inputPins[] = {leftButtonPin, rightButtonPin};

char buffer[35];

void setup() {
  Serial.begin(9600);
  for (int pin = 0; pin < sizeof(inputPins) / sizeof(int); pin++) {
    pinMode(inputPins[pin], INPUT);
    digitalWrite(inputPins[pin], HIGH);
  }
  for (int pin = 0; pin < sizeof(outputPins) / sizeof(int); pin++) {
    pinMode(outputPins[pin], OUTPUT);
  }
}

void loop() {
  leftButtonValue = digitalRead(leftButtonPin);
  rightButtonValue = digitalRead(rightButtonPin);

  handleButtons();

  leftPreviousButtonValue = leftButtonValue;
  rightPreviousButtonValue = rightButtonValue;

  analogWrite(speedPin, currentMotorSpeed);

  delay(50);
}

void handleButtons() {
  handleRightButton();
  handleLefButton();
}

void handleRightButton() {
  if (rightButtonValue != rightPreviousButtonValue && rightButtonValue == HIGH) {
    currentMotorSpeed = calculateMotorSpeed(HIGH, currentMotorSpeed);
    printInformation();
  }
}

void handleLefButton() {
  if (leftButtonValue != leftPreviousButtonValue && leftButtonValue == HIGH) {
    currentMotorSpeed = calculateMotorSpeed(LOW, currentMotorSpeed);
    printInformation();
  }
}

void printInformation() {
  Serial.print(digitalRead(directionPin2) == HIGH ? "Pushed right button" : "Pushed left button");
  Serial.println(currentMotorSpeed == MAX_SPEED ? ". Reached motor max speed" : "");
  sprintf(buffer, "Motor speed: %d, %s", currentMotorSpeed, currentMotorSpeed != 0 ? (digitalRead(directionPin2) == HIGH ? "clockwise" : "counterclockwise") : "Still");
  Serial.println(buffer);
}

int calculateMotorSpeed(int motorDirection, int currentMotorSpeed) {
  int motorSpeed = currentMotorSpeed;

  if (motorDirection < 0 || currentMotorSpeed == 0 || digitalRead(directionPin2) == motorDirection) {
    digitalWrite(directionPin1, motorDirection == HIGH ? LOW : HIGH);
    digitalWrite(directionPin2, motorDirection == HIGH ? HIGH : LOW);

    if (currentMotorSpeed == 0) {
      motorSpeed = MIN_SPEED;
    } else {
      motorSpeed + SPEED_INCREMENT <= MAX_SPEED ? motorSpeed += SPEED_INCREMENT : motorSpeed = MAX_SPEED;
    }
  } else {
    motorSpeed = currentMotorSpeed <= MIN_SPEED ? 0 : motorSpeed - SPEED_INCREMENT;
  }

  return motorSpeed;
}
