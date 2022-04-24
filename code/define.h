#ifndef _DEFINE_H_
#define _DEFINE_H_

#include "cms32f033x.h"


#define SEND_LAN_CONNECT_FUNC  	1			//���;������������������ѹ���
//######################### ��Ŀ�� ####################################//
#define U01_001			1				//����U01


#include "user_gpio.h"

//######################### ιʳ���� ####################################//
#define FEED_NEW 		0x1
#define FEED_AUTO 		0x1
#define FEED_OLD 		0x2
#define FEED_MANUAL 	0x3

#define FEED_AUTO_T 		0x1
#define FEED_MANUAL_T 		0x2
#define FEED_KEY_T 			0x3

//######################### ιʳ�������� ####################################//
//Ϳѻ����
#define ERROR_EMPTY				0x01		//��������
#define ERROR_NOT_ENOUGH		0x01		//��������
#define ERROR_IR				0x02		//�������(����)
#define ERROR_MOTOR_TIMEOUT		0x04		//�����ʱ(�豸�쳣)
#define ERROR_LOW_POWER			0x08		//������
#define ERROR_FEEDER_DUMP		0x10		//�豸�㵹

#define ERROR_LAN_CONNT			0x20		//������ͨ�� ������ʾ�û������Ǿ�����������ͨ�ţ��豸����

#define ERROR_DESICCANT_TIME	0x20		//�������������
#define ERROR_KEY_COUNT			0x20		//���������ﵽ���ֵ

#define NORMAL					0x00		//�豸��������
#define LOW_POWER				0x03		//�豸�͵���
#define FEEDING					0x05		//�豸����ιʳ

//�ѿ�Э��汾
//#define ERROR_MOTOR_TIMEOUT		0x01		//�����ʱ
//#define ERROR_EMPTY				0x02		//����
//#define ERROR_IR				0x04		//�������
//#define ERROR_NOT_ENOUGH		0x08		//��������
//#define ERROR_KEY_COUNT			0x10		//���������ﵽ���ֵ

#ifdef IR_FOOD_TUBE
enum FOOD_STATE_E{
	LED_ENOUGH_FOOD 	= 0,		//��Ͱ��ʳ����
    LED_NO_FOOD			= 1,		//��Ͱ����
    LED_NOT_ENOUGH_FOOD	= 2,		//��Ͱ��ʳ����
};
#endif
//######################### ��ʱʱ�� ####################################//
#define LED_PERIOD 				40			//400ms	�����ƣ���ƣ���˸ʱ��
#define ERROR_PERIOD 			100			//1s	�������ʱ����
#define FEED_AGAIN_PERIOD 		30000		//300s  ιʳ����֮��5��������һ��
#define MOTO_TIMEOUT			1300			//13��  	ιʳ�����⵽λ��ʱʱ��
#define LEDTIME_ALL_TIME		30010		//�����˸5����ֹͣ���������10��ȷ��LED����������״̬��

#define  GET_TIME_START		300				//��ȡʱ����ʱ	3��
#define  GET_TIME_STOP   	30000			//��ȡʱ����	5����

//######################### ��״̬ ####################################//
#ifdef LED_HIGH_ON				//�Ƹߵ�ƽ��
#define LED_OFF  				0			//
#define LED_ON   				1
#else
#define LED_OFF  				1			//
#define LED_ON   				0
#endif

#define DOOR_CLOSE			0
#define DOOR_OPEN			1

//######################### ¼�ÿ��� ####################################//
#ifdef LOCAL_RECORD_LOW
#define RECORD_E					(RECORD = 0)
#define RECORD_END_E				(RECORD = 1)
#define RECORD_PLAY_E				(SPK_EN = 0)
#define RECORD_PLAY_END_E			(SPK_EN = 1)

#define GET_RECORD_E				(RECORD == 0)
#define GET_RECORD_END_E			(RECORD == 1)
#define GET_RECORD_PLAY_E			(SPK_EN == 0)
#define GET_RECORD_PLAY_END_E		(SPK_EN == 1)

#define RESET_RECORD_TIME		130
#else
#define RECORD_E				(RECORD = 1)
#define RECORD_END_E			(RECORD = 0)
#define RECORD_PLAY_E			(SPK_EN = 1)
#define RECORD_PLAY_END_E		(SPK_EN = 0)

#define GET_RECORD_E				(RECORD == 1)
#define GET_RECORD_END_E			(RECORD == 0)
#define GET_RECORD_PLAY_E			(SPK_EN == 1)
#define GET_RECORD_PLAY_END_E		(SPK_EN == 0)

#define RESET_RECORD_TIME		40
#endif

//######################### ���� ####################################//
#define FEED_MAX_NUM 			10 			//��ʱιʳ������� 10 or 8
#define OFF_RECORD_MAX 			30 			//���洢����ιʳ��¼����
#define FLASH_KEEP_VAL 			121 		//flash�洢��ʶ��

//######################### ��ص��� ####################################//
#define BATTERY_LOW 			3.3 		//��ص͵�ѹ��ѹֵ���������ֵ����Ϊ�͵�ѹ��
#define BATTERY_LOWEST 			3.1 		//��͹�����ѹ
#define BATTERY_FULL 			4.5 		//����ص�ѹ
#define BATTERY_LOW_PC 			50 			//��ص͵�ѹ�ٷֱȣ��������ֵ����Ϊ�͵�����


//######################### ������ܶ��� ####################################//
enum DOOR_CONTROL_E
{
	DOOR_PULL		= 0x1,			//����
	DOOR_PUSH   	= 0x2,			//����
	DOOR_STOP	   	= 0x3			//ֹͣ
};
enum MOTOR_CONTROL_E
{
	MOTOR_PULL		= 0x4,			//�����ת
	MOTOR_PUSH   	= 0x5,			//�����ת
	MOTOR_STOP	   	= 0x6			//���ֹͣ
};

//##########################################################################//
//######################  flash�洢����   ##################################//
//##########################################################################//
#ifdef OFFLINE_RECORD
struct offline_record_buf{
	u8 year_h;
	u8 year_L;
	u8 month;
	u8 day;
	u8 hour;
	u8 minute;
	
	u8 weight;	
};
#endif

typedef struct {
	uint8_t 	val;
	uint8_t 	led_switch;							//ָʾ�ƿ���
	uint8_t 	food_led_switch;					//��Χ�ƿ���
	uint8_t 	lock_key;							//��������־
	#ifdef TY_DP_RECORD
	uint8_t	record_time;						//¼��ʱ��
	uint8_t	voice_times;						//¼�����Ŵ���
	uint8_t	record_state;						//¼��״̬
	#endif
	#ifdef TY_DP_DESICCANT
	uint8_t	remind_time;						//���������ʱ��
	uint8_t	remaining_time;						//�����ʣ��ʱ��
	#endif
	#ifdef OFFLINE_RECORD
	uint8_t	record_buf_num;						//����ιʳ��¼����
	#endif
} FLASH_FUNC_E;


struct feed_infos {
	u8 week;
	u8 hour;
	u8 minute;
	
	u8 weight;
	
	u8 allow_feed;
};

typedef struct {
	u8 gpio_group;
	u8 gpio_pin;

	
}PWM_INIT_INFO_E;

typedef struct {
	uint8_t val;
	uint8_t tuya_feed_num;							//Ϳѻιʳ���в���
	struct feed_infos feed_info[FEED_MAX_NUM];		//ιʳ�б�
}FLASH_FEED_INFO_E;


extern FLASH_FUNC_E 			func_flag;			//�洢flash�ı�־����
extern FLASH_FEED_INFO_E		flash_feed_info;	//ιʳ�ƻ�
//	struct offline_record_buf record_buf[OFF_RECORD_MAX];			//����ιʳ��¼�洢
//##########################################################################//
//##########################################################################//
//##########################################################################//

extern uint32_t Systemclock;		//ϵͳʱ��
extern u8 net_flag;		
extern u8 send_feed_flag;

#ifdef TY_DP_RECORD		
extern u8 voice_time_time;			//¼�����Ŵ�������
extern u8 record_change_flag;		//¼��ʱ���ı���Ҫ����flash��־
#endif

void Jump(void);
extern void send_JK_feed_info(unsigned char dpid,unsigned char value_h,unsigned short value_l);

extern u8 WDT_time;		
extern u8 com0_flag;
extern u8 com1_flag;
extern u8 com0_timeout;
extern u8 com1_timeout;

extern u8 lock_key_flag;				//����������־
extern u8 get_time_error;				//��ȡʱ���־��1����ȡʱ�� 0����ȡʱ�������سɹ� 2����ȡʱ�䳬ʱʧ�ܣ�����WiFiģ�飩

//##########################################################################//
//##########################################################################//
//##########################################################################//


#include "system.h"
//#include "intrins.h"
#include "string.h"
#include "stdio.h"

#include "led.h"
#include "adc1.h"
#include "rtc.h"
#include "motor.h"
#include "gpio.h"
#include "fmc.h"
#include "uart.h"

#include "user_gpio.h"
#include "user_time.h"
#include "user_uart.h"
#include "user_flash.h"

#include "tuya_wifi.h"
#include "feed_process.h"

//TUYA SDK
#include "wifi.h"
#include "mcu_api.h"
#include  "protocol.h"
#include  "system.h"


#endif

