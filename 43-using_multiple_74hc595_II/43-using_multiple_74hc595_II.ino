const int registersQtty = 3;

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

bool isGoingRight = true;

byte *ledsState = new byte[registersQtty];

void setup() {
  Serial.begin(9600);
  for (size_t i = 0; i < registersQtty; i++) {
    ledsState[i] = 0;
  }

  for (size_t i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);

  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);

  //analogWrite(outputEnablePin, 250);
}

void loop() {
  lightEffects();
}


void _lightEffects() {
  for (int i = 23; i >= 0; i--) {
    potVal = analogRead(potPin);
    analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
    writeToRegister(i, HIGH);
    delay(50);
    //writeToRegister(i, LOW);
    Serial.println(potVal);
  }
}

void lightEffects() {
  effectFour(-11, 0);
  effectFour(0, 11);
  effectThree(0, 11);
  effectThree(-11, 0);
  effectThree(0, 23);
  effectOne(23, 0);
  effectOne(0, -23);
  effectTwo(23, 0);
  effectTwo(0, -23);
}

void effectOne(int min, int max) {
  for (int i = min; i >= max; i--) {
    for (int j = i; j >= max; j--) {
      analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
      writeToRegister(abs(j), HIGH);
      delay(10);
      writeToRegister(abs(j), LOW);
    }
  }
}

void effectTwo(int min, int max) {
  for (int i = min; i >= max; i--) {
    analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
    writeToRegister(abs(i), HIGH);
    delay(25);
    writeToRegister(abs(i), LOW);
  }
}

void effectThree(int min, int max) {
  for (int i = max; i >= min; i--) {
    for (int k = min; k <= i; k++) {
      analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
      writeToRegister(abs(k), HIGH);
      writeToRegister(23 - abs(k), HIGH);
      delay(25);
      writeToRegister(abs(k), LOW);
      writeToRegister(23 - abs(k), LOW);
    }

    writeToRegister(abs(i), HIGH);
    writeToRegister(23 - abs(i), HIGH);
  }
}

void effectFour(int min, int max) {
  for (int i = min; i <= max; i++) {
    analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
    writeToRegister(abs(i), HIGH);
    writeToRegister(23 - abs(i), HIGH);
    delay(30);
  }

  for (int i = max; i >= min; i--) {
    analogWrite(outputEnablePin, map(analogRead(potPin), 1023 , 0, 0, 255));
    writeToRegister(abs(i), LOW);
    writeToRegister(23 - abs(i), LOW);
    delay(30);
  }
}

void effect() {
  for (int i = 23; i >= 0; i--) {
    writeToRegister(i, HIGH);
    delay(10);
  }
  for (int i = 23; i >= 0; i--) {
    writeToRegister(i, LOW);
    delay(10);
  }
  /*for (int i = 0; i <= 23; i++) {
    writeToRegister(i, HIGH);
    delay(50);
    }
    for (int i = 0; i <= 23; i++) {
    writeToRegister(i, LOW);
    delay(50);
    }*/
}

void writeToRegister(int pin, int ledState) {
  int currentRegisterIndex = pin / 8;
  int currentPinIndex = pin - (8 * currentRegisterIndex);

  digitalWrite(latchClockPin, LOW);

  for (size_t registerIndex = 0; registerIndex < registersQtty; registerIndex++) {
    byte *leds = &ledsState[registerIndex];

    if (registerIndex == currentRegisterIndex) {
      bitWrite(*leds, currentPinIndex, ledState);
    }

    shiftOut(serialDataPin, shiftClockPin, LSBFIRST, *leds);
  }

  digitalWrite(latchClockPin, HIGH);
}
