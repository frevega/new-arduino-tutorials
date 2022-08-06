#include <Servo.h>

int photoPin = A0;
int servoPin = 9;
int photoValue = 0;
int servoPos = 0;
Servo servo;

void setup() {
  pinMode(photoPin, INPUT);
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  photoValue = analogRead(photoPin);
  //servoPos = 180.0/460.0 * photoValue;
  servoPos = -180.0/460.0 * photoValue + 180;
  
  if (servoPos < 0) {
    servoPos = 0;
  } else if (servoPos > 180) {
    servoPos = 180;
  }
 
  servo.write(servoPos);
  Serial.print(photoValue);
  Serial.print(" ");
  Serial.println(servoPos);
}
