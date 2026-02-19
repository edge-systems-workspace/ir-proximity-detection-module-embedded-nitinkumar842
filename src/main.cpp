#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author Nitin Kumar
 * @date 2026-02-18
 *
 * @details
 * Reads digital input from IR sensor
 * and detects obstacle presence.
 * Provide lightweight stubs for editors/linters that can't resolve Arduino symbols.
 * These are only used when the ARDUINO macro is not defined (i.e., not a real build)
  */
#ifndef ARDUINO
// Pin modes
#define INPUT 0
#define OUTPUT 1
// Digital levels
#define LOW 0
#define HIGH 1

inline void pinMode(int, int) {}
inline int digitalRead(int) { return HIGH; }
inline void digitalWrite(int, int) {}

struct _SerialStub {
    void begin(unsigned long) {}
    void println(const char*) {}
} Serial;

inline void delay(unsigned long) {}
#endif

#define IR_PIN 2
#define LED_PIN 13

void setup() {
    pinMode(IR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int irState = digitalRead(IR_PIN);

    if (irState == LOW) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Object Detected!");
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(100);
}