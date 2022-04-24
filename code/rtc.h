#ifndef	__RTC_H
#define	__RTC_H

#include "cms32f033x.h"

#define RTC_PERIOD 100			//��ʱ��3 10ms * 100 = 1s

struct rtc_time_ascii {
	u8 year;
	u8 month;
	u8 mday;

	u8 hour;
	u8 minute;
	u8 second;
	u8 wday;
};

extern struct rtc_time_ascii rtc_date;

extern u8 task_delay_rtc;
extern u8 display_time;
extern u8 lock_key_time_1;				//��������ʱ��
extern u8 feed_lock_key_time_flag;		//������ʱ��ʼ��־
extern u8 get_time_flag;				//��ȡʱ�䣨0����δ��ȡʱ�� 1����ȡʱ�� 2����ȡʱ��ȴ������

extern void rtc_init(void);
extern void rtc_task(void);
extern void printf_rtc(void);
extern int Get_weeks (int y,u8 m, u8 d );
#endif

