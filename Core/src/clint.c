/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
/* ==================== 静态变量声明 ==================== */
static uint32_t mtimer_period_ticks;
static volatile uint32_t mtimer_interrupt_count;
/* ==================== 私有函数声明 ==================== */
static void MTimer_ScheduleNext(void);
/* ==================== 应用层APP初始化函数 ==================== */
void U_CLINT_Init(void)
{
    mtimer_period_ticks = SMU_ClocksStruct.AXIBus0_Frequency / 1000;
    MTimer_ScheduleNext();
    __asm volatile ("csrs mie, %0" :: "r" (MIE_MTIE) : "memory");
}
/* ==================== 应用层APP任务函数 ==================== */
/*
    获取ms级tick
    由内核定时器MTIM控制中断
*/
uint32_t U_GetMtick(void)
{
    return mtimer_interrupt_count;
}
/*
    更新比较寄存器值
*/
void MTimer_ScheduleNext(void)
{
    struct TimerValue now = CLINT_ReadTimerVal();
    uint64_t next = ((uint64_t)now.TimerValHigh << 32) | now.TimerValLow;
    next += mtimer_period_ticks;
    CLINT_SetTimerComparator((uint32_t)next, (uint32_t)(next >> 32));
}
/* ==================== 中断服务任务函数 ==================== */
void MTimer_IRQ_Handler(void)
{
    // MTimer_ScheduleNext();
    // ++mtimer_interrupt_count;
}
