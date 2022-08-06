int buzzPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pitch(1);
  pitch(2);
  //pitch(3);
}

void pitch(int delayTime) {
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzPin, HIGH);
    delay(delayTime);
    digitalWrite(buzzPin, LOW);
    delay(delayTime);
  }
}
