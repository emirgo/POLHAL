// Author: Emirhan Gocturk
#ifndef _POLHAL
#define _POLHAL

#include "stm32f4xx.h"                  // Device header
#include "stdio.h"

// Port naming
#define PORTA GPIOA
#define PORTB GPIOB
#define PORTC GPIOC
#define PORTD GPIOD
#define PORTE GPIOE
#define PORTF GPIOF
#define PORTG GPIOG

// Pin modes
#define OUTPUT_MODE							((uint32_t) 0x01)
#define INPUT_MODE							((uint32_t) 0x02)
#define ALTERNATE_FUNCTION_MODE ((uint32_t) 0x03)
#define ANALOG_MODE							((uint32_t) 0x04)

// Speed
#define GPIO_SPEED_HIGH		((uint32_t) 0x01)
#define GPIO_SPEED_FAST		((uint32_t)	0x02)
#define GPIO_SPEED_MEDIUM	((uint32_t) 0x03)
#define GPIO_SPEED_LOW		((uint32_t) 0x04)

// Clock
#define GPIO_CLOCK_ENABLE_PORTA	(RCC->AHB1ENR |= 1 << 0)
#define GPIO_CLOCK_ENABLE_PORTB	(RCC->AHB1ENR |= 1 << 1)
#define GPIO_CLOCK_ENABLE_PORTC	(RCC->AHB1ENR |= 1 << 2)
#define GPIO_CLOCK_ENABLE_PORTD	(RCC->AHB1ENR |= 1 << 3)
#define GPIO_CLOCK_ENABLE_PORTE	(RCC->AHB1ENR |= 1 << 4)
#define GPIO_CLOCK_ENABLE_PORTF	(RCC->AHB1ENR |= 1 << 5)
#define GPIO_CLOCK_ENABLE_PORTG	(RCC->AHB1ENR |= 1 << 6)
#define GPIO_CLOCK_ENABLE_PORTH	(RCC->AHB1ENR |= 1 << 7)

typedef struct
{
	GPIO_TypeDef *port;

	uint32_t pin;

	uint32_t mode;

	uint32_t mode_type;

	uint32_t pull;

	uint32_t speed;

	uint32_t alt_func;

} GPIO_TYPE;

void configure_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinMode);

void configure_pin_speed(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode);

#endif
