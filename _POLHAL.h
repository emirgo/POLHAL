#ifndef _POLHAL
#define _POLHAL

#ifndef __STM32F10x_H
	#include "stm32f10x.h"	// Device header
	#define __STM32F10x_H
#endif

// Pin mode
#define OUTPUT_MODE	((uint32_t) 0x01)
#define INPUT_MODE	((uint32_t) 0x02)

// Input mode type
#define INPUT_ANALOG		((uint32_t) 0x00)
#define INPUT_FLOATING	((uint32_t) 0x01)	// Default
#define INPUT_PU_PD			((uint32_t) 0x02)	// Input with pull up or pull down

// Output mode type
#define OUTPUT_GENERAL_PURPOSE					((uint32_t) 0x00)	// General purpose output
#define OUTPUT_OPEN_DRAIN								((uint32_t) 0x01)	// Output open drain
#define OUTPUT_ALT_FUNCTION							((uint32_t) 0x02)	// Push pull
#define OUTPUT_ALT_FUNCTION_OPEN_DRAIN	((uint32_t) 0x03)	// Open drain

// Pin speeds
#define SPEED_2MHZ		((uint32_t) 0x00)
#define SPEED_10MHZ		((uint32_t) 0x01)
#define SPEED_50MHZ		((uint32_t) 0x02)

// Clock enable
#define GPIO_CLOCK_ENABLE_ALT_FUNCTION	(RCC->APB2ENR |= (1 << 0))
#define GPIO_CLOCK_ENABLE_GPIOA					(RCC->APB2ENR |= (1 << 2))
#define GPIO_CLOCK_ENABLE_GPIOB					(RCC->APB2ENR |= (1 << 3))
#define GPIO_CLOCK_ENABLE_GPIOC					(RCC->APB2ENR |= (1 << 4))
#define GPIO_CLOCK_ENABLE_GPIOD					(RCC->APB2ENR |= (1 << 5))

// High bit positions for CRH (CNF and MODE)
#define CNF_POS_BIT1	(PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2	(PINPOS[pinNUmber] + 3)

// GPIO Config structure
typedef struct
{
	GPIO_TypeDef *gpio;
	uint32_t pin;
	uint32_t mode;
	uint32_t mode_type;
	uint32_t pull;
	uint32_t speed;
	uint32_t alt_func;
} GPIO_TYPE;

#endif