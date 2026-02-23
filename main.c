#include "stm32f1xx.h"

void delay(volatile uint32_t d)
{
    while(d--);
}

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    GPIOC->CRH &= ~(0xF << ((13 - 8) * 4));
    GPIOC->CRH |= (0x2 << ((13 - 8) * 4));

    while(1)
    {
        GPIOC->BSRR = (1 << 13);
        delay(800000);

        GPIOC->BRR = (1 << 13);
        delay(800000);
    }
}
