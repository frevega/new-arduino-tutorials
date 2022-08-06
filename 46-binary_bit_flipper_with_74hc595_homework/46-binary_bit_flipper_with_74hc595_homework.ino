// 74HC595
int serialDataPin = 13; // Pin 14 74HC595 (1)
int latchClockPin = 12; // pin 12 74HC595 (1)
int shiftClockPin = 11; // pin 11 74HC595 (1)
int clearPin = 10; // Pin 10 74HC595 (1)
int outputEnablePin = 9; // Pin 13 74HC595 (1)

// Potentiometer
int potPin = A0;
int potVal = 0;

int pins[] = {serialDataPin, latchClockPin, shiftClockPin, clearPin, outputEnablePin};

byte ledsState = 0b11100000;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);

  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);
}

void loop() {
  potVal = -255.0 / 1023.0 * (analogRead(potPin) - 1023);
  analogWrite(outputEnablePin, potVal);
  writeToRegister();
  Serial.print(ledsState, BIN);
  Serial.print("\t");
  Serial.println(ledsState, HEX);
  delay(200);
  ledsState = ~ledsState;
}

void writeToRegister() {
  digitalWrite(latchClockPin, LOW);
  shiftOut(serialDataPin, shiftClockPin, MSBFIRST, ledsState);
  digitalWrite(latchClockPin, HIGH);
}
