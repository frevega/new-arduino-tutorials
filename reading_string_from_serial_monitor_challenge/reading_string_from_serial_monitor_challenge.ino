int redLed = 10, blueLed = 11, greenLed = 12;
String ledColor;
int ledPinNumber;
String message = "What color led would you like me to light up?: ";
String errorMessage = "Please choose between red, green and blue";

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);
  while(Serial.available() == 0) { }

  ledColor = Serial.readString();

  if (ledPinNumber != 0) {
    digitalWrite(ledPinNumber, LOW);
  }
  
  if (ledColor == "red") {
    ledPinNumber = redLed;
  }
  else if (ledColor == "green") {
    ledPinNumber = greenLed;
  }
  else if (ledColor ==  "blue") {
    ledPinNumber = blueLed;
  }
  else {
    Serial.println(errorMessage);
  }
  
  digitalWrite(ledPinNumber, HIGH);
}
