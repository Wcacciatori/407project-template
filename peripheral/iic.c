#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "Delay.h"

void MyIIC_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_10, (BitAction)BitValue);
	Delay_us(10);
}
void MyIIC_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_12, (BitAction)BitValue);
	Delay_us(10);
}

uint8_t MyIIC_R_SDA(void)
{
	uint8_t BitValue;
	BitValue = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_12);
	
	Delay_us(10);
	return BitValue;
}

void MyIIC_Init(void)
{
	

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC ,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOC	, &GPIO_InitStructure);
		
	GPIO_SetBits(GPIOC, GPIO_Pin_10 | GPIO_Pin_12);
}

void MyIIC_Start(void)
{
	MyIIC_W_SDA(1);
	MyIIC_W_SCL(1);
	MyIIC_W_SDA(0);
	MyIIC_W_SCL(0);
}

void MyIIC_Stop(void)
{
	MyIIC_W_SDA(0);
	MyIIC_W_SCL(1);
	MyIIC_W_SDA(1);	
}

void MyIIC_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i = 0; i < 8; i++)
	{
	MyIIC_W_SDA(Byte & (0x80 >> i));
	MyIIC_W_SCL(1);
	MyIIC_W_SCL(0);
	}
}

uint8_t MyIIC_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	MyIIC_W_SDA(1);	

	for(i = 0;i < 8; i++)
	{
		MyIIC_W_SCL(1);	
		if(MyIIC_R_SDA() == 1)
		{
		Byte |= (0x80 >> i);
		}
		MyIIC_W_SCL(0);
	}
	return Byte;
	
}

void MyIIC_SendAck(uint8_t AckBit)
{

	MyIIC_W_SDA(AckBit);
	MyIIC_W_SCL(1);
	MyIIC_W_SCL(0);
	
}

uint8_t MyIIC_ReceiveAck(void)
{
	uint8_t AckBit ;
	MyIIC_W_SDA(1);	
	MyIIC_W_SCL(1);	
	AckBit = MyIIC_R_SDA();
	MyIIC_W_SCL(0);
	return AckBit;	
}