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

// Button
int buttonPin = 4;
const int buttonDebounceDelay = 50;
unsigned long buttonLastDebounceTime = 0;
int buttonState = 0, buttonValue = 0, buttonPreviousValue = 0;

void setup() {
  // HC-SR04
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();
  pinMode(potPin, INPUT);

  // Button
  pinMode(buttonPin, INPUT_PULLUP);

  
}

void loop() {
  analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
  readDistanceSensor();
}

void readDistanceSensor() {
  buttonValue = digitalRead(buttonPin);

  if (buttonValue != buttonPreviousValue) {
    buttonLastDebounceTime = millis();
  }

  if (millis() > (buttonLastDebounceTime + buttonDebounceDelay) && (buttonValue != buttonState)) {
    buttonState = buttonValue;
    if (buttonValue == LOW) {
      detectDistance();
    } else {
      printMessage("Press to measure", "distance");
    }
  }

  buttonPreviousValue = buttonValue;
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
    
    printMessage("Target distance", String( 1/29.154 * travelTime/2) + " cm");
    delay(5000);
  }
}

void printMessage(String firstLine, String secondLine) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
}
