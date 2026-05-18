#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>

// EXTI base address
#define EXTI_BASE 0x40010400

// EXTI pointer macros
#define EXTI_INTENR ((volatile uint32_t *)(EXTI_BASE + 0x00))
#define EXTI_EVENR  ((volatile uint32_t *)(EXTI_BASE + 0x04))
#define EXTI_RTENR  ((volatile uint32_t *)(EXTI_BASE + 0x08))
#define EXTI_FTENR  ((volatile uint32_t *)(EXTI_BASE + 0x0C))
#define EXTI_SWIEVR ((volatile uint32_t *)(EXTI_BASE + 0x10))
#define EXTI_INTFR  ((volatile uint32_t *)(EXTI_BASE + 0x14))

// EXTI Interrupt map template
typedef union {
    uint32_t REG;
    struct {
        uint32_t LINE0       : 1; // ID:(22) vector_offset:(0x0000 0058)
        uint32_t LINE1       : 1; // ID:(23) vector_offset:(0x0000 005C)
        uint32_t LINE2       : 1; // ID:(24) vector_offset:(0x0000 0060)
        uint32_t LINE3       : 1; // ID:(25) vector_offset:(0x0000 0064)
        uint32_t LINE4       : 1; // ID:(26) vector_offset:(0x0000 0068)

        // Group: EXTI9_5            ID:(39) vector_offset:(0x0000 009C)
        uint32_t LINE5       : 1;
        uint32_t LINE6       : 1;
        uint32_t LINE7       : 1;
        uint32_t LINE8       : 1;
        uint32_t LINE9       : 1;

        // Group: EXTI15_10          ID:(56) vector_offset:(0x0000 00E0)
        uint32_t LINE10      : 1;
        uint32_t LINE11      : 1;
        uint32_t LINE12      : 1;
        uint32_t LINE13      : 1;
        uint32_t LINE14      : 1;
        uint32_t LINE15      : 1;

        /* Internal Hardware Routing
         * Source: CH32F/V20x_V30x_V31x Series Reference Manual (p. 89)
         * Vendor: https://whc-ic.com */
        uint32_t PVD         : 1; // ID:(17) vector_offset:(0x0000 0044)
        uint32_t RTC_ALARM   : 1; // ID:(57) vector_offset:(0x0000 00E4)
        uint32_t USBWakeUp   : 1; // ID:(58) vector_offset:(0x0000 00E8)
        uint32_t ETH_WKUP    : 1; // ID:(77) vector_offset:(0x0000 0138)
        uint32_t USBHSWakeUp : 1; // ID:(84) vector_offset:(0x0000 0150)
        uint32_t TAMPER      : 1; // ID:(18) vector_offset:(0x0000 0048)

        uint32_t : 10; // reserved
    };
} EXTI_Reg_t;

// EXTI struct and accompanying pointer
typedef struct {
    EXTI_Reg_t INTENR; // (0x00) Interrupt Enable Register
    EXTI_Reg_t EVENR;  // (0x04) Event Enable Register
    EXTI_Reg_t RTENR;  // (0x08) Rising Edge Trigger Enable Register
    EXTI_Reg_t FTENR;  // (0x0C) Falling Edge Trigger Enable Register
    EXTI_Reg_t SWIEVR; // (0x10) Software Interrupt Event Register
    EXTI_Reg_t INTFR;  // (0x14) Interupt Flag Register
} EXTI_t;

#define EXTI ((volatile EXTI_t *)EXTI_BASE)

#endif
