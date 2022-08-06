int photoPin = A0;
int buzzPin = A1;
int photoValue = 0;
int toneValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  photoValue = analogRead(photoPin);
  Serial.print("Photoresistor value: ");
  Serial.println(photoValue);

  // Paul McWhorter example
  //toneValue = 9.0/550.0 * photoValue - (9.0 * 200.0 / 550.0) + 1;
  //toneValue = 9.0/550.0 * (photoValue - 200) + 1;
  //toneValue = map(photoValue, 200, 750, 1, 10);

  // My example
  //toneValue = 99.0/423.0 * (photoValue - 10) + 1;
  toneValue = map(photoValue, 10, 433, 1, 100);

  // Other examples...
  //toneValue = 14950.0/1023.0 * photoValue + 50;
  //toneValue = map(photoValue, 0, 1023, 50, 15000);
  //toneValue = -990.0/1023.0 * photoValue + 1000;
  //toneValue = map(photoValue, 0, 1023, 1000, 10);
  Serial.print("Buzzer tone: ");
  Serial.println(toneValue);
  buzz(toneValue);
  //delay(250);
}

void buzz(int delayTime) {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}
