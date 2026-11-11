/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "adc.h"
#include "main.h"
/* ==================== 静态变量声明 ==================== */
U_ADC_Typedef U_ADC0;
U_ADC_Typedef U_ADC1;
/* ==================== 私有函数声明 ==================== */
static void ADC_IRQ_Handler(U_ADC_Typedef *U_ADC);
/* ==================== 应用层APP初始化函数 ==================== */

void U_ADC0_Init(void)
{
    ADC0_CLK_ENABLE();

    ADC_InitTypeDef  ADC_InitStructure;
    PLIC_InitTypeDef PLIC_InitStruct;
    U_ADC0.ADC = ADC0;
    // ADC初始化
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_ClockDivide = ADC_CLK_DIVIDE_1;                   // 时钟4分频
    ADC_InitStructure.ADC_Resolution = ADC_RESOLUTION_12BIT;                // 采样分辨率12位
    ADC_InitStructure.ADC_Alignment = ADC_DATA_ALIGN_RIGHT;                 // 数据右对齐
    ADC_InitStructure.ADC_Symbol = ADC_DATA_SELDO_UNSIGNED;                 // 无符号数据格式

    ADC_InitStructure.ADC_RegularTrigger = ADC_TRIGGER_EXTERNAL_2;          // 常规组：外部触发 HTIM0.CHx(2)
    ADC_InitStructure.ADC_InjectTrigger = ADC_TRIGGER_INTERNAL;             // 注射组：内部触发器
    
    ADC_InitStructure.ADC_RegularEnable = ENABLE ;                          // 启用常规组转换
    ADC_InitStructure.ADC_InjectEnable = DISABLE;                           // 禁用注入组转换
    
    ADC_InitStructure.ADC_DmaEnable = DISABLE;                              // 禁用DMA传输
    
    ADC_InitStructure.ADC_TtrimRef = ADC_TTRIM_7;                           // 设置内置参考电压温度比
    ADC_InitStructure.ADC_VtrimRef = ADC_VTRIM_14;                          // 设置内置参考电压输出
    ADC_InitStructure.ADC_SelvRefbiRef = ADC_SEL_VREFBI_2V5;                // 设置内置参考输出电压
    ADC_InitStructure.ADC_VrefbiEnable = DISABLE;                           // 禁用ADC内置参考电压
    ADC_InitStructure.ADC_SelvihdlsRef  = ADC_SAR_INPUT_SINGLE_ENDED;       // 设置SAR输入类型 --->分为单端输入和差分输入
    // 采样模式1 0b 00000
    ADC_InitStructure.ADC_IntervalModeEn = DISABLE;                         // 禁用间隔模式
    ADC_InitStructure.ADC_ScanModeEn = DISABLE;                              // 启用扫描模式（多通道）
    ADC_InitStructure.ADC_ContinuousModeEn = DISABLE;                        // 启用连续转换模式
    ADC_InitStructure.ADC_RegularDiscontinuousModeEn = DISABLE;             // 禁用常规不连续模式
    ADC_InitStructure.ADC_InjectDiscontinuousModeEn = DISABLE;              // 禁用注入不连续模式
    ADC_InitStructure.ADC_InjectAutoModeEn = DISABLE;                       // 禁用注入自动模式
    
    ADC_InitStructure.ADC_RegularSequenceLength = 6;                        // 常规序列长度
    ADC_InitStructure.ADC_InjectSequenceLength = 0;                         // 注入序列长度

    ADC_InitStructure.ADC_PowerEn = ENABLE;                                 // 启用ADC模拟模块电源
    ADC_InitStructure.ADC_PowerRegain = ENABLE;                             // ADC复位使能
    ADC_InitStructure.ADC_BufEn = DISABLE;                                  // 取消标记ADC外部参考输入缓冲区
    ADC_Init(ADC0, &ADC_InitStructure);
    // 初始化中断配置
    PLIC_InitStruct.PLIC_IRQChannel = ADC0_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 4;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}
void U_ADC1_Init(void)
{
    ADC1_CLK_ENABLE();
    ADC_InitTypeDef  ADC_InitStructure;
    PLIC_InitTypeDef PLIC_InitStruct;
    // 初始化结构体
    U_ADC1.ADC = ADC1;
    // ADC初始化
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_ClockDivide = ADC_CLK_DIVIDE_4;                   // 时钟4分频
    ADC_InitStructure.ADC_Resolution = ADC_RESOLUTION_12BIT;                // 采样分辨率12位
    ADC_InitStructure.ADC_Alignment = ADC_DATA_ALIGN_RIGHT;                 // 数据右对齐
    ADC_InitStructure.ADC_Symbol = ADC_DATA_SELDO_UNSIGNED;                 // 无符号数据格式

    ADC_InitStructure.ADC_RegularTrigger = ADC_TRIGGER_INTERNAL;            // 常规组：内部触发
    ADC_InitStructure.ADC_InjectTrigger = ADC_TRIGGER_INTERNAL;             // 注射组：内部触发器
    
    ADC_InitStructure.ADC_RegularEnable = ENABLE ;                          // 启用常规组转换
    ADC_InitStructure.ADC_InjectEnable = DISABLE;                           // 禁用注入组转换
    
    ADC_InitStructure.ADC_DmaEnable = DISABLE;                              // 禁用DMA传输
    
    ADC_InitStructure.ADC_TtrimRef = ADC_TTRIM_7;                           // 设置内置参考电压温度比
    ADC_InitStructure.ADC_VtrimRef = ADC_VTRIM_14;                          // 设置内置参考电压输出
    ADC_InitStructure.ADC_SelvRefbiRef = ADC_SEL_VREFBI_2V5;                // 设置内置参考输出电压
    ADC_InitStructure.ADC_VrefbiEnable = DISABLE;                           // 禁用ADC内置参考电压
    ADC_InitStructure.ADC_SelvihdlsRef  = ADC_SAR_INPUT_SINGLE_ENDED;       // 设置SAR输入类型 --->分为单端输入和差分输入

    ADC_InitStructure.ADC_ScanModeEn = ENABLE;                              // 启用扫描模式（多通道）
    ADC_InitStructure.ADC_ContinuousModeEn = ENABLE;                        // 启用连续转换模式
    ADC_InitStructure.ADC_RegularDiscontinuousModeEn = DISABLE;             // 禁用常规不连续模式
    ADC_InitStructure.ADC_InjectDiscontinuousModeEn = DISABLE;              // 禁用注入不连续模式
    ADC_InitStructure.ADC_InjectAutoModeEn = DISABLE;                       // 禁用注入自动模式
    ADC_InitStructure.ADC_IntervalModeEn = DISABLE;                         // 禁用间隔模式
    
    ADC_InitStructure.ADC_RegularSequenceLength = 6;                        // 常规序列长度
    ADC_InitStructure.ADC_InjectSequenceLength = 0;                         // 注入序列长度

    ADC_InitStructure.ADC_PowerEn = ENABLE;                                 // 启用ADC模拟模块电源
    ADC_InitStructure.ADC_PowerRegain = ENABLE;                             // ADC复位使能
    ADC_InitStructure.ADC_BufEn = DISABLE;                                  // 取消标记ADC外部参考输入缓冲区
    ADC_Init(ADC1, &ADC_InitStructure);
    // 初始化中断配置
    PLIC_InitStruct.PLIC_IRQChannel = ADC1_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 4;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}
/* ==================== 应用层APP任务函数 ==================== */


/* ==================== 中断服务函数 ==================== */
void ADC0_IRQ_Handler(void)
{
    ADC_IRQ_Handler(&U_ADC0);
}
void ADC1_IRQ_Handler(void)
{
    ADC_IRQ_Handler(&U_ADC1);
}
/* ==================== 中断服务函数 ==================== */
void ADC_IRQ_Handler(U_ADC_Typedef *U_ADC)
{
    if(ADC_GetFlagStatus(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_0) == SET)
    {
        ADC_RSEQ0_EOCCallBack(U_ADC);
        ADC_ClearFlag(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_0);
    }
    if(ADC_GetFlagStatus(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_1) == SET)
    {
        ADC_RSEQ1_EOCCallBack(U_ADC);
        ADC_ClearFlag(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_1);
    }
    if(ADC_GetFlagStatus(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_15) == SET)
    {
        ADC_RSEQ15_EOCCallBack(U_ADC);
        ADC_ClearFlag(U_ADC->ADC, ADC_FLAG_EOC, ADC_RSEQ_15);
    }
}
/* ==================== 中断回调函数 ==================== */
__weak void ADC_RSEQ0_EOCCallBack(U_ADC_Typedef *U_ADC)
{
    UNUSED(U_ADC);
}
__weak void ADC_RSEQ1_EOCCallBack(U_ADC_Typedef *U_ADC)
{
    UNUSED(U_ADC);
}
__weak void ADC_RSEQ15_EOCCallBack(U_ADC_Typedef *U_ADC)
{
    UNUSED(U_ADC);
}