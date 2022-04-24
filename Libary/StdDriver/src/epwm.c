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
/** \file epwm.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "epwm.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/


/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 EPWM_ConfigRunMode
 **			 ����EPWM������ģʽ
 ** \param [in] EpwmRunMode: (1)EPWM_COUNT_UP_DOWN
							   (2)EPWM_COUNT_DOWN
							   (3)EPWM_OCU_ASYMMETRIC
							   (4)EPWM_OCU_SYMMETRIC
							   (5)EPWM_WFG_INDEPENDENT
							   (6)EPWM_WFG_COMPLEMENTARY
							   (7)EPWM_WFG_SYNCHRONIZED
							   (8)EPWM_OC_MODE_GROUP
							   (9)EPWM_OC_INDEPENDENT
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_ConfigRunMode(uint32_t EpwmRunMode)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;
	EPWM->CON &= ~(EPWM_CON_MODE_Msk | EPWM_CON_GROUNPEN_Msk | EPWM_CON_ASYMEN_Msk);
	EPWM->CON |= EpwmRunMode;
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelClk	
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **				ClkDiv: (1)EPWM_CLK_DIV_1 
 **						(2)EPWM_CLK_DIV_2
 **						(3)EPWM_CLK_DIV_4
 **						(4)EPWM_CLK_DIV_8
 **						(5)EPWM_CLK_DIV_16
 **						(6)EPWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)����ΪCLKPSC01��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����CLKPSC01=0x01
 **     ����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ.
 **	(2)EPWM ��Ƶ��Ϊ������CLKPSC CLKDIV
 **		��һ����Ƶ(CLKPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ ��������ϵͳʱ�ӷ�Ƶϵ�� CLKPSC+1
 **		�ڶ�����Ƶ��CLKDIV): 0x00 FEPWMPSC/2; 0x01 FEPWMPSC/4��0x02:FEPWMPSC/8��0x3 FEPWMPSC/16 0x04 FEPWMPSC ; ���� Fsys 
 ** 	��Ƶ������1~4096����Fsys=8M��EPWM��Ƶ�ʷ�Χ��1.95k ~ 8M	   
*****************************************************************************/
void EPWM_ConfigChannelClk(uint32_t EPWMn,uint32_t ClkDiv)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CLKPSC = (0x01<<EPWM_CLKPSC_CLKPSC45_Pos |
					0x01<<EPWM_CLKPSC_CLKPSC23_Pos |
					0x01<<EPWM_CLKPSC_CLKPSC01_Pos);
	EPWM->CLKDIV &= ~(0xfUL <<(EPWMn*4));
	EPWM->CLKDIV |= (ClkDiv <<(EPWMn*4));		
	EPWM->LOCK = 0x0;
}

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelPeriod	
 **			 ����EPWMͨ��������
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
*****************************************************************************/
void EPWM_ConfigChannelPeriod(uint32_t EPWMn, uint32_t Period)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;		
	EPWM->PERIOD[EPWMn] = 0xffff & Period;
	EPWM->CON3 |= (0x1UL <<(EPWMn + EPWM_CON3_LOADEN0_Pos));		/*ʹ�ܼ�������&&ռ�ձ�*/
	EPWM->LOCK = 0x0;
}

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelSymDuty	
 **			 ���öԳ�ģʽ�µ�EPWMͨ����ռ�ձ�
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			    Duty  : 16λ�Ƚ�ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelSymDuty(uint32_t EPWMn,uint32_t Duty)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;		
	EPWM->CMPADT[EPWMn] &= 0xffff0000;
	EPWM->CMPADT[EPWMn] |= 0xffff & Duty;	
	EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos));		/*ʹ�ܼ�������&&ռ�ձ�*/
	EPWM->LOCK = 0x0;
}

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelAsymDuty	
 **			 ���÷ǶԳ�ģʽ�µ� EPWMͨ����ռ�ձ�
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			    UpCmp 	  : 16λ���ϱȽ�ֵ
 **			    DownCmp   : 16λ���±Ƚ�ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelAsymDuty(uint32_t EPWMn,uint32_t UpCmp, uint32_t DownCmp)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;		
	EPWM->CMPADT[EPWMn] = (0xffff & UpCmp) | ((0xffff & DownCmp)<<16);	
	EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos));		/*ʹ�ܼ�������&&ռ�ձ�*/
	EPWM->LOCK = 0x0;
}

/*****************************************************************************
 ** \brief	 EPWM_EnableOneShotMode	
 **			 ʹ�ܵ���ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableOneShotMode(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON &= ~(EPWMnMask); 
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_EnableAutoLoadMode	
 **			 ʹ����������ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableAutoLoadMode(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON |= EPWMnMask; 
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigLoadAndIntMode
 **			 ���ü��ط�ʽ�Լ��жϷ�ʽ
 ** \param [in]  EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **				 Mode: (1)EPWM_EACH_PERIOD_ZERO
 **					   (2)EPWM_EACH_ZERO
 **					   (3)EPWM_FIRST_ZERO_NEXT_PERIOD
 **					   (4)EPWM_EVERY_TWO_ZERO
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigLoadAndIntMode(uint32_t EPWMn, uint32_t Mode)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON3 &= ~(0x3UL<< ((EPWMn*2) + EPWM_CON3_LOADTYP0_Pos));
	EPWM->CON3 |= Mode << ((EPWMn*2) + EPWM_CON3_LOADTYP0_Pos);	
	EPWM->LOCK = 0x0;			
}


/*****************************************************************************
 ** \brief	 EPWM_EnableReverseOutput	
 **			 �����������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableReverseOutput(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON |= (EPWMnMask<< EPWM_CON_PINV0_Pos); 
	EPWM->LOCK = 0x0;	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableReverseOutput	
 **			 �رշ������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableReverseOutput(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON &= ~(EPWMnMask<< EPWM_CON_PINV0_Pos); 
	EPWM->LOCK = 0x0;	
}

/*****************************************************************************
 ** \brief	 EPWM_EnableDeadZone	
 **			 ��������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 **				DeadZone : 0x00 ~ 0x3FF;
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableDeadZone(uint32_t EPWMnMask, uint32_t DeadZone)
{
	
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	if(( EPWMnMask & EPWM_CH_0_MSK) || (EPWMnMask & EPWM_CH_1_MSK))
	{
		EPWM->CON |= EPWM_CON_ENDT01_Msk;
		EPWM->DTCTL &= ~(EPWM_DTCTL_DTI01_Msk);
		EPWM->DTCTL |= 0x3ff & DeadZone;
	}
	if(( EPWMnMask & EPWM_CH_2_MSK) || (EPWMnMask & EPWM_CH_3_MSK))
	{
		EPWM->CON |= EPWM_CON_ENDT23_Msk;
		EPWM->DTCTL &= ~(EPWM_DTCTL_DTI23_Msk);
		EPWM->DTCTL |=  ((0x3ff & DeadZone)<<EPWM_DTCTL_DTI23_Pos);
	}	
	if(( EPWMnMask & EPWM_CH_4_MSK) || (EPWMnMask & EPWM_CH_5_MSK))
	{
		EPWM->CON |= EPWM_CON_ENDT45_Msk;
		EPWM->DTCTL &= ~(EPWM_DTCTL_DTI45_Msk);
		EPWM->DTCTL |= (0x3ff & DeadZone) << EPWM_DTCTL_DTI45_Pos;
	}	
	EPWM->LOCK = 0x0;	
}

/*****************************************************************************
 ** \brief	 EPWM_DisableDeadZone	
 **			 �ر�����
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableDeadZone(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	if(( EPWMnMask & EPWM_CH_0_MSK) || (EPWMnMask & EPWM_CH_1_MSK))
	{
		EPWM->CON &= ~(EPWM_CON_ENDT01_Msk);
	}
	if(( EPWMnMask & EPWM_CH_2_MSK) || (EPWMnMask & EPWM_CH_3_MSK))
	{
		EPWM->CON &= ~(EPWM_CON_ENDT23_Msk);
	}	
	if(( EPWMnMask & EPWM_CH_4_MSK) || (EPWMnMask & EPWM_CH_5_MSK))
	{
		EPWM->CON &= ~(EPWM_CON_ENDT45_Msk);
	}	
	EPWM->LOCK = 0x0;	
}


/*****************************************************************************
 ** \brief	 EPWM_EnableOutput
 **			 ����EPWMͨ�����
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void EPWM_EnableOutput(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->POEN |= EPWMnMask;
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableOutput
 **			 �ر�EPWMͨ�����
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableOutput(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->POEN &= ~(EPWMnMask);
	EPWM->LOCK = 0x0;	
}

/*****************************************************************************
 ** \brief	 EPWM_Start	
 **			 ����EPWM
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Start(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON2 |= EPWMnMask;	
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_Stop	
 **			 �ر�EPWM
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Stop(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->CON2 &= ~(EPWMnMask);			
	EPWM->CON3 |= EPWMnMask;			/*������0*/
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_ForceStop	
 **			 ǿ�ƹر�EPWM
 ** \param [in]  none
 ** \return none
 ** \note   ʹ���������EPWM
*****************************************************************************/
void EPWM_ForceStop(void)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	
	EPWM->LOCK = 0x0;	
}

/*****************************************************************************
 ** \brief	 EPWM_EnableUpCmpInt
 **			 �������ϱȽ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableUpCmpInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC |= (EPWMnMask<<EPWM_IMSC_ENUIFn_Pos);
	EPWM->LOCK = 0x0;		
}
/*****************************************************************************
 ** \brief	 EPWM_DisableUpCmpInt
 **			 �ر����ϱȽ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableUpCmpInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC &= ~(EPWMnMask<<EPWM_IMSC_ENUIFn_Pos);
	EPWM->LOCK = 0x0;	
}
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			��ȡ���ϱȽ��ж�ʹ�ܲ������жϱ�־λ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetUpCmpIntFlag(uint32_t EPWMn)
{
	return ((EPWM->MIS&(0x01UL<<(EPWMn+EPWM_MIS_UIFn_Pos)))? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			������ϱȽ��жϱ�־λ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearUpCmpIntFlag(uint32_t EPWMn)
{
	EPWM->ICLR |= (0x1UL<<(EPWMn+EPWM_ICLR_UIFn_Pos));
}

/*****************************************************************************
 ** \brief	 EPWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableDownCmpInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC |= (EPWMnMask<<EPWM_IMSC_ENDIFn_Pos);
	EPWM->LOCK = 0x0;		
}
/*****************************************************************************
 ** \brief	 EPWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableDownCmpInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC &= ~(EPWMnMask<<EPWM_IMSC_ENDIFn_Pos);
	EPWM->LOCK = 0x0;
}
/*****************************************************************************
 ** \brief	 EPWM_GetDownCmpIntFlag
 **			��ȡ���±Ƚ��ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetDownCmpIntFlag(uint32_t EPWMn)
{
	return ((EPWM->MIS&(0x01UL<<(EPWMn+EPWM_MIS_DIFn_Pos)))? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearDownCmpIntFlag
 **			������±Ƚ��жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearDownCmpIntFlag(uint32_t EPWMn)
{
	EPWM->ICLR |= (0x1UL<<(EPWMn+EPWM_ICLR_DIFn_Pos));	
}


/*****************************************************************************
 ** \brief	 EPWM_EnablePeriodInt
 **			 ���������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnablePeriodInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC |= (EPWMnMask<<EPWM_IMSC_ENPIFn_Pos);
	EPWM->LOCK = 0x0;		
}
/*****************************************************************************
 ** \brief	 EPWM_DisablePeriodInt
 **			 �ر������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisablePeriodInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC &= ~(EPWMnMask<<EPWM_IMSC_ENPIFn_Pos);
	EPWM->LOCK = 0x0;		
}
/*****************************************************************************
 ** \brief	 EPWM_GetPeriodIntFlag
 **			��ȡ�����ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetPeriodIntFlag(uint32_t EPWMn)
{
	return ((EPWM->MIS&(0x01UL<<(EPWMn+EPWM_MIS_PIFn_Pos)))? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			��������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearPeriodIntFlag(uint32_t EPWMn)
{
	EPWM->ICLR |= (0x1UL<<(EPWMn+EPWM_ICLR_PIFn_Pos));
}

/*****************************************************************************
 ** \brief	 EPWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableZeroInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC |= (EPWMnMask<<EPWM_IMSC_ENZIFn_Pos);
	EPWM->LOCK = 0x0;	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableZeroInt
 **			 �ر�����ж�
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableZeroInt(uint32_t EPWMnMask)
{
	EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;	
	EPWM->IMSC &= ~(EPWMnMask<<EPWM_IMSC_ENZIFn_Pos);
	EPWM->LOCK = 0x0;	
}
/*****************************************************************************
 ** \brief	 EPWM_GetZeroIntFlag
 **			��ȡ����ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetZeroIntFlag(uint32_t EPWMn)
{
	return ((EPWM->MIS&(0x01UL<<(EPWMn+EPWM_MIS_ZIFn_Pos)))? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearZeroIntFlag
 **			�������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearZeroIntFlag(uint32_t EPWMn)
{
	EPWM->ICLR |= (0x1UL<<(EPWMn+EPWM_ICLR_ZIFn_Pos));
}
