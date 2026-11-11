/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
/* ==================== 静态变量声明 ==================== */
// ADC外设结构体
typedef struct 
{
    ADC_TypeDef* ADC;
}U_ADC_Typedef;
extern U_ADC_Typedef U_ADC0;
extern U_ADC_Typedef U_ADC1;
/* ==================== 私有函数声明 ==================== */

/* ==================== 应用层APP初始化函数 ==================== */
void U_ADC0_Init(void);
void U_ADC1_Init(void);
/* ==================== 应用层APP任务函数 ==================== */
/* ==================== 中断服务函数 ==================== */
/* ==================== 中断回调函数 ==================== */
void ADC_RSEQ0_EOCCallBack(U_ADC_Typedef *U_ADC);
void ADC_RSEQ1_EOCCallBack(U_ADC_Typedef *U_ADC);
void ADC_RSEQ15_EOCCallBack(U_ADC_Typedef *U_ADC);