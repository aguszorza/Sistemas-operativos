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

	movl 4(%esp), %eax

	movl 0(%eax), %ecx //guardo el esp siguiente
	movl %esp, 0(%eax)
	movl %ecx, %esp


	ret
