#include "decls.h"
#include "multiboot.h"
#include "lib/string.h"

void print_memory(const multiboot_info_t* mbi){
	char mem[256] = "Physical memory: ";
	char tmp[64] = "";

	int size = (mbi->mem_upper - mbi->mem_lower) >> 10;
	if (fmt_int(size, tmp, sizeof tmp)) {
	    strlcat(mem, tmp, sizeof mem);
	    strlcat(mem, " MiB total", sizeof mem);
	}

	char tmp2[64] = "";
	if (fmt_int(mbi->mem_lower, tmp2, sizeof tmp2)) {
		strlcat(mem, " (", sizeof mem);
	    strlcat(mem, tmp2, sizeof mem);
	    strlcat(mem, " KiB base", sizeof mem);
	}

	char tmp3[64] = "";
	if (fmt_int(mbi->mem_upper, tmp3, sizeof tmp3)) {
		strlcat(mem, " , ", sizeof mem);
	    strlcat(mem, tmp3, sizeof mem);
	    strlcat(mem, " KiB extended) ", sizeof mem);
	}

	vga_write(mem, 10, 0x07);

}

void kmain(const multiboot_info_t* mbi) {
	vga_write("kern2 loading.............", 8, 0x70);

	if (mbi->flags) {
        char buf[256] = "cmdline: ";
        char *cmdline = (void *) mbi->cmdline;
        // Aquí usar strlcat() para concatenar cmdline a buf.
        strlcat (buf, cmdline, sizeof(buf));
        vga_write(buf, 9, 0x07);

        print_memory(mbi);
    }

}
