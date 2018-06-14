#include "decls.h"

#define USTACK_SIZE 4096

void kmain(const multiboot_info_t *mbi) {
    vga_write("kern2 loading.............", 8, 0x70);

    if (mbi && mbi->flags) {
        char buf[256] = "cmdline: ";
        char *cmdline = (void *) mbi->cmdline;

        strlcat (buf, cmdline, sizeof(buf));
        vga_write(buf, 9, 0x07);

        print_memory(mbi);
    }

    two_stacks();
    two_stacks_c();

    /////////////////contador_run();


    idt_init();
    asm("int3");

    vga_write2("Funciona vga_write2?", 18, 0xE0);
}


