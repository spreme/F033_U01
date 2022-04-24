#include "cms32f033x.h"
#include "define.h"

void TMR_Config(void)
{
	/*
	(1)����Timer1 ��ʱ��
	*/
	SYS_EnablePeripheralClk(SYS_CLK_TIMER01_MSK);			/*��Timer0/1��ʱ��*/
	TMR_ConfigClk(TMR1,TMR_CLK_SEL_APB,TMR_CLK_DIV_256);		/*Timer1 ��ʱ��Դѡ��APBʱ��(48Mhz),����ʱ�ӷ�ƵΪ 256��Ƶ*/
	TMR_ConfigClk(TMR0,TMR_CLK_SEL_APB,TMR_CLK_DIV_256);		/*Timer1 ��ʱ��Դѡ��APBʱ��(48Mhz),����ʱ�ӷ�ƵΪ 256��Ƶ*/
	/*
	(2)����Timer1 ����ģʽ
	*/	
	TMR_ConfigRunMode(TMR1,TMR_COUNT_PERIOD_MODE, TMR_BIT_32_MODE);		/*����Timer1Ϊ32λ���ڼ���ģʽ*/
	TMR_DisableOneShotMode(TMR1);							/*�رյ���ģʽ*/
	TMR_ConfigRunMode(TMR0,TMR_COUNT_PERIOD_MODE, TMR_BIT_32_MODE);		/*����Timer1Ϊ32λ���ڼ���ģʽ*/
	TMR_DisableOneShotMode(TMR0);							/*�رյ���ģʽ*/
	/*
	(3)����Timer1 ��������
	*/		
	TMR_SetPeriod(TMR1,180000);				/* 1/��48M/256��* 180000000= 1s*/
	TMR_SetPeriod(TMR0,1800);				/* 1/��48M/256��* 1800000 = 10ms*/
	/*
	(4)����Timer1 �ж�
	*/	
	TMR_EnableOverflowInt(TMR1);
	NVIC_EnableIRQ(TMR1_IRQn);	
	TMR_EnableOverflowInt(TMR0);
	NVIC_EnableIRQ(TMR0_IRQn);	
	/*
	(5)����Timer1 �ж����ȼ�
	*/	
	NVIC_SetPriority(TMR1_IRQn,2);	
	NVIC_SetPriority(TMR0_IRQn,2);	
	/*
	(5)����Timer1
	*/	
	TMR_Start(TMR1);
	TMR_Start(TMR0);
}


void delay_ms(uint32_t ms)
{
	uint8_t i,j,k;
	uint32_t a;
	
	for(a = 0; a < ms; a++)
	{
		for(i = 0; i < 3; i++)
			for(j = 0; j < 39; j++)
				for(k = 0; k < 47; k++)
					;
	}
}


