#include "main.hpp"
#include "gpio.hpp"
#include "delay.hpp"
#include "hardware_config.hpp"

int main()
{
  extern gpio gpio_stm32f103RC;
  gpio_plate gpio;
  gpio_init();
  // gpio_stm32f103RC.set_pin_state(GPIOC, 13, 0);

  gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D0, 0);
  gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D1, 1);
  gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D2, 1);
  gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D3, 1);
  gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D4, 1);

  while (1)
  {

    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D0, 0);
    // delay_ms(50);
    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D0, 1);

    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D1, 0);
    delay_ms(50);
    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D1, 1);

    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D2, 0);
    delay_ms(25);
    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D2, 1);

    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D3, 0);
    delay_ms(10);
    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D3, 1);

    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D4, 0);
    delay_ms(5);
    // gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D4, 1);
    // gpio_stm32f103RC.set_pin_state(GPIOC, 13, 0);

    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D0, 0);
    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D1, 1);
    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D2, 1);
    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D3, 1);
    gpio_stm32f103RC.set_pin_state(GPIOA, gpio.D4, 1);
  }
}

extern "C"
{
  void HardFault_Handler(void)
  {
    int k = 0;
    while (1)
    {
      k++;
    }
  }
}
