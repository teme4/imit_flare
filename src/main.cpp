#include "main.hpp"
#include "gpio.hpp"
#include "hardware_config.hpp"

int main()
{
  extern gpio gpio_stm32f103RC;

  gpio_init();

  while (1)
  {
    // gpio_stm32f103RC.set_pin_state(GPIOC, mcu_led.red, 0);
    // gpio_stm32f103RC.set_pin_state(GPIOC, mcu_led.red, 1);
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
