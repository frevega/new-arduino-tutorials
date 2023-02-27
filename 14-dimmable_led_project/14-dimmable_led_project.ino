int potPin = A2;
int greenPin = 10;
int potVal;
int ledVal = 0;

String potValStr = "Potentiometer value is: ";
String ledValStr = "Brightness value is: ";

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(greenPin, OUTPUT);
  //Serial.begin(9660);
}

void loop() {
  // put your main code here, to run repeatedly:
  //potVal = analogRead(potPin);
  //ledVal = potVal * (255.0 / 1023.0);
  //analogWrite(greenPin, ledVal);
  //Serial.println(potValStr + potVal);
  //Serial.println(ledValStr + ledVal);
  analogWrite(greenPin, map(analogRead(potPin), 0 , 1023, 0, 255));
  //delay(400);
}
