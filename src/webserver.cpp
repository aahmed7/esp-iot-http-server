// https://www.mischianti.org/2020/05/24/rest-server-on-esp8266-and-esp32-get-and-json-formatter-part-2/

#include <Arduino.h>
#ifdef ESP32
#include <AsyncTCP.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Serving Hello world
void getHelloWord(AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", "{\"name\": \"Hello world\"}");
}

// Serving Settings
void getSettings(AsyncWebServerRequest *request) {
    String responseStr = "{";

    responseStr += "\"ip\": \"" + WiFi.localIP().toString() + "\"";
    responseStr += ",\"gw\": \"" + WiFi.gatewayIP().toString() + "\"";
    responseStr += ",\"nm\": \"" + WiFi.subnetMask().toString() + "\"";

    // <esp-ip>/settings?signalStrength
    if (request->hasParam("signalStrength")) {
        responseStr += ",\"signalStrengh\": \"" + String(WiFi.RSSI()) + "\"";
    }

    // <esp-ip>/settings?chipInfo
    if (request->hasParam("chipInfo")) {
        responseStr += ",\"chipId\": \"" + String(ESP.getChipModel()) + "\"";
        responseStr += ",\"flashChipId\": \"" + String(ESP.getFlashChipSize()) + "\"";
        responseStr += ",\"flashChipSize\": \"" + String(ESP.getFlashChipSize()) + "\"";
        responseStr +=
            ",\"flashChipRealSize\": \"" + String(ESP.getFlashChipSize()) + "\"";
    }

    // <esp-ip>/settings?freeHeap
    if (request->hasParam("freeHeap")) {
        responseStr += ",\"freeHeap\": \"" + String(ESP.getFreeHeap()) + "\"";
    }
    responseStr += "}";

    request->send_P(200, "text/html", responseStr.c_str());
}

// Define routing
void restServerRouting() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", "Welcome to the REST Web Server");
    });
    server.on("/hello", HTTP_GET, getHelloWord);
    server.on("/settings", HTTP_GET, getSettings);

    // Start server
    server.begin();
}

// Manage not found URL
void handleNotFound(AsyncWebServerRequest *request) {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += request->url();
    message += "\nMethod: ";
    message += (request->method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += request->getParam("")->value();
    message += "\n";

    // List all parameters (Compatibility)
    int args = request->args();
    for (int i = 0; i < args; i++) {
        message += "ARG[%s]: %s\n", request->argName(i).c_str(), request->arg(i).c_str();
    }

    request->send_P(404, "text/plain", message.c_str());
}
