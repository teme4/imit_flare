#ifndef _PIN_MASK_FOR_74HC165_
#define _PIN_MASK_FOR_74HC165_

#include "gpio.hpp"

void gpio::  Set_pin_H(GPIO_TypeDef *port,uint8_t pin)
{
  port->BSRR = (1<<pin);
}

void  gpio:: Set_pin_L(GPIO_TypeDef *port,uint8_t pin)
{
  port->BSRR = (1<<pin+16);
}
void gpio::gpio_conf(GPIO_TypeDef * port, uint32_t pin, uint8_t mode)
{
 RCC->APB2ENR |= (1 << (((uint32_t)port - APB2PERIPH_BASE) / 0x400));
 if (pin > 7){
  port->CRH &= ~(0xf  << ((pin - 8) * 4));
  port->CRH |= mode << ((pin - 8) * 4);
 }
 else{
  port->CRL &= ~(0xf << (pin * 4));
  port->CRL |= mode << (pin * 4);
 }
}

 void gpio::set_pin_state(GPIO_TypeDef *GPIOx,uint8_t pin,uint8_t state)
 {
    if(state==1)
    gpio::Set_pin_H(GPIOx,pin);
    if(state==0)
    gpio::Set_pin_L(GPIOx,pin);
 }

 int gpio:: get_state_pin (GPIO_TypeDef *port, uint8_t pin)
{
	if ((port->IDR) &(1<< pin))
    {
        return 1;
    }
	else 
    {
        return 0;
    }
}
#endif