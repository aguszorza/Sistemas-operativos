
.text
.align 4
.globl task_exec
task_exec:
        // Preámbulo estándar
        push %ebp
        movl %esp, %ebp

        movl 8(%ebp), %ecx //entry
        movl 12(%ebp), %eax //stack

        leal 0(%eax), %esp
        call *%ecx

        // Restaurar registros callee-saved, si se usaron.
        movl %ebp, %esp
	popl %ebp

        ret
