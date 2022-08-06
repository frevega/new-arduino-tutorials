const int RED = 8;
const int DIT = 50;
const int DAH = 150;
const int THREE = 3;
const int LONG_DELAY = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(RED, THREE, DIT);
  blinkLed(RED, THREE, DAH);
  blinkLed(RED, THREE, DIT);
  delay(LONG_DELAY);
}

void blinkLed(int led, int iterations, int blinkDelay) {
  for (int i = 0; i < iterations; i++) {
    digitalWrite(led, HIGH);
    delay(blinkDelay);
    digitalWrite(led, LOW);
    delay(blinkDelay);
  }
}
