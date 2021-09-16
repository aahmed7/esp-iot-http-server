#include <Arduino.h>
#include <debug_print.h>
#include <sensors.h>

#define LED_PIN LED_BUILTIN

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

/* WiFi Credentials. */
const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASS";

void setup() {
    Serial.begin(115200);
    DEBUG_STATUS("TESTING SERIAL PRINT...");
    ledInit(LED_PIN);

    setup_wifi();
}

void loop() {
    ledOn(LED_PIN);
    delay(500);
    ledOff(LED_PIN);
    delay(500);
}

void setup_wifi() {
    /* Connect to WiFi. */
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");
}