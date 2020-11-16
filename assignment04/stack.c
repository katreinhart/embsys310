#include "stack.h"

#define STACK_SIZE 16

int StackStore[STACK_SIZE];

int stack_top;

void stack_init(void) {
  stack_top = -1;
  for(int i=0; i < STACK_SIZE; i++){
    StackStore[i] = 0;
  }
}

int stack_push(int a){
  if (stack_full()) {
    return -1;
  }
  
  StackStore[++stack_top] = a;
  
  return 0;
}

int stack_pop(int* a){
  if (stack_empty()) {
    return -1;
  }
  
  *a = StackStore[stack_top--];
  return 0;
}

int stack_full(void){
  return stack_top >= STACK_SIZE;
}

int stack_empty(void){
  return stack_top == -1;
}