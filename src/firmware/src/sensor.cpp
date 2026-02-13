#include "sensor.h"
#include "config.h"
#include <Wire.h>
#include <SensirionI2CSen5x.h>

static SensirionI2CSen5x sen5x;

bool sensor_init() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    sen5x.begin(Wire);

    // Reset the sensor to a known state
    uint16_t error = sen5x.deviceReset();
    if (error) {
        Serial.println("ERROR: SEN54 deviceReset() failed");
        return false;
    }

    // Wait for sensor to be ready after reset
    delay(1000);

    // Start continuous measurement mode
    error = sen5x.startMeasurement();
    if (error) {
        Serial.println("ERROR: SEN54 startMeasurement() failed");
        return false;
    }

    Serial.println("SEN54 initialized successfully");
    return true;
}

SensorData sensor_read() {
    SensorData data = {};
    data.valid = false;

    float pm1p0, pm2p5, pm4p0, pm10p0;
    float humidity, temperature;
    float vocIndex, noxIndex;

    uint16_t error = sen5x.readMeasuredValues(
        pm1p0, pm2p5, pm4p0, pm10p0,
        humidity, temperature, vocIndex, noxIndex
    );

    if (error) {
        Serial.println("ERROR: SEN54 readMeasuredValues() failed");
        return data;
    }

    data.pm1_0       = pm1p0;
    data.pm2_5       = pm2p5;
    data.pm4_0       = pm4p0;
    data.pm10_0      = pm10p0;
    data.humidity     = humidity;
    data.temperature  = temperature;
    data.vocIndex     = vocIndex;  // noxIndex discarded (SEN54 has no NOx sensor)
    data.valid        = true;

    return data;
}

void sensor_print(const SensorData& data) {
    if (!data.valid) {
        Serial.println("Sensor data invalid");
        return;
    }

    Serial.printf("PM1.0: %.1f | PM2.5: %.1f | PM4.0: %.1f | PM10: %.1f ug/m3\n",
                  data.pm1_0, data.pm2_5, data.pm4_0, data.pm10_0);
    Serial.printf("Temp: %.1f C | Humidity: %.1f%% | VOC: %.0f\n",
                  data.temperature, data.humidity, data.vocIndex);
}
