/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/ 

/*
    
    delay(100000);
    GPIOA_ODR |= ORD5; // GPIOA_ODR: Turn LED1 on
    
    delay(100000);
    GPIOA_ODR &= ~ORD5; // GPIOA_ODR: Turn LED1 off
*/

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    // R0 contains the state (0 or 1)
    // R1 contains the delay value (i.e. 100000)
    // compute address of GPIOA_ODR:
    
    LDR    R7,=GPIOA_BASE        // Load GPIOA_BASE immediate value into R2
    LDR    R2,[R7,#GPIOA_ODR]    // Read into R2 value at R7 plus offset
    CMP    R0, #1                // Compare value in R0 to 0
    BEQ    turn_on               // If equal to zero, branch to turn_on label   
    AND    R2,R2,#GPIOA_BIT_5    // AND register 2
    BL     finish
    
turn_on
    ORR    R2,R2,#GPIOA_BIT_5    // ORR register 2 with the GPIO bit flag
    BL     finish
    
finish
    STR    R2,[R7,#GPIOA_ODR]    // Store value back to ODR
    PUSH   {R0,R1}               // Push R0 and R1 onto stack (prepare to call delay)
    MOV    R0,R1                 // Move value from R1 into R0, where delay expects it
    MOV    LR,PC                 // Move program counter into LR (so we can get back here)
    BL     delay                 // call delay
    POP    {R0, R1}
    BX     LR
    END
