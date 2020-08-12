/*
 * POLHAL.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: heurisitk
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

void configure_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t mode)
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

void config_pin_speed(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode)
{
	if (pinNumber >= 8)
	{
		if (mode == INPUT_MODE)
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
		if (mode == INPUT_MODE)
		{
			gpio->CRL &= ~(1 << (PINPOS[pinNumber]) | 1 << (PINPOS[pinNumber]) + 1);
		}
		else
		{
			gpio->CRL |= (pinSpeed << (PINPOS[pinNumber]));
		}
	}
}

void gpio_write(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t state)
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

void gpio_toggle(GPIO_TypeDef *gpio, uint32_t pinNumber)
{
	gpio->ODR ^= 1 << pinNumber;
}
