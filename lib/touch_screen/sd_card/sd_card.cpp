#include "sd_card.h"

void readSensorData(SensorData& data) {
  // Code to read sensor data goes here
}

void logSensorData(const SensorData& data) {
  File file = SD.open("data.log", FILE_WRITE);
  if (file) {
    file.print(data.temperature);
    file.print(",");
    file.print(data.humidity);
    file.print(",");
    file.println(data.co2);
    file.close();
  }
}

void readAndLogSensorData() {
  SensorData data;
  readSensorData(data);
  logSensorData(data);
}

void readAndLogSensorDataWithMemoryOptimization() {
  static std::vector<SensorData> buffer;
  if (buffer.size() == buffer.capacity()) {
    esp_err_t err = heap_caps_trim(MALLOC_CAP_DEFAULT, 0);
    if (err != ESP_OK) {
      // Error handling code goes here
    }
    for (const auto& data : buffer) {
      logSensorData(data);
    }
    buffer.clear();
  }
  SensorData data;
  readSensorData(data);
  buffer.push_back(data);
}

void loop() {
  readAndLogSensorDataWithMemoryOptimization();
}
