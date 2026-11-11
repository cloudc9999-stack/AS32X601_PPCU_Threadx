/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_trng.c
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/9
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/9      1.0     build this module
 * Description:     This file provides firmware functions to manage the functionalities of the TRNG peripheral.
 */

#include "as32x601_trng.h"
#include <stddef.h>

/*
 * Function:        TRNG_StructInit
 * Description:     Initialization convert structure.
 * Param:           TRNG_InitStruct: convert config structure pointer.
 * Return:          None.
 */
void TRNG_StructInit(TRNG_InitTypeDef * const TRNG_InitStruct)
{
    /* Reset TRNG init structure parameters values */
    TRNG_InitStruct->TRNG_Commond   = TRNG_COMMAND_NOP;
}

/*
 * Function:        TRNG_Init
 * Description:     Config TRNG convert setting.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 *                  TRNG_InitStruct: convert config that need to config.
 * Return:          None.
 */
void TRNG_Init(TRNG_TypeDef *TRNGx, const TRNG_InitTypeDef * const TRNG_InitStruct)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));
    assert_param(IS_TRNG_COMMAND(TRNG_InitStruct->TRNG_Commond));

    /* Set TRNG command */
    TRNGx->CTRL &= ~((uint32_t)TRNG_CTRL_CMD);
    TRNGx->CTRL |= (((uint32_t)TRNG_InitStruct->TRNG_Commond) << TRNG_CTRL_CMD_Pos);
}

/*
 * Function:        TRNG_GetRandomNumber0
 * Description:     Get TRNG random number.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 * Return:          TRNG random number.
 */
uint32_t TRNG_GetRandomNumber0(TRNG_TypeDef *TRNGx)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));

    /* Return TRNG random number */
    return TRNGx->RAND0;
}

/*
 * Function:        TRNG_GetRandomNumber1
 * Description:     Get TRNG random number.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 * Return:          TRNG random number.
 */
uint32_t TRNG_GetRandomNumber1(TRNG_TypeDef *TRNGx)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));

    /* Return TRNG random number */
    return TRNGx->RAND1;
}

/*
 * Function:        TRNG_GetRandomNumber2
 * Description:     Get TRNG random number.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 * Return:          TRNG random number.
 */
uint32_t TRNG_GetRandomNumber2(TRNG_TypeDef *TRNGx)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));

    /* Return TRNG random number */
    return TRNGx->RAND2;
}

/*
 * Function:        TRNG_GetRandomNumber3
 * Description:     Get TRNG random number.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 * Return:          TRNG random number.
 */
uint32_t TRNG_GetRandomNumber3(TRNG_TypeDef *TRNGx)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));

    /* Return TRNG random number */
    return TRNGx->RAND3;
}

/*
 * Function:        TRNG_ITConfig
 * Description:     Enable or disable the TRNG interrupt.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 *                  ITType: TRNG interrupt type.
 *                   This parameter can be one of the following values:
 *                    TRNG_IT_ZEROIZED: TRNG Zeroized interrupt enable.
 *                    TRNG_IT_KAT_COMPLETE: TRNG KAT complete interrupt enable.
 *                    TRNG_IT_ALARMED: TRNG Alarmed interrupt enable.   
 *                    TRNG_IT_NOISE_RDY: TRNG Noise ready interrupt enable.
 *                    TRNG_IT_DONE: TRNG Done interrupt enable.
 *                    TRNG_IT_GLBL: TRNG Global interrupt enable.
 *                  NewState: ENABLE or DISABLE.
 * Return:          None.
 */
void TRNG_ITConfig(TRNG_TypeDef *TRNGx, uint32_t ITType, EnState NewState)
{
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));
    assert_param(IS_TRNG_IT(ITType));

    /* Configure the TRNG interrupt */
    if (NewState != DISABLE)
    {
        TRNGx->IE |= ITType;
    }
    else
    {
        TRNGx->IE &= ~ITType;
    }
}

/*
 * Function:        TRNG_GetITStatus
 * Description:     Get TRNG IT status.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 *                  TRNG_IT: TRNG interrupt state.
 *                   This parameter can be one of the following values:
 *                    TRNG_IT_STATE_ZEROIZED: Zeroized interrupt state .
 *                    TRNG_IT_STATE_KAT_COMPLETE: KAT complete interrupt state.
 *                    TRNG_IT_STATE_ALARMED: Alarmed interrupt state.
 *                    TRNG_IT_STATE_NOISE_RDY: Noise ready interrupt state.
 *                    TRNG_IT_STATE_DONE: Done interrupt state.
 * Return:          TRUE or FALSE.
 */
FlagStatus TRNG_GetITStatus(TRNG_TypeDef *TRNGx, uint32_t TRNG_IT)
{
    /* Check the parameters */
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));
    assert_param(IS_TRNG_IT_STATE(TRNG_IT));

    /* Return the TRNG_IT status */
    return (FlagStatus)(TRNGx->ISTAT & TRNG_IT);
}

/*
 * Function:        TRNG_ClearITPendingBit
 * Description:     Clear TRNG interrupt pending bit.
 * Param:           TRNGx: where x can be (0) to select the TRNG peripheral.
 *                  ClearIT: TRNG interrupt pending bit.
 *                   This parameter can be one of the following values:
 *                    TRNG_STATE_CLEAR_ZEROIZED: Zeroized interrupt state clear.
 *                    TRNG_STATE_CLEAR_KAT_COMPLETE: KAT complete interrupt state clear.
 *                    TRNG_STATE_CLEAR_ALARMED: Alarmed interrupt state clear.
 *                    TRNG_STATE_CLEAR_NOISE_RDY: Noise ready interrupt state clear.
 *                    TRNG_STATE_CLEAR_DONE: Done interrupt state clear.
 * Return:          None.
 */
void TRNG_ClearITPendingBit(TRNG_TypeDef *TRNGx, uint32_t ClearIT)
{
    /* Check the parameters */
    assert_param(IS_TRNG_ALL_PERIPH(TRNGx));
    assert_param(IS_TRNG_STATE_CLEAR(ClearIT));

    /* Clear the TRNG pending bit */
    TRNGx->ISTAT |= ClearIT;
}



/*****END OF FILE*****/
