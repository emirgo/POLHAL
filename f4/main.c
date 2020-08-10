// Author: Emirhan Gocturk

#include "_POLHAL.h"

void testBlink(void);

int main(void)
{
	GPIO_CLOCK_ENABLE_PORTA;
	
	configure_pin(GPIOA, 5, OUTPUT_MODE);
	configure_pin_speed(GPIOA, 5, GPIO_SPEED_HIGH, OUTPUT_MODE);

	while(1)
	{
		testBlink();
	}
	
	return 0;
}

/* Register examples */

// On board blink
void testBlink(void)
{
	/*
	// Enable clock for GPIOA
	RCC->AHB1ENR |= 1;
	// GPIO mode for PA5
	GPIOA->MODER |= 1 << 10;
	// Output Speed
	GPIOA->OSPEEDR |= 1 << 10 | 1 << 11;
	*/
	
	while (1)
	{
		GPIOA->ODR ^= 1 << 5;
		// Silly test delay :]
		volatile int i = 0;
		for (i = 0; i < 0xfffff; i++);
	}
}