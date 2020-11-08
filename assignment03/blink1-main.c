#if 1
#define RCC_BASE   0x40021000
#define GPIOA_BASE 0x48000000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE   + 0x4C))) // RCC_AHB2ENR: Enable clock to GPIOA
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE +  0x0))) // GPIOA Base address: 0x48000000
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14))) // GPIOA_MODER: set GPIOA to output

#define ORD5 (1 << 5)

unsigned int counter = 0;

void main()
{
  RCC_AHB2ENR |= 0x1;
  GPIOA_MODER &= 0xFFFFF7FF; //0xFFFFF7FF bits 10-11 to 01
  
  while(1) {
    counter = 0;
    while(counter < 100000) {
      counter++;
    }
     GPIOA_ODR |= ORD5; // GPIOB_ODR: Turn LED2 on
    
    
    
    counter = 0;
    while(counter < 100000) {
      counter++;
    }
    GPIOA_ODR &= ~ORD5; // GPIOB_ODR: Turn LED2 off
  }
}
#endif