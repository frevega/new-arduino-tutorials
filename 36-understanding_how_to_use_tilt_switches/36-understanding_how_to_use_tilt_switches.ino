int tiltPin = 2, tiltValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  tiltValue = digitalRead(tiltPin);
  Serial.println(tiltValue);
}
