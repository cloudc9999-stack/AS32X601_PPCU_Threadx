
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "as32x601_configure.h"
#include "as32x601_mpu.h"
#include "as32x601.h"
#include "tim.h"
/* Exported define -----------------------------------------------------------*/

#define LED1_Pin GPIO_Pin_5
#define LED1_GPIO_Port GPIOE

#define LED2_Pin GPIO_Pin_6
#define LED2_GPIO_Port GPIOE

#define LED3_Pin GPIO_Pin_11
#define LED3_GPIO_Port GPIOB
 
#define LED4_Pin GPIO_Pin_9
#define LED4_GPIO_Port GPIOE

#define LED5_Pin GPIO_Pin_10
#define LED5_GPIO_Port GPIOB

#define CAN3_STB_Pin GPIO_Pin_6
#define CAN3_STB_GPIO_Port GPIOC
// S1输出
#define S1O1_Pin GPIO_Pin_12
#define S1O1_GPIO_Port GPIOD

#define S1O2_Pin GPIO_Pin_11
#define S1O2_GPIO_Port GPIOD

#define S1O3_Pin GPIO_Pin_10
#define S1O3_GPIO_Port GPIOD

#define S1O4_Pin GPIO_Pin_9
#define S1O4_GPIO_Port GPIOD

#define S1O5_Pin GPIO_Pin_8
#define S1O5_GPIO_Port GPIOD

#define S1O6_Pin GPIO_Pin_15
#define S1O6_GPIO_Port GPIOB
// S1 输入
#define S1I1_Pin GPIO_Pin_13
#define S1I1_GPIO_Port GPIOA

#define S1I2_Pin GPIO_Pin_12
#define S1I2_GPIO_Port GPIOA

#define S1I3_Pin GPIO_Pin_11
#define S1I3_GPIO_Port GPIOA

#define S1I4_Pin GPIO_Pin_10
#define S1I4_GPIO_Port GPIOA

#define S1I5_Pin GPIO_Pin_9
#define S1I5_GPIO_Port GPIOA

#define S1I6_Pin GPIO_Pin_8
#define S1I6_GPIO_Port GPIOA

#define NSS2_Pin GPIO_Pin_4     // SPI4 ---> CS
#define NSS2_GPIO_Port GPIOG

#define NSS1_Pin GPIO_Pin_10    // SPI3 ---> CS
#define NSS1_GPIO_Port GPIOC
/* Exported functions ------------------------------------------------------- */
void Error_Handler(void);
#endif

/*****END OF FILE*****/
