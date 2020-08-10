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
		
	}
}