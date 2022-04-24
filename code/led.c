#include "cms32f033x.h"

#include "define.h"

//led����
u8 task_run_led = 0;
u8 task_delay_led = LED_PERIOD;

//������˸led����
u8 task_delay_error = ERROR_PERIOD;

//�������
u8 task_run_motor = 0;				//ιʳ�б�־λ1��ιʳ�У� 0�����У�
u16 task_feed_again = 0;

u8 ledtime_flag = 0;				//�����˸1���ӹرձ�־λ
u8 led_task_static = 0;				//�����˸״̬

void led_task(void)
{
	led_task_static = 1;
//	PWR_LED = ~PWR_LED;
}

void led_task_link(void)
{
	LINK_LED = ~LINK_LED;
}


#ifdef IR_FEED_TUBE
void error_task(void)
{
	static u8 error_ir_time = 0;
	
	//�жϺ���Թ��Ƿ�һֱ���赲��gpio���ŵ�ƽ0��1��
//	if(IR_LED_CTRL)
//	{
		if(IR_DET == 1)			//����
		{
			error_ir_time++;
			if(error_ir_time >= 150)	//1.5sȷ������,����
			{				
				feed_error |= ERROR_IR;
				error_ir_time = 0;
			}
		}
		else
		{
			error_ir_time = 0;
			feed_error &= ~ERROR_IR;
		}
//	}
}
#endif

#ifdef IR_FOOD_TUBE
void food_det_isr(void)
{
	if(FOOD_DET == 0)						//���������¼�
	{
		food_empty_flag = LED_NO_FOOD;				//������û��

		feed_error |= ERROR_NOT_ENOUGH;
		
		#ifdef IR_FOOD_TUBE_NOW
		feed_error |= ERROR_NOT_ENOUGH;		
		task_run_led = 1;
		#endif
	}
	#ifdef IR_FOOD_TUBE_TWO
	else if(IR_FOOD_DET2 == 0)
	{
		food_empty_flag = LED_NOT_ENOUGH_FOOD;		//����������
		#ifdef IR_FOOD_TUBE_NOW
		feed_error |= ERROR_NOT_ENOUGH;
//		task_run_led = 1;
		#endif
	}
	#endif
	else 
	{
		food_empty_flag = LED_ENOUGH_FOOD;
		if(feed_error & ERROR_NOT_ENOUGH)
		{
			feed_error &= ~ERROR_NOT_ENOUGH;
		}
	}
	
	if(food_empty_flag > 0)		//��������ʱ��һֱ������������Ƽ��
	{
		FOOD_IR = LED_ON;
//		IR_LED_CTRL = 1;
	}
	#ifdef IR_FOOD_TUBE_TWO
	else if(IR_LED_CTRL && food_empty_flag == LED_ENOUGH_FOOD)
	{
		if(task_run_motor == 0)
			IR_LED_CTRL = 0;
	}	
	#endif
}
#endif


void device_state()
{
	;
}

#ifdef SFN_BEEP
void PWMInit(void)
{	
	/*
	(1)����EPWM����ģʽ
	*/
	EPWM_ConfigRunMode(  EPWM_COUNT_DOWN 		| 			/*���¼���ģʽ(���ض���)*/
						 EPWM_OCU_SYMMETRIC 	|			/*�Գ�ģʽ*/
						 EPWM_WFG_INDEPENDENT   |			/*����ģʽ*/
						 EPWM_OC_INDEPENDENT);				/*�������ģʽ*/
	/*
	(2)����EPWMʱ������
	*/
	SYS_EnablePeripheralClk(SYS_CLK_EPWM_MSK);				/*����EPWMʱ��*/
	
	EPWM_ConfigChannelClk(EPWM1, EPWM_CLK_DIV_1);			/*����EPWMʱ��ΪAPBʱ�ӵ�1��Ƶ*/
	EPWM_ConfigChannelPeriod(EPWM1,  17778);					/*EPWM0ͨ�������� = 2400/Fepwm = 50us*/
	EPWM_ConfigChannelSymDuty(EPWM1, 8889);					/*EPWM0ͨ����ռ�ձ� = 50%*/
	/*
	(3)����EPWM�������
	*/
	EPWM_DisableReverseOutput(EPWM_CH_1_MSK);				/*�ر�EPWM0�ķ������*/

	/*
	(4)����EPWM���ط�ʽ
	*/
	EPWM_EnableAutoLoadMode(EPWM_CH_1_MSK);						/*����Ϊ�Զ�����ģʽ*/
	EPWM_ConfigLoadAndIntMode(EPWM1, EPWM_EACH_PERIOD_ZERO);	/*���ص�����Ϊÿ�����ڵ����㣬����������������ж�*/
	/*
	���ض���(���¼���)ģʽ: 
	(1)EPWM_EACH_PERIOD_ZERO: ÿ���������ڵ�������������������ڵ��жϱ�־(��Ӱ��Ƚ��ж�)
	(2)EPWM_EACH_ZERO:		 ÿ������������һ�Σ�����������жϡ�(�����������жϣ���Ӱ��Ƚ��ж�)
	(3)EPWM_FIRST_ZERO_NEXT_PERIOD:		 ÿ���������(����)����һ�Σ���������㡢�����жϡ�(��Ӱ��Ƚ��ж�)	
	(4)EPWM_EVERY_TWO_ZERO:		 ÿ���ĸ�������һ�Σ�����������жϡ�(�����������жϣ���Ӱ��Ƚ��ж�)				

	���Ķ���(���¼���)ģʽ��
	(1)EPWM_EACH_PERIOD_ZERO: ÿ���������ڵ�������������������ڵ��жϱ�־(��Ӱ��Ƚ��ж�)
	(2)EPWM_EACH_ZERO:		 ÿ�����������������жϱ�־(�����������жϣ���Ӱ��Ƚ��ж�)
	(3)EPWM_FIRST_ZERO_NEXT_PERIOD:		 ��һ���������һ�����ڵ㽻������������������ڵ��жϱ�־(ÿ��3�����(����)����һ����㣨���ڣ��ж�)(��Ӱ��Ƚ��ж�)	
	(4)EPWM_EVERY_TWO_ZERO:		 ÿ��2��������һ�Σ�����������жϡ�(�����������жϣ���Ӱ��Ƚ��ж�)		
	*/
	
//	/*
//	(5)�����ж�
//	*/
//	EPWM_EnablePeriodInt( EPWM_CH_0_MSK);				/*�������ڵ��ж�*/
//	EPWM_EnableDownCmpInt( EPWM_CH_0_MSK);				/*�������±Ƚϵ��ж�*/
//	EPWM_EnableZeroInt( EPWM_CH_0_MSK);					/*��������ж�*/
//	NVIC_EnableIRQ(EPWM_IRQn);
//	/*
//	(6)�������ȼ�
//	*/	
//	NVIC_SetPriority(EPWM_IRQn,3);					/*���ȼ�0~3�� 0��ߡ�3���*/
	
	/*
	(7)����IO�����
	*/	
	SYS_SET_IOCFG(IOP04CFG, SYS_IOCFG_P04_EPWM1);		
	EPWM_EnableOutput(EPWM_CH_1_MSK);
	/*
	(8)����EPWM
	*/		
//	EPWM_Start(EPWM_CH_1_MSK );		
}

void buzzer_en_func(u8 en)
{
	if(en)
	{
		EPWM_Start(EPWM_CH_1_MSK);
	}
	else
	{
		EPWM_Stop(EPWM_CH_1_MSK);
	}
}
#endif


