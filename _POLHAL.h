// Author: Emirhan Gocturk
#ifndef _POLHAL
#define _POLHAL

#include "stm32f4xx.h"                  // Device header

// Port naming
#define PORTA GPIOA
#define PORTB GPIOB
#define PORTC GPIOC
#define PORTD GPIOD
#define PORTE GPIOE
#define PORTF GPIOF
#define PORTG GPIOG

// Pin modes
#define OUTPUT_MODE 						((uint32_t) 0x01)
#define INPUT_MODE 							((uint32_t) 0x02)
#define ALTERNATE_FUNCTION_MODE ((uint32_t) 0x03)
#define ANALOG_MODE							((uint32_t) 0x04)



void setPinMode()
{
	
}

#endif