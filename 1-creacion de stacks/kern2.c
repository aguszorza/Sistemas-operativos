#include "decls.h"
#include "multiboot.h"
#include "lib/string.h"

#define BUF_SIZE 256

void kmain(const multiboot_info_t* mbi) {
	vga_write("kern2 loading.............", 8, 0x70);

	if (mbi->flags) {
        char buf[BUF_SIZE] = "cmdline: ";
        char *cmdline = (void *) mbi->cmdline;
        // Aquí usar strlcat() para concatenar cmdline a buf.
        strlcat (buf + strlen(buf), cmdline, BUF_SIZE - strlen(buf));
        vga_write(buf, 9, 0x07);
    }

}