#define TRIGGERPIN 12
#define ECHOPIN 11

int travelTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
}

void loop() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);

  travelTime = pulseIn(ECHOPIN, HIGH);
  Serial.println(travelTime);
  delay(1000);
}
