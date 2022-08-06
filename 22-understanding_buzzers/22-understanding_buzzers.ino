int number;
int buzzPin = 8;
String message = "Please input number:";

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);
  while (Serial.available() == 0) { }
  number = Serial.parseInt();

  if (number > 10) {
    digitalWrite(buzzPin, HIGH);
    delay(2000);
    digitalWrite(buzzPin, LOW);
  }
}
