/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "can.h"
#include "main.h"
/* ==================== 静态变量声明 ==================== */
U_CANFD_Typedef U_CANFD3;
U_CANFD_Typedef U_CANFD0;


/* ==================== 私有函数声明 ==================== */



/* ==================== 应用层APP初始化函数 ==================== */
void U_CAN3_Init(void)
{
    CANFD3_CLK_ENABLE();
    CANFD3_RESET();
    CANFD3_SET();
    GPIOC_CLK_ENABLE();
    // 初始化U_CANFD_Typedef结构体
    U_CANFD3.CANFDx = CANFD3;
    U_CANFD3.CAN_State = CAN_STATE_READY;
    GPIO_InitTypeDef  GPIO_InitStructure;
    CANFD_InitTypeDef CANFD_InitStructure;
    PLIC_InitTypeDef  PLIC_InitStructure;
    // 复用功能配置
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_CAN3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_CAN3);
    // GPIO配置
    // PC7 ----> CAN3_TX
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    // PC8 ----> CAN3_RX
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IPU;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    // 波特率设置
    // 仲裁波特率配置
    CANFD_StructInit(&CANFD_InitStructure);
    CANFD_InitStructure.CANFD_SRR = CANFD_SRR_RESET;
    CANFD_InitStructure.CANFD_APBRPR = CANFD_APBRPR_8tp;
    CANFD_InitStructure.CANFD_APBTR_APTS1 = CANFD_APBTR_TS1_7tp;
    CANFD_InitStructure.CANFD_APBTR_APTS2 = CANFD_APBTR_TS2_3tp;
    CANFD_InitStructure.CANFD_APBTR_APSJW = CANFD_APBTR_SJW_2tp;
    // 数据波特率配置
    CANFD_InitStructure.CANFD_DPBRPR = CANFD_DPBRPR_1tp;
    CANFD_InitStructure.CANFD_DPBTR_DPTS1 = CANFD_DPBTR_TS1_6tp;
    CANFD_InitStructure.CANFD_DPBTR_DPTS2 = CANFD_DPBTR_TS2_2tp;
    CANFD_InitStructure.CANFD_DPBTR_DPSJW = CANFD_DPBTR_SJW_2tp;
    CANFD_Init(CANFD3, &CANFD_InitStructure);
    // 自动重发设置
    CANFD_AutoRetransConfig(CANFD3,ENABLE);
    CANFD_AutoBusOffRecoConfig(CANFD3,ENABLE);
    // 中断使能
    uint32_t cabfd_itenable = CANFD_IT_ERXOK | CANFD_IT_EERROR | CANFD_IT_EBSFRD;
    CANFD_ITConfig(CANFD3, cabfd_itenable, ENABLE);
    // 使能CAN
    CANFD_Enable(CANFD3);
    // 中断优先级以及中断线使能
    PLIC_StructInit(&PLIC_InitStructure);
    PLIC_InitStructure.PLIC_IRQChannel = CANFD3_IRQn;
    PLIC_InitStructure.PLIC_IRQPriority = 4;
    PLIC_InitStructure.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStructure);
    CANFD_ClearITPendingBit(CANFD3, CANFD_CLEAR_ALL);
}

void U_CAN0_Init(void)
{
    CANFD0_CLK_ENABLE();
    CANFD0_RESET();
    CANFD0_SET();
    GPIOC_CLK_ENABLE();
    // 初始化U_CANFD_Typedef结构体
    U_CANFD0.CANFDx = CANFD0;
    U_CANFD0.CAN_State = CAN_STATE_READY;
    GPIO_InitTypeDef  GPIO_InitStructure;
    CANFD_InitTypeDef CANFD_InitStructure;
    PLIC_InitTypeDef  PLIC_InitStructure;
    // 复用功能配置
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_CAN0_M3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_CAN0_M3);
    // GPIO配置
    // PC12 ----> CAN0_TX
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType     = GPIO_Out_PP;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    // PD0 ----> CAN0_RX
    GPIO_InitStructure.GPIO_Pin       = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IPU;
    GPIO_InitStructure.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    // 波特率设置
    // 仲裁波特率配置
    CANFD_StructInit(&CANFD_InitStructure);
    CANFD_InitStructure.CANFD_SRR = CANFD_SRR_RESET;
    CANFD_InitStructure.CANFD_APBRPR = CANFD_APBRPR_8tp;
    CANFD_InitStructure.CANFD_APBTR_APTS1 = CANFD_APBTR_TS1_7tp;
    CANFD_InitStructure.CANFD_APBTR_APTS2 = CANFD_APBTR_TS2_3tp;
    CANFD_InitStructure.CANFD_APBTR_APSJW = CANFD_APBTR_SJW_2tp;
    // 数据波特率配置
    CANFD_InitStructure.CANFD_DPBRPR = CANFD_DPBRPR_1tp;
    CANFD_InitStructure.CANFD_DPBTR_DPTS1 = CANFD_DPBTR_TS1_6tp;
    CANFD_InitStructure.CANFD_DPBTR_DPTS2 = CANFD_DPBTR_TS2_2tp;
    CANFD_InitStructure.CANFD_DPBTR_DPSJW = CANFD_DPBTR_SJW_2tp;
    CANFD_Init(CANFD0, &CANFD_InitStructure);
    // 自动重发设置
    CANFD_AutoRetransConfig(CANFD0,ENABLE);
    CANFD_AutoBusOffRecoConfig(CANFD0,ENABLE);
    // 中断使能
    uint32_t canfd_itenable = CANFD_IT_ERXOK | CANFD_IT_EERROR | CANFD_IT_EBSFRD;
    CANFD_ITConfig(CANFD0, canfd_itenable, ENABLE);
    // 使能CAN
    CANFD_Enable(CANFD0);
    // 中断优先级以及中断线使能
    PLIC_StructInit(&PLIC_InitStructure);
    PLIC_InitStructure.PLIC_IRQChannel = CANFD0_IRQn;
    PLIC_InitStructure.PLIC_IRQPriority = 3;
    PLIC_InitStructure.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStructure);
    CANFD_ClearITPendingBit(CANFD0, CANFD_CLEAR_ALL);
}
/* ==================== 应用层APP任务函数 ==================== */





/* ==================== 加工函数 ==================== */
U_StatusTypeDef U_CANFD_Transmit(U_CANFD_Typedef* U_CANFDx, uint32_t RSTBx, uint8_t* Canfdbuf, uint32_t Buflength)
{
    uint32_t tickstart = U_GetTick();
    // if(U_CANFDx->CAN_State != CAN_STATE_READY)
    // {
    //     return U_ERROR;
    // }
    CANFD_Transmit(U_CANFDx->CANFDx, RSTBx, Canfdbuf, Buflength);
    // while((U_CANFDx->CANFDx->TRR & (0x1U << RSTBx)) != 0U)
    // {
    //     if(U_GetTick() - tickstart > CAN_TIMEOUT_VALUE)
    //     {
    //         // U_CANFDx->CAN_State = CAN_STATE_ERROR;
    //         return U_ERROR;
    //     }
    // }
    return U_OK;
}
// 获取CAN外设状态函数
U_CAN_STATE_Typedef U_CAN_GetState(U_CANFD_Typedef* U_CANFDx)
{
    U_CAN_STATE_Typedef state = CAN_STATE_READY;
    uint32_t srr = U_CANFDx->CANFDx->SRR;
    uint32_t sr = U_CANFDx->CANFDx->SR;

    if((srr & CANFD_SRR_CEN) != 0U)
    {
        if((sr & CANFD_SR_NORMAL) != 0U)
        {
            state = CAN_STATE_READY;
        }
        if((sr & CANFD_SR_ERRWRN) != 0U)
        {
            state = CAN_STATE_ERROR;
        }
        if((sr & 0x180U) != 0x80U)
        {
            state = CAN_STATE_ERROR;
        }
    }else{
        state = CAN_STATE_RESET;
    }
    U_CANFDx->CAN_State = state;
    return state;
}
// 获取CAN_SR寄存器值
uint32_t U_CAN_Get_SR(U_CANFD_Typedef* U_CANFDx)
{
    uint32_t sr = U_CANFDx->CANFDx->SR;
    return sr;
}
// 获取错误码
uint32_t U_CAN_GetErrorCode(U_CANFD_Typedef* U_CANFDx)
{
    uint32_t error = U_CANFDx->CANFDx->ESR;
    uint32_t classic_error = error & 0x1F;
    uint32_t fd_error = (error & 0xF00) >> 3;
    U_CANFDx->ERRORCode = classic_error | fd_error;
    return U_CANFDx->ERRORCode;
}




/* ==================== 中断服务函数 ==================== */
void CANFD3_IRQ_Handler()
{
    CANFD_IRQ_Handlder(&U_CANFD3);
}
void CANFD0_IRQ_Handler()
{
    CANFD_IRQ_Handlder(&U_CANFD0);
}
void CANFD_IRQ_Handlder(U_CANFD_Typedef *U_CANFDx)
{
    if(U_CANFDx->CANFDx == NULL)
    {
        Error_Handler();
    }
    // 获取寄存器值
    uint32_t interrupts = U_CANFDx->CANFDx->ISR;
    // RXOK ---> 接收中断
    if((interrupts & CANFD_FLAG_RXOK) != 0U)
    {
        /* get the receive data */
        uint32_t RFSR = U_CANFDx->CANFDx->RFSR;
        // FL[14:8] ----> 存储接收的消息个数
        uint32_t FL = (RFSR >> CANFD_RFSR_FL_Pos) & 0x7F;
        // RI[5:0] ----> 接收 FIFO读取索引
        uint32_t RI = RFSR & 0x3F;
        while(FL > 0)
        {
            U_CANFDx->RX_RI = RI;
            U_CANFD_RXCallBack(U_CANFDx);
            U_CANFDx->CANFDx->RFSR |= CANFD_RFSR_IRI;
            // 更新FL和RI最新值
            RFSR = U_CANFDx->CANFDx->RFSR;
            FL = (RFSR >> CANFD_RFSR_FL_Pos) & 0x7F;
            RI = RFSR & 0x3F;
        }
        /* Clear the interrupt pending bits */
        CANFD_ClearITPendingBit(U_CANFDx->CANFDx, CANFD_CLEAR_RXOK);
    }
    // TXOK ---> 发送中断
    if((interrupts & CANFD_FLAG_TXOK) != 0U)
    {

    }
    // ERROE  ---> 错误中断
    if((interrupts & CANFD_FLAG_ERROE) != 0U)
    {
        // 获取CAN错误状态寄存器值(ESR)，CAN错误计数寄存器(ECR)，CAN状态寄存器(SR)
        uint32_t error = U_CANFDx->CANFDx->ESR;
        uint32_t error_count = U_CANFDx->CANFDx->ECR;
        // 提取相应位
        uint32_t classic_error = error & 0x1F;
        uint32_t fd_error = (error & 0xF00) >> 3;
        // 赋值结构体
        U_CANFDx->RxErrorCount = (error_count >> 8) & 0xFF;
        U_CANFDx->TxErrorCount = error_count & 0xFF;
        U_CANFDx->ERRORCode = classic_error | fd_error;
        // 进入回调函数
        U_CANFD_ERRORCallBack(U_CANFDx);
        // 清除错误标志位
        CANFD_ClearITPendingBit(U_CANFDx->CANFDx, CANFD_CLEAR_ERROE);
    }
    // BSFRD  ---> 总线关闭恢复完成
    if((interrupts & CANFD_FLAG_BSFRD) != 0U)
    {
        U_CANFDx->CAN_State = CAN_STATE_READY;
        CANFD_ClearITPendingBit(U_CANFDx->CANFDx, CANFD_CLEAR_BSFRD);
    }

}

__weak void U_CANFD_RXCallBack(U_CANFD_Typedef *U_CANFDx)
{
    UNUSED(U_CANFDx);
}

__weak void U_CANFD_ERRORCallBack(U_CANFD_Typedef *U_CANFDx)
{
    UNUSED(U_CANFDx);
}