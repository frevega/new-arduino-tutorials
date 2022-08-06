int redPin = 8, greenPin = 9, bluePin = 10;
String message = "What color do you want?";
String errorMessage = "Please choose between red, green, blue and aqua or off to turn off leds";
String debugMsg = "DEBUG - R(8) G(9) B(10) User selected pin ";
String userColor;
int userSelection;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);
  while (Serial.available() == 0) { }

  userColor = Serial.readString();

  if (userSelection != 0) {
    digitalWrite(userSelection, LOW);
  }
  
  if (userColor == "red") {
    userSelection = redPin;
  }
  else if (userColor == "green") {
    userSelection = greenPin;
  }
  else if (userColor ==  "blue") {
    userSelection = bluePin;
  }
  else if (userColor ==  "aqua") {
    analogWrite(bluePin, 80);
    analogWrite(greenPin, 255);
    return;
  }
  else if (userColor = "off") {
    digitalWrite(userSelection, LOW);
    return;
  }
  else {
    Serial.println(errorMessage);
  }

  Serial.println(debugMsg + userSelection);
  digitalWrite(userSelection, HIGH);
}
