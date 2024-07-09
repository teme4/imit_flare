#include "main.hpp"
#include "gpio.hpp"
#include "hardware_config.hpp"

void SystemInit (void)
{
  /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
  /* Set HSION bit */
  RCC->CR |= 0x00000001U;



  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= 0xFEF6FFFFU;

  /* Reset HSEBYP bit */
  RCC->CR &= 0xFFFBFFFFU;

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
  RCC->CFGR &= 0xFF80FFFFU;


  /* Reset PLL2ON and PLL3ON bits */
  RCC->CR &= 0xEBFFFFFFU;

  /* Disable all interrupts and clear pending bits  */
  RCC->CIR = 0x00FF0000U;

  /* Reset CFGR2 register */

  RCC->CIR = 0x009F0000U;

  // SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */

}
int main()
{
  SystemInit();
  extern gpio gpio_stm32f103RC;
  gpio_init();

  while (1)
  {
    gpio_stm32f103RC.set_pin_state(GPIOB, 3, 0);
    gpio_stm32f103RC.set_pin_state(GPIOB, 3, 1);
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
