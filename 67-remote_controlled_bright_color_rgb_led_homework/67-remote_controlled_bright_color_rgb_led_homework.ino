/*
  1. Press OK button, RGB LED ON white full bright
  2. Pres OK button when LED ON, turn OFF
  3. Press ONE, turn LED RED
  4. Press TWO, turn LED GREEN
  5. Press THREE, turn LED BLUE
  6. Press FOUR, turn LED CYAN
  7. Press FIVE, turn LED MAGENTA
  8. Press SIX, turn LED YELLOW
  9. Press SEVEN, turn LED ORANGE
  10. Press EIGHT, turn LED LILAC
  11. Press NINE, turn LED BURGUNDY
  12. Press 0, turn LED WHITE
  13. Press DOWN, dimm LED
  14. Press UP brighten LED
  15. Keep brightness value while changing colors with numbers
*/

#include <IRremote.hpp>
#include "IRRemoteCodes.h"

struct Color {
  float red = 0;
  float green = 0;
  float blue = 0;

  Color(float red, float green, float blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }
};

Color colors[] = {
  Color(255, 255, 255), // WHITE
  Color(255, 0, 0),     // RED
  Color(0, 255, 0),     // GREEN
  Color(0, 0, 255),     // BLUE
  Color(0, 255, 255),   // CYAN
  Color(255, 0, 255),   // MAGENTA
  Color(255, 100, 0),   // YELLOW
  Color(255, 20, 0),    // ORANGE
  Color(255, 50, 150),  // LILAC
  Color(112, 180, 45),  // AQUAMARINE
  Color(0, 0, 0)        // OFF
};

enum ColorIndex {
  WHITE,
  RED,
  GREEN,
  BLUE,
  CYAN,
  MAGENTA,
  YELLOW,
  ORANGE,
  LILAC,
  AQUAMARINE,
  OFF
};

int redPin = 5, greenPin = 6, bluePin = 9, selectedColorIndex = 0;
float dimmFactor = 1;
bool isOn = false;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode() && IrReceiver.decodedIRData.numberOfBits > 0) {
    handleRemoteCommand(IrReceiver.decodedIRData);
  }
  IrReceiver.resume();
  delay(50);
}

void setColor(ColorIndex index, bool shouldOverride = false) {
  if (!isOn && !shouldOverride) { return; }
  
  analogWrite(redPin, colors[index].red * dimmFactor);
  analogWrite(greenPin, colors[index].green * dimmFactor);
  analogWrite(bluePin, colors[index].blue * dimmFactor);
}

void handleRemoteCommand(IRData data) {
  bool shouldOverride = false;
  switch (data.command) {
    case ONE:
      selectedColorIndex = RED;
      break;
    case TWO:
      selectedColorIndex = GREEN;
      break;
    case THREE:
      selectedColorIndex = BLUE;
      break;
    case FOUR:
      selectedColorIndex = CYAN;
      break;
    case FIVE:
      selectedColorIndex = MAGENTA;
      break;
    case SIX:
      selectedColorIndex = YELLOW;
      break;
    case SEVEN:
      selectedColorIndex = ORANGE;
      break;
    case EIGHT:
      selectedColorIndex = LILAC;
      break;
    case NINE:
      selectedColorIndex = AQUAMARINE;
      break;
    case ZERO:
      selectedColorIndex = WHITE;
      break;
    case UP:
       dimmFactor = (dimmFactor * 1.75) > 1 ? 1 : dimmFactor * 1.75;
      break;
    case DOWN:
       dimmFactor = (dimmFactor * .75) <= 0.01 ? 0.01 : dimmFactor * .75;
      break;
    case OK:
      selectedColorIndex = isOn ? OFF : WHITE;
      shouldOverride = true;
      dimmFactor = 1;
      isOn = !isOn;
      break;
  }

  setColor(selectedColorIndex, shouldOverride);
}
