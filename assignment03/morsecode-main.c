
// Set up the LED
#define RCC_BASE   0x40021000
#define GPIOA_BASE 0x48000000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE   + 0x4C))) // RCC_AHB2ENR: Enable clock to GPIOA
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE +  0x0))) // GPIOA Base address: 0x48000000
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14))) // GPIOA_MODER: set GPIOA to output

#define ORD5 (1 << 5)

#define DOT_LENGTH 100000
#define DASH_LENGTH (DOT_LENGTH * 3)
#define SPACE_LENGTH (DOT_LENGTH * 7)

unsigned int counter = 0;

void dash() {
    // Turn LED on
    GPIOA_ODR |= ORD5; // GPIOB_ODR: Turn LED1 on
    
    // on for DASH_LENGTH
    counter = 0;
    while(counter < DASH_LENGTH) {
      counter++;
    }
    
    // Turn LED off
    GPIOA_ODR &= ~ORD5; // GPIOB_ODR: Turn LED1 off
    
    // off for DOT_LENGTH 
    counter = 0;
    while(counter < DOT_LENGTH) {
      counter++;
    }
}

void dot() {
    // Turn LED on 
    GPIOA_ODR |= ORD5; // GPIOB_ODR: Turn LED1 on
    
    // on for DOT_LENGTH
    counter = 0;
    while(counter < DOT_LENGTH) {
      counter++;
    }
    
    // Turn LED Off
    GPIOA_ODR &= ~ORD5; // GPIOB_ODR: Turn LED1 off
    
    // off for DOT_LENGTH
    counter = 0;
    while(counter < DOT_LENGTH) {
      counter++;
    }
}

void letterSpace() {
  counter = 0;
    while(counter < DASH_LENGTH) {
      counter++;
    }
}

void wordSpace() {
    counter = 0;
    while(counter < SPACE_LENGTH) {
      counter++;
    }
}

void main()
{
  RCC_AHB2ENR |= 0x1;
  GPIOA_MODER &= 0xFFFFF7FF; //0xFFFFF7FF bits 10-11 to 01
  
  while(1) {
    // K: - . - 
    dash();
    dot();
    dash();
    
    letterSpace();
    
    // A: . - 
    dot();
    dash();
    
    letterSpace();
    
    // T: -
    dash();
    
    // SPACE
    wordSpace();
  }
}