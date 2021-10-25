#include <Arduino.h>
#include <debug_print.h>
#include <sensors.h>

/************************************************************************
 *
 * Function:  ledInit
 * --------------------
 *  Sets pin mode for led.
 *
 *  pin: pin of the led
 *
 *  returns: none
 *
 ************************************************************************/
void ledInit(int pin) {
    DEBUG_STATUS("SETTING PIN MODE FOR LED.");
    pinMode(pin, OUTPUT);
}

/************************************************************************
 *
 * Function:  ledOff
 * --------------------
 *  Turns off the led.
 *
 *  pin: pin of the led
 *
 *  returns: none
 *
 ************************************************************************/
void ledOn(int pin) {
    DEBUG_MESSAGE("TURNING ON LED.");
    digitalWrite(pin, HIGH);
}

/************************************************************************
 *
 * Function:  ledOff
 * --------------------
 *  Turns off the led.
 *
 *  pin: pin of the led
 *
 *  returns: none
 *
 ************************************************************************/
void ledOff(int pin) {
    DEBUG_MESSAGE("TURNING OFF LED.");
    digitalWrite(pin, LOW);
}

/************************************************************************
 *
 * Function:  ledOff
 * --------------------
 *  Turns off the led.
 *
 *  pin: pin of the led
 *
 *  returns: none
 *
 ************************************************************************/
int readADC(int pin) {
    DEBUG_MESSAGE("READING ADC.");
    return analogRead(pin);
}