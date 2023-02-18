#ifndef SD_CARD_H
#define SD_CARD_H

#include <SD.h>
#include <SPI.h>
#include <vector>
#include "esp_heap_caps.h"

struct SensorData {
  float temperature;
  float humidity;
  int co2;
};

void readSensorData(SensorData& data);
void logSensorData(const SensorData& data);
void readAndLogSensorData();
void readAndLogSensorDataWithMemoryOptimization();
void loop();

#endif
