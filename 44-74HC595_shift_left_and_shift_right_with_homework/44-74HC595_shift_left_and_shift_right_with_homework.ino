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

byte ledsState = 0b11111110;
byte significantByte = 0b0;

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
  circularShift(false);
  circularShift(true);
}

// Commented framework function in order to use Math
void circularShift(bool isGoingRight) {
  for (int i = 0; i < 8; i++) {
    Serial.print(isGoingRight ? "> " : "< ");
    Serial.println(i);
    //analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
    potVal = -255.0/1023.0 * (analogRead(potPin) - 1023);
    analogWrite(outputEnablePin, potVal);
    writeToRegister();
    //Serial.println(potVal);

    // Get the least or most significant byte before losing it (according to function parameter)
    //significantByte = bitRead(ledsState, isGoingRight ? 0 : 7);

    // Bitshinft operation
    //ledsState = isGoingRight ? ledsState >> 1 : ledsState << 1;

    // Write the least or more significant byte in proper location, according to function parameter
    //bitWrite(ledsState, isGoingRight ? 7 : 0, significantByte);
    
    Serial.println(ledsState, BIN);
    delay(200);
    ledsState = isGoingRight ? ledsState * 128 + ledsState / 2 : ledsState / 128 + ledsState * 2;
  }
}

void writeToRegister() {
  digitalWrite(latchClockPin, LOW);
  shiftOut(serialDataPin, shiftClockPin, MSBFIRST, ledsState);
  digitalWrite(latchClockPin, HIGH);
}
