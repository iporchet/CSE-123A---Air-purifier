#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H

#include <Arduino.h>

// Initialize PWM channels for both fans
void fan_init();

// Set both fans to the same duty cycle (0-255)
void fan_set_speed(uint8_t dutyCycle);

// Determine and apply fan speed based on PM2.5 reading
// Uses EPA AQI thresholds from config.h
// Returns the duty cycle that was applied
uint8_t fan_auto_speed(float pm2_5);

// Get the current duty cycle (0-255)
uint8_t fan_get_speed();

#endif // FAN_CONTROL_H
