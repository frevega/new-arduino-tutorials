int xPin = A0, yPin = A1, sPin = 2;
int xVal = 0, yVal = 0, sVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  delay(200);
  
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(", Y: ");
  Serial.print(yVal);
  Serial.print(", S: ");
  Serial.println(sVal);
}
