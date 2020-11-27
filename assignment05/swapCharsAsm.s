/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for division
*******************************************************************************/   
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
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
Function Name   : swapCharsAsm
Description     : Swaps two characters (input)
C Prototype     : int swapCharsAsm(char1, char2)
Parameters      : R0, R1: pointer of chars
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0-R2,LR}     // save the input arguments and return address
    LDR R0,[R0]         // load address of char1 into R0
    LDR R2,[R1]         // load address of char2 into R2
    LDR R1,[R0]         // load contents of char1 into R1
    LDR R0,[R2]         // load contents of char2 into R0
    POP {R0-R1,LR}      // Restore R0 and LR

    END
