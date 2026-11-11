/*
 *   __ _   _ __    ___  (_) | | (_)   ___
 *  / _` | | '_ \  / __| | | | | | |  / __|
 * | (_| | | | | | \__ \ | | | | | | | (__
 *  \__,_| |_| |_| |___/ |_| |_| |_|  \___|
 *
 * Copyright (C):  	Xiamen Guoke Anxin Technology Co., LTD
 * FileName:     	as32x601_fcu.c
 * Author:          ANSILIC APPLICATION GROUP
 * Version:         V1.0
 * Date:			2024/07/10
 * History:
 *               <author>           <time>    <version >      <desc>
 *     ANSILIC APPLICATION GROUP  2024/07/10     1.0     build this module
 * Description:     This file provides firmware functions to manage the functionalities of the FCU peripheral.
 */

#include "as32x601_fcu.h"

/*
 * Function:        FCU_StructInit
 * Description:     Fills each SPI_InitStruct member with its default value.
 * Param:           SPI_InitStruct : pointer to a SPI_InitTypeDef structure which will be initialized.
 * Return:          None
 */
void FCU_StructInit(FCU_InitTypeDef *FCU_InitStruct)
{
    /* Reset FCU init structure parameters values */
    FCU_InitStruct->FCU_Channel             = FCU_CHANNEL_EXTENDFAULT1;     /* Specifies the channel to be configured */
    FCU_InitStruct->FCU_FOCUToResetCnt      = 0;                            /* Specifies the count to reset under FOCU */
    FCU_InitStruct->FCU_AlarmToFaultCnt     = 0;                            /* Specifies the count to change the level from alarm to fault */
    FCU_InitStruct->FCU_FaultAction         = GLOBAL_SOFTWARE_RESET;        /* Specifies the actin when the fault occured every time */
    FCU_InitStruct->FCU_AlarmAction         = NONE;                         /* Specifies the actin when the alarm occured every time */
    FCU_InitStruct->FCU_FaultLevel          = INGORY;                       /* Specifies the fault level */
    FCU_InitStruct->FCU_MaskEnable          = ENABLE;                       /* Specifies the mask enable */
}

/*
 * Function:        FCU_Init
 * Description:     Initializes the FCU peripheral according to the specified parameters in the FCU_InitStruct.
 * Param:           FCU_InitStruct: pointer to a FCU_InitTypeDef structure that contains the configuration information for the FCU peripheral.
 * Return:          None
 */
void FCU_Init(FCU_InitTypeDef *FCU_InitStruct)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_FCU_CHANNEL(FCU_InitStruct->FCU_Channel));
    assert_param(IS_FAULTTORESET_COUNT(FCU_InitStruct->FCU_FOCUToResetCnt));
    assert_param(IS_ALARMTOFAULT_COUNT(FCU_InitStruct->FCU_AlarmToFaultCnt));
    assert_param(IS_FAULTACTION_STATE(FCU_InitStruct->FCU_FaultAction));
    assert_param(IS_ALARMACTION_STATE(FCU_InitStruct->FCU_AlarmAction));
    assert_param(IS_FAULTLEVEL_STATE(FCU_InitStruct->FCU_FaultLevel));
    assert_param(IS_FunctionalState_STATE(FCU_InitStruct->FCU_MaskEnable));

    /* Set the SPI clock frequency division */
    tmpreg = FCU->CFG[FCU_InitStruct->FCU_Channel];
    tmpreg &= ~((uint32_t)0x7FFFE);
    tmpreg |= ((uint32_t)(FCU_InitStruct->FCU_FOCUToResetCnt << FCU_CFG_FOCU_CNT_Pos)      | 
                            (FCU_InitStruct->FCU_AlarmToFaultCnt << FCU_CFG_ATF_CNT_Pos)    |  
                            (FCU_InitStruct->FCU_FaultAction << FCU_CFG_FACT_Pos)           | 
                            (FCU_InitStruct->FCU_AlarmAction << FCU_CFG_AACT_Pos)           | 
                            (FCU_InitStruct->FCU_FaultLevel << FCU_CFG_LEVEL_Pos)           |
                            (FCU_InitStruct->FCU_MaskEnable << FCU_CFG_MASK_Pos));
    FCU->CFG[FCU_InitStruct->FCU_Channel]= tmpreg;
}

/*
 * Function:        FCU_Cmd
 * Description:     Enables or disables the specific fcu channel.
 * Param:           Channelx: where x can be (FCU_CHANNEL_CPUDCLS...FCU_CHANNEL_EXTENDFAULT1) defined in as32x601.h to select the fcu channel.
 *                  NewState: new state of the fcu channel.
 *                   This parameter can be: ENABLE or DISABLE.
 * Return:          None.
 */
void FCU_Cmd(FCUCHANNEL_TypeDef Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_EnState_STATE(NewState));
    assert_param(IS_FCU_CHANNEL(Channelx));

    if (NewState != DISABLE) 
    {
        FCU->CFG[Channelx] |= ((uint32_t)FCU_CFG_EN);
    } 
    else
    {
        FCU->CFG[Channelx] &= ~((uint32_t)FCU_CFG_EN);
    }
}

/*
 * Function:        FCU_SetSoftwareTrigger
 * Description:     Set the software channel to trigger fault once.
 * Param:           SoftwareChannelx: where x can be (FCU_SOFTWARE_CHANNEL_0...3) to select the software channel.
 * Return:          None.
 */
void FCU_SetSoftwareTrigger(uint32_t SoftwareChannelx)
{
    /* Check the parameters */
    assert_param(IS_SOFTWARE_CHANNEL(SoftwareChannelx));

    FCU->SFTR = SoftwareChannelx;
}

/*
 * Function:        FCU_GetSoftwareFaultStatus
 * Description:     Get the software channel fault status.
 * Param:           SoftwareChannelx: where x can be (FCU_SOFTWARE_CHANNEL_0...3) to select the software channel.
 * Return:          None.
 */
FlagStatus FCU_GetSoftwareFaultStatus(uint32_t SoftwareChannelx)
{
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_SOFTWARE_CHANNEL(SoftwareChannelx));

    if(SoftwareChannelx & FCU->SFSTA)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    
    return bitstatus;
}

/*
 * Function:        FCU_SetSoftwareFaultCount
 * Description:     Set the software channel fault count.
 * Param:           SoftwareChannelx: where x can be (FCU_SOFTWARE_CHANNEL_0...3) to select the software channel.
 * Return:          None.
 */
void FCU_SetSoftwareFaultCount(uint32_t SoftwareChannelx, uint8_t count)
{
    /* Check the parameters */
    assert_param(IS_SOFTWARE_CHANNEL(SoftwareChannelx));
    assert_param(IS_SOFTWARE_COUNT(count));

    if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_0)
    {
        FCU->SFCNT &= ~FCU_SFCNT_CNT0 ;
        FCU->SFCNT |= (uint32_t)(count << FCU_SFCNT_CNT0_Pos) ;
    }
    if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_1)
    {
        FCU->SFCNT &= ~FCU_SFCNT_CNT1 ;
        FCU->SFCNT |= (uint32_t)(count << FCU_SFCNT_CNT1_Pos) ;
    }
    if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_2)
    {
        FCU->SFCNT &= ~FCU_SFCNT_CNT2 ;
        FCU->SFCNT |= (uint32_t)(count << FCU_SFCNT_CNT2_Pos) ;
    }
    if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_3)
    {
        FCU->SFCNT &= ~FCU_SFCNT_CNT3 ;
        FCU->SFCNT |= (uint32_t)(count << FCU_SFCNT_CNT3_Pos) ;
    }

}

/*
 * Function:        FCU_GetSoftwareFaultCount
 * Description:     Get the software channel fault count.
 * Param:           SoftwareChannelx: where x can be (FCU_SOFTWARE_CHANNEL_0...3) to select the software channel.
 * Return:          None.
 */
uint8_t FCU_GetSoftwareFaultCount(uint32_t SoftwareChannelx)
{
    uint8_t tmpreg = 0;

    /* Check the parameters */
    assert_param(IS_SOFTWARE_CHANNEL(SoftwareChannelx));

     if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_0)
     {
        tmpreg = (uint8_t)(FCU->SFCNT >> FCU_SFCNT_CNT0_Pos) & 0xff;
     }
     if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_1)
     {
        tmpreg = (uint8_t)(FCU->SFCNT >> FCU_SFCNT_CNT1_Pos) & 0xff;
     }
     if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_2)
     {
        tmpreg = (uint8_t)(FCU->SFCNT >> FCU_SFCNT_CNT2_Pos) & 0xff;
     }
     if(SoftwareChannelx & FCU_SOFTWARE_CHANNEL_3)
     {
        tmpreg = (uint8_t)(FCU->SFCNT >> FCU_SFCNT_CNT3_Pos) & 0xff;
     }
   
    return tmpreg;
}

/*
 * Function:        FCU_ClearSoftwareFault
 * Description:     Clear the software channel fault count.
 * Param:           SoftwareChannelx: where x can be (FCU_SOFTWARE_CHANNEL_0...3) to select the software channel.
 * Return:          None.
 */
void FCU_ClearSoftwareFault(uint32_t SoftwareChannelx)
{
    /* Check the parameters */
    assert_param(IS_SOFTWARE_CHANNEL(SoftwareChannelx));

    FCU->SFCLR |= SoftwareChannelx;
}


/*
 * Function:        FCU_GetAlarmStatus
 * Description:     Get the fcu alarm count.
 * Param:           Channelx: where x can be (FCU_CHANNEL_CPUDCLS...FCU_CHANNEL_EXTENDFAULT1) defined in as32x601.h to select the fcu channel.
 * Return:          None.
 */
FlagStatus FCU_GetAlarmStatus(FCUCHANNEL_TypeDef Channelx)
{
     FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_FCU_CHANNEL(Channelx));

    if(Channelx < 32)
    {
        if((FCU->ALARM0 & (1 << Channelx)) != 0)
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    else
    {
        if((FCU->ALARM1 & (1 << (Channelx - 32))) != 0)
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    return bitstatus;
}

/*
 * Function:        FCU_GetFaultStatus
 * Description:     Get the fcu fault count.
 * Param:           Channelx: where x can be (FCU_CHANNEL_CPUDCLS...FCU_CHANNEL_EXTENDFAULT1) defined in as32x601.h to select the fcu channel.
 * Return:          None.
 */
FlagStatus FCU_GetFaultStatus(FCUCHANNEL_TypeDef Channelx)
{
     FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_FCU_CHANNEL(Channelx));

    if(Channelx < 32)
    {
        if((FCU->FAULT0 & (1 << Channelx)) != 0)
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    else
    {
        if((FCU->FAULT1 & (1 << (Channelx - 32))) != 0)
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    return bitstatus;
}

/*
 * Function:        FCU_ClearFcuStatus
 * Description:     Clear the fcu alarm or fault state.
 * Param:           Channelx: where x can be (FCU_CHANNEL_CPUDCLS...FCU_CHANNEL_EXTENDFAULT1) defined in as32x601.h to select the fcu channel.
 * Return:          None.
 */
void FCU_ClearFcuStatus(FCUCHANNEL_TypeDef Channelx)
{

    /* Check the parameters */
    assert_param(IS_FCU_CHANNEL(Channelx));

    if(Channelx < 32)
    {
        FCU->CLEAR0 |= (uint32_t)(1 << Channelx);
    }
    else
    {
        FCU->CLEAR1 |= (uint32_t)(1 << (Channelx - 32));
    }
}

/*
 * Function:        void FCU_ClearBusTimeoutFaultStatus(void)
 * Description:     Clear the bus timeout state.
 * Param:           None.
 * Return:          None.
 */
void FCU_ClearBusTimeoutFaultStatus(void)
{
    FCU->OCLR |= FCU_OCLR_BTOC;
}

/*
 * Function:        void FCU_ClearECCFaultStatus(void)
 * Description:     Clear the bus timeout state.
 * Param:           None.
 * Return:          None.
 */
void FCU_ClearECCFaultStatus(void)
{
    FCU->OCLR |= FCU_OCLR_ECCC;
}

/*****END OF FILE*****/
