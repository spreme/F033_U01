#ifndef	_TUYA_WIFI_H_
#define	_TUYA_WIFI_H_

#include "define.h"

extern u8 	second;			//��
extern u8 	minute;
extern u8 	hour;
extern u8 	delay_flag;		//��ʱ��־λ
extern u16 	time_delay;		//��ʱʱ��Ա�
//extern u8 	key_shake_flag;			//���������ɹ���־

//extern u16 RES_KEY_time;

extern u8 RECODE_KEY_flag;			//¼�������־

extern u8  SPK_EN_flag;				//������־
extern u8 	key_one_flag;			//����һ�α�־λ


extern u8 	key_time_flag;			//��ʼ��¼����ʱ���־
extern u8 	key_flag;				//���������־λ
extern u8 	key_mode;				//������Ӧģʽ 0������ģʽ	1���ֶ�ιʳ	2����λ
extern int 	key_time;				//����ʱ��	����5�븴λ
extern u8 	lock_key_task;			//�����ɹ���˸��־
extern u8 	set_AP_mode;			//����APģʽ
extern u8 	buzzer_flag;			//���������־

extern u8   lock_flag;
extern u16  lock_timeout;

extern u8	feed_one_flag_now;		//�ֶ�ιʳһ�α�־λ
extern u8 	reset_flag;				//��λ��־λ

extern u8   spk_reset_flag;			//��¼����־
extern u8   record_flag;				
extern u8   play_flag;


extern u8	battery_flag;				//��ر�־
extern u8	battery_empty_flag;			//���������־
extern u8	battery_empty_result;		//�����������ͱ�־
extern s8 	battery_percent;			//��ص����ٷֱ�


extern void battery_isr(void);

extern void link_led_isr(void);

/////////////////////////////////////////////////////////////
extern u16 link_led_time;				//�������˸ʱ��
extern u8 wifi_error_flag;				//�����APģʽ
extern u8 link_led_open;				//�����������˸
extern u8 link_led_open_long;			//����Ƴ���

extern u8 wifi_test_flag;				//wifi����ģʽ��־
//extern bit wifi_strength_poor;			//WiFi�ź�ǿ�Ȳ��־
//extern bit wifi_normal;					//wifi������־
//extern bit wifi_no_ssid;				//ģ��δɨ�赽ָ��·����
//extern bit wifi_no_permission;			//ģ��δ��Ȩ����ģʽ
extern u8 	wifi_test_bink_time;		//wifi����ģʽ��˸����
extern u8 wifi_tset;					//WiFi����ģʽ������ͱ�־
extern u8 	wifi_test_time;				//wifi���Դ���
extern u8  wifi_test_start_flag;		//�ϵ����WiFi����ģʽ��ʱʱ��

extern u8 wifi_get_mode_delay_flag;		//�ϵ��ȡWiFiģʽ��ʱ��־

extern u8 key_dowm_time;				//�������´���
extern u8 record_key_flag;				//¼���������±�־
extern u8 remaining_change; 			//�����ʣ��ʱ����±�־


extern void feed_key_isr(void);
extern void record_key_isr(void);
extern void speak_reset_isr(void);
extern void buzzer_func_isr(void);
extern void desiccant_pull(void);



#endif

