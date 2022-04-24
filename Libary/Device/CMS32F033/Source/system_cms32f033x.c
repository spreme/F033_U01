/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/****************************************************************************/
/** \file system_cms32f030x.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms32f033x.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/


/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/
uint32_t SystemCoreClock = __HIRC_48M; 	/*ϵͳĬ��ѡ�񲢿���48M����ʱ��*/
uint32_t SystemAPBClock = __HIRC_48M;    
uint32_t CyclesPerUs;       
/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/



/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/
uint32_t HSIClock[4] ={__HIRC_64M, NULL, NULL, __HIRC_48M};

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 SystemInit
 **
 ** \param [in]  none   
 ** \return none
 ** \note  not use
*****************************************************************************/
void  SystemInit(void)
{	
	;
} 

/*****************************************************************************
 ** \brief	 SystemCoreClockUpdate
 **			 		����SystemCoreClockֵ
 ** \param [in]  none   
 ** \return none
 ** \note  
*****************************************************************************/
void  SystemCoreClockUpdate(void)
{	
	uint32_t HSIClk;
	uint32_t AHBClk, AHBClkDiv;
	uint32_t APBClkDiv;
	
	HSIClk  = HSIClock[(SYS->CLKCON & SYS_CLKCON_IRCSEL_Msk)];		/*��ȡHSI��ֵ*/
	
	if(SYS_CLK_SEL_HSI == (SYS->CLKSEL & SYS_CLKSEL_CLKSEL_Msk))	/*��ȡAHB��ֵ*/
	{
		AHBClk = HSIClk;
	}
	else if(SYS_CLK_SEL_LSI == (SYS->CLKSEL & SYS_CLKSEL_CLKSEL_Msk))
	{
		AHBClk = __LIRC;
	}
	
	AHBClkDiv = (SYS->AHBCKDIV & SYS_APBCKDIV_APBDIV_Msk) * 2;		/*��ȡAHB��Ƶ*/
	if( 0 == AHBClkDiv)
	{
		SystemCoreClock = AHBClk;									/*��ȡSystemCoreClock*/
	}	
	else
	{
		SystemCoreClock = AHBClk / AHBClkDiv;
	}
	
	APBClkDiv = (SYS->APBCKDIV & SYS_APBCKDIV_APBDIV_Msk) * 2;		/*��ȡAPB��Ƶ*/	
	if( 0 == APBClkDiv)
	{
		SystemAPBClock = AHBClk;									/*��ȡSystemAPBClock*/
	}
	else
	{
		SystemAPBClock = AHBClk / APBClkDiv;
	}
} 













