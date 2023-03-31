#include <LiquidCrystal_I2C.h>

// HC-SR04
#define TRIGGERPIN 12
#define ECHOPIN 11


int travelTime = 0;
float distanceInCm = 0, distanceInInches = 0;
const long DISTANCE_TIME_INTERVAL = 25;
unsigned long currentMillis = 0, distancePreviousTime = 0;
const long TRIGGER_LOW_TIME_INTERVAL = 4, TRIGGER_HIGH_TIME_INTERVAL = 12;
unsigned long currentMicros = 0, previousTriggerLowMicros = 0, previousTriggerHighMicros = 0;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
const long LCD_PRINT_TIME_INTERVAL = 3000;

// POTENTIOMETER & LCD LED
const int potPin = A0, lcdLedPin = 10;

// Button
int buttonPin = 4;
const int BUTTON_DEBOUNCE_INTERVAL = 50;
int buttonState = 0, buttonValue = 0, buttonPreviousValue = 0;

// Improve distance reading
int numReadings = 3000;
float distance = 0, readingAvg = 0;

// Prototype function
void printMessage(String firstLine, String secondLine = "");

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
  //Serial.begin(9600);
}

void loop() {
  analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
  readDistanceSensor();
}

void readDistanceSensor() {
  buttonValue = digitalRead(buttonPin);

  if (buttonValue != buttonPreviousValue) {
    currentMillis = millis();
  }

  if (millis() > (currentMillis + BUTTON_DEBOUNCE_INTERVAL) && (buttonValue != buttonState)) {
    buttonState = buttonValue;
    if (buttonValue == LOW) {
      printMessage("Measuring...");
      readingAvg = 0;
      for (int i = 0; i < numReadings; i += 1) {
        analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
        readingAvg += detectDistance();
        Serial.println(String(i) + " " + String(readingAvg));
      }

      printMessage("Target distance", String(readingAvg / numReadings) + " cm");
      currentMillis = millis();
      while (millis() <= (currentMillis + LCD_PRINT_TIME_INTERVAL)) {
        analogWrite(lcdLedPin, map(analogRead(potPin), 0, 1023, 0, 255));
      }
    } else {
      printMessage("Press to measure", "distance");
    }
  }

  buttonPreviousValue = buttonValue;
}

float detectDistance() {
  currentMillis = millis();
  if (currentMillis - distancePreviousTime >= DISTANCE_TIME_INTERVAL) {
    distancePreviousTime = currentMillis;

    currentMicros = micros();
    if (currentMicros - previousTriggerLowMicros >= TRIGGER_LOW_TIME_INTERVAL) {
      previousTriggerLowMicros = currentMicros;
      digitalWrite(TRIGGERPIN, LOW);
    }

    if (currentMicros - previousTriggerHighMicros >= TRIGGER_HIGH_TIME_INTERVAL) {
      previousTriggerHighMicros = currentMicros;
      digitalWrite(TRIGGERPIN, HIGH);
    }

    digitalWrite(TRIGGERPIN, LOW);
    travelTime = pulseIn(ECHOPIN, HIGH, 100000);
  }

  return 1 / 29.154 * travelTime / 2;
}

void printMessage(String firstLine, String secondLine = "") {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
}
