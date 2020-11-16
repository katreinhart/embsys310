# Assignment 02
Kat Reinhart

1.  a. When directly addressing a bit for GPIO registers (e.g.), the compiler will create READ - MODIFY - WRITE instructions (LDR, ORRS, STR), since the individual bits cannot be modified alone.
    b. When using the bit-banding feature, the compiler will just create a single WRITE instruction (STR).

2. 
    a. The calling func2 passes the arguments to func1 by loading the first `int` into R0, then pushing that onto the stack, then loads the rest of the `int`s into R0 thru R3.
    b. Before calling `func1` from `func2`, the compiler generated instruction to push R7 and LR (link register) onto the stack. 
    c. Inside of `func1`, the compiler generated instructions to push R4-R8 and the LR onto the stack, since these were in use inside of `func2`, then a LDR instruction to load what is in SP plus 0x18, or 3 slots down in the stack, which is where that 1st of the 5 arguments ended up after pushing R7 and LR. When the fifth argument is assigned to a local variable, that value is stored in LR. 
    d. I noticed that the compiler generates ADDS.W instructions that take 3 arguments. The first one is ADDS.W R8, R6, R5. R8 is empty at this point, so it will add R6 and R5 together and store into R8. Next, it ADDS.W R8, R7, R8, so it adds R7 to the value in R8 and stores back into R8. Next one is ADDS.W R8, R12, R8; adding the value in R12 to R8 and storing in R8; now it has 0XA as the value or 10, which is the sum of 1 + 2 + 3 + 4. 
    The fifth value comes from the LR, which is where the extra argument got stored above. After ADDS.W R8, LR, R8, the value of R8 is the sum of all the values, or 15. 

My code from problem 2:
```
void func1(int arg1, int arg2, int arg3, int arg4, int arg5) {
    int a = arg1;
    int b = arg2; 
    int c = arg3;
    int d = arg4;
    int e = arg5;
    
    int f = a + b + c + d + e;
}

void func2(void) {
    func1(1, 2, 3, 4, 5);
}

void main(void) {
    func2();
}
```

