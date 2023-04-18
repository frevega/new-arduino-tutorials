int xPin = A0;
int xVal = 0;

int speedPin = 5, directionPin1 = 4, directionPin2 = 3;
int outputPins[] = {speedPin, directionPin1, directionPin2};
int motorSpeed = 100;
char buffer[26];

void setup() {
  Serial.begin(9600);
  for (int pin = 0; pin < sizeof(outputPins) / sizeof(int); pin++) {
    pinMode(outputPins[pin], OUTPUT);
  }
  pinMode(xPin, INPUT);
}

void loop() {
  xVal = analogRead(xPin);

  if (xVal > 555) {
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin2, HIGH);
    //motorSpeed = map(xVal, 505, 1023, 0, 255);
    motorSpeed = 255.0 / 517.0 * (xVal - 505);
  } else if (xVal < 490) {
    digitalWrite(directionPin1, HIGH);
    digitalWrite(directionPin2, LOW);
    //motorSpeed = map(xVal, 0, 503, 255, 0);
    motorSpeed = -255.0 / 503.0 * (xVal - 503);
  } else {
    motorSpeed = 0;
  }

  analogWrite(speedPin, motorSpeed);

  sprintf(buffer, "xVal %d, motor speed: %d", xVal, motorSpeed);
  Serial.println(buffer);
}
