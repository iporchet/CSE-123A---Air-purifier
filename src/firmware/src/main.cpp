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
    
}
