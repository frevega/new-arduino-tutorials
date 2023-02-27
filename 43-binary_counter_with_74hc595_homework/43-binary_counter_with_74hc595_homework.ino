// 74HC595
const byte SERIAL_DATA_PIN = 13;   // Pin 14 74HC595 (1)
const byte LATCH_CLOCK_PIN = 12;   // pin 12 74HC595 (1)
const byte SHIFT_CLOCK_PIN = 11;   // pin 11 74HC595 (1)
const byte CLEAR_PIN = 10;         // Pin 10 74HC595 (1)
const byte OUTPUT_ENABLE_PIN = 9;  // Pin 13 74HC595 (1)

int pins[] = {SERIAL_DATA_PIN, LATCH_CLOCK_PIN, SHIFT_CLOCK_PIN, CLEAR_PIN, OUTPUT_ENABLE_PIN};

byte leds = 0b10000000; //0x80;//55;//AA;
bool isGoingRight = true;
//int checkIfResetCounter = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
  }
  digitalWrite(CLEAR_PIN, LOW);
  digitalWrite(CLEAR_PIN, HIGH);
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
  digitalWrite(LATCH_CLOCK_PIN, LOW);
  shiftOut(SERIAL_DATA_PIN, SHIFT_CLOCK_PIN, LSBFIRST, leds);
  digitalWrite(LATCH_CLOCK_PIN, HIGH);
}

void checkIfReset() {
  //if ((checkIfResetCounter += 1) > 1 && leds == 0x0) {
  if (leds == 0x0) {
    isGoingRight = !isGoingRight;
    leds = isGoingRight ? 0b10000000 : 0b00000001;//0x80 : 0x1; ////55;//AA;
    //checkIfResetCounter = 0;
  }
}
