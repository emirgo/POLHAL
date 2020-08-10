#include "_POLHAL.h"

/*
	WARNING: Ever pin in datasheet has a different offset and there is no apparent pattern
	for now at least unless an algorithm is found it is easier to hardcode the
	offset in an array like this.
	
	Description: This array returns the first bit of the MODE offset for given pin number.
*/
uint32_t PINPOS[16] = {
	(0x00),
	(0x04),
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C),
	(0x00),
	(0x04),
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C)
};

void gpio_init(GPIO_TYPE gpioType)
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

// TODO: Error handling
void configure_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t modeType)
{
	// Control high register
	if (pinNumber >= 8)
	{
		switch(modeType)
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
		switch (modeType)
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

// TODO: Error handling
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

// TODO: Error handling
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
	// Can be improved by BSRR to make it atomic
	gpio->ODR ^= 1 << pinNumber;
}
