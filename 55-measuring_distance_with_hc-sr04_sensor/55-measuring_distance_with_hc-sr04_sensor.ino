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
  delay(25);

  distanceInCm = 1/29.154 * travelTime/2;
  distanceInInches = 1/74.052 * travelTime/2;

  Serial.print("CM to target: ");
  Serial.print(distanceInCm);
  Serial.print(", IN to target: ");
  Serial.println(distanceInInches);
  
  // 56: How to Graph Live Data Using the Serial Plotter
  /*Serial.print(0);
  Serial.print(",");
  Serial.print(sin(distanceInCm));
  Serial.print(",");
  Serial.print(cos(distanceInCm));
  Serial.print(",");
  Serial.println(10);*/


  delay(250);
}
