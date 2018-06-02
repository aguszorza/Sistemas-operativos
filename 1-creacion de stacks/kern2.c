#include "decls.h"
#include "multiboot.h"


void kmain(const multiboot_info_t* mbi) {
	if (mbi == 0) {
		vga_write("NULL", 8, 0x70);
	} else {
		vga_write("kern2 loading.............", 8, 0x70);
	}
}