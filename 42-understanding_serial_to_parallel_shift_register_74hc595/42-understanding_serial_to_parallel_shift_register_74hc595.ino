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

byte leds = 0b11110000;

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
  analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
  digitalWrite(latchClockPin, LOW);
  shiftOut(serialDataPin, shiftClockPin, MSBFIRST, leds);
  digitalWrite(latchClockPin, HIGH);

  Serial.print(leds, DEC);
  Serial.print("\t");
  Serial.print(leds, HEX);
  Serial.print("\t");
  Serial.println(leds, BIN);

  leds += 1;
  delay(500);
}
