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
    uint32_t CFGLR;
    uint32_t CFGHR;
    uint16_t INDR;
    uint16_t : 16;
    uint16_t OUTDR;
    uint16_t : 16;
    uint16_t BSR;
    uint16_t : 16;
    uint16_t BCR;
    uint16_t : 16;
    uint32_t LCKR;
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
