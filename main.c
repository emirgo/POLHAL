#include "_POLHAL.h"

int main(void)
{
	// Initialize the clock
	// IOPCEN
	//RCC->APB2ENR = 1 << 4;
	GPIO_CLOCK_ENABLE_GPIOC;
	// Set PC13 as output
	// OUTPUT @ 50Mhz
	GPIOC->CRH |= ((1 << 20) | (1 << 21));
	// GPO
	GPIOC->CRH &= ~((1 << 22) | (1 << 23));
	
	while (1)
	{
		GPIOC->ODR ^= 1 << 13;
		volatile int i = 0;
		for (i = 0; i < 0xfffff; i++);
	}
	
	return 0;
}
