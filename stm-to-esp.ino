#include <DHT.h>

#define DHTPIN PA10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // UART to ESP32
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (!isnan(hum) && !isnan(temp)) {
    Serial.print(temp);
    Serial.print(",");
    Serial.println(hum);
  }

  delay(2000);
}
