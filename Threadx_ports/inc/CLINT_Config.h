/*
 *      Author: cloudc
 *
 * 
 * 
*/

    .equ         SMU_AXIBUS0_FREQUENCY,           180000000
    .equ         MTIMER_PERIOD_TICK,              (SMU_AXIBUS0_FREQUENCY / 1000)
    .equ         MTimerCMPRegister,               0x30014000
    .equ         MTimerRDRegister,                0x3001BFF8
/* 被trapentry使用和_tx_initialize_low_level.S */
.macro      UPDATE_MTIMER_COMPARE_REGISTER
    /* t3 = cmp地址 */
    lw      t0, first_NextTimeAddr
    lw      t1, 0(t0)
    beqz    t1, no_first

    /* 第一次进入mtime中断 */
    sw      x0, 0(t0)
    li      t0, MTimerRDRegister
    lw      t1, 0(t0)               /* t1低32位，t2高32位 */
    lw      t2, 4(t0)
    lw      t0, NextTimeAddr 
    j       update_next
no_first:
    lw      t0, NextTimeAddr
    lw      t1, 0(t0)
    lw      t2, 4(t0)
update_next:
    li      t3, MTIMER_PERIOD_TICK
    add     t4, t1, t3              /* t4 = 低32位新值 */
    sltu    t5, t4, t1              /* 如果新值小于旧值，说明需要进位,t5 = 1 否则, t5 = 0*/
    add     t2, t2, t5              /* 更新t2高32位 */
    sw      t4, 0(t0)               /* 写入下一次next值 */
    sw      t2, 4(t0)    

    li      t0, MTimerCMPRegister   /* 写入cmp寄存器 */
    li      t1, 0xFFFFFFFF
    sw      t1, 0(t0)
    sw      t2, 4(t0)
    sw      t4, 0(t0)
.endm

.macro      WRITE_COMPARE_REGISTER
    li      t0, MTimerCMPRegister
    li      t1, MTIMER_PERIOD_TICK
    sw      t1, 0(t0)
    sw      x0, 4(t0)
.endm














