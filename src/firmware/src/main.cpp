#include <Arduino.h>
#include "config.h"
#include "sensor.h"
#include "fan_control.h"
#include "wifi_comm.h"

// Timing trackers
static unsigned long lastSensorRead = 0;
static unsigned long lastDataSend   = 0;

// Latest sensor reading
static SensorData latestData;

// Fan mode: false = auto (default), true = manual override from server
static bool manualMode = false;
static uint8_t manualFanSpeed = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("=== Smart Air Purifier - ESP32-C3 ===");

    // 1. Initialize SEN54 sensor (I2C)
    if (!sensor_init()) {
        Serial.println("FATAL: SEN54 init failed. Halting.");
        while (true) { delay(1000); }
    }

    // 2. Initialize fan PWM channels
    fan_init();
    fan_set_speed(FAN_OFF);

    // 3. Connect to WiFi
    if (!wifi_init()) {
        Serial.println("WARNING: WiFi failed. Running in offline mode.");
    }

    Serial.println("Setup complete. Entering main loop.");
}

void loop() {
    unsigned long now = millis();

    // --- Read sensor at configured interval ---
    if (now - lastSensorRead >= SENSOR_READ_INTERVAL_MS) {
        lastSensorRead = now;
        latestData = sensor_read();

        if (latestData.valid) {
            sensor_print(latestData);

            // Auto-adjust fan speed based on PM2.5 (unless manual override)
            if (!manualMode) {
                uint8_t speed = fan_auto_speed(latestData.pm2_5);
                Serial.printf("Fan auto speed: %d/255\n", speed);
            }
        }
    }

    // --- Send data to RPi4 server at configured interval ---
    if (now - lastDataSend >= DATA_SEND_INTERVAL_MS) {
        lastDataSend = now;

        if (wifi_is_connected() && latestData.valid) {
            int httpCode = wifi_send_data(latestData, fan_get_speed());

            if (httpCode == 200) {
                // TODO: Parse response body for fan override commands
                // If command present, set manualMode and manualFanSpeed
            }
        } else if (!wifi_is_connected()) {
            // TODO: Attempt reconnection
            Serial.println("WiFi disconnected. Data not sent.");
        }
    }
}
