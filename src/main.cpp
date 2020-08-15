/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "POLHAL.h"
			

int main(void)
{
	POLHAL::GPIO_TYPE led_green;
	led_green.gpio = GPIOA;
	led_green.pin = 5;
	led_green.mode = POLHAL::GPIO_MODE::OUTPUT_MODE;
	led_green.output_type = POLHAL::GPIO_OUTPUT_TYPE::PUSH_PULL;
	led_green.speed = POLHAL::GPIO_OUTPUT_SPEED::HIGH_SPEED;

	POLHAL::gpio_init(led_green);

	while (1)
	{
		POLHAL::gpio_toggle(led_green.gpio, led_green.pin);
	}
}
