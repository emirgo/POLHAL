#include "_POLHAL.h"

void testBlink(void);

int main(void)
{
	
	while (1)
	{
		testBlink();
	}
	
	return 0;
}

// Examples
void testBlink(void)
{
	GPIO_TYPE greenLed;
	greenLed.gpio = GPIOC;
	greenLed.pin = 13;
	greenLed.mode = OUTPUT_MODE;
	greenLed.mode_type = OUTPUT_GENERAL_PURPOSE;
	greenLed.speed = SPEED_50MHZ;
	
	gpio_init(greenLed);

	volatile int i = 0;
	
	while(1)
	{
		gpio_toggle(greenLed.gpio, greenLed.pin);
		for(i = 0; i < 0xfffff; i++);
	}
}
