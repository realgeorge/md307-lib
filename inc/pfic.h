#ifndef PFIC_H
#define PFIC_H

#include <stdint.h>

// PFIC base address
#define PFIC_BASE 0xE000E000

// PFIC pointer macros
#define PFIC_ISR   ((volatile uint32_t *)(PFIC_BASE + 0x000))
#define PFIC_IPR   ((volatile uint32_t *)(PFIC_BASE + 0x020))
#define PFIC_IENR  ((volatile uint32_t *)(PFIC_BASE + 0x100))
#define PFIC_IRER  ((volatile uint32_t *)(PFIC_BASE + 0x180))
#define PFIC_IPSR  ((volatile uint32_t *)(PFIC_BASE + 0x200))
#define PFIC_IPRR  ((volatile uint32_t *)(PFIC_BASE + 0x280))
#define PFIC_IACTR ((volatile uint32_t *)(PFIC_BASE + 0x300))

// Generic Register Modification Macros
#define PFIC_REG_SET(reg, irqn) (reg[(irqn) / 32] = (1 << ((irqn) % 32)))
#define PFIC_REG_READ(reg, irqn) ((reg[(irqn) / 32] >> ((irqn) % 32)) & 1)

// Function macros

// IRQ no. enable
#define IENR_SET(irqn)                                  \
do {                                                    \
    (PFIC_IENR[(irqn) / 32] = (1 << ((irqn) % 32)));    \
    __asm volatile("fence.i" : : : "memory");           \
} while(0)

// IRQ no. disable
#define IRER_SET(irqn)                                  \
do {                                                    \
    (PFIC_IRER[(irqn) / 32] = (1 << ((irqn) % 32)));    \
    __asm volatile("fence.i" : : : "memory");           \
} while(0)

// IRQ no. set pending status
#define IPSR_SET(irqn)   (PFIC_IPSR[(irqn) / 32] = (1 << ((irqn) % 32)))

// IRQ no. clear pending status
#define IPRR_SET(irqn)   (PFIC_IPRR[(irqn) / 32] = (1 << ((irqn) % 32)))

// IRQ no. enabled status (Read Only)
#define ISR_READ(irqn)   ((PFIC_ISR[(irqn) / 32] >> ((irqn) % 32)) & 1)

// IRQ no. pending status (Read Only)
#define IPR_READ(irqn)   ((PFIC_IPR[(irqn) / 32] >> ((irqn) % 32)) & 1)

// IRQ no. active status (Read Only)
#define IACTR_READ(irqn) ((PFIC_IACTR[(irqn) / 32] >> ((irqn) % 32)) & 1)

#ifndef PFIC_H_DISABLE_IRQ_FUNCTIONS
#define IRQ_ENABLE(irqn)                 IENR_SET((irqn))
#define IRQ_DISABLE(irqn)                IRER_SET((irqn))
#define IRQ_SET_PENDING_STATUS(irqn)     IPSR_SET((irqn))
#define IRQ_CLR_PENDING_STATUS(irqn)     IPRR_SET((irqn))
#define IRQ_GET_STATUS(irqn)             ISR_GET((irqn))
#define IRQ_GET_PENDING_STATUS(irqn)     IPR_GET((irqn))
#define IRQ_GET_ACTIVATION_STATUS(irqn)  IACTR_GET((irqn))
#endif

#endif
