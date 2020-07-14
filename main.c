#include "stm32f10x.h"                  // Device header

int main(void)
{
	// IOPCEN
	RCC->APB2ENR |= 0x10;
	// Set PC13 as output
	GPIOC->CRH |= 0x300000;
	
	while(1)
	{
		GPIOC->BSRR = 1 << 13;
		for(int i = 0; i < 0xFFFFF; i++);
		GPIOC->BSRR = 1 << 29;
		for(int i = 0; i < 0xFFFFF; i++);
	}
	
	return 0;
}