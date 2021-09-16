#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#define DEBUG         1
#define SHOW_MESSAGES 1

#if DEBUG == 1
#define DEBUG_STATUS(...) Serial.println(__VA_ARGS__)
#else
#define DEBUG_STATUS(...) void()
#endif

#if SHOW_DATA_SERIAL == 1
#define DATA(...) Serial.println(__VA_ARGS__)
#else
#define DATA(...) void()
#endif

#if SHOW_MESSAGES == 1
#define DEBUG_MESSAGE(...) Serial.print(__VA_ARGS__)
#define NEWLINE            Serial.println()
#else
#define DEBUG_MESSAGE(...) void()
#define NEWLINE            void()
#endif

#endif
