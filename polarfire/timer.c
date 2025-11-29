#include <stdint.h>

#define CLINT_BASE   0x2000000UL
#define MTIMECMP     (CLINT_BASE + 0x4000)
#define MTIME        (CLINT_BASE + 0xBFF8)
#define UART0        ((volatile char *)0x10000000UL)
#define INTERVAL     3000UL  // slower for visibility

static inline void putch(char c) { *UART0 = c; }
static void puts(const char *s){ while(*s) putch(*s++); }

__attribute__((interrupt("machine"))) void handle_trap(void) {
    puts("Timer interrupt!\n");
    uint64_t now = *(volatile uint64_t *)MTIME;
    *(volatile uint64_t *)MTIMECMP = now + INTERVAL;
}

void _start(void) {
    asm volatile("la sp, __stack_top");   // <-- set stack first

    puts("Starting timer...\n");

    uintptr_t handler_addr = (uintptr_t)&handle_trap & ~0x3UL;
    asm volatile("csrw mtvec, %0" :: "r"(handler_addr));

    asm volatile("li t0, 0x80; csrs mie, t0");     // MTIE
    asm volatile("li t0, 0x8;  csrs mstatus, t0"); // MIE

    uint64_t now = *(volatile uint64_t *)MTIME;
    *(volatile uint64_t *)MTIMECMP = now + INTERVAL;

    for(;;);
}