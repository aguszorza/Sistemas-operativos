//void breakpoint(void);

.globl breakpoint
breakpoint:
    nop
    test %eax, %eax
    iret
