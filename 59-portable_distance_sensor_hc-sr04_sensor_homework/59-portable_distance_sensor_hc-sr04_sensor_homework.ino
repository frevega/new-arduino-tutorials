#include <LiquidCrystal_I2C.h>

// HC-SR04
#define TRIGGERPIN 12
#define ECHOPIN 11

int travelTime = 0;
float distanceInCm = 0, distanceInInches = 0;
unsigned long distanceTimeInterval = 250, distanceCurrentTime = 0, distancePreviousTime = 0;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// POTENTIOMETER & LCD LED
const int potPin = A0, lcdLedPin = 3;

void setup() {
  //Serial.begin(9600);

  // HC-SR04
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();
  pinMode(potPin, INPUT);
}

void loop() {
  analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
  detectDistance();
}

void detectDistance() {
  distanceCurrentTime = millis();
  if (distanceCurrentTime - distancePreviousTime >= distanceTimeInterval) {
    distancePreviousTime = distanceCurrentTime;
    digitalWrite(TRIGGERPIN, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIGGERPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGERPIN, LOW);
  
    travelTime = pulseIn(ECHOPIN, HIGH);
    delay(10);
  
    distanceInCm = 1/29.154 * travelTime/2;
    //distanceInInches = 1/74.052 * travelTime/2;
  
    //Serial.println("CM to target: " + String(distanceInCm));
    
    //Serial.print(", IN to target: ");
    //Serial.println(distanceInInches);

    printDistance(distanceInCm);
  }
}

void printDistance(float distance) {
  lcd.setCursor(0, 0);
  lcd.print("Target Distance");
  lcd.setCursor(0, 1);
  lcd.print(String(distance) + " cm   ");
}
