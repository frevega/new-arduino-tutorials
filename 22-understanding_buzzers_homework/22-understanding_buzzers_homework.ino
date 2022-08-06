int buzzPin = 9;
int potPin = A2;
int number;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  number = analogRead(potPin);//map(analogRead(potPin), 0 , 1023, 0, 255);
  Serial.println(number);
  //analogWrite(buzzPin, number);

  if (number > 1000) {
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }
}
