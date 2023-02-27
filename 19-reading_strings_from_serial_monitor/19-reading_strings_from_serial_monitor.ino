String name;
String message = "What is your name?: ";
String message2 = "Hello %s, Welcome to arduino!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);

  while(Serial.available() == 0) { }

  name = Serial.readString();
  char buffer[50];
  sprintf(buffer, message2.c_str(), name.c_str());
  Serial.println(buffer);
}
