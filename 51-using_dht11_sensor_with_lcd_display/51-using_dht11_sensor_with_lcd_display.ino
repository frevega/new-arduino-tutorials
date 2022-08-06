#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTTYPE DHT11
#define DHTPIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
float humidity = 0, celcius = 0, fahrenheit = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  delay(1000);
  humidity = dht.readHumidity();
  celcius = dht.readTemperature();
  fahrenheit = dht.readTemperature(true);

  if (isnan(humidity) || isnan(celcius) || isnan(fahrenheit)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temperature: ");
  Serial.print(celcius);
  Serial.print("ºC - ");
  Serial.print(fahrenheit);
  Serial.println("ºF");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(celcius);
  lcd.print("C/");
  lcd.print(fahrenheit);
  lcd.print("F");
}
