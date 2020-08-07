// Author: Emirhan Gocturk

#include "_POLHAL.h"

void testBlink(void);

int main(void)
{
	GPIO_TYPE LED_GREEN_Pin;
	LED_GREEN_Pin.port = GPIOA;
	LED_GREEN_Pin.mode = OUTPUT_MODE;
	LED_GREEN_Pin.pin = 5;
	LED_GREEN_Pin.speed = GPIO_SPEED_HIGH;

	gpio_init(LED_GREEN_Pin);

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
	// TODO: Enhance with init code for the pin
	while (1)
	{
		gpio_toggle(GPIOA, 5);
		// Silly test delay :]
		volatile int i = 0;
		for (i = 0; i < 0xfffff; i++);
	}
}
