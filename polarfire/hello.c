#define UART0 ((volatile char *)0x10000000UL)
static inline void putch(char c){ *UART0 = c; }

void _start(void){
    const char *s = "Hello RISC-V!\n";
    while(*s) putch(*s++);
    for(;;);
}