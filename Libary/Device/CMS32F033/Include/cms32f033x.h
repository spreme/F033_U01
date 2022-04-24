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
/** \file cms32f033x.h
**
**
** History:
** 
*****************************************************************************/
#ifndef __CMS32F033X_H__
#define __CMS32F033X_H__

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************/
/* Include files */
/*****************************************************************************/

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
	NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                      */
	HardFaULt_IRQn                = -13,      /*!<  3 Hard FaULt Interrupt                        */
	SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                           */
	PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                           */
	SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                       */   
/******  CMS32F030x Specific Interrupt Numbers ****************************************************/
	GPIO0_IRQn           = 0,       		/*!< GPIO 0 Interrupt                                 */
	GPIO1_IRQn           = 1,     			/*!< GPIO 1 Interrupt                                 */
	GPIO2_IRQn           = 2,      			/*!< GPIO 2 Interrupt                                 */
	GPIO3_IRQn           = 3,      			/*!< GPIO 3 Interrupt                                 */
	GPIO4_IRQn           = 4,       		/*!< GPIO 4 Interrupt                                 */	
	CCP_IRQn             = 6,       		/*!< Capture/PWM Interrupt                            */
	WWDT_IRQn            = 9,      			/*!< WWDT    Interrupt     			                 		  */
	EPWM_IRQn            = 10,       		/*!< EPWM    Interrupt     			                		  */
	ADC1_IRQn            = 12,     			/*!< ADC 1   Converter Interrupt                      */
	ACMP_IRQn            = 13,       		/*!< ACMP    Interrupt 			                     		  */
	UART0_IRQn           = 15,       		/*!< UART0   Interrupt 			                    		  */
	UART1_IRQn           = 16,      		/*!< UART1   Interrupt  			                 			  */
	TMR0_IRQn            = 19,     			/*!< timer 0 Interrupt     			                      */
	TMR1_IRQn            = 20,      		/*!< timer 1 Interrupt         			                  */
	WDT_IRQn             = 23,       		/*!< WDT  	 Interrupt                     			      */
	I2C_IRQn             = 24,     			/*!< I2C 	 Interrupt                     			        */
	SPI_IRQn             = 26,       		/*!< SPI  	 Interrupt                     			      */
	LVD_IRQn             = 31,       		/*!< LVD	 Interrupt                    			        */   
} IRQn_Type;
/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT           0       /*!< armikcmu does not provide a MPU present or not       */
#define __NVIC_PRIO_BITS        2       /*!< armikcmu Supports 2 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used         */

/*@}*/ /* end of group CMSIS */

#include "core_cm0.h"
#include "system_cms32f033x.h"


typedef int32_t  s32;
typedef int16_t  s16;
typedef int8_t   s8;

typedef uint32_t  u32;
typedef uint16_t  u16;
typedef uint8_t   u8;

#ifndef SUCCESS
#define SUCCESS  0
#endif
#ifndef ERROR
#define ERROR    -1
#endif

#ifndef NULL
#define NULL 0
#endif

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*---------------------- System Manger Controller -------------------------*/
typedef struct
{
	__I  uint32_t DID;					
	__IO uint32_t AHBCKDIV;				
	__IO uint32_t APBCKDIV;				
	__IO uint32_t APBCKEN;
	__IO uint32_t CLKDIV;
	__IO int32_t PCON;
	__O	 uint32_t RSTCON;
	__IO uint32_t RSTSTAT;
	__IO uint32_t CLKCON;
	__IO uint32_t CLKSEL;
	__I	 uint32_t CLKSTAT;
	__IO uint32_t APBCKSEL;
	__I	 uint32_t IOMUX;
	__I  uint32_t CIDL;
	__I  uint32_t CIDH;
	__IO uint32_t LVDCON;
	__IO uint32_t IOP00CFG;
	__IO uint32_t IOP01CFG;	
	__I  uint32_t RESERVE0[2];	
	__IO uint32_t IOP04CFG;	
	__IO uint32_t IOP05CFG;	
	__IO uint32_t IOP06CFG;	
	__IO uint32_t IOP07CFG;	
	__IO uint32_t IOP10CFG;	
	__I  uint32_t RESERVE1;	
	__IO uint32_t IOP12CFG;	
	__IO uint32_t IOP13CFG;	
	__IO uint32_t IOP14CFG;	
	__IO uint32_t IOP15CFG;	
	__IO uint32_t IOP16CFG;
	__IO uint32_t IOP17CFG;	
	__I  uint32_t RESERVE2;	
	__IO uint32_t IOP21CFG;	
	__IO uint32_t IOP22CFG;	
	__IO uint32_t IOP23CFG;	
	__IO uint32_t IOP24CFG;	
	__IO uint32_t IOP25CFG;	
	__IO uint32_t IOP26CFG;	
	__I  uint32_t RESERVE3;
	__IO uint32_t IOP30CFG;	
	__IO uint32_t IOP31CFG;	
	__IO uint32_t IOP32CFG;	
	__I  uint32_t RESERVE4;	
	__IO uint32_t IOP34CFG;	
	__IO uint32_t IOP35CFG;	
	__IO uint32_t IOP36CFG;	
	__I  uint32_t RESERVE5;	
	__IO uint32_t IOP40CFG;		
	__I  uint32_t RESERVE6[2];	
	__IO uint32_t IOP43CFG;		
	__IO uint32_t IOP44CFG;		
	__I  uint32_t RESERVE7;	
	__IO uint32_t IOP46CFG;		
	__IO uint32_t IOP47CFG;	
	__I  uint32_t RESERVE8[8];
	__IO uint32_t IMSC;		
	__I  uint32_t RIS;	
	__I  uint32_t MIS;	
	__O  uint32_t ICLR;	
	__IO uint32_t TRIM;	
	__I  uint32_t RESERVE9[39];
	__IO uint32_t SRAMLOCK;	
	__I  uint32_t RESERVE10[3];
	__IO uint32_t GPIO0LOCK;	
	__IO uint32_t GPIO1LOCK;
	__IO uint32_t GPIO2LOCK;
	__IO uint32_t GPIO3LOCK;
	__IO uint32_t GPIO4LOCK;
	__I  uint32_t RESERVE11[10];
	__IO uint32_t IOCFGLOCK;
} SYS_T;

/*------DID-----------------------------------------------------------------*/
#define	SYS_DID_DNO_Pos		(16)
#define SYS_DID_DNO_Msk		(0xffffUL<<SYS_DID_DNO_Pos)
#define	SYS_DID_DSF_Pos		(0)
#define SYS_DID_DSF_Msk		(0xffUL<<SYS_DID_DSF_Pos)
/*------AHBCKDIV------------------------------------------------------------*/
#define	SYS_AHBCKDIV_AHBDIV_Pos		(0)
#define SYS_AHBCKDIV_AHBDIV_Msk		(0xffUL<<SYS_AHBCKDIV_AHBDIV_Pos)
/*------APBCKDIV------------------------------------------------------------*/
#define	SYS_APBCKDIV_APBDIV_Pos		(0)
#define SYS_APBCKDIV_APBDIV_Msk		(0xffUL<<SYS_APBCKDIV_APBDIV_Pos)
/*------AHBCKEN-------------------------------------------------------------*/
#define	SYS_AHBCKEN_ADC1CE_Pos		(27)
#define SYS_AHBCKEN_ADC1CE_Msk		(0x1UL<<SYS_AHBCKEN_ADC1CE_Pos)
#define	SYS_AHBCKEN_ACMPCE_Pos		(26)
#define SYS_AHBCKEN_ACMPCE_Msk		(0x1UL<<SYS_AHBCKEN_ACMPCE_Pos)
#define	SYS_AHBCKEN_OP_PGACE_Pos	(25)
#define SYS_AHBCKEN_OP_PGACE_Msk	(0x1UL<<SYS_AHBCKEN_OP_PGACE_Pos)
#define	SYS_AHBCKEN_EPWMCE_Pos		(21)
#define SYS_AHBCKEN_EPWMCE_Msk		(0x1UL<<SYS_AHBCKEN_EPWMCE_Pos)
#define	SYS_AHBCKEN_CRCCE_Pos		(20)
#define SYS_AHBCKEN_CRCCE_Msk		(0x1UL<<SYS_AHBCKEN_CRCCE_Pos)
#define	SYS_AHBCKEN_WWDTCE_Pos		(14)
#define SYS_AHBCKEN_WWDTCE_Msk		(0x1UL<<SYS_AHBCKEN_WWDTCE_Pos)
#define	SYS_AHBCKEN_CCPCE_Pos		(12)
#define SYS_AHBCKEN_CCPCE_Msk		(0x1UL<<SYS_AHBCKEN_CCPCE_Pos)
#define	SYS_AHBCKEN_SPPCE_Pos		(9)
#define SYS_AHBCKEN_SPPCE_Msk		(0x1UL<<SYS_AHBCKEN_SPPCE_Pos)
#define	SYS_AHBCKEN_I2CCE_Pos		(7)
#define SYS_AHBCKEN_I2CCE_Msk		(0x1UL<<SYS_AHBCKEN_I2CCE_Pos)
#define	SYS_AHBCKEN_UART1CE_Pos		(4)
#define SYS_AHBCKEN_UART1CE_Msk		(0x1UL<<SYS_AHBCKEN_UART1CE_Pos)
#define	SYS_AHBCKEN_UART0CE_Pos		(3)
#define SYS_AHBCKEN_UART0CE_Msk		(0x1UL<<SYS_AHBCKEN_UART0CE_Pos)
#define	SYS_AHBCKEN_HWDIVCE_Pos		(2)
#define SYS_AHBCKEN_HWDIVCE_Msk		(0x1UL<<SYS_AHBCKEN_HWDIVCE_Pos)
#define	SYS_AHBCKEN_TIMER01CE_Pos	(1)
#define SYS_AHBCKEN_TIMER01CE_Msk	(0x1UL<<SYS_AHBCKEN_TIMER01CE_Pos)
#define	SYS_AHBCKEN_WDTCE_Pos		(0)
#define SYS_AHBCKEN_WDTCE_Msk		(0x1UL<<SYS_AHBCKEN_WDTCE_Pos)
/*------CLKODIV-----------------------------------------------------------*/
#define	SYS_CLKODIV_CLKSEL_Pos		(9)
#define SYS_CLKODIV_CLKSEL_Msk		(0x3UL<<SYS_CLKODIV_CLKSEL_Pos)
#define	SYS_CLKODIV_EN_Pos			(8)
#define SYS_CLKODIV_EN_Msk			(0x1UL<<SYS_CLKODIV_EN_Pos)
#define	SYS_CLKODIV_DIV_Pos			(0)
#define SYS_CLKODIV_DIV_Msk			(0xffUL<<SYS_CLKODIV_DIV_Pos)
/*------PCON--------------------------------------------------------------*/
#define	SYS_PCON_KEY_Pos			(16)
#define SYS_PCON_KEY_Msk			(0xffffUL<<SYS_PCON_KEY_Pos)
#define	SYS_PCON_STOP_Pos			(2)
#define SYS_PCON_STOP_Msk			(0x1UL<<SYS_PCON_STOP_Pos)
#define	SYS_PCON_DEEPSLEEP_Pos		(1)
#define SYS_PCON_DEEPSLEEP_Msk		(0x1UL<<SYS_PCON_DEEPSLEEP_Pos)
#define	SYS_PCON_SLEEP_Pos			(0)
#define SYS_PCON_SLEEP_Msk			(0x1UL<<SYS_PCON_SLEEP_Pos)
/*------RSTSTAT-----------------------------------------------------------*/
#define	SYS_RSTSTAT_CPURS_Pos		(2)
#define SYS_RSTSTAT_CPURS_Msk		(0x1UL<<SYS_RSTSTAT_CPURS_Pos)
#define	SYS_RSTSTAT_MCURS_Pos		(1)
#define SYS_RSTSTAT_MCURS_Msk		(0x1UL<<SYS_RSTSTAT_MCURS_Pos)
#define	SYS_RSTSTAT_WDTRS_Pos		(0)
#define SYS_RSTSTAT_WDTRS_Msk		(0x1UL<<SYS_RSTSTAT_WDTRS_Pos)
/*------CLKCON------------------------------------------------------------*/
#define	SYS_CLKCON_KEY_Pos			(16)
#define SYS_CLKCON_KEY_Msk			(0xffffUL<<SYS_CLKCON_KEY_Pos)
#define	SYS_CLKCON_IRCEN_Pos		(3)
#define SYS_CLKCON_IRCEN_Msk		(0x1UL<<SYS_CLKCON_IRCEN_Pos)
#define	SYS_CLKCON_IRCSEL_Pos		(0)
#define SYS_CLKCON_IRCSEL_Msk		(0x3UL<<SYS_CLKCON_IRCSEL_Pos)
/*------CLKSEL------------------------------------------------------------*/
#define	SYS_CLKSEL_KEY_Pos			(16)
#define SYS_CLKSEL_KEY_Msk			(0xffffUL<<SYS_CLKSEL_KEY_Pos)
#define	SYS_CLKSEL_CLKSEL_Pos		(0)
#define SYS_CLKSEL_CLKSEL_Msk		(0x3UL<<SYS_CLKSEL_CLKSEL_Pos)
/*------CLKSSTAT----------------------------------------------------------*/
#define	SYS_CLKSTAT_IRCSTB_Pos		(0)
#define SYS_CLKSTAT_IRCSTB_Msk		(0x1UL<<SYS_CLKSTAT_IRCSTB_Pos)
/*------APBCKSEL----------------------------------------------------------*/
#define	SYS_APBCKSEL_TMR01SEL_Pos	(0)
#define SYS_APBCKSEL_TMR01SEL_Msk	(0x3UL<<SYS_APBCKSEL_TMR01SEL_Pos)
/*------IOMUX-------------------------------------------------------------*/
#define	SYS_IOMUX_RESETPORT_Pos		(10)
#define SYS_IOMUX_RESETPORT_Msk		(0x3UL<<SYS_IOMUX_RESETPORT_Pos)
/*------LVDCON------------------------------------------------------------*/
#define	SYS_LVDCON_SEL_Pos			(0)
#define SYS_LVDCON_SEL_Msk			(0x7UL<<SYS_LVDCON_SEL_Pos)
/*------IMSC--------------------------------------------------------------*/
#define	SYS_IMSC_LVDIMSC_Pos		(4)
#define SYS_IMSC_LVDIMSC_Msk		(0x1UL<<SYS_IMSC_LVDIMSC_Pos)
/*------RIS---------------------------------------------------------------*/
#define	SYS_RIS_LVDRIS_Pos			(4)
#define SYS_RIS_LVDRIS_Msk			(0x1UL<<SYS_RIS_LVDRIS_Pos)
/*------MIS---------------------------------------------------------------*/
#define	SYS_MIS_LVDMIS_Pos			(4)
#define SYS_MIS_LVDMIS_Msk			(0x1UL<<SYS_MIS_LVDMIS_Pos)
/*------ICLR--------------------------------------------------------------*/
#define	SYS_ICLR_LVDICLR_Pos		(4)
#define SYS_ICLR_LVDICLR_Msk		(0x1UL<<SYS_ICLR_LVDICLR_Pos)
/*------TRIM--------------------------------------------------------------*/
#define	SYS_TRIM_KEY_Pos			(16)
#define SYS_TRIM_KEY_Msk			(0xffffUL<<SYS_TRIM_KEY_Pos)
#define	SYS_TRIM_TRIM_Pos			(0)
#define SYS_TRIM_TRIM_Msk			(0xffUL<<SYS_TRIM_TRIM_Pos)
/*------SRAMLOCK----------------------------------------------------------*/
#define	SYS_SRAMLOCK_LOCK_Pos		(16)
#define SYS_SRAMLOCK_LOCK_Msk		(0xffffUL<<SYS_SRAMLOCK_LOCK_Pos)
#define	SYS_SRAMLOCK_REGION_Pos		(0)
#define SYS_SRAMLOCK_REGION_Msk		(0xfUL<<SYS_SRAMLOCK_REGION_Pos)

/*---------------------- GPIO Manger Controller -------------------------*/
typedef struct gpio_io_t{
	__IO uint32_t P0 :1;
	__IO uint32_t P1 :1;	
	__IO uint32_t P2 :1;
	__IO uint32_t P3 :1;
	__IO uint32_t P4 :1;
	__IO uint32_t P5 :1;
	__IO uint32_t P6 :1;
	__IO uint32_t P7 :1;
}gpio_io_do_t, gpio_io_di_t;

typedef struct
{					
	__IO uint32_t PMS;
	__IO uint32_t DOM;	
	union{	
	__IO uint32_t DO;
	gpio_io_do_t DO_f;	
		};
	union{
	__I  uint32_t DI;
	gpio_io_di_t DI_f;
		};
	__IO uint32_t IMSC;	
	__I  uint32_t RIS;
	__I  uint32_t MIS;
	__IO uint32_t ICLR;	
	__IO uint32_t ITYPE;	
	__IO uint32_t IVAL;
	__IO uint32_t IANY;	
	__IO uint32_t DIDB;
	__O  uint32_t DOSET;			
	__O  uint32_t DOCLR;
	__IO uint32_t DR;
	__IO uint32_t SR;
} GPIO_T;

/*------PSM-----------------------------------------------------------------*/
#define	GPIO_PMS_PMS7_Pos		(28)
#define GPIO_PMS_PMS7_Msk		(0x7UL<<GPIO_PMS_PMS7_Pos)
#define	GPIO_PMS_PMS6_Pos		(24)
#define GPIO_PMS_PMS6_Msk		(0x7UL<<GPIO_PMS_PMS6_Pos)
#define	GPIO_PMS_PMS5_Pos		(20)
#define GPIO_PMS_PMS5_Msk		(0x7UL<<GPIO_PMS_PMS5_Pos)
#define	GPIO_PMS_PMS4_Pos		(16)
#define GPIO_PMS_PMS4_Msk		(0x7UL<<GPIO_PMS_PMS4_Pos)
#define	GPIO_PMS_PMS3_Pos		(12)
#define GPIO_PMS_PMS3_Msk		(0x7UL<<GPIO_PMS_PMS3_Pos)
#define	GPIO_PMS_PMS2_Pos		(8)
#define GPIO_PMS_PMS2_Msk		(0x7UL<<GPIO_PMS_PMS2_Pos)
#define	GPIO_PMS_PMS1_Pos		(4)
#define GPIO_PMS_PMS1_Msk		(0x7UL<<GPIO_PMS_PMS1_Pos)
#define	GPIO_PMS_PMS0_Pos		(0)
#define GPIO_PMS_PMS0_Msk		(0x7UL<<GPIO_PMS_PMS0_Pos)
/*------DIDB---------------------------------------------------------------*/
#define	GPIO_DIDB_DBCK_Pos		(8)
#define GPIO_DIDB_DBCK_Msk		(0x7UL<<GPIO_DIDB_DBCK_Pos)
#define	GPIO_DIDB_DIDB_Pos		(0)
#define GPIO_DIDB_DIDB_Msk		(0xffUL<<GPIO_DIDB_DIDB_Pos)

/*---------------------- WDT Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CON;
	__IO uint32_t LOAD;	
	__I  uint32_t VAL;
	__I  uint32_t RIS;
	__I  uint32_t MIS;
	__O  uint32_t ICLR;
	__I  uint32_t RESERVE8[314];
	__IO uint32_t LOCK;		

} WDT_T;
/*------WDTCON-------------------------------------------------------------*/
#define	WDT_WDTCON_DEBUG_Pos		(16)
#define WDT_WDTCON_DEBUG_Msk		(0x1UL<<WDT_WDTCON_DEBUG_Pos)
#define	WDT_WDTCON_WDTEN_Pos		(8)
#define WDT_WDTCON_WDTEN_Msk		(0xffUL<<WDT_WDTCON_WDTEN_Pos)
#define	WDT_WDTCON_WDTPRE_Pos		(2)
#define WDT_WDTCON_WDTPRE_Msk		(0x3UL<<WDT_WDTCON_WDTPRE_Pos)
#define	WDT_WDTCON_WDTIEN_Pos		(0)
#define WDT_WDTCON_WDTIEN_Msk		(0x1UL<<WDT_WDTCON_WDTIEN_Pos)
/*------WDTRIS-------------------------------------------------------------*/
#define	WDT_WDTRIS_WDTRIS_Pos		(0)
#define WDT_WDTRIS_WDTRIS_Msk		(0x1UL<<WDT_WDTRIS_WDTRIS_Pos)
/*------WDTMIS-------------------------------------------------------------*/
#define	WDT_WDTMIS_WDTMIS_Pos		(0)
#define WDT_WDTMIS_WDTMIS_Msk		(0x1UL<<WDT_WDTMIS_WDTMIS_Pos)

/*---------------------- WWDT Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CON;
	__IO uint32_t RL;	
	__I  uint32_t VAL;
	__I  uint32_t RIS;
	__I  uint32_t MIS;
	__O  uint32_t ICLR;		
} WWDT_T;
/*------WWDTCON------------------------------------------------------------*/
#define	WWDT_WWDTCON_DEBUG_Pos		(31)
#define WWDT_WWDTCON_DEBUG_Msk		(0x1UL<<WWDT_WWDTCON_DEBUG_Pos)
#define	WWDT_WWDTCON_CMPDAT_Pos		(16)
#define WWDT_WWDTCON_CMPDAT_Msk		(0x3fUL<<WWDT_WWDTCON_CMPDAT_Pos)
#define	WWDT_WWDTCON_PSCSEL_Pos		(4)
#define WWDT_WWDTCON_PSCSEL_Msk		(0xfUL<<WWDT_WWDTCON_PSCSEL_Pos)
#define	WWDT_WWDTCON_WWDTRF_Pos		(2)
#define WWDT_WWDTCON_WWDTRF_Msk		(0x1UL<<WWDT_WWDTCON_WWDTRF_Pos)
#define	WWDT_WWDTCON_WWDTIEN_Pos	(1)
#define WWDT_WWDTCON_WWDTIEN_Msk	(0x1UL<<WWDT_WWDTCON_WWDTIEN_Pos)
#define	WWDT_WWDTCON_WWDTEN_Pos		(0)
#define WWDT_WWDTCON_WWDTEN_Msk		(0x1UL<<WWDT_WWDTCON_WWDTEN_Pos)
/*------WWDTRIS-----------------------------------------------------------*/
#define	WWDT_WWDTRIS_WWDTRIS_Pos	(0)
#define WWDT_WWDTRIS_WWDTRIS_Msk	(0x1UL<<WWDT_WWDTRIS_WWDTRIS_Pos)
/*------WWDTMIS-----------------------------------------------------------*/
#define	WWDT_WWDTMIS_WWDTMIS_Pos	(0)
#define WWDT_WWDTMIS_WWDTMIS_Msk	(0x1UL<<WWDT_WWDTMIS_WWDTMIS_Pos)
/*------WWDTICLR----------------------------------------------------------*/
#define	WWDT_WWDTICLR_WWDTICLR_Pos	(0)
#define WWDT_WWDTICLR_WWDTICLR_Msk	(0x1UL<<WWDT_WWDTICLR_WWDTICLR_Pos)
/*---------------------- CRC Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CRCIN;
	__IO uint32_t CRCD;	
} CRC_T;
/*---------------------- HWDIV Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CON;
	__IO uint32_t DIVD;	
	__IO uint32_t DIVS;	
	__I  uint32_t DIVQ;	
	__I  uint32_t DIVR;	
} HWDIV_T;
/*------HDIV-------------------------------------------------------------*/
#define	HDIV_CON_READY_Pos			(3)
#define HDIV_CON_READY_Msk			(0x1UL<<HDIV_CON_READY_Pos)
#define	HDIV_CON_DIVBY0_Pos			(2)
#define HDIV_CON_DIVBY0_Msk			(0x1UL<<HDIV_CON_DIVBY0_Pos)
#define	HDIV_CON_SIGN_Pos			(1)
#define HDIV_CON_SIGN_Msk			(0x1UL<<HDIV_CON_SIGN_Pos)
/*---------------------- Timer  Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CON;
	__IO uint32_t LOAD;
	__IO uint32_t VAL;
	__IO uint32_t RIS;
	__IO uint32_t MIS;
	__IO uint32_t ICLR;
	__IO uint32_t BGLOAD;
} TMR_T;
/*------CON---------------------------------------------------------------*/
#define	TMR_CON_TMREN_Pos			(7)
#define TMR_CON_TMREN_Msk			(0x1UL<<TMR_CON_TMREN_Pos)
#define	TMR_CON_TMRMS_Pos			(6)
#define TMR_CON_TMRMS_Msk			(0x1UL<<TMR_CON_TMRMS_Pos)
#define	TMR_CON_TMRIE_Pos			(5)
#define TMR_CON_TMRIE_Msk			(0x1UL<<TMR_CON_TMRIE_Pos)
#define	TMR_CON_TMRPRE_Pos			(2)
#define TMR_CON_TMRPRE_Msk			(0x3UL<<TMR_CON_TMRPRE_Pos)
#define	TMR_CON_TMRSZ_Pos			(1)
#define TMR_CON_TMRSZ_Msk			(0x1UL<<TMR_CON_TMRSZ_Pos)
#define	TMR_CON_TMROS_Pos			(0)
#define TMR_CON_TMROS_Msk			(0x1UL<<TMR_CON_TMROS_Pos)
/*------RIS---------------------------------------------------------------*/
#define	TMR_RIS_RIS_Pos				(0)
#define TMR_RIS_RIS_Msk				(0x1UL<<TMR_RIS_RIS_Pos)
/*------MIS---------------------------------------------------------------*/
#define	TMR_MIS_MIS_Pos				(0)
#define TMR_MIS_MIS_Msk				(0x1UL<<TMR_MIS_MIS_Pos)
/*------ICLR--------------------------------------------------------------*/
#define	TMR_ICLR_ICLR_Pos			(0)
#define TMR_ICLR_ICLR_Msk			(0x1UL<<TMR_ICLR_ICLR_Pos)
/*---------------------- CCP  Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CON0;
	__IO uint32_t LOAD0;
	__IO uint32_t D0A;
	__IO uint32_t D0B;
	__IO uint32_t CON1;
	__IO uint32_t LOAD1;
	__IO uint32_t D1A;
	__IO uint32_t D1B;
	__I  uint32_t RESERVE0[8];
	__IO uint32_t IMSC;
	__I  uint32_t RIS;
	__I  uint32_t MIS;
	__O  uint32_t ICLR;
	__IO uint32_t RUN;
	__IO uint32_t LOCK;
	__IO uint32_t CAPCON;
	__IO uint32_t CAPCHS;	
	__IO uint32_t CAP0DAT;	
	__IO uint32_t CAP1DAT;	
	__IO uint32_t CAP2DAT;	
	__IO uint32_t CAP3DAT;	
} CCP_T;
/*------CCPCON0-------------------------------------------------------------*/
#define	CCP_CCPCON0_CCP0EN_Pos		(6)
#define CCP_CCPCON0_CCP0EN_Msk		(0x1UL<<CCP_CCPCON0_CCP0EN_Pos)
#define	CCP_CCPCON0_CCP0PS_Pos		(4)
#define CCP_CCPCON0_CCP0PS_Msk		(0x3UL<<CCP_CCPCON0_CCP0PS_Pos)
#define	CCP_CCPCON0_CCP0MS_Pos		(3)
#define CCP_CCPCON0_CCP0MS_Msk		(0x1UL<<CCP_CCPCON0_CCP0MS_Pos)
#define	CCP_CCPCON0_CCP0CM0CS_Pos	(2)
#define CCP_CCPCON0_CCP0CM0CS_Msk	(0x1UL<<CCP_CCPCON0_CCP0CM0CS_Pos)
#define	CCP_CCPCON0_CCP0CM0ES_Pos	(0)
#define CCP_CCPCON0_CCP0CM0ES_Msk	(0x3UL<<CCP_CCPCON0_CCP0CM0ES_Pos)
/*------CCPLOAD0------------------------------------------------------------*/
#define	CCP_CCPLOAD0_RELOAD_Pos		(16)
#define CCP_CCPLOAD0_RELOAD_Msk		(0x1UL<<CCP_CCPLOAD0_RELOAD_Pos)
#define	CCP_CCPLOAD0_LOAD_Pos		(0)
#define CCP_CCPLOAD0_LOAD_Msk		(0xffffUL<<CCP_CCPLOAD0_LOAD_Pos)
/*------CCPD0A--------------------------------------------------------------*/
#define	CCP_CCPD0A_PWM0AOP_Pos		(16)
#define CCP_CCPD0A_PWM0AOP_Msk		(0x1UL<<CCP_CCPD0A_PWM0AOP_Pos)
#define	CCP_CCPD0A_DATA_Pos			(0)
#define CCP_CCPD0A_DATA_Msk			(0xffffUL<<CCP_CCPD0A_DATA_Pos)
/*------CCPD0B--------------------------------------------------------------*/
#define	CCP_CCPD0B_PWM0BOP_Pos		(16)
#define CCP_CCPD0B_PWM0BOP_Msk		(0x1UL<<CCP_CCPD0B_PWM0BOP_Pos)
#define	CCP_CCPD0B_DATA_Pos			(0)
#define CCP_CCPD0B_DATA_Msk			(0xffffUL<<CCP_CCPD0B_DATA_Pos)

/*------CCPCON1-------------------------------------------------------------*/
#define	CCP_CCPCON1_CCP1EN_Pos		(6)
#define CCP_CCPCON1_CCP1EN_Msk		(0x1UL<<CCP_CCPCON1_CCP1EN_Pos)
#define	CCP_CCPCON1_CCP1PS_Pos		(4)
#define CCP_CCPCON1_CCP1PS_Msk		(0x3UL<<CCP_CCPCON1_CCP1PS_Pos)
#define	CCP_CCPCON1_CCP1MS_Pos		(3)
#define CCP_CCPCON1_CCP1MS_Msk		(0x1UL<<CCP_CCPCON1_CCP1MS_Pos)
#define	CCP_CCPCON1_CCP1CM0CS_Pos	(2)
#define CCP_CCPCON1_CCP1CM0CS_Msk	(0x1UL<<CCP_CCPCON1_CCP1CM0CS_Pos)
#define	CCP_CCPCON1_CCP1CM0ES_Pos	(0)
#define CCP_CCPCON1_CCP1CM0ES_Msk	(0x3UL<<CCP_CCPCON1_CCP1CM0ES_Pos)
/*------CCPLOAD1------------------------------------------------------------*/
#define	CCP_CCPLOAD1_RELOAD_Pos		(16)
#define CCP_CCPLOAD1_RELOAD_Msk		(0x1UL<<CCP_CCPLOAD1_RELOAD_Pos)
#define	CCP_CCPLOAD1_LOAD_Pos		(0)
#define CCP_CCPLOAD1_LOAD_Msk		(0xffffUL<<CCP_CCPLOAD1_LOAD_Pos)
/*------CCPD1A--------------------------------------------------------------*/
#define	CCP_CCPD1A_PWM1AOP_Pos		(16)
#define CCP_CCPD1A_PWM1AOP_Msk		(0x1UL<<CCP_CCPD1A_PWM1AOP_Pos)
#define	CCP_CCPD1A_DATA_Pos			(0)
#define CCP_CCPD1A_DATA_Msk			(0xffffUL<<CCP_CCPD1A_DATA_Pos)
/*------CCPD1B--------------------------------------------------------------*/
#define	CCP_CCPD1B_PWM1BOP_Pos		(16)
#define CCP_CCPD1B_PWM1BOP_Msk		(0x1UL<<CCP_CCPD1B_PWM1BOP_Pos)
#define	CCP_CCPD1B_DATA_Pos			(0)
#define CCP_CCPD1B_DATA_Msk			(0xffffUL<<CCP_CCPD1B_DATA_Pos)
/*------CCPIMSC--------------------------------------------------------------*/
#define	CCP_CCPIMSC_CAP3IMSC_Pos	(11)
#define CCP_CCPIMSC_CAP3IMSC_Msk	(0x1UL<<CCP_CCPIMSC_CAP3IMSC_Pos)
#define	CCP_CCPIMSC_CAP2IMSC_Pos	(10)
#define CCP_CCPIMSC_CAP2IMSC_Msk	(0x1UL<<CCP_CCPIMSC_CAP2IMSC_Pos)
#define	CCP_CCPIMSC_CAP1IMSC_Pos	(9)
#define CCP_CCPIMSC_CAP1IMSC_Msk	(0x1UL<<CCP_CCPIMSC_CAP1IMSC_Pos)
#define	CCP_CCPIMSC_CAP0IMSC_Pos	(8)
#define CCP_CCPIMSC_CAP0IMSC_Msk	(0x1UL<<CCP_CCPIMSC_CAP0IMSC_Pos)
#define	CCP_CCPIMSC_PWMIMSC5_Pos	(5)
#define CCP_CCPIMSC_PWMIMSC5_Msk	(0x1UL<<CCP_CCPIMSC_PWMIMSC5_Pos)
#define	CCP_CCPIMSC_PWMIMSC4_Pos	(4)
#define CCP_CCPIMSC_PWMIMSC4_Msk	(0x1UL<<CCP_CCPIMSC_PWMIMSC4_Pos)
#define	CCP_CCPIMSC_PWMIMSC1_Pos	(1)
#define CCP_CCPIMSC_PWMIMSC1_Msk	(0x1UL<<CCP_CCPIMSC_PWMIMSC1_Pos)
#define	CCP_CCPIMSC_PWMIMSC0_Pos	(0)
#define CCP_CCPIMSC_PWMIMSC0_Msk	(0x1UL<<CCP_CCPIMSC_PWMIMSC0_Pos)

/*------CCPRIS---------------------------------------------------------------*/
#define	CCP_CCPRIS_CAP3IRIS_Pos		(11)
#define CCP_CCPRIS_CAP3IRIS_Msk		(0x1UL<<CCP_CCPRIS_CAP3IRIS_Pos)
#define	CCP_CCPRIS_CAP2IRIS_Pos		(10)
#define CCP_CCPRIS_CAP2IRIS_Msk		(0x1UL<<CCP_CCPRIS_CAP2IRIS_Pos)
#define	CCP_CCPRIS_CAP1IRIS_Pos		(9)
#define CCP_CCPRIS_CAP1IRIS_Msk		(0x1UL<<CCP_CCPRIS_CAP1IRIS_Pos)
#define	CCP_CCPRIS_CAP0IRIS_Pos		(8)
#define CCP_CCPRIS_CAP0IRIS_Msk		(0x1UL<<CCP_CCPRIS_CAP0IRIS_Pos)
#define	CCP_CCPRIS_PWMRIS5_Pos		(5)
#define CCP_CCPRIS_PWMRIS5_Msk		(0x1UL<<CCP_CCPRIS_PWMRIS5_Pos)
#define	CCP_CCPRIS_PWMRIS4_Pos		(4)
#define CCP_CCPRIS_PWMRIS4_Msk		(0x1UL<<CCP_CCPRIS_PWMRIS4_Pos)
#define	CCP_CCPRIS_PWMRIS1_Pos		(1)
#define CCP_CCPRIS_PWMRIS1_Msk		(0x1UL<<CCP_CCPRIS_PWMRIS1_Pos)
#define	CCP_CCPRIS_PWMRIS0_Pos		(0)
#define CCP_CCPRIS_PWMRIS0_Msk		(0x1UL<<CCP_CCPRIS_PWMRIS0_Pos)
/*------CCPMIS---------------------------------------------------------------*/
#define	CCP_CCPMIS_CAP3IMIS_Pos		(11)
#define CCP_CCPMIS_CAP3IMIS_Msk		(0x1UL<<CCP_CCPMIS_CAP3IMIS_Pos)
#define	CCP_CCPMIS_CAP2IMIS_Pos		(10)
#define CCP_CCPMIS_CAP2IMIS_Msk		(0x1UL<<CCP_CCPMIS_CAP2IMIS_Pos)
#define	CCP_CCPMIS_CAP1IMIS_Pos		(9)
#define CCP_CCPMIS_CAP1IMIS_Msk		(0x1UL<<CCP_CCPMIS_CAP1IMIS_Pos)
#define	CCP_CCPMIS_CAP0IMIS_Pos		(8)
#define CCP_CCPMIS_CAP0IMIS_Msk		(0x1UL<<CCP_CCPMIS_CAP0IMIS_Pos)
#define	CCP_CCPMIS_PWMMIS5_Pos		(5)
#define CCP_CCPMIS_PWMMIS5_Msk		(0x1UL<<CCP_CCPMIS_PWMMIS5_Pos)
#define	CCP_CCPMIS_PWMMIS4_Pos		(4)
#define CCP_CCPMIS_PWMMIS4_Msk		(0x1UL<<CCP_CCPMIS_PWMMIS4_Pos)
#define	CCP_CCPMIS_PWMMIS1_Pos		(1)
#define CCP_CCPMIS_PWMMIS1_Msk		(0x1UL<<CCP_CCPMIS_PWMMIS1_Pos)
#define	CCP_CCPMIS_PWMMIS0_Pos		(0)
#define CCP_CCPMIS_PWMMIS0_Msk		(0x1UL<<CCP_CCPMIS_PWMMIS0_Pos)

/*------CCPICLR-------------------------------------------------------------*/
#define	CCP_CCPICLR_CAP3ICLR_Pos	(11)
#define CCP_CCPICLR_CAP3ICLR_Msk	(0x1UL<<CCP_CCPICLR_CAP3ICLR_Pos)
#define	CCP_CCPICLR_CAP2ICLR_Pos	(10)
#define CCP_CCPICLR_CAP2ICLR_Msk	(0x1UL<<CCP_CCPICLR_CAP2ICLR_Pos)
#define	CCP_CCPICLR_CAP1ICLR_Pos	(9)
#define CCP_CCPICLR_CAP1ICLR_Msk	(0x1UL<<CCP_CCPICLR_CAP1ICLR_Pos)
#define	CCP_CCPICLR_CAP0ICLR_Pos	(8)
#define CCP_CCPICLR_CAP0ICLR_Msk	(0x1UL<<CCP_CCPICLR_CAP0ICLR_Pos)
#define	CCP_CCPICLR_PWMMICLR5_Pos	(5)
#define CCP_CCPICLR_PWMMICLR5_Msk	(0x1UL<<CCP_CCPICLR_PWMMICLR5_Pos)
#define	CCP_CCPICLR_PWMMICLR4_Pos	(4)
#define CCP_CCPICLR_PWMMICLR4_Msk	(0x1UL<<CCP_CCPICLR_PWMMICLR4_Pos)
#define	CCP_CCPICLR_PWMMICLR1_Pos	(1)
#define CCP_CCPICLR_PWMMICLR1_Msk	(0x1UL<<CCP_CCPICLR_PWMMICLR1_Pos)
#define	CCP_CCPICLR_PWMMICLR0_Pos	(0)
#define CCP_CCPICLR_PWMMICLR0_Msk	(0x1UL<<CCP_CCPICLR_PWMMICLR0_Pos)
/*------CCPRUN-------------------------------------------------------------*/
#define	CCP_CCPRUN_CCPRUN1_Pos		(1)
#define CCP_CCPRUN_CCPRUN1_Msk		(0x1UL<<CCP_CCPRUN_CCPRUN1_Pos)
#define	CCP_CCPRUN_CCPRUN0_Pos		(0)
#define CCP_CCPRUN_CCPRUN0_Msk		(0x1UL<<CCP_CCPRUN_CCPRUN0_Pos)
/*------CAPCON-------------------------------------------------------------*/
#define	CCP_CAPCON_CAPEN_Pos		(12)
#define CCP_CAPCON_CAPEN_Msk		(0x1UL<<CCP_CAPCON_CAPEN_Pos)
#define	CCP_CAPCON_CAP3RLEN_Pos		(11)
#define CCP_CAPCON_CAP3RLEN_Msk		(0x1UL<<CCP_CAPCON_CAP3RLEN_Pos)
#define	CCP_CAPCON_CAP2RLEN_Pos		(10)
#define CCP_CAPCON_CAP2RLEN_Msk		(0x1UL<<CCP_CAPCON_CAP2RLEN_Pos)
#define	CCP_CAPCON_CAP1RLEN_Pos		(9)
#define CCP_CAPCON_CAP1RLEN_Msk		(0x1UL<<CCP_CAPCON_CAP1RLEN_Pos)
#define	CCP_CAPCON_CAP0RLEN_Pos		(8)
#define CCP_CAPCON_CAP0RLEN_Msk		(0x1UL<<CCP_CAPCON_CAP0RLEN_Pos)
#define	CCP_CAPCON_CAP3ES_Pos		(5)
#define CCP_CAPCON_CAP3ES_Msk		(0x7UL<<CCP_CAPCON_CAP3ES_Pos)
#define	CCP_CAPCON_CAP2ES_Pos		(4)
#define CCP_CAPCON_CAP2ES_Msk		(0x3UL<<CCP_CAPCON_CAP2ES_Pos)
#define	CCP_CAPCON_CAP1ES_Pos		(2)
#define CCP_CAPCON_CAP1ES_Msk		(0x3UL<<CCP_CAPCON_CAP1ES_Pos)
#define	CCP_CAPCON_CAP0ES_Pos		(0)
#define CCP_CAPCON_CAP0ES_Msk		(0x3UL<<CCP_CAPCON_CAP0ES_Pos)
/*------CAPCHS-------------------------------------------------------------*/
#define	CCP_CAPCHS_ECAPS_Pos		(16)
#define CCP_CAPCHS_ECAPS_Msk		(0x1UL<<CCP_CAPCHS_ECAPS_Pos)
#define	CCP_CAPCHS_CAP3CHS_Pos		(12)
#define CCP_CAPCHS_CAP3CHS_Msk		(0xfUL<<CCP_CAPCHS_CAP3CHS_Pos)
#define	CCP_CAPCHS_CAP2CHS_Pos		(8)
#define CCP_CAPCHS_CAP2CHS_Msk		(0xfUL<<CCP_CAPCHS_CAP2CHS_Pos)
#define	CCP_CAPCHS_CAP1CHS_Pos		(4)
#define CCP_CAPCHS_CAP1CHS_Msk		(0xfUL<<CCP_CAPCHS_CAP1CHS_Pos)
#define	CCP_CAPCHS_CAP0CHS_Pos		(0)
#define CCP_CAPCHS_CAP0CHS_Msk		(0xfUL<<CCP_CAPCHS_CAP0CHS_Pos)
/*------CAP0DAT-------------------------------------------------------------*/
#define	CCP_CAP0DAT_CAP_Pos			(16)
#define CCP_CAP0DAT_CAP_Msk			(0xffffUL<<CCP_CAP0DAT_CAP_Pos)
#define	CCP_CAP0DAT_DAT_Pos			(0)
#define CCP_CAP0DAT_DAT_Msk			(0xffffUL<<CCP_CAP0DAT_DAT_Pos)
/*------CAP1DAT-------------------------------------------------------------*/
#define	CCP_CAP1DAT_CAP_Pos			(16)
#define CCP_CAP1DAT_CAP_Msk			(0xffffUL<<CCP_CAP1DAT_CAP_Pos)
#define	CCP_CAP1DAT_DAT_Pos			(0)
#define CCP_CAP1DAT_DAT_Msk			(0xffffUL<<CCP_CAP1DAT_DAT_Pos)
/*------CAP2DAT-------------------------------------------------------------*/
#define	CCP_CAP2DAT_CAP_Pos			(16)
#define CCP_CAP2DAT_CAP_Msk			(0xffffUL<<CCP_CAP2DAT_CAP_Pos)
#define	CCP_CAP2DAT_DAT_Pos			(0)
#define CCP_CAP2DAT_DAT_Msk			(0xffffUL<<CCP_CAP2DAT_DAT_Pos)
/*------CAP3DAT-------------------------------------------------------------*/
#define	CCP_CAP3DAT_CAP_Pos			(16)
#define CCP_CAP3DAT_CAP_Msk			(0xffffUL<<CCP_CAP3DAT_CAP_Pos)
#define	CCP_CAP3DAT_DAT_Pos			(0)
#define CCP_CAP3DAT_DAT_Msk			(0xffffUL<<CCP_CAP3DAT_DAT_Pos)

/*---------------------- EPWM  Manger Controller -------------------------*/
typedef struct
{					
	__IO uint32_t CLKPSC;
	__IO uint32_t CLKDIV;
	__IO uint32_t CON;
	__IO uint32_t CON2;
	__IO uint32_t CON3;
	__IO uint32_t PERIOD[6];
	__IO uint32_t CMPADT[6];	
	__I  uint32_t RESERVE0;	
	__IO uint32_t POEN;
	__I  uint32_t RESERVE2;	
	__IO uint32_t DTCTL;
	__I  uint32_t RESERVE3;	
	__I  uint32_t RESERVE4;	
	__I  uint32_t RESERVE5[2];
	__IO uint32_t IMSC;
	__I  uint32_t RIS;
	__I  uint32_t MIS;
	__O  uint32_t ICLR;
	__IO uint32_t IFA;
	__IO uint32_t LOCK;
} EPWM_T;
/*------CLKPSC--------------------------------------------------------------*/
#define	EPWM_CLKPSC_CLKPSC45_Pos		(16)
#define EPWM_CLKPSC_CLKPSC45_Msk		(0xffUL<<EPWM_CLKPSC_CLKPSC45_Pos)
#define	EPWM_CLKPSC_CLKPSC23_Pos		(8)
#define EPWM_CLKPSC_CLKPSC23_Msk		(0xffUL<<EPWM_CLKPSC_CLKPSC23_Pos)
#define	EPWM_CLKPSC_CLKPSC01_Pos		(0)
#define EPWM_CLKPSC_CLKPSC01_Msk		(0xffUL<<EPWM_CLKPSC_CLKPSC01_Pos)
/*------CLKDIV--------------------------------------------------------------*/
#define	EPWM_CLKDIV_CLKDIV5_Pos			(20)
#define EPWM_CLKDIV_CLKDIV5_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV5_Pos)
#define	EPWM_CLKDIV_CLKDIV4_Pos			(16)
#define EPWM_CLKDIV_CLKDIV4_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV4_Pos)
#define	EPWM_CLKDIV_CLKDIV3_Pos			(12)
#define EPWM_CLKDIV_CLKDIV3_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV3_Pos)
#define	EPWM_CLKDIV_CLKDIV2_Pos			(8)
#define EPWM_CLKDIV_CLKDIV2_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV2_Pos)
#define	EPWM_CLKDIV_CLKDIV1_Pos			(4)
#define EPWM_CLKDIV_CLKDIV1_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV1_Pos)
#define	EPWM_CLKDIV_CLKDIV0_Pos			(0)
#define EPWM_CLKDIV_CLKDIV0_Msk			(0x7UL<<EPWM_CLKDIV_CLKDIV0_Pos)
/*------CON--------------------------------------------------------------*/
#define	EPWM_CON_MODE_Pos				(24)
#define EPWM_CON_MODE_Msk				(0x3UL<<EPWM_CON_MODE_Pos)
#define	EPWM_CON_GROUNPEN_Pos			(23)
#define EPWM_CON_GROUNPEN_Msk			(0x1UL<<EPWM_CON_GROUNPEN_Pos)
#define	EPWM_CON_ASYMEN_Pos				(22)
#define EPWM_CON_ASYMEN_Msk				(0x1UL<<EPWM_CON_ASYMEN_Pos)
#define	EPWM_CON_CNTTYPE_Pos			(21)
#define EPWM_CON_CNTTYPE_Msk			(0x1UL<<EPWM_CON_CNTTYPE_Pos)
#define	EPWM_CON_HALT_Pos				(20)
#define EPWM_CON_HALT_Msk				(0x1UL<<EPWM_CON_HALT_Pos)
#define	EPWM_CON_ENDT45_Pos				(18)
#define EPWM_CON_ENDT45_Msk				(0x1UL<<EPWM_CON_ENDT45_Pos)
#define	EPWM_CON_ENDT23_Pos				(17)
#define EPWM_CON_ENDT23_Msk				(0x1UL<<EPWM_CON_ENDT23_Pos)
#define	EPWM_CON_ENDT01_Pos				(16)
#define EPWM_CON_ENDT01_Msk				(0x1UL<<EPWM_CON_ENDT01_Pos)
#define	EPWM_CON_PINV5_Pos				(13)
#define EPWM_CON_PINV5_Msk				(0x1UL<<EPWM_CON_PINV5_Pos)
#define	EPWM_CON_PINV4_Pos				(12)
#define EPWM_CON_PINV4_Msk				(0x1UL<<EPWM_CON_PINV4_Pos)
#define	EPWM_CON_PINV3_Pos				(11)
#define EPWM_CON_PINV3_Msk				(0x1UL<<EPWM_CON_PINV3_Pos)
#define	EPWM_CON_PINV2_Pos				(10)
#define EPWM_CON_PINV2_Msk				(0x1UL<<EPWM_CON_PINV2_Pos)
#define	EPWM_CON_PINV1_Pos				(9)
#define EPWM_CON_PINV1_Msk				(0x1UL<<EPWM_CON_PINV1_Pos)
#define	EPWM_CON_PINV0_Pos				(8)
#define EPWM_CON_PINV0_Msk				(0x1UL<<EPWM_CON_PINV0_Pos)
#define	EPWM_CON_CNTMODE5_Pos			(5)
#define EPWM_CON_CNTMODE5_Msk			(0x1UL<<EPWM_CON_CNTMODE5_Pos)
#define	EPWM_CON_CNTMODE4_Pos			(4)
#define EPWM_CON_CNTMODE4_Msk			(0x1UL<<EPWM_CON_CNTMODE4_Pos)
#define	EPWM_CON_CNTMODE3_Pos			(3)
#define EPWM_CON_CNTMODE3_Msk			(0x1UL<<EPWM_CON_CNTMODE3_Pos)
#define	EPWM_CON_CNTMODE2_Pos			(2)
#define EPWM_CON_CNTMODE2_Msk			(0x1UL<<EPWM_CON_CNTMODE2_Pos)
#define	EPWM_CON_CNTMODE1_Pos			(1)
#define EPWM_CON_CNTMODE1_Msk			(0x1UL<<EPWM_CON_CNTMODE1_Pos)
#define	EPWM_CON_CNTMODE0_Pos			(0)
#define EPWM_CON_CNTMODE0_Msk			(0x1UL<<EPWM_CON_CNTMODE0_Pos)
/*------CON2--------------------------------------------------------------*/
#define	EPWM_CON2_CNTEN5_Pos			(5)
#define EPWM_CON2_CNTEN5_Msk			(0x1UL<<EPWM_CON2_CNTEN5_Pos)
#define	EPWM_CON2_CNTEN4_Pos			(4)
#define EPWM_CON2_CNTEN4_Msk			(0x1UL<<EPWM_CON2_CNTEN4_Pos)
#define	EPWM_CON2_CNTEN3_Pos			(3)
#define EPWM_CON2_CNTEN3_Msk			(0x1UL<<EPWM_CON2_CNTEN3_Pos)
#define	EPWM_CON2_CNTEN2_Pos			(2)
#define EPWM_CON2_CNTEN2_Msk			(0x1UL<<EPWM_CON2_CNTEN2_Pos)
#define	EPWM_CON2_CNTEN1_Pos			(1)
#define EPWM_CON2_CNTEN1_Msk			(0x1UL<<EPWM_CON2_CNTEN1_Pos)
#define	EPWM_CON2_CNTEN0_Pos			(0)
#define EPWM_CON2_CNTEN0_Msk			(0x1UL<<EPWM_CON2_CNTEN0_Pos)
/*------CON3--------------------------------------------------------------*/
#define	EPWM_CON3_LOADTYP5_Pos			(26)
#define EPWM_CON3_LOADTYP5_Msk			(0x3UL<<EPWM_CON3_LOADTYP5_Pos)
#define	EPWM_CON3_LOADTYP4_Pos			(24)
#define EPWM_CON3_LOADTYP4_Msk			(0x3UL<<EPWM_CON3_LOADTYP4_Pos)
#define	EPWM_CON3_LOADTYP3_Pos			(22)
#define EPWM_CON3_LOADTYP3_Msk			(0x3UL<<EPWM_CON3_LOADTYP3_Pos)
#define	EPWM_CON3_LOADTYP2_Pos			(20)
#define EPWM_CON3_LOADTYP2_Msk			(0x3UL<<EPWM_CON3_LOADTYP2_Pos)
#define	EPWM_CON3_LOADTYP1_Pos			(18)
#define EPWM_CON3_LOADTYP1_Msk			(0x3UL<<EPWM_CON3_LOADTYP1_Pos)
#define	EPWM_CON3_LOADTYP0_Pos			(16)
#define EPWM_CON3_LOADTYP0_Msk			(0x3UL<<EPWM_CON3_LOADTYP0_Pos)
#define	EPWM_CON3_LOADEN5_Pos			(13)
#define EPWM_CON3_LOADEN5_Msk			(0x1UL<<EPWM_CON3_LOADEN5_Pos)
#define	EPWM_CON3_LOADEN4_Pos			(12)
#define EPWM_CON3_LOADEN4_Msk			(0x3UL<<EPWM_CON3_LOADEN4_Pos)
#define	EPWM_CON3_LOADEN3_Pos			(11)
#define EPWM_CON3_LOADEN3_Msk			(0x1UL<<EPWM_CON3_LOADEN3_Pos)
#define	EPWM_CON3_LOADEN2_Pos			(10)
#define EPWM_CON3_LOADEN2_Msk			(0x1UL<<EPWM_CON3_LOADEN2_Pos)
#define	EPWM_CON3_LOADEN1_Pos			(9)
#define EPWM_CON3_LOADEN1_Msk			(0x1UL<<EPWM_CON3_LOADEN1_Pos)
#define	EPWM_CON3_LOADEN0_Pos			(8)
#define EPWM_CON3_LOADEN0_Msk			(0x1UL<<EPWM_CON3_LOADEN0_Pos)
#define	EPWM_CON3_CNTCLR5_Pos			(5)
#define EPWM_CON3_CNTCLR5_Msk			(0x1UL<<EPWM_CON3_CNTCLR5_Pos)
#define	EPWM_CON3_CNTCLR4_Pos			(4)
#define EPWM_CON3_CNTCLR4_Msk			(0x1UL<<EPWM_CON3_CNTCLR4_Pos)
#define	EPWM_CON3_CNTCLR3_Pos			(3)
#define EPWM_CON3_CNTCLR3_Msk			(0x1UL<<EPWM_CON3_CNTCLR3_Pos)
#define	EPWM_CON3_CNTCLR2_Pos			(2)
#define EPWM_CON3_CNTCLR2_Msk			(0x1UL<<EPWM_CON3_CNTCLR2_Pos)
#define	EPWM_CON3_CNTCLR1_Pos			(1)
#define EPWM_CON3_CNTCLR1_Msk			(0x1UL<<EPWM_CON3_CNTCLR1_Pos)
#define	EPWM_CON3_CNTCLR0_Pos			(0)
#define EPWM_CON3_CNTCLR0_Msk			(0x1UL<<EPWM_CON3_CNTCLR0_Pos)

/*------POEN------------------------------------------------------------*/
#define	EPWM_POEN_POEN5_Pos				(5)
#define EPWM_POEN_POEN5_Msk				(0x1UL<<EPWM_POEN_POEN5_Pos)
#define	EPWM_POEN_POEN4_Pos				(4)
#define EPWM_POEN_POEN4_Msk				(0x1UL<<EPWM_POEN_POEN4_Pos)
#define	EPWM_POEN_POEN3_Pos				(3)
#define EPWM_POEN_POEN3_Msk				(0x1UL<<EPWM_POEN_POEN3_Pos)
#define	EPWM_POEN_POEN2_Pos				(2)
#define EPWM_POEN_POEN2_Msk				(0x1UL<<EPWM_POEN_POEN2_Pos)
#define	EPWM_POEN_POEN1_Pos				(1)
#define EPWM_POEN_POEN1_Msk				(0x1UL<<EPWM_POEN_POEN1_Pos)
#define	EPWM_POEN_POEN0_Pos				(0)
#define EPWM_POEN_POEN0_Msk				(0x1UL<<EPWM_POEN_POEN0_Pos)
/*------DTCTL---------------------------------------------------------*/
#define	EPWM_DTCTL_DTI45_Pos			(20)
#define EPWM_DTCTL_DTI45_Msk			(0x3ffUL<<EPWM_DTCTL_DTI45_Pos)
#define	EPWM_DTCTL_DTI23_Pos			(10)
#define EPWM_DTCTL_DTI23_Msk			(0x3ffUL<<EPWM_DTCTL_DTI23_Pos)
#define	EPWM_DTCTL_DTI01_Pos			(0)
#define EPWM_DTCTL_DTI01_Msk			(0x3ffUL<<EPWM_DTCTL_DTI01_Pos)

/*------IMSC---------------------------------------------------------*/
#define	EPWM_IMSC_ENBRKIF_Pos			(31)
#define EPWM_IMSC_ENBRKIF_Msk			(0x1UL<<EPWM_IMSC_ENBRKIF_Pos)
#define	EPWM_IMSC_ENHALLIF_Pos			(30)
#define EPWM_IMSC_ENHALLIF_Msk			(0x1UL<<EPWM_IMSC_ENHALLIF_Pos)
#define	EPWM_IMSC_ENDIFn_Pos			(24)
#define EPWM_IMSC_ENDIFn_Msk			(0x3fUL<<EPWM_IMSC_ENDIFn_Pos)
#define	EPWM_IMSC_ENUIFn_Pos			(16)
#define EPWM_IMSC_ENUIFn_Msk			(0x3fUL<<EPWM_IMSC_ENUIFn_Pos)
#define	EPWM_IMSC_ENDC1IF_Pos			(15)
#define EPWM_IMSC_ENDC1IF_Msk			(0x1UL<<EPWM_IMSC_ENDC1IF_Pos)
#define	EPWM_IMSC_ENDC0IF_Pos			(14)
#define EPWM_IMSC_ENDC0IF_Msk			(0x1UL<<EPWM_IMSC_ENDC0IF_Pos)
#define	EPWM_IMSC_ENPIFn_Pos			(8)
#define EPWM_IMSC_ENPIFn_Msk			(0x3fUL<<EPWM_IMSC_ENPIFn_Pos)
#define	EPWM_IMSC_ENZIFn_Pos			(0)
#define EPWM_IMSC_ENZIFn_Msk			(0x3fUL<<EPWM_IMSC_ENZIFn_Pos)
/*------IRS----------------------------------------------------------*/
#define	EPWM_RIS_BRKIF_Pos				(31)
#define EPWM_RIS_BRKIF_Msk				(0x1UL<<EPWM_RIS_BRKIF_Pos)
#define	EPWM_RIS_HALLIF_Pos				(30)
#define EPWM_RIS_HALLIF_Msk				(0x1UL<<EPWM_RIS_HALLIF_Pos)
#define	EPWM_RIS_DIFn_Pos				(24)
#define EPWM_RIS_DIFn_Msk				(0x3fUL<<EPWM_RIS_DIFn_Pos)	
#define	EPWM_RIS_UIFn_Pos				(16)
#define EPWM_RIS_UIFn_Msk				(0x3fUL<<EPWM_RIS_UIFn_Pos)	
#define	EPWM_RIS_DC1IF_Pos				(15)
#define EPWM_RIS_DC1IF_Msk				(0x1UL<<EPWM_RIS_DC1IF_Pos)	
#define	EPWM_RIS_DC0IF_Pos				(14)
#define EPWM_RIS_DC0IF_Msk				(0x1UL<<EPWM_RIS_DC0IF_Pos)	
#define	EPWM_RIS_PIFn_Pos				(8)
#define EPWM_RIS_PIFn_Msk				(0x3fUL<<EPWM_RIS_PIFn_Pos)	
#define	EPWM_RIS_ZIFn_Pos				(0)
#define EPWM_RIS_ZIFn_Msk				(0x3fUL<<EPWM_RIS_ZIFn_Pos)
/*------MIS----------------------------------------------------------*/
#define	EPWM_MIS_BRKIF_Pos				(31)
#define EPWM_MIS_BRKIF_Msk				(0x1UL<<EPWM_MIS_BRKIF_Pos)
#define	EPWM_MIS_HALLIF_Pos				(30)
#define EPWM_MIS_HALLIF_Msk				(0x1UL<<EPWM_MIS_HALLIF_Pos)
#define	EPWM_MIS_DIFn_Pos				(24)
#define EPWM_MIS_DIFn_Msk				(0x3fUL<<EPWM_MIS_DIFn_Pos)	
#define	EPWM_MIS_UIFn_Pos				(16)
#define EPWM_MIS_UIFn_Msk				(0x3fUL<<EPWM_MIS_UIFn_Pos)	
#define	EPWM_MIS_DC1IF_Pos				(15)
#define EPWM_MIS_DC1IF_Msk				(0x1UL<<EPWM_MIS_DC1IF_Pos)	
#define	EPWM_MIS_DC0IF_Pos				(14)
#define EPWM_MIS_DC0IF_Msk				(0x1UL<<EPWM_MIS_DC0IF_Pos)	
#define	EPWM_MIS_PIFn_Pos				(8)
#define EPWM_MIS_PIFn_Msk				(0x3fUL<<EPWM_MIS_PIFn_Pos)	
#define	EPWM_MIS_ZIFn_Pos				(0)
#define EPWM_MIS_ZIFn_Msk				(0x3fUL<<EPWM_MIS_ZIFn_Pos)
/*------ICLR----------------------------------------------------------*/
#define	EPWM_ICLR_BRKIF_Pos				(31)
#define EPWM_ICLR_BRKIF_Msk				(0x1UL<<EPWM_ICLR_BRKIF_Pos)
#define	EPWM_ICLR_HALLIF_Pos			(30)
#define EPWM_ICLR_HALLIF_Msk			(0x1UL<<EPWM_ICLR_HALLIF_Pos)
#define	EPWM_ICLR_DIFn_Pos				(24)
#define EPWM_ICLR_DIFn_Msk				(0x3fUL<<EPWM_ICLR_DIFn_Pos)	
#define	EPWM_ICLR_UIFn_Pos				(16)
#define EPWM_ICLR_UIFn_Msk				(0x3fUL<<EPWM_ICLR_UIFn_Pos)	
#define	EPWM_ICLR_DC1IF_Pos				(15)
#define EPWM_ICLR_DC1IF_Msk				(0x1UL<<EPWM_ICLR_DC1IF_Pos)	
#define	EPWM_ICLR_DC0IF_Pos				(14)
#define EPWM_ICLR_DC0IF_Msk				(0x1UL<<EPWM_ICLR_DC0IF_Pos)	
#define	EPWM_ICLR_PIFn_Pos				(8)
#define EPWM_ICLR_PIFn_Msk				(0x3fUL<<EPWM_ICLR_PIFn_Pos)	
#define	EPWM_ICLR_ZIFn_Pos				(0)
#define EPWM_ICLR_ZIFn_Msk				(0x3fUL<<EPWM_ICLR_ZIFn_Pos)
/*------IFA----------------------------------------------------------*/
#define	EPWM_IFA_ZIFCMP_Pos				(4)
#define EPWM_IFA_ZIFCMP_Msk				(0xfUL<<EPWM_IFA_ZIFCMP_Pos)
#define	EPWM_IFA_ZIFAEN_Pos				(0)
#define EPWM_IFA_ZIFAEN_Msk				(0x1UL<<EPWM_IFA_ZIFAEN_Pos)
/*---------------------- UART  Manger Controller -------------------------*/
typedef struct
{					
	__I  uint32_t RBR;
	__O  uint32_t THR;
	__IO uint32_t DLR;
	__IO uint32_t IER;
	__I  uint32_t IIR;
	__O  uint32_t FCR;
	__IO uint32_t LCR;
	__IO uint32_t MCR;
	__I  uint32_t LSR;
	__I  uint32_t MSR;
	__IO uint32_t SCR;
	__IO uint32_t EFR;
	__IO uint32_t XON1;
	__IO uint32_t XON2;
	__IO uint32_t XOFF1;
	__IO uint32_t XOFF2;
} UART_T;

/*------LCR----------------------------------------------------------*/
#define	UART_LCR_BCON_Pos				(6)
#define UART_LCR_BCON_Msk				(0x1UL<<UART_LCR_BCON_Pos)
#define	UART_LCR_PSEL_Pos				(4)
#define UART_LCR_PSEL_Msk				(0x3UL<<UART_LCR_PSEL_Pos)
#define	UART_LCR_PEN_Pos				(3)
#define UART_LCR_PEN_Msk				(0x1UL<<UART_LCR_PEN_Pos)
#define	UART_LCR_SBS_Pos				(2)
#define UART_LCR_SBS_Msk				(0x1UL<<UART_LCR_SBS_Pos)
#define	UART_LCR_WLS_Pos				(0)
#define UART_LCR_WLS_Msk				(0x3UL<<UART_LCR_WLS_Pos)

/*------LSR----------------------------------------------------------*/
#define	UART_LSR_RXFE_Pos				(7)
#define UART_LSR_RXFE_Msk				(0x1UL<<UART_LSR_RXFE_Pos)
#define	UART_LSR_TEMT_Pos				(6)
#define UART_LSR_TEMT_Msk				(0x1UL<<UART_LSR_TEMT_Pos)
#define	UART_LSR_THRE_Pos				(5)
#define UART_LSR_THRE_Msk				(0x1UL<<UART_LSR_THRE_Pos)
#define	UART_LSR_BI_Pos					(4)
#define UART_LSR_BI_Msk					(0x1UL<<UART_LSR_BI_Pos)
#define	UART_LSR_FE_Pos					(3)
#define UART_LSR_FE_Msk					(0x1UL<<UART_LSR_FE_Pos)
#define	UART_LSR_PE_Pos					(2)
#define UART_LSR_PE_Msk					(0x1UL<<UART_LSR_PE_Pos)
#define	UART_LSR_OE_Pos					(1)
#define UART_LSR_OE_Msk					(0x1UL<<UART_LSR_OE_Pos)
#define	UART_LSR_RDR_Pos				(0)
#define UART_LSR_RDR_Msk				(0x1UL<<UART_LSR_RDR_Pos)

/*------EFR----------------------------------------------------------*/
#define	UART_EFR_AUTOCTS_Pos			(7)
#define UART_EFR_AUTOCTS_Msk			(0x1UL<<UART_EFR_AUTOCTS_Pos)
#define	UART_EFR_AUTORTS_Pos			(6)
#define UART_EFR_AUTORTS_Msk			(0x1UL<<UART_EFR_AUTORTS_Pos)
#define	UART_EFR_AUTOIEN_Pos			(4)
#define UART_EFR_AUTOIEN_Msk			(0x1UL<<UART_EFR_AUTOIEN_Pos)
#define	UART_EFR_TXSWFC_Pos				(2)
#define UART_EFR_TXSWFC_Msk				(0x3UL<<UART_EFR_TXSWFC_Pos)
#define	UART_EFR_RXSWFC_Pos				(0)
#define UART_EFR_RXSWFC_Msk				(0x3UL<<UART_EFR_RXSWFC_Pos)
/*------MSR----------------------------------------------------------*/
#define	UART_MSR_CTS_Pos				(4)
#define UART_MSR_CTS_Msk				(0x1UL<<UART_MSR_CTS_Pos)
#define	UART_MSR_DCTS_Pos				(0)
#define UART_MSR_DCTS_Msk				(0x1UL<<UART_MSR_DCTS_Pos)
/*------MCR----------------------------------------------------------*/
#define	UART_MCR_XOFFS_Pos				(7)
#define UART_MCR_XOFFS_Msk				(0x1UL<<UART_MCR_XOFFS_Pos)
#define	UART_MCR_IREN_Pos				(6)
#define UART_MCR_IREN_Msk				(0x1UL<<UART_MCR_IREN_Pos)
#define	UART_MCR_MLBM_Pos				(4)
#define UART_MCR_MLBM_Msk				(0x1UL<<UART_MCR_MLBM_Pos)
#define	UART_MCR_RTS_Pos				(1)
#define UART_MCR_RTS_Msk				(0x1UL<<UART_MCR_RTS_Pos)
/*------FCR----------------------------------------------------------*/
#define	UART_FCR_RXTL_Pos				(6)
#define UART_FCR_RXTL_Msk				(0x3UL<<UART_FCR_RXTL_Pos)
#define	UART_FCR_TXTL_Pos				(4)
#define UART_FCR_TXTL_Msk				(0x3UL<<UART_FCR_TXTL_Pos)
#define	UART_FCR_TXFIFORST_Pos			(2)
#define UART_FCR_TXFIFORST_Msk			(0x1UL<<UART_FCR_TXFIFORST_Pos)
#define	UART_FCR_RXFIFORST_Pos			(1)
#define UART_FCR_RXFIFORST_Msk			(0x1UL<<UART_FCR_RXFIFORST_Pos)
#define	UART_FCR_FIFOEN_Pos				(0)
#define UART_FCR_FIFOEN_Msk				(0x1UL<<UART_FCR_FIFOEN_Pos)
/*------IIR----------------------------------------------------------*/
#define	UART_IIR_INTHFC_Pos				(5)
#define UART_IIR_INTHFC_Msk				(0x1UL<<UART_IIR_INTHFC_Pos)
#define	UART_IIR_INTSFC_Pos				(4)
#define UART_IIR_INTSFC_Msk				(0x1UL<<UART_IIR_INTSFC_Pos)
#define	UART_IIR_INTID_Pos				(1)
#define UART_IIR_INTID_Msk				(0x3UL<<UART_IIR_INTID_Pos)
#define	UART_IIR_INTSTATUS_Pos			(0)
#define UART_IIR_INTSTATUS_Msk			(0x3UL<<UART_IIR_INTSTATUS_Pos)

/*------IER----------------------------------------------------------*/
#define	UART_IER_CTSIE_Pos				(7)
#define UART_IER_CTSIE_Msk				(0x1UL<<UART_IER_CTSIE_Pos)
#define	UART_IER_RTSIE_Pos				(6)
#define UART_IER_RTSIE_Msk				(0x1UL<<UART_IER_RTSIE_Pos)
#define	UART_IER_XOFIE_Pos				(5)
#define UART_IER_XOFIE_Msk				(0x1UL<<UART_IER_XOFIE_Pos)
#define	UART_IER_MDSIE_Pos				(3)
#define UART_IER_MDSIE_Msk				(0x1UL<<UART_IER_MDSIE_Pos)
#define	UART_IER_RLSIE_Pos				(2)
#define UART_IER_RLSIE_Msk				(0x1UL<<UART_IER_RLSIE_Pos)
#define	UART_IER_THREIE_Pos				(1)
#define UART_IER_THREIE_Msk				(0x1UL<<UART_IER_THREIE_Pos)
#define	UART_IER_RBRIE_Pos				(0)
#define UART_IER_RBRIE_Msk				(0x1UL<<UART_IER_RBRIE_Pos)



/*---------------------- I2C  Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t CONSET;
	__IO  uint32_t CONCLR;
	__IO  uint32_t STAT;
	__IO  uint32_t DAT;
	__IO  uint32_t CLK;
	__IO  uint32_t ADR0;
	__IO  uint32_t ADM0;
	__IO  uint32_t XADR0;
	__IO  uint32_t XADM0;
	__IO  uint32_t RST;
	__IO  uint32_t ADR1;
	__IO  uint32_t ADM1;
	__IO  uint32_t ADR2;
	__IO  uint32_t ADM2;
	__IO  uint32_t ADR3;
	__IO  uint32_t ADM3;
} I2C_T;

/*------CONSET---------------------------------------------------------------*/
#define	I2C_CONSSET_GCF_Pos				(8)
#define I2C_CONSSET_GCF_Msk				(0x1UL<<I2C_CONSSET_GCF_Pos)
#define	I2C_CONSSET_I2CIE_Pos			(7)
#define I2C_CONSSET_I2CIE_Msk			(0x1UL<<I2C_CONSSET_I2CIE_Pos)
#define	I2C_CONSSET_I2CEN_Pos			(6)
#define I2C_CONSSET_I2CEN_Msk			(0x1UL<<I2C_CONSSET_I2CEN_Pos)
#define	I2C_CONSSET_STA_Pos				(5)
#define I2C_CONSSET_STA_Msk				(0x1UL<<I2C_CONSSET_STA_Pos)
#define	I2C_CONSSET_STO_Pos				(4)
#define I2C_CONSSET_STO_Msk				(0x1UL<<I2C_CONSSET_STO_Pos)
#define	I2C_CONSSET_SI_Pos				(3)
#define I2C_CONSSET_SI_Msk				(0x1UL<<I2C_CONSSET_SI_Pos)
#define	I2C_CONSSET_AA_Pos				(2)
#define I2C_CONSSET_AA_Msk				(0x1UL<<I2C_CONSSET_AA_Pos)
#define	I2C_CONSSET_XADRF_Pos			(1)
#define I2C_CONSSET_XADRF_Msk			(0x1UL<<I2C_CONSSET_XADRF_Pos)
#define	I2C_CONSSET_ADRF_Pos			(0)
#define I2C_CONSSET_ADRF_Msk			(0x1UL<<I2C_CONSSET_ADRF_Pos)
/*------CONCLR---------------------------------------------------------------*/
#define	I2C_CONSCLR_I2CIEC_Pos			(7)
#define I2C_CONSCLR_I2CIEC_Msk			(0x1UL<<I2C_CONSCLR_I2CIEC_Pos)
#define	I2C_CONSCLR_I2CENC_Pos			(6)
#define I2C_CONSCLR_I2CEMC_Msk			(0x1UL<<I2C_CONSCLR_I2CENC_Pos)
#define	I2C_CONSCLR_STAC_Pos			(5)
#define I2C_CONSCLR_STAC_Msk			(0x1UL<<I2C_CONSCLR_STAC_Pos)
#define	I2C_CONSCLR_SIC_Pos				(3)
#define I2C_CONSCLR_SIC_Msk				(0x1UL<<I2C_CONSCLR_SIC_Pos)
#define	I2C_CONSCLR_AAC_Pos				(2)
#define I2C_CONSCLR_AAC_Msk				(0x1UL<<I2C_CONSCLR_AAC_Pos)
/*------STAT---------------------------------------------------------------*/
#define	I2C_STAT_STATUS_Pos				(2)
#define I2C_STAT_STATUS_Msk				(0x1FUL<<I2C_STAT_STATUS_Pos)





/*---------------------- SPP/SPI  Manger Controller ----------------------*/
typedef struct
{					
	__IO  uint32_t CON;
	__I   uint32_t STAT;
	__IO  uint32_t DAT;
	__IO  uint32_t CLK;
	__IO  uint32_t IMSC;
	__I   uint32_t RIS;
	__I   uint32_t MIS;
	__O   uint32_t ICLR;
	__I  uint32_t RESERVE[2];	
	__IO  uint32_t CSCR;
} SSP_T;

/*------CON---------------------------------------------------------------*/
#define	SSP_CON_LBM_Pos				(11)
#define SSP_CON_LBM_Msk				(0x1UL<<SSP_CON_LBM_Pos)
#define	SSP_CON_SSPEN_Pos			(10)
#define SSP_CON_SSPEN_Msk			(0x1UL<<SSP_CON_SSPEN_Pos)
#define	SSP_CON_MS_Pos				(9)
#define SSP_CON_MS_Msk				(0x1UL<<SSP_CON_MS_Pos)
#define	SSP_CON_SOD_Pos				(8)
#define SSP_CON_SOD_Msk				(0x1UL<<SSP_CON_SOD_Pos)
#define	SSP_CON_CPH_Pos				(7)
#define SSP_CON_CPH_Msk				(0x1UL<<SSP_CON_CPH_Pos)
#define	SSP_CON_CPO_Pos				(6)
#define SSP_CON_CPO_Msk				(0x1UL<<SSP_CON_CPO_Pos)
#define	SSP_CON_FRF_Pos				(4)
#define SSP_CON_FRF_Msk				(0x3UL<<SSP_CON_FRF_Pos)
#define	SSP_CON_DSS_Pos				(0)
#define SSP_CON_DSS_Msk				(0xFUL<<SSP_CON_DSS_Pos)
/*------STAT---------------------------------------------------------------*/
#define	SSP_STAT_BSY_Pos			(4)
#define SSP_STAT_BSY_Msk			(0x1UL<<SSP_STAT_BSY_Pos)
#define	SSP_STAT_RFF_Pos			(3)
#define SSP_STAT_RFF_Msk			(0x1UL<<SSP_STAT_RFF_Pos)
#define	SSP_STAT_RNE_Pos			(2)
#define SSP_STAT_RNE_Msk			(0x1UL<<SSP_STAT_RNE_Pos)
#define	SSP_STAT_TNF_Pos			(1)
#define SSP_STAT_TNF_Msk			(0x1UL<<SSP_STAT_TNF_Pos)
#define	SSP_STAT_TFE_Pos			(0)
#define SSP_STAT_TFE_Msk			(0x1UL<<SSP_STAT_TFE_Pos)
/*------CSCR---------------------------------------------------------------*/
#define	SSP_CSCR_SPH_Pos			(4)
#define SSP_CSCR_SPH_Msk			(0x1UL<<SSP_CSCR_SPH_Pos)
#define	SSP_CSCR_SWCS_Pos			(3)
#define SSP_CSCR_SWCS_Msk			(0x1UL<<SSP_CSCR_SWCS_Pos)
#define	SSP_CSCR_SWSEL_Pos			(2)
#define SSP_CSCR_SWSEL_Msk			(0x1UL<<SSP_CSCR_SWSEL_Pos)


/*---------------------- ADC1  Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t CON;
	__IO  uint32_t CON2;
	__IO  uint32_t HWTG;
	__I   uint32_t RESERVE0;
	__IO  uint32_t SCAN;
	__IO  uint32_t CMP0;
	__I   uint32_t RESERVE1;	
	__IO  uint32_t IMSC;
	__I   uint32_t RIS;
	__I   uint32_t MIS;
	__O   uint32_t ICLR;
	__IO  uint32_t LOCK;
	__I   uint32_t RESERVE2;
	__I   uint32_t RESERVE3;
	__I   uint32_t RESERVE4;
	__I   uint32_t RESERVE5[17];
	__I   uint32_t DATA[31];
} ADC1_T;

/*------CON----------------------------------------------------------------*/
#define	ADC1_CON_ADCRST_Pos				(31)
#define ADC1_CON_ADCRST_Msk				(0x1UL<<ADC1_CON_ADCRST_Pos)
#define	ADC1_CON_ADCCONVER_Pos			(25)
#define ADC1_CON_ADCCONVER_Msk			(0x1UL<<ADC1_CON_ADCCONVER_Pos)
#define	ADC1_CON_ADCCALERR_Pos			(24)
#define ADC1_CON_ADCCALERR_Msk			(0x1UL<<ADC1_CON_ADCCALERR_Pos)
#define	ADC1_CON_ADCCONVERRCLR_Pos		(21)
#define ADC1_CON_ADCCONVERRCLR_Msk		(0x1UL<<ADC1_CON_ADCCONVERRCLR_Pos)
#define	ADC1_CON_ADCCALERRCLR_Pos		(20)
#define ADC1_CON_ADCCALERRCLR_Msk		(0x1UL<<ADC1_CON_ADCCALERRCLR_Pos)
#define	ADC1_CON_ADCICHS_Pos			(16)
#define ADC1_CON_ADCICHS_Msk			(0x7UL<<ADC1_CON_ADCICHS_Pos)
#define	ADC1_CON_ADCSS_Pos				(14)
#define ADC1_CON_ADCSS_Msk				(0x1UL<<ADC1_CON_ADCSS_Pos)
#define	ADC1_CON_ADCSHT_Pos				(12)
#define ADC1_CON_ADCSHT_Msk				(0x3UL<<ADC1_CON_ADCSHT_Pos)
#define	ADC1_CON_ADCEN_Pos				(4)
#define ADC1_CON_ADCEN_Msk				(0x1UL<<ADC1_CON_ADCEN_Pos)
#define	ADC1_CON_ADCMS_Pos				(3)
#define ADC1_CON_ADCMS_Msk				(0x1UL<<ADC1_CON_ADCMS_Pos)
#define	ADC1_CON_ADCDIV_Pos				(0)
#define ADC1_CON_ADCDIV_Msk				(0x7UL<<ADC1_CON_ADCMS_Pos)
/*------CON2----------------------------------------------------------------*/
#define	ADC1_CON2_ADCST_Pos				(7)
#define ADC1_CON2_ADCST_Msk				(0x1UL<<ADC1_CON2_ADCST_Pos)
#define	ADC1_CON2_ADCCALCONV_Pos		(1)
#define ADC1_CON2_ADCCALCONV_Msk		(0x1UL<<ADC1_CON2_ADCCALCONV_Pos)
#define	ADC1_CON2_ADCCALEN_Pos			(0)
#define ADC1_CON2_ADCCALEN_Msk			(0x1UL<<ADC1_CON2_ADCCALEN_Pos)
/*------HWTG----------------------------------------------------------------*/
#define	ADC1_HWTG_ADCEXTEN_Pos			(17)
#define ADC1_HWTG_ADCEXTEN_Msk			(0x1UL<<ADC1_HWTG_ADCEXTEN_Pos)
#define	ADC1_HWTG_ADCEXTES_Pos			(16)
#define ADC1_HWTG_ADCEXTES_Msk			(0x1UL<<ADC1_HWTG_ADCEXTES_Pos)

/*------CMP0----------------------------------------------------------------*/
#define	ADC1_CMP0_ADCCMP0EN_Pos			(31)
#define ADC1_CMP0_ADCCMP0EN_Msk			(0x1UL<<ADC1_CMP0_ADCCMP0EN_Pos)
#define	ADC1_CMP0_ADCCMP0O_Pos			(30)
#define ADC1_CMP0_ADCCMP0O_Msk			(0x1UL<<ADC1_CMP0_ADCCMP0O_Pos)
#define	ADC1_CMP0_ADCCMP0COND_Pos		(28)
#define ADC1_CMP0_ADCCMP0COND_Msk		(0x1UL<<ADC1_CMP0_ADCCMP0COND_Pos)
#define	ADC1_CMP0_ADCCMP0MCNT_Pos		(24)
#define ADC1_CMP0_ADCCMP0MCNT_Msk		(0xFUL<<ADC1_CMP0_ADCCMP0MCNT_Pos)
#define	ADC1_CMP0_ADCCMP0CHS_Pos		(16)
#define ADC1_CMP0_ADCCMP0CHS_Msk		(0x1FUL<<ADC1_CMP0_ADCCMP0CHS_Pos)
#define	ADC1_CMP0_ADCCMP0DATA_Pos		(0)
#define ADC1_CMP0_ADCCMP0DATA_Msk		(0xFFFUL<<ADC1_CMP0_ADCCMP0CHS_Pos)

/*------IMSC----------------------------------------------------------------*/
#define	ADC1_IMSC_IMSC31_Pos			(31)
#define ADC1_IMSC_IMSC31_Msk			(0x1UL<<ADC1_IMSC_IMSC31_Pos)
/*------RIS-----------------------------------------------------------------*/
#define	ADC1_RIS_RIS31_Pos				(31)
#define ADC1_RIS_RIS31_Msk				(0x1UL<<ADC1_RIS_RIS31_Pos)
/*------MIS-----------------------------------------------------------------*/
#define	ADC1_MIS_MIS31_Pos				(31)
#define ADC1_MIS_MIS31_Msk				(0x1UL<<ADC1_MIS_MIS31_Pos)
/*------ICLR----------------------------------------------------------------*/
#define	ADC1_ICLR_ICLR31_Pos			(31)
#define ADC1_ICLR_ICLR31_Msk			(0x1UL<<ADC1_ICLR_ICLR31_Pos)



/*---------------------- OPA  Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t CON0;
	__IO  uint32_t CON1;
	__IO  uint32_t ADJE;
} OPA_T;
/*------CON0----------------------------------------------------------------*/
#define	OPA_CON0_EN_Pos					(7)
#define OPA_CON0_EN_Msk					(0x1UL<<OPA_CON0_EN_Pos)
#define	OPA_CON0_COFM_Pos				(6)
#define OPA_CON0_COFM_Msk				(0x1UL<<OPA_CON0_COFM_Pos)
#define	OPA_CON0_FIL_Pos				(5)
#define OPA_CON0_FIL_Msk				(0x1UL<<OPA_CON0_FIL_Pos)
#define	OPA_CON0_OS_Pos					(4)
#define OPA_CON0_OS_Msk					(0x1UL<<OPA_CON0_OS_Pos)
#define	OPA_CON0_NS_Pos					(2)
#define OPA_CON0_NS_Msk					(0x3UL<<OPA_CON0_NS_Pos)
#define	OPA_CON0_PS_Pos					(0)
#define OPA_CON0_PS_Msk					(0x3UL<<OPA_CON0_PS_Pos)
/*------CON1----------------------------------------------------------------*/
#define	OPA_CON1_OUT_Pos				(7)
#define OPA_CON1_OUT_Msk				(0x1UL<<OPA_CON1_OUT_Pos)
#define	OPA_CON1_CRS_Pos				(6)
#define OPA_CON1_CRS_Msk				(0x1UL<<OPA_CON1_CRS_Pos)
#define	OPA_CON1_ADJ_Pos				(0)
#define OPA_CON1_ADJ_Msk				(0x1FUL<<OPA_CON1_ADJ_Pos)

/*---------------------- PGA  Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t CON0;
} PGA_T;
/*------PGA----------------------------------------------------------------*/
#define	PGA_CON0_EN_Pos					(15)
#define PGA_CON0_EN_Msk					(0x1UL<<PGA_CON0_EN_Pos)
#define	PGA_CON0_GS_Pos					(12)
#define PGA_CON0_GS_Msk					(0x7UL<<PGA_CON0_GS_Pos)
#define	PGA_CON0_RGS_Pos				(11)
#define PGA_CON0_RGS_Msk				(0x1UL<<PGA_CON0_RGS_Pos)
#define	PGA_CON0_OS_Pos					(8)
#define PGA_CON0_OS_Msk					(0x3UL<<PGA_CON0_OS_Pos)
#define	PGA_CON0_PS_Pos					(4)
#define PGA_CON0_PS_Msk					(0x3UL<<PGA_CON0_PS_Pos)
/*---------------------- ACMP Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t C0CON0;
	__IO  uint32_t C0CON1;
	__IO  uint32_t C0CON2;
	__IO  uint32_t C0ADJE;
	__IO  uint32_t C1CON0;
	__IO  uint32_t C1CON1;
	__IO  uint32_t C1CON2;
	__IO  uint32_t C1ADJE;
	__IO  uint32_t CVRCON;
	__IO  uint32_t CEVCON;
	__IO  uint32_t IMSC;
	__I   uint32_t RIS;
	__I   uint32_t MIS;
	__O   uint32_t ICLR;
	__IO  uint32_t LOCK;
} ACMP_T;

/*------C0CON0----------------------------------------------------------------*/
#define	ACMP_C0CON0_EN_Pos					(15)
#define ACMP_C0CON0_EN_Msk					(0x1UL<<ACMP_C0CON0_EN_Pos)
#define	ACMP_C0CON0_COFM_Pos				(14)
#define ACMP_C0CON0_COFM_Msk				(0x1UL<<ACMP_C0CON0_COFM_Pos)
#define	ACMP_C0CON0_N2GND_Pos				(13)
#define ACMP_C0CON0_N2GND_Msk				(0x1UL<<ACMP_C0CON0_N2GND_Pos)
#define	ACMP_C0CON0_PS_Pos					(4)
#define ACMP_C0CON0_PS_Msk					(0x7UL<<ACMP_C0CON0_PS_Pos)
#define	ACMP_C0CON0_NS_Pos					(0)
#define ACMP_C0CON0_NS_Msk					(0xFUL<<ACMP_C0CON0_NS_Pos)
/*------C0CON1----------------------------------------------------------------*/
#define	ACMP_C0CON1_OUT_Pos					(9)
#define ACMP_C0CON1_OUT_Msk					(0x1UL<<ACMP_C0CON1_OUT_Pos)
#define	ACMP_C0CON1_CRS_Pos					(8)
#define ACMP_C0CON1_CRS_Msk					(0x1UL<<ACMP_C0CON1_CRS_Pos)
#define	ACMP_C0CON1_ADJ_Pos					(0)
#define ACMP_C0CON1_ADJ_Msk					(0x1FUL<<ACMP_C0CON1_ADJ_Pos)
/*------C0CON2----------------------------------------------------------------*/
#define	ACMP_C0CON2_HYSLS_Pos				(12)
#define ACMP_C0CON2_HYSLS_Msk				(0x1UL<<ACMP_C0CON2_HYSLS_Pos)
#define	ACMP_C0CON2_HYSVS_Pos				(10)
#define ACMP_C0CON2_HYSVS_Msk				(0x3UL<<ACMP_C0CON2_HYSVS_Pos)
#define	ACMP_C0CON2_POS_Pos					(9)
#define ACMP_C0CON2_POS_Msk					(0x1UL<<ACMP_C0CON2_POS_Pos)
#define	ACMP_C0CON2_FE_Pos					(8)
#define ACMP_C0CON2_FE_Msk					(0x1UL<<ACMP_C0CON2_FE_Pos)
#define	ACMP_C0CON2_FS_Pos					(0)
#define ACMP_C0CON2_FS_Msk					(0xFUL<<ACMP_C0CON2_FS_Pos)

/*------C1CON0----------------------------------------------------------------*/
#define	ACMP_C1CON0_EN_Pos					(15)
#define ACMP_C1CON0_EN_Msk					(0x1UL<<ACMP_C1CON0_EN_Pos)
#define	ACMP_C1CON0_COFM_Pos				(14)
#define ACMP_C1CON0_COFM_Msk				(0x1UL<<ACMP_C1CON0_COFM_Pos)
#define	ACMP_C1CON0_N2GND_Pos				(13)
#define ACMP_C1CON0_N2GND_Msk				(0x1UL<<ACMP_C1CON0_N2GND_Pos)
#define	ACMP_C1CON0_PS_Pos					(4)
#define ACMP_C1CON0_PS_Msk					(0x7UL<<ACMP_C1CON0_PS_Pos)
#define	ACMP_C1CON0_NS_Pos					(0)
#define ACMP_C1CON0_NS_Msk					(0xFUL<<ACMP_C1CON0_NS_Pos)
/*------C1CON1----------------------------------------------------------------*/
#define	ACMP_C1CON1_OUT_Pos					(9)
#define ACMP_C1CON1_OUT_Msk					(0x1UL<<ACMP_C1CON1_OUT_Pos)
#define	ACMP_C1CON1_CRS_Pos					(8)
#define ACMP_C1CON1_CRS_Msk					(0x1UL<<ACMP_C1CON1_CRS_Pos)
#define	ACMP_C1CON1_ADJ_Pos					(0)
#define ACMP_C1CON1_ADJ_Msk					(0x1FUL<<ACMP_C1CON1_ADJ_Pos)
/*------C1CON2----------------------------------------------------------------*/
#define	ACMP_C1CON2_HYSLS_Pos				(12)
#define ACMP_C1CON2_HYSLS_Msk				(0x1UL<<ACMP_C1CON2_HYSLS_Pos)
#define	ACMP_C1CON2_HYSVS_Pos				(10)
#define ACMP_C1CON2_HYSVS_Msk				(0x3UL<<ACMP_C1CON2_HYSVS_Pos)
#define	ACMP_C1CON2_POS_Pos					(9)
#define ACMP_C1CON2_POS_Msk					(0x1UL<<ACMP_C1CON2_POS_Pos)
#define	ACMP_C1CON2_FE_Pos					(8)
#define ACMP_C1CON2_FE_Msk					(0x1UL<<ACMP_C1CON2_FE_Pos)
#define	ACMP_C1CON2_FS_Pos					(0)
#define ACMP_C1CON2_FS_Msk					(0xFUL<<ACMP_C1CON2_FS_Pos)

/*------CVRCON----------------------------------------------------------------*/
#define	ACMP_CVRCON_CSVR_Pos				(4)
#define ACMP_CVRCON_CSVR_Msk				(0x3UL<<ACMP_CVRCON_CSVR_Pos)
#define	ACMP_CVRCON_CVS_Pos					(0)
#define ACMP_CVRCON_CVS_Msk					(0xFUL<<ACMP_CVRCON_CVS_Pos)

/*------CEVCON----------------------------------------------------------------*/
#define	ACMP_CEVCON_EVE1_Pos				(5)
#define ACMP_CEVCON_EVE1_Msk				(0x1UL<<ACMP_CEVCON_EVE1_Pos)
#define	ACMP_CEVCON_EVE0_Pos				(4)
#define ACMP_CEVCON_EVE0_Msk				(0x1UL<<ACMP_CEVCON_EVE0_Pos)
#define	ACMP_CEVCON_EVS1_Pos				(2)
#define ACMP_CEVCON_EVS1_Msk				(0x3UL<<ACMP_CEVCON_EVS1_Pos)
#define	ACMP_CEVCON_EVS0_Pos				(0)
#define ACMP_CEVCON_EVS0_Msk				(0x3UL<<ACMP_CEVCON_EVS0_Pos)
/*------IMSC------------------------------------------------------------------*/
#define	ACMP_IMSC_C1IF_Pos					(1)
#define ACMP_IMSC_C1IF_Msk					(0x1UL<<ACMP_IMSC_C1IF_Pos)
#define	ACMP_IMSC_C0IF_Pos					(0)
#define ACMP_IMSC_C0IF_Msk					(0x1UL<<ACMP_IMSC_C0IF_Pos)
/*------RIS------------------------------------------------------------------*/
#define	ACMP_RIS_C1IF_Pos					(1)
#define ACMP_RIS_C1IF_Msk					(0x1UL<<ACMP_RIS_C1IF_Pos)
#define	ACMP_RIS_C0IF_Pos					(0)
#define ACMP_RIS_C0IF_Msk					(0x1UL<<ACMP_RIS_C0IF_Pos)
/*------MIS------------------------------------------------------------------*/
#define	ACMP_MIS_C1IF_Pos					(1)
#define ACMP_MIS_C1IF_Msk					(0x1UL<<ACMP_MIS_C1IF_Pos)
#define	ACMP_MIS_C0IF_Pos					(0)
#define ACMP_MIS_C0IF_Msk					(0x1UL<<ACMP_MIS_C0IF_Pos)
/*------ICLR------------------------------------------------------------------*/
#define	ACMP_ICLR_C1IF_Pos					(1)
#define ACMP_ICLR_C1IF_Msk					(0x1UL<<ACMP_ICLR_C1IF_Pos)
#define	ACMP_ICLR_C0IF_Pos					(0)
#define ACMP_ICLR_C0IF_Msk					(0x1UL<<ACMP_ICLR_C0IF_Pos)



/*---------------------- FMC Manger Controller -------------------------*/
typedef struct
{					
	__IO  uint32_t CON;
	__IO  uint32_t ADR;
	__IO  uint32_t DAT;
	__IO  uint32_t CMD;
	__IO  uint32_t LOCK;
	__I   uint32_t RESERVE0[3];
	__IO  uint32_t CRCEA;
	__IO  uint32_t CRCIN;
	__IO  uint32_t CRCD;
} FMC_T;
/*------CON------------------------------------------------------------------*/
#define	FMC_CON_BUSY_Pos					(5)
#define FMC_CON_BUSY_Msk					(0x1UL<<FMC_CON_BUSY_Pos)
#define	FMC_CON_ISPS_Pos					(4)
#define FMC_CON_ISPS_Msk					(0x1UL<<FMC_CON_ISPS_Pos)



/*@}*/ /* end of REGISTER  group  Peripherals */

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup   Memory Mapped Structure for Peripheral
  @{
*/
/* Peripheral and SRAM base address */
#define FLASH_BASE          (0x00000000UL)        /*!< (FLASH   ) Base Address */
#define INFO_BASE           (0x10000000UL)        /*!< (INFO    ) Base Address */
#define SRAM_BASE           (0x20000000UL)        /*!< (SRAM    ) Base Address */
#define APB_BASE            (0x40000000UL)        /*!< (APB     ) Base Address */
#define AHB_BASE            (0x50000000UL)        /*!< (AHB     ) Base Address */
#define UDID_BASE           (0x18000004UL)        /*!< (UDID    ) Base Address */

/* APB memory map */
#define WWDT_BASE           (APB_BASE + 0x1800000UL)  
#define CCP_BASE            (APB_BASE + 0x2800000UL)  
#define SSP_BASE            (APB_BASE + 0x3800000UL)  
#define UART0_BASE          (APB_BASE + 0x4800000UL)  
#define UART1_BASE          (APB_BASE + 0x5000000UL)  
#define TMR0_BASE           (APB_BASE + 0x6800000UL)  
#define TMR1_BASE           (APB_BASE + 0x6800100UL)  
#define WDT_BASE            (APB_BASE + 0x7800000UL)  
#define I2C_BASE            (APB_BASE + 0x8000000UL)  
#define FMC_BASE            (APB_BASE + 0x9800000UL) 
#define CRC_BASE            (APB_BASE + 0xA000000UL) 
#define EPWM_BASE           (APB_BASE + 0xA800000UL) 
#define OPA0_BASE           (APB_BASE + 0xC800000UL) 
#define OPA1_BASE           (APB_BASE + 0xC80000CUL) 
#define PGA0_BASE           (APB_BASE + 0xC800018UL) 
#define PGA1_BASE           (APB_BASE + 0xC800024UL) 
#define ACMP_BASE           (APB_BASE + 0xD000000UL) 
#define ADC1_BASE           (APB_BASE + 0xD800000UL) 
/* AHB memory map */
#define SYSCON_BASE         (AHB_BASE) 
#define GPIO0_BASE          (AHB_BASE + 0x2000000UL) 
#define GPIO1_BASE          (AHB_BASE + 0x2800000UL) 
#define GPIO2_BASE          (AHB_BASE + 0x3000000UL) 
#define GPIO3_BASE          (AHB_BASE + 0x3800000UL) 
#define GPIO4_BASE          (AHB_BASE + 0x4000000UL) 
#define HWDIV_BASE          (AHB_BASE + 0x5000000UL) 

/*@}*/ /* end of group  MemoryMap */

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
/** @addtogroup  PeripheralDecl  Peripheral Declaration
  @{
*/
#define WWDT				((WWDT_T  	*)	WWDT_BASE) 
#define CCP					((CCP_T		*)	CCP_BASE)  
#define SSP					((SSP_T		*)	SSP_BASE)
#define UART0				((UART_T	*)	UART0_BASE) 
#define UART1				((UART_T	*)	UART1_BASE) 
#define TMR0				((TMR_T		*)	TMR0_BASE) 
#define TMR1				((TMR_T		*)	TMR1_BASE) 
#define WDT					((WDT_T		*)	WDT_BASE) 
#define I2C					((I2C_T		*)	I2C_BASE) 
#define FMC					((FMC_T		*)	FMC_BASE) 
#define CRC					((CRC_T		*)	CRC_BASE) 
#define EPWM                ((EPWM_T	*)	EPWM_BASE)
#define OPA0                ((OPA_T		*)	OPA0_BASE)
#define OPA1                ((OPA_T		*)	OPA1_BASE)
#define PGA0                ((PGA_T		*)	PGA0_BASE)
#define PGA1                ((PGA_T		*)	PGA1_BASE)
#define ACMP                ((ACMP_T	*)	ACMP_BASE)
#define ADC1                ((ADC1_T	*)	ADC1_BASE)
#define SYS                 ((SYS_T		*)	SYSCON_BASE)
#define GPIO0               ((GPIO_T	*)	GPIO0_BASE)
#define GPIO1               ((GPIO_T	*)	GPIO1_BASE)
#define GPIO2               ((GPIO_T	*)	GPIO2_BASE)
#define GPIO3               ((GPIO_T	*)	GPIO3_BASE)
#define GPIO4               ((GPIO_T	*)	GPIO4_BASE)
#define HWDIV				((HWDIV_T	*)	HWDIV_BASE)






/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
#include "system.h"
#include "gpio.h"
#include "acmp.h"
#include "adc1.h"
#include "ccp.h"
#include "crc.h"
#include "epwm.h"
#include "gpio.h"
#include "hwdiv.h"
#include "i2c.h"
#include "opa.h"
#include "pga.h"
#include "ssp.h"
#include "timer.h"
#include "uart.h"
#include "wdt.h"
#include "wwdt.h"


/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __CMS32F033X_H__ */






