#include <LiquidCrystal_I2C.h>

char *arrays[] = {
  " SUNFOUNDER",//29 chars
  "Hello, World!"
};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(16, 0);
  for (size_t j = 0; j < strlen(arrays[0]); j++) {
    lcd.scrollDisplayLeft();
    lcd.print(arrays[0][j]);
    delay(250);
  }

  lcd.setCursor(20, 1);
  for (size_t j = 0; j < strlen(arrays[1]); j++) {
    lcd.scrollDisplayLeft();
    lcd.print(arrays[1][j]);
    delay(250);
  }

  // Unccomment to display only one line at time
  //lcd.clear();
}

void lloop() {
  for (size_t i = 0; i < sizeof(arrays) / sizeof(arrays[0]); i++) {
    lcd.setCursor(16, i);

    for (size_t j = 0; j < strlen(arrays[i]); j++) {
      lcd.scrollDisplayLeft();
      lcd.print(arrays[i][j]);
      delay(250);
    }

    // Unccomment to display only one line at time
    //lcd.clear();
  }
}
