
#include "decls.h"
#include "interrupts.h"

#define IDT_DESCRIPTORS 256

static struct IDTR idtr;
static struct Gate idt[IDT_DESCRIPTORS];



void idt_init(){
	idtr.base = (uintptr_t) idt;
	idtr.limit = IDT_DESCRIPTORS * 8 - 1;

	asm("lidt %0" : : "m"(idtr)); //activar el uso de la IDT configurada
}


void idt_install(uint8_t n, void (*handler)(void));