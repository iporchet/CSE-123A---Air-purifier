#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
// Smart Air Purifier - Central Configuration
// ============================================================

// --- WiFi Credentials ---
// TODO: Replace with your actual WiFi credentials
#define WIFI_SSID       "YOUR_WIFI_SSID"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"

// --- RPi4 Server ---
// TODO: Replace with Raspberry Pi's IP on your local network
#define SERVER_HOST     "192.168.1.100"
#define SERVER_PORT     8000
#define SENSOR_ENDPOINT "/api/v1/sensor-data"

// --- I2C Pins for SEN54 ---
// ESP32-C3 default I2C: SDA=GPIO8, SCL=GPIO9
// NOTE: Some C3 boards have boot issues on GPIO8/9.
//       If so, remap to GPIO4 (SDA) and GPIO5 (SCL).
#define I2C_SDA_PIN     8
#define I2C_SCL_PIN     9

// --- Fan PWM Configuration ---
// Arctic P12 Max: 25kHz PWM, 4-pin connector
#define FAN1_PWM_PIN       2       // GPIO2 for Fan 1 PWM
#define FAN2_PWM_PIN       3       // GPIO3 for Fan 2 PWM
#define FAN_PWM_FREQ       25000   // 25 kHz per Arctic spec
#define FAN_PWM_RESOLUTION 8       // 8-bit: duty 0-255
#define FAN_PWM_CHANNEL_1  0
#define FAN_PWM_CHANNEL_2  1

// --- Air Quality Thresholds (PM2.5 in ug/m3) ---
// Based on EPA AQI breakpoints
#define AQ_GOOD            12.0    // Good: 0-12 ug/m3
#define AQ_MODERATE        35.4    // Moderate: 12.1-35.4
#define AQ_UNHEALTHY_SG    55.4    // Unhealthy for Sensitive Groups
#define AQ_UNHEALTHY       150.4   // Unhealthy
#define AQ_VERY_UNHEALTHY  250.4   // Very Unhealthy

// --- Fan Speed Mapping (duty cycle 0-255) ---
#define FAN_OFF     0
#define FAN_LOW     64     // ~25%
#define FAN_MEDIUM  128    // ~50%
#define FAN_HIGH    192    // ~75%
#define FAN_MAX     255    // 100%

// --- Timing ---
#define SENSOR_READ_INTERVAL_MS  1000   // Read sensor every 1 second
#define DATA_SEND_INTERVAL_MS    5000   // Send data to RPi every 5 seconds
#define WIFI_RETRY_DELAY_MS      5000   // Retry WiFi connection every 5 seconds

#endif // CONFIG_H
