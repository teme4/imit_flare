#include "hardware_config.hpp"

gpio gpio_stm32f103RC;
gpio_plate gpio;

void gpio_init()
{
    // parallel BUS
    // RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    // AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE; // только SWD без JTAG
    //***************//
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio.D0, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio.D1, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio.D2, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio.D3, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOA, gpio.D4, gpio_stm32f103RC.gpio_mode_pp_50);
    gpio_stm32f103RC.gpio_conf(GPIOC, 13, gpio_stm32f103RC.gpio_mode_pp_50);
}
