/*
 *  Author: cloudc
 *
 * 
 * 
*/
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "tx_api.h"
#include "usart.h"
#include "adc.h"
#include "can.h"
#include "spi.h"
/* Private typedef -----------------------------------------------------------*/

void Systemclock_Init();
void borad_init(void);
/* Exported define -----------------------------------------------------------*/

/*
 * Brief:           Main program
 * Description:     
 * Param:           None.
 * Return:          None.
 */
int main(void)
{
    Systemclock_Init();
    U_TIM6_Init();
    U_GPIO_Init();
    U_USART5_Init();
    U_ADC1_Init();
    U_CAN0_Init();
    U_SPI4_Init();
    tx_kernel_enter();


    while(1);
    return 0;
}


/*
 * Function:        Systemclock_Init
 * Description:     Configure Systemclock_Init.
 * Param:           None                
 * Return:          None.
 */
void Systemclock_Init()
{
    //注意：此处需要开启系统总线级的时钟配置，具体外设时钟配置可在各模块初始化函数中具体开启,具体请参考时钟树或者下图注释
    //      1. 使用串口时，由于串口挂在APB0总线下，需要在此处开启AXIBUS3时钟、AXI4TOAPB0时钟以及APBBUS0时钟。
    //      2. 使用延时函数时，需要开启CLINT时钟
    //      3. 使用eflash、qspi时，需要开启AXIBUS3时钟、AXILITEBUS2时钟
    
    //注意：osc经过PLLDIVN分频之后频率应在0.95-2.1MHz之间
    //      core_clock          (无需使能)          = pll_Q = osc % PLLDIVN x PLLDIVF % PLLDIVQ         (注：此部分时钟计算范围应在16-180MHz之间)
    //      AXI4Bus0            (无需使能)          = pll_Q = osc % PLLDIVN x PLLDIVF % PLLDIVQ         (注：此部分时钟计算范围应在16-180MHz之间)
    //      AXI4Bus1            (无需使能)          = pll_Q % 2                                         (注：此部分时钟计算范围应在8-90MHz之间)
    //      AXI4Bus2            (无需使能)          = pll_Q                                             (注：此部分时钟计算范围应在16-180MHz之间)
    //      |__AXILite4Bus0     (无需使能)          = AXI4Bus2
    //      AXI4Bus3            (按需使能)          = pll_Q % 2 % AXI4Bus3CLKDiv                        (注：此部分时钟计算范围应在8-90MHz之间)
    //      |__AXI4TOAPB0_CLK   (按需使能)
    //      |  |__APBBus0       (按需使能)          = AXI4Bus3 % APBBus0CLKDiv                          (注：此部分时钟计算范围应在4-45MHz之间)
    //      |__AXI4TOAPB1_CLK   (按需使能)
    //      |  |__APBBus1       (按需使能)          = AXI4Bus3 % APBBus1CLKDiv                          (注：此部分时钟计算范围应在4-45MHz之间)
    //      |__AXILite4Bus1     (按需使能)          = AXI4Bus3
    //      |__AXILite4Bus2     (按需使能)          = AXI4Bus3
    //      CANCLK              (接口使能)          = pll_R % 2 % CANX2CLKDiv = osc % PLLDIVN x PLLDIVF % PLLDIVR  % 2 % CANX2CLKDiv        (注：此部分时钟计算范围应在8-80MHz之间)
    //      APBBusS             (无需使能)          = 32.768kHz
    
    /* AXIBus3 clock operation Guide*/
    AXIBUS3_CLK_ENABLE();
    AXI4TOAPB0_CLK_ENABLE();
    APBBUS0_CLK_ENABLE();
    AXI4TOAPB1_CLK_ENABLE();
    APBBUS1_CLK_ENABLE();
    AXILITEBUS1_CLK_ENABLE();
    AXILITEBUS2_CLK_ENABLE();
    EFLASH_CLK_ENABLE();   
    PLIC_CLK_ENABLE();
    CLINT_CLK_ENABLE();
    
    PMU_LDO1v2VOLSca(PMU_VO12_1V28);
    PMU_LDO2v5VOLSca(PMU_VO25_2V72);

    SMU_PLLInitTypeDef SMU_PLLInitStruct;
    SMU_ClockInitTypeDef SMU_ClockInitStruct;
  
    /* Set PLL parameters values */
    SMU_PLLInitStruct.OscillatorType = SMU_OSCILLATORTYPE_OSC;
    SMU_PLLInitStruct.FIRCOscState = DISABLE;
    SMU_PLLInitStruct.FIRCCalibrationValue = 0x00;
    SMU_PLLInitStruct.PLLConfig.PLLState = ENABLE;
    SMU_PLLInitStruct.PLLConfig.PLLSource = SMU_PLLCLK_OSC;
    SMU_PLLInitStruct.PLLConfig.PLLDivR = 0x01;
    SMU_PLLInitStruct.PLLConfig.PLLDivQ = 0x01;
    SMU_PLLInitStruct.PLLConfig.PLLDivN = 0x14; // 20分频
    SMU_PLLInitStruct.PLLConfig.PLLDivF = 0xB4; // 180倍频
    SMU_PLLInit(&SMU_PLLInitStruct); 
    
    /* Ensure that the EFLASH is consistent with the system clock */
    FLASH_UnlockCtrl();
    FLASH_SetCLKFreq(0xB4);
    
    /* Set System Clock parameters values */
    SMU_ClockInitStruct.SYSCLKSelect = SMU_SYSCLK_PLL;
    SMU_ClockInitStruct.AXI4Bus3CLKDiv = AXI4Bus3CLKDiv1;
    SMU_ClockInitStruct.APBBus0CLKDiv = APBBus0CLKDiv2;
    SMU_ClockInitStruct.APBBus1CLKDiv = APBBus1CLKDiv2;
    SMU_ClockInitStruct.CANX2CLKDiv = CANX2CLKDiv1;
  
    SMU_ClockInit(&SMU_ClockInitStruct);
    
    EFLASH_CLK_UPDATE_ENABLE();
    EFLASH_CLK_UPDATE_DISABLE();

    FLASH_LockCtrl();
    
    /* Get System Clock values */
    SMU_GetClocksFreq(&SMU_ClocksStruct);
}
/*
    描述：主要针对硬件平台对Threadx系统的初始化
          主要工作有初始化定时器，开启全局中断。
*/
void borad_init(void)
{
    U_TIM6_Init();

}

/* 
 * 
 * risc-v 架构中GCC工具链的 printf 函数重定向 
 */

#include <sys/stat.h>
#include <errno.h>
int _write(int file, char *ptr, int len)
{
    // U_USART_Transmit_FIFO(&U_USART5, (uint8_t*)ptr, (uint16_t)len);
    U_USART_Transmit(&U_USART5, (uint8_t*)ptr, (uint16_t)len, 10);
    return len;
}

void Error_Handler(void)
{
    PLIC_CLK_DISABLE();
      while (1)
    {
        GPIO_ClearBits(LED1_GPIO_Port, LED1_Pin | LED2_Pin | LED3_Pin);
    }
}