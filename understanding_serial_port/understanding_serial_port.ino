int j = 1, x = 3, y = 7, z;
float pi = 3.14, r = 2, area;
String myString = "j = ";
String plusString = " + ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //z = x + y;
  //Serial.println(x + plusString + y + " = " + z);
  
  //Serial.println(myString + j);
  //j = j + 1;

  area = pi * r * r;
  Serial.print("area is ");
  Serial.println(area);
  delay(750);
}
