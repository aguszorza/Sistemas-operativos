#include "decls.h"
#include "multiboot.h"

#define COLUMNS 80
#define ROWS 25

#define VGABUF ((volatile char *) 0xB8000)

void vga_write(const char *s, int8_t linea, uint8_t color) {
/*	if (linea < 0) {
		linea = ROWS + linea;
	}*/
	volatile char* buff = VGABUF + linea * COLUMNS * 2;
	while (*s != '\0') {
		*buff++ = *s++;
		*buff++ = color;
	}
}

void kmain(const multiboot_info_t* mbi) {
	if (mbi == 0) {
		vga_write("NULL", 8, 0x70);
	} else {
		vga_write("Kernel loading.......", 8, 0x70);
	}
}
