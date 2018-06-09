// tasks.S
.globl vga_write2
vga_write2:
        push %ebp
        movl %esp, %ebp

        push %ecx
        push %edx
        push %eax
        call vga_write

        leave
        ret


.globl task_swap
task_swap:
	push %ebp
	push %ebx
	push %edi
	push %esi

	movl 20(%esp), %eax //eax = puntero a esp siguiente


    movl %esp, %ecx
    movl 0(%eax), %esp
    movl %ecx, 0(%eax)
        
    pop %esi
	pop %edi
	pop %ebx
	pop %ebp

	ret
