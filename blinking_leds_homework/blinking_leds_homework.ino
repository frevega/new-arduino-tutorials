const int RED = 8;
const int GREEN = 7;
const int BLUE = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(RED, 5, 250);
  blinkLed(GREEN, 10, 275);
  blinkLed(BLUE, 15, 300);
}

void blinkLed(int led, int iterations, int blinkDelay) {
  for (int i = 0; i < iterations; i++) {
    digitalWrite(led, HIGH);
    delay(blinkDelay);
    digitalWrite(led, LOW);
    delay(blinkDelay);
  }
}
