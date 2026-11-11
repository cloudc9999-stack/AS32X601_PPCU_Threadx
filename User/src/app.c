/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */

/* ==================== 静态变量声明 ==================== */

/* ==================== 私有函数声明 ==================== */

/* ==================== 应用层APP初始化函数 ==================== */

/* ==================== 应用层APP任务函数 ==================== */
/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
#include "app.h"
#include "tx_api.h"
#include "adc.h"
#include "can.h"
#include "usart.h"

#include "CAN_slave.h"
/* ==================== 静态变量声明 ==================== */
static uint16_t adc_value = 0;
uint32_t SN;
// 任务控制块结构体
TX_THREAD app_thread;
static TX_THREAD adc1_thread;
static TX_THREAD adc_vag_thread;
static TX_THREAD ch340_thread;
static TX_THREAD CAN0_RX_thread;
static TX_THREAD led_thread;
// 任务栈数组
ULONG app_thread_stack[1024];
static ULONG adc0_stack[1024];
static ULONG adc_avg_stack[1024];
static ULONG ch340_stack[1024];
static ULONG CAN0_RX_thread_stack[4096];
static ULONG led_thread_stack[256];
// 队列结构体
static TX_QUEUE CAN0_RX_Queue;
// 队列内存
static ULONG CAN0_RX_queue_stack[8];
// 信号量结构体
static TX_SEMAPHORE adc_isr_semaphore;
static TX_SEMAPHORE CH340_RX_Semaphore;
/* ==================== 私有函数声明 ==================== */
static void ADC1_Thread(ULONG thread_input);
static void ADC_avg_Thread(ULONG thread_input);
static void CH340_Thread(ULONG thread_input);
static void CAN0_RX_Thread(ULONG thread_input);
static void LED_Thread(ULONG thread_input);
/* ==================== 应用层APP初始化函数 ==================== */
static void CANFD0_Frame_Config(void);
void APP_Thread(ULONG thread_input)
{
    // uint32_t flash_write_data[2] = {0x78C27591, 0xAAAAAAAA};
    // FLASH_UnlockCtrl();
    // FLASH_EraseSector(0x02000000, PFLASH_SECTOR_SIZE);
    // FLASH_ProgramRom(0x02000000, 8, flash_write_data);
    // FLASH_LockCtrl();
    // 获取设备SN码
    FLASH_UnlockCtrl();
    FLASH_Read(0x02000000, 4, &SN);
    FLASH_LockCtrl();
    CANFD0_Frame_Config();
    printf("SN:%08lx", SN);
    tx_semaphore_create(&adc_isr_semaphore, "adc_isr_semaphore", 0);
    tx_semaphore_create(&CH340_RX_Semaphore, "CH340_RX_Semaphore", 0);
    tx_queue_create(&CAN0_RX_Queue, "CAN0_RX_Queue", 1, CAN0_RX_queue_stack, sizeof(CAN0_RX_queue_stack));
    tx_thread_create(&adc1_thread, "ADC1_Thread",
                    ADC1_Thread, 0,
                    adc0_stack, sizeof(adc0_stack),
                    2, 2, TX_NO_TIME_SLICE, TX_AUTO_START); 
    tx_thread_create(&adc_vag_thread, "adc_vag_thread",
                    ADC_avg_Thread, 0,
                    adc_avg_stack, sizeof(adc_avg_stack),
                    5, 5, TX_NO_TIME_SLICE, TX_AUTO_START);
    tx_thread_create(&ch340_thread, "ch340_thread",
                    CH340_Thread, 0,
                    ch340_stack, sizeof(ch340_stack),
                    5, 5, TX_NO_TIME_SLICE, TX_AUTO_START);
    tx_thread_create(&CAN0_RX_thread, "CAN0_RX_thread",
                    CAN0_RX_Thread, 0,
                    CAN0_RX_thread_stack, sizeof(CAN0_RX_thread_stack),
                    4, 4, TX_NO_TIME_SLICE, TX_AUTO_START);
    tx_thread_create(&led_thread, "LED_Thread", 
                    LED_Thread, 0,
                    led_thread_stack, sizeof(led_thread_stack),
                    5, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
    tx_thread_terminate(&app_thread);
    while(1);
}
/* ==================== 应用层APP任务函数 ==================== */
/*
    说明 ： 系统状态维护和说明
*/

/*
    说明：CAN外设接收协议解析线程
*/
void CAN0_RX_Thread(ULONG thread_input)
{
    CANFD_FilterInit(CANFD0, 0, 0xFFE << 18, 0x01 << 21);
    uint32_t RI;
    uint32_t DW[2];
    uint8_t send_data[8];
    uint8_t SDebug = 0;
    while(1)
    {
        DW[0] = 0;
        DW[1] = 0;
        if(tx_queue_receive(&CAN0_RX_Queue, &RI, TX_WAIT_FOREVER) == TX_SUCCESS)
        {
            DW[0] = U_CANFD0.CANFDx->RxMessage[RI].RB_DW0;
            DW[1] = U_CANFD0.CANFDx->RxMessage[RI].RB_DW1;
            uint32_t RX_DLC = U_CANFD0.CANFDx->RxMessage[RI].RB_DLC >> 28;
            uint32_t RX_ID = U_CANFD0.CANFDx->RxMessage[RI].RB_ID >> 21;
            if(DW[0] != 0x01030000 && SDebug == 1)
            {
                printf("\r\nDW[0]=0x%08lx\r\n", DW[0]);
                printf("DW[1]=0x%08lx\r\n", DW[1]);
                printf("DLC=%lu\r\n", RX_DLC);
                printf("ID=0x%03lx\r\n", RX_ID);
            }
            // CAN从机协议
            uint32_t DLC = AP_CAN_Slave(DW, send_data, RX_DLC);
            if(DLC != 0)
            {
                U_CANFD_Transmit(&U_CANFD0, TB0, send_data, DLC);
            }
            uint16_t receive = (uint16_t)(send_data[0] << 8) | (uint16_t)send_data[1];
            if(SDebug == 1 && receive != 0x0103)
            {
                printf("\r\nsend_data:0x");
                for(uint8_t i = 0; i < 8; i++)
                {
                    printf("%02x", send_data[i]);
                }
                printf("\r\n");
                printf("DLC:%lu\r\n", DLC);
            }
        }
    }
}
/*
    说明：调试CH340串口协议解析线程
*/
void CH340_Thread(ULONG thread_input)
{
    uint8_t usart5_rxdata[4];
    uint8_t Debug = 1;
    U_USART_Receive_IT(&U_USART5, usart5_rxdata, 4);
    while (1)
    {
        if(tx_semaphore_get(&CH340_RX_Semaphore, TX_WAIT_FOREVER) == TX_SUCCESS)
        {
            if(Debug == 1)
            {
                printf("\r\nCH340接收: ");
                for(uint8_t i = 0; i < 4; i++)
                {
                    printf("%02X ", usart5_rxdata[i]);
                }
                printf("\r\n");
            }
            uint16_t CmdCode = ((uint16_t)usart5_rxdata[0] << 8) | usart5_rxdata[3];
            switch (CmdCode)
            {
            // 设置DAC输出电压    
            case 0xAA11:   
            {
                uint32_t spi_txdata = (usart5_rxdata[1] << 8) | usart5_rxdata[2];
                // SPI_SendDataLast(SPI3, spi_txdata);
                SPI_SendDataLast(SPI4, spi_txdata);
                printf("SPI发送: 0x%02X%02X\r\n", usart5_rxdata[1], usart5_rxdata[2]);
            }
            break;
            // 获取SN码
            case 0xAA22:
            {
                uint8_t send_data[4];
                send_data[0] = (uint8_t)(SN >> 24);
                send_data[1] = (uint8_t)(SN >> 16);
                send_data[2] = (uint8_t)(SN >> 8);
                send_data[3] = (uint8_t)(SN >> 0);
                printf("flash addr 0x02000000 of value:0x");
                for(uint8_t i = 0; i < 4; i++)
                {
                    printf("%02x", send_data[i]);
                }
                printf("\r\n");
            }
            break;
            }
            U_USART_Receive_IT(&U_USART5, usart5_rxdata, 4);
        }
    }
    
}
/*
    adc_avg函数负责将中断的信号量接收并读取计算平均值存入静态变量
    adc_read函数读取静态
*/
static void ADC1_Config(void);

void ADC1_Thread(ULONG thread_input)
{
    ADC1_Config();
    ADC_SoftRegularConvert(U_ADC1.ADC);
    
    uint8_t can_buff[8];
    while(1)
    {
        // printf("\r\nIN1 = %u\r\n", adc_value);
        can_buff[0] = (uint8_t)(adc_value >> 8);
        can_buff[1] = (uint8_t)(adc_value >> 0);
        can_buff[2] = (uint8_t)(adc_value >> 8);
        can_buff[3] = (uint8_t)(adc_value >> 0);
        can_buff[4] = (uint8_t)(adc_value >> 8);
        can_buff[5] = (uint8_t)(adc_value >> 0);
        can_buff[6] = (uint8_t)(adc_value >> 8);
        can_buff[7] = (uint8_t)(adc_value >> 0);
        U_CANFD_Transmit(&U_CANFD0, TB1, can_buff, 2);
        U_CANFD_Transmit(&U_CANFD0, TB2, can_buff, 8);
        U_CANFD_Transmit(&U_CANFD0, TB3, can_buff, 8);
        tx_thread_sleep(1000U);
    }
}
void ADC_avg_Thread(ULONG thread_input)
{
    uint16_t value_buff[10];
    uint8_t index = 0;
    while(1)
    {
        if(tx_semaphore_get(&adc_isr_semaphore, TX_WAIT_FOREVER) == TX_SUCCESS)
        {
            ADC_GetSeqResult(U_ADC1.ADC, ADC_RSEQ_0, &value_buff[index]);
            index++;
            if(index >= 10)
            {
                uint32_t ValueOfAll = 0;
                for(uint8_t i = 0; i < 10; i++)
                {
                    ValueOfAll += value_buff[i];
                }
                adc_value = (uint16_t)(ValueOfAll / 10);
                index = 0;
                tx_thread_sleep(500U);
            }
        }
    }
}
void LED_Thread(ULONG thread_input)
{
    while(1)
    {
        GPIO_ToggleBits(LED1_GPIO_Port, LED1_Pin);
        if(CG_handle.CG_slave_status == 1)
        {
            GPIO_ToggleBits(LED2_GPIO_Port, LED2_Pin);
        }else{
            GPIO_SetBits(LED2_GPIO_Port, LED2_Pin);
        }
        tx_thread_sleep(1000U);
    }
}
/* ==================== Config函数 ==================== */
void ADC1_Config(void)
{
    ADC_ChannelTypeDef ADC_ChannelStructure;
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIOF_CLK_ENABLE();
    GPIOA_CLK_ENABLE();
    GPIOB_CLK_ENABLE();
    // 通道GPIO配置
    // PF12 -----> ADC1_CH16    -----> IN1
    // PA6  -----> ADC1_CH8     -----> IN2
    // PF11 -----> ADC1_CH15    -----> IN3
    // PA5  -----> ADC1_CH7     -----> IN4
    // PB2  -----> ADC1_CH14    -----> IN5
    // PA4  -----> ADC1_CH6     -----> IN6
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IN_FLOATING;
    GPIO_Init (GPIOF, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IN_FLOATING;
    GPIO_Init (GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_IType     = GPIO_IN_FLOATING;
    GPIO_Init (GPIOB, &GPIO_InitStructure);

    ADC_ChannelStructure.ADC_Channel = ADC_CH_16;
    ADC_ChannelStructure.ADC_SampleTime = ADC_SPT_CLK_640;
    ADC_ChannelStructure.ADC_InterruptEn = ENABLE;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_0, &ADC_ChannelStructure);
    ADC_ChannelStructure.ADC_InterruptEn = DISABLE;
    ADC_ChannelStructure.ADC_Channel = ADC_CH_8;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_1, &ADC_ChannelStructure);
    ADC_ChannelStructure.ADC_Channel = ADC_CH_15;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_2, &ADC_ChannelStructure);
    ADC_ChannelStructure.ADC_Channel = ADC_CH_7;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_3, &ADC_ChannelStructure);
    ADC_ChannelStructure.ADC_Channel = ADC_CH_14;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_4, &ADC_ChannelStructure);
    ADC_ChannelStructure.ADC_Channel = ADC_CH_6;
    ADC_ConfigChannel(ADC1, ADC_RSEQ_5, &ADC_ChannelStructure);
}
void CANFD0_Frame_Config(void)
{
    CANFD_TXFrameTypeDef CANFD_TXFrameStructure;
    
    /* Set the setting ID and setting mode */
    CANFD_TXFrameStructure.CANFD_TX_PROTOCOL = CAN;
    // 标准帧格式，11位标识符ID 0x000 - 0x7FF；扩展帧，29位ID
    CANFD_TXFrameStructure.CANFD_TX_FORMAT = STANDARD ;
    CANFD_TXFrameStructure.CANFD_TX_TYPE = DATA;
    // 帧ID
    CANFD_TXFrameStructure.CANFD_Frame_ID = 0x05;
    CANFD_FrameInit(CANFD0, TB0, &CANFD_TXFrameStructure);
    CANFD_TXFrameStructure.CANFD_Frame_ID = 0x06;
    CANFD_FrameInit(CANFD0, TB1, &CANFD_TXFrameStructure);
    CANFD_TXFrameStructure.CANFD_Frame_ID = 0x07;
    CANFD_FrameInit(CANFD0, TB2, &CANFD_TXFrameStructure);
    CANFD_TXFrameStructure.CANFD_Frame_ID = 0x08;
    CANFD_FrameInit(CANFD0, TB3, &CANFD_TXFrameStructure);
}
/* ==================== 中断回调服务函数 ==================== */
void ADC_RSEQ0_EOCCallBack(U_ADC_Typedef *U_ADC)
{
    if(U_ADC->ADC == ADC1)
    {
        tx_semaphore_put(&adc_isr_semaphore);
    }
}
void U_UART_RxCpltCallback(U_USART_typedef *U_USART)
{
    if(U_USART->USART == USART5)
    {
        tx_semaphore_put(&CH340_RX_Semaphore);
    }
}
void U_CANFD_RXCallBack(U_CANFD_Typedef *U_CANFDx)
{
    if(U_CANFDx->CANFDx == CANFD0)
    {   
        uint32_t RI = U_CANFDx->RX_RI;
        tx_queue_send(&CAN0_RX_Queue, &RI, TX_NO_WAIT);
    }
}

