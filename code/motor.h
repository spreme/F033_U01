#ifndef __MOTOR_H
#define __MOTOR_H

#include "cms32f033x.h"
#include "define.h"


extern u32 motor(u32 count, u8 * err_type);	//ιʳ����
extern u16 motor_door(u8 open);
extern void feed_scan(struct feed_infos * info);

extern uint8_t motor_door_close(void);
extern uint8_t motor_door_open(void);


extern struct feed_infos  feed_info;						//������xdata���Σ���Ȼ�յ����ݻ���

extern u8 feed_error;				//ιʳ���� 1(����) 2���豸�쳣�� 4��������
extern u8 send_error_again;			//��ʱ�����쳣��־
extern char food_count;				//��������ʳ�������
extern u8 ERROR_IR_style;			//�����������	
extern u8 feed_detect_sw;			////ιʳ�꣨5���ӣ���־λ
extern u8 led_status_allow_feed;	//ιʳ��ɺ�����״̬�ƿ�����־
extern u8 feed_detect_again;		//�������				ȷ����ιʳ����ִ���ٴ�ιʳ���
extern u32 already_number;			//�Ѿ�ιʳ�ķ���
extern u32 number;					//��Ҫιʳ�ķ���
extern u16 task_feed_sw;			//ιʳ�꣨5���ӣ���ʱʱ����0

extern u8 feed_required;			//��Ҫִ��ιʳ��0(��ִ��) 1(ִ��) 2(ִ��)
extern u8 feed_type; 				//ιʳ���ͣ�		

extern u8 door_open;				//���Ŵ����־��=2 ���ų���ֹͣ���ţ�
extern u8 food_empty_flag;			//Ͱ������״̬

extern u8 reverse_flag;

#endif

