void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  /*Serial.print("r: ");
  Serial.print(analogRead(A2));
  Serial.print(" g: ");
  Serial.print(analogRead(A1));
  Serial.print(" b: ");
  Serial.println(analogRead(A0));
  delay(250);*/

  analogWrite(3, map(analogRead(A2), 0, 1023, 0, 255));
  analogWrite(5, map(analogRead(A1), 0, 1023, 0, 255));
  analogWrite(6, map(analogRead(A0), 0, 1023, 0, 255));
}
