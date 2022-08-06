int buttonPin = 2;
int buttonVal = 0;
char buffer[50];

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  sprintf(buffer, "Your button is: %d", buttonVal);
  Serial.println(buffer);
  delay(100);
}
