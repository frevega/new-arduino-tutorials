// https://github.com/Arduino-IRremote/Arduino-IRremote

#include <IRremote.hpp>

IRData data;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  Serial.println(IrReceiver.decodedIRData.numberOfBits);
  if (IrReceiver.decode() && IrReceiver.decodedIRData.numberOfBits > 0) {
    data = IrReceiver.decodedIRData;
    Serial.print(data.decodedRawData, HEX); // Print "old" raw data
    Serial.print(" ");
    Serial.println(data.command);
    /* USE NEW 3.x FUNCTIONS */
    //IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    //IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
  }
  IrReceiver.resume();
}
