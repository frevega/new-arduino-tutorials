int ledPin = 8;
int buttonReadPin = 12;
int readValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonReadPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = digitalRead(buttonReadPin);
  Serial.println(readValue);

  digitalWrite(ledPin, readValue == 0 ? HIGH : LOW);
}
