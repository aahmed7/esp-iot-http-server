#ifndef SENSORS_H
#define SENSORS_H

/* Pin Definitions. */
#define LED_BUILTIN 2

/* Function Prototypes. */
void ledInit(int pin);
void ledOn(int pin);
void ledOff(int pin);

#endif