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
/** \file acmp.h
**
** History:
** 
*****************************************************************************/
#ifndef _ACMP_H_
#define _ACMP_H_

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
 **ACMP ͨ��
-----------------------------------------------------------------------------*/
#define ACMP0 					(0x00)			/* ACMP channel 0 number */
#define ACMP1					(0x01)			/* ACMP channel 1 number */
/*----------------------------------------------------------------------------
 **ACMP ����˲�ʱ��
-----------------------------------------------------------------------------*/
#define ACMP_NFCLK_1_TSYS		(0x00UL)		/*(0~1)*Tsys*/
#define ACMP_NFCLK_2_TSYS		(0x01UL)		/*(1~2)*Tsys*/
#define ACMP_NFCLK_3_TSYS		(0x02UL)		/*(2~3)*Tsys*/
#define ACMP_NGCLK_5_TSYS		(0x03UL)		/*(4~5)*Tsys*/
#define ACMP_NFCLK_9_TSYS		(0x04UL)		/*(8~9)*Tsys*/
#define ACMP_NFCLK_17_TSYS		(0x05UL)		/*(16~17)*Tsys*/
#define ACMP_NFCLK_33_TSYS		(0x06UL)		/*(32~33)*Tsys*/
#define ACMP_NGCLK_65_TSYS		(0x07UL)		/*(64~65)*Tsys*/
#define ACMP_NFCLK_129_TSYS		(0x08UL)		/*(128~129)*Tsys*/
#define ACMP_NFCLK_257_TSYS		(0x09UL)		/*(256~257)*Tsys*/
#define ACMP_NFCLK_513_TSYS		(0x0aUL)		/*(512~513)*Tsys*/
/*----------------------------------------------------------------------------
 **ACMP ����ͨ��
-----------------------------------------------------------------------------*/
#define ACMP_POSSEL_P0			(0x00UL)		/*ACMP P0����˿�*/
#define ACMP_POSSEL_P1			(0x01UL)		/*ACMP P1����˿�*/
#define ACMP_POSSEL_P2			(0x02UL)		/*ACMP P2����˿�*/
#define ACMP_POSSEL_P3			(0x03UL)		/*ACMP P3����˿�*/

/*----------------------------------------------------------------------------
 **ACMP ����ͨ��
-----------------------------------------------------------------------------*/
#define ACMP_NEGSEL_VREF_VDD_K	(0x02UL)		/*K*VDD��ѹ*/
#define ACMP_NEGSEL_VREF_BG_K	(0x03UL)		/*�ڲ� K*1.2V��׼*/
#define ACMP_NEGSEL_VREF_BG		(0x01UL)		/*�ڲ� 1.2V��׼*/
#define ACMP_NEGSEL_N			(0x00UL)		/*ACMP N����˿�*/

/*----------------------------------------------------------------------------
 **ACMP ����ģʽ
-----------------------------------------------------------------------------*/
#define ACMP_ADJ_SEL_N			(0x00UL)			/*�Ƚ���n����ģʽ�����ѡ��N(����)*/
#define ACMP_ADJ_SEL_P			(0x01UL)			/*�Ƚ���n����ģʽ�����ѡ��P(����)*/
#define ACMP_ADJ_USE_CNADJE		(0xAAUL)			/*�Ƚ���n����ʧ����ѹ��CnADJE��CnADJ[7:0]����*/
#define ACMP_ADJ_USE_CONFIG		(0xFFUL)			/*�Ƚ���n����ʧ����ѹ��Configֵ����*/

/*----------------------------------------------------------------------------
 **ACMP  �¼����жϲ���ģʽ
-----------------------------------------------------------------------------*/
#define ACMP_EVENT_INT_RISING		(0x00UL)			/*ACMPx������(0->1����)����*/
#define ACMP_EVENT_INT_FALLING		(0x1UL )			/*ACMPx�½���(1->0����)����*/
#define ACMP_EVENT_INT_BOTH_EDGE	(0x2UL)				/*ACMPx�����0->1��������1->0���������*/

/*----------------------------------------------------------------------------
 **ACMP ����ģʽ
------------------------------------------------------------------------------*/
#define ACMP_HYS_0_TO_1			(0x01UL)			/*���0->1ʱ����*/
#define ACMP_HYS_1_TO_0			(0x00UL)			/*���1->0ʱ����*/
/*----------------------------------------------------------------------------
 **ACMP ��������
------------------------------------------------------------------------------*/
#define ACMP_HYS_S_0			(0x00UL)			/*0mV����*/
#define ACMP_HYS_S_10			(0x01UL)			/*10mV����*/
#define ACMP_HYS_S_20			(0x02UL)			/*20mV����*/
#define ACMP_HYS_S_60			(0x03UL)			/*60mV����*/
/*----------------------------------------------------------------------------
 **ACMP д����
------------------------------------------------------------------------------*/
#define ACMP_WRITE_KEY 			(0x55UL)

/*****************************************************************************
 ** \brief	 ACMP0_SWITCH_POS
 **			 �Ƚ���0����ѡ��
 ** \param [in] PositiveSource:  (1)ACMP_POSSEL_P0		:C0P0
 **								 (2)ACMP_POSSEL_P1		:C0P1
 **								 (3)ACMP_POSSEL_P2		:C0P2
 **								 (4)ACMP_POSSEL_P3		:C0P3
 ** \return  none
 ** \note   
*****************************************************************************/
#define ACMP0_SWITCH_POS(PositiveSource) do{\
											ACMP->LOCK = ACMP_WRITE_KEY;\
											ACMP->C0CON0 &= ~(ACMP_C0CON0_PS_Msk);\
											ACMP->C0CON0 |= (PositiveSource<<ACMP_C0CON0_PS_Pos);\
											ACMP->LOCK = 0x00;\
										  }while(0)							  										  
/*****************************************************************************
 ** \brief	 ACMP1_SWITCH_POS
 **			 �Ƚ���1����ѡ��
 ** \param [in] PositiveSource:  (1)ACMP_POSSEL_P0		:C1P0
 **								 (2)ACMP_POSSEL_P1		:C1P1
 **								 (3)ACMP_POSSEL_P2		:C1P2
 **								 (4)ACMP_POSSEL_P3		:C1P3
 ** \return  none
 ** \note 										  
*****************************************************************************/
#define ACMP1_SWITCH_POS(PositiveSource) do{\
											ACMP->LOCK = ACMP_WRITE_KEY;\
											ACMP->C1CON0 &= ~(ACMP_C1CON0_PS_Msk);\
											ACMP->C1CON0 |= (PositiveSource<<ACMP_C1CON0_PS_Pos);\
											ACMP->LOCK = 0x00;\
										  }while(0)



/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **ACMP ���˻�׼��ѹ VDD / BG ϵ�� K
-----------------------------------------------------------------------------*/
typedef enum V_B_Coefficient{
	V_B_COF_2 =0, 
	V_B_COF_3 =1, 
	V_B_COF_4 =2, 
	V_B_COF_5 =3, 
	V_B_COF_6 =4,
	V_B_COF_7 =5,    
	V_B_COF_8 =6, 
	V_B_COF_9 =7, 
	V_B_COF_10 =8, 
	V_B_COF_11 =9,
	V_B_COF_12 =10,  
	V_B_COF_13 =11, 
	V_B_COF_14 =12, 
	V_B_COF_15 =13, 
	V_B_COF_16 =14,
	V_B_COF_17 =15,
}V_B_Coefficient_T;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/******************************************************************************
 ** \brief	 ACMP_ConfigPositive
 **			 ���ñȽ�����������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \param [in] PositiveSource:  (1)ACMP_POSSEL_P0		:C0P0
 **								 (2)ACMP_POSSEL_P1		:C0P1
 **								 (3)ACMP_POSSEL_P2		:C0P2
 **								 (4)ACMP_POSSEL_P3		:C0P3
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_ConfigPositive( uint32_t ACMPx, uint32_t PositiveSource);

/*****************************************************************************
 ** \brief	 ACMP_ConfigNegative
 **			 ���ñȽ�����������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				NegativeSource:  (1)ACMP_NEGSEL_N		:CnN  ACMP N����˿�			 
 **								 (2)ACMP_NEGSEL_VREF_VDD_K	:K*VDD��ѹ	
 **								 (3)ACMP_NEGSEL_VREF_BG��	 �ڲ�1.2V��׼
 **								 (4)ACMP_NEGSEL_VREF_BG_K:	 �ڲ� K*1.2V��׼
 **				VBCoefficient: VDD/BGϵ��K ��0x00~0x0f (V_B_COEFF_2 ... V_B_COEFF_17)
 ** \return  none
 ** \note   �Ƚ���0/1���û�׼VDD��ѹϵ��
*****************************************************************************/
void ACMP_ConfigNegative( uint32_t ACMPx, uint32_t NegativeSource,uint32_t VBCoefficient);

/*****************************************************************************
 ** \brief	 ACMP_EnableReverseOutput
 **			 �����������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
*****************************************************************************/
void  ACMP_EnableReverseOutput( uint32_t ACMPx);
/*****************************************************************************
 ** \brief	 ACMP_DisableReverseOutput
 **			 �رշ������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void  ACMP_DisableReverseOutput( uint32_t ACMPx);
/******************************************************************************
 ** \brief	 ACMP_EnableFilter
 **			 �����˲�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				FilterTime: (1)ACMP_NFCLK_1_TSYS .... ACMP_NFCLK_513_TSYS
 ** \return  none
 ** \note   
******************************************************************************/
void  ACMP_EnableFilter( uint32_t ACMPx, uint32_t FilterTime);
/******************************************************************************
 ** \brief	 ACMP_DisableFilter
 **			 �ر��˲�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
*****************************************************************************/
void  ACMP_DisableFilter( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_EnableEventOut
 **			 �����Ƚ����¼����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
 *****************************************************************************/
void ACMP_EnableEventOut( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_ConfigEventAndIntMode
 **			 �����¼����жϲ���ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				EventAndIntMode: 	(1)ACMP_EVENT_INT_RISING 		: ACMPx����������ش���
 **				 			 		(2)ACMP_EVENT_INT_FALLING 		: ACMPx������½��ش���
 **						     		(3)ACMP_EVENT_INT_BOTH_EDGE 	: ACMPx�������0->1��������1->0�����䴥��
 ** \return  none
 ** \note   
 *****************************************************************************/

void ACMP_ConfigEventAndIntMode( uint32_t ACMPx, uint32_t EventAndIntMode);

/*****************************************************************************
 ** \brief	 ACMP_DisableEventOut
 **			 �رձȽ����¼����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
 *****************************************************************************/
void ACMP_DisableEventOut( uint32_t ACMPx);

/******************************************************************************
 ** \brief	 ACMP_EnableInt
 **			 ����ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
 *****************************************************************************/
void ACMP_EnableInt(uint32_t ACMPx);
/*****************************************************************************
 ** \brief	 ACMP_DisableInt
 **			 �ر�ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_DisableInt( uint32_t ACMPx);
/*****************************************************************************
 ** \brief	 ACMP_GetIntFlag
 **			 ��ȡACMP��ʹ���жϱ�־
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  0: ���жϲ��� �� 1���ж�ʹ�ܲ������ж�
 ** \note   
******************************************************************************/
uint32_t ACMP_GetIntFlag( uint32_t ACMPx);
/*****************************************************************************
 ** \brief	 ACMP_ClearIntFlag
 **			 ��ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void ACMP_ClearIntFlag( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_Start
 **			 ����ACMP
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void ACMP_Start( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_Stop
 **			 �ر�ACMP
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
**********************************************************************?******/
void ACMP_Stop( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_GetResult
 **			 ��ȡ�Ƚ���ֵ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  0/1
 ** \note   
 *****************************************************************************/
uint32_t ACMP_GetResult( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_EnableConfigAdjust
 **			 ʹ�ܱȽ���Config����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   ʹ���ڲ�Config����ֵ
 *****************************************************************************/
void ACMP_EnableConfigAdjust( uint32_t ACMPx);
/*****************************************************************************
 ** \brief	 ACMP_EnableAutoAdjust
 **			 ʹ�ܱȽ����Զ�����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  8bits
 ** \note   �˺����Զ���ȡ���ʵĵ�ѹ����ֵ
 *****************************************************************************/
uint32_t ACMP_EnableAutoAdjust( uint32_t ACMPx);
 /*****************************************************************************
 ** \brief	 ACMP_EnableCADJAdjust
 **			 �����Ƚ���CnADJ����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				AdjustValue: 0x00 ~ 0x1f
 ** \return  none
 ** \note    ʹ��CnCON1 �Ĵ����е�CnADJ<4:0>����
 *****************************************************************************/
void ACMP_EnableCADJAdjust( uint32_t ACMPx, uint32_t AdjustValue);
/*****************************************************************************
 ** \brief	 ACMP_EnableAdjustMode
 **			 �����Ƚ�������ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				AdjustTarget:    (1)ACMP_ADJ_SEL_N		:���������ڸ�������		
 **								 (2)ACMP_ADJ_SEL_P		:������������������	
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_EnableAdjustMode( uint32_t ACMPx, uint32_t AdjustTarget);

/*****************************************************************************
 ** \brief	 ACMP_DisableAdjustMode
 **			 �رձȽ�������ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_DisableAdjustMode( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_ConfigHYS
 **			 ���ñȽ�������ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				HYSSelect	:(1)ACMP_HYS_0_TO_1	: ���0->1ʱ����
 **							 (2)ACMP_HYS_1_TO_0	: ���1->0ʱ����
 **				HYSValue 	:(1)ACMP_HYS_S_0	��0mV ����
 **							 (2)ACMP_HYS_S_10	: 10mV����
 **							 (3)ACMP_HYS_S_20	��20mV����
 **							 (4)ACMP_HYS_S_60	��60mV���� 
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_ConfigHYS( uint32_t ACMPx ,uint32_t HYSSelect, uint32_t HYSValue);



#ifdef __cplusplus
}
#endif

#endif /* _ACMP_H_ */

