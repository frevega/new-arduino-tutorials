int buzzPin = 8;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pitch(i);
  i++;
  Serial.println(i);
  delay(50);
}

void pitch(int delayTime) {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}
