#include "hardware_config.hpp"

gpio gpio_stm32f103RC;
gpio_lcd_oled gpio_lcds;

void gpio_init()
{
    // parallel BUS
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE; // только SWD без JTAG
                                                 //***************//
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D0, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D1, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D2, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D3, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D4, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D5, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D6, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio_lcds.D7, gpio_stm32f103RC.gpio_mode_pp_50);
}
