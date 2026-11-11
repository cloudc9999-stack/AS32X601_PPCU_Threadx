/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_pka.c
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/29
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/29     1.0     build this module
 * Description:     This file provides firmware functions to manage the functionalities of the PKA peripheral.
 */

#include "as32x601_pka.h"
#include <stddef.h>

/**
 * Function:        PKA_Struct
 * Description:     Initialization convert structure.
 * Param:           PKA_Struct: convert config structure pointer.
 * Return:          None.
 */
void PKA_Struct(PKA_InitTypeDef * const PKA_InitStruct)
{
    /* Reset PKA init structure parameters values */
    PKA_InitStruct->PKA_PartialRadix = 17;
    PKA_InitStruct->PKA_BaseRadix = PKA_BASE_RADIX_256;
    PKA_InitStruct->PKA_M521Mode = 0;
    PKA_InitStruct->PKA_StopRqst = PKA_STOP_RQST_DIS;
    PKA_InitStruct->PKA_Go = PKA_GO_DIS;
    PKA_InitStruct->PKA_AltAccess = PKA_ALT_ACCESS_NORMAL;
    PKA_InitStruct->PKA_EndianSwap = PKA_ENDIAN_SWAP_LITTLE;
}

/**
 * Function:        PKA_Init
 * Description:     Initialization PKA peripheral.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 *                  PKA_InitStruct: PKA config structure pointer.
 * Return:          None.
 */
void PKA_Init(PKA_TypeDef *PKAx, const PKA_InitTypeDef * const PKA_InitStruct)
{
    uint32_t tmpreg = 0x00;
  
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));
    assert_param(PKA_InitStruct != NULL);
    assert_param(IS_PKA_BASE_RADIX(PKA_InitStruct->PKA_BaseRadix));
    assert_param(IS_PKA_STOP_RQST(PKA_InitStruct->PKA_StopRqst));
    assert_param(IS_PKA_GO(PKA_InitStruct->PKA_Go));
    assert_param(IS_PKA_ALT_ACCESS(PKA_InitStruct->PKA_AltAccess));
    assert_param(IS_PKA_ENDIAN_SWAP(PKA_InitStruct->PKA_EndianSwap));
    
    tmpreg = PKAx->CONFIG;

    /* Enable the alternate access mode */
    tmpreg &= ~((uint32_t)PKA_CONFIG_ALT_ACCESS);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_AltAccess) << PKA_CONFIG_ALT_ACCESS_Pos);

    /* Set PKA endian swap mode */
    tmpreg &= ~((uint32_t)PKA_CONFIG_ENDIAN_SWAP);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_EndianSwap) << PKA_CONFIG_ENDIAN_SWAP_Pos);
    
    PKAx->CONFIG = tmpreg;
    
    tmpreg = PKAx->CTRL;

    /* Set PKA partial radix */
    tmpreg &= ~((uint32_t)PKA_CTRL_PARTIAL_RADIX);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_PartialRadix) << PKA_CTRL_PARTIAL_RADIX_Pos);

    /* Set PKA base radix */
    tmpreg &= ~((uint32_t)PKA_CTRL_BASE_RADIX);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_BaseRadix) << PKA_CTRL_BASE_RADIX_Pos);

    /* Set PKA M521 mode */
    tmpreg &= ~((uint32_t)PKA_CTRL_M521_MODE);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_M521Mode) << PKA_CTRL_M521_MODE_Pos);

    /* Set PKA stop request */
    tmpreg &= ~((uint32_t)PKA_CTRL_STOP_RQST);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_StopRqst) << PKA_CTRL_STOP_RQST_Pos);

    /* Set PKA go */
    tmpreg &= ~((uint32_t)PKA_CTRL_GO);
    tmpreg |= (((uint32_t)PKA_InitStruct->PKA_Go) << PKA_CTRL_GO_Pos);
    
    PKAx->CTRL = tmpreg;
}

/**
 * Function:        PKA_ITConfig
 * Description:     Enable or disable the PKA interrupt.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 *                  ITType: PKA interrupt type.
 *                   This parameter can be one of the following values:
 *                    PKA_IT_SIF_ERR：SIF error interrupt enable.
 *                    PKA_IT_SIF_SBE：
 *                    PKA_IT_DONE: Done interrupt enable.
 *                    PKA_IT_GLB: Global interrupt enable.
 *                  NewState: ENABLE or DISABLE.
 * Return:          None.
 */
void PKA_ITConfig(PKA_TypeDef *PKAx, uint32_t ITType, EnState NewState)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));
    assert_param(IS_PKA_IT(ITType));

    /* Configure the PKA interrupt */
    if (NewState != DISABLE)
    {
        PKAx->IRQ_EN |= ITType;
    }
    else
    {
        PKAx->IRQ_EN &= ~ITType;
    }
}

/**
 * Function:        PKA_GetFlagStatus
 * Description:     Get the PKA flag status.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral
 *                  PKA_FLAG: PKA flag.
 *                   This parameter can be one of the following values:
 *                    PKA_FLAG_ZERO: Zero flag.
 *                    PKA_FLAG_MEMORYTEST: Memory test flag.
 *                    PKA_FLAG_BORROW: Borrow flag.
 *                    PKA_FLAG_CARRY: Carry flag.
 *                    PKA_FLAG_USERFLAG0: User flag 0.
 *                    PKA_FLAG_USERFLAG1: User flag 1.
 *                    PKA_FLAG_USERFLAG2: User flag 2.
 *                    PKA_FLAG_USERFLAG3: User flag 3.
 * Return:          The new state of PKA_FLAG (SET or RESET).
 * Note:            None.
 */
FlagStatus PKA_GetFlagStatus(PKA_TypeDef *PKAx, uint32_t PKA_Flag)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));
    assert_param(IS_PKA_FLAG(PKA_Flag));

    /* Return the PKA_FLAG status */
    return (FlagStatus)(PKAx->FLAGS & PKA_Flag);
}

/**
 * Function:        PKA_GetStatStatus
 * Description:     Get the PKA stat status.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 *                  PKA_Stat: PKA stat.
 *                   This parameter can be one of the following values:
 *                    PKA_STATE_SIF_ERR：Indicates that an SIF error has occurred.
 *                    PKA_STATE_SIF_SBE：Indicates that an SIF single bit error has occurred.
 *                    PKA_STATE_DONE: Indicates that the operation has completed.
 * Return:          The new state of PKA_FLAG (SET or RESET).
 * Note:            None.
 */
FlagStatus PKA_GetStatStatus(PKA_TypeDef *PKAx, uint32_t PKA_Stat)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));
    assert_param(IS_PKA_IT_STATE(PKA_Stat));

    /* Return the PKA_STAT status */
    return (FlagStatus)(PKAx->STAT & PKA_Stat);
}

/**
 * Function:        PKA_ClearStatus
 * Description:     Clear the PKA stat status.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 *                  PKA_Stat: PKA stat.
 *                   This parameter can be one of the following values:
 *                    PKA_STATE_SIF_ERR：Indicates that an SIF error has occurred.
 *                    PKA_STATE_SIF_SBE：Indicates that an SIF single bit error has occurred.
 *                    PKA_STATE_DONE: Indicates that the operation has completed.
 * Return:          None.
 * Note:            None.
 */
void PKA_ClearStatus(PKA_TypeDef *PKAx, uint32_t PKA_Stat)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));
    assert_param(IS_PKA_IT_STATE(PKA_Stat));

    /* Clear the PKA_STAT status */
    PKAx->STAT &= ~PKA_Stat;
}

/**
 * Function:        PKA_SetStack
 * Description:     Set the PKA stack pointer.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 *                  StackPtr: Stack pointer.
 * Return:          None.
 * Note:            None.
 */
void PKA_SetStack(PKA_TypeDef *PKAx, uint32_t StackPtr)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));

    /* Set the stack pointer */
    PKAx->ENTRY_PNT = StackPtr;
}

/**
 * Function:        PKA_ClearStack
 * Description:     Clear the PKA stack pointer.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 * Return:          None.
 * Note:            None.
 */
void PKA_ClearStack(PKA_TypeDef *PKAx)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));

    /* Clear the stack pointer */
    PKAx->STACK_PNTR = 0x0;
}

/**
 * Function:        PKA_GetRTNCode
 * Description:     Get the PKA stop reason code.
 * Param:           PKAx: where x can be (0) to select the PKA peripheral.
 * Return:          PKA_StopReasonEnum.
 * Note:            None.
 */
PKA_StopReasonEnum PKA_GetStopReasonCode(PKA_TypeDef *PKAx)
{
    /* Check the parameters */
    assert_param(IS_PKA_ALL_PERIPH(PKAx));

    /* Return the return code */
    return (PKA_StopReasonEnum)((PKAx->RTN_CODE & PKA_RTN_CODE_STOP_REASON) >> PKA_RTN_CODE_STOP_REASON_Pos);
}

/*****END OF FILE*****/
