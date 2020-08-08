// Author: Emirhan Gocturk

#include "_POLHAL.h"

void testInitBlink(void);
void testBlink(void);

int main(void)
{
	testInitBlink();

	while(1)
	{
		testBlink();
	}

	return 0;
}


/* Examples */

// On board blink
// BEGIN
void testInitBlink(void)
{
	// Configure pin type
	GPIO_TYPE LED_GREEN_Pin;
	LED_GREEN_Pin.port = GPIOA;
	LED_GREEN_Pin.mode = OUTPUT_MODE;
	LED_GREEN_Pin.pin = 5;
	LED_GREEN_Pin.speed = GPIO_SPEED_HIGH;

	// Pass configured pin to initialize
	gpio_init(LED_GREEN_Pin);
}

void testBlink(void)
{
	// Requires testInitBlink
	while (1)
	{
		gpio_toggle(GPIOA, 5);
		// Silly test delay :]
		volatile int i = 0;
		for (i = 0; i < 0xfffff; i++);
	}
}
// END
