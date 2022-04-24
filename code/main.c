#include "cms32f033x.h"
#include "define.h"

u8 net_flag = 0;		
u8 send_feed_flag = 0;
u8 WDT_time = 0;

u8 com0_flag  = 0;
u8 com1_flag  = 0;
u8 com0_timeout  = 0;
u8 com1_timeout  = 0;

u8 get_time_error = 0;				//��ȡʱ���־��1����ȡʱ�� 0����ȡʱ�������سɹ� 2����ȡʱ�䳬ʱʧ�ܣ�����WiFiģ�飩

#ifdef TY_DP_RECORD		
u8 voice_time_time = 1;		//¼�����Ŵ�������
u8 record_change_flag = 0;	//¼��ʱ���ı���Ҫ����flash��־
#endif

void sys_init()
{
	SYS_DisableIOCFGProtect();			/*�ر�IOCONFIGд����*/
	SYS_DisableGPIO0Protect();			/*�ر�GPIO0����ؼĴ���д����*/
	SYS_DisableGPIO1Protect();			/*�ر�GPIO1����ؼĴ���д����*/
	SYS_DisableGPIO2Protect();			/*�ر�GPIO2����ؼĴ���д����*/
	SYS_DisableGPIO3Protect();			/*�ر�GPIO3����ؼĴ���д����*/
	SYS_DisableGPIO4Protect();			/*�ر�GPIO4����ؼĴ���д����*/
	
	SYS_ConfigHSI(SYS_CLK_HSI_48M);		/*�����ڲ�����ʱ��Ϊ48Mhz*/
	SYS_EnableHSI();					/*��������ʱ��*/
	SYS_ConfigAHBClock(SYS_CLK_SEL_HSI,SYS_CLK_DIV_1);	/*����AHBʱ��Ϊ����ʱ�ӵ�1��Ƶ*/
	SYS_ConfigAPBClock(AHB_CLK_DIV_1);					/*����APBʱ��ΪAHBʱ�ӵ�1��Ƶ*/
}
/*****************************************************************************
 ** \brief	 main
 **
 ** \param [in]  none   
 **
 ** \return 0
*****************************************************************************/
int main(void)
{	
	delay_ms(3000);			//��ʱ��ȷ����ʼ���ɹ�
	
	#ifdef	BATTERY_DETECT
	float battery = 0;
//	u8 battery_buf[2];
	
    u32 vddVol = 0.0;
//    uint16_t adcRes = 0x0000;
//    float channelVol = 0.0;
	u8 battery_empty_flag_old = 0;
#endif
#ifdef MACHINE_DUMP_E
	u8 dump_send_flag = 99;
	u8 ret;
#endif
	
	u8 DC_det_flag = 0x99;
	u8 feed_error_old = 0;
	u8 old_min = 111;

	sys_init();

	WDT_ConfigClk(WDT_CLK_DIV_256);	
	WDT_ConfigPeriod(3200);				// 40KHZ/256 * 3200 = 5000ms
	WDT_EnableRestSystem();
	WDT_ClearOverflowIntFlag();
//	WDT_DisableRestSystem();
	WDT_ClearWDT();

	GPIO_Config();			//GPIO��ʼ��
	TMR_Config();

	rtc_init();				//��Ƭ��ʱ���ʼ��

#ifdef	BATTERY_DETECT
	ADCInit();
#endif	
	
#ifdef	SFN_BEEP
	PWMInit();
#endif	

	UART_Config();
	
	delay_ms(200);			//��ʱ��ȷ����ʼ���ɹ�
	
	
	printf("  \r\n");
	printf("  Version: %s \r\n", VERSION_F);
	printf("  date: %s \r\n",VERSION_DATA);
	printf("PID: %s \r\n", PRODUCT_KEY);
	
	eeprom_data_init(0);
	wifi_protocol_init();		//wifi ��ʼ��
	
	#ifdef LOCAL_RECORD_LOW
	IAP_read_user(FLASH_FEED_INFO_ADDR + 1, &a, 1);
	if(a != 2)
	{
		MX_RSTB			= 0;			//����¼��оƬ��λ��
		delay_ms(5);
		{
			MX_RSTB			= 1;			//����¼��оƬ��λ��
		}
//		delay_ms(1000);
//		MX_RSTB			= 0;			//����¼��оƬ��λ��
//		delay_ms(5);
//		{
//			MX_RSTB			= 1;			//����¼��оƬ��λ��
//		}
	}
	else
	{
		a = 0;
		user_write_flash(FLASH_FEED_INFO_ADDR + 1, &a, 1);
	}
		
	#endif


	if(FEED_KEY == 0)
	{
		wifi_test_start_flag = 1;	
	}
	
	key_time_flag = 0;
	key_time = 0;	
	
	while(1)
	{	
		wifi_uart_service();

		WDT_time = 0;
		
		if(display_time)
		{
			display_time = 0;
			printf_rtc();		//��ʾʱ��
			if(wifi_test_flag == 0 && WIFI_PWR == 1)
			{
				mcu_get_wifi_connect_status();		//��ȡ����״̬
								
				//5���Ӽ����ȡʱ��
				if( get_time_flag == 0)
				{
					mcu_get_system_time();				//��ȡʱ��
					if(get_time_error == 0)
						get_time_error = 1;					//��ȡʱ���־
				}
			}
			
			if(feed_error != feed_error_old)
			{				
				send_feed_state(feed_error);
				feed_error_old = feed_error;
				mcu_dp_fault_update(DPID_FAULT,feed_error);
				printf("send error:%d \r\n",feed_error);
			}
			#ifdef SEND_LAN_CONNECT_FUNC				////���;������������������ѹ���
			if(send_error_again == 2)
			{
				printf("send ERROR_LAN_CONNT\r\n");
				mcu_dp_fault_update(DPID_FAULT,ERROR_LAN_CONNT);
				send_error_again = 1;
			}
			#endif
			
			if(wifi_test_flag == 1 && wifi_tset == 1)
			{
				mcu_start_wifitest();
			}

			if(net_flag == 3 && send_feed_flag == 1)
			{
				send_feed_flag = 2;
				send_feed_info();
			}
			
			
			#ifdef MACHINE_DUMP_E
			if(DUMP_DET == 0 && dump_send_flag != 0)
			{
				delay_ms(10);
				if(DUMP_DET == 0)
				{
//					printf("send machine dump \r\n");
					dump_send_flag = 0;
					ret = ERROR_FEEDER_DUMP;
					mcu_dp_fault_update(DPID_FAULT,ret);
				}
			}
			else if(DUMP_DET && dump_send_flag != 1)
			{
				delay_ms(10);
				if(DUMP_DET)
				{
//					printf("send no machine dump \r\n");
					dump_send_flag = 1;
					ret = feed_error;
					mcu_dp_fault_update(DPID_FAULT,ret);
				}
			}
			#endif
			
			
			#ifdef OFFLINE_RECORD
//			send_offline_buf();
			#endif
			
//			printf("record_key_flag:%bd \r\n",record_key_flag);
//			printf("RECORD_KEY:%bd\r\n",(RECORD_KEY == 1));
			
//			printf("wifi_tset-wifi_tset_flag:%bd-%bd \r\n",wifi_tset,wifi_test_flag);

//			printf("DOOR_OPEN:%bd- DOOR_CLOSE:%bd \r\n",(IR_DOOR_OPEN == 1), (IR_DOOR_CLOSE == 1));
//			printf("FEED_KEY:%bd- RESET_KEY:%bd \r\n",(FEED_KEY == 1), (RESET_KEY == 1));
//			printf("wifi_test_flag:%bd- wifi_tset:%bd \r\n",wifi_test_flag, (wifi_tset == 1));
//			printf("WIFI_PWR:%bd \r\n",(WIFI_PWR == 1));
//			printf("RECORD:%bd- SPK_EN:%bd \r\n",(RECORD == 1), (SPK_EN == 1));

//			printf("voice_time_time-voice_times:%bd-%bd \r\n",voice_time_time,func_flag.voice_times);
//			printf("record_time:%hd \r\n",func_flag.record_time);
//			printf("record_state:%hd \r\n",func_flag.record_state);			
		}
		
		
		#ifdef LOCK_KEY_KEY_E			//������������
		
		if(lock_timeout == 0 && func_flag.lock_key == 0)
		{
			func_flag.lock_key = 1;	
			
			user_write_flash(FLASH_FUNC_ADDR,(u8 *) &func_flag, sizeof(FLASH_FUNC_E));		//д��������־
			
		}
	
		if(lock_key_flag > 0)		
		{
			#ifdef RELOCK_KEY_KEY_E			//������������Ϊ��������
			if(lock_key_flag == 2 && func_flag.lock_key > 0)			//
			{
				func_flag.lock_key = 0;
				PWR_LED = LED_OFF;
				lock_key_task = 1;					//����������־
			}
			else if(lock_key_flag == 1 && func_flag.lock_key == 0)
			{
				func_flag.lock_key = 1;
				PWR_LED = LED_OFF;
				lock_key_task = 1;					//����������־
			}
			#else
			if(func_flag.lock_key > 0)			//������־
			{
				func_flag.lock_key = 0;
				lock_timeout = LOCK_TIMEOUT_TIME;
			}
			else if(func_flag.lock_key == 0)
			{
				func_flag.lock_key = 1;
				lock_timeout = 0;
				
			}
			
//			PWR_LED = LED_OFF;
//			lock_key_task = 1;					//����������־
			#endif			
			
			printf("lock_key:%bd \n",func_flag.lock_key);
			lock_key_flag = 0;

			user_write_flash(FLASH_FUNC_ADDR,(u8 *) &func_flag, sizeof(FLASH_FUNC_E));		//д��������־
		}
		#elif defined LOCK_KEY_E
		if(key_time >= 5 && record_flag == 0)				//����6s��ιʳ��¼������
		{
			if(func_flag.lock_key > 0)			//������־
				func_flag.lock_key = 0;
			else if(func_flag.lock_key == 0)
				func_flag.lock_key = 1;
			
			lock_key_task = 1;
			key_time_flag = 0;
			key_time = 0;
			key_dowm_time = 0;
			user_write_flash(FLASH_FUNC_ADDR,(u8 *) &func_flag, sizeof(FLASH_FUNC_E));		//д��������־
		}
		#endif
		

		if(reset_flag == 1)			//��ʼ��λ��־
		{
			reset_flag = 2;
			mcu_reset_wifi();			//���͸�λָ���WiFiģ��
			
			spk_reset_flag = 1;			//��¼��оƬ
		}
		if(reset_flag == 2)
		{
			if(net_flag == 1)
			{
				printf(" reset the mcu 3\r\n");
				delay_ms(1000);
				eeprom_data_init(0x0b);		//��ʼ��flash
				delay_ms(800);
//				if(spk_reset_flag == 2)			//¼��оƬ����ɹ�
				{
					SYS_ResetCPU();				//�����λ,ϵͳ���´��û���������ʼ���г���
					spk_reset_flag = 0;
					reset_flag = 0;
				}
				reset_flag = 3;			
			}
		}

//		if(cancel_send_feed_error == 2)
//		{
//			mcu_dp_fault_update(DPID_FAULT,0);
//			cancel_send_feed_error = 0;
//		}

		#ifdef TY_DP_RECORD
		if(record_change_flag == 1)
		{
			printf("record_change_flag \r\n");
			record_change_flag = 0;
			user_write_flash(FLASH_FUNC_ADDR, (uint8_t *) &func_flag, sizeof(FLASH_FUNC_E));
			
			//mcu_dp_bool_update(DPID_RECORDING_STATUS, func_flag.record_state);
		}	
		#endif
		
//		if(wifi_test_flag == 10)					//10s��ʱδ��⵽�����ȵ�
//		{
//			SYS_ResetMCU();				//�����λ,ϵͳ���´��û���������ʼ���г���
//		}
		
		if(feed_one_flag_now == 1)
		{
			feed_one_flag_now = 0;
			printf("feed one on key !\r\n");
			feed_info.weight = 1;
			feed_required = FEED_MANUAL;
			feed_type = FEED_KEY_T;
		}
		
		if(rtc_date.minute != old_min)						//ιʳ��⣺һ������1һ��
		{
			old_min = rtc_date.minute;

			feed_scan(&feed_info);			//ɨ��eeprom�ж��Ƿ���Ҫִ�ж�ʱιʳ
		}
		else if(feed_detect_again)			//�ٴ�ιʳ���
		{
			if((feed_error & ERROR_IR) == 0)		//���Ǻ�����󣬳���������
			{
//				printf(" feed required : feed_old !\r\n");
				feed_required = FEED_OLD;			//��������
			}
		}
		
		if(manual_mark)
		{
			manual_mark=0;
			feed_info.weight = manual_feed;
			feed_type = FEED_MANUAL_T;
			feed_error = feed_run(feed_required, &feed_info, feed_type);
			
		}
		
		if(feed_required > 0)
		{
			feed_error = feed_run(feed_required, &feed_info, feed_type);
			
			feed_required = 0;
			
			printf("++++++++++++++ feed_error:%d \r\n",feed_error);

			if(feed_error & ERROR_IR)			//ιʳ�������
			{
				feed_detect_again = 1;			//�������ȷ��ιʳ�����ٴ�ιʳ���
			}
			else
			{
				feed_detect_again = 0;
			}
			task_feed_again = 0;
		}

			#ifdef DOOR_CONTROL
			//û���ٴ�ιʳ�ƻ�������û�����Ųֵ�λû�ڹ��ŵ�λλ��
			if(feed_detect_again == 0 && door_open == 0 && (DOOR_DET_N != DOOR_CLOSE) && (IR_DET == 0))
			{
				motor_door_close();				//�ز���
			}
			#endif	

			
		#ifdef TY_DP_DESICCANT
		desiccant_pull();
		#endif
		
#ifndef BATTERY_DC_DETECT
		if(DC_DET == 0)
		{
//			if(task_run_led == 0 && wifi_test_bink_time != 10 && lock_key_task == 0)
//				BAT_LED = LED_ON;

			DC_det_flag = 1;

			#ifdef DC_POWER_CONTROL
			WIFI_PWR = 0;
			#endif
		}
		else
		{
			#ifdef DC_POWER_CONTROL
			if(DC_det_flag == 1 && WIFI_PWR == 0)	
			#else
			if(DC_det_flag == 1)
			#endif
			{
				DC_det_flag = 0;
				WIFI_PWR = 1;
//				BAT_LED = LED_OFF;
			}
		}
#endif
		
#ifdef BATTERY_DETECT
		battery_flag = 1;				//��ر�־
		if(DC_DET == 0)
		{			
			if(!ADC1_IS_BUSY())
			{ 
				ADC1_Go();
				while(ADC1_IS_BUSY());
				vddVol = ADC1_GetResult(ADC_CHANNEL);
				battery = 5.0 * vddVol / 4096.0;

				printf("ADCValue:0x%04X  \r\n",vddVol);
				printf("ADCValueLocal:%.2f V \r\n",battery);
			}
				
			battery_percent = ((battery - BATTERY_LOWEST) / (BATTERY_FULL - BATTERY_LOWEST)) * 100;
			
			if(battery_percent <= BATTERY_LOW_PC)
			{
				battery_empty_flag = 1;
			}
			else
			{
				battery_empty_flag = 0;
				WIFI_PWR = 1; 
			}
			
			if(battery_empty_result || (battery_empty_flag_old != battery_empty_flag))
			{
				battery_empty_flag_old = battery_empty_flag;

				mcu_dp_value_update(DPID_BATTERY_PERCENTAGE, battery_percent);
				battery_empty_result = 0;
			}
		}
		else if(battery_empty_result)
		{
			WIFI_PWR = 1; 
			battery_percent = 100;
			battery_empty_result = 0;
			mcu_dp_value_update(DPID_BATTERY_PERCENTAGE, battery_percent);			
		}
		else if(battery_empty_flag)
		{
			WIFI_PWR = 1; 
			battery_empty_flag = 0;
		}
#endif		
	}
}



//��ת��boot��ִ��
void Jump(void)
{
	FMC->LOCK = FMC_WRITE_KEY;
	FMC->CON &= ~FMC_CON_ISPS_Msk;	
	FMC->LOCK = 0x00;
	SYS_ResetCPU();
}

////��ת����������ִ��(boot������)
//void Jump(void)
//{
//	FMC->LOCK = FMC_WRITE_KEY;
//	FMC->CON |= FMC_CON_ISPS_Msk;	
//	FMC->LOCK = 0x00;
//	SYS_ResetCPU();
//}










