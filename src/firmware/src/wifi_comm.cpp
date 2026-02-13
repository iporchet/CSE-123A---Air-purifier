#include "wifi_comm.h"
#include "config.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

bool wifi_init() {
    Serial.printf("Connecting to WiFi: %s", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 10) {
        delay(WIFI_RETRY_DELAY_MS);
        Serial.print(".");
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.printf("\nWiFi connected! IP: %s\n", WiFi.localIP().toString().c_str());
        return true;
    }

    Serial.println("\nWiFi connection failed");
    return false;
}

bool wifi_is_connected() {
    return WiFi.status() == WL_CONNECTED;
}

int wifi_send_data(const SensorData& data, uint8_t fanSpeed) {
    if (!wifi_is_connected()) {
        return -1;
    }

    HTTPClient http;
    String url = String("http://") + SERVER_HOST + ":" + String(SERVER_PORT) + SENSOR_ENDPOINT;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    // Build JSON payload
    JsonDocument doc;
    doc["pm1_0"]       = data.pm1_0;
    doc["pm2_5"]       = data.pm2_5;
    doc["pm4_0"]       = data.pm4_0;
    doc["pm10_0"]      = data.pm10_0;
    doc["humidity"]     = data.humidity;
    doc["temperature"]  = data.temperature;
    doc["voc_index"]    = data.vocIndex;
    doc["fan_speed"]    = fanSpeed;
    doc["timestamp"]    = (unsigned long)(millis() / 1000);

    String payload;
    serializeJson(doc, payload);

    int httpCode = http.POST(payload);

    if (httpCode > 0) {
        Serial.printf("HTTP POST: %d\n", httpCode);
        // TODO: Parse response for fan override commands
        // String response = http.getString();
        // JsonDocument resDoc;
        // deserializeJson(resDoc, response);
        // if (resDoc.containsKey("command")) { ... }
    } else {
        Serial.printf("HTTP POST failed: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
    return httpCode;
}
