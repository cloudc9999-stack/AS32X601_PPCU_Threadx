/*
 *  Author: cloudc
 *
 * 
 * 
*/
#include "tim.h"
#include "tx_port.h"

volatile uint32_t TickCount = 0;
extern void _tx_timer_interrupt(void);
/* =========================== 定时器初始化函数 ======================= */
/*
 * Function:        TIM0_Config
 * Description:     Configure TIMER0.
 * Param:           None.                 
 * Return:          None.
 */
void U_TIM6_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    PLIC_InitTypeDef PLIC_InitStructure;
    TIM6_CLK_ENABLE();

    /* Initializes the TIM0 */
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_Period = 999;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 44;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

    TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);

    PLIC_StructInit(&PLIC_InitStructure);
    PLIC_InitStructure.PLIC_IRQChannel = TIM6_IRQn;
    PLIC_InitStructure.PLIC_IRQPriority = 1;
    PLIC_InitStructure.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStructure);
    
    TIM_Cmd(TIM6, ENABLE);
}
/*
    HTIM0定时器初始化函数
    时钟:AXILite4 BUS2 90MHZ
    S2 PWM 输出映射
    PA3 ---> HTIM0_CH5  ---> PWM1
    PA2 ---> HTIM0_CH4  ---> PWM2
    PC5 ---> HTIM0_CH5N ---> PWM3
    PC4 ---> HTIM0_CH4N ---> PWM4
*/
void U_TIM0_Init(void)
{
    GPIOA_CLK_ENABLE();
    GPIOC_CLK_ENABLE();
    HTIM0_CLK_ENABLE();

    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef TIM_OC_InitStructure;

    /* Set GPIO multiplex mapping */
    // S2 PWM 输出映射
    // PA3 ---> HTIM0_CH5  ---> PWM1
    // PA2 ---> HTIM0_CH4  ---> PWM2
    // PC5 ---> HTIM0_CH5N ---> PWM3
    // PC4 ---> HTIM0_CH4N ---> PWM4
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_HTIM0_M1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_HTIM0_M1);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource5, GPIO_AF_HTIM0_M1);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource4, GPIO_AF_HTIM0_M1);


    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_18mA;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_18mA;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    /* Initializes the TIM0 */
    //频率计算：AXILITEBUS1/(ARR+1)/(PSC+1)
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     //注：此分频设置的是死区采样时钟分频比，不影响定时计数
    TIM_TimeBaseInitStructure.TIM_Period = 89;  
    TIM_TimeBaseInitStructure.TIM_Prescaler = 0; 
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 
    TIM_TimeBaseInit(TIM0, &TIM_TimeBaseInitStructure);

    TIM_OCStructInit(&TIM_OC_InitStructure);
    TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;                              // CCMR_OCxM位域，输出输入模式配置
    TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;                  // CCER_CCxE位域，使能通道x输出
    TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;                // CCER_CCxNE，通道x互补使能
    TIM_OC_InitStructure.TIM_Pulse = 30;
    TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                      // CCER_CCxP,通道x极性
    TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;                    // CCER_CCxNP,通道xN极性
    TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;                     // CR2_OISx通道x空闲状态电平
    TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;                 // CR2_OISxN通道xN空闲状态电平
    TIM_OC4Init(TIM0, &TIM_OC_InitStructure);
    TIM_OC5Init(TIM0, &TIM_OC_InitStructure);
    TIM_Cmd(TIM0, ENABLE);
}
/*
    HTIM2定时器初始化函数
    时钟:APB_BUS0  45MHZ
*/
void U_TIM2_Init(void)
{
    GPIOG_CLK_ENABLE();
    HTIM2_CLK_ENABLE();

    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef TIM_OC_InitStructure;

    /* Set GPIO multiplex mapping */
    // S2 PWM 输出映射
    // PG1 ---> HTIM0_CH4  ---> PWM5
    // PG0 ---> HTIM0_CH3  ---> PWM6
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource1, GPIO_AF_HTIM2);
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource0, GPIO_AF_HTIM2);

    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_18mA;
    GPIO_Init(GPIOG, &GPIO_InitStructure);

    /* Initializes the TIM0 */
    //频率计算：AXILITEBUS1/(ARR+1)/(PSC+1)
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     //注：此分频设置的是死区采样时钟分频比，不影响定时计数
    TIM_TimeBaseInitStructure.TIM_Period = 99;  
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8; 
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    TIM_OCStructInit(&TIM_OC_InitStructure);
    TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;                              // CCMR_OCxM位域，输出输入模式配置
    TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;                  // CCER_CCxE位域，使能通道x输出
    TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;                // CCER_CCxNE，通道x互补使能
    TIM_OC_InitStructure.TIM_Pulse = 30;
    TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                      // CCER_CCxP,通道x极性
    TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;                    // CCER_CCxNP,通道xN极性
    TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;                     // CR2_OISx通道x空闲状态电平
    TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;                 // CR2_OISxN通道xN空闲状态电平
    TIM_OC3Init(TIM2, &TIM_OC_InitStructure);
    TIM_OC4Init(TIM2, &TIM_OC_InitStructure);
    TIM_Cmd(TIM2, ENABLE);
}
/*
    HTIM1定时器初始化函数
    时钟:AXILite4 BUS1 90MHZ
*/
void U_TIM1_Init(void)
{
    GPIOG_CLK_ENABLE();
    GPIOB_CLK_ENABLE();
    HTIM1_CLK_ENABLE();

    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef TIM_OC_InitStructure;

    /* Set GPIO multiplex mapping */
    // S1 PWM 输出映射
    // PB3  --->  HTIM0_CH6N  ---> PWM1
    // PG15 --->  HTIM0_CH5N  ---> PWM2
    // PG10 --->  HTIM0_CH6   ---> PWM3
    // PG9  --->  HTIM0_CH5   ---> PWM4
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_HTIM1);
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource15, GPIO_AF_HTIM1);
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource10, GPIO_AF_HTIM1);
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource9, GPIO_AF_HTIM1);
    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_10 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_18mA;
    GPIO_Init(GPIOG, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* Initializes the TIM0 */
    //频率计算：AXILITEBUS1/(ARR+1)/(PSC+1)
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     //注：此分频设置的是死区采样时钟分频比，不影响定时计数
    TIM_TimeBaseInitStructure.TIM_Period = 99;  
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8; 
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

    TIM_OCStructInit(&TIM_OC_InitStructure);
    TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;                              // CCMR_OCxM位域，输出输入模式配置
    TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;                  // CCER_CCxE位域，使能通道x输出
    TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;                // CCER_CCxNE，通道x互补使能
    TIM_OC_InitStructure.TIM_Pulse = 30;
    TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                      // CCER_CCxP,通道x极性
    TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;                    // CCER_CCxNP,通道xN极性
    TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;                     // CR2_OISx通道x空闲状态电平
    TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;                 // CR2_OISxN通道xN空闲状态电平
    TIM_OC5Init(TIM1, &TIM_OC_InitStructure);
    TIM_OC6Init(TIM1, &TIM_OC_InitStructure);
    TIM_Cmd(TIM1, ENABLE);
}
/*
    HTIM5定时器初始化函数
    时钟:APB_BUS1  45MHZ
*/
void U_TIM5_Init(void)
{
    GPIOA_CLK_ENABLE();
    HTIM5_CLK_ENABLE();

    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef TIM_OC_InitStructure;

    /* Set GPIO multiplex mapping */
    // S1 PWM 输出映射
    // PA15  --->  HTIM0_CH4N  ---> PWM5
    // PA14  --->  HTIM0_CH3N  ---> PWM6
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_HTIM5);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_HTIM5);

    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_18mA;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Initializes the TIM0 */
    //频率计算：AXILITEBUS1/(ARR+1)/(PSC+1)
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     //注：此分频设置的是死区采样时钟分频比，不影响定时计数
    TIM_TimeBaseInitStructure.TIM_Period = 99;  
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8; 
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStructure);

    TIM_OCStructInit(&TIM_OC_InitStructure);
    TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM2;                              // CCMR_OCxM位域，输出输入模式配置
    TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Disable;                  // CCER_CCxE位域，使能通道x输出
    TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;                // CCER_CCxNE，通道x互补使能
    TIM_OC_InitStructure.TIM_Pulse = 30;
    TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;                      // CCER_CCxP,通道x极性
    TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;                    // CCER_CCxNP,通道xN极性
    TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;                     // CR2_OISx通道x空闲状态电平
    TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;                 // CR2_OISxN通道xN空闲状态电平
    TIM_OC3Init(TIM5, &TIM_OC_InitStructure);
    TIM_OC4Init(TIM5, &TIM_OC_InitStructure);
    TIM_Cmd(TIM5, ENABLE);
}
/* =========================== 定时器初始化函数 ======================= */
/*
    获取tick时间
*/
uint32_t U_GetTick(void)
{
    
    return TickCount;
}
/*
    毫秒延迟函数
*/
void U_Delay(uint32_t delaytime)
{
    uint32_t StartTime = U_GetTick();
    while((U_GetTick() - StartTime <= delaytime))
    {
        
    }
}
/*
    中断服务函数
*/
void TIM6_IRQ_Handler(void)
{
    TickCount++;
    // _tx_timer_interrupt();
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
}