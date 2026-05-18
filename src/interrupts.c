#include "afio.h"
#include "exti.h"
#include "pfic.h"

void init_interrupts() {
    // Enable SysTick interrupts
    IRQ_ENABLE(12);
    // Enable EXTI{0,1,2,3}
    IRQ_ENABLE(22);
    IRQ_ENABLE(23);
    IRQ_ENABLE(24);
    IRQ_ENABLE(25);
    // Connect EXTI{0,1,2,3} to port D
    AFIO->EXTICR1 = 0x3333;
}