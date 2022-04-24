#include "cms32f033x.h"

#include "define.h"

u16	link_led_time = 0;				//�������˸ʱ��
u8 wifi_error_flag = 0;			//�����APģʽ
u8 link_led_open = 1;				//�����������˸
u8 link_led_open_long = 0;			//����Ƴ���

u8 	wifi_test_flag = 0;				//wifi����ģʽ��־
u8 	wifi_test_bink_time = 0;		//wifi����ģʽ��˸����
u8 wifi_tset = 0;					//WiFi����ģʽ������ͱ�־

u8  wifi_test_start_flag = 0;		//�ϵ����WiFi����ģʽ��ʱ��־
u8  wifi_get_mode_delay_flag = 1;	//�ϵ��ȡWiFiģʽ��ʱ��־		1(��ʱ��)  2����ʱ�������Ѿ���ȡ��WiFiģʽ��

u8 remaining_change = 0;			//�����ʣ��ʱ����±�־

u8 SPK_EN_time = 10;
u8 reset_res_time = RESET_RECORD_TIME;
u16 rec_time_out = RECORD_TIME_MAX_U;			//¼����ʱ
u8 key_dowm_time = 0;			//�������´���

u8 record_timeout_flag = 0;			//¼����ʱ��־


u8 delay_flag 	= 0;			//��ʱ��־λ
u16 time_delay 	= 0;			//��ʱʱ��Ա�

int key_time 	= 1;			//����ʱ��	����6�븴λ
u8 key_time_flag = 0;			//��ʼ��¼����ʱ���־
u8 reset_flag	= 0;			//��λ��־λ
u8 feed_one_flag_now = 0;		//�ֶ�ιʳһ�α�־λ
u8 SPK_EN_flag = 0;				//������־

u8 lock_key_task = 0;			//�����ɹ���˸��־

//feed_key_isr
#ifdef ONE_KEY_RECORD
void feed_key_isr()
{
	if(key_time_flag == 1)			//����ιʳ���
	{
		if(FEED_KEY)
		{
			if(key_time < 1 && key_dowm_time >= 2)
			{
				if(func_flag.lock_key == 0)			//û������ʱ
					feed_one_flag_now = 1;				//ιʳ
				
				key_time_flag = 0;
				key_dowm_time = 0;
			}	
			else if(key_dowm_time == 1 && key_time >= 1 && record_flag == 0 && key_time <= 2)
			{
				if(func_flag.lock_key == 0)			//û������ʱ
					feed_one_flag_now = 1;				//ιʳ
				
				key_time_flag = 0;
				key_dowm_time = 0;
			}
			else if(key_time >= 1)
			{
				key_time_flag = 0;
				key_dowm_time = 0;
			}
		}
	}
}
#else // THREE_KEY_FUNC
void feed_key_isr()
{
	if(key_time_flag == 1 && FEED_KEY == 1)
	{
		if(key_time <= 1)
		{
			if(func_flag.lock_key == 0)				//û������ʱ
			{
				feed_one_flag_now = 1;				//����ιʳ
				
				lock_timeout = LOCK_TIMEOUT_TIME;	//��������ʱ
			}
		}	
		key_time_flag = 0;
		key_time = 0;
	}
}
#endif


//��¼������
#ifndef NO_RECORD_FUNC
//speak_reset_isr
#ifdef TY_DP_RECORD
void speak_reset_isr()
{
	static u16 record_time_time = 0;			//¼��ʱ����ʱ

	if(SPK_EN_flag == 1)					//����������Ȼ��100ms�����ͣ�
	{
		if(func_flag.record_state && voice_time_time > 0)		//����¼������¼�����Ŵ�������0
		{
			RECORD_PLAY_E;
			SPK_EN_time--;
			if(SPK_EN_time == 0)
			{	
				SPK_EN_flag = 2;
				SPK_EN_time = 10;
				RECORD_PLAY_END_E;
				voice_time_time--;
				record_time_time = func_flag.record_time;
			}
		}
	}
	
	if(SPK_EN_flag == 2)				//�ȴ�������ɣ�������һ��¼��
	{
		record_time_time--;
		if(record_time_time == 0)
		{
			SPK_EN_flag = 1;
		}
	}
	else if(voice_time_time == 0)
	{
		SPK_EN_flag = 0;
	}
	
	if(spk_reset_flag == 1)				//��¼����¼��Ȼ���600ms����¼����
	{
		RECORD_E;
		reset_res_time--;
		if(reset_res_time == 0)
		{	
			func_flag.record_state = 0;
			spk_reset_flag = 0;
			RECORD_END_E;
			reset_res_time = RESET_RECORD_TIME;
//			spk_reset_flag = 2;
		}	
	}	
}
#else
void speak_reset_isr()
{
	if(SPK_EN_flag /*&& func_flag.lock_key == 0*/)					//����������Ȼ��100ms�����ͣ�
	{
		RECORD_PLAY_E;
		SPK_EN_time--;
		if(SPK_EN_time == 0)
		{	
			SPK_EN_flag = 0;
			RECORD_PLAY_END_E;
			SPK_EN_time = 10;
		}	
	}
	else
	{
		RECORD_PLAY_END_E;
	}
	
	if(spk_reset_flag == 1)				//��¼����¼��Ȼ���600ms����¼����
	{
		RECORD_E;
		reset_res_time--;
		if(reset_res_time == 0)
		{	
			spk_reset_flag = 0;
			RECORD_END_E;
			reset_res_time = RESET_RECORD_TIME;
//			spk_reset_flag = 2;
		}	
	}
}	
#endif

//record_key_isr
#ifdef TY_DP_RECORD
void record_key_isr()
{
	if(record_flag == 1 && RESET_KEY == 0 && record_timeout_flag == 0)		//��ʼ¼����δ��ʱ��
	{
		RECORD_E;
				
		rec_time_out--;
		if(rec_time_out == 0)
		{
			record_flag = 2;
			RECORD_END_E;
			rec_time_out = RECORD_TIME_MAX_U;
			record_timeout_flag = 1;
		}
	}
	else 
	{
		if(record_flag == 2)
		{
			func_flag.record_state = 1;
			record_flag = 0;
			func_flag.record_time = 1000;
			record_change_flag = 1;
		}
		else if(record_flag > 0 && rec_time_out != RECORD_TIME_MAX_U)
		{
			if((RECORD_TIME_MAX_U - rec_time_out) <= 60)			//����ʱ��С��600ms���൱����¼��
			{
				func_flag.record_state = 0;
				func_flag.record_time = 0;
			}
			else
			{
				func_flag.record_state = 1;
				func_flag.record_time = RECORD_TIME_MAX_U - rec_time_out;			//
			}		
			record_change_flag = 1;
		}
		
		if(spk_reset_flag == 0)
		{
			RECORD_END_E;
		}
		if(rec_time_out != RECORD_TIME_MAX_U)
		{
			rec_time_out = RECORD_TIME_MAX_U;
			record_flag = 0;
		}
		
		record_timeout_flag = 0;
	}	
}
#elif defined ONE_KEY_RECORD
void record_key_isr()
{
	if(record_flag && FEED_KEY == 0 && record_timeout_flag == 0)		//��ʼ¼����δ��ʱ��
	{
		RECORD_E;
				
		rec_time_out--;
		if(rec_time_out == 0)
		{
			record_flag = 0;
			RECORD_END_E;
			rec_time_out = RECORD_TIME_MAX_U;
			
			key_time_flag = 0;
			key_time = 0;
			record_timeout_flag = 1;
		}
	}
	else 
	{
		if(spk_reset_flag == 0)
			RECORD_END_E;
		if(rec_time_out != 1000)
		{
			rec_time_out = RECORD_TIME_MAX_U;
			record_flag = 0;
			
			key_time_flag = 0;
			key_time = 0;
		}
		
		record_timeout_flag = 0;
	}
}
#elif defined PLAY_KEY_RECORD
void record_key_isr()
{
	static u16	record_key_time = 0;			//¼��������ʱ

	if(record_key_flag && RECORD_KEY == 0)
	{
		if(record_key_time >= 100 && func_flag.lock_key == 0 && record_timeout_flag == 0)		//����ʱ��������¼��
		{
			RECORD_E;
				
			rec_time_out--;
			if(rec_time_out == 0)
			{
				RECORD_END_E;
				rec_time_out = RECORD_TIME_MAX_U;
				record_timeout_flag = 1;
				lock_timeout = LOCK_TIMEOUT_TIME;	//��������ʱ
				SPK_EN_flag = 1;
				
			}
		}
	}
	else 
	{
		if(record_key_flag && record_key_time < 100 && func_flag.lock_key == 0)  	//����ʱ������������
		{
			SPK_EN_flag = 1;
			
			lock_timeout = LOCK_TIMEOUT_TIME;	//��������ʱ
		}
		record_key_flag = 0;
		
		if(spk_reset_flag == 0)
			RECORD_END_E;
		if(rec_time_out != RECORD_TIME_MAX_U)	//�ɿ�����
		{
			rec_time_out = RECORD_TIME_MAX_U;
			lock_timeout = LOCK_TIMEOUT_TIME;	//��������ʱ
			SPK_EN_flag = 1;
			
		}
		
		record_timeout_flag = 0;
	}	
	
	if(record_key_flag)
	{
		record_key_time++;
	}
	else if(record_key_time > 0)
	{
		record_key_time = 0;
	}	

}
#else
void record_key_isr()
{
	if(RECORD_KEY == 0 && func_flag.lock_key == 0 && record_timeout_flag == 0)//if(record_flag)		//��ʼ¼����δ��ʱ��
	{
		RECORD_E;
			
		rec_time_out--;
		if(rec_time_out == 0)
		{
			RECORD_END_E;
			rec_time_out = RECORD_TIME_MAX_U;
			record_timeout_flag = 1;
		}
	}
	else 
	{		
		
		if(rec_time_out > (RECORD_TIME_MAX_U - 30) && GET_RECORD_E)
		{
			rec_time_out--;
		}
		else
		{			
			if(spk_reset_flag == 0)
				RECORD_END_E;
			if(rec_time_out != RECORD_TIME_MAX_U)
				rec_time_out = RECORD_TIME_MAX_U;
			
			record_timeout_flag = 0;
		}
	}
}
#endif

#endif		///* end of NO_RECORD_FUNC */

///
//buzzer_func_isr
#ifdef KEY_BUZZER_FUNC
u8 buzzer_flag = 0;			//���������־
void buzzer_func_isr()
{
	static u8 buzzer_time = 0;
	static u8 buzzer_flag_1 = 0;
	static u8 key_flag_2 = 0;
	static u8 key_flag_3 = 0;
	static u8 reset_buzz_flag = 0;
//	static u8 reset_buzz_time = 0;
	static u8 reset_buzz_delay = 0;
	
	//��������һ��
	if(buzzer_flag)
	{
		if(buzzer_time == 0 && buzzer_flag_1 == 0)
		{
			buzzer_time = 20;
			buzzer_flag_1 = 1;
			buzzer_flag = 0;
		}	
	}
	else
	{
		buzzer_flag_1 = 0;
	}

	#ifdef THREE_KEY_FUNC
	if(RECORD_KEY == 0 && func_flag.lock_key == 1)
	{
		if(buzzer_time == 0 && key_flag_1 == 0)
		{
			buzzer_time = 20;
			key_flag_1 = 1;
		}
	}
	else
	{
		key_flag_1 = 0;
	}
	
	if(FEED_KEY == 0 && func_flag.lock_key == 0)
	{
		if(buzzer_time == 0 && key_flag_2 == 0)
		{
			buzzer_time = 20;
			key_flag_2 = 1;
		}
	}
	else
	{
		key_flag_2 = 0;
	}
	
	if(RESET_KEY == 0)
	{
		if(buzzer_time == 0 && key_flag_3 == 0)
		{
			buzzer_time = 20;
			key_flag_3 = 1;
		}
	}
	else
	{
		key_flag_3 = 0;
	}
	#endif
	
	#ifdef LOCK_KEY_KEY_E
	if(LOCK_KEY == 0 && func_flag.lock_key == 0)
	{
		if(buzzer_time == 0 && key_flag_4 == 0)
		{
			buzzer_time = 20;
			key_flag_4 = 1;
		}
	}
	else
	{
		key_flag_4 = 0;
	}
	#endif	
	
	if(spk_reset_flag && reset_buzz_flag == 0)
	{
		buzzer_time = 10;
		reset_buzz_flag = 1;
		reset_buzz_delay = 60;
	}
	else if(reset_buzz_delay > 0  && reset_buzz_flag < 3)	//&& buzzer_time == 0
	{
		reset_buzz_delay--;
		if(reset_buzz_delay == 0)
		{
			if(reset_buzz_flag == 1)
				reset_buzz_flag = 2;
			else if(reset_buzz_flag == 2)
			{
				reset_buzz_flag = 3;
			}
			reset_buzz_delay = 20;
			buzzer_time = 10;
		}
	}	
	
	if(buzzer_time > 0)
	{
		buzzer_time--;
		#ifdef POWER_BEEP
		BUZZER_EN = 1;
		#elif SFN_BEEP
		buzzer_en_func(1);
		#endif
	}
	else
	{
		#ifdef POWER_BEEP
		BUZZER_EN = 0;	
		#elif SFN_BEEP
		buzzer_en_func(0);
		#endif	
	}
	
}
#endif


#ifdef TY_DP_DESICCANT
void desiccant_pull()
{	
	if(func_flag.remaining_time == 0 && func_flag.remind_time > 0)
	{
		mcu_dp_fault_update(DPID_FAULT,ERROR_DESICCANT_TIME);
	}
	
	if(remaining_change)
	{
		remaining_change = 0;
		user_write_flash(FLASH_FUNC_ADDR, (uint8_t *) &func_flag, sizeof(FLASH_FUNC_E));
		mcu_dp_value_update(DPID_REMAINING_TIME, func_flag.remaining_time);
	}
}

#endif

#ifdef BATTERY_DETECT

u8	battery_flag = 0;				//��ر�־
u8	battery_empty_flag = 0;			//���������־
u8	battery_empty_result = 0;		//�����������ͱ�־
s8 	battery_percent = 100;			//��ص����ٷֱ�


void battery_isr(void)
{
	static u16 battery_time = 0;			//��������ʱ��
//	static u16 battery_empty_time = 500;	//�����������˸ʱ��5s�������200ms

	static u16 battery_led_time_slow = 50;
	static u16 battery_led_time = 20;
	static u16 battery_off_wifi = 0;
	
	//������������
	
	if(battery_flag)			
	{
		battery_time++;
		if(battery_time == 300)
		{
			battery_empty_result = 1;
		}
		if(battery_time > 30000)		//ÿ��5��������һ�ε���
		{
			battery_time = 0;
		}
	}
	else if(battery_time != 0)
		battery_time = 0;
	
	//�͵�������5s��ر�WiFi
	if(battery_empty_flag && WIFI_PWR && net_flag == 3)
	{
		battery_off_wifi++;
		if(battery_off_wifi >= 500)
		{
			WIFI_PWR = 0;
			battery_off_wifi = 0;
		}
	}
	else
	{
		battery_off_wifi = 0;
	}
	
	if(DC_DET == 0)
	{
		if(battery_percent <= 20)
		{
			battery_led_time--;
			if(battery_led_time == 0)
			{
				BAT_LED = ~BAT_LED;
				battery_led_time = 20;
			}
		}
		else if(battery_percent <= 50)
		{
			battery_led_time_slow--;
			if(battery_led_time_slow == 0)
			{
				BAT_LED = ~BAT_LED;
				battery_led_time_slow = 50;
			}
		}
		else
		{
			BAT_LED = LED_ON;
		}
	}
	else
		BAT_LED = LED_OFF;
}
#endif


#ifdef LINK_LED_FUNC 
void link_led_isr(void)
{
	static u8 link_time = 25;
	
//	if(link_led_open && wifi_test_bink_time != 10  && pwr_led_flag == 0 )
	if(link_led_open)
	{
		#ifndef BATTERY_DC_DETECT
		if(DC_DET == 0)
		{
			LINK_LED = LED_OFF;
		}
		else
		#endif		
			if(link_led_open_long)
		{
			#ifdef ERROR_LINK_LED_ON
			LINK_LED = LED_ON;
			#else
//			if(task_run_led == 0)
//			{
				LINK_LED = LED_ON;
//			}
//			else
//				LINK_LED = LED_OFF;
			#endif
		}
		
		else if(wifi_error_flag)
		{
			LINK_LED = LED_OFF;
			
		}
		else
		{
			link_time--;
			if(link_time == 0)
			{
				led_task_link();
				link_time = link_led_time;
			}
		}
	}
	
	//�ϵ�׵���
	if(wifi_get_mode_delay_flag < 2)
	{
//		wifi_get_mode_delay_time--;
		LINK_LED = LED_OFF;
//		if(wifi_get_mode_delay_time == 0)
//		{
			wifi_get_mode_delay_flag = 2;
//		}
	}
}

#endif

