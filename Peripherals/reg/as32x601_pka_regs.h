/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_pka_reg.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/11
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/11     1.0     build this module
 * Description:     This file contains all the register correlation defines for the PKA firmware library.
 */

#ifndef AS32X601_PKA_REGS_H
#define AS32X601_PKA_REGS_H

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
	__IO uint32_t CTRL;						/* PKA Control Register,							Address offset: 0x00 */
	__IO uint32_t ENTRY_PNT;				/* PKA Program Entry Point Register,				Address offset: 0x04 */
	__IO uint32_t RTN_CODE;					/* PKA Return Code Register,						Address offset: 0x08 */
	__IO uint32_t RESERVED0;				/* PKA Reserved,									Address offset: 0x0C */
	__IO uint32_t STACK_PNTR;				/* PKA Stack Pointer Register,						Address offset: 0x10 */
	__IO uint32_t INSTR_SINCE_GO;			/* PKA Instructions Since GO Register,				Address offset: 0x14 */
	__IO uint32_t RESERVED1;				/* PKA Reserved,									Address offset: 0x18 */
	__IO uint32_t CONFIG;					/* Sets Configuration State Within The PKA,			Address offset: 0x1C */
	__IO uint32_t STAT;						/* PKA Status Register,								Address offset: 0x20 */
	__IO uint32_t FLAGS;					/* PKA Falgs Register,								Address offset: 0x24 */
	__IO uint32_t WATCHDOG;					/* PKA Watchdog Register,							Address offset: 0x28 */
	__IO uint32_t CYCLES_SINCE_GO;			/* PKA Cycles Since GO Register,					Address offset: 0x2C */
	__IO uint32_t RESERVED2[4];				/* PKA Reserved,									Address offset: 0x30 - 0x3C */
	__IO uint32_t IRQ_EN;					/* PKA Interrupt Enable Register,					Address offset: 0x40 */
}PKA_TypeDef;

/*
 * @addtogroup PKA Peripheral declaration
 */
#define PKA				((PKA_TypeDef*)PKA_BASE)

/******************  Bit definition for PKA_CTRL register  *******************/
#define PKA_CTRL_PARTIAL_RADIX_DPos 						(0)
#define PKA_CTRL_PARTIAL_RADIX_Pos							PKA_CTRL_PARTIAL_RADIX_DPos
#define PKA_CTRL_PARTIAL_RADIX_Msk 							(0xFFUL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x000000FF */
#define PKA_CTRL_PARTIAL_RADIX								PKA_CTRL_PARTIAL_RADIX_Msk							/*  Selects a partial field from within the base radix */
#define PKA_CTRL_PARTIAL_RADIX_0							(0x01UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000001 */
#define PKA_CTRL_PARTIAL_RADIX_1							(0x02UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000002 */
#define PKA_CTRL_PARTIAL_RADIX_2							(0x04UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000004 */
#define PKA_CTRL_PARTIAL_RADIX_3							(0x08UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000008 */
#define PKA_CTRL_PARTIAL_RADIX_4							(0x10UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000010 */
#define PKA_CTRL_PARTIAL_RADIX_5							(0x20UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000020 */
#define PKA_CTRL_PARTIAL_RADIX_6							(0x40UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000040 */
#define PKA_CTRL_PARTIAL_RADIX_7							(0x80UL << PKA_CTRL_PARTIAL_RADIX_Pos)				/* 0x00000080 */

#define PKA_CTRL_BASE_RADIX_DPos 							(8)
#define PKA_CTRL_BASE_RADIX_Pos								PKA_CTRL_BASE_RADIX_DPos
#define PKA_CTRL_BASE_RADIX_Msk 							(0x7UL << PKA_CTRL_BASE_RADIX_Pos)					/* 0x00000300 */
#define PKA_CTRL_BASE_RADIX									PKA_CTRL_BASE_RADIX_Msk								/* Sets the size of the base operand size (radix) */
#define PKA_CTRL_BASE_RADIX_0								(0x01UL << PKA_CTRL_BASE_RADIX_Pos)					/* 0x00000100 */
#define PKA_CTRL_BASE_RADIX_1								(0x02UL << PKA_CTRL_BASE_RADIX_Pos)					/* 0x00000200 */
#define PKA_CTRL_BASE_RADIX_2								(0x04UL << PKA_CTRL_BASE_RADIX_Pos)					/* 0x00000400 */

#define PKA_CTRL_M521_MODE_DPos 							(16)
#define PKA_CTRL_M521_MODE_Pos								PKA_CTRL_M521_MODE_DPos
#define PKA_CTRL_M521_MODE_Msk 								(0x1FUL << PKA_CTRL_M521_MODE_Pos)					/* 0x001F0000 */
#define PKA_CTRL_M521_MODE									PKA_CTRL_M521_MODE_Msk								/* Sets operating to Mersenne M-521 */
#define PKA_CTRL_M521_MODE_0								(0x01UL << PKA_CTRL_M521_MODE_Pos)					/* 0x00010000 */
#define PKA_CTRL_M521_MODE_1								(0x02UL << PKA_CTRL_M521_MODE_Pos)					/* 0x00020000 */
#define PKA_CTRL_M521_MODE_2								(0x04UL << PKA_CTRL_M521_MODE_Pos)					/* 0x00040000 */
#define PKA_CTRL_M521_MODE_3								(0x08UL << PKA_CTRL_M521_MODE_Pos)					/* 0x00080000 */
#define PKA_CTRL_M521_MODE_4								(0x10UL << PKA_CTRL_M521_MODE_Pos)					/* 0x00100000 */

#define PKA_CTRL_STOP_RQST_DPos 							(27)
#define PKA_CTRL_STOP_RQST_Pos								PKA_CTRL_STOP_RQST_DPos
#define PKA_CTRL_STOP_RQST_Msk 								(0x1UL << PKA_CTRL_STOP_RQST_Pos)					/* 0x08000000 */
#define PKA_CTRL_STOP_RQST									PKA_CTRL_STOP_RQST_Msk								/* Requests PKA to halt at the next instruction boundary */

#define PKA_CTRL_GO_DPos 									(31)
#define PKA_CTRL_GO_Pos										PKA_CTRL_GO_DPos
#define PKA_CTRL_GO_Msk 									(0x1UL << PKA_CTRL_GO_Pos)							/* 0x80000000 */
#define PKA_CTRL_GO											PKA_CTRL_GO_Msk										/* Starts the PKA execution */

/******************  Bit definition for PKA_ENTRY_PNT register  *******************/
#define PKA_ENTRT_PNT_ADDR_DPos 							(0)
#define PKA_ENTRT_PNT_ADDR_Pos								PKA_ENTRT_PNT_ADDR_DPos
#define PKA_ENTRT_PNT_ADDR_Msk 								(0xFFFUL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000FFF */
#define PKA_ENTRT_PNT_ADDR									PKA_ENTRT_PNT_ADDR_Msk								/* Program entry point */
#define PKA_ENTRT_PNT_ADDR_0								(0x1UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000001 */
#define PKA_ENTRT_PNT_ADDR_1								(0x2UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000002 */
#define PKA_ENTRT_PNT_ADDR_2								(0x4UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000004 */
#define PKA_ENTRT_PNT_ADDR_3								(0x8UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000008 */
#define PKA_ENTRT_PNT_ADDR_4								(0x10UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000010 */
#define PKA_ENTRT_PNT_ADDR_5								(0x20UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000020 */
#define PKA_ENTRT_PNT_ADDR_6								(0x40UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000040 */
#define PKA_ENTRT_PNT_ADDR_7								(0x80UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000080 */
#define PKA_ENTRT_PNT_ADDR_8								(0x100UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000100 */
#define PKA_ENTRT_PNT_ADDR_9								(0x200UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000200 */
#define PKA_ENTRT_PNT_ADDR_10								(0x400UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000400 */
#define PKA_ENTRT_PNT_ADDR_11								(0x800UL << PKA_ENTRT_PNT_ADDR_Pos)					/* 0x00000800 */

/******************  Bit definition for PKA_RTN_CODE register  *******************/
#define PKA_RTN_CODE_STOP_REASON_DPos 						(16)
#define PKA_RTN_CODE_STOP_REASON_Pos						PKA_RTN_CODE_STOP_REASON_DPos
#define PKA_RTN_CODE_STOP_REASON_Msk 						(0xFFUL << PKA_RTN_CODE_STOP_REASON_Pos)			/* 0x00FF0000 */	
#define PKA_RTN_CODE_STOP_REASON							PKA_RTN_CODE_STOP_REASON_Msk						/* Indicates why the PKA stopped */
#define PKA_RTN_CODE_STOP_REASON_0							(0x1UL << PKA_RTN_CODE_STOP_REASON_Pos)				/* 0x00010000 */
#define PKA_RTN_CODE_STOP_REASON_1							(0x2UL << PKA_RTN_CODE_STOP_REASON_Pos)				/* 0x00020000 */
#define PKA_RTN_CODE_STOP_REASON_2							(0x4UL << PKA_RTN_CODE_STOP_REASON_Pos)				/* 0x00040000 */
#define PKA_RTN_CODE_STOP_REASON_3							(0x8UL << PKA_RTN_CODE_STOP_REASON_Pos)				/* 0x00080000 */
#define PKA_RTN_CODE_STOP_REASON_4							(0x10UL << PKA_RTN_CODE_STOP_REASON_Pos)			/* 0x00100000 */
#define PKA_RTN_CODE_STOP_REASON_5							(0x20UL << PKA_RTN_CODE_STOP_REASON_Pos)			/* 0x00200000 */
#define PKA_RTN_CODE_STOP_REASON_6							(0x40UL << PKA_RTN_CODE_STOP_REASON_Pos)			/* 0x00400000 */
#define PKA_RTN_CODE_STOP_REASON_7							(0x80UL << PKA_RTN_CODE_STOP_REASON_Pos)			/* 0x00800000 */

#define PKA_RTN_CODE_DPA_EN_DPos 							(27)
#define PKA_RTN_CODE_DPA_EN_Pos								PKA_RTN_CODE_DPA_EN_DPos
#define	PKA_RTN_CODE_DPA_EN_Msk 							(0x1UL << PKA_RTN_CODE_DPA_EN_Pos)					/* 0x08000000 */
#define PKA_RTN_CODE_DPA_EN									PKA_RTN_CODE_DPA_EN_Msk								/* Indicates that the core is capable of operating in TA and/or DPA mode. */

#define PKA_RTN_CODE_ZERO_DPos 								(28)
#define PKA_RTN_CODE_ZERO_Pos								PKA_RTN_CODE_ZERO_DPos
#define PKA_RTN_CODE_ZERO_Msk 								(0x1UL << PKA_RTN_CODE_ZERO_Pos)					/* 0x10000000 */
#define PKA_RTN_CODE_ZERO									PKA_RTN_CODE_ZERO_Msk								/* Indicates the state of the zero flag in the sequencer */

#define PKA_RTN_CODE_IRQ_DPos 								(30)
#define PKA_RTN_CODE_IRQ_Pos								PKA_RTN_CODE_IRQ_DPos
#define PKA_RTN_CODE_IRQ_Msk 								(0x1UL << PKA_RTN_CODE_IRQ_Pos)						/* 0x40000000 */
#define PKA_RTN_CODE_IRQ									PKA_RTN_CODE_IRQ_Msk								/* Indicates when the PKA has completed its task */

#define PKA_RTN_CODE_BUSY_DPos 								(31)
#define PKA_RTN_CODE_BUSY_Pos								PKA_RTN_CODE_BUSY_DPos
#define PKA_RTN_CODE_BUSY_Msk 								(0x1UL << PKA_RTN_CODE_BUSY_Pos)					/* 0x80000000 */
#define PKA_RTN_CODE_BUSY									PKA_RTN_CODE_BUSY_Msk								/* Indicates that the PKA is actively executing a program */

/******************  Bit definition for PKA_STACK_PNTR register  *******************/
#define PKA_STACK_PNTR_PNTR_DPos 							(0)
#define PKA_STACK_PNTR_PNTR_Pos								PKA_STACK_PNTR_PNTR_DPos
#define PKA_STACK_PNTR_PNTR_Msk 							(0xFFFUL << PKA_STACK_PNTR_PNTR_Pos)				/* 0x00000FFF */
#define PKA_STACK_PNTR_PNTR									PKA_STACK_PNTR_PNTR_Msk								/* Stack pointer */
#define PKA_STACK_PNTR_PNTR_0								(0x1UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000001 */
#define PKA_STACK_PNTR_PNTR_1								(0x2UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000002 */
#define PKA_STACK_PNTR_PNTR_2								(0x4UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000004 */
#define PKA_STACK_PNTR_PNTR_3								(0x8UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000008 */
#define PKA_STACK_PNTR_PNTR_4								(0x10UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000010 */
#define PKA_STACK_PNTR_PNTR_5								(0x20UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000020 */
#define PKA_STACK_PNTR_PNTR_6								(0x40UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000040 */
#define PKA_STACK_PNTR_PNTR_7								(0x80UL << PKA_STACK_PNTR_PNTR_Pos)					/* 0x00000080 */
#define PKA_STACK_PNTR_PNTR_8								(0x100UL << PKA_STACK_PNTR_PNTR_Pos)				/* 0x00000100 */
#define PKA_STACK_PNTR_PNTR_9								(0x200UL << PKA_STACK_PNTR_PNTR_Pos)				/* 0x00000200 */
#define PKA_STACK_PNTR_PNTR_10								(0x400UL << PKA_STACK_PNTR_PNTR_Pos)				/* 0x00000400 */
#define PKA_STACK_PNTR_PNTR_11								(0x800UL << PKA_STACK_PNTR_PNTR_Pos)				/* 0x00000800 */

/******************  Bit definition for PKA_INSTR_SINCE_GO register  *******************/
#define PKA_INSTR_SINCE_GO_INSTRS_DPos 						(0)
#define PKA_INSTR_SINCE_GO_INSTRS_Pos						PKA_INSTR_SINCE_GO_INSTRS_DPos
#define PKA_INSTR_SINCE_GO_INSTRS_Msk 						(0xFFFFFFFFUL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0xFFFFFFFF */
#define PKA_INSTR_SINCE_GO_INSTRS							PKA_INSTR_SINCE_GO_INSTRS_Msk
#define PKA_INSTR_SINCE_GO_INSTRS_0							(0x1UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000001 */
#define PKA_INSTR_SINCE_GO_INSTRS_1							(0x2UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000002 */
#define PKA_INSTR_SINCE_GO_INSTRS_2							(0x4UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000004 */
#define PKA_INSTR_SINCE_GO_INSTRS_3							(0x8UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000008 */
#define PKA_INSTR_SINCE_GO_INSTRS_4							(0x10UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000010 */
#define PKA_INSTR_SINCE_GO_INSTRS_5							(0x20UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000020 */
#define PKA_INSTR_SINCE_GO_INSTRS_6							(0x40UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000040 */
#define PKA_INSTR_SINCE_GO_INSTRS_7							(0x80UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000080 */
#define PKA_INSTR_SINCE_GO_INSTRS_8							(0x100UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000100 */
#define PKA_INSTR_SINCE_GO_INSTRS_9							(0x200UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000200 */
#define PKA_INSTR_SINCE_GO_INSTRS_10						(0x400UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000400 */
#define PKA_INSTR_SINCE_GO_INSTRS_11						(0x800UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00000800 */
#define PKA_INSTR_SINCE_GO_INSTRS_12						(0x1000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00001000 */
#define PKA_INSTR_SINCE_GO_INSTRS_13						(0x2000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00002000 */
#define PKA_INSTR_SINCE_GO_INSTRS_14						(0x4000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00004000 */
#define PKA_INSTR_SINCE_GO_INSTRS_15						(0x8000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)			/* 0x00008000 */
#define PKA_INSTR_SINCE_GO_INSTRS_16						(0x10000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00010000 */
#define PKA_INSTR_SINCE_GO_INSTRS_17						(0x20000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00020000 */
#define PKA_INSTR_SINCE_GO_INSTRS_18						(0x40000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00040000 */
#define PKA_INSTR_SINCE_GO_INSTRS_19						(0x80000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00080000 */
#define PKA_INSTR_SINCE_GO_INSTRS_20						(0x100000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00100000 */
#define PKA_INSTR_SINCE_GO_INSTRS_21						(0x200000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00200000 */
#define PKA_INSTR_SINCE_GO_INSTRS_22						(0x400000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00400000 */
#define PKA_INSTR_SINCE_GO_INSTRS_23						(0x800000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x00800000 */
#define PKA_INSTR_SINCE_GO_INSTRS_24						(0x1000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x01000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_25						(0x2000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x02000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_26						(0x4000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x04000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_27						(0x8000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x08000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_28						(0x10000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x10000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_29						(0x20000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x20000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_30						(0x40000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x40000000 */
#define PKA_INSTR_SINCE_GO_INSTRS_31						(0x80000000UL << PKA_INSTR_SINCE_GO_INSTRS_Pos)		/* 0x80000000 */

/******************  Bit definition for PKA_CONFIG register  *******************/
#define PKA_CONFIG_ALT_ACCESS_DPos 							(0)
#define PKA_CONFIG_ALT_ACCESS_Pos							PKA_CONFIG_ALT_ACCESS_DPos
#define PKA_CONFIG_ALT_ACCESS_Msk 							(0x1UL << PKA_CONFIG_ALT_ACCESS_Pos)				/* 0x00000001 */
#define PKA_CONFIG_ALT_ACCESS								PKA_CONFIG_ALT_ACCESS_Msk							/* Enable the alternate access mode */

#define PKA_CONFIG_ENDIAN_SWAP_DPos 						(26)
#define PKA_CONFIG_ENDIAN_SWAP_Pos							PKA_CONFIG_ENDIAN_SWAP_DPos
#define PKA_CONFIG_ENDIAN_SWAP_Msk 							(0x1UL << PKA_CONFIG_ENDIAN_SWAP_Pos)				/* 0x04000000 */
#define PKA_CONFIG_ENDIAN_SWAP								PKA_CONFIG_ENDIAN_SWAP_Msk							/* Cause the data memory regions to be endian swapped on transfer in or out of core */

/******************  Bit definition for PKA_STAT register  *******************/
#define PKA_STAT_SIF_ERR_DPos 								(0)
#define PKA_STAT_SIF_ERR_Pos								PKA_STAT_SIF_ERR_DPos
#define PKA_STAT_SIF_ERR_Msk 								(0x1UL << PKA_STAT_SIF_ERR_Pos)						/* 0x00000001 */
#define PKA_STAT_SIF_ERR									PKA_STAT_SIF_ERR_Msk								/* Indicates that an SIF error has occurred */

#define PKA_STAT_SIF_SBE_DPos 								(1)
#define PKA_STAT_SIF_SBE_Pos								PKA_STAT_SIF_SBE_DPos
#define PKA_STAT_SIF_SBE_Msk 								(0x1UL << PKA_STAT_SIF_SBE_Pos)						/* 0x00000002 */
#define PKA_STAT_SIF_SBE									PKA_STAT_SIF_SBE_Msk								/* Indicates that an SIF single bit error has occurred */

#define PKA_STAT_DONE_DPos 									(30)
#define PKA_STAT_DONE_Pos									PKA_STAT_DONE_DPos
#define PKA_STAT_DONE_Msk 									(0x1UL << PKA_STAT_DONE_Pos)						/* 0x40000000 */
#define PKA_STAT_DONE										PKA_STAT_DONE_Msk									/* Indicates that the operation has completed */

/******************  Bit definition for PKA_FLAGS register  *******************/
#define PKA_FLAGS_Z_DPos 									(0)
#define PKA_FLAGS_Z_Pos										PKA_FLAGS_Z_DPos
#define PKA_FLAGS_Z_Msk 									(0x1UL << PKA_FLAGS_Z_Pos)							/* 0x00000001 */
#define PKA_FLAGS_Z											PKA_FLAGS_Z_Msk										/* Zero flag */

#define PKA_FLAGS_M_DPos 									(1)
#define PKA_FLAGS_M_Pos										PKA_FLAGS_M_DPos
#define PKA_FLAGS_M_Msk 									(0x1UL << PKA_FLAGS_M_Pos)							/* 0x00000002 */
#define PKA_FLAGS_M											PKA_FLAGS_M_Msk										/* Memory-test flag */

#define PKA_FLAGS_B_DPos 									(2)
#define PKA_FLAGS_B_Pos										PKA_FLAGS_B_DPos
#define PKA_FLAGS_B_Msk 									(0x1UL << PKA_FLAGS_B_Pos)							/* 0x00000004 */
#define PKA_FLAGS_B											PKA_FLAGS_B_Msk										/* Borrow flag */

#define PKA_FLAGS_C_DPos 									(3)
#define PKA_FLAGS_C_Pos										PKA_FLAGS_C_DPos
#define PKA_FLAGS_C_Msk 									(0x1UL << PKA_FLAGS_C_Pos)							/* 0x00000008 */
#define PKA_FLAGS_C											PKA_FLAGS_C_Msk										/* Carry flag */

#define PKA_FLAGS_F0_DPos 									(4)
#define PKA_FLAGS_F0_Pos									PKA_FLAGS_F0_DPos
#define PKA_FLAGS_F0_Msk 									(0x1UL << PKA_FLAGS_F0_Pos)							/* 0x00000010 */
#define PKA_FLAGS_F0										PKA_FLAGS_F0_Msk									/* User flag 0 */

#define PKA_FLAGS_F1_DPos 									(5)
#define PKA_FLAGS_F1_Pos									PKA_FLAGS_F1_DPos
#define PKA_FLAGS_F1_Msk 									(0x1UL << PKA_FLAGS_F1_Pos)							/* 0x00000020 */
#define PKA_FLAGS_F1										PKA_FLAGS_F1_Msk									/* User flag 1 */

#define PKA_FLAGS_F2_DPos 									(6)
#define PKA_FLAGS_F2_Pos									PKA_FLAGS_F2_DPos
#define PKA_FLAGS_F2_Msk 									(0x1UL << PKA_FLAGS_F2_Pos)							/* 0x00000040 */
#define PKA_FLAGS_F2										PKA_FLAGS_F2_Msk									/* User flag 2 */

#define PKA_FLAGS_F3_DPos 									(7)
#define PKA_FLAGS_F3_Pos									PKA_FLAGS_F3_DPos
#define PKA_FLAGS_F3_Msk 									(0x1UL << PKA_FLAGS_F3_Pos)							/* 0x00000080 */
#define PKA_FLAGS_F3										PKA_FLAGS_F3_Msk									/* User flag 3 */

/******************  Bit definition for PKA_WATCHDOG register  *******************/
#define PKA_WATCHDOG_RELOAD_DPos 							(0)
#define PKA_WATCHDOG_RELOAD_Pos								PKA_WATCHDOG_RELOAD_DPos
#define PKA_WATCHDOG_RELOAD_Msk 							(0xFFFFFFFFUL << PKA_WATCHDOG_RELOAD_Pos)			/* 0xFFFFFFFF */
#define PKA_WATCHDOG_RELOAD									PKA_WATCHDOG_RELOAD_Msk								/* Reload value for the watchdog timer */
#define PKA_WATCHDOG_RELOAD_0								(0x1UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000001 */
#define PKA_WATCHDOG_RELOAD_1								(0x2UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000002 */
#define PKA_WATCHDOG_RELOAD_2								(0x4UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000004 */
#define PKA_WATCHDOG_RELOAD_3								(0x8UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000008 */
#define PKA_WATCHDOG_RELOAD_4								(0x10UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000010 */
#define PKA_WATCHDOG_RELOAD_5								(0x20UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000020 */
#define PKA_WATCHDOG_RELOAD_6								(0x40UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000040 */
#define PKA_WATCHDOG_RELOAD_7								(0x80UL << PKA_WATCHDOG_RELOAD_Pos)					/* 0x00000080 */
#define PKA_WATCHDOG_RELOAD_8								(0x100UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00000100 */
#define PKA_WATCHDOG_RELOAD_9								(0x200UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00000200 */
#define PKA_WATCHDOG_RELOAD_10								(0x400UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00000400 */
#define PKA_WATCHDOG_RELOAD_11								(0x800UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00000800 */
#define PKA_WATCHDOG_RELOAD_12								(0x1000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00001000 */
#define PKA_WATCHDOG_RELOAD_13								(0x2000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00002000 */
#define PKA_WATCHDOG_RELOAD_14								(0x4000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00004000 */
#define PKA_WATCHDOG_RELOAD_15								(0x8000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00008000 */
#define PKA_WATCHDOG_RELOAD_16								(0x10000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00010000 */
#define PKA_WATCHDOG_RELOAD_17								(0x20000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00020000 */
#define PKA_WATCHDOG_RELOAD_18								(0x40000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00040000 */
#define PKA_WATCHDOG_RELOAD_19								(0x80000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00080000 */
#define PKA_WATCHDOG_RELOAD_20								(0x100000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00100000 */
#define PKA_WATCHDOG_RELOAD_21								(0x200000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00200000 */
#define PKA_WATCHDOG_RELOAD_22								(0x400000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00400000 */
#define PKA_WATCHDOG_RELOAD_23								(0x800000UL << PKA_WATCHDOG_RELOAD_Pos)				/* 0x00800000 */
#define PKA_WATCHDOG_RELOAD_24								(0x1000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x01000000 */
#define PKA_WATCHDOG_RELOAD_25								(0x2000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x02000000 */
#define PKA_WATCHDOG_RELOAD_26								(0x4000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x04000000 */
#define PKA_WATCHDOG_RELOAD_27								(0x8000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x08000000 */
#define PKA_WATCHDOG_RELOAD_28								(0x10000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x10000000 */
#define PKA_WATCHDOG_RELOAD_29								(0x20000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x20000000 */
#define PKA_WATCHDOG_RELOAD_30								(0x40000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x40000000 */
#define PKA_WATCHDOG_RELOAD_31								(0x80000000UL << PKA_WATCHDOG_RELOAD_Pos)			/* 0x80000000 */

/******************  Bit definition for PKA_CYCLES_SINCE_GO register  *******************/
#define PKA_CYCLES_SINCE_GO_CYCLES_DPos 					(0)
#define PKA_CYCLES_SINCE_GO_Cycles_Pos						PKA_CYCLES_SINCE_GO_CYCLES_DPos
#define PKA_CYCLES_SINCE_GO_Cycles_Msk 						(0xFFFFFFFFUL << PKA_CYCLES_SINCE_GO_Cycles_Pos)	/* 0xFFFFFFFF */
#define PKA_CYCLES_SINCE_GO_Cycles							PKA_CYCLES_SINCE_GO_Cycles_Msk						/* Number of cycles since the last GO command */
#define PKA_CYCLES_SINCE_GO_Cycles_0						(0x1UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000001 */
#define PKA_CYCLES_SINCE_GO_Cycles_1						(0x2UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000002 */
#define PKA_CYCLES_SINCE_GO_Cycles_2						(0x4UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000004 */
#define PKA_CYCLES_SINCE_GO_Cycles_3						(0x8UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000008 */
#define PKA_CYCLES_SINCE_GO_Cycles_4						(0x10UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000010 */
#define PKA_CYCLES_SINCE_GO_Cycles_5						(0x20UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000020 */
#define PKA_CYCLES_SINCE_GO_Cycles_6						(0x40UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000040 */
#define PKA_CYCLES_SINCE_GO_Cycles_7						(0x80UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000080 */
#define PKA_CYCLES_SINCE_GO_Cycles_8						(0x100UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000100 */
#define PKA_CYCLES_SINCE_GO_Cycles_9						(0x200UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000200 */
#define PKA_CYCLES_SINCE_GO_Cycles_10						(0x400UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000400 */
#define PKA_CYCLES_SINCE_GO_Cycles_11						(0x800UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)			/* 0x00000800 */
#define PKA_CYCLES_SINCE_GO_Cycles_12						(0x1000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00001000 */
#define PKA_CYCLES_SINCE_GO_Cycles_13						(0x2000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00002000 */
#define PKA_CYCLES_SINCE_GO_Cycles_14						(0x4000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00004000 */
#define PKA_CYCLES_SINCE_GO_Cycles_15						(0x8000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00008000 */
#define PKA_CYCLES_SINCE_GO_Cycles_16						(0x10000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00010000 */
#define PKA_CYCLES_SINCE_GO_Cycles_17						(0x20000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00020000 */
#define PKA_CYCLES_SINCE_GO_Cycles_18						(0x40000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00040000 */
#define PKA_CYCLES_SINCE_GO_Cycles_19						(0x80000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00080000 */
#define PKA_CYCLES_SINCE_GO_Cycles_20						(0x100000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00100000 */
#define PKA_CYCLES_SINCE_GO_Cycles_21						(0x200000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00200000 */
#define PKA_CYCLES_SINCE_GO_Cycles_22						(0x400000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00400000 */
#define PKA_CYCLES_SINCE_GO_Cycles_23						(0x800000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x00800000 */
#define PKA_CYCLES_SINCE_GO_Cycles_24						(0x1000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x01000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_25						(0x2000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x02000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_26						(0x4000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x04000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_27						(0x8000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)		/* 0x08000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_28						(0x10000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)	/* 0x10000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_29						(0x20000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)	/* 0x20000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_30						(0x40000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)	/* 0x40000000 */
#define PKA_CYCLES_SINCE_GO_Cycles_31						(0x80000000UL << PKA_CYCLES_SINCE_GO_Cycles_Pos)	/* 0x80000000 */

/******************  Bit definition for PKA_IRQ_EN register  *******************/
#define PKA_IRQ_EN_SIF_ERR_IE_DPos 							(0)
#define PKA_IRQ_EN_SIF_ERR_IE_Pos							PKA_IRQ_EN_SIF_ERR_IE_DPos
#define PKA_IRQ_EN_SIF_ERR_IE_Msk 							(0x1UL << PKA_IRQ_EN_SIF_ERR_IE_Pos)				/* 0x00000001 */
#define PKA_IRQ_EN_SIF_ERR_IE								PKA_IRQ_EN_SIF_ERR_IE_Msk							/* Enable interrupt on SIF error */

#define PKA_IRQ_EN_SIF_SBE_IE_DPos 							(1)
#define PKA_IRQ_EN_SIF_SBE_IE_Pos							PKA_IRQ_EN_SIF_SBE_IE_DPos
#define PKA_IRQ_EN_SIF_SBE_IE_Msk 							(0x2UL << PKA_IRQ_EN_SIF_SBE_IE_Pos)				/* 0x00000002 */
#define PKA_IRQ_EN_SIF_SBE_IE								PKA_IRQ_EN_SIF_SBE_IE_Msk							/* Enable interrupt on SIF single bit error */

#define PKA_IRQ_EN_DONE_IE_DPos 							(30)
#define PKA_IRQ_EN_DONE_IE_Pos								PKA_IRQ_EN_DONE_IE_DPos
#define PKA_IRQ_EN_DONE_IE_Msk 								(0x1UL << PKA_IRQ_EN_DONE_IE_Pos)					/* 0x40000000 */
#define PKA_IRQ_EN_DONE_IE									PKA_IRQ_EN_DONE_IE_Msk								/* Enable interrupt on PKA done */

#define PKA_IRQ_EN_GLB_IE_DPos 								(31)
#define PKA_IRQ_EN_GLB_IE_Pos								PKA_IRQ_EN_GLB_IE_DPos
#define PKA_IRQ_EN_GLB_IE_Msk 								(0x1UL << PKA_IRQ_EN_GLB_IE_Pos)					/* 0x80000000 */
#define PKA_IRQ_EN_GLB_IE									PKA_IRQ_EN_GLB_IE_Msk								/* Enable interrupt on PKA global error */

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
