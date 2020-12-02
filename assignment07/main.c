#if 1
#include <stdint.h>
#include "stm32l475xx.h"


#define SYS_CLOCK_HZ 4000000

void delay(uint32_t delay_in_ms);
void SysTick_Initialize();

uint32_t delay_counter;

void main()
{
  delay_counter = 0;
  
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  SysTick_Initialize();
  
  while(1) {
    delay(1000);
  }
}

void delay(uint32_t delay_in_ms) {
  if (delay_counter >= delay_in_ms) {
    GPIOA->ODR ^= GPIO_ODR_OD5;
    delay_counter = 0;
  }
}

void SysTick_Initialize(){
  SysTick->LOAD = SYS_CLOCK_HZ / 1000;
  SysTick->VAL = 0x0;
  SysTick->CTRL = 0x7;
}

void SysTick_Handler(void) {
  __disable_irq();
  delay_counter++;
  __enable_irq();
}

#endif
