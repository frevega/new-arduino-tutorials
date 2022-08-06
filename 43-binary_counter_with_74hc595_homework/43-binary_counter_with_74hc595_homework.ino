int dataPin = 13, latchPin = 12, clockPin = 11, clearPin = 10, outputEnablePin = 9;

int pins[] = {dataPin, latchPin, clockPin, clearPin, outputEnablePin};

byte leds = 0b10000000; //0x80;//55;//AA;
bool isGoingRight = true;
//int checkIfResetCounter = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);
}

void loop() {
  do {
    writeToRegister();
    printInfo();
    leds = isGoingRight ? leds >> 1 : leds << 1;
    delay(100);
    writeToRegister();
  } while (leds > 0x0);
  
  checkIfReset();
}

void printInfo() {
  printinfoDetail(DEC, "\t");
  printinfoDetail(HEX, "\t");
  printinfoDetail(BIN, "\n");
}

void printinfoDetail(char format, String special) {
  Serial.print(leds, format);
  Serial.print(special);
}

void writeToRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void checkIfReset() {
  //if ((checkIfResetCounter += 1) > 1 && leds == 0x0) {
  if (leds == 0x0) {
    isGoingRight = !isGoingRight;
    leds = isGoingRight ? 0b10000000 : 0b00000001;//0x80 : 0x1; ////55;//AA;
    //checkIfResetCounter = 0;
  }
}
