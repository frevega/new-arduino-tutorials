#include <Servo.h>

int servoPin = 9;
int servoPos = 0;
Servo servo;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  Serial.println("What angle for the servo?: ");
  while (Serial.available() == 0) {}

  servoPos = Serial.parseInt();

  if (servoPos >= 0 && servoPos <= 180) {
    Serial.println(servoPos);
    servo.write(servoPos);
  } else {
    Serial.println("Please provide an angle between 0 to 180");
  }
}
