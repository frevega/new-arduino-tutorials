/*int number;
String message = "Please enter your number: ";
String message2 = "Your number is: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);

  while (Serial.available() == 0) {
    
  }

  number = Serial.parseInt();
  Serial.println(message2 + number);
}*/

// BLINK RED LED ACCORDING TO USER INPUT
/*int numBlinks;
String message = "How many blinks do you want?: ";
int blinkPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);

  while (Serial.available() == 0) {
    
  }

  numBlinks = Serial.parseInt();

  for (int i = 0; i < numBlinks; i++) {
    digitalWrite(blinkPin, HIGH);
    delay(400);
    digitalWrite(blinkPin, LOW);
    delay(400);
  }
}*/

// GET CICLE AREA
float radius;
String message = "What is the radius of your circle: ";
String message2 = "Your circle area is: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);

  while (Serial.available() == 0) {
    
  }

  radius = Serial.parseFloat();
  Serial.println(message2 + 3.14 * radius * radius);
}
