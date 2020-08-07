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
	while (1)
	{
		gpio_toggle(GPIOA, 5);
		// Silly test delay :]
		volatile int i = 0;
		for (i = 0; i < 0xfffff; i++);
	}
}
