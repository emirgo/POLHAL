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

void POLHAL::gpio_init(GPIO_TYPE gpioType)
{
	if (gpioType.gpio == GPIOA)
	{
		GPIO_CLOCK_ENABLE_GPIOA;
	}
	else if (gpioType.gpio == GPIOB)
	{
		GPIO_CLOCK_ENABLE_GPIOB;
	}
	else if (gpioType.gpio == GPIOC)
	{
		GPIO_CLOCK_ENABLE_GPIOC;
	}
	else if (gpioType.gpio == GPIOD)
	{
		GPIO_CLOCK_ENABLE_GPIOD;
	}

	configure_pin(gpioType.gpio, gpioType.pin, gpioType.mode);

	config_pin_speed(gpioType.gpio, gpioType.pin, gpioType.speed, gpioType.mode_type);
}

void POLHAL::configure_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t mode)
{
	// Control high register
	if (pinNumber >= 8)
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

void POLHAL::config_pin_speed(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinSpeed, uint32_t modeType)
{
	if (pinNumber >= 8)
	{
		if (modeType == INPUT_MODE)
		{
			gpio->CRH &= ~(1 << (PINPOS[pinNumber]) | 1 << (PINPOS[pinNumber]) + 1);
		}
		else
		{
			gpio->CRH |= (pinSpeed << (PINPOS[pinNumber]));
		}
	}
	else
	{
		if (modeType == INPUT_MODE)
		{
			gpio->CRL &= ~(1 << (PINPOS[pinNumber]) | 1 << (PINPOS[pinNumber]) + 1);
		}
		else
		{
			gpio->CRL |= (pinSpeed << (PINPOS[pinNumber]));
		}
	}
}

void POLHAL::gpio_write(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t state)
{
	if (state == HIGH)
	{
		gpio->BSRR |= 1 << pinNumber;
	}
	else if (state == LOW)
	{
		gpio->BSRR |= 1 << (pinNumber + 16);
	}
	else
	{
		// Error
	}
}

void POLHAL::gpio_toggle(GPIO_TypeDef *gpio, uint32_t pinNumber)
{
	gpio->ODR ^= 1 << pinNumber;
}
