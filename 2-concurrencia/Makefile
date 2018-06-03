CFLAGS := -g -std=c99 -Wall -Wextra -Wpedantic
CFLAGS += -m32 -O1 -ffreestanding

#########CPPFLAGS += -nostdinc -idirafter lib

########GCC_PATH := /usr/lib/gcc/x86_64-linux-gnu/6
#####CPPFLAGS += -I$(GCC_PATH)/include -I$(GCC_PATH)/include-fixed

SRCS := $(wildcard *.c)  # usar wildcard *.c
SRCS += $(wildcard lib/*.c)  # usar wildcard *.c
OBJS := $(patsubst %.c,%.o,$(SRCS))  # usar patsubst sobre SRCS

SRCSS := $(wildcard *.S)  # usar wildcard *.c
OBJSS := $(patsubst %.S,%.o,$(SRCSS))  # usar patsubst sobre SRCS

QEMU := qemu-system-i386 -serial mon:stdio
KERN := kern2
BOOT := -kernel $(KERN) $(QEMU_EXTRA)

LIBGCC := $(shell $(CC) $(CFLAGS) -print-libgcc-file-name)

qemu: $(KERN)
	$(QEMU) $(BOOT)

qemu-gdb: $(KERN)
	$(QEMU) -kernel kern0 -S -gdb tcp:127.0.0.1:7508 $(BOOT)

gdb:
	gdb -q -s kern0 -n -ex 'target remote 127.0.0.1:7508'

.PHONY: qemu qemu-gdb gdb

kern2: $(OBJSS) $(OBJS) 
	ld -m elf_i386 -Ttext 0x100000 $^ $(LIBGCC) -o $@
	# Verificar imagen Multiboot v1.
	grub-file --is-x86-multiboot $@

%.o: %.S
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f kern2 *.o core

.PHONY: clean
