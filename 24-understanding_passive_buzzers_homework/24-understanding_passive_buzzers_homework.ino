int buzzPin = 8;
int potPin = A0;
int toneVal, potVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  toneVal = -9940.0/1023.0 * potVal + 10000;
  //toneVal = map(analogRead(potPin), 0 , 1023, 10000, 60);
  Serial.print(potVal);
  Serial.print(" ");
  Serial.println(toneVal);
  pitch(toneVal);
}

void pitch(int delayTime) {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}
