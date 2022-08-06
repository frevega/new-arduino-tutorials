int speedPin = 5, directionPin1 = 4, directionPin2 = 3; // Direcction pin 1 low, direction pin 2 high and viceversa change directions
int outputPins[] = {speedPin, directionPin1, directionPin2};
int motorSpeed = 60; // Between 0 and 255, 0 off, 255 max speed and numbers in between will control the speed
int direction = LOW;

void setup() {
  Serial.begin(9600);
  for (int pin = 0; pin < sizeof(outputPins) / sizeof(int); pin++) {
    pinMode(outputPins[pin], OUTPUT);
    Serial.println(outputPins[pin]);
  }
}

void loop() {
  Serial.println(direction);
  digitalWrite(directionPin1, direction == HIGH ? HIGH : LOW);
  digitalWrite(directionPin2, direction == HIGH ? LOW : HIGH);
  analogWrite(speedPin, motorSpeed);
}
