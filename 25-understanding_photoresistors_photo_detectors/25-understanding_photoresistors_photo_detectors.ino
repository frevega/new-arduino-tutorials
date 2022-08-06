int lightPin = A0;
int greenPin = 2;
int redPin = 3;
int lightVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  handleLeds(lightVal);
  Serial.println(lightVal);
  delay(250);
}

void handleLeds(int value) {
  if (value < 150) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
}
