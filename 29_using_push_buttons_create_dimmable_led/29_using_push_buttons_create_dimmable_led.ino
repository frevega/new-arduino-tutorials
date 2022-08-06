int dimmUpPin = 6;
int dimmDownPin = 7;
int ledPin = 9;
int buzzPin = 10;

int dimmUpValue = 0;
int dimmDownValue = 0;

const int MAX_BRIGHT = 255;
const int MIN_BRIGHT = 0;

int ledBright = 0;

void setup() {
  pinMode(dimmUpPin, INPUT);
  pinMode(dimmDownPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  dimmUpValue = digitalRead(dimmUpPin);
  dimmDownValue = digitalRead(dimmDownPin);
  
  /*Serial.print("Dimm up button: ");
  Serial.println(dummUpValue);
  Serial.print("Dimm down button: ");
  Serial.println(dummDownValue);*/

  // Increase bright
  dimm(dimmUpPin, dimmUpValue);

  // Decrease bright
  dimm(dimmDownPin, dimmDownValue);

  if (ledBright == MAX_BRIGHT) {
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    delay(100);
  }
}

void dimm(int pin, int pinValue) {
  //Serial.println("calling dimm");
  if (pinValue == 0) {
    if (pin == dimmUpPin && ledBright < MAX_BRIGHT) {
      ledBright += 5;
    } else if (pin == dimmDownPin && ledBright > MIN_BRIGHT) { 
      ledBright -= 5;
    }
    Serial.println(ledBright);

    analogWrite(ledPin, ledBright);
    delay(50);
  }
}
