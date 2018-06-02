.globl main

main:
        mov $1, %ebx		#ebx = palabra actual
        mov 4(%esp), %ecx  #ecx = argc
        mov 8(%esp), %edi  #edi = argv
        add $4, %edi
        push %ecx
for:
		push (%edi)
        call puts
        pop %eax
        add $4, %edi
        add $1, %ebx
        cmp %ebx, (%esp)
        jne for
        pop %ecx
        mov %ecx, %eax
        sub $1, %eax
        ret
