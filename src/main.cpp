#include <Arduino.h>
#include <debug_print.h>
#include <sensors.h>
#include <webserver.h>

#define LED_PIN LED_BUILTIN

#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

/* WiFi Credentials. */
const char* ssid = "Xiaomi_7E1B";
const char* password = "bonefire5628";

void setup_wifi() {
    /* Connect to WiFi. */
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    DEBUG_STATUS("Connected to the WiFi network");

    // Print local IP address and start web server
    DEBUG_STATUS("");
    DEBUG_STATUS("WiFi connected.");
    DEBUG_STATUS("IP address: ");
    DEBUG_STATUS(WiFi.localIP());
}

void setup() {
    Serial.begin(115200);
    DEBUG_STATUS("TESTING SERIAL PRINT...");
    ledInit(LED_PIN);

    setup_wifi();
    restServerRouting();
}

void loop() { delay(10); }
