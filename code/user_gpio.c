#include "cms32f033x.h"
#include "define.h"

/*****************************************************************************
 ** \brief	 GPIO_ConfigRunMode
 **			 配置IO口运行模式
 ** \param [in] port : GPIO0、GPIO1 、GPIO2、GPIO3、GPIO4
 **				PinMask: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK
 **				Mode:	 (1)GPIO_MODE_INPUT
 **						 (2)GPIO_MODE_OUTPUT
 **						 (3)GPIO_MODE_OPEN_DRAIN_WITHOUT_PULL_UP
 **						 (4)GPIO_MODE_INPUT_WITH_PULL_UP
 **						 (5)GPIO_MODE_INPUT_WITH_PULL_DOWN
 ** \return  none
 ** \note	
*****************************************************************************/


//######################### U01_001 ####################################//
#if defined U01_001
void GPIO_Config(void)
{	
	SYS_SET_IOCFG(IOP01CFG,SYS_IOCFG_P01_GPIO);		//外电检测
//	SYS_SET_IOCFG(IOP00CFG,SYS_IOCFG_P00_GPIO);		//电池电量ADC检测口

	SYS_SET_IOCFG(IOP40CFG,SYS_IOCFG_P40_GPIO);		//故障黄灯

	SYS_SET_IOCFG(IOP10CFG,SYS_IOCFG_P10_GPIO);		//喂食电机
	SYS_SET_IOCFG(IOP12CFG,SYS_IOCFG_P12_GPIO);		//锁键白灯
	SYS_SET_IOCFG(IOP13CFG,SYS_IOCFG_P13_GPIO);		//WiFi白灯
	SYS_SET_IOCFG(IOP14CFG,SYS_IOCFG_P14_GPIO);		//余粮红灯

	SYS_SET_IOCFG(IOP43CFG,SYS_IOCFG_P43_GPIO);		//录音键
	SYS_SET_IOCFG(IOP30CFG,SYS_IOCFG_P30_GPIO);		//喂食/复位键
	SYS_SET_IOCFG(IOP44CFG,SYS_IOCFG_P44_GPIO);		//解锁键

	SYS_SET_IOCFG(IOP32CFG,SYS_IOCFG_P32_GPIO);		//余粮检测灯

	SYS_SET_IOCFG(IOP34CFG,SYS_IOCFG_P34_GPIO);		//红外对管检测
	SYS_SET_IOCFG(IOP35CFG,SYS_IOCFG_P35_GPIO);		//余粮检测

	SYS_SET_IOCFG(IOP36CFG,SYS_IOCFG_P36_GPIO);		//WiFi模块电源控制

	SYS_SET_IOCFG(IOP21CFG,SYS_IOCFG_P21_GPIO);		//喂食电机到位

	SYS_SET_IOCFG(IOP26CFG,SYS_IOCFG_P26_GPIO);		//录音控制
	SYS_SET_IOCFG(IOP25CFG,SYS_IOCFG_P25_GPIO);		//播音控制



	GPIO_CONFIG_IO_MODE(GPIO0,GPIO_PIN_1,GPIO_MODE_INPUT);
//	GPIO_CONFIG_IO_MODE(GPIO0,GPIO_PIN_0,GPIO_MODE_INPUT_WITH_PULL_UP);

	GPIO_CONFIG_IO_MODE(GPIO4,GPIO_PIN_0,GPIO_MODE_OUTPUT);

	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_0,GPIO_MODE_OUTPUT);
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_2,GPIO_MODE_OUTPUT);
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_3,GPIO_MODE_OUTPUT);
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_4,GPIO_MODE_OUTPUT);

	GPIO_CONFIG_IO_MODE(GPIO4,GPIO_PIN_3,GPIO_MODE_INPUT_WITH_PULL_UP);
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_0,GPIO_MODE_INPUT_WITH_PULL_UP);
	GPIO_CONFIG_IO_MODE(GPIO4,GPIO_PIN_4,GPIO_MODE_INPUT_WITH_PULL_UP);

	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_2,GPIO_MODE_OUTPUT);

	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_4,GPIO_MODE_INPUT_WITH_PULL_UP);
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_5,GPIO_MODE_INPUT_WITH_PULL_UP);

	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_6,GPIO_MODE_OUTPUT);

	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_1,GPIO_MODE_INPUT_WITH_PULL_UP);

	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_6,GPIO_MODE_OUTPUT);
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_5,GPIO_MODE_OUTPUT);


	/*
	(2)设置中断为下降沿中断模式
	*/	
	GPIO_EnableInt(GPIO3,GPIO_PIN_0_MSK,GPIO_INT_EDGE_FALLING);
	GPIO_EnableInt(GPIO4,GPIO_PIN_3_MSK,GPIO_INT_EDGE_FALLING);
	/*
	(3)设置 IO口输入滤波		
	*/		
	GPIO_EnableFilter(GPIO3,GPIO_PIN_0_MSK,GPIO_FILCLK_DIV_10);
	GPIO_EnableFilter(GPIO4,GPIO_PIN_3_MSK,GPIO_FILCLK_DIV_10);
	/*
	(4)设置GPIO中断
	*/
	GPIO_ClearIntFlag(GPIO3,GPIO_PIN_0);	/*清除中断标志位*/
	GPIO_ClearIntFlag(GPIO4,GPIO_PIN_3);	/*清除中断标志位*/
	NVIC_EnableIRQ(GPIO3_IRQn);				/*开启GPIO中断*/
	NVIC_EnableIRQ(GPIO4_IRQn);				/*开启GPIO中断*/

	/*
	(5)设置GPIO中断优先级
	*/	
	NVIC_SetPriority(GPIO3_IRQn,3);			/* 0~3, 0最高, 3最低*/
	NVIC_SetPriority(GPIO4_IRQn,3);			/* 0~3, 0最高, 3最低*/



/*
按键按下为低电平，抬起为高电平
LED低电平点亮，高电平熄灭
*/
//	FEED_KEY = 	1;
//	LOCK_KEY = 	1;
//	RECORD_KEY = 1;

	FOOD_IR = 	LED_ON;

	WARN_Y = 	LED_OFF;
	LOCK_LED = 	LED_OFF;
	LINK_LED = 	LED_OFF;
	FOOD_LED = 	LED_OFF;
	
//	WIFI_PWR = 1;

	MOTOR_FEED_G = 0;
	

//	IR_DET = 	1;		//被挡住
//	FOOD_DET = 	1;
//	MOTOR_DET = 1;

	RECORD = 	0;
	SPK_EN = 	0;


	
}
#endif
//######################### V86 ####################################//




