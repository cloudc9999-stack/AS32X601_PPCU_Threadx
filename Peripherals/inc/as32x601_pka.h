/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_pka.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/29
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/29     1.0     build this module
 * Description:     This file contains all the functions prototypes for the pka firmware library.
 */
#ifndef AS32X601_PKA_H
#define AS32X601_PKA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601_pka_regs.h"

/*
 * @brief  Use by parameter examine.
 */
#define IS_PKA_ALL_PERIPH(PERIPH) (((PERIPH) == PKA))

/*
 * @brief PKA Init Structure definition
 */
typedef struct 
{
    uint32_t PKA_PartialRadix;                      /* Selects a partial field from within the base radix */
    uint32_t PKA_BaseRadix;                         /* Sets the size of the base operand size (radix) */
    uint32_t PKA_M521Mode;                          /* Sets operating to Mersenne M-521 */
    uint32_t PKA_StopRqst;                          /* Requests PKA to halt at the next instruction boundary */
    uint32_t PKA_Go;                                /* Starts the PKA operation */
    uint32_t PKA_AltAccess;                         /* C-memory access */
    uint32_t PKA_EndianSwap;                        /* Enable or disable the endian swap */
}PKA_InitTypeDef;

/**
 * @brief PKA Stop Reason Enumeration
 */
typedef enum
{
	NORMAL_STOP					= 0x00,
	INVALID_OP_CODE				= 0x01,
	STACK_UNDERFLOW				= 0x02,
	STACK_OVERFLOW				= 0x03,
	WATCHDOG 					= 0x04,
	HOST_REQUEST 				= 0x05,
	MEMORY_PORT_COLLISION 		= 0x08,	
}PKA_StopReasonEnum;

/*
 * @brief PKA Base Radix selection
 */
#define PKA_BASE_RADIX_256                          ((uint32_t)0x00000002)          /* 256-bit */
#define PKA_BASE_RADIX_512                          ((uint32_t)0x00000003)          /* 512-bit */
#define PKA_BASE_RADIX_1024                         ((uint32_t)0x00000004)          /* 1024-bit */
#define PKA_BASE_RADIX_2048                         ((uint32_t)0x00000005)          /* 2048-bit */
#define PKA_BASE_RADIX_4096                         ((uint32_t)0x00000006)          /* 4096-bit */
#define IS_PKA_BASE_RADIX(RADIX)                    (((RADIX) == PKA_BASE_RADIX_256) || \
                                                     ((RADIX) == PKA_BASE_RADIX_512) || \
                                                     ((RADIX) == PKA_BASE_RADIX_1024) || \
                                                     ((RADIX) == PKA_BASE_RADIX_2048) || \
                                                     ((RADIX) == PKA_BASE_RADIX_4096))

/*
 * @brief PKA Stop Rqst selection
 */
#define PKA_STOP_RQST_DIS                           ((uint32_t)0x00000000)          /* Stop request is disabled */
#define PKA_STOP_RQST_EN                            ((uint32_t)0x00000001)          /* Stop request is enabled */
#define IS_PKA_STOP_RQST(RQST)                      (((RQST) == PKA_STOP_RQST_DIS) || \
                                                     ((RQST) == PKA_STOP_RQST_EN))

/*
 * @brief PKA Go selection
 */
#define PKA_GO_DIS                                  ((uint32_t)0x00000000)          /* Go is disabled */
#define PKA_GO_EN                                   ((uint32_t)0x00000001)          /* Go is enabled */
#define IS_PKA_GO(GO)                               (((GO) == PKA_GO_DIS) || \
                                                     ((GO) == PKA_GO_EN))

/*
 * @brief PKA Alt Access selection
 */
#define PKA_ALT_ACCESS_NORMAL                       ((uint32_t)0x00000000)          /* Normal C-memory access */
#define PKA_ALT_ACCESS_DPA                          ((uint32_t)0x00000001)          /* Switch the C-memory read/write-access slot to the DPA shadow memory */
#define IS_PKA_ALT_ACCESS(ACCESS)                   (((ACCESS) == PKA_ALT_ACCESS_NORMAL) || \
                                                     ((ACCESS) == PKA_ALT_ACCESS_DPA))        

/*
 * @brief PKA Endian Swap selection
 */
#define PKA_ENDIAN_SWAP_LITTLE                      ((uint32_t)0x00000000)          /* Little-endian */
#define PKA_ENDIAN_SWAP_BIG                         ((uint32_t)0x00000001)          /* Big-endian */
#define IS_PKA_ENDIAN_SWAP(SWAP)                    (((SWAP) == PKA_ENDIAN_SWAP_LITTLE) || \
                                                     ((SWAP) == PKA_ENDIAN_SWAP_BIG))

/**
 * @brief PKA State
 */
#define PKA_STATE_SIF_ERR                           PKA_STAT_SIF_ERR                /* Indicates that an SIF error has occurred */
#define PKA_STATE_SIF_SBE                           PKA_STAT_SIF_SBE                /* Indicates that an SIF single bit error has occurred */
#define PKA_STATE_DONE                              PKA_STAT_DONE                   /* Indicates that the operation has completed */
#define IS_PKA_IT_STATE(STATE)                      (((STATE) == PKA_STATE_SIF_ERR) || \
                                                     ((STATE) == PKA_STATE_SIF_SBE) || \
                                                     ((STATE) == PKA_STATE_DONE))

/**
 * @brief PKA Flags
 */
#define PKA_FLAG_ZERO                               PKA_FLAGS_Z                     /* Zero flag */
#define PKA_FLAG_MEMORYTEST                         PKA_FLAGS_M                     /* Memory-test flag */
#define PKA_FLAG_BORROW                             PKA_FLAGS_B                     /* Borrow flag */
#define PKA_FLAG_CARRY                              PKA_FLAGS_C                     /* Carry flag */
#define PKA_FLAG_USERFLAG0                          PKA_FLAGS_F0                    /* User flag 0 */
#define PKA_FLAG_USERFLAG1                          PKA_FLAGS_F1                    /* User flag 1 */
#define PKA_FLAG_USERFLAG2                          PKA_FLAGS_F2                    /* User flag 2 */
#define PKA_FLAG_USERFLAG3                          PKA_FLAGS_F3                    /* User flag 3 */
#define IS_PKA_FLAG(FLAG)                           (((FLAG) == PKA_FLAG_ZERO) || \
                                                     ((FLAG) == PKA_FLAG_MEMORYTEST) || \
                                                     ((FLAG) == PKA_FLAG_BORROW) || \
                                                     ((FLAG) == PKA_FLAG_CARRY) || \
                                                     ((FLAG) == PKA_FLAG_USERFLAG0) || \
                                                     ((FLAG) == PKA_FLAG_USERFLAG1) || \
                                                     ((FLAG) == PKA_FLAG_USERFLAG2) || \
                                                     ((FLAG) == PKA_FLAG_USERFLAG3))

/**
 * @brief PKA Interrupt Enable
 */
#define PKA_IT_SIF_ERR                              PKA_IRQ_EN_SIF_ERR_IE           /* Enable interrupt on SIF error */
#define PKA_IT_SIF_SBE                              PKA_IRQ_EN_SIF_SBE_IE           /* Enable interrupt on SIF single bit error */
#define PKA_IT_DONE                                 PKA_IRQ_EN_DONE_IE              /* Enable interrupt on PKA done */
#define PKA_IT_GLB                                  PKA_IRQ_EN_GLB_IE               /* Enable interrupt on PKA global error */
#define IS_PKA_IT(IT)                               (((IT) == PKA_IT_SIF_ERR) || \
                                                     ((IT) == PKA_IT_SIF_SBE) || \
                                                     ((IT) == PKA_IT_DONE) || \
                                                     ((IT) == PKA_IT_GLB))

/**
 * @brief PKA Wide Register Map Base Addresses, ECC ops 256bit
 */
#define PKA_ECC_ADDR_256_A0                         ((uint32_t)(PKA_BASE + 0x400))
#define PKA_ECC_ADDR_256_A1                         ((uint32_t)(PKA_BASE + 0x420))
#define PKA_ECC_ADDR_256_A2                         ((uint32_t)(PKA_BASE + 0x440))
#define PKA_ECC_ADDR_256_A3                         ((uint32_t)(PKA_BASE + 0x460))
#define PKA_ECC_ADDR_256_A4                         ((uint32_t)(PKA_BASE + 0x480))
#define PKA_ECC_ADDR_256_A5                         ((uint32_t)(PKA_BASE + 0x4A0))
#define PKA_ECC_ADDR_256_A6                         ((uint32_t)(PKA_BASE + 0x4C0))
#define PKA_ECC_ADDR_256_A7                         ((uint32_t)(PKA_BASE + 0x4E0))
#define PKA_ECC_ADDR_256_B0                         ((uint32_t)(PKA_BASE + 0x800))
#define PKA_ECC_ADDR_256_B1                         ((uint32_t)(PKA_BASE + 0x820))
#define PKA_ECC_ADDR_256_B2                         ((uint32_t)(PKA_BASE + 0x840))
#define PKA_ECC_ADDR_256_B3                         ((uint32_t)(PKA_BASE + 0x860))
#define PKA_ECC_ADDR_256_B4                         ((uint32_t)(PKA_BASE + 0x880))
#define PKA_ECC_ADDR_256_B5                         ((uint32_t)(PKA_BASE + 0x8A0))
#define PKA_ECC_ADDR_256_B6                         ((uint32_t)(PKA_BASE + 0x8C0))
#define PKA_ECC_ADDR_256_B7                         ((uint32_t)(PKA_BASE + 0x8E0))
#define PKA_ECC_ADDR_256_C0                         ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_ECC_ADDR_256_C1                         ((uint32_t)(PKA_BASE + 0xC20))
#define PKA_ECC_ADDR_256_C2                         ((uint32_t)(PKA_BASE + 0xC40))
#define PKA_ECC_ADDR_256_C3                         ((uint32_t)(PKA_BASE + 0xC60))
#define PKA_ECC_ADDR_256_C4                         ((uint32_t)(PKA_BASE + 0xC80))
#define PKA_ECC_ADDR_256_C5                         ((uint32_t)(PKA_BASE + 0xCA0))
#define PKA_ECC_ADDR_256_C6                         ((uint32_t)(PKA_BASE + 0xCC0))
#define PKA_ECC_ADDR_256_C7                         ((uint32_t)(PKA_BASE + 0xCE0))
#define PKA_ECC_ADDR_256_D0                         ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_ECC_ADDR_256_D1                         ((uint32_t)(PKA_BASE + 0x1020))
#define PKA_ECC_ADDR_256_D2                         ((uint32_t)(PKA_BASE + 0x1040))
#define PKA_ECC_ADDR_256_D3                         ((uint32_t)(PKA_BASE + 0x1060))
#define PKA_ECC_ADDR_256_D4                         ((uint32_t)(PKA_BASE + 0x1080))
#define PKA_ECC_ADDR_256_D5                         ((uint32_t)(PKA_BASE + 0x10A0))
#define PKA_ECC_ADDR_256_D6                         ((uint32_t)(PKA_BASE + 0x10C0))
#define PKA_ECC_ADDR_256_D7                         ((uint32_t)(PKA_BASE + 0x10E0))

/**
 * @brief PKA Wide Register Map Base Addresses, ECC ops 512bit
 */
#define PKA_ECC_ADDR_512_A0                         ((uint32_t)(PKA_BASE + 0x400))
#define PKA_ECC_ADDR_512_A1                         ((uint32_t)(PKA_BASE + 0x440))
#define PKA_ECC_ADDR_512_A2                         ((uint32_t)(PKA_BASE + 0x480))
#define PKA_ECC_ADDR_512_A3                         ((uint32_t)(PKA_BASE + 0x4C0))
#define PKA_ECC_ADDR_512_A4                         ((uint32_t)(PKA_BASE + 0x500))
#define PKA_ECC_ADDR_512_A5                         ((uint32_t)(PKA_BASE + 0x540))
#define PKA_ECC_ADDR_512_A6                         ((uint32_t)(PKA_BASE + 0x580))
#define PKA_ECC_ADDR_512_A7                         ((uint32_t)(PKA_BASE + 0x5C0))
#define PKA_ECC_ADDR_512_B0                         ((uint32_t)(PKA_BASE + 0x800))
#define PKA_ECC_ADDR_512_B1                         ((uint32_t)(PKA_BASE + 0x840))
#define PKA_ECC_ADDR_512_B2                         ((uint32_t)(PKA_BASE + 0x880))
#define PKA_ECC_ADDR_512_B3                         ((uint32_t)(PKA_BASE + 0x8C0))
#define PKA_ECC_ADDR_512_B4                         ((uint32_t)(PKA_BASE + 0x900))
#define PKA_ECC_ADDR_512_B5                         ((uint32_t)(PKA_BASE + 0x940))
#define PKA_ECC_ADDR_512_B6                         ((uint32_t)(PKA_BASE + 0x980))
#define PKA_ECC_ADDR_512_B7                         ((uint32_t)(PKA_BASE + 0x9C0))
#define PKA_ECC_ADDR_512_C0                         ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_ECC_ADDR_512_C1                         ((uint32_t)(PKA_BASE + 0xC40))
#define PKA_ECC_ADDR_512_C2                         ((uint32_t)(PKA_BASE + 0xC80))
#define PKA_ECC_ADDR_512_C3                         ((uint32_t)(PKA_BASE + 0xCC0))
#define PKA_ECC_ADDR_512_C4                         ((uint32_t)(PKA_BASE + 0xD00))
#define PKA_ECC_ADDR_512_C5                         ((uint32_t)(PKA_BASE + 0xD40))
#define PKA_ECC_ADDR_512_C6                         ((uint32_t)(PKA_BASE + 0xD80))
#define PKA_ECC_ADDR_512_C7                         ((uint32_t)(PKA_BASE + 0xDC0))
#define PKA_ECC_ADDR_512_D0                         ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_ECC_ADDR_512_D1                         ((uint32_t)(PKA_BASE + 0x1040))
#define PKA_ECC_ADDR_512_D2                         ((uint32_t)(PKA_BASE + 0x1080))
#define PKA_ECC_ADDR_512_D3                         ((uint32_t)(PKA_BASE + 0x10C0))
#define PKA_ECC_ADDR_512_D4                         ((uint32_t)(PKA_BASE + 0x1100))
#define PKA_ECC_ADDR_512_D5                         ((uint32_t)(PKA_BASE + 0x1140))
#define PKA_ECC_ADDR_512_D6                         ((uint32_t)(PKA_BASE + 0x1180))
#define PKA_ECC_ADDR_512_D7                         ((uint32_t)(PKA_BASE + 0x11C0))

/**
 * @brief PKA Wide Register Map Base Addresses, ECC ops 1024bit
 */
#define PKA_ECC_ADDR_1024_A0                        ((uint32_t)(PKA_BASE + 0x400))
#define PKA_ECC_ADDR_1024_A1                        ((uint32_t)(PKA_BASE + 0x480))
#define PKA_ECC_ADDR_1024_A2                        ((uint32_t)(PKA_BASE + 0x500))
#define PKA_ECC_ADDR_1024_A3                        ((uint32_t)(PKA_BASE + 0x580))
#define PKA_ECC_ADDR_1024_A4                        ((uint32_t)(PKA_BASE + 0x600))
#define PKA_ECC_ADDR_1024_A5                        ((uint32_t)(PKA_BASE + 0x680))
#define PKA_ECC_ADDR_1024_A6                        ((uint32_t)(PKA_BASE + 0x700))
#define PKA_ECC_ADDR_1024_A7                        ((uint32_t)(PKA_BASE + 0x780))
#define PKA_ECC_ADDR_1024_B0                        ((uint32_t)(PKA_BASE + 0x800))
#define PKA_ECC_ADDR_1024_B1                        ((uint32_t)(PKA_BASE + 0x880))
#define PKA_ECC_ADDR_1024_B2                        ((uint32_t)(PKA_BASE + 0x900))
#define PKA_ECC_ADDR_1024_B3                        ((uint32_t)(PKA_BASE + 0x980))
#define PKA_ECC_ADDR_1024_B4                        ((uint32_t)(PKA_BASE + 0xA00))
#define PKA_ECC_ADDR_1024_B5                        ((uint32_t)(PKA_BASE + 0xA80))
#define PKA_ECC_ADDR_1024_B6                        ((uint32_t)(PKA_BASE + 0xB00))
#define PKA_ECC_ADDR_1024_B7                        ((uint32_t)(PKA_BASE + 0xB80))
#define PKA_ECC_ADDR_1024_C0                        ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_ECC_ADDR_1024_C1                        ((uint32_t)(PKA_BASE + 0xC80))
#define PKA_ECC_ADDR_1024_C2                        ((uint32_t)(PKA_BASE + 0xD00))
#define PKA_ECC_ADDR_1024_C3                        ((uint32_t)(PKA_BASE + 0xD80))
#define PKA_ECC_ADDR_1024_C4                        ((uint32_t)(PKA_BASE + 0xE00))
#define PKA_ECC_ADDR_1024_C5                        ((uint32_t)(PKA_BASE + 0xE80))
#define PKA_ECC_ADDR_1024_C6                        ((uint32_t)(PKA_BASE + 0xF00))
#define PKA_ECC_ADDR_1024_C7                        ((uint32_t)(PKA_BASE + 0xF80))
#define PKA_ECC_ADDR_1024_D0                        ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_ECC_ADDR_1024_D1                        ((uint32_t)(PKA_BASE + 0x1080))
#define PKA_ECC_ADDR_1024_D2                        ((uint32_t)(PKA_BASE + 0x1100))
#define PKA_ECC_ADDR_1024_D3                        ((uint32_t)(PKA_BASE + 0x1180))
#define PKA_ECC_ADDR_1024_D4                        ((uint32_t)(PKA_BASE + 0x1200))
#define PKA_ECC_ADDR_1024_D5                        ((uint32_t)(PKA_BASE + 0x1280))
#define PKA_ECC_ADDR_1024_D6                        ((uint32_t)(PKA_BASE + 0x1300))
#define PKA_ECC_ADDR_1024_D7                        ((uint32_t)(PKA_BASE + 0x1380))

/**
 * @brief PKA Wide Register Map Base Addresses, RSA ops 512bit
 */
#define PKA_RSA_ADDR_512_A0                         ((uint32_t)(PKA_BASE + 0x400))
#define PKA_RSA_ADDR_512_A1                         ((uint32_t)(PKA_BASE + 0x440))
#define PKA_RSA_ADDR_512_A2                         ((uint32_t)(PKA_BASE + 0x480))
#define PKA_RSA_ADDR_512_A3                         ((uint32_t)(PKA_BASE + 0x4C0))
#define PKA_RSA_ADDR_512_B0                         ((uint32_t)(PKA_BASE + 0x800))
#define PKA_RSA_ADDR_512_B1                         ((uint32_t)(PKA_BASE + 0x840))
#define PKA_RSA_ADDR_512_B2                         ((uint32_t)(PKA_BASE + 0x880))
#define PKA_RSA_ADDR_512_B3                         ((uint32_t)(PKA_BASE + 0x8C0))
#define PKA_RSA_ADDR_512_C0                         ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_RSA_ADDR_512_C1                         ((uint32_t)(PKA_BASE + 0xC40))
#define PKA_RSA_ADDR_512_C2                         ((uint32_t)(PKA_BASE + 0xC80))
#define PKA_RSA_ADDR_512_C3                         ((uint32_t)(PKA_BASE + 0xCC0))
#define PKA_RSA_ADDR_512_D0                         ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_RSA_ADDR_512_D1                         ((uint32_t)(PKA_BASE + 0x1040))
#define PKA_RSA_ADDR_512_D2                         ((uint32_t)(PKA_BASE + 0x1080))
#define PKA_RSA_ADDR_512_D3                         ((uint32_t)(PKA_BASE + 0x10C0))
#define PKA_RSA_ADDR_512_D4                         ((uint32_t)(PKA_BASE + 0x1100))
#define PKA_RSA_ADDR_512_D5                         ((uint32_t)(PKA_BASE + 0x1140))
#define PKA_RSA_ADDR_512_D6                         ((uint32_t)(PKA_BASE + 0x1180))
#define PKA_RSA_ADDR_512_D7                         ((uint32_t)(PKA_BASE + 0x11C0))

/**
 * @brief PKA Wide Register Map Base Addresses, RSA ops 1024bit
 */
#define PKA_RSA_ADDR_1024_A0                        ((uint32_t)(PKA_BASE + 0x400))
#define PKA_RSA_ADDR_1024_A1                        ((uint32_t)(PKA_BASE + 0x480))
#define PKA_RSA_ADDR_1024_A2                        ((uint32_t)(PKA_BASE + 0x500))
#define PKA_RSA_ADDR_1024_A3                        ((uint32_t)(PKA_BASE + 0x580))
#define PKA_RSA_ADDR_1024_B0                        ((uint32_t)(PKA_BASE + 0x800))
#define PKA_RSA_ADDR_1024_B1                        ((uint32_t)(PKA_BASE + 0x880))
#define PKA_RSA_ADDR_1024_B2                        ((uint32_t)(PKA_BASE + 0x900))
#define PKA_RSA_ADDR_1024_B3                        ((uint32_t)(PKA_BASE + 0x980))
#define PKA_RSA_ADDR_1024_C0                        ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_RSA_ADDR_1024_C1                        ((uint32_t)(PKA_BASE + 0xC80))
#define PKA_RSA_ADDR_1024_C2                        ((uint32_t)(PKA_BASE + 0xD00))
#define PKA_RSA_ADDR_1024_C3                        ((uint32_t)(PKA_BASE + 0xD80))
#define PKA_RSA_ADDR_1024_D0                        ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_RSA_ADDR_1024_D1                        ((uint32_t)(PKA_BASE + 0x1080))
#define PKA_RSA_ADDR_1024_D2                        ((uint32_t)(PKA_BASE + 0x1100))
#define PKA_RSA_ADDR_1024_D3                        ((uint32_t)(PKA_BASE + 0x1180))
#define PKA_RSA_ADDR_1024_D4                        ((uint32_t)(PKA_BASE + 0x1200))
#define PKA_RSA_ADDR_1024_D5                        ((uint32_t)(PKA_BASE + 0x1280))
#define PKA_RSA_ADDR_1024_D6                        ((uint32_t)(PKA_BASE + 0x1300))
#define PKA_RSA_ADDR_1024_D7                        ((uint32_t)(PKA_BASE + 0x1380))

/**
 * @brief PKA Wide Register Map Base Addresses, RSA ops 2048bit
 */
#define PKA_RSA_ADDR_2048_A0                        ((uint32_t)(PKA_BASE + 0x400))
#define PKA_RSA_ADDR_2048_A1                        ((uint32_t)(PKA_BASE + 0x500))
#define PKA_RSA_ADDR_2048_A2                        ((uint32_t)(PKA_BASE + 0x600))
#define PKA_RSA_ADDR_2048_A3                        ((uint32_t)(PKA_BASE + 0x700))
#define PKA_RSA_ADDR_2048_B0                        ((uint32_t)(PKA_BASE + 0x800))
#define PKA_RSA_ADDR_2048_B1                        ((uint32_t)(PKA_BASE + 0x900))
#define PKA_RSA_ADDR_2048_B2                        ((uint32_t)(PKA_BASE + 0xA00))
#define PKA_RSA_ADDR_2048_B3                        ((uint32_t)(PKA_BASE + 0xB00))
#define PKA_RSA_ADDR_2048_C0                        ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_RSA_ADDR_2048_C1                        ((uint32_t)(PKA_BASE + 0xD00))
#define PKA_RSA_ADDR_2048_C2                        ((uint32_t)(PKA_BASE + 0xE00))
#define PKA_RSA_ADDR_2048_C3                        ((uint32_t)(PKA_BASE + 0xF00))
#define PKA_RSA_ADDR_2048_D0                        ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_RSA_ADDR_2048_D1                        ((uint32_t)(PKA_BASE + 0x1100))
#define PKA_RSA_ADDR_2048_D2                        ((uint32_t)(PKA_BASE + 0x1200))
#define PKA_RSA_ADDR_2048_D3                        ((uint32_t)(PKA_BASE + 0x1300))
#define PKA_RSA_ADDR_2048_D4                        ((uint32_t)(PKA_BASE + 0x1400))
#define PKA_RSA_ADDR_2048_D5                        ((uint32_t)(PKA_BASE + 0x1500))
#define PKA_RSA_ADDR_2048_D6                        ((uint32_t)(PKA_BASE + 0x1600))
#define PKA_RSA_ADDR_2048_D7                        ((uint32_t)(PKA_BASE + 0x1700))

/**
 * @brief PKA Wide Register Map Base Addresses, RSA ops 4096bit
 */
#define PKA_RSA_ADDR_4096_A0                        ((uint32_t)(PKA_BASE + 0x400))
#define PKA_RSA_ADDR_4096_A1                        ((uint32_t)(PKA_BASE + 0x600))
#define PKA_RSA_ADDR_4096_B0                        ((uint32_t)(PKA_BASE + 0x800))
#define PKA_RSA_ADDR_4096_B1                        ((uint32_t)(PKA_BASE + 0xA00))
#define PKA_RSA_ADDR_4096_C0                        ((uint32_t)(PKA_BASE + 0xC00))
#define PKA_RSA_ADDR_4096_C1                        ((uint32_t)(PKA_BASE + 0xE00))
#define PKA_RSA_ADDR_4096_D0                        ((uint32_t)(PKA_BASE + 0x1000))
#define PKA_RSA_ADDR_4096_D1                        ((uint32_t)(PKA_BASE + 0x1200))
#define PKA_RSA_ADDR_4096_D2                        ((uint32_t)(PKA_BASE + 0x1400))
#define PKA_RSA_ADDR_4096_D3                        ((uint32_t)(PKA_BASE + 0x1600))

/*
 * @brief Function declaration
 */
void PKA_Struct(PKA_InitTypeDef * const PKA_InitStruct);
void PKA_Init(PKA_TypeDef *PKAx, const PKA_InitTypeDef * const PKA_InitStruct);
void PKA_ITConfig(PKA_TypeDef *PKAx, uint32_t ITType, EnState NewState);
FlagStatus PKA_GetFlagStatus(PKA_TypeDef *PKAx, uint32_t PKA_Flag);
FlagStatus PKA_GetStatStatus(PKA_TypeDef *PKAx, uint32_t PKA_Stat);
void PKA_ClearStatus(PKA_TypeDef *PKAx, uint32_t PKA_Stat);
void PKA_SetStack(PKA_TypeDef *PKAx, uint32_t StackPtr);
void PKA_ClearStack(PKA_TypeDef *PKAx);
PKA_StopReasonEnum PKA_GetStopReasonCode(PKA_TypeDef *PKAx);

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
