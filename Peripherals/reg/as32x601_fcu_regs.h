/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_fcu_regs.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version:         V1.0
 * Date:            2025/07/10
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2025/07/10     1.0     build this module
 * Description:     This file contains all the register correlation defines for the FCU firmware library.
 */

#ifndef AS32X601_FCU_REG_H
#define AS32X601_FCU_REG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601.h"
#include "as32x601_addrmap.h"

/*
 * @brief FCU registers structure
 */
typedef struct
{
    __IO uint32_t CFG[42];      /* FCU_CFGx         Config register,                            Address offset: 0x00~0xA4 */
    __IO uint32_t SFTR;         /* FCU_SFTR         Software Fault Trigger register,            Address offset: 0xA8 */
    __I  uint32_t SFSTA;        /* FCU_SFSTA        Software Fault Status register,             Address offset: 0xAC */
    __IO uint32_t SFCNT;        /* FCU_SFCNT        Software Fault Count register,              Address offset: 0xB0 */
    __IO uint32_t SFCLR;        /* FCU_SFCLR        Software Fault Clear register,              Address offset: 0xB4 */
    __I  uint32_t ALARM0;       /* FCU_ALARM0       Fault Alert register                        Address offset: 0xB8*/
    __I  uint32_t ALARM1;       /* FCU_ALARM1       Fault Alert register                        Address offset: 0xBC*/
    __I  uint32_t FAULT0;       /* FCU_FAULT0       Fault Source register                       Address offset: 0xC0*/
    __I  uint32_t FAULT1;       /* FCU_FAULT1       Fault Source register                       Address offset: 0xC4*/
    __IO uint32_t CLEAR0;       /* FCU_CLEAR0       Fault/Alarm Clear register                  Address offset: 0xC8*/
    __IO uint32_t CLEAR1;       /* FCU_CLEAR1       Fault/Alarm Clear register                  Address offset: 0xCC*/
    __IO uint32_t OCLR;         /* FCU_OCLR         Bus Timeout/ECC Clear register              Address offset: 0xD0*/
} FCU_TypeDef;

/*
 * @brief CMU peripheral declaration
 */
#define FCU    ((FCU_TypeDef *)FCU_BASE)

/******************  Bits definition for FCU_CFGx register  *****************/
#define FCU_CFG_EN_DPos             (0U)
#define FCU_CFG_EN_Pos              FCU_CFG_EN_DPos
#define FCU_CFG_EN_Msk              (0x1UL << FCU_CFG_EN_Pos)               /* 0x00000001 */
#define FCU_CFG_EN                  FCU_CFG_EN_Msk                          /* CFG[0] bit (FCU channel enable) */ 

#define FCU_CFG_MASK_DPos           (1U)
#define FCU_CFG_MASK_Pos            FCU_CFG_MASK_DPos
#define FCU_CFG_MASK_Msk            (0x1UL << FCU_CFG_MASK_Pos)             /* 0x00000002 */
#define FCU_CFG_MASK                FCU_CFG_MASK_Msk                        /* CFG[1] bit (FCU channel mask config) */

#define FCU_CFG_LEVEL_DPos          (2U)
#define FCU_CFG_LEVEL_Pos           FCU_CFG_LEVEL_DPos
#define FCU_CFG_LEVEL_Msk           (0x3UL << FCU_CFG_LEVEL_Pos)            /* 0x0000000C */
#define FCU_CFG_LEVEL               FCU_CFG_LEVEL_Msk                       /* CFG[3:2] bits (FCU channel fault level) */

#define FCU_CFG_AACT_DPos           (4U)
#define FCU_CFG_AACT_Pos            FCU_CFG_AACT_DPos
#define FCU_CFG_AACT_Msk            (0x1UL << FCU_CFG_AACT_Pos)             /* 0x00000010 */
#define FCU_CFG_AACT                FCU_CFG_AACT_Msk                        /* CFG[4] bit (FCU channel alarm action) */

#define FCU_CFG_FACT_DPos           (5U)
#define FCU_CFG_FACT_Pos            FCU_CFG_FACT_DPos
#define FCU_CFG_FACT_Msk            (0x3UL << FCU_CFG_FACT_Pos)             /* 0x00000050 */
#define FCU_CFG_FACT                FCU_CFG_FACT_Msk                        /* CFG[6:5] bits (FCU channel alarm action) */

#define FCU_CFG_ATF_CNT_DPos        (7U)
#define FCU_CFG_ATF_CNT_Pos         FCU_CFG_ATF_CNT_DPos
#define FCU_CFG_ATF_CNT_Msk         (0xFFUL << FCU_CFG_ATF_CNT_Pos)         /* 0x00007F80 */
#define FCU_CFG_ATF_CNT             FCU_CFG_ATF_CNT_Msk                     /* CFG[14:7] bits (FCU channel alarm to fault count) */

#define FCU_CFG_FOCU_CNT_DPos       (15U)
#define FCU_CFG_FOCU_CNT_Pos        FCU_CFG_FOCU_CNT_DPos
#define FCU_CFG_FOCU_CNT_Msk        (0xFFUL << FCU_CFG_FOCU_CNT_Pos)        /* 0x000000FF */
#define FCU_CFG_FOCU_CNT            FCU_CFG_FOCU_CNT_Msk                    /* CFG[22:15] bits (FCU channel fault to reset count) */

/******************  Bits definition for FCU_SFTR register  *****************/
#define FCU_SFTR_TRIG0_DPos         (0U)
#define FCU_SFTR_TRIG0_Pos          FCU_SFTR_TRIG0_DPos
#define FCU_SFTR_TRIG0_Msk          (0x1UL << FCU_SFTR_TRIG0_Pos)           /* 0x00000001 */
#define FCU_SFTR_TRIG0              FCU_SFTR_TRIG0_Msk                      /* Software fault channel 0 trigger bit */

#define FCU_SFTR_TRIG1_DPos         (1U)
#define FCU_SFTR_TRIG1_Pos          FCU_SFTR_TRIG1_DPos
#define FCU_SFTR_TRIG1_Msk          (0x1UL << FCU_SFTR_TRIG1_Pos)           /* 0x00000002 */
#define FCU_SFTR_TRIG1              FCU_SFTR_TRIG1_Msk                      /* Software fault channel 1 trigger bit */

#define FCU_SFTR_TRIG2_DPos         (2U)
#define FCU_SFTR_TRIG2_Pos          FCU_SFTR_TRIG2_DPos
#define FCU_SFTR_TRIG2_Msk          (0x1UL << FCU_SFTR_TRIG2_Pos)           /* 0x00000004 */
#define FCU_SFTR_TRIG2              FCU_SFTR_TRIG2_Msk                      /* Software fault channel 2 trigger bit */

#define FCU_SFTR_TRIG3_DPos         (3U)
#define FCU_SFTR_TRIG3_Pos          FCU_SFTR_TRIG3_DPos
#define FCU_SFTR_TRIG3_Msk          (0x1UL << FCU_SFTR_TRIG3_Pos)           /* 0x00000008 */
#define FCU_SFTR_TRIG3              FCU_SFTR_TRIG3_Msk                      /* Software fault channel 3 trigger bit */

/******************  Bits definition for FCU_SFSTA register  *****************/

#define FCU_SFSTA_STA0_DPos        (0U)
#define FCU_SFSTA_STA0_Pos         FCU_SFSTA_STA0_DPos
#define FCU_SFSTA_STA0_Msk         (0x1UL << FCU_SFSTA_STA0_Pos)            /* 0x00000001 */
#define FCU_SFSTA_STA0             FCU_SFSTA_STA0_Msk                       /* Software fault channel 0 status bit */

#define FCU_SFSTA_STA1_DPos        (1U)
#define FCU_SFSTA_STA1_Pos         FCU_SFSTA_STA1_DPos
#define FCU_SFSTA_STA1_Msk         (0x1UL << FCU_SFSTA_STA1_Pos)            /* 0x00000002 */
#define FCU_SFSTA_STA1             FCU_SFSTA_STA1_Msk                       /* Software fault channel 1 status bit */

#define FCU_SFSTA_STA2_DPos        (2U)
#define FCU_SFSTA_STA2_Pos         FCU_SFSTA_STA2_DPos
#define FCU_SFSTA_STA2_Msk         (0x1UL << FCU_SFSTA_STA2_Pos)            /* 0x00000004 */
#define FCU_SFSTA_STA2             FCU_SFSTA_STA2_Msk                       /* Software fault channel 2 status bit */

#define FCU_SFSTA_STA3_DPos        (3U)
#define FCU_SFSTA_STA3_Pos         FCU_SFSTA_STA3_DPos
#define FCU_SFSTA_STA3_Msk         (0x1UL << FCU_SFSTA_STA3_Pos)            /* 0x00000008 */
#define FCU_SFSTA_STA3             FCU_SFSTA_STA3_Msk                       /* Software fault channel 3 status bit */

/******************  Bits definition for FCU_SFCNT register  *****************/

#define FCU_SFCNT_CNT0_DPos        (0U)
#define FCU_SFCNT_CNT0_Pos         FCU_SFCNT_CNT0_DPos
#define FCU_SFCNT_CNT0_Msk         (0xFFUL << FCU_SFCNT_CNT0_Pos)        /* 0x000000FF */
#define FCU_SFCNT_CNT0             FCU_SFCNT_CNT0_Msk                    /* SFCNT[7:0] bits (Software fault channel 0 count) */

#define FCU_SFCNT_CNT1_DPos        (8U)
#define FCU_SFCNT_CNT1_Pos         FCU_SFCNT_CNT1_DPos
#define FCU_SFCNT_CNT1_Msk         (0xFFUL << FCU_SFCNT_CNT1_Pos)        /* 0x0000FF00 */
#define FCU_SFCNT_CNT1             FCU_SFCNT_CNT1_Msk                    /* SFCNT[15:8] bits (Software fault channel 1 count) */

#define FCU_SFCNT_CNT2_DPos        (16U)
#define FCU_SFCNT_CNT2_Pos         FCU_SFCNT_CNT2_DPos
#define FCU_SFCNT_CNT2_Msk         (0xFFUL << FCU_SFCNT_CNT2_Pos)        /* 0x00FF0000 */
#define FCU_SFCNT_CNT2             FCU_SFCNT_CNT2_Msk                    /* SFCNT[23:16] bits (Software fault channel 2 count) */

#define FCU_SFCNT_CNT3_DPos        (24U)
#define FCU_SFCNT_CNT3_Pos         FCU_SFCNT_CNT3_DPos
#define FCU_SFCNT_CNT3_Msk         (0xFFUL << FCU_SFCNT_CNT3_Pos)        /* 0xFF000000 */
#define FCU_SFCNT_CNT3             FCU_SFCNT_CNT3_Msk                    /* SFCNT[31:24] bits (Software fault channel 3 count) */

/******************  Bits definition for FCU_SFCLR register  *****************/

#define FCU_SFCLR_CLR0_DPos        (0U)
#define FCU_SFCLR_CLR0_Pos         FCU_SFCLR_CLR0_DPos
#define FCU_SFCLR_CLR0_Msk         (0x1UL << FCU_SFCLR_CLR0_Pos)         /* 0x00000001 */
#define FCU_SFCLR_CLR0             FCU_SFCLR_CLR0_Msk                    /* Software fault channel 0 clear bit */

#define FCU_SFCLR_CLR1_DPos        (1U)
#define FCU_SFCLR_CLR1_Pos         FCU_SFCLR_CLR1_DPos
#define FCU_SFCLR_CLR1_Msk         (0x1UL << FCU_SFCLR_CLR1_Pos)         /* 0x00000002 */
#define FCU_SFCLR_CLR1             FCU_SFCLR_CLR1_Msk                    /* Software fault channel 1 clear bit */

#define FCU_SFCLR_CLR2_DPos        (2U)
#define FCU_SFCLR_CLR2_Pos         FCU_SFCLR_CLR2_DPos
#define FCU_SFCLR_CLR2_Msk         (0x1UL << FCU_SFCLR_CLR2_Pos)         /* 0x00000004 */
#define FCU_SFCLR_CLR2             FCU_SFCLR_CLR2_Msk                    /* Software fault channel 2 clear bit */

#define FCU_SFCLR_CLR3_DPos        (3U)
#define FCU_SFCLR_CLR3_Pos         FCU_SFCLR_CLR3_DPos
#define FCU_SFCLR_CLR3_Msk         (0x1UL << FCU_SFCLR_CLR3_Pos)         /* 0x00000008 */
#define FCU_SFCLR_CLR3             FCU_SFCLR_CLR3_Msk                    /* Software fault channel 3 clear bit */

/******************  Bits definition for FCU_ALARM0 register  *****************/

#define FCU_ALARM0_A0_DPos          (0U)
#define FCU_ALARM0_A0_Pos           FCU_ALARM0_A0_DPos
#define FCU_ALARM0_A0_Msk           (0x1UL << FCU_ALARM0_A0_Pos)         /* 0x00000001 */
#define FCU_ALARM0_A0               FCU_ALARM0_A0_Msk                    /* FCU Channel 0 alarm bit */

#define FCU_ALARM0_A1_DPos          (1U)
#define FCU_ALARM0_A1_Pos           FCU_ALARM0_A1_DPos
#define FCU_ALARM0_A1_Msk           (0x1UL << FCU_ALARM0_A1_Pos)         /* 0x00000002 */
#define FCU_ALARM0_A1               FCU_ALARM0_A1_Msk                    /* FCU Channel 1 alarm bit */

#define FCU_ALARM0_A2_DPos          (2U)
#define FCU_ALARM0_A2_Pos           FCU_ALARM0_A2_DPos
#define FCU_ALARM0_A2_Msk           (0x1UL << FCU_ALARM0_A2_Pos)         /* 0x00000004 */
#define FCU_ALARM0_A2               FCU_ALARM0_A2_Msk                    /* FCU Channel 2 alarm bit */

#define FCU_ALARM0_A3_DPos          (3U)
#define FCU_ALARM0_A3_Pos           FCU_ALARM0_A3_DPos
#define FCU_ALARM0_A3_Msk           (0x1UL << FCU_ALARM0_A3_Pos)         /* 0x00000008 */
#define FCU_ALARM0_A3               FCU_ALARM0_A3_Msk                    /* FCU Channel 3 alarm bit */

#define FCU_ALARM0_A4_DPos          (4U)
#define FCU_ALARM0_A4_Pos           FCU_ALARM0_A4_DPos
#define FCU_ALARM0_A4_Msk           (0x1UL << FCU_ALARM0_A4_Pos)         /* 0x00000010 */
#define FCU_ALARM0_A4               FCU_ALARM0_A4_Msk                    /* FCU Channel 4 alarm bit */

#define FCU_ALARM0_A5_DPos          (5U)
#define FCU_ALARM0_A5_Pos           FCU_ALARM0_A5_DPos
#define FCU_ALARM0_A5_Msk           (0x1UL << FCU_ALARM0_A5_Pos)         /* 0x00000020 */
#define FCU_ALARM0_A5               FCU_ALARM0_A5_Msk                    /* FCU Channel 5 alarm bit */

#define FCU_ALARM0_A6_DPos          (6U)
#define FCU_ALARM0_A6_Pos           FCU_ALARM0_A6_DPos
#define FCU_ALARM0_A6_Msk           (0x1UL << FCU_ALARM0_A6_Pos)         /* 0x00000040 */
#define FCU_ALARM0_A6               FCU_ALARM0_A6_Msk                    /* FCU Channel 6 alarm bit */

#define FCU_ALARM0_A7_DPos          (7U)
#define FCU_ALARM0_A7_Pos           FCU_ALARM0_A7_DPos
#define FCU_ALARM0_A7_Msk           (0x1UL << FCU_ALARM0_A7_Pos)         /* 0x00000080 */
#define FCU_ALARM0_A7               FCU_ALARM0_A7_Msk                    /* FCU Channel 7 alarm bit */

#define FCU_ALARM0_A8_DPos          (8U)
#define FCU_ALARM0_A8_Pos           FCU_ALARM0_A8_DPos
#define FCU_ALARM0_A8_Msk           (0x1UL << FCU_ALARM0_A8_Pos)         /* 0x00000100 */
#define FCU_ALARM0_A8               FCU_ALARM0_A8_Msk                    /* FCU Channel 8 alarm bit */

#define FCU_ALARM0_A9_DPos          (9U)
#define FCU_ALARM0_A9_Pos           FCU_ALARM0_A9_DPos
#define FCU_ALARM0_A9_Msk           (0x1UL << FCU_ALARM0_A9_Pos)         /* 0x00000200 */
#define FCU_ALARM0_A9               FCU_ALARM0_A9_Msk                    /* FCU Channel 9 alarm bit */

#define FCU_ALARM0_A10_DPos         (10U)
#define FCU_ALARM0_A10_Pos          FCU_ALARM0_A10_DPos
#define FCU_ALARM0_A10_Msk          (0x1UL << FCU_ALARM0_A10_Pos)         /* 0x00000400 */
#define FCU_ALARM0_A10              FCU_ALARM0_A10_Msk                    /* FCU Channel 10 alarm bit */

#define FCU_ALARM0_A11_DPos         (11U)
#define FCU_ALARM0_A11_Pos          FCU_ALARM0_A11_DPos
#define FCU_ALARM0_A11_Msk          (0x1UL << FCU_ALARM0_A11_Pos)         /* 0x00000800 */
#define FCU_ALARM0_A11              FCU_ALARM0_A11_Msk                    /* FCU Channel 11 alarm bit */

#define FCU_ALARM0_A12_DPos         (12U)
#define FCU_ALARM0_A12_Pos          FCU_ALARM0_A12_DPos
#define FCU_ALARM0_A12_Msk          (0x1UL << FCU_ALARM0_A12_Pos)         /* 0x00001000 */
#define FCU_ALARM0_A12              FCU_ALARM0_A12_Msk                    /* FCU Channel 12 alarm bit */

#define FCU_ALARM0_A13_DPos         (13U)
#define FCU_ALARM0_A13_Pos          FCU_ALARM0_A13_DPos
#define FCU_ALARM0_A13_Msk          (0x1UL << FCU_ALARM0_A13_Pos)         /* 0x00002000 */
#define FCU_ALARM0_A13              FCU_ALARM0_A13_Msk                    /* FCU Channel 13 alarm bit */

#define FCU_ALARM0_A14_DPos         (14U)
#define FCU_ALARM0_A14_Pos          FCU_ALARM0_A14_DPos
#define FCU_ALARM0_A14_Msk          (0x1UL << FCU_ALARM0_A14_Pos)         /* 0x00004000 */
#define FCU_ALARM0_A14              FCU_ALARM0_A14_Msk                    /* FCU Channel 14 alarm bit */

#define FCU_ALARM0_A15_DPos         (15U)
#define FCU_ALARM0_A15_Pos          FCU_ALARM0_A15_DPos
#define FCU_ALARM0_A15_Msk          (0x1UL << FCU_ALARM0_A15_Pos)         /* 0x00008000 */
#define FCU_ALARM0_A15              FCU_ALARM0_A15_Msk                    /* FCU Channel 15 alarm bit */

#define FCU_ALARM0_A16_DPos         (16U)
#define FCU_ALARM0_A16_Pos          FCU_ALARM0_A16_DPos
#define FCU_ALARM0_A16_Msk          (0x1UL << FCU_ALARM0_A16_Pos)         /* 0x00010000 */
#define FCU_ALARM0_A16              FCU_ALARM0_A16_Msk                    /* FCU Channel 16 alarm bit */

#define FCU_ALARM0_A17_DPos         (17U)
#define FCU_ALARM0_A17_Pos          FCU_ALARM0_A17_DPos
#define FCU_ALARM0_A17_Msk          (0x1UL << FCU_ALARM0_A17_Pos)         /* 0x00020000 */
#define FCU_ALARM0_A17              FCU_ALARM0_A17_Msk                    /* FCU Channel 17 alarm bit */

#define FCU_ALARM0_A18_DPos         (18U)
#define FCU_ALARM0_A18_Pos          FCU_ALARM0_A18_DPos
#define FCU_ALARM0_A18_Msk          (0x1UL << FCU_ALARM0_A18_Pos)         /* 0x00040000 */
#define FCU_ALARM0_A18              FCU_ALARM0_A18_Msk                    /* FCU Channel 18 alarm bit */

#define FCU_ALARM0_A19_DPos         (19U)
#define FCU_ALARM0_A19_Pos          FCU_ALARM0_A19_DPos
#define FCU_ALARM0_A19_Msk          (0x1UL << FCU_ALARM0_A19_Pos)         /* 0x00080000 */
#define FCU_ALARM0_A19              FCU_ALARM0_A19_Msk                    /* FCU Channel 19 alarm bit */

#define FCU_ALARM0_A20_DPos         (20U)
#define FCU_ALARM0_A20_Pos          FCU_ALARM0_A20_DPos
#define FCU_ALARM0_A20_Msk          (0x1UL << FCU_ALARM0_A20_Pos)         /* 0x00100000 */
#define FCU_ALARM0_A20              FCU_ALARM0_A20_Msk                    /* FCU Channel 20 alarm bit */

#define FCU_ALARM0_A21_DPos         (21U)
#define FCU_ALARM0_A21_Pos          FCU_ALARM0_A21_DPos
#define FCU_ALARM0_A21_Msk          (0x1UL << FCU_ALARM0_A21_Pos)         /* 0x00200000 */
#define FCU_ALARM0_A21              FCU_ALARM0_A21_Msk                    /* FCU Channel 21 alarm bit */

#define FCU_ALARM0_A22_DPos         (22U)
#define FCU_ALARM0_A22_Pos          FCU_ALARM0_A22_DPos
#define FCU_ALARM0_A22_Msk          (0x1UL << FCU_ALARM0_A22_Pos)         /* 0x00400000 */
#define FCU_ALARM0_A22              FCU_ALARM0_A22_Msk                    /* FCU Channel 22 alarm bit */

#define FCU_ALARM0_A23_DPos         (23U)
#define FCU_ALARM0_A23_Pos          FCU_ALARM0_A23_DPos
#define FCU_ALARM0_A23_Msk          (0x1UL << FCU_ALARM0_A23_Pos)         /* 0x00800000 */
#define FCU_ALARM0_A23              FCU_ALARM0_A23_Msk                    /* FCU Channel 23 alarm bit */

#define FCU_ALARM0_A24_DPos         (24U)
#define FCU_ALARM0_A24_Pos          FCU_ALARM0_A24_DPos
#define FCU_ALARM0_A24_Msk          (0x1UL << FCU_ALARM0_A24_Pos)         /* 0x01000000 */
#define FCU_ALARM0_A24              FCU_ALARM0_A24_Msk                    /* FCU Channel 24 alarm bit */

#define FCU_ALARM0_A25_DPos         (25U)
#define FCU_ALARM0_A25_Pos          FCU_ALARM0_A25_DPos
#define FCU_ALARM0_A25_Msk          (0x1UL << FCU_ALARM0_A25_Pos)         /* 0x02000000*/
#define FCU_ALARM0_A25              FCU_ALARM0_A25_Msk                    /* FCU Channel 25 alarm bit */

#define FCU_ALARM0_A26_DPos         (26U)
#define FCU_ALARM0_A26_Pos          FCU_ALARM0_A26_DPos
#define FCU_ALARM0_A26_Msk          (0x1UL << FCU_ALARM0_A26_Pos)         /* 0x04000000*/
#define FCU_ALARM0_A26              FCU_ALARM0_A26_Msk                    /* FCU Channel 26 alarm bit */

#define FCU_ALARM0_A27_DPos         (27U)
#define FCU_ALARM0_A27_Pos          FCU_ALARM0_A27_DPos
#define FCU_ALARM0_A27_Msk          (0x1UL << FCU_ALARM0_A27_Pos)         /* 0x08000000 */
#define FCU_ALARM0_A27              FCU_ALARM0_A27_Msk                    /* FCU Channel 27 alarm bit */

#define FCU_ALARM0_A28_DPos         (28U)
#define FCU_ALARM0_A28_Pos          FCU_ALARM0_A28_DPos
#define FCU_ALARM0_A28_Msk          (0x1UL << FCU_ALARM0_A28_Pos)         /* 0x10000000 */
#define FCU_ALARM0_A28              FCU_ALARM0_A28_Msk                    /* FCU Channel 28 alarm bit */

#define FCU_ALARM0_A29_DPos         (29U)
#define FCU_ALARM0_A29_Pos          FCU_ALARM0_A29_DPos
#define FCU_ALARM0_A29_Msk          (0x1UL << FCU_ALARM0_A29_Pos)         /* 0x20000000 */
#define FCU_ALARM0_A29              FCU_ALARM0_A29_Msk                    /* FCU Channel 29 alarm bit */

#define FCU_ALARM0_A30_DPos         (30U)
#define FCU_ALARM0_A30_Pos          FCU_ALARM0_A30_DPos
#define FCU_ALARM0_A30_Msk          (0x1UL << FCU_ALARM0_A30_Pos)         /* 0x40000000 */
#define FCU_ALARM0_A30              FCU_ALARM0_A30_Msk                    /* FCU Channel 30 alarm bit */

#define FCU_ALARM0_A31_DPos         (31U)
#define FCU_ALARM0_A31_Pos          FCU_ALARM0_A31_DPos
#define FCU_ALARM0_A31_Msk          (0x1UL << FCU_ALARM0_A31_Pos)         /* 0x80000000*/
#define FCU_ALARM0_A31              FCU_ALARM0_A31_Msk                    /* FCU Channel 31 alarm bit */

/******************  Bits definition for FCU_ALARM1 register  *****************/

#define FCU_ALARM1_A32_DPos         (0U)
#define FCU_ALARM1_A32_Pos          FCU_ALARM1_A32_DPos
#define FCU_ALARM1_A32_Msk          (0x1UL << FCU_ALARM1_A32_Pos)         /* 0x00000001 */
#define FCU_ALARM1_A32              FCU_ALARM1_A32_Msk                    /* FCU Channel 32 alarm bit */

#define FCU_ALARM1_A33_DPos         (1U)
#define FCU_ALARM1_A33_Pos          FCU_ALARM1_A33_DPos
#define FCU_ALARM1_A33_Msk          (0x1UL << FCU_ALARM1_A33_Pos)         /* 0x00000002 */
#define FCU_ALARM1_A33              FCU_ALARM1_A33_Msk                    /* FCU Channel 33 alarm bit */

#define FCU_ALARM1_A34_DPos         (2U)
#define FCU_ALARM1_A34_Pos          FCU_ALARM1_A34_DPos
#define FCU_ALARM1_A34_Msk          (0x1UL << FCU_ALARM1_A34_Pos)         /* 0x00000004 */
#define FCU_ALARM1_A34              FCU_ALARM1_A34_Msk                    /* FCU Channel 34 alarm bit */

#define FCU_ALARM1_A35_DPos         (3U)
#define FCU_ALARM1_A35_Pos          FCU_ALARM1_A35_DPos
#define FCU_ALARM1_A35_Msk          (0x1UL << FCU_ALARM1_A35_Pos)         /* 0x00000008 */
#define FCU_ALARM1_A35              FCU_ALARM1_A35_Msk                    /* FCU Channel 35 alarm bit */

#define FCU_ALARM1_A36_DPos         (4U)
#define FCU_ALARM1_A36_Pos          FCU_ALARM1_A36_DPos
#define FCU_ALARM1_A36_Msk          (0x1UL << FCU_ALARM1_A36_Pos)         /* 0x00000010 */
#define FCU_ALARM1_A36              FCU_ALARM1_A36_Msk                    /* FCU Channel 36 alarm bit */

#define FCU_ALARM1_A37_DPos         (5U)
#define FCU_ALARM1_A37_Pos          FCU_ALARM1_A37_DPos
#define FCU_ALARM1_A37_Msk          (0x1UL << FCU_ALARM1_A37_Pos)         /* 0x00000020 */
#define FCU_ALARM1_A37              FCU_ALARM1_A37_Msk                    /* FCU Channel 37 alarm bit */

#define FCU_ALARM1_A38_DPos         (6U)
#define FCU_ALARM1_A38_Pos          FCU_ALARM1_A38_DPos
#define FCU_ALARM1_A38_Msk          (0x1UL << FCU_ALARM1_A38_Pos)         /* 0x00000040 */
#define FCU_ALARM1_A38              FCU_ALARM1_A38_Msk                    /* FCU Channel 38 alarm bit */

#define FCU_ALARM1_A39_DPos         (7U)
#define FCU_ALARM1_A39_Pos          FCU_ALARM1_A39_DPos
#define FCU_ALARM1_A39_Msk          (0x1UL << FCU_ALARM1_A39_Pos)         /* 0x00000080 */
#define FCU_ALARM1_A39              FCU_ALARM1_A39_Msk                    /* FCU Channel 39 alarm bit */

#define FCU_ALARM1_A40_DPos         (8U)
#define FCU_ALARM1_A40_Pos          FCU_ALARM1_A40_DPos
#define FCU_ALARM1_A40_Msk          (0x1UL << FCU_ALARM1_A40_Pos)         /* 0x00000100 */
#define FCU_ALARM1_A40              FCU_ALARM1_A40_Msk                    /* FCU Channel 40 alarm bit */

#define FCU_ALARM1_A41_DPos         (9U)
#define FCU_ALARM1_A41_Pos          FCU_ALARM1_A41_DPos
#define FCU_ALARM1_A41_Msk          (0x1UL << FCU_ALARM1_A41_Pos)         /* 0x00000200 */
#define FCU_ALARM1_A41              FCU_ALARM1_A41_Msk                    /* FCU Channel 41 alarm bit */

/******************  Bits definition for FCU_FAULT0 register  *****************/

#define FCU_FAULT0_F0_DPos          (0U)
#define FCU_FAULT0_F0_Pos           FCU_FAULT0_F0_DPos
#define FCU_FAULT0_F0_Msk           (0x1UL << FCU_FAULT0_F0_Pos)         /* 0x00000001 */
#define FCU_FAULT0_F0               FCU_FAULT0_F0_Msk                    /* FCU Channel 0 fault bit */

#define FCU_FAULT0_F1_DPos          (1U)
#define FCU_FAULT0_F1_Pos           FCU_FAULT0_F1_DPos
#define FCU_FAULT0_F1_Msk           (0x1UL << FCU_FAULT0_F1_Pos)         /* 0x00000002 */
#define FCU_FAULT0_F1               FCU_FAULT0_F1_Msk                    /* FCU Channel 1 fault bit */

#define FCU_FAULT0_F2_DPos          (2U)
#define FCU_FAULT0_F2_Pos           FCU_FAULT0_F2_DPos
#define FCU_FAULT0_F2_Msk           (0x1UL << FCU_FAULT0_F2_Pos)         /* 0x00000004 */
#define FCU_FAULT0_F2               FCU_FAULT0_F2_Msk                    /* FCU Channel 2 fault bit */

#define FCU_FAULT0_F3_DPos          (3U)
#define FCU_FAULT0_F3_Pos           FCU_FAULT0_F3_DPos
#define FCU_FAULT0_F3_Msk           (0x1UL << FCU_FAULT0_F3_Pos)         /* 0x00000008 */
#define FCU_FAULT0_F3               FCU_FAULT0_F3_Msk                    /* FCU Channel 3 fault bit */

#define FCU_FAULT0_F4_DPos          (4U)
#define FCU_FAULT0_F4_Pos           FCU_FAULT0_F4_DPos
#define FCU_FAULT0_F4_Msk           (0x1UL << FCU_FAULT0_F4_Pos)         /* 0x00000010 */
#define FCU_FAULT0_F4               FCU_FAULT0_F4_Msk                    /* FCU Channel 4 fault bit */

#define FCU_FAULT0_F5_DPos          (5U)
#define FCU_FAULT0_F5_Pos           FCU_FAULT0_F5_DPos
#define FCU_FAULT0_F5_Msk           (0x1UL << FCU_FAULT0_F5_Pos)         /* 0x00000020 */
#define FCU_FAULT0_F5               FCU_FAULT0_F5_Msk                    /* FCU Channel 5 fault bit */

#define FCU_FAULT0_F6_DPos          (6U)
#define FCU_FAULT0_F6_Pos           FCU_FAULT0_F6_DPos
#define FCU_FAULT0_F6_Msk           (0x1UL << FCU_FAULT0_F6_Pos)         /* 0x00000040 */
#define FCU_FAULT0_F6               FCU_FAULT0_F6_Msk                    /* FCU Channel 6 fault bit */

#define FCU_FAULT0_F7_DPos          (7U)
#define FCU_FAULT0_F7_Pos           FCU_FAULT0_F7_DPos
#define FCU_FAULT0_F7_Msk           (0x1UL << FCU_FAULT0_F7_Pos)         /* 0x00000080 */
#define FCU_FAULT0_F7               FCU_FAULT0_F7_Msk                    /* FCU Channel 7 fault bit */

#define FCU_FAULT0_F8_DPos          (8U)
#define FCU_FAULT0_F8_Pos           FCU_FAULT0_F8_DPos
#define FCU_FAULT0_F8_Msk           (0x1UL << FCU_FAULT0_F8_Pos)         /* 0x00000100 */
#define FCU_FAULT0_F8               FCU_FAULT0_F8_Msk                    /* FCU Channel 8 fault bit */

#define FCU_FAULT0_F9_DPos          (9U)
#define FCU_FAULT0_F9_Pos           FCU_FAULT0_F9_DPos
#define FCU_FAULT0_F9_Msk           (0x1UL << FCU_FAULT0_F9_Pos)         /* 0x00000200 */
#define FCU_FAULT0_F9               FCU_FAULT0_F9_Msk                    /* FCU Channel 9 fault bit */

#define FCU_FAULT0_F10_DPos         (10U)
#define FCU_FAULT0_F10_Pos          FCU_FAULT0_F10_DPos
#define FCU_FAULT0_F10_Msk          (0x1UL << FCU_FAULT0_F10_Pos)         /* 0x00000400 */
#define FCU_FAULT0_F10              FCU_FAULT0_F10_Msk                    /* FCU Channel 10 fault bit */

#define FCU_FAULT0_F11_DPos         (11U)
#define FCU_FAULT0_F11_Pos          FCU_FAULT0_F11_DPos
#define FCU_FAULT0_F11_Msk          (0x1UL << FCU_FAULT0_F11_Pos)         /* 0x00000800 */
#define FCU_FAULT0_F11              FCU_FAULT0_F11_Msk                    /* FCU Channel 11 fault bit */

#define FCU_FAULT0_F12_DPos         (12U)
#define FCU_FAULT0_F12_Pos          FCU_FAULT0_F12_DPos
#define FCU_FAULT0_F12_Msk          (0x1UL << FCU_FAULT0_F12_Pos)         /* 0x00001000 */
#define FCU_FAULT0_F12              FCU_FAULT0_F12_Msk                    /* FCU Channel 12 fault bit */

#define FCU_FAULT0_F13_DPos         (13U)
#define FCU_FAULT0_F13_Pos          FCU_FAULT0_F13_DPos
#define FCU_FAULT0_F13_Msk          (0x1UL << FCU_FAULT0_F13_Pos)         /* 0x00002000 */
#define FCU_FAULT0_F13              FCU_FAULT0_F13_Msk                    /* FCU Channel 13 fault bit */

#define FCU_FAULT0_F14_DPos         (14U)
#define FCU_FAULT0_F14_Pos          FCU_FAULT0_F14_DPos
#define FCU_FAULT0_F14_Msk          (0x1UL << FCU_FAULT0_F14_Pos)         /* 0x00004000 */
#define FCU_FAULT0_F14              FCU_FAULT0_F14_Msk                    /* FCU Channel 14 fault bit */

#define FCU_FAULT0_F15_DPos         (15U)
#define FCU_FAULT0_F15_Pos          FCU_FAULT0_F15_DPos
#define FCU_FAULT0_F15_Msk          (0x1UL << FCU_FAULT0_F15_Pos)         /* 0x00008000 */
#define FCU_FAULT0_F15              FCU_FAULT0_F15_Msk                    /* FCU Channel 15 fault bit */

#define FCU_FAULT0_F16_DPos         (16U)
#define FCU_FAULT0_F16_Pos          FCU_FAULT0_F16_DPos
#define FCU_FAULT0_F16_Msk          (0x1UL << FCU_FAULT0_F16_Pos)         /* 0x00010000 */
#define FCU_FAULT0_F16              FCU_FAULT0_F16_Msk                    /* FCU Channel 16 fault bit */

#define FCU_FAULT0_F17_DPos         (17U)
#define FCU_FAULT0_F17_Pos          FCU_FAULT0_F17_DPos
#define FCU_FAULT0_F17_Msk          (0x1UL << FCU_FAULT0_F17_Pos)         /* 0x00020000 */
#define FCU_FAULT0_F17              FCU_FAULT0_F17_Msk                    /* FCU Channel 17 fault bit */

#define FCU_FAULT0_F18_DPos         (18U)
#define FCU_FAULT0_F18_Pos          FCU_FAULT0_F18_DPos
#define FCU_FAULT0_F18_Msk          (0x1UL << FCU_FAULT0_F18_Pos)         /* 0x00040000 */
#define FCU_FAULT0_F18              FCU_FAULT0_F18_Msk                    /* FCU Channel 18 fault bit */

#define FCU_FAULT0_F19_DPos         (19U)
#define FCU_FAULT0_F19_Pos          FCU_FAULT0_F19_DPos
#define FCU_FAULT0_F19_Msk          (0x1UL << FCU_FAULT0_F19_Pos)         /* 0x00080000 */
#define FCU_FAULT0_F19              FCU_FAULT0_F19_Msk                    /* FCU Channel 19 fault bit */

#define FCU_FAULT0_F20_DPos         (20U)
#define FCU_FAULT0_F20_Pos          FCU_FAULT0_F20_DPos
#define FCU_FAULT0_F20_Msk          (0x1UL << FCU_FAULT0_F20_Pos)         /* 0x00100000 */
#define FCU_FAULT0_F20              FCU_FAULT0_F20_Msk                    /* FCU Channel 20 fault bit */

#define FCU_FAULT0_F21_DPos         (21U)
#define FCU_FAULT0_F21_Pos          FCU_FAULT0_F21_DPos
#define FCU_FAULT0_F21_Msk          (0x1UL << FCU_FAULT0_F21_Pos)         /* 0x00200000 */
#define FCU_FAULT0_F21              FCU_FAULT0_F21_Msk                    /* FCU Channel 21 fault bit */

#define FCU_FAULT0_F22_DPos         (22U)
#define FCU_FAULT0_F22_Pos          FCU_FAULT0_F22_DPos
#define FCU_FAULT0_F22_Msk          (0x1UL << FCU_FAULT0_F22_Pos)         /* 0x00400000 */
#define FCU_FAULT0_F22              FCU_FAULT0_F22_Msk                    /* FCU Channel 22 fault bit */

#define FCU_FAULT0_F23_DPos         (23U)
#define FCU_FAULT0_F23_Pos          FCU_FAULT0_F23_DPos
#define FCU_FAULT0_F23_Msk          (0x1UL << FCU_FAULT0_F23_Pos)         /* 0x00800000 */
#define FCU_FAULT0_F23              FCU_FAULT0_F23_Msk                    /* FCU Channel 23 fault bit */

#define FCU_FAULT0_F24_DPos         (24U)
#define FCU_FAULT0_F24_Pos          FCU_FAULT0_F24_DPos
#define FCU_FAULT0_F24_Msk          (0x1UL << FCU_FAULT0_F24_Pos)         /* 0x01000000 */
#define FCU_FAULT0_F24              FCU_FAULT0_F24_Msk                    /* FCU Channel 24 fault bit */

#define FCU_FAULT0_F25_DPos         (25U)
#define FCU_FAULT0_F25_Pos          FCU_FAULT0_F25_DPos
#define FCU_FAULT0_F25_Msk          (0x1UL << FCU_FAULT0_F25_Pos)         /* 0x02000000 */
#define FCU_FAULT0_F25              FCU_FAULT0_F25_Msk                    /* FCU Channel 25 fault bit */

#define FCU_FAULT0_F26_DPos         (26U)
#define FCU_FAULT0_F26_Pos          FCU_FAULT0_F26_DPos
#define FCU_FAULT0_F26_Msk          (0x1UL << FCU_FAULT0_F26_Pos)         /* 0x04000000 */
#define FCU_FAULT0_F26              FCU_FAULT0_F26_Msk                    /* FCU Channel 26 fault bit */

#define FCU_FAULT0_F27_DPos         (27U)
#define FCU_FAULT0_F27_Pos          FCU_FAULT0_F27_DPos
#define FCU_FAULT0_F27_Msk          (0x1UL << FCU_FAULT0_F27_Pos)         /* 0x08000000 */
#define FCU_FAULT0_F27              FCU_FAULT0_F27_Msk                    /* FCU Channel 27 fault bit */

#define FCU_FAULT0_F28_DPos         (28U)
#define FCU_FAULT0_F28_Pos          FCU_FAULT0_F28_DPos
#define FCU_FAULT0_F28_Msk          (0x1UL << FCU_FAULT0_F28_Pos)         /* 0x10000000 */
#define FCU_FAULT0_F28              FCU_FAULT0_F28_Msk                    /* FCU Channel 28 fault bit */

#define FCU_FAULT0_F29_DPos         (29U)
#define FCU_FAULT0_F29_Pos          FCU_FAULT0_F29_DPos
#define FCU_FAULT0_F29_Msk          (0x1UL << FCU_FAULT0_F29_Pos)         /* 0x20000000 */
#define FCU_FAULT0_F29              FCU_FAULT0_F29_Msk                    /* FCU Channel 29 fault bit */

#define FCU_FAULT0_F30_DPos         (30U)
#define FCU_FAULT0_F30_Pos          FCU_FAULT0_F30_DPos
#define FCU_FAULT0_F30_Msk          (0x1UL << FCU_FAULT0_F30_Pos)         /* 0x40000000 */
#define FCU_FAULT0_F30              FCU_FAULT0_F30_Msk                    /* FCU Channel 30 fault bit */

#define FCU_FAULT0_F31_DPos         (31U)
#define FCU_FAULT0_F31_Pos          FCU_FAULT0_F31_DPos
#define FCU_FAULT0_F31_Msk          (0x1UL << FCU_FAULT0_F31_Pos)         /* 0x80000000 */
#define FCU_FAULT0_F31              FCU_FAULT0_F31_Msk                    /* FCU Channel 31 fault bit */

/******************  Bits definition for FCU_FAULT1 register  *****************/

#define FCU_FAULT1_F32_DPos         (0U)
#define FCU_FAULT1_F32_Pos          FCU_FAULT1_F32_DPos
#define FCU_FAULT1_F32_Msk          (0x1UL << FCU_FAULT1_F32_Pos)         /* 0x00000001 */
#define FCU_FAULT1_F32              FCU_FAULT1_F32_Msk                    /* FCU Channel 32 fault bit */

#define FCU_FAULT1_F33_DPos         (1U)
#define FCU_FAULT1_F33_Pos          FCU_FAULT1_F33_DPos
#define FCU_FAULT1_F33_Msk          (0x1UL << FCU_FAULT1_F33_Pos)         /* 0x00000002 */
#define FCU_FAULT1_F33              FCU_FAULT1_F33_Msk                    /* FCU Channel 33 fault bit */

#define FCU_FAULT1_F34_DPos         (2U)
#define FCU_FAULT1_F34_Pos          FCU_FAULT1_F34_DPos
#define FCU_FAULT1_F34_Msk          (0x1UL << FCU_FAULT1_F34_Pos)         /* 0x00000004 */
#define FCU_FAULT1_F34              FCU_FAULT1_F34_Msk                    /* FCU Channel 34 fault bit */

#define FCU_FAULT1_F35_DPos         (3U)
#define FCU_FAULT1_F35_Pos          FCU_FAULT1_F35_DPos
#define FCU_FAULT1_F35_Msk          (0x1UL << FCU_FAULT1_F35_Pos)         /* 0x00000008 */
#define FCU_FAULT1_F35              FCU_FAULT1_F35_Msk                    /* FCU Channel 35 fault bit */

#define FCU_FAULT1_F36_DPos         (4U)
#define FCU_FAULT1_F36_Pos          FCU_FAULT1_F36_DPos
#define FCU_FAULT1_F36_Msk          (0x1UL << FCU_FAULT1_F36_Pos)         /* 0x00000010 */
#define FCU_FAULT1_F36              FCU_FAULT1_F36_Msk                    /* FCU Channel 36 fault bit */

#define FCU_FAULT1_F37_DPos         (5U)
#define FCU_FAULT1_F37_Pos          FCU_FAULT1_F37_DPos
#define FCU_FAULT1_F37_Msk          (0x1UL << FCU_FAULT1_F37_Pos)         /* 0x00000020 */
#define FCU_FAULT1_F37              FCU_FAULT1_F37_Msk                    /* FCU Channel 37 fault bit */

#define FCU_FAULT1_F38_DPos         (6U)
#define FCU_FAULT1_F38_Pos          FCU_FAULT1_F38_DPos
#define FCU_FAULT1_F38_Msk          (0x1UL << FCU_FAULT1_F38_Pos)         /* 0x00000040 */
#define FCU_FAULT1_F38              FCU_FAULT1_F38_Msk                    /* FCU Channel 38 fault bit */

#define FCU_FAULT1_F39_DPos         (7U)
#define FCU_FAULT1_F39_Pos          FCU_FAULT1_F39_DPos
#define FCU_FAULT1_F39_Msk          (0x1UL << FCU_FAULT1_F39_Pos)         /* 0x00000080 */
#define FCU_FAULT1_F39              FCU_FAULT1_F39_Msk                    /* FCU Channel 39 fault bit */

#define FCU_FAULT1_F40_DPos         (8U)
#define FCU_FAULT1_F40_Pos          FCU_FAULT1_F40_DPos
#define FCU_FAULT1_F40_Msk          (0x1UL << FCU_FAULT1_F40_Pos)         /* 0x00000100 */
#define FCU_FAULT1_F40              FCU_FAULT1_F40_Msk                    /* FCU Channel 40 fault bit */

#define FCU_FAULT1_F41_DPos         (9U)
#define FCU_FAULT1_F41_Pos          FCU_FAULT1_F41_DPos
#define FCU_FAULT1_F41_Msk          (0x1UL << FCU_FAULT1_F41_Pos)         /* 0x00000200 */
#define FCU_FAULT1_F41              FCU_FAULT1_F41_Msk                    /* FCU Channel 41 fault bit */

/******************  Bits definition for FCU_CLEAR0 register  *****************/

#define FCU_CLEAR0_C0_DPos          (0U)
#define FCU_CLEAR0_C0_Pos           FCU_CLEAR0_C0_DPos
#define FCU_CLEAR0_C0_Msk           (0x1UL << FCU_CLEAR0_C0_Pos)         /* 0x00000001 */
#define FCU_CLEAR0_C0               FCU_CLEAR0_C0_Msk                    /* FCU Channel 0 clear bit */

#define FCU_CLEAR0_C1_DPos          (1U)
#define FCU_CLEAR0_C1_Pos           FCU_CLEAR0_C1_DPos
#define FCU_CLEAR0_C1_Msk           (0x1UL << FCU_CLEAR0_C1_Pos)         /* 0x00000002 */
#define FCU_CLEAR0_C1               FCU_CLEAR0_C1_Msk                    /* FCU Channel 1 clear bit */

#define FCU_CLEAR0_C2_DPos          (2U)
#define FCU_CLEAR0_C2_Pos           FCU_CLEAR0_C2_DPos
#define FCU_CLEAR0_C2_Msk           (0x1UL << FCU_CLEAR0_C2_Pos)         /* 0x00000004 */
#define FCU_CLEAR0_C2               FCU_CLEAR0_C2_Msk                    /* FCU Channel 2 clear bit */

#define FCU_CLEAR0_C3_DPos          (3U)
#define FCU_CLEAR0_C3_Pos           FCU_CLEAR0_C3_DPos
#define FCU_CLEAR0_C3_Msk           (0x1UL << FCU_CLEAR0_C3_Pos)         /* 0x00000008 */
#define FCU_CLEAR0_C3               FCU_CLEAR0_C3_Msk                    /* FCU Channel 3 clear bit */

#define FCU_CLEAR0_C4_DPos          (4U)
#define FCU_CLEAR0_C4_Pos           FCU_CLEAR0_C4_DPos
#define FCU_CLEAR0_C4_Msk           (0x1UL << FCU_CLEAR0_C4_Pos)         /* 0x00000010 */
#define FCU_CLEAR0_C4               FCU_CLEAR0_C4_Msk                    /* FCU Channel 4 clear bit */

#define FCU_CLEAR0_C5_DPos          (5U)
#define FCU_CLEAR0_C5_Pos           FCU_CLEAR0_C5_DPos
#define FCU_CLEAR0_C5_Msk           (0x1UL << FCU_CLEAR0_C5_Pos)         /* 0x00000020 */
#define FCU_CLEAR0_C5               FCU_CLEAR0_C5_Msk                    /* FCU Channel 5 clear bit */

#define FCU_CLEAR0_C6_DPos          (6U)
#define FCU_CLEAR0_C6_Pos           FCU_CLEAR0_C6_DPos
#define FCU_CLEAR0_C6_Msk           (0x1UL << FCU_CLEAR0_C6_Pos)         /* 0x00000040 */
#define FCU_CLEAR0_C6               FCU_CLEAR0_C6_Msk                    /* FCU Channel 6 clear bit */

#define FCU_CLEAR0_C7_DPos          (7U)
#define FCU_CLEAR0_C7_Pos           FCU_CLEAR0_C7_DPos
#define FCU_CLEAR0_C7_Msk           (0x1UL << FCU_CLEAR0_C7_Pos)         /* 0x00000080 */
#define FCU_CLEAR0_C7               FCU_CLEAR0_C7_Msk                    /* FCU Channel 7 clear bit */

#define FCU_CLEAR0_C8_DPos          (8U)
#define FCU_CLEAR0_C8_Pos           FCU_CLEAR0_C8_DPos
#define FCU_CLEAR0_C8_Msk           (0x1UL << FCU_CLEAR0_C8_Pos)         /* 0x00000100 */
#define FCU_CLEAR0_C8               FCU_CLEAR0_C8_Msk                    /* FCU Channel 8 clear bit */

#define FCU_CLEAR0_C9_DPos          (9U)
#define FCU_CLEAR0_C9_Pos           FCU_CLEAR0_C9_DPos
#define FCU_CLEAR0_C9_Msk           (0x1UL << FCU_CLEAR0_C9_Pos)         /* 0x00000200 */
#define FCU_CLEAR0_C9               FCU_CLEAR0_C9_Msk                    /* FCU Channel 9 clear bit */

#define FCU_CLEAR0_C10_DPos         (10U)
#define FCU_CLEAR0_C10_Pos          FCU_CLEAR0_C10_DPos
#define FCU_CLEAR0_C10_Msk          (0x1UL << FCU_CLEAR0_C10_Pos)         /* 0x00000400 */
#define FCU_CLEAR0_C10              FCU_CLEAR0_C10_Msk                    /* FCU Channel 10 clear bit */

#define FCU_CLEAR0_C11_DPos         (11U)
#define FCU_CLEAR0_C11_Pos          FCU_CLEAR0_C11_DPos
#define FCU_CLEAR0_C11_Msk          (0x1UL << FCU_CLEAR0_C11_Pos)         /* 0x00000800 */
#define FCU_CLEAR0_C11              FCU_CLEAR0_C11_Msk                    /* FCU Channel 11 clear bit */

#define FCU_CLEAR0_C12_DPos         (12U)
#define FCU_CLEAR0_C12_Pos          FCU_CLEAR0_C12_DPos
#define FCU_CLEAR0_C12_Msk          (0x1UL << FCU_CLEAR0_C12_Pos)         /* 0x00001000 */
#define FCU_CLEAR0_C12              FCU_CLEAR0_C12_Msk                    /* FCU Channel 12 clear bit */

#define FCU_CLEAR0_C13_DPos         (13U)
#define FCU_CLEAR0_C13_Pos          FCU_CLEAR0_C13_DPos
#define FCU_CLEAR0_C13_Msk          (0x1UL << FCU_CLEAR0_C13_Pos)         /* 0x00002000 */
#define FCU_CLEAR0_C13              FCU_CLEAR0_C13_Msk                    /* FCU Channel 13 clear bit */

#define FCU_CLEAR0_C14_DPos         (14U)
#define FCU_CLEAR0_C14_Pos          FCU_CLEAR0_C14_DPos
#define FCU_CLEAR0_C14_Msk          (0x1UL << FCU_CLEAR0_C14_Pos)         /* 0x00004000 */
#define FCU_CLEAR0_C14              FCU_CLEAR0_C14_Msk                    /* FCU Channel 14 clear bit */

#define FCU_CLEAR0_C15_DPos         (15U)
#define FCU_CLEAR0_C15_Pos          FCU_CLEAR0_C15_DPos
#define FCU_CLEAR0_C15_Msk          (0x1UL << FCU_CLEAR0_C15_Pos)         /* 0x00008000 */
#define FCU_CLEAR0_C15              FCU_CLEAR0_C15_Msk                    /* FCU Channel 15 clear bit */

#define FCU_CLEAR0_C16_DPos         (16U)
#define FCU_CLEAR0_C16_Pos          FCU_CLEAR0_C16_DPos
#define FCU_CLEAR0_C16_Msk          (0x1UL << FCU_CLEAR0_C16_Pos)         /* 0x00010000 */
#define FCU_CLEAR0_C16              FCU_CLEAR0_C16_Msk                    /* FCU Channel 16 clear bit */

#define FCU_CLEAR0_C17_DPos         (17U)
#define FCU_CLEAR0_C17_Pos          FCU_CLEAR0_C17_DPos
#define FCU_CLEAR0_C17_Msk          (0x1UL << FCU_CLEAR0_C17_Pos)         /* 0x00020000 */
#define FCU_CLEAR0_C17              FCU_CLEAR0_C17_Msk                    /* FCU Channel 17 clear bit */

#define FCU_CLEAR0_C18_DPos         (18U)
#define FCU_CLEAR0_C18_Pos          FCU_CLEAR0_C18_DPos
#define FCU_CLEAR0_C18_Msk          (0x1UL << FCU_CLEAR0_C18_Pos)         /* 0x00040000 */
#define FCU_CLEAR0_C18              FCU_CLEAR0_C18_Msk                    /* FCU Channel 18 clear bit */

#define FCU_CLEAR0_C19_DPos         (19U)
#define FCU_CLEAR0_C19_Pos          FCU_CLEAR0_C19_DPos
#define FCU_CLEAR0_C19_Msk          (0x1UL << FCU_CLEAR0_C19_Pos)         /* 0x00080000 */
#define FCU_CLEAR0_C19              FCU_CLEAR0_C19_Msk                    /* FCU Channel 19 clear bit */

#define FCU_CLEAR0_C20_DPos         (20U)
#define FCU_CLEAR0_C20_Pos          FCU_CLEAR0_C20_DPos
#define FCU_CLEAR0_C20_Msk          (0x1UL << FCU_CLEAR0_C20_Pos)         /* 0x00100000 */
#define FCU_CLEAR0_C20              FCU_CLEAR0_C20_Msk                    /* FCU Channel 20 clear bit */

#define FCU_CLEAR0_C21_DPos         (21U)
#define FCU_CLEAR0_C21_Pos          FCU_CLEAR0_C21_DPos
#define FCU_CLEAR0_C21_Msk          (0x1UL << FCU_CLEAR0_C21_Pos)         /* 0x00200000 */
#define FCU_CLEAR0_C21              FCU_CLEAR0_C21_Msk                    /* FCU Channel 21 clear bit */

#define FCU_CLEAR0_C22_DPos         (22U)
#define FCU_CLEAR0_C22_Pos          FCU_CLEAR0_C22_DPos
#define FCU_CLEAR0_C22_Msk          (0x1UL << FCU_CLEAR0_C22_Pos)         /* 0x00400000 */
#define FCU_CLEAR0_C22              FCU_CLEAR0_C22_Msk                    /* FCU Channel 22 clear bit */

#define FCU_CLEAR0_C23_DPos         (23U)
#define FCU_CLEAR0_C23_Pos          FCU_CLEAR0_C23_DPos
#define FCU_CLEAR0_C23_Msk          (0x1UL << FCU_CLEAR0_C23_Pos)         /* 0x00800000 */
#define FCU_CLEAR0_C23              FCU_CLEAR0_C23_Msk                    /* FCU Channel 23 clear bit */

#define FCU_CLEAR0_C24_DPos         (24U)
#define FCU_CLEAR0_C24_Pos          FCU_CLEAR0_C24_DPos
#define FCU_CLEAR0_C24_Msk          (0x1UL << FCU_CLEAR0_C24_Pos)         /* 0x01000000 */
#define FCU_CLEAR0_C24              FCU_CLEAR0_C24_Msk                    /* FCU Channel 24 clear bit */

#define FCU_CLEAR0_C25_DPos         (25U)
#define FCU_CLEAR0_C25_Pos          FCU_CLEAR0_C25_DPos
#define FCU_CLEAR0_C25_Msk          (0x1UL << FCU_CLEAR0_C25_Pos)         /* 0x02000000 */
#define FCU_CLEAR0_C25              FCU_CLEAR0_C25_Msk                    /* FCU Channel 25 clear bit */

#define FCU_CLEAR0_C26_DPos         (26U)
#define FCU_CLEAR0_C26_Pos          FCU_CLEAR0_C26_DPos
#define FCU_CLEAR0_C26_Msk          (0x1UL << FCU_CLEAR0_C26_Pos)         /* 0x04000000 */
#define FCU_CLEAR0_C26              FCU_CLEAR0_C26_Msk                    /* FCU Channel 26 clear bit */

#define FCU_CLEAR0_C27_DPos         (27U)
#define FCU_CLEAR0_C27_Pos          FCU_CLEAR0_C27_DPos
#define FCU_CLEAR0_C27_Msk          (0x1UL << FCU_CLEAR0_C27_Pos)         /* 0x08000000 */
#define FCU_CLEAR0_C27              FCU_CLEAR0_C27_Msk                    /* FCU Channel 27 clear bit */

#define FCU_CLEAR0_C28_DPos         (28U)
#define FCU_CLEAR0_C28_Pos          FCU_CLEAR0_C28_DPos
#define FCU_CLEAR0_C28_Msk          (0x1UL << FCU_CLEAR0_C28_Pos)         /* 0x10000000 */
#define FCU_CLEAR0_C28              FCU_CLEAR0_C28_Msk                    /* FCU Channel 28 clear bit */

#define FCU_CLEAR0_C29_DPos         (29U)
#define FCU_CLEAR0_C29_Pos          FCU_CLEAR0_C29_DPos
#define FCU_CLEAR0_C29_Msk          (0x1UL << FCU_CLEAR0_C29_Pos)         /* 0x20000000 */
#define FCU_CLEAR0_C29              FCU_CLEAR0_C29_Msk                    /* FCU Channel 29 clear bit */

#define FCU_CLEAR0_C30_DPos         (30U)
#define FCU_CLEAR0_C30_Pos          FCU_CLEAR0_C30_DPos
#define FCU_CLEAR0_C30_Msk          (0x1UL << FCU_CLEAR0_C30_Pos)         /* 0x40000000 */
#define FCU_CLEAR0_C30              FCU_CLEAR0_C30_Msk                    /* FCU Channel 30 clear bit */

#define FCU_CLEAR0_C31_DPos         (31U)
#define FCU_CLEAR0_C31_Pos          FCU_CLEAR0_C31_DPos
#define FCU_CLEAR0_C31_Msk          (0x1UL << FCU_CLEAR0_C31_Pos)         /* 0x80000000 */
#define FCU_CLEAR0_C31              FCU_CLEAR0_C31_Msk                    /* FCU Channel 31 clear bit */

/******************  Bits definition for FCU_CLEAR1 register  *****************/

#define FCU_CLEAR1_C32_DPos         (0U)
#define FCU_CLEAR1_C32_Pos          FCU_CLEAR1_C32_DPos
#define FCU_CLEAR1_C32_Msk          (0x1UL << FCU_CLEAR1_C32_Pos)         /* 0x00000001 */
#define FCU_CLEAR1_C32              FCU_CLEAR1_C32_Msk                    /* FCU Channel 32 clear bit */

#define FCU_CLEAR1_C33_DPos         (1U)
#define FCU_CLEAR1_C33_Pos          FCU_CLEAR1_C33_DPos
#define FCU_CLEAR1_C33_Msk          (0x1UL << FCU_CLEAR1_C33_Pos)         /* 0x00000002 */
#define FCU_CLEAR1_C33              FCU_CLEAR1_C33_Msk                    /* FCU Channel 33 clear bit */

#define FCU_CLEAR1_C34_DPos         (2U)
#define FCU_CLEAR1_C34_Pos          FCU_CLEAR1_C34_DPos
#define FCU_CLEAR1_C34_Msk          (0x1UL << FCU_CLEAR1_C34_Pos)         /* 0x00000004 */
#define FCU_CLEAR1_C34              FCU_CLEAR1_C34_Msk                    /* FCU Channel 34 clear bit */

#define FCU_CLEAR1_C35_DPos         (3U)
#define FCU_CLEAR1_C35_Pos          FCU_CLEAR1_C35_DPos
#define FCU_CLEAR1_C35_Msk          (0x1UL << FCU_CLEAR1_C35_Pos)         /* 0x00000008 */
#define FCU_CLEAR1_C35              FCU_CLEAR1_C35_Msk                    /* FCU Channel 35 clear bit */

#define FCU_CLEAR1_C36_DPos         (4U)
#define FCU_CLEAR1_C36_Pos          FCU_CLEAR1_C36_DPos
#define FCU_CLEAR1_C36_Msk          (0x1UL << FCU_CLEAR1_C36_Pos)         /* 0x00000010 */
#define FCU_CLEAR1_C36              FCU_CLEAR1_C36_Msk                    /* FCU Channel 36 clear bit */

#define FCU_CLEAR1_C37_DPos         (5U)
#define FCU_CLEAR1_C37_Pos          FCU_CLEAR1_C37_DPos
#define FCU_CLEAR1_C37_Msk          (0x1UL << FCU_CLEAR1_C37_Pos)         /* 0x00000020 */
#define FCU_CLEAR1_C37              FCU_CLEAR1_C37_Msk                    /* FCU Channel 37 clear bit */

#define FCU_CLEAR1_C38_DPos         (6U)
#define FCU_CLEAR1_C38_Pos          FCU_CLEAR1_C38_DPos
#define FCU_CLEAR1_C38_Msk          (0x1UL << FCU_CLEAR1_C38_Pos)         /* 0x00000040 */
#define FCU_CLEAR1_C38              FCU_CLEAR1_C38_Msk                    /* FCU Channel 38 clear bit */

#define FCU_CLEAR1_C39_DPos         (7U)
#define FCU_CLEAR1_C39_Pos          FCU_CLEAR1_C39_DPos
#define FCU_CLEAR1_C39_Msk          (0x1UL << FCU_CLEAR1_C39_Pos)         /* 0x00000080 */
#define FCU_CLEAR1_C39              FCU_CLEAR1_C39_Msk                    /* FCU Channel 39 clear bit */

#define FCU_CLEAR1_C40_DPos         (8U)
#define FCU_CLEAR1_C40_Pos          FCU_CLEAR1_C40_DPos
#define FCU_CLEAR1_C40_Msk          (0x1UL << FCU_CLEAR1_C40_Pos)         /* 0x00000100 */
#define FCU_CLEAR1_C40              FCU_CLEAR1_C40_Msk                    /* FCU Channel 40 clear bit */

#define FCU_CLEAR1_C41_DPos         (9U)
#define FCU_CLEAR1_C41_Pos          FCU_CLEAR1_C41_DPos
#define FCU_CLEAR1_C41_Msk          (0x1UL << FCU_CLEAR1_C41_Pos)         /* 0x00000200 */
#define FCU_CLEAR1_C41              FCU_CLEAR1_C41_Msk                    /* FCU Channel 41 clear bit */
/******************  Bits definition for FCU_OCLR register  *****************/

#define FCU_OCLR_ECCC_DPos          (0U)
#define FCU_OCLR_ECCC_Pos           FCU_OCLR_ECCC_DPos
#define FCU_OCLR_ECCC_Msk           (0x1UL << FCU_OCLR_ECCC_Pos)          /* 0x00000001 */
#define FCU_OCLR_ECCC               FCU_OCLR_ECCC_Msk                     /* Bus timeout count fault clear bit */

#define FCU_OCLR_BTOC_DPos          (1U)
#define FCU_OCLR_BTOC_Pos           FCU_OCLR_BTOC_DPos
#define FCU_OCLR_BTOC_Msk           (0x1UL << FCU_OCLR_BTOC_Pos)          /* 0x00000002 */
#define FCU_OCLR_BTOC               FCU_OCLR_BTOC_Msk                     /* ECC controller fault clear bit */

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
