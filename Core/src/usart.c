/*
 *  Author: cloudc
 *
 * 
 * 
*/
/* =================================== 包含头文件 =================================== */
#include "usart.h"


/* =================================== 结构体定义 =================================== */
U_USART_typedef U_USART5;
U_USART_typedef U_USART1;
U_USART_typedef U_USART6;
/* =================================== 宏定义 =================================== */
#define USART_RX_IT_TIMEOUT                 (3UL)
/* =================================== 初始化函数 =================================== */
/*
 *  初始化函数
 *  
*/
// RS422-1 ----> usart1
void U_USART1_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;
    PLIC_InitTypeDef PLIC_InitStruct;
    U_USART1.USART = USART1;
    U_USART1.usart_it.tx_count = 0;
    U_USART1.usart_it.tx_head = 0;
    U_USART1.usart_it.tx_tail = 0;
    U_USART1.usart_fifo.tx_head = 0;
    U_USART1.usart_fifo.tx_tail = 0;
    U_USART1.usart_fifo.tx_count = 0;
    USART1_CLK_ENABLE();
    GPIOD_CLK_ENABLE();
    /* Set gpio multiplex mapping */
    // PD15 -----> usart1_TX
    // PH2  -----> usart1_RX
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource2, GPIO_AF_USART1);
    /* GPIO Configure */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStruct.GPIO_OStrength = GPIO_OStrength_4_5mA;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_IType = GPIO_IN_FLOATING;
    GPIO_Init(GPIOH, &GPIO_InitStruct);
    /* Init Usart1 */
    USART_DeInit(USART1);
    USART_StructInit(&USART_InitStruct);
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_WordLength   = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits     = USART_StopBits_1;
    USART_InitStruct.USART_Parity       = USART_Parity_No;
    USART_InitStruct.USART_Mode         = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_OverSampling = USART_OverSampling_16;
    USART_Init(USART1, &USART_InitStruct);
    USART_EnableFifoMode(USART1);
    USART_Cmd(USART1, ENABLE);
    /* Configure usart1  interrupt */
    PLIC_InitStruct.PLIC_IRQChannel = USART1_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 5;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}
// RS422-2 ----> usart6
void U_USART6_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;
    PLIC_InitTypeDef PLIC_InitStruct;
    U_USART6.USART = USART6;
    U_USART6.usart_it.tx_count = 0;
    U_USART6.usart_it.tx_head = 0;
    U_USART6.usart_it.tx_tail = 0;
    U_USART6.usart_fifo.tx_head = 0;
    U_USART6.usart_fifo.tx_tail = 0;
    U_USART6.usart_fifo.tx_count = 0;
    USART6_CLK_ENABLE();

    /* Set gpio multiplex mapping */
    // PE0 ----> usart6_TX
    // PE1 ====-> usart6_RX
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_USART6);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_USART6);
    /* GPIO Configure */
    // PE0 ----> usart6_TX
    // PE1 ====-> usart6_RX
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStruct.GPIO_OStrength = GPIO_OStrength_9mA;
    GPIO_Init(GPIOE, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_IType = GPIO_IN_FLOATING;
    GPIO_Init(GPIOE, &GPIO_InitStruct);
    
    /* Init Usart6 */
    USART_DeInit(USART6);
    USART_StructInit(&USART_InitStruct);
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_WordLength   = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits     = USART_StopBits_1;
    USART_InitStruct.USART_Parity       = USART_Parity_No;
    USART_InitStruct.USART_Mode         = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_OverSampling = USART_OverSampling_16;
    USART_Init(USART6, &USART_InitStruct);
    USART_EnableFifoMode(USART6);
    USART_Cmd(USART6, ENABLE);
    /* Configure usart6  interrupt */
    PLIC_InitStruct.PLIC_IRQChannel = USART6_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 4;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}
// CH340 ----> usart5
void U_USART5_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;
    PLIC_InitTypeDef PLIC_InitStruct;
    U_USART5.USART = USART5;
    U_USART5.usart_it.tx_count = 0;
    U_USART5.usart_it.tx_head = 0;
    U_USART5.usart_it.tx_tail = 0;
    U_USART5.usart_fifo.tx_count = 0;
    U_USART5.usart_fifo.tx_head = 0;
    U_USART5.usart_fifo.tx_tail = 0;
    U_USART5.usart_fifo.isempty = 0;
    USART5_CLK_ENABLE();

    /* Set gpio multiplex mapping */
    // PG12 ----> USART5_TX
    // PG13 -----> USART5_RX
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource12, GPIO_AF_USART5);
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource13, GPIO_AF_USART5);
    /* GPIO Configure */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_Out_PP;
    GPIO_InitStruct.GPIO_OStrength = GPIO_OStrength_4_5mA;
    GPIO_Init(GPIOG, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_IType = GPIO_IN_FLOATING;
    GPIO_InitStruct.GPIO_OStrength = GPIO_OStrength_4_5mA;
    GPIO_Init(GPIOG, &GPIO_InitStruct);
    USART_DeInit(USART5);
    /* Init Usart5 */
    USART_StructInit(&USART_InitStruct);
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_WordLength   = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits     = USART_StopBits_1;
    USART_InitStruct.USART_Parity       = USART_Parity_No;
    USART_InitStruct.USART_Mode         = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_OverSampling = USART_OverSampling_16;
    USART_Init(USART5, &USART_InitStruct);
    USART_EnableFifoMode(USART5);
    USART_Cmd(USART5, ENABLE);
    /* Configure usart5  interrupt */
    PLIC_InitStruct.PLIC_IRQChannel = USART5_IRQn;
    PLIC_InitStruct.PLIC_IRQPriority = 4;
    PLIC_InitStruct.PLIC_IRQChannelCmd = ENABLE;
    PLIC_Init(&PLIC_InitStruct);
}

/* =================================== 封装函数 =================================== */
U_StatusTypeDef U_USART_Transmit(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    if(U_USART == NULL || pData == NULL || Size == 0)
    {
        return U_ERROR;
    }
    uint16_t DSize = Size;
    while(DSize)
    {
        uint32_t start_time = U_GetTick();
        USART_SendData(U_USART->USART, *pData);
        DSize--;
        pData++;
        while(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXE) == RESET)
        {
            if(U_GetTick() - start_time > Timeout)
            {
                return U_TIMEOUT;
            }
        }
    }
    return U_OK;
}
U_StatusTypeDef U_USART_Receive(U_USART_typedef *U_USART, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
    if(U_USART == NULL || pData == NULL || Size == 0)
    {
        return U_ERROR;
    }
    uint16_t DSize = Size;
    while(DSize)
    {
        uint32_t start_time = U_GetTick();
        while(!(U_USART->USART->ISR & USART_ISR_RXNE_RXFNE_Msk))
        {
            if(U_GetTick() - start_time > Timeout)
            {
                return U_TIMEOUT;
            }
        }
        *pData = USART_ReceiveData(U_USART->USART);
        pData++;
        DSize--;
    }
    return U_OK;
}
U_StatusTypeDef U_USART_Transmit_IT(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size)
{
    if(U_USART == NULL || pData == NULL || Size == 0)
    {
        return U_ERROR;
    }
    uint32_t isempty = U_USART->usart_it.tx_count;
    uint16_t datasize = Size;
    uint8_t *ptrdata = pData;
    while((IT_TX_BUFFER_SIZE - U_USART->usart_it.tx_count) < Size);
    // 数据复制到发送缓冲区
    while(datasize != 0)
    {
        datasize--;
        U_USART->usart_it.txBuffer[U_USART->usart_it.tx_head] = *ptrdata;
        ptrdata++;
        U_USART->usart_it.tx_head = (U_USART->usart_it.tx_head + 1) % IT_TX_BUFFER_SIZE;
    }
    U_USART->usart_it.tx_count += (uint32_t)Size;
    // 第一次发送写入寄存器
    if(isempty == 0)
    {
        // 写入TDR
        USART_SendData(U_USART->USART, U_USART->usart_it.txBuffer[U_USART->usart_it.tx_tail]);
        U_USART->usart_it.tx_tail = (U_USART->usart_it.tx_tail + 1) % IT_TX_BUFFER_SIZE;
        U_USART->usart_it.tx_count--;
        if(U_USART->usart_it.tx_count != 0)
        {
            USART_ITConfig(U_USART->USART, USART_IT_TC, ENABLE);
            // USART_ITConfig(U_USART->USART, USART_IT_TXE, ENABLE);
        }
    }
    return U_OK;
}
U_StatusTypeDef U_USART_Receive_IT(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size)
{
    if(U_USART == NULL || pData == NULL || Size == 0)
    {
        return U_ERROR;
    }
    U_USART->usart_it.rx_buff = pData;
    U_USART->usart_it.rx_buffptr = pData;
    U_USART->usart_it.rx_count = 0;
    U_USART->usart_it.rx_size = Size;
    U_USART->usart_it.rx_starttime = U_GetTick();
    USART_ITConfig(U_USART->USART, USART_IT_RXNE, ENABLE);
    return U_OK;
}
U_StatusTypeDef U_USART_Transmit_FIFO(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size)
{
    if(U_USART == NULL || pData == NULL || Size == 0)
    {
        return U_ERROR;
    }
    U_USART->usart_fifo.isempty = U_USART->usart_fifo.tx_count;
    uint16_t datasize = Size;
    uint8_t *ptrdata = pData;
    if((FIFO_TX_BUFFER_SIZE - U_USART->usart_fifo.tx_count) < Size)
    {
        return U_BUSY;
    }
    // 数据复制到发送缓冲区
    while(datasize != 0)
    {
        datasize--;
        U_USART->usart_fifo.txBuffer[U_USART->usart_fifo.tx_head] = *ptrdata;
        ptrdata++;
        U_USART->usart_fifo.tx_head = (U_USART->usart_fifo.tx_head + 1) % FIFO_TX_BUFFER_SIZE;
    }
    // 如果第一次发送，开启FIFO发送
    if(U_USART->usart_fifo.tx_count == 0)
    {
        // 写入FIFO缓冲区
        U_USART->usart_fifo.tx_count += Size;
        while(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFNF) != RESET &&
                U_USART->usart_fifo.tx_count > 0)
        {
            USART_SendData(U_USART->USART, U_USART->usart_fifo.txBuffer[U_USART->usart_fifo.tx_tail]);
            U_USART->usart_fifo.tx_tail = (U_USART->usart_fifo.tx_tail + 1) % FIFO_TX_BUFFER_SIZE;
            U_USART->usart_fifo.tx_count--;
        }
        USART_ITConfig(U_USART->USART, USART_IT_TXFNF, ENABLE);
    }else{
        U_USART->usart_fifo.tx_count += Size;
    }
    return U_OK;
}

/* =================================== usart5 interrupt IRQ ========================= */
void USART5_IRQ_Handler()
{
    U_USART_IRQ_Handler(&U_USART5);
}
void USART6_IRQ_Handler()
{
    U_USART_IRQ_Handler(&U_USART6);
}
void USART1_IRQ_Handler()
{
    U_USART_IRQ_Handler(&U_USART1);
}

/* =================================== 中断服务函数 =================================== */
void U_USART_IRQ_Handler(U_USART_typedef *U_USART)
{
    if(U_USART->USART == NULL)
    {
        Error_Handler();
    }
    // 接收寄存器不为空中断处理函数
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_RXNE) != RESET &&
        USART_GetITStatus(U_USART->USART, USART_IT_RXNE) != RESET)
    {
        if((U_GetTick() - U_USART->usart_it.rx_starttime) > USART_RX_IT_TIMEOUT && U_USART->usart_it.rx_count != 0)
        {
            U_USART->usart_it.rx_buffptr = U_USART->usart_it.rx_buff;
            U_USART->usart_it.rx_count = 0;
        }
        *U_USART->usart_it.rx_buffptr = USART_ReceiveData(U_USART->USART);
        U_USART->usart_it.rx_buffptr++;
        U_USART->usart_it.rx_count++;
        U_USART->usart_it.rx_starttime = U_GetTick();
        if(U_USART->usart_it.rx_count >= U_USART->usart_it.rx_size)
        {
            USART_ITConfig(U_USART->USART, USART_IT_RXNE, DISABLE);
            U_UART_RxCpltCallback(U_USART);
        }
    }
    // 发送TDR寄存器为空中断处理函数
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXE) != RESET &&
        USART_GetITStatus(U_USART->USART, USART_IT_TXE) != RESET)
    {
       
    }
    // 发送完成TC中断处理函数
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TC) != RESET&&
        USART_GetITStatus(U_USART->USART, USART_IT_TC) != RESET)
    {
        U_USART->USART->TDR = (U_USART->usart_it.txBuffer[U_USART->usart_it.tx_tail] & (uint16_t)0x01FF);
        U_USART->usart_it.tx_tail = (U_USART->usart_it.tx_tail + 1) % IT_TX_BUFFER_SIZE;
        U_USART->usart_it.tx_count--;
        if(U_USART->usart_it.tx_count == 0)
        {
            USART_ITConfig(U_USART->USART, USART_IT_TXE, DISABLE);            
            U_UART_TxCpltCallback(U_USART);        
        }
        USART_ClearITPendingBit(U_USART->USART, USART_CLEAR_TCF);
    }
    // 发送TXFIFO阈值中断
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFT) != RESET&&
        USART_GetITStatus(U_USART->USART, USART_IT_TXFT) != RESET)
    {

    }
    // 发送fifo空中断
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFE) != RESET&&
        USART_GetITStatus(U_USART->USART, USART_IT_TXFE) != RESET)
    {
        if(U_USART->usart_fifo.tx_count == 0)
        {
            USART_ITConfig(U_USART->USART, USART_IT_TXFE, DISABLE);
            return;
        }
        while(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFNF) != RESET &&
                U_USART->usart_fifo.tx_count > 0)
        {
            USART_SendData(U_USART->USART, U_USART->usart_fifo.txBuffer[U_USART->usart_fifo.tx_tail]);
            U_USART->usart_fifo.tx_tail = (U_USART->usart_fifo.tx_tail + 1) % FIFO_TX_BUFFER_SIZE;
            U_USART->usart_fifo.tx_count--;
        }
        if(U_USART->usart_fifo.tx_count == 0)
        {
            USART_ITConfig(U_USART->USART, USART_IT_TXFE, DISABLE);
        }
        USART_ClearITPendingBit(U_USART->USART, USART_CLEAR_TXFEF);
        GPIO_SetBits(LED2_GPIO_Port, LED2_Pin);
    }
    // 发送fifo非满中断 发送数据寄存器空
    if(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFNF) != RESET&&
    USART_GetITStatus(U_USART->USART, USART_IT_TXFNF) != RESET)
    {
        while(USART_GetFlagStatus(U_USART->USART, USART_FLAG_TXFNF) != RESET &&
                U_USART->usart_fifo.tx_count > 0)
        {
            USART_SendData(U_USART->USART, U_USART->usart_fifo.txBuffer[U_USART->usart_fifo.tx_tail]);
            U_USART->usart_fifo.tx_tail = (U_USART->usart_fifo.tx_tail + 1) % FIFO_TX_BUFFER_SIZE;
            U_USART->usart_fifo.tx_count--;
        }
        if(U_USART->usart_fifo.tx_count == 0)
        {
            USART_ITConfig(U_USART->USART, USART_IT_TXFNF, DISABLE);
        }
    }
}



/* =================================== 中断回调服务函数 =================================== */
__weak void U_UART_RxCpltCallback(U_USART_typedef *U_USART)
{
    UNUSED(U_USART);
}
__weak void U_UART_TxCpltCallback(U_USART_typedef *U_USART)
{
    UNUSED(U_USART);
}