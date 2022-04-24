#include "motor.h"
#include "define.h"


u8 feed_error = 0;				//ιʳ���� 0x1(����) 			0x2���豸�쳣�� 0x4��������
u8 send_error_again = 0;		//��ʱ�����쳣��־
u8 feed_detect_sw = 0;			////ιʳ�꣨5���ӣ���־λ
u16 task_feed_sw = 0;			//ιʳ�꣨5���ӣ���ʱʱ����0
u8 led_status_allow_feed = 0;	//ιʳ��ɺ�����״̬�ƿ�����־
u8 feed_detect_again = 0;		//�������		ȷ����ιʳ����ִ���ٴ�ιʳ���
u8 feed_required 	= 0; 		//��Ҫִ��ιʳ��			0(��ִ��) 1(ִ��) 2(ִ��)
u8 feed_type 		= 0; 		//ιʳ���ͣ�		
#ifdef MOTOR_REVERSE
u8 reverse_flag = 0;
#endif

u8 food_empty_flag = 0;			//Ͱ������״̬

struct feed_infos  feed_info;

void motor_contorl(enum MOTOR_CONTROL_E motor_c)
{
	switch(motor_c)
	{
		case MOTOR_PULL:
		{
			MOTOR_FEED_G = 1;
			#ifdef MOTOR_REVERSE
			MOTOR_FEED_B = 0;
			#endif
		}
		break;
		
		case MOTOR_PUSH:
		{
			MOTOR_FEED_G = 0;
			#ifdef MOTOR_REVERSE
			MOTOR_FEED_B = 1;
			#endif
		}
		break;
		
		case MOTOR_STOP:
		{
			MOTOR_FEED_G = 0;
			#ifdef MOTOR_REVERSE
			MOTOR_FEED_B = 0;
			#endif
		}
		break;
		
		default:
			break;			
	}
}


#ifdef DOOR_CONTROL
uint8_t door_open = 0;				//���Ŵ����־��=2 ���ų���ֹͣ���ţ�

void door_motor_contorl(enum DOOR_CONTROL_E door_c)
{
	switch(door_c)
	{
		case DOOR_PULL:
		{
			MOTOR_DOOR_G = 1;
			MOTOR_DOOR_B = 0;
		}
		break;
		
		case DOOR_PUSH:
		{
			MOTOR_DOOR_G = 0;
			MOTOR_DOOR_B = 1;
		}
		break;
		
		case DOOR_STOP:
		{
			MOTOR_DOOR_G = 0;
			MOTOR_DOOR_B = 0;
		}
		break;
		
		default:
			break;			
	}
}

uint8_t motor_door_open(void)
{
	uint16_t timeout = 400;
	
	task_run_motor = 1;
	door_open = 0;
	
	printf("open:%d, close:%d\r\n",(DOOR_DET_P == 1),(DOOR_DET_N == 1));
	//��λ����ǰ��λλ��		����(�Ųֵ�λ��ѹ��Ϊ�ߵ�ƽ)
	if(DOOR_DET_P != DOOR_CLOSE)
	{
		door_motor_contorl(DOOR_PULL);
	}

	while(timeout)
	{
		if(DOOR_DET_P == DOOR_CLOSE)				//���￪�ŵ�λλ��
		{
			delay_ms(10);
			if(DOOR_DET_P == DOOR_CLOSE)
			{
				door_motor_contorl(DOOR_STOP);
				printf("door open success\r\n");
				feed_error &= ~ERROR_DOOR_CONTROL;				//��������
				break;
			}				
		}
		delay_ms(10);
		
		timeout--;
		if(timeout == 0)
		{
			door_motor_contorl(DOOR_STOP);
			printf("open door timeout!!!\r\n");
								
			feed_error |= ERROR_DOOR_CONTROL;				//�����쳣

			return 1;
		}
	}
	
	door_motor_contorl(DOOR_STOP);
	return 0;
}

uint8_t motor_door_close(void)
{
	uint16_t timeout = 1300;
		
	task_run_motor = 1;
	door_open = 0;

	//��λ���ں�λλ��		����
	if(DOOR_DET_N != DOOR_CLOSE)
	{
		door_motor_contorl(DOOR_PUSH);
	}
	
	while(timeout)
	{
		#ifdef IR_FEED_TUBE
		if(IR_DET == 1)			//�����Թܶ���
		{
			motor_door_open();
			delay_ms(1000);
			
			if(IR_DET == 1)			//�����Թܶ���
			{
				break;
			}
			else
			{
				door_motor_contorl(DOOR_PUSH);
			}
		}		
		#endif
		
		if(DOOR_DET_N == DOOR_CLOSE)				//�����λλ��
		{
			delay_ms(10);
			if(DOOR_DET_N == DOOR_CLOSE)
			{
				door_motor_contorl(DOOR_STOP);	
				printf("close door success!!!\r\n");
				feed_error &= ~ERROR_DOOR_CONTROL;				//��������
				break;
			}
		}
		
		if(timeout == 800)
		{
			printf("close door error first time, open the door\r\n");			
			motor_door_open();
			delay_ms(1000);
			timeout = 790;
			door_motor_contorl(DOOR_PUSH);
		}
		
		if(timeout == 300)
		{
			printf("close door error second time, open the door until next feed time\r\n");			
			motor_door_open();
			door_open = 2;
			task_run_motor = 0;
					
			feed_error |= ERROR_DOOR_CONTROL;				//�����쳣
			
			return 1;
		}
		
		delay_ms(10);
		timeout--;
	}
	
	door_motor_contorl(DOOR_STOP);
	task_run_motor = 0;

	return 0;
}
#endif



u16 motor_run(void)
{
	u16 timeout1 = MOTO_TIMEOUT; //�����жϵ����ʱ
	u16 i;
	u16 key_cont = 0;
	#ifdef MOTOR_DET_ADDR
	u8 feed_det_flag = 0;
	#endif
	
	//�������
	motor_contorl(MOTOR_PULL);

	//���õ��ת��һ���Ƕȣ��˳���λ����ѹ�ŵ�״̬
	key_cont = 0;
	i = 200;
	printf("det out:i:%d \r\n",i);
	while(i)
	{
		delay_ms(10);

		if(MOTOR_DET == 1)
		{
			printf("MOTOR_DET \r\n");
			break;
		}
		i--;
		if(i == 0)
		{
			printf("i=0\r\n");
			timeout1 = 0;
		}
	}

	//�ȴ�����ж�(�½��ش���)�������жϵ������ж��ж����ŵ�ƽ�Ƿ�Ϊ��(������ʱȥ��)
	//�ͱ�ʾ��λ���ػ����������ת����ѹ�ţ���ʱ���ֹͣת��
	while(timeout1)
	{			
//		wifi_uart_service();
		if(MOTOR_DET == 0) //ιʳ�����λ
		{			
			delay_ms(10);	//��ʱȥ��
			
			if(MOTOR_DET == 0)
			{
				
				key_cont++;
				if(key_cont > 6)
				{
					printf("feed det and out \r\n");
					key_cont = 0;
					#ifndef MOTOR_DET_ADDR
					return timeout1;
					#else
					feed_det_flag = 1;					
					#endif
				}
			}
		}
		#ifdef MOTOR_DET_ADDR
		if(feed_det_flag && MOTOR_DET == 1)
		{
			feed_det_flag = 0;
			return timeout1;
		}
		#endif
		
		delay_ms(10);
		timeout1--;

	}
	//�������������
	#ifdef MOTOR_REVERSE
	if(timeout1 == 0 && reverse_flag == 0)
	{
		reverse_flag++;
				
		motor_contorl(MOTOR_PUSH);
		delay_ms(500);
		motor_contorl(MOTOR_PULL);
		delay_ms(500);
		motor_contorl(MOTOR_PUSH);
		delay_ms(500);
		motor_contorl(MOTOR_PULL);
		delay_ms(500);
		motor_contorl(MOTOR_PUSH);
		delay_ms(500);
		motor_contorl(MOTOR_PULL);
		delay_ms(500);
		motor_run();
//		return 0xfe;
	}
	else
	{
		reverse_flag = 0;
	}
	#endif
	
	return timeout1;

}

#ifdef IR_FEED_TUBE
u32 motor(u32 count, u8 * err_type)
{
	u8 errs = 0;
	int feed_cont = count;		//�����жϵ��ת��������ÿת��һ�Σ�ιʳһ�ݣ����10g��
	int timeout = MOTO_TIMEOUT; //�����жϵ����ʱ
	int feed_already = count;		//ʱ��ιʳ���������10g��
	u8 time_ir_out = 50;		//������ʱ����������5s

	ledtime_flag = 1;
	task_run_led = 0;
	
	task_run_motor = 1;

//	IR_LED_CTRL	= 1;	
	
	delay_ms(40);
	*err_type = 0;
	
	SPK_EN_flag = 1;					//����
	#ifdef TY_DP_RECORD
	voice_time_time = flash_feed_info.voice_times;
	#endif
	
//	P0EXTIE |=  0x08;			//���������ж�
	
	//�ж��Ƿ�������е�ιʳ���������ÿת��һ��ιʳһ�ݣ����10g��
	printf("++++++++ feed_error ######## %d\r\n",feed_cont);
	while(feed_cont > 0)
	{
		wifi_uart_service();
again:
		WDT_time = 0;
		
		if(IR_DET == 0)		
			timeout = motor_run();
		else
		{
			feed_cont++;
			feed_already++;
			timeout = 5;
		}
		//�����ʱ�����ûת��λ����̽�����(��λ����û�ж�)
		if(timeout == 0)
		{
			printf("motor not move or det err\r\n");
			*err_type |= ERROR_MOTOR_TIMEOUT;
			feed_error |= ERROR_MOTOR_TIMEOUT;//����
			task_run_led = 1;
			goto err;
		}

		//��ʱ��ʳ���ֵ���
		MOTOR_DELAY;

		feed_cont--;
		feed_already--;

#ifdef	IR_CHECK_FOOD	
		if(food_count == 0)
			feed_already++;
		
		//ʳ���(ʳ�����0 �Һ���Թܵ�ͨ)��������
		if((food_count == 0) && (FOOD_DET == 0))		//��ͨ
		{
			*err_type = ERROR_EMPTY;
			errs++;

			if(errs <= 4)
			{
				*err_type = 0;
				feed_cont++;
				
				printf("no food ready\r\n");
				printf("feed_cont:%d - count:%d \r\n", feed_cont, count);
				
				goto again;
			}
			else
			{
				printf("no food\r\n");
				feed_error = ERROR_EMPTY;//����
				feed_cont++;
				*err_type = ERROR_EMPTY;
				errs = 0;
				goto err;
			}
		}
#endif		

			if(IR_DET == 1)
			{
				printf("ir_error ready\r\n");

				time_ir_out = 50;
				while(time_ir_out)
				{
					motor_contorl(MOTOR_STOP);	//����5s����ͣ
					time_ir_out--;
					delay_ms(100);
					
					if(IR_DET == 0)
						break;
					else
					{
						if(time_ir_out == 0)
						{
							printf("ir error\r\n");
							*err_type |= ERROR_IR;		//����
							
							goto err;
						}
					}
				}							
			}
			

		if(*err_type)
		{
			if(feed_cont != 0)
			{
				errs++;

				if(errs < 2)
				{
					*err_type = 0;
					goto again;
				}
				else
				{
					goto err;
				}
			}
		}

		//�ɹ�ιʳһ��
		*err_type = 0;
		errs = 0;
		feed_error = 0;
	}
err:
//	P0EXTIE &=	~0x08;			//�رպ����ж�
	#ifdef MOTOR_REVERSE
		reverse_flag = 0;
	#endif

	#ifdef IR_FOOD_TUBE
	if(food_empty_flag > 0)
	{
		*err_type |= ERROR_NOT_ENOUGH;		//ȱ��
		printf("food error \r\n");
	}
	#endif
		
	//ֹͣ���
	motor_contorl(MOTOR_STOP);
	
//	IR_LED_CTRL = 0;
	task_run_motor = 0;			//ιʳ�б�־λ1��ιʳ�У� 0�����У�

	feed_detect_sw = 1;			//ιʳ�꣨5���ӣ���־λ
	task_feed_sw = 0;			//ιʳ�꣨5���ӣ���ʱʱ����0
	ledtime_flag = 0;			//ιʳ��������˸1���ӱ�־
	led_status_allow_feed = 1;	//ιʳ��ɺ�����״̬�ƿ�����־
	
	return (count - feed_already);
}
#else
u32 motor(u32 count, u8 * err_type)
{
	int feed_cont = count;		//�����жϵ��ת��������ÿת��һ�Σ�ιʳһ�ݣ����10g��
	int timeout = MOTO_TIMEOUT; //�����жϵ����ʱ
	int feed_already = count;		//ʱ��ιʳ���������10g��
	
//	ledtime_flag = 1;
//	task_run_led = 0;
	
//	task_run_motor = 1;
	*err_type = 0;

	SPK_EN_flag = 1;				//����
	#ifdef TY_DP_RECORD
	voice_time_time = flash_feed_info.voice_times;
	#endif
	
	//�ж��Ƿ�������е�ιʳ���������ÿת��һ��ιʳһ�ݣ����10g��
	while(feed_cont > 0)
	{
//		food_count = 0; 		//���ϼ�������
//		WDT_time = 0;
		
		timeout = motor_run();

		//�����ʱ�����ûת��λ����̽�����(��λ����û�ж�)
		if(timeout == 0)
		{
			printf("motor not move or det err\r\n");
			*err_type |= ERROR_MOTOR_TIMEOUT;
			feed_error |= ERROR_MOTOR_TIMEOUT;
//			task_run_led = 1;
			goto err;
		}

		//��ʱ��ʳ���ֵ���
		MOTOR_DELAY;

		
		feed_cont--;
		feed_already--;


		//�ɹ�ιʳһ��
		*err_type = 0;
		feed_error = 0;
	}
err:
	#ifdef IR_FOOD_TUBE
	if(food_empty_flag > 0)
	{
		*err_type |= ERROR_NOT_ENOUGH;
		feed_error |= ERROR_NOT_ENOUGH;
		printf("food error \r\n");
	}
	#endif
	#ifdef MOTOR_REVERSE
		reverse_flag = 0;
	#endif
	
	//ֹͣ���
	motor_contorl(MOTOR_STOP);
//	task_run_motor = 0;			//ιʳ�б�־λ1��ιʳ�У� 0�����У�

	feed_detect_sw = 1;			//ιʳ�꣨5���ӣ���־λ
	task_feed_sw = 0;			//ιʳ�꣨5���ӣ���ʱʱ����0
//	ledtime_flag = 0;			//ιʳ��������˸1���ӱ�־
	led_status_allow_feed = 1;	//ιʳ��ɺ�����״̬�ƿ�����־
	
	return (count - feed_already);
}

#endif


