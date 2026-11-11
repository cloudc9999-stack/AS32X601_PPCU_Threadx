/* GCC linker script for AS32x601 (RV32IMAFDC)
 * Flash: 0x01000000, 2 MB
 * SRAM:  0x20000000, 512 KB
 */
OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x01000000, LENGTH = 2M
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 512K
}

STACK_SIZE      = 0x2000;
SECTIONS
{
    /* Code and read-only data in Flash */
    .text : {
        . = ALIGN(4);
        *(.init)
        *(.text .text.*)
        *(.rodata .rodata.*)
        . = ALIGN(4);
        _text_end = .;
    } > FLASH

    /* Initialized data: stored in Flash, copied to SRAM at startup */
    _data_load = LOADADDR(.data);
    .data : {
        . = ALIGN(4);
        _data_start = .;
        *(.data .data.*)
        *(.sdata .sdata.*)
        __global_pointer$ = . + 0x800;
        . = ALIGN(4);
        _data_end = .;
    } > SRAM AT > FLASH

    /* BSS (zero-initialized) */
    .bss : {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss .bss.*)
        *(.sbss .sbss.*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
        PROVIDE(end = .);
        PROVIDE(_end = .);
    } > SRAM

    /* Heap (between BSS and stack) */
    .heap (NOLOAD) : {
        . = ALIGN(8);
        _heap_start = .;
    } > SRAM
    /* Stack at end of SRAM */
    .stack ORIGIN(SRAM) + LENGTH(SRAM) - STACK_SIZE (NOLOAD):
    {
        . = ALIGN(8);
        _stack_bottom = .;
        _heap_end = _stack_bottom;
        . += STACK_SIZE;
        _stack_top = .;
    } > SRAM
    

    ASSERT(_stack_top <= ORIGIN(SRAM) + LENGTH(SRAM), "SRAM overflow!")
}
