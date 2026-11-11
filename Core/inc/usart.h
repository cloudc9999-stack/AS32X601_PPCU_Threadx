/*
 *  Author: cloudc
 *
 * 
 * 
 * 
 */
#ifndef USART_H
#define USART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define FIFO_TX_BUFFER_SIZE                     (1*1024)
#define IT_TX_BUFFER_SIZE                       (1*1024)
typedef enum
{
  U_UART_STATE_RESET             = 0x01U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
  U_UART_STATE_READY             = 0x02U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
  U_UART_STATE_BUSY              = 0x03U,    /*!< an internal process is ongoing
                                                   Value is allowed for gState only */
  U_UART_STATE_BUSY_TX           = 0x04U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
  U_UART_STATE_BUSY_RX           = 0x05U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
  U_UART_STATE_BUSY_TX_RX        = 0x06U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
  U_UART_STATE_TIMEOUT           = 0x07U,    /*!< Timeout state
                                                   Value is allowed for gState only */
  U_UART_STATE_ERROR             = 0x08U     /*!< Error
                                                   Value is allowed for gState only */
} U_UART_StateTypeDef;

typedef struct 
{
    // FIFO发送结构体
    uint8_t txBuffer[FIFO_TX_BUFFER_SIZE];
    uint32_t tx_head;
    uint32_t tx_tail;
    uint32_t tx_count;
    uint8_t isempty;
}U_USART_FIFO_typedef;
typedef struct 
{
    // 中断发送结构体
    uint8_t txBuffer[IT_TX_BUFFER_SIZE];
    uint32_t tx_head;
    uint32_t tx_tail;
    uint32_t tx_count;
    uint8_t *rx_buff;
    uint8_t *rx_buffptr;
    volatile uint16_t rx_count;
    uint16_t rx_size;
    uint32_t rx_starttime;
}U_USART_IT_typedef;

typedef struct 
{
    USART_TypeDef* USART;
    volatile U_UART_StateTypeDef Txstate;

    U_USART_IT_typedef usart_it;
    U_USART_FIFO_typedef usart_fifo;
}U_USART_typedef;



extern U_USART_typedef U_USART5;
extern U_USART_typedef U_USART1;
extern U_USART_typedef U_USART6;


/* ----------------------------------- 初始化函数 ----------------------------------- */
void U_USART5_Init(void);
void U_USART1_Init(void);
void U_USART6_Init(void);
/* ----------------------------------- 封装函数 ----------------------------------- */
U_StatusTypeDef U_USART_Transmit(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size, uint32_t Timeout);
U_StatusTypeDef U_USART_Receive(U_USART_typedef *U_USART, uint8_t* pData, uint16_t Size, uint32_t Timeout);
U_StatusTypeDef U_USART_Transmit_IT(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size);
U_StatusTypeDef U_USART_Receive_IT(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size);
U_StatusTypeDef U_USART_Transmit_FIFO(U_USART_typedef *U_USART, uint8_t *pData, uint16_t Size);
/* ----------------------------------- 中断服务函数 ----------------------------------- */
void U_USART_IRQ_Handler(U_USART_typedef *U_USART);
/* ----------------------------------- 中断服务函数 ----------------------------------- */
void U_UART_RxCpltCallback(U_USART_typedef *U_USART);
void U_UART_TxCpltCallback(U_USART_typedef *U_USART);

#ifdef __cplusplus
}
#endif

#endif