byte myByte = 0xE;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(myByte, DEC);
  Serial.print("\t");
  Serial.print(myByte, HEX);
  Serial.print("\t");
  Serial.println(myByte, BIN);
  myByte += 1;
  delay(400);
}
