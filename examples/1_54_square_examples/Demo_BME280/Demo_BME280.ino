/*
 * To Read Temperature, Pressure and Humidity with onboard BME280 Sensor
 * 
 */
#include <Adafruit_BME280.h>

// Replace with your I2C SDA and SCL pin numbers
#define SDA_PIN 38
#define SCL_PIN 39

// Create BME280 sensor object
Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  // Begin I2C communication
  Wire.begin(SDA_PIN, SCL_PIN);

  // Check BME280 sensor connection
  if (!bme.begin(0x76)) {  // Address might differ (check datasheet)
    Serial.println("Could not find BME280 sensor!");
    while (1) delay(10);
  }

  // Set sensor sampling (adjust if needed)
  bme.setSampling(Adafruit_BME280::MODE_NORMAL, Adafruit_BME280::SAMPLING_X1, Adafruit_BME280::SAMPLING_X1, Adafruit_BME280::SAMPLING_X1);
}

void loop() {
  // Read temperature as Celsius (modify for Fahrenheit if needed)
  float temperature = bme.readTemperature();
  // Read pressure as Pa (modify for other units if needed)
  float pressure = bme.readPressure();
  // Read humidity as %
  float humidity = bme.readHumidity();

  // Print sensor readings to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Adjust delay between readings as needed
}
