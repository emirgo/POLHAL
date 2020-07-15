#include "stm32f10x.h"                  // Device header

int main(void)
{
	// Initialize the clock
	// IOPCEN
	RCC->APB2ENR = 1 << 4;
	// Set PC13 as output
	// OUTPUT @ 50Mhz
	GPIOC->CRH |= ((1 << 20) | (1 << 21));
	// GPO
	GPIOC->CRH &= ~((1 << 22) | (1 << 23));
	
	while(1)
	{
		GPIOC->BSRR = (1 << 13);
		for(volatile int i = 0; i < 0xfffff; ++i);
		GPIOC->BSRR = (1 << (13 + 16));
		for(volatile int i = 0; i < 0xfffff; ++i);
	}
	
	return 0;
}