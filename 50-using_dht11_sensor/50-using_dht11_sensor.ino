#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);
float humidity = 0, celcius = 0, fahrenheit = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);
  humidity = dht.readHumidity();
  celcius = dht.readTemperature();
  fahrenheit = dht.readTemperature(true);

  if (isnan(humidity) || isnan(celcius) || isnan(fahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temperature: ");
  Serial.print(celcius);
  Serial.print("ºC - ");
  Serial.print(fahrenheit);
  Serial.println("ºF");
}
