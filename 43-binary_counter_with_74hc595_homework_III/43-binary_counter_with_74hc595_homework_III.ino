const byte REGISTERS_QTTY = 3;
const uint32_t COUNTER_MAX_VALUE = pow(256, REGISTERS_QTTY) - 1;

// 74HC595
const byte SERIAL_DATA_PIN = 13;   // Pin 14 74HC595 (1)
const byte LATCH_CLOCK_PIN = 12;   // pin 12 74HC595 (1)
const byte SHIFT_CLOCK_PIN = 11;   // pin 11 74HC595 (1)
const byte CLEAR_PIN = 10;         // Pin 10 74HC595 (1)
const byte OUTPUT_ENABLE_PIN = 9;  // Pin 13 74HC595 (1)

// Potentiometer
const byte potPin = A0;

int shiftRegistersPins[] = { SERIAL_DATA_PIN, LATCH_CLOCK_PIN, SHIFT_CLOCK_PIN, CLEAR_PIN, OUTPUT_ENABLE_PIN };

uint32_t value = 0;  //16776960; //13391359;
byte *ledsState = new byte[REGISTERS_QTTY];

void setup() {
  for (size_t i = 0; i < REGISTERS_QTTY; i++) {
    ledsState[i] = 0;
  }

  for (size_t i = 0; i < sizeof(shiftRegistersPins); i++) {
    pinMode(shiftRegistersPins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);

  digitalWrite(CLEAR_PIN, LOW);
  digitalWrite(CLEAR_PIN, HIGH);

  //Serial.begin(9600);
  //value = 13391359;
  // Serial.println(value, BIN);
  // Serial.println();
  // Serial.println(value >> 16, BIN); // GET FIRST BYTE
  // Serial.println(((byte)(value >> 8)), BIN); // GET SECOND BYTE?
  //Serial.println(value & 0xFF, BIN); // GET LAST BYTE
}

void loop() {
  analogWrite(OUTPUT_ENABLE_PIN, map(analogRead(potPin), 1023, 0, 0, 255));
  value = value < COUNTER_MAX_VALUE ? value + 1 : 0;
  ledsState[0] = value >> 16;
  ledsState[1] = value >> 8;
  ledsState[2] = value & 0xFF;
  // for (int i = REGISTERS_QTTY -1; i >= 0; i--) {
  //   ledsState[i] = i > 0 ? value >> 8 * i : value && 0xFF;
  // }
  writeToRegister();

  /*Serial.print("Value: " + String(value) + " ");
  Serial.print(value, BIN);
  Serial.print(" ");
  for (byte i = 0; i < 3; i++) {
    Serial.print(String(i) + ": ");
    Serial.print(ledsState[i], BIN);
    Serial.print(" ");
  }
  Serial.println();
  delay(100);*/
}

void writeToRegister() {
  digitalWrite(LATCH_CLOCK_PIN, LOW);
  for (byte registerIndex = 0; registerIndex < REGISTERS_QTTY; registerIndex++) {
    byte *leds = &ledsState[registerIndex];
    shiftOut(SERIAL_DATA_PIN, SHIFT_CLOCK_PIN, MSBFIRST, *leds);
  }
  digitalWrite(LATCH_CLOCK_PIN, HIGH);
}