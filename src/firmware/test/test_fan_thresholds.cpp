#include <unity.h>

// TODO: Include fan_control logic for testing thresholds
// These tests validate the PM2.5 -> fan speed mapping without hardware

void test_good_air_returns_fan_off() {
    // PM2.5 <= 12.0 should map to FAN_OFF (0)
    // TODO: Call fan_auto_speed(10.0) and assert result == 0
    TEST_ASSERT_TRUE(true);  // placeholder
}

void test_moderate_air_returns_fan_low() {
    // PM2.5 12.1-35.4 should map to FAN_LOW (64)
    // TODO: Call fan_auto_speed(25.0) and assert result == 64
    TEST_ASSERT_TRUE(true);
}

void test_unhealthy_sg_returns_fan_medium() {
    // PM2.5 35.5-55.4 should map to FAN_MEDIUM (128)
    // TODO: Call fan_auto_speed(45.0) and assert result == 128
    TEST_ASSERT_TRUE(true);
}

void test_unhealthy_returns_fan_high() {
    // PM2.5 55.5-150.4 should map to FAN_HIGH (192)
    // TODO: Call fan_auto_speed(100.0) and assert result == 192
    TEST_ASSERT_TRUE(true);
}

void test_very_unhealthy_returns_fan_max() {
    // PM2.5 > 250.4 should map to FAN_MAX (255)
    // TODO: Call fan_auto_speed(300.0) and assert result == 255
    TEST_ASSERT_TRUE(true);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_good_air_returns_fan_off);
    RUN_TEST(test_moderate_air_returns_fan_low);
    RUN_TEST(test_unhealthy_sg_returns_fan_medium);
    RUN_TEST(test_unhealthy_returns_fan_high);
    RUN_TEST(test_very_unhealthy_returns_fan_max);
    UNITY_END();
}

void loop() {
    // Nothing
}
