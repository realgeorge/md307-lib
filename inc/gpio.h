#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// GPIO base addresses
#define GPIO_A_BASE 0x40010800
#define GPIO_B_BASE 0x40010C00
#define GPIO_C_BASE 0x40011000
#define GPIO_D_BASE 0x40011400
#define GPIO_E_BASE 0x40011800

// GPIO pointer macros
#define GPIO_CFGLR(x) ((volatile uint32_t *)(x + 0x00))
#define GPIO_CFGHR(x) ((volatile uint32_t *)(x + 0x04))
#define GPIO_IDR(x)   ((volatile uint16_t *)(x + 0x08))
#define GPIO_ODR(x)   ((volatile uint16_t *)(x + 0x0C))
#define GPIO_BSR(x)   ((volatile uint16_t *)(x + 0x10))
#define GPIO_BCR(x)   ((volatile uint16_t *)(x + 0x14))
#define GPIO_LCKR(x)  ((volatile uint32_t *)(x + 0x18))



// GPIO struct and accompanying pointers
typedef struct {
    union {
        /* Port configuration register low (pin[7:0])

        To configure multiple pins at once write the corresponding
        hexadecimal configuration values in the form of 16-bit to
        the CFGLR register.

        #### The two lower bits for each pin byte configures MODE:
        - 00: Input mode;
        - 01: Output mode, maximum speed: 10MHz;
        - 10: Output mode, maximum speed: 2MHz;
        - 11: Output mode, maximum speed: 50MHz;

        #### The two higher bits for each pin byte configures CNF:
        Input mode (MODE = 00):
        - 00: Analog input mode;
        - 01: Floating input mode;
        - 10: Mode with pull-up pull down;
        - 11: Reserved;

        Output mode (MODE > 00):
        - 00: General push-pull output mode;
        - 01: General open-drain mode;
        - 10: Alternate function push-pull output mode;
        - 11: Alternate function open-drain output mode. */
        uint32_t CFGLR;
        struct {
            uint32_t pin0 : 4;
            uint32_t pin1 : 4;
            uint32_t pin2 : 4;
            uint32_t pin3 : 4;
            uint32_t pin4 : 4;
            uint32_t pin5 : 4;
            uint32_t pin6 : 4;
            uint32_t pin7 : 4;
        } cfglr;
    };
    union {
        /* Port configuration register low (pin[15:8])

        To configure multiple pins at once write the corresponding
        hexadecimal configuration values in the form of 16-bit to
        the CFGHR register.

        #### The two lower bits for each pin byte configures MODE:
        - 00: Input mode;
        - 01: Output mode, maximum speed: 10MHz;
        - 10: Output mode, maximum speed: 2MHz;
        - 11: Output mode, maximum speed: 50MHz;

        #### The two higher bits for each pin byte configures CNF:
        Input mode (MODE = 00):
        - 00: Analog input mode;
        - 01: Floating input mode;
        - 10: Mode with pull-up pull down;
        - 11: Reserved;

        Output mode (MODE > 00):
        - 00: General push-pull output mode;
        - 01: General open-drain mode;
        - 10: Alternate function push-pull output mode;
        - 11: Alternate function open-drain output mode. */
        uint32_t CFGHR;
        struct {
            uint32_t pin8  : 4;
            uint32_t pin9  : 4;
            uint32_t pin10 : 4;
            uint32_t pin11 : 4;
            uint32_t pin12 : 4;
            uint32_t pin13 : 4;
            uint32_t pin14 : 4;
            uint32_t pin15 : 4;
        } cfghr;
    };
    union {
        // Port input data register (read only)
        uint32_t INDR;
        struct {
            uint32_t pin0  : 1;
            uint32_t pin1  : 1;
            uint32_t pin2  : 1;
            uint32_t pin3  : 1;
            uint32_t pin4  : 1;
            uint32_t pin5  : 1;
            uint32_t pin6  : 1;
            uint32_t pin7  : 1;
            uint32_t pin8  : 1;
            uint32_t pin9  : 1;
            uint32_t pin10 : 1;
            uint32_t pin11 : 1;
            uint32_t pin12 : 1;
            uint32_t pin13 : 1;
            uint32_t pin14 : 1;
            uint32_t pin15 : 1;
            uint32_t : 16; // reserved
        } indr;
    };
    union {
        /* Port out data register
        These bits can only be operated in the form of 16 bits.
        The I/O port outputs the value of these registers externally.
        #### For input modes with pull-up and pull-down:
        - 0: pull-down input
        - 1: pull-up input */ 
        uint32_t OUTDR;
        struct {
            uint32_t pin0  : 1;
            uint32_t pin1  : 1;
            uint32_t pin2  : 1;
            uint32_t pin3  : 1;
            uint32_t pin4  : 1;
            uint32_t pin5  : 1;
            uint32_t pin6  : 1;
            uint32_t pin7  : 1;
            uint32_t pin8  : 1;
            uint32_t pin9  : 1;
            uint32_t pin10 : 1;
            uint32_t pin11 : 1;
            uint32_t pin12 : 1;
            uint32_t pin13 : 1;
            uint32_t pin14 : 1;
            uint32_t pin15 : 1;
            uint32_t : 16; // reserved
        } outdr;
    };
    union {
        /* Setting these bits will set the corresponding OUTDR 
        bits, and writing 0 has no effect. These bits can only 
        be accessed in form of 16 bits. */
        uint32_t BSR;
        struct {
            uint32_t pin0  : 1; 
            uint32_t pin1  : 1; 
            uint32_t pin2  : 1; 
            uint32_t pin3  : 1; 
            uint32_t pin4  : 1; 
            uint32_t pin5  : 1; 
            uint32_t pin6  : 1; 
            uint32_t pin7  : 1; 
            uint32_t pin8  : 1; 
            uint32_t pin9  : 1; 
            uint32_t pin10 : 1; 
            uint32_t pin11 : 1; 
            uint32_t pin12 : 1; 
            uint32_t pin13 : 1; 
            uint32_t pin14 : 1; 
            uint32_t pin15 : 1; 
            uint32_t : 16; // reserved
        } bsr;
    };
    union {
        /* Setting these bits will clear the corresponding OUTDR 
        bits, and writing 0 has no effect. These bits can only 
        be accessed in form of 16 bits. */
        uint32_t BCR;
        struct {
            uint32_t br0  : 1;
            uint32_t br1  : 1;
            uint32_t br2  : 1;
            uint32_t br3  : 1;
            uint32_t br4  : 1;
            uint32_t br5  : 1;
            uint32_t br6  : 1;
            uint32_t br7  : 1;
            uint32_t br8  : 1;
            uint32_t br9  : 1;
            uint32_t br10 : 1;
            uint32_t br11 : 1;
            uint32_t br12 : 1;
            uint32_t br13 : 1;
            uint32_t br14 : 1;
            uint32_t br15 : 1;
            uint32_t : 16; // reserved
        } bcr;
    };
    union {
        /* When these bits[15:0] are 1, it means that the
        configuration of the corresponding port is locked.
        These bits can only be changed before the LCKK
        is unlocked. The locked configuration refers to
        GPIOx_CFGLR and GPIOx_CFGHR. 
        
        Bit 16 (LCKK) is the lock key. It can be locked by writing 
        in a specific sequence, but it can be read out at any time. 
        When it's read as 0, it means that it is unlocked.
        When it's read as 1, it means that it is locked.
        The write sequence of the lock key is: write 1-write 0-
        write 1-read 0-read 1. */
        uint32_t LCKR;
        struct {
            uint32_t pin0  : 1;
            uint32_t pin1  : 1;
            uint32_t pin2  : 1;
            uint32_t pin3  : 1;
            uint32_t pin4  : 1;
            uint32_t pin5  : 1;
            uint32_t pin6  : 1;
            uint32_t pin7  : 1;
            uint32_t pin8  : 1;
            uint32_t pin9  : 1;
            uint32_t pin10 : 1;
            uint32_t pin11 : 1;
            uint32_t pin12 : 1;
            uint32_t pin13 : 1;
            uint32_t pin14 : 1;
            uint32_t pin15 : 1;
            uint32_t LCKK  : 1;
            uint32_t : 15; // reserved
        } lckr;
    };
} GPIO_t;

#define GPIOA ((volatile GPIO_t *)GPIO_A_BASE)
#define GPIOB ((volatile GPIO_t *)GPIO_B_BASE)
#define GPIOC ((volatile GPIO_t *)GPIO_C_BASE)
#define GPIOD ((volatile GPIO_t *)GPIO_D_BASE)
#define GPIOE ((volatile GPIO_t *)GPIO_E_BASE)

// Function prototypes

// Initialize GPIO
void init_gpio();

#endif
