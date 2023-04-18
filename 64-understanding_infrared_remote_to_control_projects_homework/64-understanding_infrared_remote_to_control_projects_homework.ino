// https://github.com/Arduino-IRremote/Arduino-IRremote

#include <IRremote.hpp>
#include "IRRemoteCodes.h"

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode() && IrReceiver.decodedIRData.numberOfBits > 0) {
    valueFor(IrReceiver.decodedIRData);
  }
  IrReceiver.resume();
  delay(50);
}

void valueFor(IRData data) {
  switch (data.command) {
    case ONE:
      Serial.println("ONE");
    break;
    case TWO:
      Serial.println("TWO");
    break;
    case THREE:
      Serial.println("THREE");
    break;
    case FOUR:
      Serial.println("FOUR");
    break;
    case FIVE:
      Serial.println("FIVE");
    break;
    case SIX:
      Serial.println("SIX");
    break;
    case SEVEN:
      Serial.println("SEVEN");
    break;
    case EIGHT:
      Serial.println("EIGHT");
    break;
    case NINE:
      Serial.println("NINE");
    break;
    case ASTERISK:
      Serial.println("ASTERISK");
    break;
    case ZERO:
      Serial.println("ZERO");
    break;
    case HASH:
      Serial.println("HASH");
    break;
    case UP:
      Serial.println("UP");
    break;
    case DOWN:
      Serial.println("DOWN");
    break;
    case LEFT:
      Serial.println("LEFT");
    break;
    case RIGHT:
      Serial.println("RIGHT");
    break;
    case OK:
      Serial.println("OK");
    break;
  }
}
