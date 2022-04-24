#include "cms32f033x.h"
#include "define.h"

FLASH_FUNC_E 			func_flag;			//�洢flash�ı�־����
FLASH_FEED_INFO_E		flash_feed_info;	//ιʳ�ƻ�

 FLASH_FUNC_E 	func_flag_default = {
	FLASH_KEEP_VAL,
	1,							//ָʾ�ƿ���
	1,							//��Χ�ƿ���
	0,							//��������־
	#ifdef TY_DP_RECORD
	0,							//¼��ʱ��
	1,							//¼�����Ŵ���
	0,							//¼��״̬
	#endif
	#ifdef TY_DP_DESICCANT
	30,							//���������ʱ��
	30,							//�����ʣ��ʱ��
	#endif	 
	#ifdef OFFLINE_RECORD
	0,							//����ιʳ��¼����
	#endif
};

/*****************************************************************************
 ** \brief	FMC_EraseAll
 **			FMC �������
 ** \param [in] none 
 ** \return  none
 ** \note	������APROM
*****************************************************************************/
void FMC_EraseAll(void)
{
	FMC->LOCK = FMC_WRITE_KEY;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->CMD = FMC_CMD_ALL_ERASE;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	FMC_ErasePage
 **			FMC ҳ����
 ** \param [in] PageAddr: 
 ** \return  none
 ** \note	
*****************************************************************************/
void FMC_ErasePage(uint32_t PageAddr)
{
	FMC->LOCK = FMC_WRITE_KEY;
	FMC->ADR = PageAddr;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->CMD = FMC_CMD_PAGE_ERASE;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	FMC_Read
 **			FMC ��
** \param [in] DataAddr:��ַ����λ����Ϊ0
 ** \return  32λ����
 ** \note	
*****************************************************************************/
uint32_t FMC_Read(uint32_t DataAddr)
{
	uint32_t FlashData;
	FMC->LOCK = FMC_WRITE_KEY;
	FMC->ADR = (DataAddr & 0xFFFFFFFC);
	FMC->CMD = FMC_CMD_READ;
	FlashData = FMC->DAT;
	FMC->LOCK = 0x00;
	return FlashData;
}

/*****************************************************************************
 ** \brief	FMC_Write
 **			FMC д
** \param [in] DataAddr:��ַ����λ����Ϊ0
 **				DataVlue: 32λ����
 ** \return  none
 ** \note	
*****************************************************************************/
void FMC_Write(uint32_t DataAddr, uint32_t DataVlue)
{
	FMC->LOCK = FMC_WRITE_KEY;
	FMC->ADR = (DataAddr & 0xFFFFFFFC);
	FMC->DAT = DataVlue;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->CMD = FMC_CMD_WRITE;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	FMC->LOCK = 0x00;
}

/*****************************************************************************
 ** \brief	FMC_CRC
 **			FMC CRCУ��
 ** \param [in] CRCStartAddr:	  CRCУ����ʼ��ַ
 **				CRCStopAddr:	  CRCУ�������ַ
 ** \return  none
 ** \note	 ֻ������APROM��
*****************************************************************************/
uint16_t FMC_CRC(uint32_t CRCStartAddr, uint32_t CRCStopAddr)
{
	uint16_t CrcResult;
	FMC->LOCK = FMC_WRITE_KEY;
	FMC->ADR = CRCStartAddr & 0xFFFFFFFC;
	FMC->CRCEA = CRCStopAddr & 0xFFFFFFFC;
	FMC->CRCIN = 0x00;
	FMC->CRCD = 0x00;
	FMC->CMD = FMC_CMD_CRC;
	while((FMC->CON & FMC_CON_BUSY_Msk)==FMC_CON_BUSY_Msk);
	CrcResult = FMC->CRCD;	
	FMC->LOCK = 0x00;
	return CrcResult;
}

void IAP_erase_user(uint32_t PageAddr)				//������������(512�ֽ�һ����)
{	
	FMC_ErasePage(PageAddr); 
}	


void IAP_write_user(uint32_t Addr, uint8_t *EEDATA, uint16_t number)		
{
	uint16_t i,j;
	uint32_t data = 0;
	
	for(i = 0; i < number / 4; i++)
	{
		data = (EEDATA[i * 4] << 24) | (EEDATA[i * 4 + 1] << 16) | (EEDATA[i * 4 + 2] << 8) | EEDATA[i * 4 + 3];
		FMC_Write((Addr + (i*4)), data);
	}	
	data = 0;
	for(j = 0; j < number % 4; j++)
	{
		data = data + (EEDATA[i * 4 + j] << (24 - (j * 8)));
		data = data & 0xffffffff;
	}
	if(number % 4 > 0)
	{
		FMC_Write((Addr + (i*4)), data);
	}
}

void IAP_read_user(uint32_t Addr, uint8_t *DataAddress, uint16_t number)
{	
	uint16_t i,j;
	uint32_t data = 0;
	
	for(i = 0; i < number / 4; i++)
	{
		data = FMC_Read(Addr + (i*4));
		*(DataAddress + (i * 4)) 		= (data >> 24) & 0xFF;
		*(DataAddress + (i * 4) + 1) 	= (data >> 16) & 0xFF;
		*(DataAddress + (i * 4) + 2) 	= (data >> 8) & 0xFF;
		*(DataAddress + (i * 4) + 3) 	= data & 0xFF;
	}
	data = FMC_Read(Addr + (i*4));
	for(j = 0; j < number % 4; j++)
	{
		*(DataAddress + (i * 4) + j) = (data >> (24 - (j * 8))) & 0xFF;
	}		
}

 void printf_feed_info()
{
	u8 i;
	
	IAP_read_user(FLASH_FEED_INFO_ADDR, (u8 *) &flash_feed_info, sizeof(FLASH_FEED_INFO_E));

	printf("read feed_info:  \r\n");
	for(i = 0; i < FEED_MAX_NUM; i++)
	{
		printf("%02X-%02X-%02X-%02X-%02X  \r\n",
		flash_feed_info.feed_info[i].week, flash_feed_info.feed_info[i].hour, flash_feed_info.feed_info[i].minute, 
		flash_feed_info.feed_info[i].weight, flash_feed_info.feed_info[i].allow_feed);		
	}
}
 void printf_func_info()
{
	IAP_read_user(FLASH_FUNC_ADDR, (u8 *)&func_flag, sizeof(FLASH_FUNC_E) / 4);

	printf("val:%d  \r\n",func_flag.val);
	printf("led_switch:%d  \r\n",func_flag.led_switch);
	printf("food_led_switch:%d  \r\n",func_flag.food_led_switch);
	printf("lock_key:%d  \r\n",func_flag.lock_key);
	#ifdef TY_DP_RECORD
	printf("record_time:%d  \r\n",func_flag.record_time);
	printf("voice_times:%d  \r\n",func_flag.voice_times);
	printf("record_state:%d  \r\n",func_flag.record_state);
	#endif
	#ifdef TY_DP_DESICCANT
	printf("remind_time:%d  \r\n",func_flag.remind_time);
	printf("remaining_time:%d  \r\n",func_flag.remaining_time);
	#endif
	#ifdef OFFLINE_RECORD
	printf("record_buf_num:%d  \r\n",func_flag.record_buf_num);
	#endif
}

//flash�洢��ʼ��
void eeprom_data_init(u8 cmd)
{
	IAP_read_user(FLASH_FEED_INFO_ADDR, (u8 *)&flash_feed_info, sizeof(FLASH_FEED_INFO_E));
	IAP_read_user(FLASH_FUNC_ADDR, (u8 *)&func_flag, sizeof(FLASH_FUNC_E) / 4);

	if(cmd != 0)
	{
		memset(&flash_feed_info, 0, sizeof(FLASH_FEED_INFO_E));
		memcpy(&func_flag, &func_flag_default, sizeof(FLASH_FUNC_E));
	
		flash_feed_info.val = FLASH_KEEP_VAL;
		user_write_flash(FLASH_FEED_INFO_ADDR, (u8 *) &flash_feed_info, sizeof(FLASH_FEED_INFO_E));		
		user_write_flash(FLASH_FUNC_ADDR, (u8 *) &func_flag, sizeof(FLASH_FUNC_E));
	}
	else
	{
		//flash�Ѿ���ʼ�������Ҳ����û���Ҫ���³�ʼ��flash���˳���ʼ��flash
		if(flash_feed_info.val != FLASH_KEEP_VAL )
		{
			memset(&flash_feed_info, 0, sizeof(FLASH_FEED_INFO_E));
			
			flash_feed_info.val = FLASH_KEEP_VAL;
			user_write_flash(FLASH_FEED_INFO_ADDR, (u8 *) &flash_feed_info, sizeof(FLASH_FEED_INFO_E));
		}
		
		if(func_flag.val != FLASH_KEEP_VAL )
		{
			memcpy(&func_flag, &func_flag_default, sizeof(FLASH_FUNC_E));
			
			user_write_flash(FLASH_FUNC_ADDR, (u8 *) &func_flag, sizeof(FLASH_FUNC_E)/4);
		}		
	}	
	
	printf_feed_info();
	printf_func_info();
}

/* д���ݽ�����Flash�洢��(EEPROM), ֻ��ͬһ��������д������ͬһ�����в����޸ĵ�����    */
/* begin_addr,��д����Flash��ʼ��ַ��counter,����д���ٸ��ֽڣ� dat��������Դ; sector:������       */
void user_write_flash(u32 begin_addr, u8 *dat, u16 counter)
{
	u8 protect_buffer[USED_BYTE_QTY_IN_ONE_SECTOR];
	u16 i = 0;
	u32 in_sector_begin_addr = 0;
	u32 sector_addr = 0;

	memset(protect_buffer,0,sizeof(protect_buffer));

	in_sector_begin_addr = begin_addr & 0x1ff;
	/* ������������ 0 - (USED_BYTE_QTY_IN_ONE_SECTOR-1) �ֽ����ݶ��뻺�������� */	
	if(begin_addr >= FMC_DAT_START + SECTOR_SIZE)
	{
		sector_addr = FMC_DAT_START + SECTOR_SIZE;
	}
	else
		sector_addr = FMC_DAT_START;
	
	IAP_read_user(sector_addr, protect_buffer, USED_BYTE_QTY_IN_ONE_SECTOR);

	/* ��Ҫд�������д�뱣������������Ӧ����,���ಿ�ֱ��� */
	for (i = 0; i < counter; i++) 
	{
		protect_buffer[in_sector_begin_addr++] = dat[i];
	}
	
	/* ���� Ҫ�޸�/д�� ������ */
	IAP_erase_user( sector_addr);
	
	/* ������������������д�� Data Flash, EEPROM */
	IAP_write_user(sector_addr, (u8 *) &protect_buffer, USED_BYTE_QTY_IN_ONE_SECTOR);	
}
