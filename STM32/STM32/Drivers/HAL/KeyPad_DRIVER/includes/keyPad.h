#ifndef KEYPAD_h
#define KEYPAD_h

#include "GPIO.h"
typedef enum
{
    Keypad_1,
    keypad_2
} KeypadNum_t;

typedef enum
{
    KEY_NOT_PRESSED,
    KEY_PRESSED
} KeyStatus_t;

/* Write default state to rows pins*/
void KeyPad_init();

/* Get Key pressed or not and key row and colum */
KeyStatus_t GetKeyPressed(uint8_t *row, uint8_t *colum);

#endif
