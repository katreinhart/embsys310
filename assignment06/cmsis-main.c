#if 1
#include "stm32l475xx.h"

void delay(int cycles);

void main()
{

  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  while(1) {
    delay(100000);
    GPIOA->ODR |= GPIO_ODR_OD5; // GPIOB_ODR: Turn LED1 on
    
    delay(100000);
    GPIOA->ODR &= ~GPIO_ODR_OD5; // GPIOB_ODR: Turn LED1 off
  }

}

void delay(int cycles) {
  unsigned int counter = 0;
  while(counter < cycles) {
    counter++;
  }
}
#endif