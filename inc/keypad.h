#ifndef KEYPAD_H
#define KEYPAD_H

#include "gpio.h"
#include <stdint.h>

// Function prototypes

// Read keypad (GPIO [0:7])
// Returns key index if a key is pressed, otherwise error code 0xFF
uint8_t keypad(GPIO_t *GPIO);

#endif
