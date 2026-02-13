#include "fan_control.h"
#include "config.h"

static uint8_t currentSpeed = 0;

void fan_init() {
    ledcSetup(FAN_PWM_CHANNEL_1, FAN_PWM_FREQ, FAN_PWM_RESOLUTION);
    ledcSetup(FAN_PWM_CHANNEL_2, FAN_PWM_FREQ, FAN_PWM_RESOLUTION);
    ledcAttachPin(FAN1_PWM_PIN, FAN_PWM_CHANNEL_1);
    ledcAttachPin(FAN2_PWM_PIN, FAN_PWM_CHANNEL_2);

    Serial.println("Fan PWM initialized (25kHz, 8-bit)");
}

void fan_set_speed(uint8_t dutyCycle) {
    currentSpeed = dutyCycle;
    ledcWrite(FAN_PWM_CHANNEL_1, dutyCycle);
    ledcWrite(FAN_PWM_CHANNEL_2, dutyCycle);
}

uint8_t fan_auto_speed(float pm2_5) {
    uint8_t speed;

    if (pm2_5 <= AQ_GOOD) {
        speed = FAN_OFF;
    } else if (pm2_5 <= AQ_MODERATE) {
        speed = FAN_LOW;
    } else if (pm2_5 <= AQ_UNHEALTHY_SG) {
        speed = FAN_MEDIUM;
    } else if (pm2_5 <= AQ_UNHEALTHY) {
        speed = FAN_HIGH;
    } else {
        speed = FAN_MAX;
    }

    fan_set_speed(speed);
    return speed;
}

uint8_t fan_get_speed() {
    return currentSpeed;
}
