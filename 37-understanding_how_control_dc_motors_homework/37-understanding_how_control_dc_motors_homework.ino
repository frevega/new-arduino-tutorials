int speedPin = 5, directionPin1 = 4, directionPin2 = 3;
int outputPins[] = {speedPin, directionPin1, directionPin2};
int motorSpeed = 95;
int tiltPin = 2, tiltValue = 0;

void setup() {
  Serial.begin(9600);
  for (int pin = 0; pin < sizeof(outputPins) / sizeof(int); pin++) {
    pinMode(outputPins[pin], OUTPUT);
  }
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  digitalWrite(directionPin1, HIGH);
  digitalWrite(directionPin2, LOW);
}

void loop() {
  tiltValue = digitalRead(tiltPin);
  analogWrite(speedPin, tiltValue == LOW ? motorSpeed : 0);
  Serial.println(tiltValue == LOW ? "Vertical" : "Horizontal");
}
