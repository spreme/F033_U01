#ifndef _FLASH_USER_H_
#define _FLASH_USER_H_

#include "define.h"

/*----------------------------------------------------------------------------
 **FMC ��������
-----------------------------------------------------------------------------*/
#define	FMC_APROM_START		(0x00UL)		
#define	FMC_APROM_END		(0xFFFFFFFFUL)				/*Max:64Kb*/

#define	FMC_DAT_START		(0x1C000000UL)
#define	FMC_DAT_END			(0x1C0003FFUL)				/*1Kb*/


/*----------------------------------------------------------------------------
 **FMC ��������
-----------------------------------------------------------------------------*/
#define	FMC_CMD_READ		(0x1U)				
#define FMC_CMD_WRITE		(0x2U)				
#define FMC_CMD_CRC			(0xDU)				/*CRCУ�� CRC16-CCITT*/
#define FMC_CMD_PAGE_ERASE		(0x3U)				/*ҳ����*/
#define FMC_CMD_ALL_ERASE		(0x6U)				/*�������*/

/*----------------------------------------------------------------------------
 **FMC ����
-----------------------------------------------------------------------------*/
#define	FMC_WRITE_KEY	(0x55AA6699)

/*****************************************************************************
 ** \brief	
 **			
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/

							
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
 ** \brief	
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	FMC_EraseAll
 **			FMC �������
 ** \param [in] none 
 ** \return  none
 ** \note	������APROM
*****************************************************************************/
void FMC_EraseAll(void);

/*****************************************************************************
 ** \brief	FMC_ErasePage
 **			FMC ҳ����
 ** \param [in] PageAddr: 
 ** \return  none
 ** \note	
*****************************************************************************/
void FMC_ErasePage(uint32_t PageAddr);

/*****************************************************************************
 ** \brief	FMC_Read
 **			FMC ��
 ** \param [in] DataAddr����ַ��λ����Ϊ0
 ** \return  32λ����
 ** \note	
*****************************************************************************/
uint32_t FMC_Read(uint32_t DataAddr);
/*****************************************************************************
 ** \brief	FMC_Write
 **			FMC д
 ** \param [in] DataAddr����ַ��λ����Ϊ0
 **				DataVlue: 32λ����
 ** \return  none
 ** \note	
*****************************************************************************/
void FMC_Write(uint32_t DataAddr, uint32_t DataVlue);

/*****************************************************************************
 ** \brief	FMC_CRC
 **			FMC CRCУ��
 ** \param [in] CRCStartAddr:	  CRCУ����ʼ��ַ
 **				CRCStopAddr:	  CRCУ�������ַ
 ** \return  none
 ** \note	ֻ������APROM��
*****************************************************************************/
uint16_t FMC_CRC(uint32_t CRCStartAddr, uint32_t CRCStopAddr);


#define		SECTOR_SIZE         512				//������С
#define		SECTOR_AMOUNT       2				//��������

#define USED_BYTE_QTY_IN_ONE_SECTOR     128		//���洢�ֽ�(��΢ʵ��512)
//#define USED_BYTE_QTY_IN_ONE_SECTOR   256
//#define USED_BYTE_QTY_IN_ONE_SECTOR   512

#define FLASH_FEED_INFO_ADDR  	FMC_DAT_START + 4
#define FLASH_FUNC_ADDR  		FMC_DAT_START + SECTOR_SIZE


extern void IAP_erase_user(uint32_t PageAddr);						//ɾ������
extern void IAP_write_user(uint32_t Addr, uint8_t *EEDATA, u16 number);		//д������
extern void IAP_read_user(uint32_t Addr, uint8_t *DataAddress, u16 number);	//��ȡ����
extern void eeprom_data_init(u8 cmd);								//��ʼ��flash
extern void user_write_flash(u32 begin_addr, u8 *dat, u16 counter);		//д��������
extern void protect_data_change(char error_num);					//���ݱ������ݸ���ιʳ�ƻ�
extern char check_eeprom_data(void);									//��ⱸ��ιʳ�ƻ���ιʳ�ƻ��Ƿ��쳣

extern void printf_feed_info(void);
#endif

