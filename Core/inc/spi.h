/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
/* ==================== 静态变量声明 ==================== */
typedef struct 
{
    SPI_TypeDef *SPIx;
}U_SPI_typedef;

extern U_SPI_typedef U_SPI4;
extern U_SPI_typedef U_SPI3;
/* ==================== 应用层APP初始化函数 ==================== */
void U_SPI3_Init(void);
void U_SPI4_Init(void);
/* ==================== 应用层APP任务函数 ==================== */
U_StatusTypeDef U_SPI_SendData(U_SPI_typedef *U_SPI, uint32_t Data);
U_StatusTypeDef U_SPI_SendData_IT(U_SPI_typedef *U_SPI, uint32_t Data);

/* ==================== 中断服务函数 ==================== */
void SPI_IRQ_Handler(U_SPI_typedef *U_SPI);
void U_SPI_TxCpltCallback(U_SPI_typedef *U_SPI);