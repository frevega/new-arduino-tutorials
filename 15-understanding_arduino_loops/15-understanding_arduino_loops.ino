int yellowLed = 7, redLed = 9, delayTime = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(yellowLed, 3, delayTime);
  blinkLed(redLed, 5, delayTime);
}

void blinkLed(int led, int blinkCount, int delayTime) {
  for (int i = 0; i < blinkCount; i++) {
    digitalWrite(led, HIGH);
    delay(delayTime);
    digitalWrite(led, LOW);
    delay(delayTime);
  }
}
