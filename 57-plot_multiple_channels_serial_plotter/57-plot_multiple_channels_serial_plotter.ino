float parab1 = 0, parab2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sinGraph();
  parabGraph();
  parabSinGraph();
}

void sinGraph() {
  for (float j = 0; j <=  (2 * 3.1416); j += 0.01) {
    Serial.print(sin(j) + 2);
    Serial.print(",");
    Serial.println(cos(j * 10));
  }
}

void parabGraph() {
  for (float j = -4; j <=  4; j += 0.01) {
    Serial.print(j * j);
    Serial.print(",");
    Serial.println(-(j * j));
  }
}


void parabSinGraph() {
  for (float j = -4; j <=  4; j += 0.01) {
    Serial.print(j * j);
    Serial.print(",");
    Serial.println(j * j * sin(j));
  }
}
