const byte START_LED_STATE = 0b10000000;
const byte END_LED_STATE   = 0b00000001;
//const byte START_LED_STATE = 0b10101010;
//const byte END_LED_STATE   = 0b01010101;

int serialDataPin = 13; // Pin 14 74HC595 (1)
int latchClockPin = 12; // pin 12 74HC595 (1)
int shiftClockPin = 11; // pin 11 74HC595 (1)
int clearPin = 10; // Pin 10 74HC595 (1)

int pins[] = {serialDataPin, latchClockPin, shiftClockPin, clearPin};

bool isGoingRight = true;

byte ledsState = START_LED_STATE;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
  clearAndActivate();
}

void loop() {
  do {
    writeToRegister();
    printInfo();
    ledsState = isGoingRight ? ledsState >> 1 : ledsState << 1;
    delay(500);
    writeToRegister();
  } while (ledsState > 0x0);

  checkIfReset();
}

void clearAndActivate() {
  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);
}

void printInfo() {
  printinfoDetail(DEC, "\t");
  printinfoDetail(HEX, "\t");
  printinfoDetail(BIN, "\n");
}

void printinfoDetail(char format, String special) {
  Serial.print(ledsState, format);
  Serial.print(special);
}

void writeToRegister() {
  digitalWrite(latchClockPin, LOW);
  shiftOut(serialDataPin, shiftClockPin, LSBFIRST, ledsState);
  //shiftOut(serialDataPin, shiftClockPin, LSBFIRST, ledsState);
  //shiftOut(serialDataPin, shiftClockPin, LSBFIRST, ledsState);
  digitalWrite(latchClockPin, HIGH);
}

void checkIfReset() {
  if (ledsState == 0x0) {
    isGoingRight = !isGoingRight;
    ledsState = isGoingRight ? START_LED_STATE : END_LED_STATE;
  }
}
