# Assignment 02
Kat Reinhart

1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
a) What is the value of the “counter” from the “Locals” window? 
    -2147483648 
b) What is the value of the “counter” in the “Registers” window?
    0x80000000
c) Please note down if the N and/or V flags are set in the APSR register. And explain why. 
    N & V are both 1.
    N is 1 because the result of the last operation is negative.
    V is 1 because the last operation caused an overflow.


2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
a) What happens to the value of “counter” in the “Locals” window?
    It goes from -1 (0xFFFFFFFF) to 0 (0x00000000)
b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
    N is not set, because the result is not negative, it is zero.
    V is also not set, because it was not an overflow (the two results are contiguous)
    The Z and C registers are set, indicating zero (0) and carry (since 0xFFFFFFFF would carry into the next nibble).


3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?
    2147483648
b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
    N and V flags are both set, which I was not expecting. Maybe these register status bits are treated differently with unsigned ints - treated as ints by the CPU and unsigned elsewhere?
    I reran the condition a few times and got the same result each time. 

    After reading about this, it looks like the CPU does not distinguish between signed and unsigned ints, so my hypothesis was correct. The N and V flags are set, because if it were a signed int, it would have overflowed and been negative. And the C and Z registers are not set, because it is not zero and there was not a carry from the last operation on the leftmost bit.

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?
    0
b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
    Neither N nor V are set. Z and C are both set. Again this result is surprising to me. I assume it is the same reason as above, where unsigned ints are treated the same as regular ints by the CPU, but translated differently in different contexts.

    Same as with the above answer, this is expected due to the lack of distinction between signed and unsigned ints at the CPU level. The Z and C flags are set because it carried over the last bit (C) and the result was a zero (Z) - in a signed integer. It's up to us and the compiler, not the CPU, to know the difference between signed and unsigned ints.

5. Move the “counter’ variable outside of main (at the top of the file):
a) What is the scope of the variable “counter”?
    Global
b) Is it still visible in the “Locals” view?
    No
c) In which window view can we track “counter” now?
    It is in the "Memory" view
d) What is the address of the “counter” variable in memory?
    0x20000000

6.Change the source code to the following, then run the program in the simulator:
a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
    counter value = 4
b) Explain why the counter value has changed?
    The pointer *p_int is set to the memory address of the counter variable (0x20000000). The next 3 lines dereference the pointer and increment the value stored at its address (which is the same as counter). The last line, `counter++`, also increments this same value, because it is stored in the same slot in memory. So `counter++` and `++(*p_int)` have the same effect in this instance. 

7. Change the setting of IAR to run the same program on the evaluation board:
a) What is the address where “counter” is stored?
    0x2000000
b) Is the “counter” variable stored in RAM or ROM?
    RAM
c) What is the value of “counter” at the end of the program (halting at the return 0 statement).
    4
