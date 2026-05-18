#ifndef AFIO_H
#define AFIO_H

#include <stdint.h>

// AFIO base address
#define AFIO_BASE 0x40010000

// AFIO pointer macros
#define AFIO_ECR     ((volatile uint32_t *)(AFIO_BASE + 0x00))
#define AFIO_PCFR    ((volatile uint32_t *)(AFIO_BASE + 0x04))
#define AFIO_EXTICR1 ((volatile uint16_t *)(AFIO_BASE + 0x08))
#define AFIO_EXTICR2 ((volatile uint16_t *)(AFIO_BASE + 0x0C))
#define AFIO_EXTICR3 ((volatile uint16_t *)(AFIO_BASE + 0x10))
#define AFIO_EXTICR4 ((volatile uint16_t *)(AFIO_BASE + 0x14))
#define AFIO_PCFR2   ((volatile uint32_t *)(AFIO_BASE + 0x18))

// AFIO struct and accopanying pointer
typedef struct {
    uint32_t ECR;
    uint32_t PCFR1;
    union {
        uint32_t EXTICR1;
        struct {
            uint32_t EXTI0 : 4;
            uint32_t EXTI1 : 4;
            uint32_t EXTI2 : 4;
            uint32_t EXTI3 : 4;
            uint32_t : 16; // reserved
        };
    };
    union {
        uint32_t EXTICR2;
        struct {
            uint32_t EXTI4 : 4;
            uint32_t EXTI5 : 4;
            uint32_t EXTI6 : 4;
            uint32_t EXTI7 : 4;
            uint32_t : 16; // reserved
        };
    };
    union {
        uint32_t EXTICR3;
        struct {
            uint32_t EXTI8  : 4;
            uint32_t EXTI9  : 4;
            uint32_t EXTI10 : 4;
            uint32_t EXTI11 : 4;
            uint32_t : 16; // reserved
        };
    };
    union {
        uint32_t EXTICR4;
        struct {
            uint32_t EXTI12 : 4;
            uint32_t EXTI13 : 4;
            uint32_t EXTI14 : 4;
            uint32_t EXTI15 : 4;
            uint32_t : 16; // reserved
        };
    };
    uint32_t PCFR2;
} AFIO_t;

#define AFIO ((volatile AFIO_t *)AFIO_BASE)

/* Hardware Multiplexer IDs for Port Routing
 * These are integer selectors used as bitwise shift values, not memory addresses. */
#define AFIO_PORT_A 0x0
#define AFIO_PORT_B 0x1
#define AFIO_PORT_C 0x2
#define AFIO_PORT_D 0x3
#define AFIO_PORT_E 0x4

/* Masks the EXTI line number to 4 bits (0-15). 
 * This is the integer value used to calculate register offsets, not a memory address. */
#define AFIO_EXTI(x) ((x) & 0xF)

/* Example: Configure PE7 to EXTI7
 * AFIO_EXTICR_Configure(AFIO_EXTI(7), AFIO_EXTI_PORT_E) */
#define AFIO_EXTI_Config(exti, port)                       \
do {                                                       \
    uint32_t shift = ((exti) % 4) * 4;                     \
    AFIO->EXTICR[(exti) / 4] &= ~(0xF << shift);           \
    AFIO->EXTICR[(exti) / 4] |= (((port) & 0xF) << shift); \
} while(0)

/* Example: Configure EXTICR1 (EXTI{0,1,2,3}) to Port E
 * AFIO_EXTICR_Config(*AFIO_EXTICR1, AFIO_EXTI_PORT_E) 
 *
 * Note: The first argument must evaluate to an assignable lvalue 
 * (the physical register itself). You must pass a dereferenced pointer 
 * (e.g., *AFIO_EXTICRn) or a struct member (e.g., AFIO->EXTICRn).
 */
#define AFIO_EXTICR_Config(exticr, port)                   \
do {                                                       \
    uint32_t block = ((port) & 0xF) * 0x1111;              \
    (exti) = ((exti) & 0xFFFF0000) | block;                \
} while(0)

#endif
