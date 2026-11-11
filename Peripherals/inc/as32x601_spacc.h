/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_spacc.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/6
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/6      1.0     build this module
 * Description:     This file contains all the functions prototypes for the spacc firmware library.
 */
#ifndef AS32X601_SPACC_H
#define AS32X601_SPACC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601_spacc_regs.h"

/*
 * @brief  Use by parameter examine.
 */
#define IS_SPACC_ALL_PERIPH(PERIPH) (((PERIPH) == SPACC))

/*
 * @brief SPACC context address
 */
#define SPACC_CIPHER_CONTEXT_BASE                   (uint32_t)(SPACC_BASE + 0x4000)
#define SPACC_HASH_CONTEXT_BASE                     (uint32_t)(SPACC + 0x8000)

/*
 * @brief SPACC Init Structure definition
 */
typedef struct 
{
    uint32_t SPACC_CipherAlgorithm;                 /* Cipher algorithm selection */
    uint32_t SPACC_SM4CipherMode;                   /* SM4 cipher mode selection */
    uint32_t SPACC_HashAlgorithm;                   /* Hash algorithm selection */
    uint32_t SPACC_SM3HashMode;                     /* SM3 hash mode selection */
    uint32_t SPACC_TransferMode;                    /* Transfer mode selection, encryption or decryption */
    uint32_t SPACC_ContextIndex;                    /* Context index selection */
    uint32_t SPACC_KeyFrom;                         /* Key source selection, context or SKP */
    uint32_t SPACC_AADCopy;                         /* Whether to copy PRE_AAD to the target buffer */
    uint32_t SPACC_ICVCompute;                      /* ICV Compute method */
    uint32_t SPACC_ICVEncrypt;                      /* Whether the ICV is encrypted */
    uint32_t SPACC_ICVLocation;                     /* ICV Location selection */
    uint32_t SPACC_KeyExpand;                       /* Key expand selection */
    uint32_t SPACC_MessageBegin;                    /* Begin flag for partial packet processing, first or not */
    uint32_t SPACC_MessageEnd;                      /* End flag for partial packet processing, last or not */
    uint32_t SPACC_SoftwareID;                      /* Software ID */
    uint32_t SPACC_PriorityCommandFIFO;             /* Priority command FIFO selection */
    uint32_t SPACC_KeySize;                         /* Key size selection */
    uint32_t SPACC_KeyIndex;                        /* Key index selection */
    uint32_t SPACC_KeyType;                         /* Key type selection */
}SPACC_InitTypeDef;

/*
 * @brief Packet format in memory
 */
typedef struct 
{
    uint32_t SPACC_SourcePtr;                       /* Pointer to source packet data structure in system memory */
    uint32_t SPACC_DestinationPtr;                  /* Pointer to destination packet data structure in system memory */
    uint32_t SPACC_SouPREAADOffset;                 /* Source Packet define offsets within the packet data structure to the start of PRE-AAD */
    uint32_t SPACC_DestPREAADOffset;                /* Destination Packet define offsets within the packet data structure to the start of PRE-AAD */
    uint32_t SPACC_PREAADLen;                       /* PRE-AAD length in bytes */
    uint32_t SPACC_POSTAADLen;                      /* POST-AAD length in bytes */
    uint32_t SPACC_PROCLen;                         /* Processing length in bytes */
    uint32_t SPACC_ICVLen;                          /* ICV length in bytes */
    uint32_t SPACC_ICVOffset;                       /* ICV offset in bytes */
    uint32_t SPACC_IVOffset;                        /* IV offset in bytes */
    uint32_t SPACC_IVLocation;                      /* Controls the location of the IV value, context or source */
}SPACC_PacketTypeDef;

/**
 * @brief SPACC Status Register Parameter definition
 */
typedef struct 
{
    uint32_t SPACC_Status_SoftwareID    :8;         /* Software ID */
    uint32_t SPACC_Status_Reservend0    :16;        /* Reserved */
    uint32_t SPACC_Status_Result        :3;         /* Result of the operation */
    uint32_t SPACC_Status_Reservend1    :4;         /* Reserved */
    uint32_t SPACC_Status_CommandMode   :1;         /* Command mode */
}SPACC_StatusTypedef;


/*
 * @brief SPACC Cipher Algorithm selection
 */
#define SPACC_CIPHER_ALG_NULL                       ((uint32_t)0x00000000)          /* NULL Algorithm is selected */
#define SPACC_CIPHER_ALG_DES                        ((uint32_t)0x00000001)          /* DES Algorithm is selected */
#define SPACC_CIPHER_ALG_AES                        ((uint32_t)0x00000002)          /* AES Algorithm is selected */
#define SPACC_CIPHER_ALG_RC4                        ((uint32_t)0x00000003)          /* RC4 Algorithm is selected */
#define SPACC_CIPHER_ALG_MULTI2                     ((uint32_t)0x00000004)          /* MULTI2 Algorithm is selected */
#define SPACC_CIPHER_ALG_KASUMI                     ((uint32_t)0x00000005)          /* KASUMI Algorithm is selected */
#define SPACC_CIPHER_ALG_SNOW_3G_UEA2               ((uint32_t)0x00000006)          /* SNOW-3G UEA2 Algorithm is selected */
#define SPACC_CIPHER_ALG_ZUC_128_EE3                ((uint32_t)0x00000007)          /* ZUC-128-EE3 Algorithm is selected */
#define SPACC_CIPHER_ALG_CHACHA20                   ((uint32_t)0x00000008)          /* CHACHA20 Algorithm is selected */
#define SPACC_CIPHER_ALG_SM4                        ((uint32_t)0x00000009)          /* SM4 Algorithm is selected */
#define IS_SPACC_CIPHER_ALG(ALG)                    (((ALG) == SPACC_CIPHER_ALG_NULL) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_DES) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_AES) || \
                                                     ((ALG) ==SPACC_CIPHER_ALG_RC4) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_MULTI2) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_KASUMI) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_SNOW_3G_UEA2) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_ZUC_128_EE3) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_CHACHA20) || \
                                                     ((ALG) == SPACC_CIPHER_ALG_SM4))

/*
 * @brief SPACC SM4 Cipher Mode selection
 */
#define SPACC_SM4_CIPHER_MODE_ECB                   ((uint32_t)0x00000000)          /* ECB Mode is selected */
#define SPACC_SM4_CIPHER_MODE_CBC                   ((uint32_t)0x00000001)          /* CBC Mode is selected */
#define SPACC_SM4_CIPHER_MODE_CTR_STREAM            ((uint32_t)0x00000002)          /* CTR_STREAM Mode is selected */
#define SPACC_SM4_CIPHER_MODE_CCM                   ((uint32_t)0x00000003)          /* CCM Mode is selected */
#define SPACC_SM4_CIPHER_MODE_GCM_AEAD              ((uint32_t)0x00000005)          /* GCM_AEAD Mode is selected */
#define SPACC_SM4_CIPHER_MODE_OFB                   ((uint32_t)0x00000007)          /* OFB Mode is selected */
#define SPACC_SM4_CIPHER_MODE_CFB                   ((uint32_t)0x00000008)          /* CFB Mode is selected */
#define SPACC_SM4_CIPHER_MODE_F8                    ((uint32_t)0x00000009)          /* F8 Mode is selected */
#define SPACC_SM4_CIPHER_MODE_XTS                   ((uint32_t)0x0000000A)          /* XTS Mode is selected */
#define IS_SPACC_SM4_CIPHER_MODE(MODE)              (((MODE) == SPACC_SM4_CIPHER_MODE_ECB) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_CBC) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_CTR_STREAM) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_CCM) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_GCM_AEAD) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_OFB) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_CFB) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_F8) || \
                                                     ((MODE) == SPACC_SM4_CIPHER_MODE_XTS))

/*
 * @brief SPACC Hash Algorithm selection
 */
#define SPACC_HASH_ALG_NULL                         ((uint32_t)0x00000000)          /* NULL Algorithm is selected */
#define SPACC_HASH_ALG_MD5                          ((uint32_t)0x00000001)          /* MD5 Algorithm is selected */
#define SPACC_HASH_ALG_SHA1                         ((uint32_t)0x00000002)          /* SHA1 Algorithm is selected */
#define SPACC_HASH_ALG_SHA224                       ((uint32_t)0x00000003)          /* SHA224 Algorithm is selected */
#define SPACC_HASH_ALG_SHA256                       ((uint32_t)0x00000004)          /* SHA256 Algorithm is selected */
#define SPACC_HASH_ALG_SHA384                       ((uint32_t)0x00000005)          /* SHA384 Algorithm is selected */
#define SPACC_HASH_ALG_SHA512                       ((uint32_t)0x00000006)          /* SHA512 Algorithm is selected */
#define SPACC_HASH_ALG_AES_XCBC_MAC                 ((uint32_t)0x00000007)          /* AES_XCBC_MAC Algorithm is selected */  
#define SPACC_HASH_ALG_AES_CMAC                     ((uint32_t)0x00000008)          /* AES_CMAC Algorithm is selected */
#define SPACC_HASH_ALG_KASUMI_F9                    ((uint32_t)0x00000009)          /* KASUMI_F9 Algorithm is selected */
#define SPACC_HASH_ALG_SNOW_3G_UIA2                 ((uint32_t)0x0000000A)          /* SNOW-3G_UIA2 Algorithm is selected */
#define SPACC_HASH_ALG_CRC_32_IEEE_802_3            ((uint32_t)0x0000000B)          /* CRC_32_IEEE_802_3 Algorithm is selected */
#define SPACC_HASH_ALG_ZUC_128_EIA3                 ((uint32_t)0x0000000C)          /* ZUC_128_EIA3 Algorithm is selected */
#define SPACC_HASH_ALG_SHA_512_224                  ((uint32_t)0x0000000D)          /* SHA_512_224 Algorithm is selected */
#define SPACC_HASH_ALG_SHA_512_256                  ((uint32_t)0x0000000E)          /* SHA_512_256 Algorithm is selected */
#define SPACC_HASH_ALG_MICHAEL                      ((uint32_t)0x0000000F)          /* MICHAEL Algorithm is selected */
#define SPACC_HASH_ALG_SHA3_224                     ((uint32_t)0x00000010)          /* SHA3_224 Algorithm is selected */
#define SPACC_HASH_ALG_SHA3_256                     ((uint32_t)0x00000011)          /* SHA3_256 Algorithm is selected */
#define SPACC_HASH_ALG_SHA3_384                     ((uint32_t)0x00000012)          /* SHA3_384 Algorithm is selected */
#define SPACC_HASH_ALG_SHA3_512                     ((uint32_t)0x00000013)          /* SHA3_512 Algorithm is selected */
#define SPACC_HASH_ALG_SHAKE128                     ((uint32_t)0x00000014)          /* SHAKE128 Algorithm is selected */
#define SPACC_HASH_ALG_SHAKE256                     ((uint32_t)0x00000015)          /* SHAKE256 Algorithm is selected */
#define SPACC_HASH_ALG_POIY305                      ((uint32_t)0x00000016)          /* POIY305 Algorithm is selected */
#define SPACC_HASH_ALG_SM3                          ((uint32_t)0x00000017)          /* SM3 Algorithm is selected */
#define SPACC_HASH_ALG_SM4_XCBC_MAC                 ((uint32_t)0x00000018)          /* SM4_XCBC_MAC Algorithm is selected */
#define SPACC_HASH_ALG_SM4_CMAC                     ((uint32_t)0x00000019)          /* SM4_CMAC Algorithm is selected */
#define IS_SPACC_HASH_ALG(ALG)                      (((ALG) == SPACC_HASH_ALG_NULL) || ((ALG) == SPACC_HASH_ALG_MD5) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA1) || ((ALG) == SPACC_HASH_ALG_SHA224) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA256) || ((ALG) == SPACC_HASH_ALG_SHA384) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA512) || ((ALG) == SPACC_HASH_ALG_AES_XCBC_MAC) || \
                                                     ((ALG) == SPACC_HASH_ALG_AES_CMAC) || ((ALG) == SPACC_HASH_ALG_KASUMI_F9) || \
                                                     ((ALG) == SPACC_HASH_ALG_SNOW_3G_UIA2) || ((ALG) == SPACC_HASH_ALG_CRC_32_IEEE_802_3) || \
                                                     ((ALG) == SPACC_HASH_ALG_ZUC_128_EIA3) || ((ALG) ==SPACC_HASH_ALG_SHA_512_224) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA_512_256) || ((ALG) ==SPACC_HASH_ALG_MICHAEL) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA3_224) || ((ALG) == SPACC_HASH_ALG_SHA3_256) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHA3_384) || ((ALG) == SPACC_HASH_ALG_SHA3_512) || \
                                                     ((ALG) == SPACC_HASH_ALG_SHAKE128) || ((ALG) == SPACC_HASH_ALG_SHAKE256) || \
                                                     ((ALG) == SPACC_HASH_ALG_POIY305) || ((ALG) == SPACC_HASH_ALG_SM3) || \
                                                     ((ALG) == SPACC_HASH_ALG_SM4_XCBC_MAC) || ((ALG) == SPACC_HASH_ALG_SM4_CMAC))
                                                     
/*
 * @brief SPACC SM3 Hash Mode selection
 */
#define SPACC_SM3_HASH_MODE_RAW_SHAKE               ((uint32_t)0x00000000)          /* RAW_SHAKE mode is selected */
#define SPACC_SM3_HASH_MODE_SSLMAC_CSHAKE           ((uint32_t)0x00000001)          /* SSLMAC_CSHAKE mode is selected */
#define SPACC_SM3_HASH_MODE_HMAC_KMAC               ((uint32_t)0x00000002)          /* HMAC_KMAC mode is selected */
#define IS_SPACC_SM3_HASH_MODE(MODE)                (((MODE) == SPACC_SM3_HASH_MODE_RAW_SHAKE) || \
                                                     ((MODE) == SPACC_SM3_HASH_MODE_SSLMAC_CSHAKE) || \
                                                     ((MODE) == SPACC_SM3_HASH_MODE_HMAC_KMAC))

/*
 * @brief SPACC Transform To Apply selection
 */
#define SPACC_TRANS_TO_APPLY_DECRYPT                ((uint32_t)0x00000000)          /* Decrypt mode is selected */
#define SPACC_TRANS_TO_APPLY_ENCRYPT                ((uint32_t)0x00000001)          /* Encrypt mode is selected */
#define IS_SPACC_TRANS_TO_APPLY(MODE)               (((MODE) == SPACC_TRANS_TO_APPLY_DECRYPT) || \
                                                     ((MODE) == SPACC_TRANS_TO_APPLY_ENCRYPT))

/*
 * @brief SPACC Key From selection
 */
#define SPACC_KEY_FROM_CTX                          ((uint32_t)0x00000000)          /* Use cipher key from context */
#define SPACC_KEY_FROM_SKP                          ((uint32_t)0x00000001)          /* Use cipher key from SKP */
#define IS_SPACC_KEY_FROM(FROM)                     (((FROM) == SPACC_KEY_FROM_CTX) || \
                                                     ((FROM) == SPACC_KEY_FROM_SKP))

/*
 * @brief SPACC Copy the PRE_AAD to the destination buffer selection
 */
#define SPACC_APP_NOT_COPY                          ((uint32_t)0x00000000)          /* Do not copy the PRE_AAD to the destination buffer */
#define SPACC_APP_COPY                              ((uint32_t)0x00000001)          /* Copy the PRE_AAD to the destination buffer */
#define IS_SPACC_APP_COPY(COPY)                     (((COPY) == SPACC_APP_NOT_COPY) || \
                                                     ((COPY) == SPACC_APP_COPY))

/*
 * @brief SPACC ICV Computer selection
 */
#define SPACC_ICV_COMPUTER_PLAIN                    ((uint32_t)0x00000000)          /* ICV is computed over the plaintext */
#define SPACC_ICV_COMPUTER_CIPHER                   ((uint32_t)0x00000001)          /* ICV is computed over the ciphertext */
#define IS_SPACC_ICV_COMPUTER(COMPUTER)             (((COMPUTER) == SPACC_ICV_COMPUTER_PLAIN) || \
                                                     ((COMPUTER) == SPACC_ICV_COMPUTER_CIPHER))

/*
 * @brief SPACC ICV Encrypt selection
 */
#define SPACC_ICV_NOT_ENCRYPT                       ((uint32_t)0x00000000)          /* ICV is not encrypted */
#define SPACC_ICV_ENCRYPT                           ((uint32_t)0x00000001)          /* ICV is encrypted */
#define IS_SPACC_ICV_ENCRYPT(ENCRYPT)               (((ENCRYPT) == SPACC_ICV_NOT_ENCRYPT) || \
                                                     ((ENCRYPT) == SPACC_ICV_ENCRYPT))

/*
 * @brief SPACC ICV Location selection
 */
#define SPACC_ICV_LOCATION_OFFSET                   ((uint32_t)0x00000000)          /* ICV location indicated by ICV OFFSET */
#define SPACC_ICV_LOCATION_APPEND                   ((uint32_t)0x00000001)          /* ICV located at end of packet */
#define IS_SPACC_ICV_LOCATION(LOCATION)             (((LOCATION) == SPACC_ICV_LOCATION_OFFSET) || \
                                                     ((LOCATION) == SPACC_ICV_LOCATION_APPEND))

/*
 * @brief SPACC KEY Expand selection
 */
#define SPACC_KEY_NOT_EXPAND                        ((uint32_t)0x00000000)          /* Do not expand the key */
#define SPACC_KEY_EXPAND                            ((uint32_t)0x00000001)          /* Expand the key */
#define IS_SPACC_KEY_EXPAND(EXPAND)                 (((EXPAND) == SPACC_KEY_NOT_EXPAND) || \
                                                     ((EXPAND) == SPACC_KEY_EXPAND))

/*
 * @brief SPACC Message Begin selection
 */
#define SPACC_MSG_BEGIN_NOT_FIRST                   ((uint32_t)0x00000000)          /* Subsequent segment of packet */
#define SPACC_MSG_BEGIN_FIRST                       ((uint32_t)0x00000001)          /* First segment of packet */
#define IS_SPACC_MSG_BEGIN(BEGIN)                   (((BEGIN) == SPACC_MSG_BEGIN_NOT_FIRST) || \
                                                     ((BEGIN) == SPACC_MSG_BEGIN_FIRST))

/*
 * @brief SPACC Message End selection
 */                                            
#define SPACC_MSG_END_NOT_LAST                       ((uint32_t)0x00000000)         /* Non-last segment of packet */
#define SPACC_MSG_END_LAST                           ((uint32_t)0x00000001)         /* Last segment of packet */
#define IS_SPACC_MSG_END(END)                        (((END) == SPACC_MSG_END_NOT_LAST) || \
                                                     ((END) == SPACC_MSG_END_LAST))

/*
 * @brief SPACC IV Location selection
 */
#define SPACC_IV_LOCATION_CONTEST                   ((uint32_t)0x00000000)          /* The IV value is fetched from the context age. */
#define SPACC_IV_LOCATION_SOURCE                    ((uint32_t)0x00000001)          /* The IV value is fetched from the source buffer. */
#define IS_SPACC_IV_LOCATION(LOCATION)              (((LOCATION) == SPACC_IV_LOCATION_CONTEST) || \
                                                     ((LOCATION) == SPACC_IV_LOCATION_SOURCE))

/*
 * @brief SPACC Key Type selection
 */
#define SPACC_KEY_TYPE_HASH                         ((uint32_t)0x00000000)          /* Hash Key */
#define SPACC_KEY_TYPE_CIPHER                       ((uint32_t)0x00000001)          /* Cipher Key */
#define IS_SPACC_KEY_TYPE(TYPE)                     (((TYPE) == SPACC_KEY_TYPE_HASH) || \
                                                     ((TYPE) == SPACC_KEY_TYPE_CIPHER))

/*
 * @brief SPACC Interrupt Enable selection
 */ 
#define SPACC_IT_CMDO                               SPACC_IRQ_EN_CMD0_EN            /* Command FIFO priority 0 interrupt enable */
#define SPACC_IT_CMD1                               SPACC_IRQ_EN_CMD1_EN            /* Command FIFO priority 1 interrupt enable */
#define SPACC_IT_CMD2                               SPACC_IRQ_EN_CMD2_EN            /* Command FIFO priority 2 interrupt enable */
#define SPACC_IT_STAT                               SPACC_IRQ_EN_STAT_EN            /* Status FIFO interrupt enable */
#define SPACC_IT_RC4_DMA                            SPACC_IRQ_EN_RC4_DMA_EN         /* RC4 context DMA interrupt enable */
#define SPACC_IT_STAT_WD                            SPACC_IRQ_EN_STAT_WD_EN         /* Status watchdog interrupt enable */
#define SPACC_IT_GLBL                               SPACC_IRQ_EN_GLBL_EN            /* Global interrupt enable */
#define IS_SPACC_IT(IT)                             (((IT) == SPACC_IT_CMDO) || \
                                                     ((IT) == SPACC_IT_CMD1) || \
                                                     ((IT) == SPACC_IT_CMD2) || \
                                                     ((IT) == SPACC_IT_STAT) || \
                                                     ((IT)== SPACC_IT_RC4_DMA) || \
                                                     ((IT) == SPACC_IT_STAT_WD) || \
                                                     ((IT) == SPACC_IT_GLBL))

/*
 * @brief SPACC Interrupt State selection
 */
#define SPACC_IT_STATE_CMDO                         SPACC_IRQ_STAT_CMD0             /* Command FIFO priority 0 interrupt state */
#define SPACC_IT_STATE_CMD1                         SPACC_IRQ_STAT_CMD1             /* Command FIFO priority 1 interrupt state */
#define SPACC_IT_STATE_CMD2                         SPACC_IRQ_STAT_CMD2             /* Command FIFO priority 2 interrupt state */
#define SPACC_IT_STATE_STAT                         SPACC_IRQ_STAT_STAT             /* Status FIFO interrupt state */
#define SPACC_IT_STATE_RC4_DMA                      SPACC_IRQ_STAT_RC4_DMA          /* RC4 context DMA interrupt state */
#define SPACC_IT_STATE_STAT_WD                      SPACC_IRQ_STAT_STAT_WD          /* Status watchdog interrupt state */
#define IS_SPACC_IT_STATE(STATE)                    (((STATE) == SPACC_IT_STATE_CMDO) || \
                                                     ((STATE) == SPACC_IT_STATE_CMD1) || \
                                                     ((STATE) == SPACC_IT_STATE_CMD2) || \
                                                     ((STATE) == SPACC_IT_STATE_STAT) || \
                                                     ((STATE) == SPACC_IT_STATE_RC4_DMA) || \
                                                     ((STATE) == SPACC_IT_STATE_STAT_WD))

/*
 * @brief Function declaration
 */
void SPACC_Struct(SPACC_InitTypeDef * const SPACC_InitStruct);
void SPACC_Init(SPACC_TypeDef *SPACCx, const SPACC_InitTypeDef * const SPACC_InitStruct);
void SPACC_PacketInit(SPACC_TypeDef *SPACCx, const SPACC_PacketTypeDef * const SPACC_PacketStruct);
void SPACC_ITConfig(SPACC_TypeDef *SPACCx, uint32_t ITType, EnState NewState);
FlagStatus SPACC_GetITStatus(SPACC_TypeDef *SPACCx, uint32_t SPACC_IT);
FlagStatus SPACC_CommandExecResult(SPACC_TypeDef *SPACCx, uint32_t SoftwareID);
FlagStatus SPACC_StateFIFOFlag(SPACC_TypeDef *SPACCx);

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
