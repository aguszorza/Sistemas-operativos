#define PIC1 0x20
#define ACK_IRQ 0x20

.globl ack_irq
ack_irq:
    // Indicar que se manejo la interrupcion.
    movl $ACK_IRQ, %eax
    outb %al, $PIC1
    iret


.globl timer_asm
timer_asm:
        pusha
        //call timer
        popa

        jmp ack_irq

.globl keyboard_asm
keyboard_asm:
        pusha
        call keyboard
        popa

        jmp ack_irq
