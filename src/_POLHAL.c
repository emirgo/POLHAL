// Author: Emirhan Gocturk
#include "_POLHAL.h"

void configure_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinMode)
{
	// Set pin mode
	switch (pinMode)
	{
		case INPUT_MODE:
			// Do nothing
		break;

		case OUTPUT_MODE:
			gpio->MODER |= (1 << (pinNumber * 2));
		break;

		case ALTERNATE_FUNCTION_MODE:
			gpio->MODER |= (1 << ((pinNumber * 2) + 1));
		break;

		case ANALOG_MODE:
			gpio->MODER |= (1 << ((pinNumber * 2) + 1)) | (1 << (pinNumber * 2));
		break;
	}
}

void configure_pin_speed(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode)
{
	if (mode == OUTPUT_MODE)
	{
		switch (pinSpeed)
		{
			case GPIO_SPEED_HIGH:
				gpio->OSPEEDR |= (1 << (pinNumber * 2)) | (1 << ((pinNumber * 2) + 1));
			break;

			case GPIO_SPEED_FAST:
				gpio->OSPEEDR |= (1 << ((pinNumber * 2) + 1));
			break;

			case GPIO_SPEED_MEDIUM:
				gpio->OSPEEDR |= (1 << (pinNumber * 2));
			break;

			case GPIO_SPEED_LOW:
				// Do nothing
			break;
		}
	}
}

void gpio_write(GPIO_TypeDef *gpio, uint32_t pinNumber, uint8_t state)
{
	// TODO: Replace ODR with BSRR
	if (state == HIGH)
	{
		gpio->ODR |= 1 << pinNumber;
	}
	else if (state == LOW)
	{
		gpio->ODR |= 0 << pinNumber;
	}
	else
	{
		// Error
	}
}

void gpio_toggle(GPIO_TypeDef *gpio, uint32_t pinNumber)
{
	// TODO: Replace ODR with BSRR
	gpio->ODR ^= pinNumber;
}
