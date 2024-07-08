#ifndef _PIN_CONFIG_STM32
#define _PIN_CONFIG_STM32

#include <stm32f1xx.h>
#include "gpio.hpp"

struct gpio_lcd_oled
{
    uint8_t D0 = 0;
    uint8_t D1 = 1;
    uint8_t D2 = 2;
    uint8_t D3 = 3;
    uint8_t D4 = 4;
    uint8_t D5 = 5;
    uint8_t D6 = 6;
    uint8_t D7 = 7;
    uint8_t RW = 15;
    uint8_t EN = 12;
    uint8_t RS = 11;
};
void gpio_init(void);
#endif // #endif//_PIN_STM32
