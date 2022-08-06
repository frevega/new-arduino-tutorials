#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char *messages[] = {
  "Input 1st number",
  "Input 2nd number",
  "Input +, -, *, /",
  "The answer is"
};

float operators[] = {0, 0};
float result;
byte buffer[1];

String inputString = "";

int i = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  while (true) {
    lcd.setCursor(0, 0);
    lcd.printstr(messages[i]);
    lcd.setCursor(0, 1);

    if (i != 3) {
      lcd.blink_on();

      while (Serial.available() == 0) { }

      if (Serial.available() != 0) {
        inputString = Serial.readString();
        inputString.trim();

        switch (i) {
          case 0: case 1:
            if (inputString.toFloat() == 0) {
              continue;
            }
            operators[i] = inputString.toFloat();
            break;
          case 2:
            //byte buffer[inputString.length() + 1];
            inputString.toCharArray(buffer, inputString.length() + 1);
            result = operation(buffer[0]);
            if (result == NULL) {
              continue;
            }
            break;
        }

        lcd.blink_off();
        lcd.print(inputString);
      }
    } else {
      lcd.blink_off();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(operators[0]);
      lcd.print(char(buffer[0]));
      lcd.print(operators[1]);
      lcd.setCursor(0, 1);
      lcd.print("= ");
      lcd.print(result);
    }

    delay(i < 3 ? 1000 : 5000);
    lcd.clear();

    i = (i == 3) ? 0 : i += 1;
  }
}

float operation(char operation) {
  switch (operation) {
    case '+':
      return operators[0] + operators[1];
      break;
    case '-':
      return operators[0] - operators[1];
      break;
    case '*':
      return operators[0] * operators[1];
      break;
    case '/':
      return operators[0] / operators[1];
      break;
    default:
      return NULL;
      break;
  }
}
