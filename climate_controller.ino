#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include "MHZ19.h"

#define RXD2 16
#define TXD2 17

#define DHTPIN 18
#define DHTTYPE DHT22

#define MHZ19_RX_PIN 16
#define MHZ19_TX_PIN 17

DHT dht(DHTPIN, DHTTYPE);
MHZ19 myMHZ19;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  myMHZ19.begin(MHZ19_RX_PIN, MHZ19_TX_PIN);

  dht.begin();

  Wire.begin(21, 22);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  myMHZ19.setRange(2000);
  myMHZ19.setAutoCalibration();
  myMHZ19.setFilter(false);

  int co2 = myMHZ19.getCO2();

  Serial.printf("Temperature: %.2f °C\n", temperature);
  Serial.printf("Humidity: %.2f %%\n", humidity);
  Serial.printf("CO2: %d ppm\n", co2);

  delay(1000);
}

У меня будет свой бордель с блек джеком и шлюхами