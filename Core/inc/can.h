/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
/* ==================== 静态变量声明 ==================== */
// 总线状态
typedef enum{
    CAN_STATE_RESET                     = 0x00U,            // CAN未使能
    CAN_STATE_READY                     = 0x01U,            // CAN已准备
    CAN_STATE_LISTENING                 = 0x02U,            // 
    CAN_STATE_SLEEP_PENDING             = 0x03U,            //
    CAN_STATE_SLEEP_ACTIVE              = 0x04U,            //
    CAN_STATE_ERROR                     = 0x05U,            //
}U_CAN_STATE_Typedef;






// CAN外设结构体
typedef struct 
{
    CANFD_TypeDef* CANFDx;
    U_CAN_STATE_Typedef CAN_State;
    uint32_t RX_RI;
    uint32_t ERRORCode;
    uint32_t RxErrorCount;
    uint32_t TxErrorCount;
}U_CANFD_Typedef;
// 接收消息内容结构体
typedef struct {
    uint32_t DLC;
    uint32_t ID;
    uint32_t RX_data[2];
}U_RX_CANFD_Typedef;
extern U_CANFD_Typedef U_CANFD3;
extern U_CANFD_Typedef U_CANFD0;


// CAN超时时间定义
#define         CAN_TIMEOUT_VALUE           (10U)                     //
// 总线错误码宏定义
#define         CANFD_ERROR_NONE            (0x00000000U)               // 无错误
#define         CANFD_ERROR_CRCER           (0X00000001U)               // bit0 CRC校验错误
#define         CANFD_ERROR_FMER            (0x00000002U)               // bit1 格式错误
#define         CANFD_ERROR_STER            (0x00000004U)               // bit2 填充位错误
#define         CANFD_ERROR_BERR            (0x00000008U)               // bit3 位错误
#define         CANFD_ERROR_ACKER           (0x00000010U)               // bit4 应答错误
#define         CANFD_ERROR_F_CRCER         (0x00000020U)               // bit5 CAN FD CRC错误
#define         CANFD_ERROR_F_FMER          (0x00000040U)               // bit6 CAN FD格式错误
#define         CANFD_ERROR_F_STER          (0x00000080U)               // bit7 CAN FD填充位错误
#define         CANFD_ERROR_F_BERR          (0x00000100U)               // bit8 CAN FD位错误
/* ==================== 私有函数声明 ==================== */

/* ==================== 应用层APP初始化函数 ==================== */
void U_CAN3_Init(void);
void U_CAN0_Init(void);
U_StatusTypeDef U_CANFD_Transmit(U_CANFD_Typedef* U_CANFDx, uint32_t RSTBx, uint8_t* Canfdbuf, uint32_t Buflength);
U_CAN_STATE_Typedef U_CAN_GetState(U_CANFD_Typedef* U_CANFDx);
uint32_t U_CAN_Get_SR(U_CANFD_Typedef* U_CANFDx);
uint32_t U_CAN_GetErrorCode(U_CANFD_Typedef* U_CANFDx);
/* ==================== 应用层APP任务函数 ==================== */
void CANFD_IRQ_Handlder(U_CANFD_Typedef *U_CANFDx);
void U_CANFD_RXCallBack(U_CANFD_Typedef *U_CANFDx);
void U_CANFD_ERRORCallBack(U_CANFD_Typedef *U_CANFDx);