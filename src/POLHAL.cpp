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

	configure_pin(gpio_type.gpio, gpio_type.pin, gpio_type.mode, gpio_type.output_type);
	config_pin_speed(gpio_type.gpio, gpio_type.pin, gpio_type.speed);
	//config_pin_speed(gpio_type.gpio, gpio_type.pin, gpio_type.speed, gpio_type.mode_type);
}

void POLHAL::configure_pin(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_MODE mode, POLHAL::GPIO_OUTPUT_TYPE gpio_output_type)
{
	POLHAL polhal;
	polhal.gpio_set_mode(gpio, pin_number, mode);
	polhal.configure_output_type(gpio, pin_number, gpio_output_type);
}

void POLHAL::gpio_set_mode(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_MODE mode)
{
	switch (mode)
	{
		case POLHAL::GPIO_MODE::INPUT_MODE:
			// Default
		break;

		case POLHAL::GPIO_MODE::OUTPUT_MODE:
			gpio->MODER |= 1 << pin_number;
		break;

		case POLHAL::GPIO_MODE::ALTERNATE_FUNCTION:
			gpio->MODER |= 1 << (pin_number + 1);
		break;

		case POLHAL::GPIO_MODE::ANALOG_MODE:
			gpio->MODER |= (1 << pin_number) | (1 << (pin_number + 1));
		break;

		default:
			// Error TODO: error handling
		break;
	}
}

void POLHAL::configure_output_type(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_OUTPUT_TYPE gpio_output_type)
{
	if (gpio_output_type == POLHAL::GPIO_OUTPUT_TYPE::OPEN_DRAIN)
	{
		gpio->OTYPER |= 1 << pin_number;
	}
	else
	{
		// Do nothing
		// By default push pull is active
	}
}

void POLHAL::config_pin_speed(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_OUTPUT_SPEED gpio_output_speed)
{
	switch (gpio_output_speed)
	{
		case POLHAL::GPIO_OUTPUT_SPEED::LOW_SPEED:
			// Default
		break;

		case POLHAL::GPIO_OUTPUT_SPEED::MEDIUM_SPEED:
			gpio->OSPEEDR |= 1 << (pin_number * 2);
		break;

		case POLHAL::GPIO_OUTPUT_SPEED::FAST_SPEED:
			gpio->OSPEEDR |= 1 << ((pin_number * 2) + 1);
		break;

		case POLHAL::GPIO_OUTPUT_SPEED::HIGH_SPEED:
			gpio->OSPEEDR |= (1 << (pin_number * 2)) | (1 << ((pin_number * 2) + 1));
		break;
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
