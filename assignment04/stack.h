#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int stack_push(int);
int stack_pop(int*);
int stack_full(void);
int stack_empty(void);

#endif