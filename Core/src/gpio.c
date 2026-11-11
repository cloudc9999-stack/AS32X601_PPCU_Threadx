/*
 *  Author: cloudc
 *
 * 
 * 
*/
#include "gpio.h"


void U_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIOA_CLK_ENABLE();
    GPIOB_CLK_ENABLE();
    GPIOC_CLK_ENABLE();
    GPIOD_CLK_ENABLE();
    GPIOE_CLK_ENABLE();
    GPIOF_CLK_ENABLE();
    GPIOG_CLK_ENABLE();
    // LED初始化
    GPIO_InitStructure.GPIO_Pin = LED3_Pin | LED5_Pin; 
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(LED3_GPIO_Port, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = LED1_Pin | LED2_Pin | LED4_Pin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(LED1_GPIO_Port, &GPIO_InitStructure);
    GPIO_SetBits(LED1_GPIO_Port, LED1_Pin | LED2_Pin | LED4_Pin);
    GPIO_SetBits(LED3_GPIO_Port, LED3_Pin | LED5_Pin);

    // GPIO输出
    GPIO_InitStructure.GPIO_Pin = S1O1_Pin | S1O2_Pin | S1O3_Pin | S1O4_Pin | S1O5_Pin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(S1O1_GPIO_Port, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = S1O6_Pin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(S1O6_GPIO_Port, &GPIO_InitStructure);
    GPIO_SetBits(S1O1_GPIO_Port, S1O1_Pin | S1O2_Pin | S1O3_Pin | S1O4_Pin | S1O5_Pin);
    GPIO_SetBits(S1O6_GPIO_Port, S1O6_Pin);

    // GPIO输入
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource13, GPIO_AF_Pin_x);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_Pin_x);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_Pin_x);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_Pin_x);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_Pin_x);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_Pin_x);
    GPIO_InitStructure.GPIO_Pin = S1I1_Pin | S1I2_Pin | S1I3_Pin | S1I4_Pin | S1I5_Pin | S1I6_Pin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IPD;
    GPIO_Init(S1I1_GPIO_Port, &GPIO_InitStructure);
}