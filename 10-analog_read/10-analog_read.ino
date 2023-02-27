int readPin = A3;
float v2 = 0;
String voltageStr = "Voltage is: ";

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  v2 = analogRead(readPin) * 5.0/1023.0;
  Serial.println(voltageStr + v2);
  delay(1000);
}
