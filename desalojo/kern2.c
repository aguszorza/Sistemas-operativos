#include "decls.h"

#define USTACK_SIZE 4096

void kmain(const multiboot_info_t *mbi) {
    vga_write("kern2 loading.............", 8, 0x70);

    idt_init();
    irq_init();
}


