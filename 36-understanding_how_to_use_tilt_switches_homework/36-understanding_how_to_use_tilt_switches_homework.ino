int tiltPin = 2, tiltValue = 0, previousTiltValue = -1;
int greenPin = 6, redPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  tiltValue = digitalRead(tiltPin);
  
  if (tiltValue != previousTiltValue) { 
    Serial.println(tiltValue == LOW ? "Vertical" : "Horizontal");
  }
  previousTiltValue = tiltValue;
  
  digitalWrite(redPin, tiltValue == HIGH ? HIGH : LOW);
  digitalWrite(greenPin, tiltValue == LOW ? HIGH : LOW);
  delay(50);
}
