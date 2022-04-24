#include "cms32f033x.h"
#include "define.h"

void TMR_Config(void)
{
	/*
	(1)设置Timer1 的时钟
	*/
	SYS_EnablePeripheralClk(SYS_CLK_TIMER01_MSK);			/*打开Timer0/1的时钟*/
	TMR_ConfigClk(TMR1,TMR_CLK_SEL_APB,TMR_CLK_DIV_256);		/*Timer1 的时钟源选择APB时钟(48Mhz),设置时钟分频为 256分频*/
	TMR_ConfigClk(TMR0,TMR_CLK_SEL_APB,TMR_CLK_DIV_256);		/*Timer1 的时钟源选择APB时钟(48Mhz),设置时钟分频为 256分频*/
	/*
	(2)设置Timer1 运行模式
	*/	
	TMR_ConfigRunMode(TMR1,TMR_COUNT_PERIOD_MODE, TMR_BIT_32_MODE);		/*设置Timer1为32位周期计数模式*/
	TMR_DisableOneShotMode(TMR1);							/*关闭单次模式*/
	TMR_ConfigRunMode(TMR0,TMR_COUNT_PERIOD_MODE, TMR_BIT_32_MODE);		/*设置Timer1为32位周期计数模式*/
	TMR_DisableOneShotMode(TMR0);							/*关闭单次模式*/
	/*
	(3)设置Timer1 运行周期
	*/		
	TMR_SetPeriod(TMR1,180000);				/* 1/（48M/256）* 180000000= 1s*/
	TMR_SetPeriod(TMR0,1800);				/* 1/（48M/256）* 1800000 = 10ms*/
	/*
	(4)设置Timer1 中断
	*/	
	TMR_EnableOverflowInt(TMR1);
	NVIC_EnableIRQ(TMR1_IRQn);	
	TMR_EnableOverflowInt(TMR0);
	NVIC_EnableIRQ(TMR0_IRQn);	
	/*
	(5)设置Timer1 中断优先级
	*/	
	NVIC_SetPriority(TMR1_IRQn,2);	
	NVIC_SetPriority(TMR0_IRQn,2);	
	/*
	(5)开启Timer1
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


