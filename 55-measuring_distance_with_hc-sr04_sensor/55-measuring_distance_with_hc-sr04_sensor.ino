#define TRIGGERPIN 12
#define ECHOPIN 11

int travelTime = 0;
float distanceInCm = 0;
float distanceInInches = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
}

void loop() {
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN, LOW);

  travelTime = pulseIn(ECHOPIN, HIGH);

  distanceInCm = 1/29.154 * travelTime/2;
  distanceInInches = 1/74.052 * travelTime/2;
  
  Serial.println(travelTime);
  Serial.print(distanceInCm);
  Serial.print(" cm ");
  Serial.print(distanceInInches);
  Serial.println(" in");
  delay(250);
}
