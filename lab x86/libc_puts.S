.globl main
#// #Call libcs wrappers to write(2) and _exit(2):
#//
#//    # void _exit(int status);
#//     #ssize_t write(int fd, const void *buf, size_t count);
#//
main:
        #// Call convention: arguments on the stack (reverse order).
        push $msg
        call puts
        pop %eax
        mov $7, %eax
        ret

.data
msg:
        .asciz "Hello, world!"