// Author: Emirhan Gocturk
#include "_POLHAL.h"

void configure_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinMode)
{
	// Set pin mode
	switch (pinMode)
	{
		case INPUT_MODE:
			// Do nothing
		break;
		
		case OUTPUT_MODE:
			port->MODER |= (1 << (pinNumber * 2));
		break;
		
		case ALTERNATE_FUNCTION_MODE:
			port->MODER |= (1 << ((pinNumber * 2) + 1));
		break;
		
		case ANALOG_MODE:
			port->MODER |= (1 << ((pinNumber * 2) + 1)) | (1 << (pinNumber * 2));
		break;
	}
}

void configure_pin_speed(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode)
{
	if (mode == OUTPUT_MODE)
	{
		switch (pinSpeed)
		{
			case GPIO_SPEED_HIGH:
				port->OSPEEDR |= (1 << (pinNumber * 2)) | (1 << ((pinNumber * 2) + 1));
			break;
			
			case GPIO_SPEED_FAST:
				port->OSPEEDR |= (1 << ((pinNumber * 2) + 1));
			break;
			
			case GPIO_SPEED_MEDIUM:
				port->OSPEEDR |= (1 << (pinNumber * 2));
			break;
			
			case GPIO_SPEED_LOW:
				// Do nothing
			break;
		}
	}
}
