/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_trng.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/9
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/9      1.0     build this module
 * Description:     This file contains all the functions prototypes for the TRNG firmware library.
 */
#ifndef AS32X601_TRNG_H
#define AS32X601_TRNG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601_trng_regs.h"

/*
 * @brief  Use by parameter examine.
 */
#define IS_TRNG_ALL_PERIPH(PERIPH) (((PERIPH) == TRNG))

/*
 * @brief TRNG Init Structure definition
 */
typedef struct
{
    uint32_t TRNG_Commond;                              /* TRNG Execute A Command */
} TRNG_InitTypeDef;

/*
 * @brief TRNG commands selection
 */
#define TRNG_COMMAND_NOP                    ((uint32_t)0x00000000)          /* No command */
#define TRNG_COMMAND_GEN_NOISE              ((uint32_t)0x00000001)          /* Generate full-entropy seed from noise */
#define TRNG_COMMAND_GEN_NONCE              ((uint32_t)0x00000002)          /* Generate seed from host-written nonce */
#define TRNG_COMMAND_CREATE_STATE           ((uint32_t)0x00000003)          /* Move DRBG to create state */
#define TRNG_COMMAND_RENEW_STATE            ((uint32_t)0x00000004)          /* Move DRBG to renew state */
#define TRNG_COMMAND_REFRESH_ADDIN          ((uint32_t)0x00000005)          /* Move DRBG to refresh addin */
#define TRNG_COMMAND_GEN_RANDOM             ((uint32_t)0x00000006)          /* Move DRBG to refresh addin */
#define TRNG_COMMAND_ADVANCE_STATE          ((uint32_t)0x00000007)          /* Advance DRBG state */
#define TRNG_COMMAND_RUN_KAT                ((uint32_t)0x00000008)          /* Run KAT on DRBG or entropy source */
#define TRNG_COMMAND_ZEROIZE                ((uint32_t)0x0000000F)          /* Zeroize */
#define IS_TRNG_COMMAND(COMMAND)            (((COMMAND) == TRNG_COMMAND_NOP) 	        || ((COMMAND) == TRNG_COMMAND_GEN_NOISE) || \
											 ((COMMAND) == TRNG_COMMAND_GEN_NONCE) 	    || ((COMMAND) == TRNG_COMMAND_CREATE_STATE) || \
											 ((COMMAND) == TRNG_COMMAND_RENEW_STATE)    || ((COMMAND) == TRNG_COMMAND_REFRESH_ADDIN) || \
											 ((COMMAND) == TRNG_COMMAND_GEN_RANDOM) 	|| ((COMMAND) == TRNG_COMMAND_ADVANCE_STATE) || \
                                             ((COMMAND) == TRNG_COMMAND_RUN_KAT) 	    || ((COMMAND) == TRNG_COMMAND_ZEROIZE))

/*
 * @brief TRNG Interrupt Enable selection
 */
#define TRNG_IT_ZEROIZED                    TRNG_IE_ZEROIZED                /* Zeroized interrupt enable */
#define TRNG_IT_KAT_COMPLETE                TRNG_IE_KAT_COMPLETE            /* KAT complete interrupt enable */
#define TRNG_IT_NOISE_RDY                   TRNG_IE_NOISE_RDY               /* Noise ready interrupt enable */
#define TRNG_IT_ALARMED                     TRNG_IE_ALARMED                 /* Alarmed interrupt enable */
#define TRNG_IT_DONE                        TRNG_IE_DONE                    /* Done interrupt enable */
#define TRNG_IT_GLBL                        TRNG_IE_GLBL                    /* Global interrupt enable */
#define IS_TRNG_IT(IT)                      (((IT) == TRNG_IT_ZEROIZED)     || ((IT) == TRNG_IT_KAT_COMPLETE) || \
											 ((IT) == TRNG_IT_NOISE_RDY)    || ((IT) == TRNG_IT_ALARMED) || \
											 ((IT) == TRNG_IT_DONE)         || ((IT) == TRNG_IT_GLBL))

/*
 * @brief TRNG Interrupt State selection
 */
#define TRNG_IT_STATE_ZEROIZED              TRNG_ISTAT_ZEROIZED             /* Zeroized interrupt state */
#define TRNG_IT_STATE_KAT_COMPLETE          TRNG_ISTAT_KAT_COMPLETE         /* KAT complete interrupt state */
#define TRNG_IT_STATE_NOISE_RDY             TRNG_ISTAT_NOISE_RDY            /* Noise ready interrupt state */
#define TRNG_IT_STATE_ALARMED               TRNG_ISTAT_ALARMED              /* Alarmed interrupt state */
#define TRNG_IT_STATE_DONE                  TRNG_ISTAT_DONE                 /* Done interrupt state */
#define IS_TRNG_IT_STATE(STATE)             (((STATE) == TRNG_IT_STATE_ZEROIZED)     || ((STATE) == TRNG_IT_STATE_KAT_COMPLETE) || \
											 ((STATE) == TRNG_IT_STATE_NOISE_RDY)    || ((STATE) == TRNG_IT_STATE_ALARMED) || \
											 ((STATE) ==TRNG_IT_STATE_DONE))

/*
 * @brief TRNG Interrupt State Clear
 */                                   
#define TRNG_STATE_CLEAR_ZEROIZED           TRNG_ISTAT_ZEROIZED             /* Zeroized interrupt state clear */
#define TRNG_STATE_CLEAR_KAT_COMPLETE       TRNG_ISTAT_KAT_COMPLETE         /* KAT complete interrupt state clear */
#define TRNG_STATE_CLEAR_NOISE_RDY          TRNG_ISTAT_NOISE_RDY            /* Noise ready interrupt state clear */
#define TRNG_STATE_CLEAR_ALARMED            TRNG_ISTAT_ALARMED              /* Alarmed interrupt state clear */
#define TRNG_STATE_CLEAR_DONE               TRNG_ISTAT_DONE                 /* Done interrupt state clear */
#define IS_TRNG_STATE_CLEAR(CLEAR)          (((CLEAR) == TRNG_STATE_CLEAR_ZEROIZED)     || ((CLEAR) == TRNG_STATE_CLEAR_KAT_COMPLETE) || \
											 ((CLEAR) == TRNG_STATE_CLEAR_NOISE_RDY)    || ((CLEAR) == TRNG_STATE_CLEAR_ALARMED) || \
                                             ((CLEAR) == TRNG_STATE_CLEAR_DONE))

/*
 * @brief Function declaration
 */
void TRNG_StructInit(TRNG_InitTypeDef * const TRNG_InitStruct);
void TRNG_Init(TRNG_TypeDef *TRNGx, const TRNG_InitTypeDef * const TRNG_InitStruct);
uint32_t TRNG_GetRandomNumber0(TRNG_TypeDef *TRNGx);
uint32_t TRNG_GetRandomNumber1(TRNG_TypeDef *TRNGx);
uint32_t TRNG_GetRandomNumber2(TRNG_TypeDef *TRNGx);
uint32_t TRNG_GetRandomNumber3(TRNG_TypeDef *TRNGx);
void TRNG_ITConfig(TRNG_TypeDef *TRNGx, uint32_t ITType, EnState NewState);
FlagStatus TRNG_GetITStatus(TRNG_TypeDef *TRNGx, uint32_t TRNG_IT);
void TRNG_ClearITPendingBit(TRNG_TypeDef *TRNGx, uint32_t ClearIT);

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
