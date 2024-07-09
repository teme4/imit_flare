#ifndef _PIN_CONFIG_STM32
#define _PIN_CONFIG_STM32

#include <stm32f1xx.h>
#include "gpio.hpp"

struct gpio_plate
{
    uint8_t D0 = 0;
    uint8_t D1 = 1;
    uint8_t D2 = 2;
    uint8_t D3 = 3;
    uint8_t D4 = 4;
};
void gpio_init(void);
#endif // #endif//_PIN_STM32
