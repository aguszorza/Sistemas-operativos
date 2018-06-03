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
	push %ebx
	push %esi
	push %edi

	movl 16(%esp), %esi

	movl (%esi), %ebx //guardo el esp siguiente
	movl %esp, (%esi)
	movl %ebx, %esp

	pop %edi
	pop %esi
	pop %ebx

	ret
