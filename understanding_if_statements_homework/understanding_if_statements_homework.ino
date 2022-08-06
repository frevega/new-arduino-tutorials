int readPin = A2;
float v2;
String voltageStr = "Voltage from potentiometer is: ";

int greenPin = 7;
int yellowPin = 8;
int redPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  v2 = analogRead(readPin) * 5.0/1023.0;
  Serial.println(voltageStr + v2);

  digitalWrite(greenPin, v2 < 3 ? HIGH : LOW);
  digitalWrite(yellowPin, v2 >= 3 && v2 < 4 ? HIGH : LOW);
  digitalWrite(redPin, v2 >= 4 ? HIGH : LOW);
  delay(500);
}
