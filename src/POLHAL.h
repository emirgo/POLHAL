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

#ifndef POLHAL_H_
#define POLHAL_H_

#include "stm32f4xx.h"

// TODO: Find better ways than symbolic definitions
// Signal definitions
#define HIGH	1
#define LOW		0

// Pin speeds
#define SPEED_2MHZ		((uint32_t) 0x02)
#define SPEED_10MHZ		((uint32_t) 0x01)
#define SPEED_50MHZ		((uint32_t) 0x03)

// Clock enable
#define GPIO_CLOCK_ENABLE_GPIOA			(RCC->AHB1ENR |= (1 << 0))
#define GPIO_CLOCK_ENABLE_GPIOB			(RCC->AHB1ENR |= (1 << 1))
#define GPIO_CLOCK_ENABLE_GPIOC			(RCC->AHB1ENR |= (1 << 2))
#define GPIO_CLOCK_ENABLE_GPIOD			(RCC->AHB1ENR |= (1 << 3))
#define GPIO_CLOCK_ENABLE_GPIOE			(RCC->AHB1ENR |= (1 << 4))
#define GPIO_CLOCK_ENABLE_GPIOF			(RCC->AHB1ENR |= (1 << 5))
#define GPIO_CLOCK_ENABLE_GPIOG			(RCC->AHB1ENR |= (1 << 6))
#define GPIO_CLOCK_ENABLE_GPIOH			(RCC->AHB1ENR |= (1 << 7))

// High bit positions for CRH, when you add
// +2 or +3 to offset of the first bit of mode
// you can manipulate CNF bits
#define CNF_POS_BIT1 	(PINPOS[pin_number] + 2)
#define CNF_POS_BIT2	(PINPOS[pin_number] + 3)

class POLHAL {
public:
	POLHAL();
	virtual ~POLHAL();

public:
	// GPIO Modes
	typedef enum
	{
		INPUT_MODE = 0x00,
		OUTPUT_MODE = 0x01,
		ALTERNATE_FUNCTION = 0x10,
		ANALOG_MODE = 0x11
	} GPIO_MODE;

	// Output type
	typedef enum
	{
		PUSH_PULL = 0,
		OPEN_DRAIN
	} GPIO_OUTPUT_TYPE;

	typedef enum
	{
		LOW_SPEED = 0,
		MEDIUM_SPEED,
		FAST_SPEED,
		HIGH_SPEED
	} GPIO_OUTPUT_SPEED;

	// GPIO Config structure
	typedef struct
	{
		GPIO_TypeDef *gpio;
		uint32_t pin;
		GPIO_MODE mode;
		GPIO_OUTPUT_TYPE output_type;
		GPIO_OUTPUT_SPEED speed;
	} GPIO_TYPE;

public:
	static void gpio_init(POLHAL::GPIO_TYPE gpio_type);
	static void configure_pin(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_MODE mode, POLHAL::GPIO_OUTPUT_TYPE gpio_output_type);
	static void config_pin_speed(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_OUTPUT_SPEED gpio_output_speed);

	static void gpio_write(GPIO_TypeDef *gpio, uint32_t pin_number, uint32_t state);
	static void gpio_toggle(GPIO_TypeDef *gpio, uint32_t pin_number);

public:
	void gpio_set_mode(GPIO_TypeDef *gpio, uint32_t pin_number, GPIO_MODE mode);
	void configure_output_type(GPIO_TypeDef *gpio, uint32_t pin_number, POLHAL::GPIO_OUTPUT_TYPE gpio_output_type);

private:



};

#endif /* POLHAL_H_ */
