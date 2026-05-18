#include "keypad.h"
#include "gpio.h"

uint8_t keypad(GPIO_t *GPIO) {
    // Deactivate all rows
    GPIO->BSR = (0xF << 4);

    for (int row = 0; row < 4; row++) {
        // Activate row
        GPIO->BCR = 1 << (row + 4);
        // pin update speed set to 2 MHz
        // => need to wait for 500 ns before reading columns
        // but can't overwrite systick, so we'll waste time with an empty loop
        for (int i = 0; i < 100; i++)
            ;

        // If column is active, activate all rows and return key index
        for (int col = 0; col < 4; col++) {
            if ((GPIO->INDR & (1 << col)) == 0) {
                GPIO->BCR = 0xF << 4;
                return 4 * row + col;
            }
        }
    }
    // No key pressed. Activate all rows and return error code
    GPIO->BCR = (0xF << 4);
    return 0xFF;
}
