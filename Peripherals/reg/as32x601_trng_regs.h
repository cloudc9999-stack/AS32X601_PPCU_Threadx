/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_trng_reg.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/9
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/9      1.0     build this module
 * Description:     This file contains all the register correlation defines for the TRNG firmware library.
 */

#ifndef AS32X601_TRNG_REGS_H
#define AS32X601_TRNG_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "as32x601.h"
#include "as32x601_addrmap.h"

/*
 * @brief General Purpose I/O registers structure
 */
typedef struct 
{
	__IO uint32_t CTRL;						/* TRNG Control Register,							Address offset: 0x00 */
	__IO uint32_t RESERVED0[3];				/* TRNG Reserved,									Address offset: 0x04 - 0x0C */
	__IO uint32_t IE;						/* TRNG Interrupt Enable Register,					Address offset: 0x10 */
	__IO uint32_t ISTAT;					/* TRNG Interrupt Status Register,					Address offset: 0x14 */
	__IO uint32_t RESERVED1[3];				/* TRNG Reserved,									Address offset: 0x18 - 0x20 */
	__I  uint32_t RAND0;					/* TRNG Random Number Register 0,					Address offset: 0x24 */
	__I  uint32_t RAND1;					/* TRNG Random Number Register 1,					Address offset: 0x28 */
	__I  uint32_t RAND2;					/* TRNG Random Number Register 2,					Address offset: 0x2C */
	__I  uint32_t RAND3;					/* TRNG Random Number Register 3,					Address offset: 0x30 */
}TRNG_TypeDef;

/*
 * @addtogroup TRNG Peripheral declaration
 */
#define TRNG			((TRNG_TypeDef*)TRNG_BASE)

/******************  Bit definition for TRNG_CTRL register  *******************/
#define TRNG_CTRL_CMD_DPos       			(0U)
#define TRNG_CTRL_CMD_Pos         			TRNG_CTRL_CMD_DPos
#define TRNG_CTRL_CMD_Msk         			(0xFUL << TRNG_CTRL_CMD_Pos)			/* 0x0000000F */
#define TRNG_CTRL_CMD             			TRNG_CTRL_CMD_Msk						/* TRNG Execute A Command */
#define TRNG_CTRL_CMD_0						(0x1UL << TRNG_CTRL_CMD_Pos)			/* 0x00000001 */
#define TRNG_CTRL_CMD_1						(0x2UL << TRNG_CTRL_CMD_Pos)			/* 0x00000002 */
#define TRNG_CTRL_CMD_2						(0x4UL << TRNG_CTRL_CMD_Pos)			/* 0x00000004 */
#define TRNG_CTRL_CMD_3						(0x8UL << TRNG_CTRL_CMD_Pos)			/* 0x00000008 */		

/******************  Bit definition for TRNG_IE register  *******************/
#define TRNG_IE_ZEROIZED_DPos     			(0U)
#define TRNG_IE_ZEROIZED_Pos      			TRNG_IE_ZEROIZED_DPos
#define TRNG_IE_ZEROIZED_Msk      			(0x1UL << TRNG_IE_ZEROIZED_Pos)			/* 0x00000001 */
#define TRNG_IE_ZEROIZED          			TRNG_IE_ZEROIZED_Msk					/* TRNG Zeroized Interrupt Enable */

#define TRNG_IE_KAT_COMPLETED_DPos      	(1U)
#define TRNG_IE_KAT_COMPLETED_Pos      		TRNG_IE_KAT_COMPLETED_DPos
#define TRNG_IE_KAT_COMPLETED_Msk      		(0x1UL << TRNG_IE_KAT_COMPLETED_Pos)	/* 0x00000002 */
#define TRNG_IE_KAT_COMPLETED     			TRNG_IE_KAT_COMPLETED_Msk				/* TRNG KAT Completed Interrupt Enable */

#define TRNG_IE_NOISE_RDY_DPos       		(2U)
#define TRNG_IE_NOISE_RDY_Pos      			TRNG_IE_NOISE_RDY_DPos
#define TRNG_IE_NOISE_RDY_Msk      			(0x1UL << TRNG_IE_NOISE_RDY_Pos)		/* 0x00000004 */
#define TRNG_IE_NOISE_RDY     				TRNG_IE_NOISE_RDY_Msk					/* TRNG Noise Ready Interrupt Enable */

#define TRNG_IE_ALARMS_DPos       			(3U)
#define TRNG_IE_ALARMS_Pos      			TRNG_IE_ALARMS_DPos
#define TRNG_IE_ALARMS_Msk      			(0x1UL << TRNG_IE_ALARMS_Pos)			/* 0x00000008 */
#define TRNG_IE_ALARMS     					TRNG_IE_ALARMS_Msk						/* TRNG Alarms Interrupt Enable */

#define TRNG_IE_DONE_DPos       			(4U)
#define TRNG_IE_DONE_Pos      				TRNG_IE_DONE_DPos
#define TRNG_IE_DONE_Msk      				(0x1UL << TRNG_IE_DONE_Pos)				/* 0x00000010 */
#define TRNG_IE_DONE     					TRNG_IE_DONE_Msk						/*TRNG Done Interrupt Enable */

#define TRNG_IE_GLBL_DPos       			(31U)
#define TRNG_IE_GLBL_Pos      				TRNG_IE_GLBL_DPos
#define TRNG_IE_GLBL_Msk      				(0x1UL << TRNG_IE_GLBL_Pos)				/* 0x80000000 */
#define TRNG_IE_GLBL     					TRNG_IE_GLBL_Msk						/* TRNG Global Interrupt Enable */

/******************  Bit definition for TRNG_ISTAT register  *******************/
#define TRNG_ISTAT_ZEROIZED_DPos       		(0U)
#define TRNG_ISTAT_ZEROIZED_Pos       		TRNG_ISTAT_ZEROIZED_DPos
#define TRNG_ISTAT_ZEROIZED_Msk       		(0x1UL << TRNG_ISTAT_ZEROIZED_Pos)		/* 0x00000001 */
#define TRNG_ISTAT_ZEROIZED     			TRNG_ISTAT_ZEROIZED_Msk					/* TRNG Zeroized Interrupt Status */

#define TRNG_ISTAT_KAT_COMPLETED_DPos      	(1U)
#define TRNG_ISTAT_KAT_COMPLETED_Pos      	TRNG_ISTAT_KAT_COMPLETED_DPos
#define TRNG_ISTAT_KAT_COMPLETED_Msk      	(0x1UL << TRNG_ISTAT_KAT_COMPLETED_Pos)	/* 0x00000002 */
#define TRNG_ISTAT_KAT_COMPLETED     		TRNG_ISTAT_KAT_COMPLETED_Msk			/* TRNG KAT Completed Interrupt Status */

#define TRNG_ISTAT_NOISE_RDY_DPos       	(2U)
#define TRNG_ISTAT_NOISE_RDY_Pos      		TRNG_ISTAT_NOISE_RDY_DPos
#define TRNG_ISTAT_NOISE_RDY_Msk      		(0x1UL << TRNG_ISTAT_NOISE_RDY_Pos)		/* 0x00000004 */
#define TRNG_ISTAT_NOISE_RDY     			TRNG_ISTAT_NOISE_RDY_Msk				/* TRNG Noise Ready Interrupt Status */

#define TRNG_ISTAT_ALARMS_DPos       		(3U)
#define TRNG_ISTAT_ALARMS_Pos      			TRNG_ISTAT_ALARMS_DPos
#define TRNG_ISTAT_ALARMS_Msk      			(0x1UL << TRNG_ISTAT_ALARMS_Pos)		/* 0x00000008 */
#define TRNG_ISTAT_ALARMS     				TRNG_ISTAT_ALARMS_Msk					/* TRNG Alarms Interrupt Status */

#define TRNG_ISTAT_DONE_DPos       			(4U)
#define TRNG_ISTAT_DONE_Pos      			TRNG_ISTAT_DONE_DPos					
#define TRNG_ISTAT_DONE_Msk      			(0x1UL << TRNG_ISTAT_DONE_Pos)			/* 0x00000010 */
#define TRNG_ISTAT_DONE     				TRNG_ISTAT_DONE_Msk						/* TRNG Done Interrupt Status */

/******************  Bit definition for TRNG_RAND0 register  *******************/
#define TRNG_RAND0_RAND_DPos      			(0U)
#define TRNG_RAND0_RAND_Pos      			TRNG_RAND0_RAND_DPos
#define TRNG_RAND0_RAND_Msk      			(0xFFFFFFFFUL << TRNG_RAND0_RAND_Pos)	/* 0xFFFFFFFF */
#define TRNG_RAND0_RAND     				TRNG_RAND0_RAND_Msk						/* TRNG Random Number Register 0 */
#define TRNG_RAND0_RAND_0					(0x1UL << TRNG_RAND0_RAND_Pos)			/* 0x00000001 */
#define TRNG_RAND0_RAND_1					(0x2UL << TRNG_RAND0_RAND_Pos)			/* 0x00000002 */
#define TRNG_RAND0_RAND_2					(0x4UL << TRNG_RAND0_RAND_Pos)			/* 0x00000004 */
#define TRNG_RAND0_RAND_3					(0x8UL << TRNG_RAND0_RAND_Pos)			/* 0x00000008 */
#define TRNG_RAND0_RAND_4					(0x10UL << TRNG_RAND0_RAND_Pos)			/* 0x00000010 */
#define TRNG_RAND0_RAND_5					(0x20UL << TRNG_RAND0_RAND_Pos)			/* 0x00000020 */
#define TRNG_RAND0_RAND_6					(0x40UL << TRNG_RAND0_RAND_Pos)			/* 0x00000040 */
#define TRNG_RAND0_RAND_7					(0x80UL << TRNG_RAND0_RAND_Pos)			/* 0x00000080 */
#define TRNG_RAND0_RAND_8					(0x100UL << TRNG_RAND0_RAND_Pos)		/* 0x00000100 */
#define TRNG_RAND0_RAND_9					(0x200UL << TRNG_RAND0_RAND_Pos)		/* 0x00000200 */
#define TRNG_RAND0_RAND_10					(0x400UL << TRNG_RAND0_RAND_Pos)		/* 0x00000400 */
#define TRNG_RAND0_RAND_11					(0x800UL << TRNG_RAND0_RAND_Pos)		/* 0x00000800 */
#define TRNG_RAND0_RAND_12					(0x1000UL << TRNG_RAND0_RAND_Pos)		/* 0x00001000 */
#define TRNG_RAND0_RAND_13					(0x2000UL << TRNG_RAND0_RAND_Pos)		/* 0x00002000 */
#define TRNG_RAND0_RAND_14					(0x4000UL << TRNG_RAND0_RAND_Pos)		/* 0x00004000 */
#define TRNG_RAND0_RAND_15					(0x8000UL << TRNG_RAND0_RAND_Pos)		/* 0x00008000 */
#define TRNG_RAND0_RAND_16					(0x10000UL << TRNG_RAND0_RAND_Pos)		/* 0x00010000 */
#define TRNG_RAND0_RAND_17					(0x20000UL << TRNG_RAND0_RAND_Pos)		/* 0x00020000 */
#define TRNG_RAND0_RAND_18					(0x40000UL << TRNG_RAND0_RAND_Pos)		/* 0x00040000 */
#define TRNG_RAND0_RAND_19					(0x80000UL << TRNG_RAND0_RAND_Pos)		/* 0x00080000 */
#define TRNG_RAND0_RAND_20					(0x100000UL << TRNG_RAND0_RAND_Pos)		/* 0x00100000 */
#define TRNG_RAND0_RAND_21					(0x200000UL << TRNG_RAND0_RAND_Pos)		/* 0x00200000 */
#define TRNG_RAND0_RAND_22					(0x400000UL << TRNG_RAND0_RAND_Pos)		/* 0x00400000 */
#define TRNG_RAND0_RAND_23					(0x800000UL << TRNG_RAND0_RAND_Pos)		/* 0x00800000 */
#define TRNG_RAND0_RAND_24					(0x1000000UL << TRNG_RAND0_RAND_Pos)	/* 0x01000000 */
#define TRNG_RAND0_RAND_25					(0x2000000UL << TRNG_RAND0_RAND_Pos)	/* 0x02000000 */
#define TRNG_RAND0_RAND_26					(0x4000000UL << TRNG_RAND0_RAND_Pos)	/* 0x04000000 */
#define TRNG_RAND0_RAND_27					(0x8000000UL << TRNG_RAND0_RAND_Pos)	/* 0x08000000 */
#define TRNG_RAND0_RAND_28					(0x10000000UL << TRNG_RAND0_RAND_Pos)	/* 0x10000000 */
#define TRNG_RAND0_RAND_29					(0x20000000UL << TRNG_RAND0_RAND_Pos)	/* 0x20000000 */
#define TRNG_RAND0_RAND_30					(0x40000000UL << TRNG_RAND0_RAND_Pos)	/* 0x40000000 */
#define TRNG_RAND0_RAND_31					(0x80000000UL << TRNG_RAND0_RAND_Pos)	/* 0x80000000 */

/******************  Bit definition for TRNG_RAND1 register  *******************/
#define TRNG_RAND1_RAND_DPos      			(0U)
#define TRNG_RAND1_RAND_Pos      			TRNG_RAND1_RAND_DPos
#define TRNG_RAND1_RAND_Msk      			(0xFFFFFFFFUL << TRNG_RAND1_RAND_Pos)	/* 0xFFFFFFFF */
#define TRNG_RAND1_RAND     				TRNG_RAND1_RAND_Msk						/* TRNG Random Number Register 1 */
#define TRNG_RAND1_RAND_0					(0x1UL << TRNG_RAND1_RAND_Pos)			/* 0x00000001 */
#define TRNG_RAND1_RAND_1					(0x2UL << TRNG_RAND1_RAND_Pos)			/* 0x00000002 */
#define TRNG_RAND1_RAND_2					(0x4UL << TRNG_RAND1_RAND_Pos)			/* 0x00000004 */
#define TRNG_RAND1_RAND_3					(0x8UL << TRNG_RAND1_RAND_Pos)			/* 0x00000008 */
#define TRNG_RAND1_RAND_4					(0x10UL << TRNG_RAND1_RAND_Pos)			/* 0x00000010 */
#define TRNG_RAND1_RAND_5					(0x20UL << TRNG_RAND1_RAND_Pos)			/* 0x00000020 */
#define TRNG_RAND1_RAND_6					(0x40UL << TRNG_RAND1_RAND_Pos)			/* 0x00000040 */
#define TRNG_RAND1_RAND_7					(0x80UL << TRNG_RAND1_RAND_Pos)			/* 0x00000080 */
#define TRNG_RAND1_RAND_8					(0x100UL << TRNG_RAND1_RAND_Pos)		/* 0x00000100 */
#define TRNG_RAND1_RAND_9					(0x200UL << TRNG_RAND1_RAND_Pos)		/* 0x00000200 */
#define TRNG_RAND1_RAND_10					(0x400UL << TRNG_RAND1_RAND_Pos)		/* 0x00000400 */
#define TRNG_RAND1_RAND_11					(0x800UL << TRNG_RAND1_RAND_Pos)		/* 0x00000800 */
#define TRNG_RAND1_RAND_12					(0x1000UL << TRNG_RAND1_RAND_Pos)		/* 0x00001000 */
#define TRNG_RAND1_RAND_13					(0x2000UL << TRNG_RAND1_RAND_Pos)		/* 0x00002000 */
#define TRNG_RAND1_RAND_14					(0x4000UL << TRNG_RAND1_RAND_Pos)		/* 0x00004000 */
#define TRNG_RAND1_RAND_15					(0x8000UL << TRNG_RAND1_RAND_Pos)		/* 0x00008000 */
#define TRNG_RAND1_RAND_16					(0x10000UL << TRNG_RAND1_RAND_Pos)		/* 0x00010000 */
#define TRNG_RAND1_RAND_17					(0x20000UL << TRNG_RAND1_RAND_Pos)		/* 0x00020000 */
#define TRNG_RAND1_RAND_18					(0x40000UL << TRNG_RAND1_RAND_Pos)		/* 0x00040000 */
#define TRNG_RAND1_RAND_19					(0x80000UL << TRNG_RAND1_RAND_Pos)		/* 0x00080000 */
#define TRNG_RAND1_RAND_20					(0x100000UL << TRNG_RAND1_RAND_Pos)		/* 0x00100000 */
#define TRNG_RAND1_RAND_21					(0x200000UL << TRNG_RAND1_RAND_Pos)		/* 0x00200000 */
#define TRNG_RAND1_RAND_22					(0x400000UL << TRNG_RAND1_RAND_Pos)		/* 0x00400000 */
#define TRNG_RAND1_RAND_23					(0x800000UL << TRNG_RAND1_RAND_Pos)		/* 0x00800000 */
#define TRNG_RAND1_RAND_24					(0x1000000UL << TRNG_RAND1_RAND_Pos)	/* 0x01000000 */
#define TRNG_RAND1_RAND_25					(0x2000000UL << TRNG_RAND1_RAND_Pos)	/* 0x02000000 */
#define TRNG_RAND1_RAND_26					(0x4000000UL << TRNG_RAND1_RAND_Pos)	/* 0x04000000 */
#define TRNG_RAND1_RAND_27					(0x8000000UL << TRNG_RAND1_RAND_Pos)	/* 0x08000000 */
#define TRNG_RAND1_RAND_28					(0x10000000UL << TRNG_RAND1_RAND_Pos)	/* 0x10000000 */
#define TRNG_RAND1_RAND_29					(0x20000000UL << TRNG_RAND1_RAND_Pos)	/* 0x20000000 */
#define TRNG_RAND1_RAND_30					(0x40000000UL << TRNG_RAND1_RAND_Pos)	/* 0x40000000 */
#define TRNG_RAND1_RAND_31					(0x80000000UL << TRNG_RAND1_RAND_Pos)	/* 0x80000000 */

/******************  Bit definition for TRNG_RAND2 register  *******************/
#define TRNG_RAND2_RAND_DPos      			(0U)
#define TRNG_RAND2_RAND_Pos      			TRNG_RAND2_RAND_DPos
#define TRNG_RAND2_RAND_Msk      			(0xFFFFFFFFUL << TRNG_RAND2_RAND_Pos)	/* 0xFFFFFFFF */
#define TRNG_RAND2_RAND     				TRNG_RAND2_RAND_Msk						/* TRNG Random Number Register 2 */
#define TRNG_RAND2_RAND_0					(0x1UL << TRNG_RAND2_RAND_Pos)			/* 0x00000001 */
#define TRNG_RAND2_RAND_1					(0x2UL << TRNG_RAND2_RAND_Pos)			/* 0x00000002 */
#define TRNG_RAND2_RAND_2					(0x4UL << TRNG_RAND2_RAND_Pos)			/* 0x00000004 */
#define TRNG_RAND2_RAND_3					(0x8UL << TRNG_RAND2_RAND_Pos)			/* 0x00000008 */
#define TRNG_RAND2_RAND_4					(0x10UL << TRNG_RAND2_RAND_Pos)			/* 0x00000010 */
#define TRNG_RAND2_RAND_5					(0x20UL << TRNG_RAND2_RAND_Pos)			/* 0x00000020 */
#define TRNG_RAND2_RAND_6					(0x40UL << TRNG_RAND2_RAND_Pos)			/* 0x00000040 */
#define TRNG_RAND2_RAND_7					(0x80UL << TRNG_RAND2_RAND_Pos)			/* 0x00000080 */
#define TRNG_RAND2_RAND_8					(0x100UL << TRNG_RAND2_RAND_Pos)		/* 0x00000100 */
#define TRNG_RAND2_RAND_9					(0x200UL << TRNG_RAND2_RAND_Pos)		/* 0x00000200 */
#define TRNG_RAND2_RAND_10					(0x400UL << TRNG_RAND2_RAND_Pos)		/* 0x00000400 */
#define TRNG_RAND2_RAND_11					(0x800UL << TRNG_RAND2_RAND_Pos)		/* 0x00000800 */
#define TRNG_RAND2_RAND_12					(0x1000UL << TRNG_RAND2_RAND_Pos)		/* 0x00001000 */
#define TRNG_RAND2_RAND_13					(0x2000UL << TRNG_RAND2_RAND_Pos)		/* 0x00002000 */
#define TRNG_RAND2_RAND_14					(0x4000UL << TRNG_RAND2_RAND_Pos)		/* 0x00004000 */
#define TRNG_RAND2_RAND_15					(0x8000UL << TRNG_RAND2_RAND_Pos)		/* 0x00008000 */
#define TRNG_RAND2_RAND_16					(0x10000UL << TRNG_RAND2_RAND_Pos)		/* 0x00010000 */
#define TRNG_RAND2_RAND_17					(0x20000UL << TRNG_RAND2_RAND_Pos)		/* 0x00020000 */
#define TRNG_RAND2_RAND_18					(0x40000UL << TRNG_RAND2_RAND_Pos)		/* 0x00040000 */
#define TRNG_RAND2_RAND_19					(0x80000UL << TRNG_RAND2_RAND_Pos)		/* 0x00080000 */
#define TRNG_RAND2_RAND_20					(0x100000UL << TRNG_RAND2_RAND_Pos)		/* 0x00100000 */
#define TRNG_RAND2_RAND_21					(0x200000UL << TRNG_RAND2_RAND_Pos)		/* 0x00200000 */
#define TRNG_RAND2_RAND_22					(0x400000UL << TRNG_RAND2_RAND_Pos)		/* 0x00400000 */
#define TRNG_RAND2_RAND_23					(0x800000UL << TRNG_RAND2_RAND_Pos)		/* 0x00800000 */
#define TRNG_RAND2_RAND_24					(0x1000000UL << TRNG_RAND2_RAND_Pos)	/* 0x01000000 */
#define TRNG_RAND2_RAND_25					(0x2000000UL << TRNG_RAND2_RAND_Pos)	/* 0x02000000 */
#define TRNG_RAND2_RAND_26					(0x4000000UL << TRNG_RAND2_RAND_Pos)	/* 0x04000000 */
#define TRNG_RAND2_RAND_27					(0x8000000UL << TRNG_RAND2_RAND_Pos)	/* 0x08000000 */
#define TRNG_RAND2_RAND_28					(0x10000000UL << TRNG_RAND2_RAND_Pos)	/* 0x10000000 */
#define TRNG_RAND2_RAND_29					(0x20000000UL << TRNG_RAND2_RAND_Pos)	/* 0x20000000 */
#define TRNG_RAND2_RAND_30					(0x40000000UL << TRNG_RAND2_RAND_Pos)	/* 0x40000000 */
#define TRNG_RAND2_RAND_31					(0x80000000UL << TRNG_RAND2_RAND_Pos)	/* 0x80000000 */

/******************  Bit definition for TRNG_RAND3 register  *******************/
#define TRNG_RAND3_RAND_DPos      			(0U)
#define TRNG_RAND3_RAND_Pos      			TRNG_RAND3_RAND_DPos
#define TRNG_RAND3_RAND_Msk      			(0xFFFFFFFFUL << TRNG_RAND3_RAND_Pos)	/* 0xFFFFFFFF */
#define TRNG_RAND3_RAND     				TRNG_RAND3_RAND_Msk						/* TRNG Random Number Register 3 */
#define TRNG_RAND3_RAND_0					(0x1UL << TRNG_RAND3_RAND_Pos)			/* 0x00000001 */
#define TRNG_RAND3_RAND_1					(0x2UL << TRNG_RAND3_RAND_Pos)			/* 0x00000002 */
#define TRNG_RAND3_RAND_2					(0x4UL << TRNG_RAND3_RAND_Pos)			/* 0x00000004 */
#define TRNG_RAND3_RAND_3					(0x8UL << TRNG_RAND3_RAND_Pos)			/* 0x00000008 */
#define TRNG_RAND3_RAND_4					(0x10UL << TRNG_RAND3_RAND_Pos)			/* 0x00000010 */
#define TRNG_RAND3_RAND_5					(0x20UL << TRNG_RAND3_RAND_Pos)			/* 0x00000020 */
#define TRNG_RAND3_RAND_6					(0x40UL << TRNG_RAND3_RAND_Pos)			/* 0x00000040 */
#define TRNG_RAND3_RAND_7					(0x80UL << TRNG_RAND3_RAND_Pos)			/* 0x00000080 */
#define TRNG_RAND3_RAND_8					(0x100UL << TRNG_RAND3_RAND_Pos)		/* 0x00000100 */
#define TRNG_RAND3_RAND_9					(0x200UL << TRNG_RAND3_RAND_Pos)		/* 0x00000200 */
#define TRNG_RAND3_RAND_10					(0x400UL << TRNG_RAND3_RAND_Pos)		/* 0x00000400 */
#define TRNG_RAND3_RAND_11					(0x800UL << TRNG_RAND3_RAND_Pos)		/* 0x00000800 */
#define TRNG_RAND3_RAND_12					(0x1000UL << TRNG_RAND3_RAND_Pos)		/* 0x00001000 */
#define TRNG_RAND3_RAND_13					(0x2000UL << TRNG_RAND3_RAND_Pos)		/* 0x00002000 */
#define TRNG_RAND3_RAND_14					(0x4000UL << TRNG_RAND3_RAND_Pos)		/* 0x00004000 */
#define TRNG_RAND3_RAND_15					(0x8000UL << TRNG_RAND3_RAND_Pos)		/* 0x00008000 */
#define TRNG_RAND3_RAND_16					(0x10000UL << TRNG_RAND3_RAND_Pos)		/* 0x00010000 */
#define TRNG_RAND3_RAND_17					(0x20000UL << TRNG_RAND3_RAND_Pos)		/* 0x00020000 */
#define TRNG_RAND3_RAND_18					(0x40000UL << TRNG_RAND3_RAND_Pos)		/* 0x00040000 */
#define TRNG_RAND3_RAND_19					(0x80000UL << TRNG_RAND3_RAND_Pos)		/* 0x00080000 */
#define TRNG_RAND3_RAND_20					(0x100000UL << TRNG_RAND3_RAND_Pos)		/* 0x00100000 */
#define TRNG_RAND3_RAND_21					(0x200000UL << TRNG_RAND3_RAND_Pos)		/* 0x00200000 */
#define TRNG_RAND3_RAND_22					(0x400000UL << TRNG_RAND3_RAND_Pos)		/* 0x00400000 */
#define TRNG_RAND3_RAND_23					(0x800000UL << TRNG_RAND3_RAND_Pos)		/* 0x00800000 */
#define TRNG_RAND3_RAND_24					(0x1000000UL << TRNG_RAND3_RAND_Pos)	/* 0x01000000 */
#define TRNG_RAND3_RAND_25					(0x2000000UL << TRNG_RAND3_RAND_Pos)	/* 0x02000000 */
#define TRNG_RAND3_RAND_26					(0x4000000UL << TRNG_RAND3_RAND_Pos)	/* 0x04000000 */
#define TRNG_RAND3_RAND_27					(0x8000000UL << TRNG_RAND3_RAND_Pos)	/* 0x08000000 */
#define TRNG_RAND3_RAND_28					(0x10000000UL << TRNG_RAND3_RAND_Pos)	/* 0x10000000 */
#define TRNG_RAND3_RAND_29					(0x20000000UL << TRNG_RAND3_RAND_Pos)	/* 0x20000000 */
#define TRNG_RAND3_RAND_30					(0x40000000UL << TRNG_RAND3_RAND_Pos)	/* 0x40000000 */
#define TRNG_RAND3_RAND_31					(0x80000000UL << TRNG_RAND3_RAND_Pos)	/* 0x80000000 */

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
