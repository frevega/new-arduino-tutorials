int redPin = 9, greenPin = 10, bluePin = 11;

struct Color {
  int red = 0;
  int green = 0;
  int blue = 0;
}
redColor,
greenColor,
blueColor,
cyanColor,
magentaColor,
yellowColor,
orangeColor,
offColor,
fuchsiaColor,
colors[8];

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  prepareColors();
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLed();
}

void lightLed() {
  for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
    analogWrite(redPin, colors[i].red);
    analogWrite(greenPin, colors[i].green);
    analogWrite(bluePin, colors[i].blue);
    delay(1000);
  }
}

void prepareColors() {
  redColor.red = 255;
  greenColor.green = 255;
  blueColor.blue = 255;
  cyanColor.green = 255;
  cyanColor.blue = 255;
  magentaColor.red = 255;
  magentaColor.blue = 255;
  yellowColor.red = 255;
  yellowColor.green = 100;
  orangeColor.red = 255;
  orangeColor.blue = 165;
  fuchsiaColor.red = 217;
  fuchsiaColor.green = 2;
  fuchsiaColor.blue = 125;

  colors[0] = redColor;
  colors[1] = greenColor;
  colors[2] = blueColor;
  colors[3] = cyanColor;
  colors[4] = magentaColor;
  colors[5] = yellowColor;
  colors[6] = offColor;
  colors[7] = fuchsiaColor;

  return colors;
}

/*red
  green
  blue
  cyan 0, 255, 255
  magenta 255, 0, 255
  yellow 255, 255, 0
  orange 255, 165, 0
  off
  fuchsia 217, 2 125*/
