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

#include "stm32f1xx.h"

// TODO: Better ways
constexpr uint32_t PINPOS[16] = {
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

// Signal definitions
#define HIGH	1
#define LOW		0

// Pin mode
#define OUTPUT_MODE		((uint32_t) 0x01)
#define INPUT_MODE		((uint32_t) 0x02)

// Input mode type
#define INPUT_ANALOG	((uint32_t) 0x00)
#define INPUT_FLOATING	((uint32_t) 0x01)
#define INPUT_PU_PD		((uint32_t) 0x02)

// Output mode type
#define OUTPUT_GENERAL_PURPOSE			((uint32_t) 0x00)
#define OUTPUT_OPEN_DRAIN				((uint32_t) 0x01)
#define OUTPUT_ALT_FUNCTION				((uint32_t) 0x02)
#define OUTPUT_ALT_FUNCTION_OPEN_DRAIN	((uint32_t) 0x03)

// Pin speeds
#define SPEED_2MHZ		((uint32_t) 0x02)
#define SPEED_10MHZ		((uint32_t) 0x01)
#define SPEED_50MHZ		((uint32_t) 0x03)

// Clock enable
#define GPIO_CLOCK_ENABLE_ALT_FUNCTION	(RCC->APB2ENR |= (1 << 0))
#define GPIO_CLOCK_ENABLE_GPIOA			(RCC->APB2ENR |= (1 << 2))
#define GPIO_CLOCK_ENABLE_GPIOB			(RCC->APB2ENR |= (1 << 3))
#define GPIO_CLOCK_ENABLE_GPIOC			(RCC->APB2ENR |= (1 << 4))
#define GPIO_CLOCK_ENABLE_GPIOD			(RCC->APB2ENR |= (1 << 5))

// High bit positions for CRH, when you add
// +2 or +3 to offset of the first bit of mode
// you can manipulate CNF bits
// TODO: Fix :)
#define CNF_POS_BIT1 	(PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2	(PINPOS[pinNumber] + 3)

class POLHAL {
public:
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

public:
	POLHAL();
	virtual ~POLHAL();

	static void gpio_init(POLHAL::GPIO_TYPE gpioType);
	static void configure_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t mode);
	static void config_pin_speed(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinSpeed, uint32_t modeType);

	static void gpio_write(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t state);
	static void gpio_toggle(GPIO_TypeDef *gpio, uint32_t pinNumber);


private:



};

#endif /* POLHAL_H_ */
