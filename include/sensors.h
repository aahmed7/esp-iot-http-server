#ifndef SENSORS_H
#define SENSORS_H

/* Pin Definitions. */
#define LED_BUILTIN 2
#define PIN_VP      36

/* Function Prototypes. */
void ledInit(int pin);
void ledOn(int pin);
void ledOff(int pin);
int  readADC(int pin);

#endif