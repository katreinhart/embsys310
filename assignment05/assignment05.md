# Assignment 05
Kat Reinhart

1. 

```c
// Swap Pointers
void swapPtr(int* ptr1, int* ptr2) {
  int* temp = ptr1;
  ptr1 = ptr2;
  ptr2 = temp;
}
```

a. First, it moves the number #1 into R0, then stores the value from R0 (#1) into the address at the stack pointer plus offset of 4 (size of int). Next it moves the number #2 into R0, then stores it into the address at the stack pointer. Then it moves the stack pointer into R1 and adds the address in the stack pointer and the number 4 (size of int) and stores this in R0. Then it branches to the swapPtr method.
b.  R0 contains 0x200003FC and R1 contains 0x200003F8.
c. ![stack](./stack.png)

2.

