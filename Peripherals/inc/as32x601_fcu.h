/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):    Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	 as32x601_fcu.h
 * Author:           ANSILIC APPLICATION GROUP
 * Version:          V1.0
 * Date:             2025/07/10
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2025/07/10     1.0     build this module
 * Description:     This file contains all the functions prototypes for the FCU firmware library.
 */

#ifndef AS32X601_FCU_H
#define AS32X601_FCU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601_fcu_regs.h"


/*
 * @brief   FCU Channel type enumeration
 */
typedef enum 
{
    FCU_CHANNEL_CPUDCLS             = 0x00,       /* FCU Channel 0  CPUDCLS         */
    FCU_CHANNEL_MPU0                = 0x01,       /* FCU Channel 1  MPU0            */
    FCU_CHANNEL_MPU1                = 0x02,       /* FCU Channel 2  MPU1            */
    FCU_CHANNEL_MPU2                = 0x03,       /* FCU Channel 3  MPU2            */
    FCU_CHANNEL_CACHEECC            = 0x04,       /* FCU Channel 4  CACHEECC        */
    FCU_CHANNEL_CPUPORTECC          = 0x05,       /* FCU Channel 5  CPUPORTECC      */
    FCU_CHANNEL_FLASHPORTECC        = 0x06,       /* FCU Channel 6  FLASHPORTECC    */
    FCU_CHANNEL_EFLASHECC           = 0x07,       /* FCU Channel 7  EFLASHECC       */
    FCU_CHANNEL_CPUIBUSTIMEOUT      = 0x08,       /* FCU Channel 8  CPUIBUSTOMEOUT  */
    FCU_CHANNEL_DMA0DCLS            = 0x09,       /* FCU Channel 9  DMA0DCLS        */
    FCU_CHANNEL_DMA1DCLS            = 0x0A,       /* FCU Channel 10 DMA1DCLS        */
    FCU_CHANNEL_MPUDMA0             = 0x0B,       /* FCU Channel 11 MPUDMA0         */
    FCU_CHANNEL_MPUDMA1             = 0x0C,       /* FCU Channel 12 MPUDMA1         */
    FCU_CHANNEL_DMA0ECC             = 0x0D,       /* FCU Channel 13 DMA0ECC         */
    FCU_CHANNEL_DMA1ECC             = 0x0E,       /* FCU Channel 14 DMA1ECC         */
    FCU_CHANNEL_SRAMECC             = 0x0F,       /* FCU Channel 15 SRAMECC         */
    FCU_CHANNEL_CPUDBUSTIMEOUT     = 0x10,        /* FCU Channel 16 CPUDBUSTIMEOUT  */
    FCU_CHANNEL_MACBUSTIMEOUT       = 0x11,       /* FCU Channel 17 MACBUSTIMEOUT   */
    FCU_CHANNEL_DMA0BUSTIMEOUT      = 0x12,       /* FCU Channel 18 DMA0BUSTIMEOUT  */
    FCU_CHANNEL_DMA1BUSTIMEOUT      = 0x13,       /* FCU Channel 19 DMA1BUSTIMEOUT  */
    FCU_CHANNEL_DSEBUSTIMEOUT       = 0x14,       /* FCU Channel 20 DSEBUSTIMEOUT   */
    FCU_CHANNEL_CPUPBUSTIMEOUT      = 0x15,       /* FCU Channel 21 CPUPBUSTIMEOUT  */
    FCU_CHANNEL_APB0ECC             = 0x16,       /* FCU Channel 22 APB0ECC         */
    FCU_CHANNEL_APB1ECC             = 0x17,       /* FCU Channel 23 APB1ECC         */
    FCU_CHANNEL_AXILITE0ECC         = 0x18,       /* FCU Channel 24 AXILITE0ECC     */
    FCU_CHANNEL_CMU0                = 0x19,       /* FCU Channel 25 CMU0            */
    FCU_CHANNEL_CMU1                = 0x1A,       /* FCU Channel 26 CMU1            */
    FCU_CHANNEL_CMU2                = 0x1B,       /* FCU Channel 27 CMU2            */
    FCU_CHANNEL_CMU3                = 0x1C,       /* FCU Channel 28 CMU3            */
    FCU_CHANNEL_AXILITE1ECC         = 0x1D,       /* FCU Channel 29 AXILITE1ECC     */
    FCU_CHANNEL_AXILITE2ECC         = 0x1E,       /* FCU Channel 30 AXILITE2ECC     */
    FCU_CHANNEL_WWDG0               = 0x1F,       /* FCU Channel 21 WWDG0           */
    FCU_CHANNEL_WWDG1               = 0x20,       /* FCU Channel 32 WWDG1           */
    FCU_CHANNEL_LVD                 = 0x21,       /* FCU Channel 33 LVD             */
    FCU_CHANNEL_HVD                 = 0x22,       /* FCU Channel 34 HVD             */
    FCU_CHANNEL_IWDG                = 0x23,       /* FCU Channel 35 IWDG            */
    FCU_CHANNEL_SOFTWARE0           = 0x24,       /* FCU Channel 36 SOFTWARE0       */
    FCU_CHANNEL_SOFTWARE1           = 0x25,       /* FCU Channel 37 SOFTWARE1       */
    FCU_CHANNEL_SOFTWARE2           = 0x26,       /* FCU Channel 38 SOFTWARE2       */
    FCU_CHANNEL_SOFTWARE3           = 0x27,       /* FCU Channel 39 SOFTWARE3       */
    FCU_CHANNEL_EXTENDFAULT0        = 0x28,       /* FCU Channel 40 EXTENDFAULT0    */
    FCU_CHANNEL_EXTENDFAULT1        = 0x29        /* FCU Channel 41 EXTENDFAULT1    */
} FCUCHANNEL_TypeDef;
#define IS_FCU_CHANNEL(CHANNEL) (((CHANNEL) == FCU_CHANNEL_CPUDCLS)         || ((CHANNEL) == FCU_CHANNEL_MPU0)              || \
                                 ((CHANNEL) == FCU_CHANNEL_MPU1)            || ((CHANNEL) == FCU_CHANNEL_CACHEECC)          || \
                                 ((CHANNEL) == FCU_CHANNEL_CPUPORTECC)      || ((CHANNEL) == FCU_CHANNEL_FLASHPORTECC)      || \
                                 ((CHANNEL) == FCU_CHANNEL_EFLASHECC)       || ((CHANNEL) == FCU_CHANNEL_CPUIBUSTIMEOUT)    || \
                                 ((CHANNEL) == FCU_CHANNEL_DMA0DCLS)        || ((CHANNEL) == FCU_CHANNEL_DMA1DCLS)          || \
                                 ((CHANNEL) == FCU_CHANNEL_SRAMECC)         || ((CHANNEL) == FCU_CHANNEL_CPUDBUSTIMEOUT)    || \
                                 ((CHANNEL) == FCU_CHANNEL_MACBUSTIMEOUT)   || ((CHANNEL) == FCU_CHANNEL_DMA0BUSTIMEOUT)    || \
                                 ((CHANNEL) == FCU_CHANNEL_DMA1BUSTIMEOUT)  || ((CHANNEL) == FCU_CHANNEL_DSEBUSTIMEOUT)     || \
                                 ((CHANNEL) == FCU_CHANNEL_CPUPBUSTIMEOUT)  || ((CHANNEL) == FCU_CHANNEL_APB0ECC)           || \
                                 ((CHANNEL) == FCU_CHANNEL_CMU0)            || ((CHANNEL) == FCU_CHANNEL_CMU1)              || \
                                 ((CHANNEL) == FCU_CHANNEL_CMU2)            || ((CHANNEL) == FCU_CHANNEL_CMU3)              || \
                                 ((CHANNEL) == FCU_CHANNEL_WWDG0)           || ((CHANNEL) == FCU_CHANNEL_WWDG1)             || \
                                 ((CHANNEL) == FCU_CHANNEL_LVD)             || ((CHANNEL) == FCU_CHANNEL_HVD)               || \
                                 ((CHANNEL) == FCU_CHANNEL_IWDG)            || ((CHANNEL) == FCU_CHANNEL_SOFTWARE0)         || \
                                 ((CHANNEL) == FCU_CHANNEL_SOFTWARE1)       || ((CHANNEL) == FCU_CHANNEL_SOFTWARE2)         || \
                                 ((CHANNEL) == FCU_CHANNEL_SOFTWARE3)       || ((CHANNEL) == FCU_CHANNEL_EXTENDFAULT0)      || \
                                 ((CHANNEL) == FCU_CHANNEL_EXTENDFAULT1)    || ((CHANNEL) == FCU_CHANNEL_AXILITE1ECC)       || \
                                 ((CHANNEL) == FCU_CHANNEL_AXILITE2ECC)     || ((CHANNEL) == FCU_CHANNEL_AXILITE0ECC )      || \
                                 ((CHANNEL) == FCU_CHANNEL_APB1ECC)         || ((CHANNEL) == FCU_CHANNEL_MPUDMA0 )          || \
                                 ((CHANNEL) == FCU_CHANNEL_MPUDMA1)         || ((CHANNEL) == FCU_CHANNEL_DMA0ECC )          || \
                                 ((CHANNEL) == FCU_CHANNEL_DMA1ECC)         || ((CHANNEL) == FCU_CHANNEL_MPU2 ))

/*
 * @brief  Use by parameter examine.
 */
#define IS_FCU_SOFTWARE_TYPE(TYPE) (((TYPE) == FCU_CHANNEL_SOFTWARE0)       || ((TYPE) == FCU_CHANNEL_SOFTWARE1)           || \
                                    ((TYPE) == FCU_CHANNEL_SOFTWARE2)       || ((TYPE) == FCU_CHANNEL_SOFTWARE3))

/*
 * @brief  Use by parameter examine.
 */
#define IS_FCU_ECCFAULT_TYPE(TYPE) (((TYPE) == FCU_CHANNEL_CACHEECC)      || ((TYPE) == FCU_CHANNEL_CPUPORTECC)           || \
                                    ((TYPE) == FCU_CHANNEL_FLASHPORTECC)  || ((TYPE) == FCU_CHANNEL_EFLASHECC)            || \
                                    ((TYPE) == FCU_CHANNEL_DMA0ECC)       || ((TYPE) == FCU_CHANNEL_DMA1ECC)              || \
                                    ((TYPE) == FCU_CHANNEL_SRAMECC)       || ((TYPE) == FCU_CHANNEL_APB0ECC)              || \
                                    ((TYPE) == FCU_CHANNEL_APB1ECC)       || ((TYPE) == FCU_CHANNEL_AXILITE0ECC)          || \
                                    ((TYPE) == FCU_CHANNEL_AXILITE1ECC)   || ((TYPE) == FCU_CHANNEL_AXILITE2ECC))

/*
 * @brief   FCU FAULT Action type enumeration
 */
typedef enum 
{
    FAULT_INTERRUPT                     = 0x00,         /* FCU FAULT Action Interrupt               */
    GLOBAL_SOFTWARE_RESET               = 0x02          /* FCU FAULT Action Global Software Reset   */
} FCUFAULTACTION_TypeDef;
#define IS_FAULTACTION_STATE(STATE) (((STATE) == INTERRUPT) || ((STATE) == GLOBAL_SOFTWARE_RESET))

/*
 * @brief   FCU ALARM Action type enumeration
 */
typedef enum 
{
    NONE                    = 0x00,         /* FCU ALARM Action NONE              */
    ALARM_INTERRUPT         = 0x01          /* FCU ALARM Action Interrupt         */
} FCUALARMACTION_TypeDef;
#define IS_ALARMACTION_STATE(STATE) (((STATE) == INTERRUPT) || ((STATE) == NONE))

/*
 * @brief   FCU ALARM Action type enumeration
 */
typedef enum 
{
    INGORY                  = 0x00,         /* FCU FAULT Level INGORY            */
    ALARM                   = 0x01,         /* FCU FAULT Level ALARM             */
    FAULT                   = 0x02          /* FCU FAULT Level FAULT             */
} FCUFAULTLEVEL_TypeDef;
#define IS_FAULTLEVEL_STATE(STATE) (((STATE) == INGORY) || ((STATE) == ALARM) || ((STATE) == FAULT))

#define IS_FAULTTORESET_COUNT(COUNT) (((COUNT) >= 0) && ((COUNT) <= 0xFFU))
#define IS_ALARMTOFAULT_COUNT(COUNT) (((COUNT) >= 0) && ((COUNT) <= 0xFFU))
/*
 * @brief FCU init structure definition
 */
typedef struct
{
    FCUCHANNEL_TypeDef      FCU_Channel;                        /* Specifies the channel to be configured */
    uint8_t                 FCU_FOCUToResetCnt;                 /* Specifies the count to reset under FOCU */
    uint8_t                 FCU_AlarmToFaultCnt;                /* Specifies the count to change the level from alarm to fault */
    FCUFAULTACTION_TypeDef  FCU_FaultAction;                    /* Specifies the actin when the fault occured every time */
    FCUALARMACTION_TypeDef  FCU_AlarmAction;                    /* Specifies the actin when the alarm occured every time */
    FCUFAULTLEVEL_TypeDef   FCU_FaultLevel;                     /* Specifies the fault level */
    FunctionalState         FCU_MaskEnable;                     /* Specifies the mask enable */
} FCU_InitTypeDef;

#define FCU_SOFTWARE_CHANNEL_0  (uint32_t)0x00000001
#define FCU_SOFTWARE_CHANNEL_1  (uint32_t)0x00000002
#define FCU_SOFTWARE_CHANNEL_2  (uint32_t)0x00000004
#define FCU_SOFTWARE_CHANNEL_3  (uint32_t)0x00000008
#define IS_SOFTWARE_CHANNEL(CHANNEL)  (((CHANNEL) >= 1) && ((CHANNEL) <= 0xFU))

#define IS_SOFTWARE_COUNT(COUNT) (((COUNT) >= 0) && ((COUNT) <= 0xFFU))


/*
 * @brief Function declaration
 */
void FCU_StructInit(FCU_InitTypeDef *FCU_InitStruct);
void FCU_Init(FCU_InitTypeDef *FCU_InitStruct);
void FCU_Cmd(FCUCHANNEL_TypeDef Channelx, FunctionalState NewState);
void FCU_SetSoftwareTrigger(uint32_t SoftwareChannelx);
FlagStatus FCU_GetSoftwareFaultStatus(uint32_t SoftwareChannelx);
void FCU_SetSoftwareFaultCount(uint32_t SoftwareChannelx, uint8_t count);
uint8_t FCU_GetSoftwareFaultCount(uint32_t SoftwareChannelx);
void FCU_ClearSoftwareFault(uint32_t SoftwareChannelx);
FlagStatus FCU_GetAlarmStatus(FCUCHANNEL_TypeDef Channelx);
FlagStatus FCU_GetFaultStatus(FCUCHANNEL_TypeDef Channelx);
void FCU_ClearFcuStatus(FCUCHANNEL_TypeDef Channelx);
void FCU_ClearBusTimeoutFaultStatus(void);
void FCU_ClearECCFaultStatus(void);

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
