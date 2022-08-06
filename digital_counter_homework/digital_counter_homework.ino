int leds[] = {5, 6, 7, 8, 9};
int LED0 = 5;
int LED1 = 6;
int LED2 = 7;
int LED3 = 8;
int LED4 = 9;

int binaryValues[][5] = {
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 1},
  {0, 0, 1, 1, 0},
  {0, 0, 1, 1, 1},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 1},
  {0, 1, 1, 0, 0},
  {0, 1, 1, 0, 1},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 1, 1},
  {1, 0, 1, 0, 0},
  {1, 0, 1, 0, 1},
  {1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1},
  {1, 1, 0, 0, 0},
  {1, 1, 0, 0, 1},
  {1, 1, 0, 1, 0},
  {1, 1, 0, 1, 1},
  {1, 1, 1, 0, 0},
  {1, 1, 1, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1}
};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < sizeof(leds); i++) {
    pinMode(leds[i], OUTPUT);
  }
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rowLenght = sizeof(binaryValues) / sizeof(binaryValues[0]);
  int columnLenght = sizeof(binaryValues[0]) / sizeof(binaryValues[0][0]);
  
  //Serial.println(rowLenght);
  //Serial.println(columnLenght);
  
  for (int i = 0; i < rowLenght; i++) {
    for (int j = 0; j < columnLenght; j++) {
      digitalLight(binaryValues[i]);
    }
    //Serial.println();
  }
}

void digitalLight(int values[]) {
  digitalWrite(LED0, values[0] == 0 ? LOW : HIGH);
  digitalWrite(LED1, values[1] == 0 ? LOW : HIGH);
  digitalWrite(LED2, values[2] == 0 ? LOW : HIGH);
  digitalWrite(LED3, values[3] == 0 ? LOW : HIGH);
  digitalWrite(LED4, values[4] == 0 ? LOW : HIGH);
  delay(200);
}
