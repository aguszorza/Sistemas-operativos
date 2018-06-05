#include "decls.h"

#define COUNTLEN 20
#define TICKS (1ULL << 15)
#define DELAY(x) (TICKS << (x))
#define USTACK_SIZE 4096

static volatile char *const VGABUF = (volatile void *) 0xb8000;

static uintptr_t esp;
static uint32_t stack1[USTACK_SIZE] __attribute__((aligned(4096)));
static uint32_t stack2[USTACK_SIZE] __attribute__((aligned(4096)));

static void yield() {
    if (esp)
        task_swap(&esp);
}

static void contador_yield(unsigned lim, uint8_t linea, char color) {
    char counter[COUNTLEN] = {'0'};  // ASCII digit counter (RTL).

    while (lim--) {
        char *c = &counter[COUNTLEN];
        volatile char *buf = VGABUF + 160 * linea + 2 * (80 - COUNTLEN);

        unsigned p = 0;
        unsigned long long i = 0;

        while (i++ < DELAY(8))  // Usar un entero menor si va demasiado lento.
            ;

        while (counter[p] == '9') {
            counter[p++] = '0';
        }

        if (!counter[p]++) {
            counter[p] = '1';
        }

        while (c-- > counter) {
            *buf++ = *c;
            *buf++ = color;
        }

        yield();
    }
}

void halt();

void contador_run() {

    uintptr_t *a = stack1 + USTACK_SIZE;
    uintptr_t *b = stack2 + USTACK_SIZE;

    *(--a) = 0x2F;
    *(--a) = 0;
    *(--a) = 100;

    *(--b) = 0x4F;
    *(--b) = 1;
    *(--b) = 100;

    *(--b) = (uintptr_t)halt;
    *(--b) = (uintptr_t)contador_yield;


    esp = (uintptr_t)b;

    task_exec((uintptr_t) contador_yield, (uintptr_t) a);

    //contador_yield(100, 0, 0x2F);
    //contador_yield(100, 1, 0x4F);
}
