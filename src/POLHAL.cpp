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

#include "POLHAL.h"

POLHAL::POLHAL() {
	// TODO Auto-generated constructor stub

}

POLHAL::~POLHAL() {
	// TODO Auto-generated destructor stub
}

void POLHAL::gpio_init(GPIO_TYPE gpio_type)
{
	if (gpio_type.gpio == GPIOA)
	{
		GPIO_CLOCK_ENABLE_GPIOA;
	}
	else if (gpio_type.gpio == GPIOB)
	{
		GPIO_CLOCK_ENABLE_GPIOB;
	}
	else if (gpio_type.gpio == GPIOC)
	{
		GPIO_CLOCK_ENABLE_GPIOC;
	}
	else if (gpio_type.gpio == GPIOD)
	{
		GPIO_CLOCK_ENABLE_GPIOD;
	}

	configure_pin(gpio_type.gpio, gpio_type.pin, gpio_type.mode);

	config_pin_speed(gpio_type.gpio, gpio_type.pin, gpio_type.speed, gpio_type.mode_type);
}

void POLHAL::configure_pin(GPIO_TypeDef *gpio, uint32_t pin_number, uint32_t mode)
{
	// Control high register
	if (pin_number >= 8)
	{
		switch(mode)
		{
			case OUTPUT_GENERAL_PURPOSE:
				gpio->CRH &= ~((1 << CNF_POS_BIT1) | (1 << CNF_POS_BIT2));
			break;

			case OUTPUT_OPEN_DRAIN | INPUT_FLOATING:
				gpio->CRH &= ~(1 << CNF_POS_BIT2);
				gpio->CRH |= (1 << CNF_POS_BIT1);
			break;

			case OUTPUT_ALT_FUNCTION | INPUT_PU_PD:
				gpio->CRH |= OUTPUT_ALT_FUNCTION << (CNF_POS_BIT1);
			break;

			case OUTPUT_ALT_FUNCTION_OPEN_DRAIN:
				gpio->CRH |= OUTPUT_ALT_FUNCTION_OPEN_DRAIN << (CNF_POS_BIT1);
			break;
		}
	}
	// Control low register
	else
	{
		switch (mode)
		{
			case OUTPUT_GENERAL_PURPOSE:
				gpio->CRL &= ~((1 << CNF_POS_BIT1) | (1 << CNF_POS_BIT2));
			break;

			case OUTPUT_OPEN_DRAIN | INPUT_FLOATING:
				gpio->CRL &= ~(1 << CNF_POS_BIT2);
				gpio->CRL |= (1 << CNF_POS_BIT1);
			break;

			case OUTPUT_ALT_FUNCTION | INPUT_PU_PD:
				gpio->CRL |= OUTPUT_ALT_FUNCTION << (CNF_POS_BIT1);
			break;

			case OUTPUT_ALT_FUNCTION_OPEN_DRAIN:
				gpio->CRL |= OUTPUT_ALT_FUNCTION_OPEN_DRAIN << (CNF_POS_BIT1);
			break;
		}
	}
}

void POLHAL::config_pin_speed(GPIO_TypeDef *gpio, uint32_t pin_number, uint32_t pin_speed, uint32_t mode_type)
{
	if (pin_number >= 8)
	{
		if (mode_type == INPUT_MODE)
		{
			gpio->CRH &= ~(1 << (PINPOS[pin_number]) | 1 << (PINPOS[pin_number]) + 1);
		}
		else
		{
			gpio->CRH |= (pin_speed << (PINPOS[pin_number]));
		}
	}
	else
	{
		if (mode_type == INPUT_MODE)
		{
			gpio->CRL &= ~(1 << (PINPOS[pin_number]) | 1 << (PINPOS[pin_number]) + 1);
		}
		else
		{
			gpio->CRL |= (pin_speed << (PINPOS[pin_number]));
		}
	}
}

void POLHAL::gpio_write(GPIO_TypeDef *gpio, uint32_t pin_number, uint32_t state)
{
	if (state == HIGH)
	{
		gpio->BSRR |= 1 << pin_number;
	}
	else if (state == LOW)
	{
		gpio->BSRR |= 1 << (pin_number + 16);
	}
	else
	{
		// Error
	}
}

void POLHAL::gpio_toggle(GPIO_TypeDef *gpio, uint32_t pin_number)
{
	gpio->ODR ^= 1 << pin_number;
}
