/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/*****************************************************************************/
/** \file system.h
**
** History:
** 
*****************************************************************************/
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms32f033x.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **System оƬFlash��С
-----------------------------------------------------------------------------*/
#define		SYS_FLASH_SIZE_28K		(0x1CUL)		/*Flash Ϊ 28K*/	
#define		SYS_FLASH_SIZE_32K		(0xFFUL)		/*Flash Ϊ 32K*/
/*----------------------------------------------------------------------------
 **System  ʱ��Դ
-----------------------------------------------------------------------------*/
#define		SYS_CLK_HSI_64M			(0x00UL)			/*HSI(����ʱ��)ѡ������64Mhz*/
#define		SYS_CLK_HSI_48M			(0x3UL)				/*HSI(����ʱ��)ѡ������48Mhz*/
#define		SYS_CLK_SEL_HSI			(0x00UL)			/*AHPʱ��ѡ�����ʱ��*/
#define		SYS_CLK_SEL_LSI			(0x2UL)				/*AHPʱ��ѡ�����ʱ��*/
#define		SYS_CLKSEL_WRITE_KEY	(0x5A690000UL)		/*ʱ��ѡ��д����*/		
/*----------------------------------------------------------------------------
 **System  ʱ�ӳ��÷�Ƶ
-----------------------------------------------------------------------------*/
#define 	SYS_CLK_DIV_1			(0x0UL)			/*ʱ�� 1��Ƶ*/
#define 	SYS_CLK_DIV_2			(0x1UL)			/*ʱ�� 2��Ƶ*/
#define 	SYS_CLK_DIV_4			(0x2UL)			/*ʱ�� 4��Ƶ*/
#define 	SYS_CLK_DIV_6			(0x3UL)			/*ʱ�� 6��Ƶ*/
#define 	SYS_CLK_DIV_8			(0x4UL)			/*ʱ�� 8��Ƶ*/
#define 	SYS_CLK_DIV_10			(0x5UL)			/*ʱ�� 10��Ƶ*/

#define 	AHB_CLK_DIV_1			(0x0UL)			/*ʱ�� 1��Ƶ*/
#define 	AHB_CLK_DIV_2			(0x1UL)			/*ʱ�� 2��Ƶ*/
#define 	AHB_CLK_DIV_4			(0x2UL)			/*ʱ�� 4��Ƶ*/
#define 	AHB_CLK_DIV_6			(0x3UL)			/*ʱ�� 6��Ƶ*/
#define 	AHB_CLK_DIV_8			(0x4UL)			/*ʱ�� 8��Ƶ*/
#define 	AHB_CLK_DIV_10			(0x5UL)			/*ʱ�� 10��Ƶ*/
#define 	AHB_CLK_DIV_12			(0x6UL)			/*ʱ�� 12��Ƶ*/
#define 	AHB_CLK_DIV_14			(0x7UL)			/*ʱ�� 14��Ƶ*/
#define 	AHB_CLK_DIV_16			(0x8UL)			/*ʱ�� 16��Ƶ*/
#define 	AHB_CLK_DIV_18			(0x9UL)			/*ʱ�� 18��Ƶ*/
#define 	AHB_CLK_DIV_20			(0xAUL)			/*ʱ�� 20��Ƶ*/


/*----------------------------------------------------------------------------
 **System  ����ʱ��
-----------------------------------------------------------------------------*/
#define 	SYS_CLK_ADC1_MSK		(SYS_AHBCKEN_ADC1CE_Msk)	/*ADC1ʱ��ʹ��λ*/
#define 	SYS_CLK_ACMP_MSK		(SYS_AHBCKEN_ACMPCE_Msk)	/*ģ��Ƚ���ʱ��ʹ��λ*/
#define 	SYS_CLK_OPA_PGA_MSK		(SYS_AHBCKEN_OP_PGACE_Msk)	/*�˷�/GPAʱ��ʹ��λ*/
#define 	SYS_CLK_EPWM_MSK		(SYS_AHBCKEN_EPWMCE_Msk)	/*EPWMʱ��ʹ��λ*/
#define 	SYS_CLK_CRC_MSK			(SYS_AHBCKEN_CRCCE_Msk)		/*CRCʱ��ʹ��λ*/
#define 	SYS_CLK_WWDT_MSK		(SYS_AHBCKEN_WWDTCE_Msk)	/*WWDTʱ��ʹ��λ*/
#define 	SYS_CLK_CCP_MSK			(SYS_AHBCKEN_CCPCE_Msk)		/*����/PWMʱ��ʹ��λ*/
#define 	SYS_CLK_ADC0_MSK		(SYS_AHBCKEN_ADC0CE_Msk)	/*ADC0ʱ��ʹ��λ*/
#define 	SYS_CLK_SSP_MSK			(SYS_AHBCKEN_SPPCE_Msk)		/*SSPʱ��ʹ��λ*/
#define 	SYS_CLK_I2C_MSK			(SYS_AHBCKEN_I2CCE_Msk)		/*I2Cʱ��ʹ��λ*/
#define 	SYS_CLK_UART1_MSK		(SYS_AHBCKEN_UART1CE_Msk)	/*UART1ʱ��ʹ��λ*/
#define 	SYS_CLK_UART0_MSK		(SYS_AHBCKEN_UART0CE_Msk)	/*UART0ʱ��ʹ��λ*/
#define 	SYS_CLK_HWDIVCE_MSK		(SYS_AHBCKEN_HWDIVCE_Msk)	/*Ӳ��������ʱ��ʹ��λ*/
#define 	SYS_CLK_TIMER01_MSK		(SYS_AHBCKEN_TIMER01CE_Msk)	/*��ʱ��ʱ��ʹ��λ*/
#define 	SYS_CLK_WDT_MSK			(SYS_AHBCKEN_WDTCE_Msk)		/*WDTʱ��ʹ��λ*/

/*----------------------------------------------------------------------------
 **System  ʱ�����ѡ��
-----------------------------------------------------------------------------*/
#define		SYS_CLK_OUT_SEL_AHB		(0x0UL<<SYS_CLKODIV_CLKSEL_Pos)	/*ʱ�����ѡ��AHPʱ��*/
#define		SYS_CLK_OUT_SEL_HSI		(0x1UL<<SYS_CLKODIV_CLKSEL_Pos)	/*ʱ�����ѡ��HSIʱ��*/

/*----------------------------------------------------------------------------
 **System  ��Դ����
-----------------------------------------------------------------------------*/
#define		SYS_STOP_MODE			(0x1UL<<SYS_PCON_STOP_Pos)		/*ϵͳ����ֹͣģʽ*/
#define		SYS_SLEEP_MODE			(0x1UL<<SYS_PCON_SLEEP_Pos)		/*ϵͳ����˯��ģʽ*/	
#define		SYS_DEEP_SLEEP_MODE		(0x1UL<<SYS_PCON_DEEPSLEEP_Pos)	/*ϵͳ�������˯��ģʽ*/	
#define		SYS_PCON_WRITE_KEY		(0x5A690000UL)					/*�Ĵ���д����*/
/*----------------------------------------------------------------------------
 **System  ϵͳ��λ
-----------------------------------------------------------------------------*/
#define		SYS_RESET_CPU_MODE		(0x55AA669AUL)		/*����CPU��λ,��������������*/
#define		SYS_RESET_MCU_MODE		(0x55AA6699UL)		/*����MCU��λ,���¼�����������*/
#define 	SYS_RESET_IO_CLOSE		(0x3UL<<SYS_IOMUX_RESETPORT_Pos)	/*�ⲿ��λ��ֹ*/
#define 	SYS_RESET_IO_P10		(0x2UL<<SYS_IOMUX_RESETPORT_Pos)	/*P10���ⲿ��λ����*/
#define 	SYS_RESET_IO_P44		(0x1UL<<SYS_IOMUX_RESETPORT_Pos)	/*P44���ⲿ��λ����*/
#define 	SYS_RESET_IO_P43		(0x0UL<<SYS_IOMUX_RESETPORT_Pos)	/*P43���ⲿ��λ����*/

/*----------------------------------------------------------------------------
 **System  LVDϵͳ���
-----------------------------------------------------------------------------*/
#define		SYS_LVD_2V				(0x00UL)			/*LVD����ѹѡ��2V*/
#define		SYS_LVD_2P2V			(0x01UL)			/*LVD����ѹѡ��2.2V*/
#define		SYS_LVD_2P4V			(0x02UL)			/*LVD����ѹѡ��2.4V*/
#define		SYS_LVD_2P7V			(0x03UL)			/*LVD����ѹѡ��2.7V*/
#define		SYS_LVD_3V				(0x04UL)			/*LVD����ѹѡ��3V*/
#define		SYS_LVD_3P7V			(0x05UL)			/*LVD����ѹѡ��3.7V*/

/*----------------------------------------------------------------------------
 **System  SRAMд����
-----------------------------------------------------------------------------*/
#define 	SYS_SRAM_PORTECT_2K_4K_MSK	(0x2UL)			/*SRAM��2K~4K��ַ��Χд����*/	
#define 	SYS_SRAM_PORTECT_4K_6K_MSK	(0x4UL)			/*SRAM��4K~6K��ַ��Χд����*/	
#define 	SYS_SRAM_PORTECT_6K_8K_MSK	(0x8UL)			/*SRAM��6K~8K��ַ��Χд����*/	
#define		SYS_SRAMLOCK_WRITE_KEY		(0x55AA0000UL)	/*�Ĵ���SRAMLOCKд����λ*/

/*----------------------------------------------------------------------------
 **System  IOд����
-----------------------------------------------------------------------------*/
#define 	SYS_GPIOLOCK_WRETE_KEY		(0x99UL)		/*IO��������*/
/*----------------------------------------------------------------------------
 **System  IO����
-----------------------------------------------------------------------------*/
/*----------GPIO_P0_0--------------------------------------------------------*/
#define 	SYS_IOCFG_P00_GPIO		(0x00UL)
#define		SYS_IOCFG_P00_AN0		(0x00UL)
#define 	SYS_IOCFG_P00_TXD0		(0x02UL)
#define		SYS_IOCFG_P00_CTS0		(0x03UL)
#define 	SYS_IOCFG_P00_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P00_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P00_EPWM2		(0x06UL)
#define		SYS_IOCFG_P00_SWDCLK2	(0x07UL)
#define		SYS_IOCFG_P00_TXD1		(0x08UL)
#define		SYS_IOCFG_P00_RXD1		(0x09UL)
/*----------GPIO_P0_1--------------------------------------------------------*/
#define 	SYS_IOCFG_P01_GPIO		(0x00UL)
#define		SYS_IOCFG_P01_AN1		(0x01UL)
#define 	SYS_IOCFG_P01_RXD0		(0x02UL)
#define		SYS_IOCFG_P01_RTS0		(0x03UL)
#define 	SYS_IOCFG_P01_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P01_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P01_EPWM0		(0x06UL)
#define		SYS_IOCFG_P01_ADET		(0x07UL)
#define		SYS_IOCFG_P01_TXD1		(0x08UL)
#define		SYS_IOCFG_P01_RXD1		(0x09UL)
/*----------GPIO_P0_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P04_GPIO		(0x00UL)
#define		SYS_IOCFG_P04_AN2		(0x01UL)
#define		SYS_IOCFG_P04_CTS1		(0x03UL)
#define 	SYS_IOCFG_P04_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P04_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P04_EPWM1		(0x06UL)
#define		SYS_IOCFG_P04_SPI0CLK	(0x07UL)
#define		SYS_IOCFG_P04_TXD1		(0x08UL)
#define		SYS_IOCFG_P04_RXD1		(0x09UL)
/*----------GPIO_P0_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P05_GPIO		(0x00UL)
#define		SYS_IOCFG_P05_AN3		(0x01UL)
#define		SYS_IOCFG_P05_RTS1		(0x03UL)
#define 	SYS_IOCFG_P05_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P05_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P05_EPWM2		(0x06UL)
#define		SYS_IOCFG_P05_ADET		(0x07UL)
#define		SYS_IOCFG_P05_TXD1		(0x08UL)
#define		SYS_IOCFG_P05_RXD1		(0x09UL)
/*----------GPIO_P0_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P06_GPIO		(0x00UL)
#define		SYS_IOCFG_P06_AN4		(0x01UL)
#define		SYS_IOCFG_P06_SDA0		(0x03UL)
#define 	SYS_IOCFG_P06_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P06_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P06_EPWM3		(0x06UL)
#define		SYS_IOCFG_P06_CTS1		(0x07UL)
#define		SYS_IOCFG_P06_TXD1		(0x08UL)
#define		SYS_IOCFG_P06_RXD1		(0x09UL)
/*----------GPIO_P0_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P07_GPIO		(0x00UL)
#define		SYS_IOCFG_P07_AN5		(0x01UL)
#define		SYS_IOCFG_P07_SCL0		(0x03UL)
#define 	SYS_IOCFG_P07_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P07_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P07_EPWM4		(0x06UL)
#define		SYS_IOCFG_P07_TXD1		(0x08UL)
#define		SYS_IOCFG_P07_RXD1		(0x09UL)
/*----------GPIO_P1_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P10_GPIO		(0x00UL)
#define		SYS_IOCFG_P10_AN6		(0x01UL)
#define		SYS_IOCFG_P10_C0P5		(0x01UL)
#define		SYS_IOCFG_P10_TXD0		(0x02UL)
#define		SYS_IOCFG_P10_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P10_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P10_CTS1		(0x07UL)
#define		SYS_IOCFG_P10_TXD1		(0x08UL)
#define		SYS_IOCFG_P10_RXD1		(0x09UL)
/*----------GPIO_P1_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P12_GPIO		(0x00UL)
#define		SYS_IOCFG_P12_AN7		(0x01UL)
#define		SYS_IOCFG_P12_A1P0		(0x01UL)
#define		SYS_IOCFG_P12_RXD0		(0x02UL)
#define		SYS_IOCFG_P12_SDA0		(0x03UL)
#define		SYS_IOCFG_P12_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P12_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P12_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P12_RTS1		(0x07UL)
#define		SYS_IOCFG_P12_TXD1		(0x08UL)
#define		SYS_IOCFG_P12_RXD1		(0x09UL)
/*----------GPIO_P1_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P13_GPIO		(0x00UL)
#define 	SYS_IOCFG_P13_ECAP00	(0x00UL)
#define		SYS_IOCFG_P13_AN8		(0x01UL)
#define		SYS_IOCFG_P13_C0P0		(0x01UL)
#define		SYS_IOCFG_P13_TXD0		(0x02UL)
#define		SYS_IOCFG_P13_SCL0		(0x03UL)
#define		SYS_IOCFG_P13_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P13_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P13_EPWM1		(0x06UL)
#define		SYS_IOCFG_P13_TXD1		(0x08UL)
#define		SYS_IOCFG_P13_RXD1		(0x09UL)
/*----------GPIO_P1_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P14_GPIO		(0x00UL)
#define 	SYS_IOCFG_P14_ECAP01	(0x00UL)
#define		SYS_IOCFG_P14_AN9		(0x01UL)
#define		SYS_IOCFG_P14_C0P1		(0x01UL)
#define		SYS_IOCFG_P14_SDA0		(0x03UL)
#define		SYS_IOCFG_P14_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P14_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P14_EPWM4		(0x06UL)
#define		SYS_IOCFG_P14_TXD1		(0x08UL)
#define		SYS_IOCFG_P14_RXD1		(0x09UL)
/*----------GPIO_P1_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P15_GPIO		(0x00UL)
#define 	SYS_IOCFG_P15_ECAP02	(0x00UL)
#define		SYS_IOCFG_P15_AN10		(0x01UL)
#define		SYS_IOCFG_P15_C0P2		(0x01UL)
#define		SYS_IOCFG_P15_A1P1		(0x01UL)
#define		SYS_IOCFG_P15_SCL0		(0x03UL)
#define		SYS_IOCFG_P15_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P15_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P15_EPWM5		(0x06UL)
#define		SYS_IOCFG_P15_TXD1		(0x08UL)
#define		SYS_IOCFG_P15_RXD1		(0x09UL)
/*----------GPIO_P1_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P16_GPIO		(0x00UL)
#define		SYS_IOCFG_P16_AN11		(0x07UL)
#define		SYS_IOCFG_P16_OP1O		(0x07UL)
#define		SYS_IOCFG_P16_RXD0		(0x02UL)
#define		SYS_IOCFG_P16_SCL0		(0x03UL)
#define		SYS_IOCFG_P16_CTS0		(0x04UL)
#define		SYS_IOCFG_P16_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P16_EPWM2		(0x06UL)
#define		SYS_IOCFG_P16_TXD1		(0x08UL)
#define		SYS_IOCFG_P16_RXD1		(0x09UL)
/*----------GPIO_P1_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P17_GPIO		(0x00UL)
#define		SYS_IOCFG_P17_AN12		(0x01UL)
#define		SYS_IOCFG_P17_OP1N		(0x01UL)
#define		SYS_IOCFG_P17_TXD0		(0x02UL)
#define		SYS_IOCFG_P17_SDA0		(0x03UL)
#define		SYS_IOCFG_P17_RTS0		(0x04UL)
#define		SYS_IOCFG_P17_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P17_EPWM4		(0x06UL)
#define		SYS_IOCFG_P17_TXD1		(0x08UL)
#define		SYS_IOCFG_P17_RXD1		(0x09UL)
/*----------GPIO_P2_1-------------------------------------------------------*/
#define 	SYS_IOCFG_P21_GPIO		(0x00UL)
#define		SYS_IOCFG_P21_AN13		(0x01UL)
#define		SYS_IOCFG_P21_OP1P		(0x01UL)
#define		SYS_IOCFG_P21_RXD0		(0x02UL)
#define		SYS_IOCFG_P21_SCL0		(0x03UL)
#define		SYS_IOCFG_P21_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P21_EPWM5		(0x06UL)
#define		SYS_IOCFG_P21_TXD1		(0x08UL)
#define		SYS_IOCFG_P21_RXD1		(0x09UL)
/*----------GPIO_P2_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P22_GPIO		(0x00UL)
#define		SYS_IOCFG_P22_AN14		(0x01UL)
#define		SYS_IOCFG_P22_TXD0		(0x02UL)
#define		SYS_IOCFG_P22_SCL0		(0x03UL)
#define		SYS_IOCFG_P22_CTS1		(0x04UL)
#define		SYS_IOCFG_P22_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P22_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P22_SDA0		(0x07UL)
#define		SYS_IOCFG_P22_TXD1		(0x08UL)
#define		SYS_IOCFG_P22_RXD1		(0x09UL)
/*----------GPIO_P2_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P23_GPIO		(0x00UL)
#define		SYS_IOCFG_P23_AN15		(0x01UL)
#define		SYS_IOCFG_P23_OP0O		(0x01UL)
#define		SYS_IOCFG_P23_SDA0		(0x03UL)
#define		SYS_IOCFG_P23_RTS1		(0x04UL)
#define		SYS_IOCFG_P23_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P23_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P23_SWDDAT1	(0x07UL)
#define		SYS_IOCFG_P23_TXD1		(0x08UL)
#define		SYS_IOCFG_P23_RXD1		(0x09UL)
/*----------GPIO_P2_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P24_GPIO		(0x00UL)
#define		SYS_IOCFG_P24_AN16		(0x01UL)
#define		SYS_IOCFG_P24_OP0N		(0x01UL)
#define		SYS_IOCFG_P24_SDA0		(0x03UL)
#define		SYS_IOCFG_P24_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P24_EPWM2		(0x06UL)
#define 	SYS_IOCFG_P24_SWDCLK13	(0x07UL)
#define		SYS_IOCFG_P24_TXD1		(0x08UL)
#define		SYS_IOCFG_P24_RXD1		(0x09UL)
/*----------GPIO_P2_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P25_GPIO		(0x00UL)
#define		SYS_IOCFG_P25_AN17		(0x01UL)
#define		SYS_IOCFG_P25_OP0P		(0x01UL)
#define		SYS_IOCFG_P25_SCL0		(0x03UL)
#define		SYS_IOCFG_P25_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P25_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P25_EPWM3		(0x06UL)
#define 	SYS_IOCFG_P25_C1O		(0x07UL)
#define		SYS_IOCFG_P25_TXD1		(0x08UL)
#define		SYS_IOCFG_P25_RXD1		(0x09UL)
/*----------GPIO_P2_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P26_GPIO		(0x00UL)
#define		SYS_IOCFG_P26_AN18		(0x01UL)
#define		SYS_IOCFG_P26_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P26_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P26_EPWM4		(0x06UL)
#define 	SYS_IOCFG_P26_C0O		(0x07UL)
#define		SYS_IOCFG_P26_TXD1		(0x08UL)
#define		SYS_IOCFG_P26_RXD1		(0x09UL)
/*----------GPIO_P3_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P30_GPIO		(0x00UL)
#define 	SYS_IOCFG_P30_ECAP13	(0x00UL)
#define		SYS_IOCFG_P30_AN19		(0x01UL)
#define		SYS_IOCFG_P30_C1P3		(0x01UL)
#define		SYS_IOCFG_P30_A1P2		(0x01UL)
#define		SYS_IOCFG_P30_RXD0		(0x02UL)
#define		SYS_IOCFG_P30_CCP0A		(0x03UL)
#define		SYS_IOCFG_P30_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P30_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P30_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P30_ADET		(0x07UL)
#define		SYS_IOCFG_P30_TXD1		(0x08UL)
#define		SYS_IOCFG_P30_RXD1		(0x09UL)
/*----------GPIO_P3_1-------------------------------------------------------*/
#define 	SYS_IOCFG_P31_GPIO		(0x00UL)
#define 	SYS_IOCFG_P31_ECAP10	(0x00UL)
#define		SYS_IOCFG_P31_AN20		(0x01UL)
#define		SYS_IOCFG_P31_C1P0		(0x01UL)
#define		SYS_IOCFG_P31_A0P2		(0x01UL)
#define		SYS_IOCFG_P31_CTS0		(0x02UL)
#define		SYS_IOCFG_P31_SCL0		(0x03UL)
#define		SYS_IOCFG_P31_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P31_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P31_EPWM4		(0x06UL)
#define		SYS_IOCFG_P31_TXD1		(0x08UL)
#define		SYS_IOCFG_P31_RXD1		(0x09UL)
/*----------GPIO_P3_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P32_GPIO		(0x00UL)
#define 	SYS_IOCFG_P32_ECAP11	(0x00UL)
#define		SYS_IOCFG_P32_AN21		(0x01UL)
#define		SYS_IOCFG_P32_C1P1		(0x01UL)
#define		SYS_IOCFG_P32_A0P1		(0x01UL)
#define		SYS_IOCFG_P32_RXD0		(0x02UL)
#define		SYS_IOCFG_P32_SDA0		(0x03UL)
#define		SYS_IOCFG_P32_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P32_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P32_EPWM1		(0x06UL)
#define		SYS_IOCFG_P32_TXD1		(0x08UL)
#define		SYS_IOCFG_P32_RXD1		(0x09UL)
/*----------GPIO_P3_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P34_GPIO		(0x00UL)
#define 	SYS_IOCFG_P34_ECAP12	(0x00UL)
#define		SYS_IOCFG_P34_AN22		(0x01UL)
#define		SYS_IOCFG_P34_C1P2		(0x01UL)
#define		SYS_IOCFG_P34_A0O		(0x01UL)
#define		SYS_IOCFG_P34_TXD0		(0x02UL)
#define		SYS_IOCFG_P34_SDA0		(0x03UL)
#define		SYS_IOCFG_P34_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P34_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P34_EPWM3		(0x06UL)
#define		SYS_IOCFG_P34_TXD1		(0x08UL)
#define		SYS_IOCFG_P34_RXD1		(0x09UL)
/*----------GPIO_P3_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P35_GPIO		(0x00UL)
#define		SYS_IOCFG_P35_AN23		(0x01UL)
#define		SYS_IOCFG_P35_C1N		(0x01UL)
#define		SYS_IOCFG_P35_A1O		(0x01UL)
#define		SYS_IOCFG_P35_RTS0		(0x02UL)
#define		SYS_IOCFG_P35_SCL0		(0x03UL)
#define		SYS_IOCFG_P35_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P35_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P35_EPWM5 	(0x06UL)
#define 	SYS_IOCFG_P35_CLKO		(0x07UL)
#define		SYS_IOCFG_P35_TXD1		(0x08UL)
#define		SYS_IOCFG_P35_RXD1		(0x09UL)
/*----------GPIO_P3_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P36_GPIO		(0x00UL)
#define 	SYS_IOCFG_P36_ECAP03	(0x00UL)
#define		SYS_IOCFG_P36_AN24		(0x01UL)
#define		SYS_IOCFG_P36_C0P3		(0x01UL)
#define		SYS_IOCFG_P36_A0P0		(0x01UL)
#define		SYS_IOCFG_P36_CLKO		(0x04UL)
#define		SYS_IOCFG_P36_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P36_EPWM0 	(0x06UL)
#define 	SYS_IOCFG_P36_SWDDAT3	(0x07UL)
#define		SYS_IOCFG_P36_TXD1		(0x08UL)
#define		SYS_IOCFG_P36_RXD1		(0x09UL)
/*----------GPIO_P4_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P40_GPIO		(0x00UL)
#define		SYS_IOCFG_P40_AN25		(0x01UL)
#define		SYS_IOCFG_P40_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P40_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P40_SWDDAT2	(0x07UL)
#define		SYS_IOCFG_P40_TXD1		(0x08UL)
#define		SYS_IOCFG_P40_RXD1		(0x09UL)
/*----------GPIO_P4_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P43_GPIO		(0x00UL)
#define		SYS_IOCFG_P43_AN26		(0x01UL)
#define		SYS_IOCFG_P43_C0N		(0x01UL)
#define		SYS_IOCFG_P43_A0P3		(0x01UL)
#define		SYS_IOCFG_P43_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P43_EPWM2		(0x06UL)
#define		SYS_IOCFG_P43_TXD1		(0x08UL)
#define		SYS_IOCFG_P43_RXD1		(0x09UL)
/*----------GPIO_P4_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P44_GPIO		(0x00UL)
#define		SYS_IOCFG_P44_AN27		(0x01UL)
#define		SYS_IOCFG_P44_A1P3		(0x01UL)
#define		SYS_IOCFG_P44_TXD0		(0x02UL)
#define		SYS_IOCFG_P44_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P44_EPWM1		(0x06UL)
#define		SYS_IOCFG_P44_TXD1		(0x08UL)
#define		SYS_IOCFG_P44_RXD1		(0x09UL)
/*----------GPIO_P4_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P46_GPIO		(0x00UL)
#define		SYS_IOCFG_P46_AN28		(0x01UL)
#define		SYS_IOCFG_P46_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P46_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P46_EPWM2		(0x06UL)
#define 	SYS_IOCFG_P46_SWDCLK0	(0x07UL)
#define		SYS_IOCFG_P46_TXD1		(0x08UL)
#define		SYS_IOCFG_P46_RXD1		(0x09UL)
/*----------GPIO_P4_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P47_GPIO		(0x00UL)
#define		SYS_IOCFG_P47_AN29		(0x01UL)
#define		SYS_IOCFG_P47_RTS1		(0x03UL)
#define		SYS_IOCFG_P47_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P47_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P47_EPWM5		(0x06UL)
#define 	SYS_IOCFG_P47_SWDDAT0	(0x07UL)
#define		SYS_IOCFG_P47_TXD1		(0x08UL)
#define		SYS_IOCFG_P47_RXD1		(0x09UL)

/*****************************************************************************
 ** \brief	SYS_SET_IOCFG
 **			���� IOCFGֵ(����IO�ڵĸ��ù���)
 ** \param [in] PinCFG:	P00CFG ~ P47CFG�Ĵ���
 **				MuxMode:
 ** \return none
 ** \note	 
*****************************************************************************/	
#define SYS_SET_IOCFG(PinCFG, MuxMode)	do{\
											SYS->PinCFG = MuxMode;\
											}while(0)
/*****************************************************************************
 ** \brief	SYS_FLASH_SIZE
 **			����оƬFlash��С
 ** \param [in] none
 ** \return  0x1C: 	 SYS_FLASH_SIZE_28K  	 Flash Ϊ28K
 **			 ����:   SYS_FLASH_SIZE_32K 	 Flash Ϊ32K	
 ** \note	 
*****************************************************************************/	
#define 	SYS_FLASH_SIZE()		((SYS->DID & (SYS_DID_DSF_Msk)))

/*****************************************************************************
 ** \brief	SYS_RESET_IO_STATE
 **			���ظ�λ���ŵ�״̬
 ** \param [in] none
 ** \return  0: 	 SYS_RESET_IO_P43  		 P43���ⲿ��λ����
 **			 0x200:  SYS_RESET_IO_P44 		 P44���ⲿ��λ����
 **			 0x400:	 SYS_RESET_IO_P10		 P10���ⲿ��λ����
 **			 0x600:	 SYS_RESET_IO_CLOSE      �ⲿ��λ��ֹ
 ** \note	 
*****************************************************************************/	
#define 	SYS_GET_RESET_IO_STATE()		((SYS->IOMUX & (SYS_IOMUX_RESETPORT_Msk)))

/*****************************************************************************
 ** \brief	SYS_SET_LVD_LEVERL
 **			����LVD��ѹ
 ** \param [in] LVDLevel��(1)SYS_LVD_2V		LVD����ѹѡ��2V
 **						  (2)SYS_LVD_2P2V	LVD����ѹѡ��2.2V
 **						  (3)SYS_LVD_2P4V	LVD����ѹѡ��2.4V
 **						  (4)SYS_LVD_2P7V	LVD����ѹѡ��2.7
 **						  (5)SYS_LVD_3V		LVD����ѹѡ��3V
 **						  (6)SYS_LVD_3P7V	LVD����ѹѡ��3.7
 ** \return  none
 ** \note	 
*****************************************************************************/
#define		SYS_SET_LVD_LEVERL(LVDLevel)	do{\
												SYS->LVDCON  = LVDLevel;\
											  }while(1)
/*****************************************************************************
 ** \brief	SYS_IS_LVD_LESS_VDD
 **			LVD��ѹ����VDD��ѹ
 ** \param [in] none
 ** \return  0��LVD��ѹС��LVD��ѹ  1:LVD��ѹ����VDD��ѹ
 ** \note	 
*****************************************************************************/	
#define		SYS_IS_LVD_GREATER_VDD()		((SYS->RIS & SYS_RIS_LVDRIS_Msk)? 1:0)

/*****************************************************************************
 ** \brief	SYS_ENABLE_APBCLK
 **			��������ʱ��
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1ʱ��ʹ��λ
 **						  (2)SYS_CLK_ACMP_MSK:		ģ��Ƚ���ʱ��ʹ��λ				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	�˷�/PGAʱ��ʹ��λ	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWMʱ��ʹ��λ	
 **						  (5)SYS_CLK_CRC_MSK:		CRCʱ��ʹ��λ	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDTʱ��ʹ��λ	
 **						  (7)SYS_CLK_CCP_MSK:		����/PWMʱ��ʹ��λ	
 **						  (9)SYS_CLK_SSP_MSK:		SSPʱ��ʹ��λ	
 **						  (10)SYS_CLK_I2C_MSK:		I2Cʱ��ʹ��λ	
 **						  (11)SYS_CLK_UART1_MSK:	UART1ʱ��ʹ��λ	
 **						  (12)SYS_CLK_UART0_MSK:	UART0ʱ��ʹ��λ	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	Ӳ��������ʱ��ʹ��λ	
 **						  (14)SYS_CLK_TIMER01_MSK:	��ʱ��ʱ��ʹ��λ	
 **						  (15)SYS_CLK_WDT_MSK:		WDTʱ��ʹ��λ	
 ** \return  none
 ** \note	 
*****************************************************************************/	
#define		SYS_ENABLE_APBCLK(ModuleMask)	do{\
												SYS->APBCKEN |= ModuleMask;\
												}while(0)
/*****************************************************************************
 ** \brief	SYS_DISABLE_APBCLK
 **			�ر�����ʱ��
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1ʱ��ʹ��λ
 **						  (2)SYS_CLK_ACMP_MSK:		ģ��Ƚ���ʱ��ʹ��λ				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	�˷�/PGAʱ��ʹ��λ	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWMʱ��ʹ��λ	
 **						  (5)SYS_CLK_CRC_MSK:		CRCʱ��ʹ��λ	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDTʱ��ʹ��λ	
 **						  (7)SYS_CLK_CCP_MSK:		����/PWMʱ��ʹ��λ	
 **						  (9)SYS_CLK_SSP_MSK:		SSPʱ��ʹ��λ	
 **						  (10)SYS_CLK_I2C_MSK:		I2Cʱ��ʹ��λ	
 **						  (11)SYS_CLK_UART1_MSK:	UART1ʱ��ʹ��λ	
 **						  (12)SYS_CLK_UART0_MSK:	UART0ʱ��ʹ��λ	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	Ӳ��������ʱ��ʹ��λ	
 **						  (14)SYS_CLK_TIMER01_MSK:	��ʱ��ʱ��ʹ��λ	
 **						  (15)SYS_CLK_WDT_MSK:		WDTʱ��ʹ��λ	
 ** \return  none
 ** \note	 
*****************************************************************************/	
#define		SYS_DISABLE_APBCLK(ModuleMask)	do{\
												SYS->APBCKEN &= ~(ModuleMask);\
												}while(0)

											  
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	SYS_EnterStop
 **			ϵͳ����ֹͣģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterStop(void)
{
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_STOP_MODE;
	__ASM("WFI");	
}
/*****************************************************************************
 ** \brief	SYS_EnterSleep
 **			ϵͳ����˯��ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterSleep(void)
{
	SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_SLEEP_MODE;
	__ASM("WFI");
}
/*****************************************************************************
 ** \brief	SYS_EnterDeepSleep
 **			ϵͳ�������˯��ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterDeepSleep(void)
{
	SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_DEEP_SLEEP_MODE;
	__ASM("WFI");
}

/*****************************************************************************
 ** \brief	SYS_ResetMCU
 **			��λMCU
 ** \param [in] none
 ** \return  none
 ** \note   ����MCU��λ,���¼����������� 
*****************************************************************************/
__STATIC_INLINE  void SYS_ResetMCU(void)
{
	SYS->RSTCON = SYS_RESET_MCU_MODE;
}
/*****************************************************************************
 ** \brief	SYS_ResetCPU
 **			��λCPU
 ** \param [in] none
 ** \return  none
 ** \note	����CPU��λ,��������������
*****************************************************************************/
__STATIC_INLINE  void SYS_ResetCPU(void)
{
	SYS->RSTCON = SYS_RESET_CPU_MODE;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO0Protect
 **			ʹ��GPIO0����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO0Protect(void)
{
	SYS->GPIO0LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO0Protect
 **			�ر�GPIO0����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO0Protect(void)
{
	SYS->GPIO0LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO1Protect
 **			ʹ��GPIO1����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO1Protect(void)
{
	SYS->GPIO1LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO1Protect
 **			�ر�GPIO1����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO1Protect(void)
{
	SYS->GPIO1LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO2Protect
 **			ʹ��GPIO2����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO2Protect(void)
{
	SYS->GPIO2LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO2Protect
 **			�ر�GPIO2����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO2Protect(void)
{
	SYS->GPIO2LOCK = SYS_GPIOLOCK_WRETE_KEY;
}

/*****************************************************************************
 ** \brief	SYS_EnableGPIO3Protect
 **			ʹ��GPIO3����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO3Protect(void)
{
	SYS->GPIO3LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO3Protect
 **			�ر�GPIO3����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO3Protect(void)
{
	SYS->GPIO3LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO4Protect
 **			ʹ��GPIO4����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO4Protect(void)
{
	SYS->GPIO4LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO4Protect
 **			�ر�GPIO4����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO4Protect(void)
{
	SYS->GPIO4LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableIOCFGProtect
 **			ʹ��GPIO Config ����
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableIOCFGProtect(void)
{
	SYS->IOCFGLOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableIOCFGProtect
 **			�ر�GPIO Config ���� 
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableIOCFGProtect(void)
{
	SYS->IOCFGLOCK = SYS_GPIOLOCK_WRETE_KEY;
}

/*****************************************************************************
 ** \brief	SYS_GetCPUResetFlag
 **			��ȡCPU��λ��־
 ** \param [in] none			
 ** \return  0:δ��λ  1����λ
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetCPUResetFlag( void);
/*****************************************************************************
 ** \brief	SYS_GetMCUResetFlag
 **			��ȡMCU��λ��־
 ** \param [in] none			
 ** \return  0:δ��λ  1����λ
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetMCUResetFlag( void);
/*****************************************************************************
 ** \brief	SYS_GetWDTResetFlag
 **			��ȡWDT��λϵͳ��־
 ** \param [in] none			
 ** \return  0:WDTδ��λϵͳ  1��WDT��λϵͳ
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetWDTResetFlag( void);

/*****************************************************************************
 ** \brief	WWDT_GetWWDTResetFlag
 **			��ȡWWDT��λϵͳ��־
 ** \param [in] none			
 ** \return  0:WWDTδ��λϵͳ  1��WWDT��λϵͳ
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetWWDTResetFlag( void);

/*****************************************************************************
 ** \brief	SYS_EnableClkOutput
 **			ʹ��ϵͳʱ�����
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableClkOutput(void);
/*****************************************************************************
 ** \brief	SYS_DisableClkOutput
 **			�ر�ϵͳʱ�����
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableClkOutput(void);
/*****************************************************************************
 ** \brief	SYS_ConfigClkOutput
 **			����ϵͳʱ�����
 ** \param [in] ClkSel : (1)SYS_CLK_OUT_SEL_AHB		
 **						 (2)SYS_CLK_OUT_SEL_HSI
 **				ClkDiv : 0~255   ʱ�������Ƶ
 ** \return  none
 ** \note	0: FCLKO=FSEL ��1~255: FCLKO=FSEL/(2��DIV)
*****************************************************************************/
void  SYS_ConfigClkOutput(uint32_t ClkSel , uint32_t ClkDiv);

/*****************************************************************************
 ** \brief	SYS_EnableHSI
 **			ʹ�ܸ���ʱ��
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableHSI(void);
/*****************************************************************************
 ** \brief	SYS_DisableHSI
 **			�رո���ʱ��
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableHSI(void);
/*****************************************************************************
 ** \brief	SYS_ConfigHSI
 **			���ø���ʱ��
 ** \param [in] HSISel: (1)SYS_CLK_HSI_64M
 **						(2)SYS_CLK_HSI_48M
 ** \return  none
 ** \note �л���ͬ��HSI Ƶ��ʱ����ҪԼ125us��4~5*TLSI�������л�����ѡ��Ƶ�ʣ�
 **		  �ڴ��ڼ䣬CPU ��ͣ���С�
*****************************************************************************/
void  SYS_ConfigHSI(uint32_t HSISel);
/*****************************************************************************
 ** \brief	SYS_EnableTRIMAdjustHSI
 **			����TRIM��������Ƶ��
 ** \param [in] AdjValue: 0~255
 ** \return  none
 ** \note  �ϵ��ı�CLKCON[0]λʱ��ϵͳ�Զ����س���ʱ���޵�ֵ
*****************************************************************************/
void  SYS_EnableTRIMAdjustHSI(uint32_t AdjValue);
/*****************************************************************************
 ** \brief	SYS_ConfigAHBClock
 **			����AHBʱ��
 ** \param [in] ClkSel :(1)SYS_CLK_SEL_HSI
 **						(2)SYS_CLK_SEL_LSI
 **				ClkDiv ��0~ 255	
 ** \return  none
 ** \note	(1) 0: HCLK = FSYS �� 1~255: HCLK = FSYS/(2��DIV)
 **			(2) �˺����Զ����� SystemCoreClockUpdate(),ˢ��ϵͳʱ��ֵ
*****************************************************************************/
void  SYS_ConfigAHBClock(uint32_t ClkSel, uint32_t ClkDiv);
/*****************************************************************************
 ** \brief	SYS_ConfigAPBClock
 **			����APBʱ��
 ** \param [in] ClkDiv ��0~255				
 ** \return  none
 ** \note	(1) 0: PCLK = HCLK�� 1~255: PCLK = HCLK/(2��DIV)
 **			(2) �˺����Զ����� SystemCoreClockUpdate(),ˢ��ϵͳʱ��ֵ
*****************************************************************************/
void  SYS_ConfigAPBClock( uint32_t ClkDiv);


/*****************************************************************************
 ** \brief	SYS_ConfigLVDLevel
 **			����LVD��ѹ
 ** \param [in] LVDLevel��(1)SYS_LVD_2V		LVD����ѹѡ��2V
 **						  (2)SYS_LVD_2P2V	LVD����ѹѡ��2.2V
 **						  (3)SYS_LVD_2P4V	LVD����ѹѡ��2.4V
 **						  (4)SYS_LVD_2P7V	LVD����ѹѡ��2.7
 **						  (5)SYS_LVD_3V		LVD����ѹѡ��3V
 **						  (6)SYS_LVD_3P7V	LVD����ѹѡ��3.0	
 ** \return  none
 ** \note	LVDһֱ����
*****************************************************************************/
void SYS_ConfigLVDLevel(uint32_t LVDLevel);

/*****************************************************************************
 ** \brief	SYS_EnableLVDInt
 **			ʹ��LVD�ж�
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void SYS_EnableLVDInt(void);
/*****************************************************************************
 ** \brief	SYS_DisableLVDInt
 **			�ر�LVD�ж�
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void SYS_DisableLVDInt(void);
/*****************************************************************************
 ** \brief	SYS_GetLVDIntFlag
 **			��ȡLVD�ж�״̬��־
 ** \param [in] none			
 ** \return  0��δ�����ж� 1��ʹ�ܲ������ж�
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetLVDIntFlag(void);
/*****************************************************************************
 ** \brief	SYS_GetLVDStateFlag
 **			��ȡLVD״̬��־
 ** \param [in] none			
 ** \return  1��LVD����VDD 0��LVDС��VDD
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetLVDStateFlag(void);

/*****************************************************************************
 ** \brief	SYS_ClearLVDIntFlag
 **			���LVD�ж�״̬��־
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_ClearLVDIntFlag(void);

/*****************************************************************************
 ** \brief	SYS_EnableSARMProtect
 **			����SRAM����
 ** \param [in] SRAMAddrMask :(1) SYS_SRAM_PORTECT_2K_4K_MSK 	RAM��2K~4K��ַ��Χд����
 **							  (2) SYS_SRAM_PORTECT_4K_6K_MSK	SRAM��4K~6K��ַ��Χд����
 **							  (3) SYS_SRAM_PORTECT_6K_8K_MSK	SRAM��6K~8K��ַ��Χд����
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableSARMProtect(uint32_t SRAMAddrMask);
/*****************************************************************************
 ** \brief	SYS_DisableSARMProtect
 **			�ر�SRAM����
 ** \param [in] SRAMAddrMask :(1) SYS_SRAM_PORTECT_2K_4K_MSK 	RAM��2K~4K��ַ��Χд����
 **							  (2) SYS_SRAM_PORTECT_4K_6K_MSK	SRAM��4K~6K��ַ��Χд����
 **							  (3) SYS_SRAM_PORTECT_6K_8K_MSK	SRAM��6K~8K��ַ��Χд����
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableSARMProtect(uint32_t SRAMAddrMask);

/*****************************************************************************
 ** \brief	SYS_DisablePeripheralClk
 **			�ر�����ʱ��
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1ʱ��ʹ��λ
 **						  (2)SYS_CLK_ACMP_MSK:		ģ��Ƚ���ʱ��ʹ��λ				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	�˷�/PGAʱ��ʹ��λ	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWMʱ��ʹ��λ	
 **						  (5)SYS_CLK_CRC_MSK:		CRCʱ��ʹ��λ	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDTʱ��ʹ��λ	
 **						  (7)SYS_CLK_CCP_MSK:		����/PWMʱ��ʹ��λ	
 **						  (9)SYS_CLK_SSP_MSK:		SSPʱ��ʹ��λ	
 **						  (10)SYS_CLK_I2C_MSK:		I2Cʱ��ʹ��λ	
 **						  (11)SYS_CLK_UART1_MSK:	UART1ʱ��ʹ��λ	
 **						  (12)SYS_CLK_UART0_MSK:	UART0ʱ��ʹ��λ	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	Ӳ��������ʱ��ʹ��λ	
 **						  (14)SYS_CLK_TIMER01_MSK:	��ʱ��ʱ��ʹ��λ	
 **						  (15)SYS_CLK_WDT_MSK:		WDTʱ��ʹ��λ	
 ** \return  none
 ** \note	 
*****************************************************************************/	
void 	SYS_DisablePeripheralClk(uint32_t ModuleMask);
/*****************************************************************************
 ** \brief	SYS_EnablePeripheralClk
 **			��������ʱ��
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1ʱ��ʹ��λ
 **						  (2)SYS_CLK_ACMP_MSK:		ģ��Ƚ���ʱ��ʹ��λ				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	�˷�/PGAʱ��ʹ��λ	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWMʱ��ʹ��λ	
 **						  (5)SYS_CLK_CRC_MSK:		CRCʱ��ʹ��λ	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDTʱ��ʹ��λ	
 **						  (7)SYS_CLK_CCP_MSK:		����/PWMʱ��ʹ��λ	
 **						  (9)SYS_CLK_SSP_MSK:		SSPʱ��ʹ��λ	
 **						  (10)SYS_CLK_I2C_MSK:		I2Cʱ��ʹ��λ	
 **						  (11)SYS_CLK_UART1_MSK:	UART1ʱ��ʹ��λ	
 **						  (12)SYS_CLK_UART0_MSK:	UART0ʱ��ʹ��λ	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	Ӳ��������ʱ��ʹ��λ	
 **						  (14)SYS_CLK_TIMER01_MSK:	��ʱ��ʱ��ʹ��λ	
 **						  (15)SYS_CLK_WDT_MSK:		WDTʱ��ʹ��λ	
 ** \return  none
 ** \note	 
*****************************************************************************/	
void 	SYS_EnablePeripheralClk(uint32_t ModuleMask);





#ifdef __cplusplus
}
#endif
#endif /* __SYSTEM_H__ */

