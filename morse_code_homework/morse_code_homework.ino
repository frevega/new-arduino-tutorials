const int RED = 8;
const int GREEN = 7;
const int BLUE = 6;

const int SLOW = 500;
const int MEDIUM = 300;
const int FAST = 100;

const int SLOW_BLINKING_TIMES = 15;
const int MEDIUM_BLINKING_TIMES = 10;
const int FAST_BLINKING_TIMES = 5;

const int LONG_DELAY = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(RED, FAST_BLINKING_TIMES, FAST);
  blinkLed(GREEN, MEDIUM_BLINKING_TIMES, MEDIUM);
  blinkLed(BLUE, SLOW_BLINKING_TIMES, SLOW);
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
