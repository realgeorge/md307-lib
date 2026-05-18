#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

// SysTick base address
#define STK_BASE 0xE000F000

// SysTick pointer macros
#define STK_CTLR  ((volatile uint32_t *)(STK_BASE + 0x00))
#define STK_SR    ((volatile uint32_t *)(STK_BASE + 0x04))
#define STK_CNTL  ((volatile uint32_t *)(STK_BASE + 0x08))
#define STK_CNTH  ((volatile uint32_t *)(STK_BASE + 0x0C))
#define STK_CMPLR ((volatile uint32_t *)(STK_BASE + 0x10))
#define STK_CMPHR ((volatile uint32_t *)(STK_BASE + 0x14))

// SysTick struct and accompanying pointer
typedef struct {
    union {
        uint32_t CTLR; 
        struct {
            uint32_t ste   :  1; // SysTick Timer Enable
            uint32_t stie  :  1; // SysTick Timer Interrupt Enable
            uint32_t stclk :  1; // SysTick Timer Clock Source
            uint32_t stre  :  1; // SysTick Timer Reload Enable   
            uint32_t mode  :  1; // SysTick Timer Mode (1: Upcount, 2: Downcount)
            uint32_t init  :  1; // SysTick Timer Init (Load/Clears CNT and CMP)
            uint32_t       : 25; // Reserved
            uint32_t swie  :  1; // SysTick Software Interrupt Enable
        } ctrl;
    };
    union {
        uint32_t SR;
        struct
        {
            uint32_t cnt   :  1; // 1 if counter has reached its final value, 0 otherwise
            uint32_t       : 31; // Reserved
        } sr;
    };
    union {
        uint64_t CNT; 
        struct {
            uint64_t CNTLR : 32;
            uint64_t CNTHR : 32;
        };
    }; 
    union {
        uint64_t CMP; 
        struct {
            uint64_t CMPLR : 32;
            uint64_t CMPHR : 32;
        };
    }; 
} STK_t;

#define STK ((volatile STK_t *)STK_BASE)

// Function prototypes

// Stop SysTick
void systick_stop();

#endif
