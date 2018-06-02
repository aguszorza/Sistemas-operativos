#include <bits/errno.h>
#include <sys/syscall.h>

.globl write2
write2:
		push %ebp
    	movl %esp, %ebp

    	push %ebx  #callee saved

    	mov $SYS_write, %eax  #primer argumento, operacion

    	mov 8(%ebp), %ebx #segundo argumento

    	mov 12(%ebp), %ecx #stercer argumento

    	mov 16(%ebp), %edx #cuarto argumento

    	int $0x80

    	pop %ebx #restauro ebx


        movl %ebp, %esp
	    popl %ebp

	    ret

