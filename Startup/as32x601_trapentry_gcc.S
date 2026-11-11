/*
 * as32x601_trapentry_gcc.S
 * GCC/GAS-compatible trap/interrupt entry for AS32x601
 * Converted from IAR-syntax as32x601_trapentry.S
 */
#include "tx_port.h"
#include "CLINT_Config.h"
//
.equ    TX_TRAP_FRAME_SIZE, TX_RISCV_TRAP_FRAME_SIZE


    .section .text.entry
    .align   2
    .global  TrapEntry
    .extern led_test

/*
 * TrapEntry - trap/interrupt handler entry point
 * Saves context, calls PLIC_TrapHandler(mcause), restores context
 */
TrapEntry:
    addi    sp, sp, -TX_TRAP_FRAME_SIZE     /* 申请保存栈空间 */
    sw      ra, 28*4(sp)                    /* 提前保存ra，否则call后会覆盖ra值 */
    call    _tx_thread_context_save         /* 保存上下文 */
    csrr    a0, mcause                      /* 读取mcause到a0 */
    li      t0, 0x80000007                  /* 0x80000007 = 机器定时器中断 */                  
    beq     a0, t0, Mtime_handler           /* 如果a0 = t0, 则是MTime中断 */
    
    call    PLIC_TrapHandler                /* 正常进入PLIC中断 */
    j       Context_Restore                 /* 恢复上下文 */


Mtime_handler:
    UPDATE_MTIMER_COMPARE_REGISTER
    call    _tx_timer_interrupt
    j       Context_Restore                 /* 恢复上下文 */


Context_Restore:
    j       _tx_thread_context_restore



