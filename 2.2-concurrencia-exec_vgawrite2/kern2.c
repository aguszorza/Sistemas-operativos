#include "decls.h"
#include "multiboot.h"

#define USTACK_SIZE 4096

void kmain(const multiboot_info_t *mbi) {
    vga_write("kern2 loading.............", 8, 0x70);

    two_stacks();
    two_stacks_c();

    vga_write2("Funciona vga_write2?", 18, 0xE0);
}

