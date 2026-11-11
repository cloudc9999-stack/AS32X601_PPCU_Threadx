/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_spacc.c
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/11
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/11     1.0     build this module
 * Description:     This file provides firmware functions to manage the functionalities of the SPACC peripheral.
 */

#include "as32x601_spacc.h"
#include <stddef.h>

/*
 * Function:        SPACC_Struct
 * Description:     Initialization convert structure.
 * Param:           SPACC_Struct: convert config structure pointer.
 * Return:          None.
 */
void SPACC_Struct(SPACC_InitTypeDef * const SPACC_InitStruct)
{
    /* Reset SPACC init structure parameters values */
    SPACC_InitStruct->SPACC_CipherAlgorithm = SPACC_CIPHER_ALG_NULL;
    SPACC_InitStruct->SPACC_SM4CipherMode = SPACC_SM4_CIPHER_MODE_ECB;
    SPACC_InitStruct->SPACC_HashAlgorithm = SPACC_HASH_ALG_NULL;
    SPACC_InitStruct->SPACC_SM3HashMode = SPACC_SM3_HASH_MODE_RAW_SHAKE;
    SPACC_InitStruct->SPACC_TransferMode = SPACC_TRANS_TO_APPLY_DECRYPT;
    SPACC_InitStruct->SPACC_ContextIndex = 0;
    SPACC_InitStruct->SPACC_KeyFrom = SPACC_KEY_FROM_CTX;
    SPACC_InitStruct->SPACC_AADCopy = SPACC_APP_NOT_COPY;
    SPACC_InitStruct->SPACC_ICVCompute = SPACC_ICV_COMPUTER_PLAIN;
    SPACC_InitStruct->SPACC_ICVEncrypt = SPACC_ICV_NOT_ENCRYPT;
    SPACC_InitStruct->SPACC_ICVLocation = SPACC_ICV_LOCATION_OFFSET;
    SPACC_InitStruct->SPACC_KeyExpand = SPACC_KEY_NOT_EXPAND;
    SPACC_InitStruct->SPACC_MessageBegin = SPACC_MSG_BEGIN_NOT_FIRST;
    SPACC_InitStruct->SPACC_MessageEnd = SPACC_MSG_END_NOT_LAST;
    SPACC_InitStruct->SPACC_SoftwareID = 0;
    SPACC_InitStruct->SPACC_PriorityCommandFIFO = 0;
    SPACC_InitStruct->SPACC_KeySize = 0;
    SPACC_InitStruct->SPACC_KeyIndex = 0;
    SPACC_InitStruct->SPACC_KeyType = SPACC_KEY_TYPE_HASH;
}

/*
 * Function:        SPACC_Init
 * Description:     Initialization SPACC peripheral.
 * Param:           SPACCx: where x can be (0) to select the SPACC peripheral.
 *                  SPACC_InitStruct: SPACC config structure pointer.
 * Return:          None.
 */
void SPACC_Init(SPACC_TypeDef *SPACCx, const SPACC_InitTypeDef * const SPACC_InitStruct)
{
    uint32_t temp = 0;
  
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));
    assert_param(SPACC_InitStruct != NULL);
    assert_param(IS_SPACC_KEY_TYPE(SPACC_InitStruct->SPACC_KeyType));
    assert_param(IS_SPACC_CIPHER_ALG(SPACC_InitStruct->SPACC_CipherAlgorithm));
    assert_param(IS_SPACC_SM4_CIPHER_MODE(SPACC_InitStruct->SPACC_SM4CipherMode));
    assert_param(IS_SPACC_HASH_ALG(SPACC_InitStruct->SPACC_HashAlgorithm));
    assert_param(IS_SPACC_SM3_HASH_MODE(SPACC_InitStruct->SPACC_SM3HashMode));
    assert_param(IS_SPACC_TRANS_TO_APPLY(SPACC_InitStruct->SPACC_TransferMode));
    assert_param(IS_SPACC_KEY_FROM(SPACC_InitStruct->SPACC_KeyFrom));
    assert_param(IS_SPACC_APP_COPY(SPACC_InitStruct->SPACC_AADCopy));
    assert_param(IS_SPACC_ICV_COMPUTER(SPACC_InitStruct->SPACC_ICVCompute));
    assert_param(IS_SPACC_ICV_ENCRYPT(SPACC_InitStruct->SPACC_ICVEncrypt));
    assert_param(IS_SPACC_ICV_LOCATION(SPACC_InitStruct->SPACC_ICVLocation));
    assert_param(IS_SPACC_KEY_EXPAND(SPACC_InitStruct->SPACC_KeyExpand));
    assert_param(IS_SPACC_MSG_BEGIN(SPACC_InitStruct->SPACC_MessageBegin));
    assert_param(IS_SPACC_MSG_END(SPACC_InitStruct->SPACC_MessageEnd));

    /* Set SPACC software ID */
    SPACCx->SW_CTRL &= ~((uint32_t)SPACC_SW_CTRL_SW_ID);
    SPACCx->SW_CTRL |= (((uint32_t)SPACC_InitStruct->SPACC_SoftwareID) << SPACC_SW_CTRL_SW_ID_Pos);

    /* Set SPACC priority command FIFO */
    SPACCx->SW_CTRL &= ~((uint32_t)SPACC_SW_CTRL_PRIORITY);
    SPACCx->SW_CTRL |= (((uint32_t)SPACC_InitStruct->SPACC_PriorityCommandFIFO) << SPACC_SW_CTRL_PRIORITY_Pos);

    /* Set SPACC key size */
    SPACCx->KEY_SZ &= ~((uint32_t)SPACC_KEY_SZ_SIZE);
    SPACCx->KEY_SZ |= (((uint32_t)SPACC_InitStruct->SPACC_KeySize) << SPACC_KEY_SZ_SIZE_Pos);

    /* Set SPACC key index */
    SPACCx->KEY_SZ &= ~((uint32_t)SPACC_KEY_SZ_CTX_IDX);
    SPACCx->KEY_SZ |= (((uint32_t)SPACC_InitStruct->SPACC_KeyIndex) << SPACC_KEY_SZ_CTX_IDX_Pos);
    
    /* Set SPACC key type */
    SPACCx->KEY_SZ &= ~((uint32_t)SPACC_KEY_SZ_CIPHER);
    SPACCx->KEY_SZ |= (((uint32_t)SPACC_InitStruct->SPACC_KeyType) << SPACC_KEY_SZ_CIPHER_Pos);
    
    temp = SPACCx->CTRL;

    /* Set SPACC cipher algorithm */
    temp &= ~((uint32_t)SPACC_CTRL_SM4_CIPH_ALG);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_CipherAlgorithm) << SPACC_CTRL_SM4_CIPH_ALG_Pos);

    /* Set SPACC SM4 cipher mode */
    temp &= ~((uint32_t)SPACC_CTRL_SM4_CIPH_MODE);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_SM4CipherMode) << SPACC_CTRL_SM4_CIPH_MODE_Pos);

    /* Set SPACC hash algorithm */
    temp &= ~((uint32_t)SPACC_CTRL_SM_HASH_ALG);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_HashAlgorithm) << SPACC_CTRL_SM_HASH_ALG_Pos);

    /* Set SPACC SM3 hash mode */
    temp &= ~((uint32_t)SPACC_CTRL_SM3_HASH_MODE);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_SM3HashMode) << SPACC_CTRL_SM3_HASH_MODE_Pos);

    /* Set SPACC transfer mode */
    temp &= ~((uint32_t)SPACC_CTRL_ENCRYPT);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_TransferMode) << SPACC_CTRL_ENCRYPT_Pos);

    /* Set SPACC context index */
    temp &= ~((uint32_t)SPACC_CTRL_CTX_IDX);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_ContextIndex) << SPACC_CTRL_CTX_IDX_Pos);

    /* Set SPACC key from */
    temp &= ~((uint32_t)SPACC_CTRL_SEC_KEY);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_KeyFrom) << SPACC_CTRL_SEC_KEY_Pos);

    /* Set SPACC AAD copy */
    temp &= ~((uint32_t)SPACC_CTRL_AAD_COPY);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_AADCopy) << SPACC_CTRL_AAD_COPY_Pos);

    /* Set SPACC ICV compute */
    temp &= ~((uint32_t)SPACC_CTRL_ICV_PT);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_ICVCompute) << SPACC_CTRL_ICV_PT_Pos);

    /* Set SPACC ICV encrypt */
    temp &= ~((uint32_t)SPACC_CTRL_ICV_ENC);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_ICVEncrypt) << SPACC_CTRL_ICV_ENC_Pos);

    /* Set SPACC ICV location */
    temp &= ~((uint32_t)SPACC_CTRL_ICV_APPEND);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_ICVLocation) << SPACC_CTRL_ICV_APPEND_Pos);

    /* Set SPACC key expand */
    temp &= ~((uint32_t)SPACC_CTRL_KEY_EXP);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_KeyExpand) << SPACC_CTRL_KEY_EXP_Pos);

    /* Set SPACC message begin */
    temp &= ~((uint32_t)SPACC_CTRL_MSG_BEGIN);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_MessageBegin) << SPACC_CTRL_MSG_BEGIN_Pos);

    /* Set SPACC message end */
    temp &= ~((uint32_t)SPACC_CTRL_MSG_END);
    temp |= (((uint32_t)SPACC_InitStruct->SPACC_MessageEnd) << SPACC_CTRL_MSG_END_Pos);
    
    SPACCx->CTRL = temp;
}

/*
 * Function:        SPACC_PacketInit
 * Description:     Initialization SPACC packet structure.
 * Param:           SPACCx: where x can be (0) to select the SPACC peripheral.
 *                  SPACC_PacketStruct: SPACC packet config structure pointer.
 * Return:          None.
 */
void SPACC_PacketInit(SPACC_TypeDef *SPACCx, const SPACC_PacketTypeDef * const SPACC_PacketStruct)
{
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));

    /* Pointer to source packet data structure in system memory */
    SPACCx->SRC_PTR &= ~((uint32_t)SPACC_SRC_PTR_PTR);
    SPACCx->SRC_PTR |= (((uint32_t)SPACC_PacketStruct->SPACC_SourcePtr) );

    /* Pointer to destination packet data structure in system memory */
    SPACCx->DST_PTR &= ~((uint32_t)SPACC_DST_PTR_PTR);
    SPACCx->DST_PTR |= (((uint32_t)SPACC_PacketStruct->SPACC_DestinationPtr));

    /* Source buffer offset */
    SPACCx->OFFSET &= ~((uint32_t)SPACC_OFFSET_SRC);
    SPACCx->OFFSET |= (((uint32_t)SPACC_PacketStruct->SPACC_SouPREAADOffset) << SPACC_OFFSET_SRC_Pos);

    /* Destination buffer offset */
    SPACCx->OFFSET &= ~((uint32_t)SPACC_OFFSET_DST);
    SPACCx->OFFSET |= (((uint32_t)SPACC_PacketStruct->SPACC_DestPREAADOffset) << SPACC_OFFSET_DST_Pos);

    /* Byte length of the prefixed AAD */
    SPACCx->PRE_AAD_LEN &= ~((uint32_t)SPACC_PRE_AAD_LEN_LEN);
    SPACCx->PRE_AAD_LEN |= (((uint32_t)SPACC_PacketStruct->SPACC_PREAADLen) << SPACC_PRE_AAD_LEN_LEN_Pos);

    /* Byte length of the postfix AAD */
    SPACCx->POST_AAD_LEN &= ~((uint32_t)SPACC_POST_AAD_LEN_LEN);
    SPACCx->POST_AAD_LEN |= (((uint32_t)SPACC_PacketStruct->SPACC_POSTAADLen) << SPACC_POST_AAD_LEN_LEN_Pos);

    /* Total packet byte length for processing, including PRE_AAD_LEN and payload */
    SPACCx->PROC_LEN &= ~((uint32_t)SPACC_PROC_LEN_LEN);
    SPACCx->PROC_LEN |= (((uint32_t)SPACC_PacketStruct->SPACC_PROCLen) << SPACC_PROC_LEN_LEN_Pos);

    /* Byte length of the ICV */
    SPACCx->ICV_LEN &= ~((uint32_t)SPACC_ICV_LEN_LEN);
    SPACCx->ICV_LEN |= (((uint32_t)SPACC_PacketStruct->SPACC_ICVLen) << SPACC_ICV_LEN_LEN_Pos);

    /* Byte offset in packet data structure to start of ICV */
    SPACCx->ICV_OFFSET &= ~((uint32_t)SPACC_ICV_OFFSET_OFFSET);
    SPACCx->ICV_OFFSET |= (((uint32_t)SPACC_PacketStruct->SPACC_ICVOffset) << SPACC_ICV_OFFSET_OFFSET_Pos);

    /* Byte offset in source buffer to obtain the IV value */
    SPACCx->IV_OFFSET &= ~((uint32_t)SPACC_IV_OFFSET_OFFSET);
    SPACCx->IV_OFFSET |= (((uint32_t)SPACC_PacketStruct->SPACC_IVOffset) << SPACC_IV_OFFSET_OFFSET_Pos);

    /* Controls the location of the IV value */
    SPACCx->IV_OFFSET &= ~((uint32_t)SPACC_IV_OFFSET_ENABLE);
    SPACCx->IV_OFFSET |= (((uint32_t)SPACC_PacketStruct->SPACC_IVLocation) << SPACC_IV_OFFSET_ENABLE_Pos);
}

/*
 * Function:        SPACC_ITConfig
 * Description:     Enable or disable the SPACC interrupt.
 * Param:           SPACCx: where x can be (0) to select the TRNG peripheral.
 *                  ITType: SPACC interrupt type.
 *                   This parameter can be one of the following values:
 *                    SPACC_IT_CMDO: Command FIFO priority 0 interrupt enable.
 *                    SPACC_IT_CMD1: Command FIFO priority 1 interrupt enable.
 *                    SPACC_IT_CMD2: Command FIFO priority 2 interrupt enable.
 *                    SPACC_IT_STAT: Status FIFO interrupt enable.   
 *                    SPACC_IT_RC4_DMA: RC4 context DMA interrupt enable.
 *                    SPACC_IT_STAT_WD: Status watchdog interrupt enable.
 *                    SPACC_IT_GLBL: Global interrupt enable.
 *                  NewState: ENABLE or DISABLE.
 * Return:          None.
 */
void SPACC_ITConfig(SPACC_TypeDef *SPACCx, uint32_t ITType, EnState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));
    assert_param(IS_SPACC_IT(ITType));

    /* Configure the SPACC interrupt */
    if (NewState != DISABLE)
    {
        SPACCx->IRQ_EN |= ITType;
    }
    else
    {
        SPACCx->IRQ_EN &= ~ITType;
    }
}

/*
 * Function:        SPACC_GetITStatus
 * Description:     Get the SPACC interrupt status.
 * Param:           SPACCx: where x can be (0) to select the SPACC peripheral.
 *                  SPACC_IT: SPACC interrupt type.
 *                   This parameter can be one of the following values:
 *                    SPACC_IT_CMDO: Command FIFO priority 0 interrupt enable.
 *                    SPACC_IT_CMD1: Command FIFO priority 1 interrupt enable.
 *                    SPACC_IT_CMD2: Command FIFO priority 2 interrupt enable.
 *                    SPACC_IT_STAT: Status FIFO interrupt enable.   
 *                    SPACC_IT_RC4_DMA: RC4 context DMA interrupt enable.
 *                    SPACC_IT_STAT_WD: Status watchdog interrupt enable.
 * Return:          The new state of SPACC_IT (SET or RESET).
 * Note:            None.
 */
FlagStatus SPACC_GetITStatus(SPACC_TypeDef *SPACCx, uint32_t SPACC_IT)
{
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));
    assert_param(IS_SPACC_IT_STATE(SPACC_IT));

    /* Return the SPACC_IT status */
    return (FlagStatus)(SPACCx->IRQ_STAT & SPACC_IT);
}

/*
 * Function:        SPACC_CommandExecResult
 * Description:     Get the result of the command execution.
 * Param:           SPACCx: where x can be (0) to select the SPACC peripheral.
 *                  SoftwareID: Software ID of the command.
 * Return:          SET or RESET.
 * Note:            None.
 */
FlagStatus SPACC_CommandExecResult(SPACC_TypeDef *SPACCx, uint32_t SoftwareID)
{
    uint32_t temp = 0;
    
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));
    
    /* The STATUS status is ejected by writing the STAT_POP register */
    SPACCx->STAT_POP = 1;

    temp = (SPACCx->STATUS & SPACC_STATUS_SW_ID) >> SPACC_STATUS_SW_ID_Pos;

    if(temp == SoftwareID)
    {
        return SET;
    }
    return RESET;
}

/*
 * Function:        SPACC_StateFIFOFlag
 * Description:     Get the state of the state FIFO.
 * Param:           SPACCx: where x can be (0) to select the SPACC peripheral.
 * Return:          SET or RESET.
 * Note:            None.
 */
FlagStatus SPACC_StateFIFOFlag(SPACC_TypeDef *SPACCx)
{
    /* Check the parameters */
    assert_param(IS_SPACC_ALL_PERIPH(SPACCx));
    
    return (FlagStatus)((SPACCx->FIFO_STAT & SPACC_FIFO_STAT_STAT_EMPTY) >> SPACC_FIFO_STAT_STAT_EMPTY_Pos);
}

/*****END OF FILE*****/
