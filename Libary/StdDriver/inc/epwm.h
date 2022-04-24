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

/*****************************************************************************/
/** \file epwm.h
**
** History:
** 
*****************************************************************************/
#ifndef __EPWM_H_
#define __EPWM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms32f033x.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **EPWM ͨ��
-----------------------------------------------------------------------------*/
#define	EPWM0 			(0x00UL)
#define	EPWM1 			(0x01UL)
#define	EPWM2 			(0x02UL)
#define	EPWM3 			(0x03UL)
#define	EPWM4 			(0x04UL)
#define	EPWM5 			(0x05UL)

#define	EPWM_CH_0_MSK 		(0x01UL)
#define	EPWM_CH_1_MSK 		(0x02UL)
#define	EPWM_CH_2_MSK 		(0x04UL)
#define	EPWM_CH_3_MSK 		(0x08UL)
#define EPWM_CH_4_MSK 		(0x10UL)
#define	EPWM_CH_5_MSK		(0x20UL)

/*----------------------------------------------------------------------------
 **EPWM ��ӳ��
-----------------------------------------------------------------------------*/
#define	IPG0			(0x00UL)
#define	IPG1			(0x01UL)
#define	IPG2			(0x02UL)
#define	IPG3			(0x03UL)
#define	IPG4			(0x04UL)
#define	IPG5			(0x05UL)
#define EPWM_REMAP_ENABLE	(0xAAUL)
/*----------------------------------------------------------------------------
 **EPWM ģʽ
-----------------------------------------------------------------------------*/
/*------EPWM����ģʽ---------------------------------------------------------*/
#define EPWM_COUNT_UP_DOWN			(0x01UL<<EPWM_CON_CNTTYPE_Pos)  	/*EPWM������COUNT��ģʽ�����¼��������Ķ��룩ģʽ*/
#define EPWM_COUNT_DOWN				(0x00UL)  							/*EPWM������COUNT��ģʽ�����¼��������ض��룩ģʽ*/
/*------EPWM����Ƚϵ�Ԫ(OCU)ģʽ--------------------------------------------*/
#define EPWM_OCU_ASYMMETRIC			(0x01UL<<EPWM_CON_ASYMEN_Pos)  		/*EPWM����Ƚϵ�Ԫ��OCU��ģʽ�� �ǶԳ�ģʽ*/
#define EPWM_OCU_SYMMETRIC			(0x00UL) 					 		/*EPWM����Ƚϵ�Ԫ��OCU��ģʽ�� �Գ�ģʽ*/
/*------EPWM���η�������Ԫ(WFG)ģʽ------------------------------------------*/
#define EPWM_WFG_INDEPENDENT		(0x0UL)  							/*EPWM���η�������WFG��ģʽ��������������ģʽ*/
#define EPWM_WFG_COMPLEMENTARYK 	(0x1UL<<EPWM_CON_MODE_Pos) 			/*EPWM���η�������WFG��ģʽ������ģʽ*/
#define EPWM_WFG_SYNCHRONIZED		(0x2UL<<EPWM_CON_MODE_Pos) 			/*EPWM���η�������WFG��ģʽ��ͬ��ģʽ*/
/*------EPWM������Ƶ�Ԫ(OC)ģʽ---------------------------------------------*/
#define EPWM_OC_GROUP				(0x01UL<<EPWM_CON_GROUNPEN_Pos)  	/*EPWM������ƣ�OC��ģʽ�� ���ģʽ*/
#define EPWM_OC_INDEPENDENT			(0x00UL) 						 	/*EPWM������ƣ�OC��ģʽ�� ͨ�����Զ�������*/

/*----------------------------------------------------------------------------
 **EPWM ʱ��
-----------------------------------------------------------------------------*/
#define 	EPWM_CLK_DIV_1				(0x5UL)		
#define 	EPWM_CLK_DIV_2				(0x4UL)		
#define	 	EPWM_CLK_DIV_4				(0x0UL)		
#define	 	EPWM_CLK_DIV_8				(0x1UL)		
#define 	EPWM_CLK_DIV_16				(0x2UL)		
#define 	EPWM_CLK_DIV_32				(0x3UL)		

/*----------------------------------------------------------------------------
 **EPWM ���ڡ�ռ�ձȼ��ط�ʽ�������жϡ�����жϲ�����ʽ
-----------------------------------------------------------------------------*/
#define		EPWM_EACH_PERIOD_ZERO		(0x0UL)		/*ÿ����������ڵ�*/
#define		EPWM_EACH_ZERO				(0x1UL)		/*ÿ�����*/
#define		EPWM_FIRST_ZERO_NEXT_PERIOD	(0x2UL)		/*��һ���������һ�����ڵ�*/
#define		EPWM_EVERY_TWO_ZERO			(0x3UL)		/*ÿ�������*/

/*----------------------------------------------------------------------------
 **EPWM д����
-----------------------------------------------------------------------------*/
#define		EPWM_LOCK_P1A_WRITE_KEY		(0xAAUL)
#define		EPWM_LOCK_P1B_WRITE_KEY		(0x55UL)



/*****************************************************************************
 ** \brief	EPWM_GET_UPCMP_RIS_FLAG
 **			��ȡ���ϱȽ��ж�Դ��־
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 ** \return  1�������ж�  0:���ж�
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_UPCMP_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_UIFn_Pos))? 1:0)))
		
/*****************************************************************************
 ** \brief	EPWM_GET_DOWNCMP_RIS_FLAG
 **			��ȡ���±Ƚ��ж�Դ��־
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 ** \return  1�������ж�  0:���ж�
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_DOWNCMP_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_DIFn_Pos)))? 1:0))


/*****************************************************************************
 ** \brief	EPWM_GET_PERIOD_RIS_FLAG
 **			��ȡ�����ж�Դ��־
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 ** \return  1�������ж�  0:���ж�
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_PERIOD_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_PIFn_Pos)))? 1:0))
		
/*****************************************************************************
 ** \brief	EPWM_GET_ZERO_RIS_FLAG
 **			��ȡ����ж�Դ��־
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 ** \return  1�������ж�  0:���ж�
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_ZERO_RIS_FLAG(EPWMn)	(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_ZIFn_Pos)))? 1:0))


/*****************************************************************************
 ** \brief	EPWM_SET_COMPARE
 **			����EPWMn�Ƚ�ֵ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			   CMR : 16λ�Ƚ���ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_COMPARE(EPWMn,CMR)	 do{\
											EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
											EPWM->CMPADT[EPWMn] &= 0xffff0000;\
											EPWM->CMPADT[EPWMn] |= 0xffff & CMR;\
											EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
											EPWM->LOCK = 0x0;\
										  }while(0)
/*****************************************************************************
 ** \brief	EPWM_SET_PERIOD
 **			����EPWMn����ֵ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			   period : 16λ����ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_PERIOD(EPWMn,period)	do{\
												EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
												EPWM->PERIOD[EPWMn] = 0xffff & Period;\
												EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
												EPWM->LOCK = 0x0;\
											}while(0)

/*****************************************************************************
 ** \brief	EPWM_SET_COMPARE_D
 **			����EPWMn���±Ƚ�ֵ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			   CMRD : 16λ���±Ƚ���ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_COMPARE_D(EPWMn,CMRD)	do{\
													EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
													EPWM->CMPADT[EPWMn] &= 0xffff;\
													EPWM->CMPADT[EPWMn] |= ((0xffff & CMRD)<< 16);\
													EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
													EPWM->LOCK = 0x0;\
											 }while(0)
	
											 
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************
 ** \brief	 EPWM_ConfigRunMode
 **			 ����EPWM������ģʽ
 ** \param [in] EpwmRunMode:   (1)EPWM_COUNT_UP_DOWN
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
void EPWM_ConfigRunMode(uint32_t EpwmRunMode);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelClk	
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **				ClkDiv: (1)EPWM_CLK_DIV_1 
 **						(2)EPWM_CLK_DIV_2
 **						(2)EPWM_CLK_DIV_4
 **						(2)EPWM_CLK_DIV_8
 **						(2)EPWM_CLK_DIV_16
 **						(2)EPWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)����ΪCLKPSC01��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����CLKPSC01=0x01
 **     ����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ.
 **	(2)EPWM ��Ƶ��Ϊ������CLKPSC CLKDIV
 **		��һ����Ƶ(CLKPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ ��������ϵͳʱ�ӷ�Ƶϵ�� CLKPSC+1
 **		�ڶ�����Ƶ��CLKDIV): 0x00 FEPWMPSC/2; 0x01 FEPWMPSC/4��0x02:FEPWMPSC/8��0x3 FEPWMPSC/16 0x04 FEPWMPSC ; ���� Fsys 
 ** 	��Ƶ������1~4096����Fsys=8M��EPWM��Ƶ�ʷ�Χ��1.95k ~ 8M	   
*****************************************************************************/
void EPWM_ConfigChannelClk(uint32_t EPWMn,uint32_t ClkDiv);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelPeriod	
 **			 ����EPWMͨ��������
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
*****************************************************************************/
void EPWM_ConfigChannelPeriod(uint32_t EPWMn, uint32_t Period);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelSymDuty	
 **			 ���öԳ�ģʽ�µ�EPWMͨ����ռ�ձ�
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			    Duty  : 16λ�Ƚ�ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelSymDuty(uint32_t EPWMn,uint32_t Duty);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelAsymDuty	
 **			 ���÷ǶԳ�ģʽ�µ� EPWMͨ����ռ�ձ�
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 
 **			    UpCmp 	  : 16λ���ϱȽ�ֵ
 **			    DownCmp   : 16λ���±Ƚ�ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelAsymDuty(uint32_t EPWMn,uint32_t UpCmp, uint32_t DownCmp);

/*****************************************************************************
 ** \brief	 EPWM_EnableOneShotMode	
 **			 ʹ�ܵ���ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableOneShotMode(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_EnableAutoLoadMode	
 **			 ʹ����������ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableAutoLoadMode(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableReverseOutput	
 **			 �����������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableReverseOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_DisableReverseOutput	
 **			 �رշ������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableReverseOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableDeadZone	
 **			 ��������
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 **				DeadZone : 0x00 ~ 0x3FF;
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableDeadZone(uint32_t EPWMnMask, uint32_t DeadZone);

/*****************************************************************************
 ** \brief	 EPWM_DisableDeadZone	
 **			 �ر�����
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableDeadZone(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_Start	
 **			 ����EPWM
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Start(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_Stop	
 **			 �ر�EPWM
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Stop(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_ForceStop	
 **			 ǿ�ƹر�EPWM
 ** \param [in]  none
 ** \return none
 ** \note   ʹ���������EPWM
*****************************************************************************/
void EPWM_ForceStop(void);

/*****************************************************************************
 ** \brief	 EPWM_EnableOutput
 **			 ����EPWMͨ�����
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void EPWM_EnableOutput(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableOutput
 **			 �ر�EPWMͨ�����
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_ConfigLoadAndIntMode
 **			 ���ü��ط�ʽ�Լ��жϷ�ʽ
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 **				 Mode: (1)EPWM_EACH_PERIOD_ZERO
 **					   (2)EPWM_EACH_ZERO
 **					   (3)EPWM_FIRST_ZERO_NEXT_PERIOD
 **					   (4)EPWM_EVERY_TWO_ZERO
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigLoadAndIntMode(uint32_t EPWMnMask, uint32_t Mode);

/*****************************************************************************
 ** \brief	 EPWM_EnableUpCmpInt
 **			 �������ϱȽ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableUpCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableUpCmpInt
 **			 �ر����ϱȽ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableUpCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			��ȡ���ϱȽ��ж�ʹ�ܲ������жϱ�־λ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetUpCmpIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			������ϱȽ��жϱ�־λ
 ** \param [in]EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearUpCmpIntFlag(uint32_t EPWMn);

/*****************************************************************************
 ** \brief	 EPWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableDownCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableDownCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetDownCmpIntFlag
 **			��ȡ���±Ƚ��ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetDownCmpIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearDownCmpIntFlag
 **			������±Ƚ��жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearDownCmpIntFlag(uint32_t EPWMn);


/*****************************************************************************
 ** \brief	 EPWM_EnablePeriodInt
 **			 ���������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnablePeriodInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisablePeriodInt
 **			 �ر������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisablePeriodInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetPeriodIntFlag
 **			��ȡ�����ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetPeriodIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			��������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearPeriodIntFlag(uint32_t EPWMn);

/*****************************************************************************
 ** \brief	 EPWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableZeroInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableZeroInt
 **			 �ر�����ж�
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK ��
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableZeroInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetZeroIntFlag
 **			��ȡ����ж�ʹ�ܲ������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return 1���ж�ʹ�ܲ��Ҳ����ж�  0�����ж�
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetZeroIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearZeroIntFlag
 **			�������жϱ�־λ
 ** \param [in] EPWMn : EPWM0 ��EPWM1 ��EPWM2 ��EPWM3 ��EPWM4 ��EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearZeroIntFlag(uint32_t EPWMn);

#ifdef __cplusplus
}
#endif

#endif /*__EPWM_H_ */

