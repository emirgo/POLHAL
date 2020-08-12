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
	POLHAL::GPIO_TYPE gpioType;
	gpioType.gpio = GPIOC;
	gpioType.pin = 13;
	gpioType.mode = OUTPUT_MODE;
	gpioType.mode_type = OUTPUT_GENERAL_PURPOSE;
	gpioType.speed = SPEED_50MHZ;

	POLHAL::gpio_init(gpioType);

	volatile int i = 0;

	while (1)
	{
		POLHAL::gpio_toggle(gpioType.gpio, gpioType.pin);
		for(i = 0; i < 0xffff; i++);

	}
}
