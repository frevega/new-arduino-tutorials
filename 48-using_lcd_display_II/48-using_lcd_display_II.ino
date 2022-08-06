#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Watch me count");

  for (size_t i = 1; i <= 10; i++) {
    lcd.setCursor(i < 10 ? 15 : 14, 1);
    lcd.print(i);
    delay(500);
  }

  lcd.clear();
}
