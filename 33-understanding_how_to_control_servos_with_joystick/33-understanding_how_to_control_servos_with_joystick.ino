#include <Servo.h>

int xPin = A0, yPin = A1, sPin = 2;
int xVal = 0, yVal = 0, sVal = 0;
int servoXPin = 5, servoYPin = 6;
int servoXPos = 0, servoYPos = 0;
int buzzPin = 8;
Servo servoX, servoY;

void setup() {
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(sPin, HIGH);

  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);

  //servoXPos = 180.0/1023.0 * xVal;
  //servoYPos = 180.0/1023.0 * yVal;
  servoXPos = map(xVal, 0, 1023, 180, 0);
  servoYPos = map(yVal, 0, 1023, 0, 180);
  servoX.write(servoXPos);
  servoY.write(servoYPos);

  digitalWrite(buzzPin, sVal == 0 ? HIGH : LOW);
  delay(20);
 
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(", Y: ");
  Serial.print(yVal);
  Serial.print(", S: ");
  Serial.print(sVal);
  Serial.print(", Servo x Pos: ");
  Serial.print(servoXPos);
  Serial.print(", Servo Y Pos: ");
  Serial.println(servoYPos);
}
