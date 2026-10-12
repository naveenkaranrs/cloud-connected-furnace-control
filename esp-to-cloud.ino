#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "FURNACE TRACKER"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

// Uncomment this line for Serial debug output
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// DHT11 Setup
#define DHTPIN 4       // GPIO4 (D4 pin on NodeMCU-32S)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Blynk Virtual Pins
#define VPIN_TEMP V0
#define VPIN_HUMI V1
#define VPIN_STATUS V2

// Fan control pin
#define FAN_PIN 5      // GPIO5 → controls relay/fan

// Thresholds
#define TEMP_THRESHOLD 35.0    // °C
#define HUM_THRESHOLD 70.0     // %

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  // Set fan pin as OUTPUT and turn OFF initially
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
}

void loop()
{
  Blynk.run();
  readAndSendData();
  delay(3000); // Read every 3 seconds
}

void readAndSendData()
{
  float temp = dht.readTemperature();  // °C
  float hum = dht.readHumidity();

  // Check if DHT11 gives valid readings
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Humidity: ");
  Serial.print(hum);
  Serial.print(" %");

  // Determine status and control fan
  String status;
  if (temp > TEMP_THRESHOLD || hum > HUM_THRESHOLD) {
    status = "Abnormal";
    digitalWrite(FAN_PIN, HIGH);  // Turn fan ON
  } else {
    status = "Normal";
    digitalWrite(FAN_PIN, LOW);   // Turn fan OFF
  }

  Serial.print(" | Status: ");
  Serial.println(status);

  // Send to Blynk Cloud
  Blynk.virtualWrite(VPIN_TEMP, temp);
  Blynk.virtualWrite(VPIN_HUMI, hum);
  Blynk.virtualWrite(VPIN_STATUS, status);
}