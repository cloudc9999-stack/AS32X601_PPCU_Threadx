/*
 *  Author: cloudc
 *
 * 
 * 
 * 
 */
#ifndef TIM_H
#define TIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* =========================== 库函数包含 ======================= */
#include "main.h"







/* =========================== 定时器初始化函数 ======================= */
void U_TIM6_Init(void);
void U_TIM0_Init(void);
void U_TIM2_Init(void);
void U_TIM1_Init(void);
void U_TIM5_Init(void);
/* =========================== 定时器外部调用函数 ======================= */
void U_Delay(uint32_t delaytime);
uint32_t U_GetTick(void);
/* =========================== 定时器中断回调函数 ======================= */





#ifdef __cplusplus
}
#endif

#endif