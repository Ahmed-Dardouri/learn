/* Minimal RISC-V bare-metal linker script for QEMU virt */
ENTRY(_start)

MEMORY
{
  RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS
{
  /* Code + read-only data live together for simplicity */
  .text : ALIGN(4)
  {
    KEEP(*(.init))
    *(.text .text.*)
    *(.rodata .rodata.*)
  } > RAM

  /* Read-write data */
  .data : ALIGN(4)
  {
    *(.sdata .sdata.*)
    *(.data .data.*)
    *(.srodata .srodata.*)
  } > RAM

  /* Zero-initialized data */
  .bss (NOLOAD) : ALIGN(4)
  {
    __bss_start = .;
    *(.sbss .sbss.*)
    *(.bss .bss.*)
    *(COMMON)
    __bss_end = .;
  } > RAM

  /* Simple symbols for heap/stack if you add startup later */
  . = ALIGN(16);
  __heap_start = .;
  __stack_top  = ORIGIN(RAM) + LENGTH(RAM);
}
