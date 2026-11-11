/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "spi.h"
#include "main.h"
/* ==================== 静态变量声明 ==================== */
U_SPI_typedef U_SPI4;
U_SPI_typedef U_SPI3;
/* ==================== 私有函数声明 ==================== */

/* ==================== 应用层APP初始化函数 ==================== */
// S1 ---> dac
void U_SPI3_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    SPI_InitTypeDef SPI_InitStructure;
    PLIC_InitTypeDef PLIC_InitStruct;
    // 
    U_SPI3.SPIx = SPI3;
    SPI3_CLK_ENABLE();
    GPIOC_CLK_ENABLE();
    GPIOD_CLK_ENABLE();

    /* Set GPIO multiplex mapping */
    // PD3 -----> SPI3_SCK
    // PD1 -----> SPI3_MOSI
    // PC10 -----> SPI3_CS0
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);    /* SPI3 CS0 */ 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource3, GPIO_AF_SPI3);     /* SPI3 SCK */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_SPI3);     /* SPI3 MOSI */

    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_SetBits(GPIOC, GPIO_Pin_10);

    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* Initializes the SPI3 */
    SPI_StructInit(&SPI_InitStructure);
    SPI_InitStructure.SPI_CLKDiv       = SPI_CLKDiv32;
    SPI_InitStructure.SPI_Mode         = SPI_Mode_Master;
    SPI_InitStructure.SPI_FrameSize    = SPI_FrameSize_16b;
    SPI_InitStructure.SPI_MotorolaMode = SPI_Motorola_Mode1;
    SPI_InitStructure.SPI_TransMode    = SPI_TransNor;
    SPI_Init(SPI3, &SPI_InitStructure);
    /* Resets FIFO of the SPI3 */
    SPI_ResetFIFO(SPI3, SPI_ResetFIFO_TxandRx);
    SPI_NSSConfig(SPI3, SPI_Slave0, ENABLE);
    /* Enable SPI3 */
    SPI_Cmd(SPI3, ENABLE);
    // 中断配置
    PLIC_InitStruct.PLIC_IRQChannel = SPI3_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 5;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}
// S2 ---> dac
void U_SPI4_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    SPI_InitTypeDef SPI_InitStructure;
    PLIC_InitTypeDef PLIC_InitStruct;

    SPI4_CLK_ENABLE();
    GPIOG_CLK_ENABLE();
    /* Set GPIO multiplex mapping */
    // PG4 -----> SPI4_CS0
    // PG5 -----> SPI4_SCK
    // PG6 -----> SPI4_MOSI
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource4, GPIO_AF_SPI4);    /* SPI4 CS0 */
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource5, GPIO_AF_SPI4);     /* SPI4 SCK */
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource6, GPIO_AF_SPI4);     /* SPI4 MOSI */

    /* GPIO Configure */
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOG, &GPIO_InitStructure);
    GPIO_SetBits(GPIOG, GPIO_Pin_4);
    
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOG, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOG, &GPIO_InitStructure);

    /* Initializes the SPI4 */
    SPI_StructInit(&SPI_InitStructure);
    SPI_InitStructure.SPI_CLKDiv       = SPI_CLKDiv32;
    SPI_InitStructure.SPI_Mode         = SPI_Mode_Master;
    SPI_InitStructure.SPI_FrameSize    = SPI_FrameSize_16b;
    SPI_InitStructure.SPI_MotorolaMode = SPI_Motorola_Mode1;
    SPI_InitStructure.SPI_TransMode    = SPI_TransNor;
    SPI_Init(SPI4, &SPI_InitStructure);
    /* Resets FIFO of the SPI4 */
    SPI_ResetFIFO(SPI4, SPI_ResetFIFO_TxandRx);
    SPI_NSSConfig(SPI4, SPI_Slave0, ENABLE);
    /* Enable SPI4 */
    SPI_Cmd(SPI4, ENABLE);
    // 中断配置
    PLIC_InitStruct.PLIC_IRQChannel = SPI4_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 4;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);

    // 结构体初始化
    U_SPI4.SPIx = SPI4;
}
/* ==================== 应用层APP任务函数 ==================== */
U_StatusTypeDef U_SPI_SendData(U_SPI_typedef *U_SPI, uint32_t Data)
{  
    if(U_SPI->SPIx == NULL)
    {
        return U_ERROR;
    }
    SPI_SendData(U_SPI->SPIx, Data);
    return U_OK;
}
U_StatusTypeDef U_SPI_SendData_IT(U_SPI_typedef *U_SPI, uint32_t Data)
{
    if(U_SPI->SPIx == NULL)
    {
        return U_ERROR;
    }
    SPI_ITConfig(U_SPI->SPIx, SPI_IT_TD, ENABLE);
    SPI_SendDataLast(U_SPI->SPIx, Data);
    return U_OK;
}

/* ==================== 中断服务函数 ==================== */
void SPI3_IRQ_Handler(void)
{
    SPI_IRQ_Handler(&U_SPI3);
}
void SPI4_IRQ_Handler(void)
{
    SPI_IRQ_Handler(&U_SPI4);
}


/* ===================================================== */
void SPI_IRQ_Handler(U_SPI_typedef *U_SPI)
{
    if(SPI_GetITStatus(U_SPI->SPIx, SPI_ITStatus_TD) == SET)
    {
        SPI_ClearITPendingBit(U_SPI->SPIx, SPI_CLEAR_TD);
        SPI_ITConfig(U_SPI->SPIx, SPI_IT_TD, DISABLE);
        U_SPI_TxCpltCallback(U_SPI);
    }    
}
__weak void U_SPI_TxCpltCallback(U_SPI_typedef *U_SPI)
{
    UNUSED(U_SPI);
}