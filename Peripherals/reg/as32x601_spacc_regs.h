/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_spacc_reg.h
 * Author:          ANSILIC APPLICATION GROUP
 * Version :        V1.0
 * Date:			2024/9/4
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/9/4       1.0     build this module
 * Description:     This file contains all the register correlation defines for the SPACC firmware library.
 */

#ifndef AS32X601_SPACC_REGS_H
#define AS32X601_SPACC_REGS_H

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
	__IO uint32_t 	IRQ_EN;					/* SPACC Interrupt Enable Register,				Address offset: 0x00 */
	__IO uint32_t 	IRQ_STAT;				/* SPACC Interrupt Status Register,				Address offset: 0x04 */
	__IO uint32_t 	IRQ_CTRL;				/* SPACC Interrupt Control Register,			Address offset: 0x08 */
	__IO uint32_t 	FIFO_STAT;				/* SPACC FIFO Status Register,					Address offset: 0x0C */
	__IO uint32_t	RESERVEND0[4];			/* SPACC Reserved, 								Address offset: 0x10 - 0x1C */ 
	__IO uint32_t	SRC_PTR;				/* SPACC Source Pointer Register,				Address offset: 0x20 */
	__IO uint32_t	DST_PTR;				/* SPACC Destination Pointer Register,			Address offset: 0x24 */
	__IO uint32_t	OFFSET;					/* SPACC Offset Register,						Address offset: 0x28 */
	__IO uint32_t	PRE_AAD_LEN;			/* SPACC Prefixed AAD Length Register,			Address offset: 0x2C */
	__IO uint32_t	POST_AAD_LEN;			/* SPACC Postfixed AAD Length Register,			Address offset: 0x30 */
	__IO uint32_t	PROC_LEN;				/* SPACC Packet Length Register,				Address offset: 0x34 */
	__IO uint32_t	ICV_LEN;				/* SPACC ICV Length Register,					Address offset: 0x38 */
	__IO uint32_t	ICV_OFFSET;				/* SPACC ICV Offset Register,					Address offset: 0x3C */
	__IO uint32_t	IV_OFFSET;				/* SPACC IV Offset Register,					Address offset: 0x40 */
	__IO uint32_t	SW_CTRL;				/* SPACC Software Control Register,				Address offset: 0x44 */
	__IO uint32_t	AUX_INFO;				/* SPACC Auxiliary Information Register,		Address offset: 0x48 */
	__IO uint32_t	CTRL;					/* SPACC Control Register,						Address offset: 0x4C */
	__IO uint32_t	STAT_POP;				/* SPACC Status FIFO POP Register,				Address offset: 0x50 */
	__IO uint32_t	STATUS;					/* SPACC Status FIFO Register,					Address offset: 0x54 */
	__IO uint32_t	RESERVEND1[10];			/* SPACC Reserved, 								Address offset: 0x58 - 0x7C */
	__IO uint32_t	STAT_WD_CTRL;			/* SPACC Status Watchdog Register,				Address offset: 0x80 */
	__IO uint32_t	RESERVEND2[31];			/* SPACC Reserved, 								Address offset: 0x84 - 0xFC */
	__IO uint32_t	KEY_SZ;					/* SPACC Key Size Register,						Address offset: 0x100 */
} SPACC_TypeDef;

/*
 * @addtogroup SPACC Peripheral declaration
 */
#define SPACC 			((SPACC_TypeDef*)SPACC_BASE)

/******************  Bit definition for SPACC_IRQ_EN register  *******************/
#define SPACC_IRQ_EN_CMD0_EN_DPos      						(0U)
#define SPACC_IRQ_EN_CMD0_EN_Pos							SPACC_IRQ_EN_CMD0_EN_DPos
#define SPACC_IRQ_EN_CMD0_EN_Msk       						(0x1UL << SPACC_IRQ_EN_CMD0_EN_Pos)					/* 0x00000001 */
#define SPACC_IRQ_EN_CMD0_EN								SPACC_IRQ_EN_CMD0_EN_Msk							/* SPACC Command FIFO Priority 0 Interrupt Enable */

#define SPACC_IRQ_EN_CMD1_EN_DPos      						(1U)
#define SPACC_IRQ_EN_CMD1_EN_Pos							SPACC_IRQ_EN_CMD1_EN_DPos
#define SPACC_IRQ_EN_CMD1_EN_Msk       						(0x1UL << SPACC_IRQ_EN_CMD1_EN_Pos)					/* 0x00000002 */
#define SPACC_IRQ_EN_CMD1_EN								SPACC_IRQ_EN_CMD1_EN_Msk							/* SPACC Command FIFO Priority 1 Interrupt Enable */

#define SPACC_IRQ_EN_CMD2_EN_DPos      						(2U)
#define SPACC_IRQ_EN_CMD2_EN_Pos							SPACC_IRQ_EN_CMD2_EN_DPos
#define SPACC_IRQ_EN_CMD2_EN_Msk       						(0x1UL << SPACC_IRQ_EN_CMD2_EN_Pos)					/* 0x00000004 */
#define SPACC_IRQ_EN_CMD2_EN								SPACC_IRQ_EN_CMD2_EN_Msk							/* SPACC Command FIFO Priority 2 Interrupt Enable */

#define SPACC_IRQ_EN_STAT_EN_DPos      						(4U)
#define SPACC_IRQ_EN_STAT_EN_Pos							SPACC_IRQ_EN_STAT_EN_DPos
#define SPACC_IRQ_EN_STAT_EN_Msk       						(0x1UL << SPACC_IRQ_EN_STAT_EN_Pos)					/* 0x00000010 */
#define SPACC_IRQ_EN_STAT_EN								SPACC_IRQ_EN_STAT_EN_Msk							/* SPACC Status FIFO Interrupt Enable */

#define SPACC_IRQ_EN_RC4_DMA_EN_DPos      					(8U)
#define SPACC_IRQ_EN_RC4_DMA_EN_Pos							SPACC_IRQ_EN_RC4_DMA_EN_DPos
#define SPACC_IRQ_EN_RC4_DMA_EN_Msk       					(0x1UL << SPACC_IRQ_EN_RC4_DMA_EN_Pos)				/* 0x00000100 */
#define SPACC_IRQ_EN_RC4_DMA_EN								SPACC_IRQ_EN_RC4_DMA_EN_Msk

#define SPACC_IRQ_EN_STAT_WD_EN_DPos      					(12U)
#define SPACC_IRQ_EN_STAT_WD_EN_Pos							SPACC_IRQ_EN_STAT_WD_EN_DPos
#define SPACC_IRQ_EN_STAT_WD_EN_Msk       					(0x1UL << SPACC_IRQ_EN_STAT_WD_EN_Pos)				/* 0x00001000 */
#define SPACC_IRQ_EN_STAT_WD_EN								SPACC_IRQ_EN_STAT_WD_EN_Msk							/* SPACC Status Watchdog Interrupt Enable */

#define SPACC_IRQ_EN_GLBL_EN_DPos      						(31U)
#define SPACC_IRQ_EN_GLBL_EN_Pos							SPACC_IRQ_EN_GLBL_EN_DPos
#define SPACC_IRQ_EN_GLBL_EN_Msk       						(0x1UL << SPACC_IRQ_EN_GLBL_EN_Pos)					/* 0x80000000 */
#define SPACC_IRQ_EN_GLBL_EN								SPACC_IRQ_EN_GLBL_EN_Msk							/* SPACC Global Enable Control For Interrupt Sources */

/******************  Bit definition for SPACC_IRQ_STAT register  *******************/
#define SPACC_IRQ_STAT_CMD0_DPos      						(0U)
#define SPACC_IRQ_STAT_CMD0_Pos								SPACC_IRQ_STAT_CMD0_DPos
#define SPACC_IRQ_STAT_CMD0_Msk       						(0x1UL << SPACC_IRQ_STAT_CMD0_Pos)					/* 0x00000001 */
#define SPACC_IRQ_STAT_CMD0									SPACC_IRQ_STAT_CMD0_Msk								/* SPACC Command FIFO Priority 0 Interrupt Status */

#define SPACC_IRQ_STAT_CMD1_DPos      						(1U)
#define SPACC_IRQ_STAT_CMD1_Pos								SPACC_IRQ_STAT_CMD1_DPos
#define SPACC_IRQ_STAT_CMD1_Msk       						(0x1UL << SPACC_IRQ_STAT_CMD1_Pos)					/* 0x00000002 */
#define SPACC_IRQ_STAT_CMD1									SPACC_IRQ_STAT_CMD1_Msk								/* SPACC Command FIFO Priority 1 Interrupt Status */

#define SPACC_IRQ_STAT_CMD2_DPos      						(2U)
#define SPACC_IRQ_STAT_CMD2_Pos								SPACC_IRQ_STAT_CMD2_DPos
#define SPACC_IRQ_STAT_CMD2_Msk       						(0x1UL << SPACC_IRQ_STAT_CMD2_Pos)					/* 0x00000004 */
#define SPACC_IRQ_STAT_CMD2									SPACC_IRQ_STAT_CMD2_Msk								/* SPACC Command FIFO Priority 2 Interrupt Status */

#define SPACC_IRQ_STAT_STAT_DPos      						(4U)
#define SPACC_IRQ_STAT_STAT_Pos								SPACC_IRQ_STAT_STAT_DPos
#define SPACC_IRQ_STAT_STAT_Msk       						(0x1UL << SPACC_IRQ_STAT_STAT_Pos)					/* 0x00000010 */
#define SPACC_IRQ_STAT_STAT									SPACC_IRQ_STAT_STAT_Msk								/* SPACC Status FIFO Interrupt Status */

#define SPACC_IRQ_STAT_RC4_DMA_DPos      					(8U)
#define SPACC_IRQ_STAT_RC4_DMA_Pos							SPACC_IRQ_STAT_RC4_DMA_DPos
#define SPACC_IRQ_STAT_RC4_DMA_Msk       					(0x1UL << SPACC_IRQ_STAT_RC4_DMA_Pos)				/* 0x00000100 */
#define SPACC_IRQ_STAT_RC4_DMA								SPACC_IRQ_STAT_RC4_DMA_Msk

#define SPACC_IRQ_STAT_STAT_WD_DPos      					(12U)
#define SPACC_IRQ_STAT_STAT_WD_Pos							SPACC_IRQ_STAT_STAT_WD_DPos
#define SPACC_IRQ_STAT_STAT_WD_Msk       					(0x1UL << SPACC_IRQ_STAT_STAT_WD_Pos)				/* 0x00001000 */
#define SPACC_IRQ_STAT_STAT_WD								SPACC_IRQ_STAT_STAT_WD_Msk							/* SPACC Status Watchdog Interrupt Status */

/******************  Bit definition for SPACC_IRQ_CTRL register  *******************/
#define SPACC_IRQ_CTRL_CMD0_CNT_DPos      					(0U)
#define SPACC_IRQ_CTRL_CMD0_CNT_Pos							SPACC_IRQ_CTRL_CMD0_CNT_DPos
#define SPACC_IRQ_CTRL_CMD0_CNT_Msk       					(0xFFUL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x000000FF */
#define SPACC_IRQ_CTRL_CMD0_CNT								SPACC_IRQ_CTRL_CMD0_CNT_Msk							/* SPACC FIFO Fill Level To Trigger A CMD0 Interrupt */
#define SPACC_IRQ_CTRL_CMD0_CNT_0							(0x1UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000001 */
#define SPACC_IRQ_CTRL_CMD0_CNT_1							(0x2UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000002 */
#define SPACC_IRQ_CTRL_CMD0_CNT_2							(0x4UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000004 */
#define SPACC_IRQ_CTRL_CMD0_CNT_3							(0x8UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000008 */
#define SPACC_IRQ_CTRL_CMD0_CNT_4							(0x10UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000010 */
#define SPACC_IRQ_CTRL_CMD0_CNT_5							(0x20UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000020 */
#define SPACC_IRQ_CTRL_CMD0_CNT_6							(0x40UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000040 */
#define SPACC_IRQ_CTRL_CMD0_CNT_7							(0x80UL << SPACC_IRQ_CTRL_CMD0_CNT_Pos)				/* 0x00000080 */

#define SPACC_IRQ_CTRL_STAT_CNT_DPos      					(16U)
#define SPACC_IRQ_CTRL_STAT_CNT_Pos							SPACC_IRQ_CTRL_STAT_CNT_DPos
#define SPACC_IRQ_CTRL_STAT_CNT_Msk       					(0xFFUL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00FF0000 */
#define SPACC_IRQ_CTRL_STAT_CNT								SPACC_IRQ_CTRL_STAT_CNT_Msk							/* SPACC FIFO Fill Level To Trigger A STAT Interrupt */
#define SPACC_IRQ_CTRL_STAT_CNT_0							(0x1UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00010000 */
#define SPACC_IRQ_CTRL_STAT_CNT_1							(0x2UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00020000 */
#define SPACC_IRQ_CTRL_STAT_CNT_2							(0x4UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00040000 */
#define SPACC_IRQ_CTRL_STAT_CNT_3							(0x8UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00080000 */
#define SPACC_IRQ_CTRL_STAT_CNT_4							(0x10UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00100000 */
#define SPACC_IRQ_CTRL_STAT_CNT_5							(0x20UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00200000 */
#define SPACC_IRQ_CTRL_STAT_CNT_6							(0x40UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00400000 */
#define SPACC_IRQ_CTRL_STAT_CNT_7							(0x80UL << SPACC_IRQ_CTRL_STAT_CNT_Pos)				/* 0x00800000 */

/******************  Bit definition for SPACC_FIFO_STAT register  *******************/
#define SPACC_FIFO_STAT_CMD0_CNT_DPos      					(0U)
#define SPACC_FIFO_STAT_CMD0_CNT_Pos						SPACC_FIFO_STAT_CMD0_CNT_DPos
#define SPACC_FIFO_STAT_CMD0_CNT_Msk       					(0xFFUL << SPACC_FIFO_STAT_CMD0_CNT_Pos)			/* 0x000000FF */
#define SPACC_FIFO_STAT_CMD0_CNT							SPACC_FIFO_STAT_CMD0_CNT_Msk						/* SPACC Current Number Of Commands Enqueued In The CMD0 FIFO */
#define SPACC_FIFO_STAT_CMD0_CNT_0							(0x1UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)				/* 0x00000001 */
#define SPACC_FIFO_STAT_CMD0_CNT_1							(0x2UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)				/* 0x00000002 */
#define SPACC_FIFO_STAT_CMD0_CNT_2							(0x4UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)				/* 0x00000004 */
#define SPACC_FIFO_STAT_CMD0_CNT_3							(0x8UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)				/* 0x00000008 */
#define SPACC_FIFO_STAT_CMD0_CNT_4							(0x10UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)			/* 0x00000010 */
#define SPACC_FIFO_STAT_CMD0_CNT_5							(0x20UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)			/* 0x00000020 */
#define SPACC_FIFO_STAT_CMD0_CNT_6							(0x40UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)			/* 0x00000040 */
#define SPACC_FIFO_STAT_CMD0_CNT_7							(0x80UL << SPACC_FIFO_STAT_CMD0_CNT_Pos)			/* 0x00000080 */

#define SPACC_FIFO_STAT_CMD0_FULL_DPos      				(15U)
#define SPACC_FIFO_STAT_CMD0_FULL_Pos						SPACC_FIFO_STAT_CMD0_FULL_DPos
#define SPACC_FIFO_STAT_CMD0_FULL_Msk       				(0x1UL << SPACC_FIFO_STAT_CMD0_FULL_Pos)			/* 0x00008000 */
#define SPACC_FIFO_STAT_CMD0_FULL							SPACC_FIFO_STAT_CMD0_FULL_Msk						/* Flag Indicating That The CMD0 FIFO Is Full */

#define SPACC_FIFO_STAT_STAT_CNT_DPos      					(16U)
#define SPACC_FIFO_STAT_STAT_CNT_Pos						SPACC_FIFO_STAT_STAT_CNT_DPos
#define SPACC_FIFO_STAT_STAT_CNT_Msk       					(0xFFUL << SPACC_FIFO_STAT_STAT_CNT_Pos)			/* 0x00FF0000 */
#define SPACC_FIFO_STAT_STAT_CNT							SPACC_FIFO_STAT_STAT_CNT_Msk						/* SPACC Current Number Of Status Values Enqueued In The STAT FIFO */
#define SPACC_FIFO_STAT_STAT_CNT_0							(0x1UL << SPACC_FIFO_STAT_STAT_CNT_Pos)				/* 0x00000001 */
#define SPACC_FIFO_STAT_STAT_CNT_1							(0x2UL << SPACC_FIFO_STAT_STAT_CNT_Pos)				/* 0x00000002 */
#define SPACC_FIFO_STAT_STAT_CNT_2							(0x4UL << SPACC_FIFO_STAT_STAT_CNT_Pos)				/* 0x00000004 */
#define SPACC_FIFO_STAT_STAT_CNT_3							(0x8UL << SPACC_FIFO_STAT_STAT_CNT_Pos)				/* 0x00000008 */
#define SPACC_FIFO_STAT_STAT_CNT_4							(0x10UL << SPACC_FIFO_STAT_STAT_CNT_Pos)			/* 0x00000010 */
#define SPACC_FIFO_STAT_STAT_CNT_5							(0x20UL << SPACC_FIFO_STAT_STAT_CNT_Pos)			/* 0x00000020 */
#define SPACC_FIFO_STAT_STAT_CNT_6							(0x40UL << SPACC_FIFO_STAT_STAT_CNT_Pos)			/* 0x00000040 */
#define SPACC_FIFO_STAT_STAT_CNT_7							(0x80UL << SPACC_FIFO_STAT_STAT_CNT_Pos)			/* 0x00000080 */

#define SPACC_FIFO_STAT_STAT_EMPTY_DPos      				(31U)
#define SPACC_FIFO_STAT_STAT_EMPTY_Pos						SPACC_FIFO_STAT_STAT_EMPTY_DPos
#define SPACC_FIFO_STAT_STAT_EMPTY_Msk       				(0x1UL << SPACC_FIFO_STAT_STAT_EMPTY_Pos)			/* 0x80000000 */
#define SPACC_FIFO_STAT_STAT_EMPTY							SPACC_FIFO_STAT_STAT_EMPTY_Msk						/* Flag Indicating That The STAT FIFO Is Empty */

/******************  Bit definition for SPACC_SRC_PTR register  *******************/
#define SPACC_SRC_PTR_PTR_DPos								(3U)
#define SPACC_SRC_PTR_PTR_Pos								SPACC_SRC_PTR_PTR_DPos
#define SPACC_SRC_PTR_PTR_Msk       						(0x1FFFFFFFUL << SPACC_SRC_PTR_PTR_Pos)				/* 0xFFFFFFF8 */
#define SPACC_SRC_PTR_PTR									SPACC_SRC_PTR_PTR_Msk								/* SPACC Pointer To Source Packet Data Structure In System Memory */
#define SPACC_SRC_PTR_PTR_0									(0x1UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000008 */
#define SPACC_SRC_PTR_PTR_1									(0x2UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000010 */
#define SPACC_SRC_PTR_PTR_2									(0x4UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000020 */
#define SPACC_SRC_PTR_PTR_3									(0x8UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000040 */
#define SPACC_SRC_PTR_PTR_4									(0x10UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000080 */
#define SPACC_SRC_PTR_PTR_5									(0x20UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000100 */
#define SPACC_SRC_PTR_PTR_6									(0x40UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000200 */
#define SPACC_SRC_PTR_PTR_7									(0x80UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000400 */
#define SPACC_SRC_PTR_PTR_8									(0x100UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00000800 */
#define SPACC_SRC_PTR_PTR_9									(0x200UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00001000 */
#define SPACC_SRC_PTR_PTR_10								(0x400UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00002000 */
#define SPACC_SRC_PTR_PTR_11								(0x800UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00004000 */
#define SPACC_SRC_PTR_PTR_12								(0x1000UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00008000 */
#define SPACC_SRC_PTR_PTR_13								(0x2000UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00010000 */
#define SPACC_SRC_PTR_PTR_14								(0x4000UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00020000 */
#define SPACC_SRC_PTR_PTR_15								(0x8000UL << SPACC_SRC_PTR_PTR_Pos)					/* 0x00040000 */
#define SPACC_SRC_PTR_PTR_16								(0x10000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x00080000 */
#define SPACC_SRC_PTR_PTR_17								(0x20000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x00100000 */
#define SPACC_SRC_PTR_PTR_18								(0x40000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x00200000 */
#define SPACC_SRC_PTR_PTR_19								(0x80000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x00400000 */
#define SPACC_SRC_PTR_PTR_20								(0x100000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x00800000 */
#define SPACC_SRC_PTR_PTR_21								(0x200000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x01000000 */
#define SPACC_SRC_PTR_PTR_22								(0x400000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x02000000 */
#define SPACC_SRC_PTR_PTR_23								(0x800000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x04000000 */
#define SPACC_SRC_PTR_PTR_24								(0x1000000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x08000000 */
#define SPACC_SRC_PTR_PTR_25								(0x2000000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x10000000 */
#define SPACC_SRC_PTR_PTR_26								(0x4000000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x20000000 */
#define SPACC_SRC_PTR_PTR_27								(0x8000000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x40000000 */
#define SPACC_SRC_PTR_PTR_28								(0x10000000UL << SPACC_SRC_PTR_PTR_Pos)				/* 0x80000000 */

/******************  Bit definition for SPACC_DST_PTR register  *******************/
#define SPACC_DST_PTR_PTR_DPos								(3U)
#define SPACC_DST_PTR_PTR_Pos								SPACC_DST_PTR_PTR_DPos
#define SPACC_DST_PTR_PTR_Msk       						(0x1FFFFFFFUL << SPACC_DST_PTR_PTR_Pos)				/* 0xFFFFFFF8 */
#define SPACC_DST_PTR_PTR									SPACC_DST_PTR_PTR_Msk								/* SPACC Pointer To Destination Packet Data Structure In System Memory */
#define SPACC_DST_PTR_PTR_0									(0x1UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000008 */
#define SPACC_DST_PTR_PTR_1									(0x2UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000010 */
#define SPACC_DST_PTR_PTR_2									(0x4UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000020 */
#define SPACC_DST_PTR_PTR_3									(0x8UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000040 */
#define SPACC_DST_PTR_PTR_4									(0x10UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000080 */
#define SPACC_DST_PTR_PTR_5									(0x20UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000100 */
#define SPACC_DST_PTR_PTR_6									(0x40UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000200 */
#define SPACC_DST_PTR_PTR_7									(0x80UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000400 */
#define SPACC_DST_PTR_PTR_8									(0x100UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00000800 */
#define SPACC_DST_PTR_PTR_9									(0x200UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00001000 */
#define SPACC_DST_PTR_PTR_10								(0x400UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00002000 */
#define SPACC_DST_PTR_PTR_11								(0x800UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00004000 */
#define SPACC_DST_PTR_PTR_12								(0x1000UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00008000 */
#define SPACC_DST_PTR_PTR_13								(0x2000UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00010000 */
#define SPACC_DST_PTR_PTR_14								(0x4000UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00020000 */
#define SPACC_DST_PTR_PTR_15								(0x8000UL << SPACC_DST_PTR_PTR_Pos)					/* 0x00040000 */
#define SPACC_DST_PTR_PTR_16								(0x10000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x00080000 */
#define SPACC_DST_PTR_PTR_17								(0x20000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x00100000 */
#define SPACC_DST_PTR_PTR_18								(0x40000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x00200000 */
#define SPACC_DST_PTR_PTR_19								(0x80000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x00400000 */
#define SPACC_DST_PTR_PTR_20								(0x100000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x00800000 */
#define SPACC_DST_PTR_PTR_21								(0x200000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x01000000 */
#define SPACC_DST_PTR_PTR_22								(0x400000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x02000000 */
#define SPACC_DST_PTR_PTR_23								(0x800000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x04000000 */
#define SPACC_DST_PTR_PTR_24								(0x1000000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x08000000 */
#define SPACC_DST_PTR_PTR_25								(0x2000000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x10000000 */
#define SPACC_DST_PTR_PTR_26								(0x4000000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x20000000 */
#define SPACC_DST_PTR_PTR_27								(0x8000000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x40000000 */
#define SPACC_DST_PTR_PTR_28								(0x10000000UL << SPACC_DST_PTR_PTR_Pos)				/* 0x80000000 */

/******************  Bit definition for SPACC_OFFSET register  *******************/
#define SPACC_OFFSET_SRC_DPOS								(0U)
#define SPACC_OFFSET_SRC_Pos								SPACC_OFFSET_SRC_DPOS
#define SPACC_OFFSET_SRC_Msk       							(0xFFFUL << SPACC_OFFSET_SRC_Pos)					/* 0x00000FFF */
#define SPACC_OFFSET_SRC									SPACC_OFFSET_SRC_Msk								/* SPACC Source Buffer Offset */
#define SPACC_OFFSET_SRC_0									(0x1UL << SPACC_OFFSET_SRC_Pos)						/* 0x00000001 */
#define SPACC_OFFSET_SRC_1									(0x2UL << SPACC_OFFSET_SRC_Pos)						/* 0x00000002 */
#define SPACC_OFFSET_SRC_2									(0x4UL << SPACC_OFFSET_SRC_Pos)						/* 0x00000004 */
#define SPACC_OFFSET_SRC_3									(0x8UL << SPACC_OFFSET_SRC_Pos)						/* 0x00000008 */
#define SPACC_OFFSET_SRC_4									(0x10UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000010 */
#define SPACC_OFFSET_SRC_5									(0x20UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000020 */
#define SPACC_OFFSET_SRC_6									(0x40UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000040 */
#define SPACC_OFFSET_SRC_7									(0x80UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000080 */
#define SPACC_OFFSET_SRC_8									(0x100UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000100 */
#define SPACC_OFFSET_SRC_9									(0x200UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000200 */
#define SPACC_OFFSET_SRC_10									(0x400UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000400 */
#define SPACC_OFFSET_SRC_11									(0x800UL << SPACC_OFFSET_SRC_Pos)					/* 0x00000800 */

#define SPACC_OFFSET_DST_DPOS								(16U)
#define SPACC_OFFSET_DST_Pos								SPACC_OFFSET_DST_DPOS
#define SPACC_OFFSET_DST_Msk       							(0xFFFUL << SPACC_OFFSET_DST_Pos)					/* 0x0FFF0000 */
#define SPACC_OFFSET_DST									SPACC_OFFSET_DST_Msk								/* SPACC Destination Buffer Offset */
#define SPACC_OFFSET_DST_0									(0x1UL << SPACC_OFFSET_DST_Pos)						/* 0x00000001 */
#define SPACC_OFFSET_DST_1									(0x2UL << SPACC_OFFSET_DST_Pos)						/* 0x00000002 */
#define SPACC_OFFSET_DST_2									(0x4UL << SPACC_OFFSET_DST_Pos)						/* 0x00000004 */
#define SPACC_OFFSET_DST_3									(0x8UL << SPACC_OFFSET_DST_Pos)						/* 0x00000008 */
#define SPACC_OFFSET_DST_4									(0x10UL << SPACC_OFFSET_DST_Pos)					/* 0x00000010 */
#define SPACC_OFFSET_DST_5									(0x20UL << SPACC_OFFSET_DST_Pos)					/* 0x00000020 */
#define SPACC_OFFSET_DST_6									(0x40UL << SPACC_OFFSET_DST_Pos)					/* 0x00000040 */
#define SPACC_OFFSET_DST_7									(0x80UL << SPACC_OFFSET_DST_Pos)					/* 0x00000080 */
#define SPACC_OFFSET_DST_8									(0x100UL << SPACC_OFFSET_DST_Pos)					/* 0x00000100 */
#define SPACC_OFFSET_DST_9									(0x200UL << SPACC_OFFSET_DST_Pos)					/* 0x00000200 */
#define SPACC_OFFSET_DST_10									(0x400UL << SPACC_OFFSET_DST_Pos)					/* 0x00000400 */
#define SPACC_OFFSET_DST_11									(0x800UL << SPACC_OFFSET_DST_Pos)					/* 0x00000800 */

/******************  Bit definition for SPACC_PRE_AAD_LEN register  *******************/
#define SPACC_PRE_AAD_LEN_LEN_DPos	      					(0U)
#define SPACC_PRE_AAD_LEN_LEN_Pos							SPACC_PRE_AAD_LEN_LEN_DPos
#define SPACC_PRE_AAD_LEN_LEN_Msk       					(0x3FFFUL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00003FFF */
#define SPACC_PRE_AAD_LEN_LEN								SPACC_PRE_AAD_LEN_LEN_Msk							/* SPACC Byte Length Of The Prefixed AAD */
#define SPACC_PRE_AAD_LEN_LEN_0								(0x1UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000001 */
#define SPACC_PRE_AAD_LEN_LEN_1								(0x2UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000002 */
#define SPACC_PRE_AAD_LEN_LEN_2								(0x4UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000004 */
#define SPACC_PRE_AAD_LEN_LEN_3								(0x8UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000008 */
#define SPACC_PRE_AAD_LEN_LEN_4								(0x10UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000010 */
#define SPACC_PRE_AAD_LEN_LEN_5								(0x20UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000020 */
#define SPACC_PRE_AAD_LEN_LEN_6								(0x40UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000040 */
#define SPACC_PRE_AAD_LEN_LEN_7								(0x80UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000080 */
#define SPACC_PRE_AAD_LEN_LEN_8								(0x100UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000100 */
#define SPACC_PRE_AAD_LEN_LEN_9								(0x200UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000200 */
#define SPACC_PRE_AAD_LEN_LEN_10							(0x400UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000400 */
#define SPACC_PRE_AAD_LEN_LEN_11							(0x800UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00000800 */
#define SPACC_PRE_AAD_LEN_LEN_12							(0x1000UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00001000 */
#define SPACC_PRE_AAD_LEN_LEN_13							(0x2000UL << SPACC_PRE_AAD_LEN_LEN_Pos)				/* 0x00002000 */

/******************  Bit definition for SPACC_POST_AAD_LEN register  *******************/
#define SPACC_POST_AAD_LEN_LEN_DPos	      					(0U)
#define SPACC_POST_AAD_LEN_LEN_Pos							SPACC_POST_AAD_LEN_LEN_DPos
#define SPACC_POST_AAD_LEN_LEN_Msk       					(0x3FFFUL << SPACC_POST_AAD_LEN_LEN_Pos)			/* 0x00003FFF */
#define SPACC_POST_AAD_LEN_LEN								SPACC_POST_AAD_LEN_LEN_Msk							/* SPACC Byte Length Of The Postfix AAD */
#define SPACC_POST_AAD_LEN_LEN_0							(0x1UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000001 */
#define SPACC_POST_AAD_LEN_LEN_1							(0x2UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000002 */
#define SPACC_POST_AAD_LEN_LEN_2							(0x4UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000004 */
#define SPACC_POST_AAD_LEN_LEN_3							(0x8UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000008 */
#define SPACC_POST_AAD_LEN_LEN_4							(0x10UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000010 */
#define SPACC_POST_AAD_LEN_LEN_5							(0x20UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000020 */
#define SPACC_POST_AAD_LEN_LEN_6							(0x40UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000040 */
#define SPACC_POST_AAD_LEN_LEN_7							(0x80UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000080 */
#define SPACC_POST_AAD_LEN_LEN_8							(0x100UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000100 */
#define SPACC_POST_AAD_LEN_LEN_9							(0x200UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000200 */
#define SPACC_POST_AAD_LEN_LEN_10							(0x400UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000400 */
#define SPACC_POST_AAD_LEN_LEN_11							(0x800UL << SPACC_POST_AAD_LEN_LEN_Pos)				/* 0x00000800 */
#define SPACC_POST_AAD_LEN_LEN_12							(0x1000UL << SPACC_POST_AAD_LEN_LEN_Pos)			/* 0x00001000 */
#define SPACC_POST_AAD_LEN_LEN_13							(0x2000UL << SPACC_POST_AAD_LEN_LEN_Pos)			/* 0x00002000 */

/******************  Bit definition for SPACC_PROC_LEN register  *******************/
#define SPACC_PROC_LEN_LEN_DPos	      						(0U)
#define SPACC_PROC_LEN_LEN_Pos								SPACC_PROC_LEN_LEN_DPos
#define SPACC_PROC_LEN_LEN_Msk       						(0x3FFFUL << SPACC_PROC_LEN_LEN_Pos)				/* 0x00003FFF */
#define SPACC_PROC_LEN_LEN									SPACC_PROC_LEN_LEN_Msk								/* SPACC Byte Length Of The Data To Be Processed */
#define SPACC_PROC_LEN_LEN_0								(0x1UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000001 */
#define SPACC_PROC_LEN_LEN_1								(0x2UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000002 */
#define SPACC_PROC_LEN_LEN_2								(0x4UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000004 */
#define SPACC_PROC_LEN_LEN_3								(0x8UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000008 */
#define SPACC_PROC_LEN_LEN_4								(0x10UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000010 */
#define SPACC_PROC_LEN_LEN_5								(0x20UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000020 */
#define SPACC_PROC_LEN_LEN_6								(0x40UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000040 */
#define SPACC_PROC_LEN_LEN_7								(0x80UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000080 */
#define SPACC_PROC_LEN_LEN_8								(0x100UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000100 */
#define SPACC_PROC_LEN_LEN_9								(0x200UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000200 */
#define SPACC_PROC_LEN_LEN_10								(0x400UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000400 */
#define SPACC_PROC_LEN_LEN_11								(0x800UL << SPACC_PROC_LEN_LEN_Pos)					/* 0x00000800 */
#define SPACC_PROC_LEN_LEN_12								(0x1000UL << SPACC_PROC_LEN_LEN_Pos)				/* 0x00001000 */
#define SPACC_PROC_LEN_LEN_13								(0x2000UL << SPACC_PROC_LEN_LEN_Pos)				/* 0x00002000 */

/******************  Bit definition for SPACC_ICV_LEN register  *******************/
#define SPACC_ICV_LEN_LEN_DPos	      						(0U)
#define SPACC_ICV_LEN_LEN_Pos								SPACC_ICV_LEN_LEN_DPos
#define SPACC_ICV_LEN_LEN_Msk       						(0x3FUL << SPACC_ICV_LEN_LEN_Pos)					/* 0x0000003F */
#define SPACC_ICV_LEN_LEN									SPACC_ICV_LEN_LEN_Msk								/* SPACC Byte Length Of The ICV */
#define SPACC_ICV_LEN_LEN_0									(0x1UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000001 */
#define SPACC_ICV_LEN_LEN_1									(0x2UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000002 */
#define SPACC_ICV_LEN_LEN_2									(0x4UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000004 */
#define SPACC_ICV_LEN_LEN_3									(0x8UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000008 */
#define SPACC_ICV_LEN_LEN_4									(0x10UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000010 */
#define SPACC_ICV_LEN_LEN_5									(0x20UL << SPACC_ICV_LEN_LEN_Pos)					/* 0x00000020 */

/******************  Bit definition for SPACC_ICV_OFFSET register  *******************/
#define SPACC_ICV_OFFSET_OFFSET_DPos	      				(0U)
#define SPACC_ICV_OFFSET_OFFSET_Pos							SPACC_ICV_OFFSET_OFFSET_DPos
#define SPACC_ICV_OFFSET_OFFSET_Msk       					(0x3FFFUL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00003FFF */
#define SPACC_ICV_OFFSET_OFFSET								SPACC_ICV_OFFSET_OFFSET_Msk							/* SPACC Byte Offset Of The ICV */
#define SPACC_ICV_OFFSET_OFFSET_0							(0x1UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000001 */
#define SPACC_ICV_OFFSET_OFFSET_1							(0x2UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000002 */
#define SPACC_ICV_OFFSET_OFFSET_2							(0x4UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000004 */
#define SPACC_ICV_OFFSET_OFFSET_3							(0x8UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000008 */
#define SPACC_ICV_OFFSET_OFFSET_4							(0x10UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000010 */
#define SPACC_ICV_OFFSET_OFFSET_5							(0x20UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000020 */
#define SPACC_ICV_OFFSET_OFFSET_6							(0x40UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000040 */
#define SPACC_ICV_OFFSET_OFFSET_7							(0x80UL << SPACC_ICV_OFFSET_OFFSET_Pos)				/* 0x00000080 */
#define SPACC_ICV_OFFSET_OFFSET_8							(0x100UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00000100 */
#define SPACC_ICV_OFFSET_OFFSET_9							(0x200UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00000200 */
#define SPACC_ICV_OFFSET_OFFSET_10							(0x400UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00000400 */
#define SPACC_ICV_OFFSET_OFFSET_11							(0x800UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00000800 */
#define SPACC_ICV_OFFSET_OFFSET_12							(0x1000UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00001000 */
#define SPACC_ICV_OFFSET_OFFSET_13							(0x2000UL << SPACC_ICV_OFFSET_OFFSET_Pos)			/* 0x00002000 */

/******************  Bit definition for SPACC_IV_OFFSET register  *******************/
#define SPACC_IV_OFFSET_OFFSET_DPos	      					(0U)
#define SPACC_IV_OFFSET_OFFSET_Pos							SPACC_IV_OFFSET_OFFSET_DPos
#define SPACC_IV_OFFSET_OFFSET_Msk       					(0x3FFFUL << SPACC_IV_OFFSET_OFFSET_Pos)			/* 0x00003FFF */
#define SPACC_IV_OFFSET_OFFSET								SPACC_IV_OFFSET_OFFSET_Msk							/* SPACC Byte Offset Of The IV */
#define SPACC_IV_OFFSET_OFFSET_0							(0x1UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000001 */
#define SPACC_IV_OFFSET_OFFSET_1							(0x2UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000002 */
#define SPACC_IV_OFFSET_OFFSET_2							(0x4UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000004 */
#define SPACC_IV_OFFSET_OFFSET_3							(0x8UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000008 */
#define SPACC_IV_OFFSET_OFFSET_4							(0x10UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000010 */
#define SPACC_IV_OFFSET_OFFSET_5							(0x20UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000020 */
#define SPACC_IV_OFFSET_OFFSET_6							(0x40UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000040 */
#define SPACC_IV_OFFSET_OFFSET_7							(0x80UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000080 */
#define SPACC_IV_OFFSET_OFFSET_8							(0x100UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000100 */
#define SPACC_IV_OFFSET_OFFSET_9							(0x200UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000200 */
#define SPACC_IV_OFFSET_OFFSET_10							(0x400UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000400 */
#define SPACC_IV_OFFSET_OFFSET_11							(0x800UL << SPACC_IV_OFFSET_OFFSET_Pos)				/* 0x00000800 */
#define SPACC_IV_OFFSET_OFFSET_12							(0x1000UL << SPACC_IV_OFFSET_OFFSET_Pos)			/* 0x00001000 */
#define SPACC_IV_OFFSET_OFFSET_13							(0x2000UL << SPACC_IV_OFFSET_OFFSET_Pos)			/* 0x00002000 */

#define SPACC_IV_OFFSET_ENABLE_DPos      					(31U)
#define SPACC_IV_OFFSET_ENABLE_Pos							SPACC_IV_OFFSET_ENABLE_DPos
#define SPACC_IV_OFFSET_ENABLE_Msk       					(0x1UL << SPACC_IV_OFFSET_ENABLE_Pos)				/* 0x80000000 */
#define SPACC_IV_OFFSET_ENABLE								SPACC_IV_OFFSET_ENABLE_Msk

/******************  Bit definition for SPACC_SW_CTRL register  *******************/
#define SPACC_SW_CTRL_SW_ID_DPos      						(0U)
#define SPACC_SW_CTRL_SW_ID_Pos								SPACC_SW_CTRL_SW_ID_DPos
#define SPACC_SW_CTRL_SW_ID_Msk       						(0xFFUL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x000000FF */
#define SPACC_SW_CTRL_SW_ID									SPACC_SW_CTRL_SW_ID_Msk								/* Software Tag Of Job ID */
#define SPACC_SW_CTRL_SW_ID_0								(0x1UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000001 */
#define SPACC_SW_CTRL_SW_ID_1								(0x2UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000002 */
#define SPACC_SW_CTRL_SW_ID_2								(0x4UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000004 */
#define SPACC_SW_CTRL_SW_ID_3								(0x8UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000008 */
#define SPACC_SW_CTRL_SW_ID_4								(0x10UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000010 */
#define SPACC_SW_CTRL_SW_ID_5								(0x20UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000020 */
#define SPACC_SW_CTRL_SW_ID_6								(0x40UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000040 */
#define SPACC_SW_CTRL_SW_ID_7								(0x80UL << SPACC_SW_CTRL_SW_ID_Pos)					/* 0x00000080 */

#define SPACC_SW_CTRL_PRIORITY_DPos      					(30U)
#define SPACC_SW_CTRL_PRIORITY_Pos							SPACC_SW_CTRL_PRIORITY_DPos
#define SPACC_SW_CTRL_PRIORITY_Msk       					(0x3UL << SPACC_SW_CTRL_PRIORITY_Pos)				/* 0xC0000000 */
#define SPACC_SW_CTRL_PRIORITY								SPACC_SW_CTRL_PRIORITY_Msk							/* Selects The Prioritized Command FIFO To Be Used For Command Dispatch */
#define SPACC_SW_CTRL_PRIORITY_0							(0x1UL << SPACC_SW_CTRL_PRIORITY_Pos)				/* 0x40000000 */
#define SPACC_SW_CTRL_PRIORITY_1							(0x2UL << SPACC_SW_CTRL_PRIORITY_Pos)				/* 0x80000000 */

/******************  Bit definition for SPACC_AUX_INFO register  *******************/
#define SPACC_AUX_INFO_CBC_CS_SEL_DPos      				(16U)
#define SPACC_AUX_INFO_CBC_CS_SEL_Pos						SPACC_AUX_INFO_CBC_CS_SEL_DPos
#define SPACC_AUX_INFO_CBC_CS_SEL_Msk       				(0x3UL << SPACC_AUX_INFO_CBC_CS_SEL_Pos)			/* 0x00030000 */
#define SPACC_AUX_INFO_CBC_CS_SEL							SPACC_AUX_INFO_CBC_CS_SEL_Msk						/* Selects the CTS mode to apply for SM4-CBC */
#define SPACC_AUX_INFO_CBC_CS_SEL_0							(0x1UL << SPACC_AUX_INFO_CBC_CS_SEL_Pos)			/* 0x00010000 */
#define SPACC_AUX_INFO_CBC_CS_SEL_1							(0x2UL << SPACC_AUX_INFO_CBC_CS_SEL_Pos)			/* 0x00020000 */

/******************  Bit definition for SPACC_CTRL register  *******************/
#define SPACC_CTRL_SM4_CIPH_ALG_DPos      					(0U)
#define SPACC_CTRL_SM4_CIPH_ALG_Pos							SPACC_CTRL_SM4_CIPH_ALG_DPos
#define SPACC_CTRL_SM4_CIPH_ALG_Msk       					(0xFUL << SPACC_CTRL_SM4_CIPH_ALG_Pos)				/* 0x0000000F */
#define SPACC_CTRL_SM4_CIPH_ALG								SPACC_CTRL_SM4_CIPH_ALG_Msk							/* Cipher Algorithm To Employ */
#define SPACC_CTRL_SM4_CIPH_ALG_0							(0x1UL << SPACC_CTRL_SM4_CIPH_ALG_Pos)				/* 0x00000001 */
#define SPACC_CTRL_SM4_CIPH_ALG_1							(0x2UL << SPACC_CTRL_SM4_CIPH_ALG_Pos)				/* 0x00000002 */
#define SPACC_CTRL_SM4_CIPH_ALG_2							(0x4UL << SPACC_CTRL_SM4_CIPH_ALG_Pos)				/* 0x00000004 */
#define SPACC_CTRL_SM4_CIPH_ALG_3							(0x8UL << SPACC_CTRL_SM4_CIPH_ALG_Pos)				/* 0x00000008 */

#define SPACC_CTRL_SM4_CIPH_MODE_DPos      					(4U)
#define SPACC_CTRL_SM4_CIPH_MODE_Pos						SPACC_CTRL_SM4_CIPH_MODE_DPos
#define SPACC_CTRL_SM4_CIPH_MODE_Msk       					(0xFUL << SPACC_CTRL_SM4_CIPH_MODE_Pos)				/* 0x000000F0 */
#define SPACC_CTRL_SM4_CIPH_MODE							SPACC_CTRL_SM4_CIPH_MODE_Msk						/* SM4 Cipher Mode To Use */
#define SPACC_CTRL_SM4_CIPH_MODE_0							(0x1UL << SPACC_CTRL_SM4_CIPH_MODE_Pos)				/* 0x00000010 */
#define SPACC_CTRL_SM4_CIPH_MODE_1							(0x2UL << SPACC_CTRL_SM4_CIPH_MODE_Pos)				/* 0x00000020 */
#define SPACC_CTRL_SM4_CIPH_MODE_2							(0x4UL << SPACC_CTRL_SM4_CIPH_MODE_Pos)				/* 0x00000040 */
#define SPACC_CTRL_SM4_CIPH_MODE_3							(0x8UL << SPACC_CTRL_SM4_CIPH_MODE_Pos)				/* 0x00000080 */

#define SPACC_CTRL_SM_HASH_ALG_DPos      					(8U)
#define SPACC_CTRL_SM_HASH_ALG_Pos							SPACC_CTRL_SM_HASH_ALG_DPos
#define SPACC_CTRL_SM_HASH_ALG_Msk       					(0x1FUL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x0001F00 */
#define SPACC_CTRL_SM_HASH_ALG								SPACC_CTRL_SM_HASH_ALG_Msk							/* Hash Algorithm To Employ */
#define SPACC_CTRL_SM_HASH_ALG_0							(0x1UL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x00000100 */
#define SPACC_CTRL_SM_HASH_ALG_1							(0x2UL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x00000200 */
#define SPACC_CTRL_SM_HASH_ALG_2							(0x4UL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x00000400 */
#define SPACC_CTRL_SM_HASH_ALG_3							(0x8UL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x00000800 */
#define SPACC_CTRL_SM_HASH_ALG_4							(0x10UL << SPACC_CTRL_SM_HASH_ALG_Pos)				/* 0x00001000 */

#define SPACC_CTRL_SM3_HASH_MODE_DPos      					(13U)
#define SPACC_CTRL_SM3_HASH_MODE_Pos						SPACC_CTRL_SM3_HASH_MODE_DPos
#define SPACC_CTRL_SM3_HASH_MODE_Msk       					(0x3UL << SPACC_CTRL_SM3_HASH_MODE_Pos)				/* 0x00006000 */
#define SPACC_CTRL_SM3_HASH_MODE							SPACC_CTRL_SM3_HASH_MODE_Msk						/* SM3 Hash Mode To Use */
#define SPACC_CTRL_SM3_HASH_MODE_0							(0x1UL << SPACC_CTRL_SM3_HASH_MODE_Pos)				/* 0x00002000 */
#define SPACC_CTRL_SM3_HASH_MODE_1							(0x2UL << SPACC_CTRL_SM3_HASH_MODE_Pos)				/* 0x00004000 */

#define SPACC_CTRL_ENCRYPT_DPos      						(15U)
#define SPACC_CTRL_ENCRYPT_Pos								SPACC_CTRL_ENCRYPT_DPos
#define SPACC_CTRL_ENCRYPT_Msk       						(0x1UL << SPACC_CTRL_ENCRYPT_Pos)					/* 0x00008000 */
#define SPACC_CTRL_ENCRYPT									SPACC_CTRL_ENCRYPT_Msk								/* Transform To Apply */

#define SPACC_CTRL_CTX_IDX_DPos      						(16U)
#define SPACC_CTRL_CTX_IDX_Pos								SPACC_CTRL_CTX_IDX_DPos
#define SPACC_CTRL_CTX_IDX_Msk       						(0xFFUL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00FF0000 */
#define SPACC_CTRL_CTX_IDX									SPACC_CTRL_CTX_IDX_Msk								/* Context Index */
#define SPACC_CTRL_CTX_IDX_0								(0x1UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00010000 */
#define SPACC_CTRL_CTX_IDX_1								(0x2UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00020000 */
#define SPACC_CTRL_CTX_IDX_2								(0x4UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00040000 */
#define SPACC_CTRL_CTX_IDX_3								(0x8UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00080000 */
#define SPACC_CTRL_CTX_IDX_4								(0x10UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00100000 */
#define SPACC_CTRL_CTX_IDX_5								(0x20UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00200000 */
#define SPACC_CTRL_CTX_IDX_6								(0x40UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00400000 */
#define SPACC_CTRL_CTX_IDX_7								(0x80UL << SPACC_CTRL_CTX_IDX_Pos)					/* 0x00800000 */

#define SPACC_CTRL_SEC_KEY_DPos      						(24U)
#define SPACC_CTRL_SEC_KEY_Pos								SPACC_CTRL_SEC_KEY_DPos
#define SPACC_CTRL_SEC_KEY_Msk       						(0x1UL << SPACC_CTRL_SEC_KEY_Pos)					/* 0x01000000 */
#define SPACC_CTRL_SEC_KEY									SPACC_CTRL_SEC_KEY_Msk								/* Use The Secure Key Port For Fetching Cipher Key Information */

#define SPACC_CTRL_AAD_COPY_DPos      						(25U)
#define SPACC_CTRL_AAD_COPY_Pos								SPACC_CTRL_AAD_COPY_DPos
#define SPACC_CTRL_AAD_COPY_Msk       						(0x1UL << SPACC_CTRL_AAD_COPY_Pos)					/* 0x02000000 */
#define SPACC_CTRL_AAD_COPY									SPACC_CTRL_AAD_COPY_Msk								/* Copy The PRE_AAD To The Destination Buffer */

#define SPACC_CTRL_ICV_PT_DPos      						(26U)
#define SPACC_CTRL_ICV_PT_Pos								SPACC_CTRL_ICV_PT_DPos
#define SPACC_CTRL_ICV_PT_Msk       						(0x1UL << SPACC_CTRL_ICV_PT_Pos)					/* 0x04000000 */
#define SPACC_CTRL_ICV_PT									SPACC_CTRL_ICV_PT_Msk								/* ICV Computed Set */

#define SPACC_CTRL_ICV_ENC_DPos      						(27U)
#define SPACC_CTRL_ICV_ENC_Pos								SPACC_CTRL_ICV_ENC_DPos
#define SPACC_CTRL_ICV_ENC_Msk       						(0x1UL << SPACC_CTRL_ICV_ENC_Pos)					/* 0x08000000 */
#define SPACC_CTRL_ICV_ENC									SPACC_CTRL_ICV_ENC_Msk								/* ICV Computed Encrypted */

#define SPACC_CTRL_ICV_APPEND_DPos      					(28U)
#define SPACC_CTRL_ICV_APPEND_Pos							SPACC_CTRL_ICV_APPEND_DPos
#define SPACC_CTRL_ICV_APPEND_Msk       					(0x1UL << SPACC_CTRL_ICV_APPEND_Pos)				/* 0x10000000 */
#define SPACC_CTRL_ICV_APPEND								SPACC_CTRL_ICV_APPEND_Msk							/* ICV Computed Appended */

#define SPACC_CTRL_KEY_EXP_DPos      						(29U)
#define SPACC_CTRL_KEY_EXP_Pos								SPACC_CTRL_KEY_EXP_DPos
#define SPACC_CTRL_KEY_EXP_Msk       						(0x1UL << SPACC_CTRL_KEY_EXP_Pos)					/* 0x20000000 */
#define SPACC_CTRL_KEY_EXP									SPACC_CTRL_KEY_EXP_Msk								/* Key Expansion */

#define SPACC_CTRL_MSG_BEGIN_DPos      						(30U)
#define SPACC_CTRL_MSG_BEGIN_Pos							SPACC_CTRL_MSG_BEGIN_DPos
#define SPACC_CTRL_MSG_BEGIN_Msk       						(0x1UL << SPACC_CTRL_MSG_BEGIN_Pos)					/* 0x40000000 */
#define SPACC_CTRL_MSG_BEGIN								SPACC_CTRL_MSG_BEGIN_Msk							/* Begin Flag For Partial Packet Processing */

#define SPACC_CTRL_MSG_END_DPos      						(31U)
#define SPACC_CTRL_MSG_END_Pos								SPACC_CTRL_MSG_END_DPos
#define SPACC_CTRL_MSG_END_Msk       						(0x1UL << SPACC_CTRL_MSG_END_Pos)					/* 0x80000000*/
#define SPACC_CTRL_MSG_END									SPACC_CTRL_MSG_END_Msk								/* End Flag For Partial Packet Processing */

/******************  Bit definition for SPACC_STAT_POP register  *******************/
#define SPACC_STAT_POP_POP_DPos      						(0U)
#define SPACC_STAT_POP_POP_Pos								SPACC_STAT_POP_POP_DPos
#define SPACC_STAT_POP_POP_Msk       						(0x1UL << SPACC_STAT_POP_POP_Pos)					/* 0x00000001 */
#define SPACC_STAT_POP_POP									SPACC_STAT_POP_POP_Msk								/* SPACC Status FIFO Pop */

/******************  Bit definition for SPACC_STATUS register  *******************/
#define SPACC_STATUS_SW_ID_DPos      						(0U)
#define SPACC_STATUS_SW_ID_Pos								SPACC_STATUS_SW_ID_DPos
#define SPACC_STATUS_SW_ID_Msk       						(0xFFUL << SPACC_STATUS_SW_ID_Pos)					/* 0x000000FF */
#define SPACC_STATUS_SW_ID									SPACC_STATUS_SW_ID_Msk								/* Software Tag Of Job ID */
#define SPACC_STATUS_SW_ID_0								(0x1UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000001 */
#define SPACC_STATUS_SW_ID_1								(0x2UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000002 */
#define SPACC_STATUS_SW_ID_2								(0x4UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000004 */
#define SPACC_STATUS_SW_ID_3								(0x8UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000008 */
#define SPACC_STATUS_SW_ID_4								(0x10UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000010 */
#define SPACC_STATUS_SW_ID_5								(0x20UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000020 */
#define SPACC_STATUS_SW_ID_6								(0x40UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000040 */
#define SPACC_STATUS_SW_ID_7								(0x80UL << SPACC_STATUS_SW_ID_Pos)					/* 0x00000080 */

#define SPACC_STATUS_RET_CODE_DPos      					(24U)
#define SPACC_STATUS_RET_CODE_Pos							SPACC_STATUS_RET_CODE_DPos
#define SPACC_STATUS_RET_CODE_Msk       					(0x7UL << SPACC_STATUS_RET_CODE_Pos)				/* 0x07000000 */
#define SPACC_STATUS_RET_CODE								SPACC_STATUS_RET_CODE_Msk							/* Result Of Operation */
#define SPACC_STATUS_RET_CODE_0								(0x1UL << SPACC_STATUS_RET_CODE_Pos)				/* 0x00000001 */
#define SPACC_STATUS_RET_CODE_1								(0x2UL << SPACC_STATUS_RET_CODE_Pos)				/* 0x00000002 */
#define SPACC_STATUS_RET_CODE_2								(0x4UL << SPACC_STATUS_RET_CODE_Pos)				/* 0x00000004 */

#define SPACC_STATUS_SEC_CMD_DPos      						(31U)
#define SPACC_STATUS_SEC_CMD_Pos							SPACC_STATUS_SEC_CMD_DPos
#define SPACC_STATUS_SEC_CMD_Msk       						(0x1UL << SPACC_STATUS_SEC_CMD_Pos)					/* 0x80000000 */
#define SPACC_STATUS_SEC_CMD								SPACC_STATUS_SEC_CMD_Msk							/* Indicates If The Command Executed In Secure Or Normal Mode */

/******************  Bit definition for SPACC_STAT_WD_CTRL register  *******************/
#define SPACC_STAT_WD_CTRL_TIMER_DPos      					(0U)
#define SPACC_STAT_WD_CTRL_TIMER_Pos						SPACC_STAT_WD_CTRL_TIMER_DPos
#define SPACC_STAT_WD_CTRL_TIMER_Msk       					(0xFFFFFFUL << SPACC_STAT_WD_CTRL_TIMER_Pos)		/* 0x00FFFFFF */
#define SPACC_STAT_WD_CTRL_TIMER							SPACC_STAT_WD_CTRL_TIMER_Msk						/* SPACC Status Watchdog Timer */
#define SPACC_STAT_WD_CTRL_TIMER_0							(0x1UL << SPACC_STAT_WD_CTRL_TIMER_Pos)				/* 0x00000001 */
#define SPACC_STAT_WD_CTRL_TIMER_1							(0x2UL << SPACC_STAT_WD_CTRL_TIMER_Pos)				/* 0x00000002 */
#define SPACC_STAT_WD_CTRL_TIMER_2							(0x4UL << SPACC_STAT_WD_CTRL_TIMER_Pos)				/* 0x00000004 */
#define SPACC_STAT_WD_CTRL_TIMER_3							(0x8UL << SPACC_STAT_WD_CTRL_TIMER_Pos)				/* 0x00000008 */
#define SPACC_STAT_WD_CTRL_TIMER_4							(0x10UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000010 */
#define SPACC_STAT_WD_CTRL_TIMER_5							(0x20UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000020 */
#define SPACC_STAT_WD_CTRL_TIMER_6							(0x40UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000040 */
#define SPACC_STAT_WD_CTRL_TIMER_7							(0x80UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000080 */
#define SPACC_STAT_WD_CTRL_TIMER_8							(0x100UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000100 */
#define SPACC_STAT_WD_CTRL_TIMER_9							(0x200UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000200 */
#define SPACC_STAT_WD_CTRL_TIMER_10							(0x400UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000400 */
#define SPACC_STAT_WD_CTRL_TIMER_11							(0x800UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00000800 */
#define SPACC_STAT_WD_CTRL_TIMER_12							(0x1000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00001000 */
#define SPACC_STAT_WD_CTRL_TIMER_13							(0x2000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00002000 */
#define SPACC_STAT_WD_CTRL_TIMER_14							(0x4000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00004000 */
#define SPACC_STAT_WD_CTRL_TIMER_15							(0x8000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00008000 */
#define SPACC_STAT_WD_CTRL_TIMER_16							(0x10000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00010000 */
#define SPACC_STAT_WD_CTRL_TIMER_17							(0x20000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00020000 */
#define SPACC_STAT_WD_CTRL_TIMER_18							(0x40000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00040000 */
#define SPACC_STAT_WD_CTRL_TIMER_19							(0x80000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)			/* 0x00080000 */
#define SPACC_STAT_WD_CTRL_TIMER_20							(0x100000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)		/* 0x00100000 */
#define SPACC_STAT_WD_CTRL_TIMER_21							(0x200000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)		/* 0x00200000 */
#define SPACC_STAT_WD_CTRL_TIMER_22							(0x400000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)		/* 0x00400000 */
#define SPACC_STAT_WD_CTRL_TIMER_23							(0x800000UL << SPACC_STAT_WD_CTRL_TIMER_Pos)		/* 0x00800000 */

/******************  Bit definition for SPACC_KEY_SZ register  *******************/
#define SPACC_KEY_SZ_SIZE_DPos      						(0U)
#define SPACC_KEY_SZ_SIZE_Pos								SPACC_KEY_SZ_SIZE_DPos
#define SPACC_KEY_SZ_SIZE_Msk       						(0xFFUL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x000000FF */
#define SPACC_KEY_SZ_SIZE									SPACC_KEY_SZ_SIZE_Msk								/* Key Size */
#define SPACC_KEY_SZ_SIZE_0									(0x1UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000001 */
#define SPACC_KEY_SZ_SIZE_1									(0x2UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000002 */
#define SPACC_KEY_SZ_SIZE_2									(0x4UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000004 */
#define SPACC_KEY_SZ_SIZE_3									(0x8UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000008 */
#define SPACC_KEY_SZ_SIZE_4									(0x10UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000010 */
#define SPACC_KEY_SZ_SIZE_5									(0x20UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000020 */
#define SPACC_KEY_SZ_SIZE_6									(0x40UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000040 */
#define SPACC_KEY_SZ_SIZE_7									(0x80UL << SPACC_KEY_SZ_SIZE_Pos)					/* 0x00000080 */

#define SPACC_KEY_SZ_CTX_IDX_DPos      						(8U)
#define SPACC_KEY_SZ_CTX_IDX_Pos							SPACC_KEY_SZ_CTX_IDX_DPos
#define SPACC_KEY_SZ_CTX_IDX_Msk       						(0xFFUL << SPACC_KEY_SZ_CTX_IDX_Pos)				/* 0x0000FF00 */
#define SPACC_KEY_SZ_CTX_IDX								SPACC_KEY_SZ_CTX_IDX_Msk							/* Context Index */
#define SPACC_KEY_SZ_CTX_IDX_0								(0x1UL << SPACC_KEY_SZ_CTX_IDX_Pos)					/* 0x00000100 */
#define SPACC_KEY_SZ_CTX_IDX_1								(0x2UL << SPACC_KEY_SZ_CTX_IDX_Pos)					/* 0x00000200 */
#define SPACC_KEY_SZ_CTX_IDX_2								(0x4UL << SPACC_KEY_SZ_CTX_IDX_Pos)					/* 0x00000400 */
#define SPACC_KEY_SZ_CTX_IDX_3								(0x8UL << SPACC_KEY_SZ_CTX_IDX_Pos)					/* 0x00000800 */
#define SPACC_KEY_SZ_CTX_IDX_4								(0x10UL << SPACC_KEY_SZ_CTX_IDX_Pos)				/* 0x00001000 */
#define SPACC_KEY_SZ_CTX_IDX_5								(0x20UL << SPACC_KEY_SZ_CTX_IDX_Pos)				/* 0x00002000 */
#define SPACC_KEY_SZ_CTX_IDX_6								(0x40UL << SPACC_KEY_SZ_CTX_IDX_Pos)				/* 0x00004000 */
#define SPACC_KEY_SZ_CTX_IDX_7								(0x80UL << SPACC_KEY_SZ_CTX_IDX_Pos)				/* 0x00008000 */

#define SPACC_KEY_SZ_CIPHER_DPos      						(31U)
#define SPACC_KEY_SZ_CIPHER_Pos								SPACC_KEY_SZ_CIPHER_DPos
#define SPACC_KEY_SZ_CIPHER_Msk       						(0x1UL << SPACC_KEY_SZ_CIPHER_Pos)					/* 0x80000000 */
#define SPACC_KEY_SZ_CIPHER									SPACC_KEY_SZ_CIPHER_Msk								/* Indicates Whether This Key Size Is A Cipher Key Or A Hash Key */

#ifdef __cplusplus
}
#endif

#endif

/*****END OF FILE*****/
