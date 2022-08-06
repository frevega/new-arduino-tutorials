int ledPin = 8;
int buttonPin = 12; 
int ledState = 1;   
int buttonValue = 0;         
int previousButtonValue = 0;    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  toggleLed();
}

void toggleLed() {
  buttonValue = digitalRead(buttonPin);
  if (buttonValue != previousButtonValue) {
    if (buttonValue == 1) {
      Serial.println(ledState);
      ledState = (ledState + 1) % 2;
      
      Serial.print("Led state: ");
      Serial.println(ledState);// == HIGH ? "ON" : "OFF");
    } else {
      Serial.println("Button value 0");
    }
  
    digitalWrite(ledPin, ledState);
    delay(50);
  }
  
  previousButtonValue = buttonValue;
}
