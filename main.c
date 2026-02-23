#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)
#define GPIOC_CRH   (*(volatile uint32_t*)0x40011004)
#define GPIOC_BSRR  (*(volatile uint32_t*)0x40011010)
#define GPIOC_BRR   (*(volatile uint32_t*)0x40011014)

void delay(volatile uint32_t d)
{
    while(d--);
}

int main(void)
{
    RCC_APB2ENR |= (1 << 4);

    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |=  (0x2 << 20);

    while(1)
    {
        GPIOC_BRR = (1 << 13);
        delay(500000);

        GPIOC_BSRR = (1 << 13);
        delay(500000);
    }
}
