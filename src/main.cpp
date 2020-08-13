/*
	Copyright 2020 Emirhan Gocturk

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "stm32f1xx.h"
#include "POLHAL.h"
			

int main(void)
{
	POLHAL::GPIO_TYPE led_green;
	led_green.gpio = GPIOC;
	led_green.pin = 13;
	led_green.mode = OUTPUT_MODE;
	led_green.mode_type = OUTPUT_GENERAL_PURPOSE;
	led_green.speed = SPEED_50MHZ;

	POLHAL::gpio_init(led_green);

	volatile int i = 0;
	volatile int speed = 0xffff;

	while (1)
	{
		POLHAL::gpio_toggle(led_green.gpio, led_green.pin);
		for(i = 0; i < speed; i++);
	}
}
