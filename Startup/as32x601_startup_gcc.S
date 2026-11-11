/*
 * as32x601_startup_gcc.S
 * GCC/GAS-compatible startup for AS32x601 (RV32IMAFDC)
 *
 * Symbols provided by as32x601.ld:
 *   _stack_top        - initial stack pointer
 *   _data_load        - Flash load address of .data
 *   _data_start       - SRAM start of .data
 *   _data_end         - SRAM end of .data
 *   _bss_start        - start of .bss
 *   _bss_end          - end of .bss
 *   __global_pointer$ - GP base for GP-relative addressing
 */
#include "CLINT_Config.h"
    .section .init
    .global  _start
    .align   2

_start:
    .option  norvc
    /* Set global pointer */
    .option  push
    .option  norelax
    la       gp, __global_pointer$
    .option  pop

    /* Set stack pointer */
    la       sp, _stack_top

    /* Copy .data section from Flash to SRAM */
    la       a0, _data_load
    la       a1, _data_start
    la       a2, _data_end
    bgeu     a1, a2, ClearBssSection
copy_data:
    lw       t0, 0(a0)
    sw       t0, 0(a1)
    addi     a0, a0, 4
    addi     a1, a1, 4
    bltu     a1, a2, copy_data

ClearBssSection:
    /* Zero .bss section */
    la       a0, _bss_start
    la       a1, _bss_end
    bgeu     a0, a1, done_bss
zero_bss:
    sw       zero, 0(a0)
    addi     a0, a0, 4
    bltu     a0, a1, zero_bss

done_bss:
    /* Enable CPU global interrupt:
     *   mstatus[3]  MIE  = 0   disable
     *   mstatus[7]  MPIE = 1
     *   mstatus[12:11] MPP = 11 (machine mode)
     *   mstatus[14:13] FS  = 01 initial
     * Value: 0x00003880
     */
    li       a5, 0x3880
    csrw     mstatus, a5

    /* mie[11] MEIE = 1 (enable external interrupts via PLIC)
     * mie[7]  MTIE = 1 (enable MTIME interrupts via CLINT)
     * mie[3]  MSIE = 0 (disable software interrupts via CLINT)
     * Value: 0x00000880
     */
    li       a5, 0x880
    csrw     mie, a5

    /* Set trap/exception entry vector */
    la       t0, TrapEntry
    csrw     mtvec, t0
    /* Jump to main application */
    call     main

    /* Should never reach here */
loop:
    j        loop
