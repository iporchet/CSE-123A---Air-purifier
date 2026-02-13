#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

// Data structure for all SEN54 measurements
struct SensorData {
    float pm1_0;        // PM1.0 concentration (ug/m3)
    float pm2_5;        // PM2.5 concentration (ug/m3)
    float pm4_0;        // PM4.0 concentration (ug/m3)
    float pm10_0;       // PM10.0 concentration (ug/m3)
    float humidity;     // Relative humidity (%)
    float temperature;  // Temperature (Celsius)
    float vocIndex;     // VOC Index (1-500)
    bool  valid;        // false if read error occurred
};

// Initialize I2C bus and SEN54 sensor
// Returns true on success
bool sensor_init();

// Read all measurements from SEN54
// Returns SensorData with valid=false on error
SensorData sensor_read();

// Print sensor data to Serial for debugging
void sensor_print(const SensorData& data);

#endif // SENSOR_H
