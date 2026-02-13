#ifndef WIFI_COMM_H
#define WIFI_COMM_H

#include <Arduino.h>
#include "sensor.h"

// Connect to WiFi network
// Blocks until connected or timeout (~10 retries)
// Returns true on success
bool wifi_init();

// Check if WiFi is currently connected
bool wifi_is_connected();

// Send sensor data + fan speed as JSON via HTTP POST to RPi4
// Returns HTTP response code (200 = success, -1 = error)
int wifi_send_data(const SensorData& data, uint8_t fanSpeed);

#endif // WIFI_COMM_H
