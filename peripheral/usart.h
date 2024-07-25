#ifndef __USART_H
#define __USART_H

#include "main.h" 




/*���ڵĳ�ʼ���������ʼ����PA9��PA10*/
void Serial_Init(void);

/*���͵����ֽ�*/
void Serial_SendByte(uint8_t Byte);

/*���յ����ֽ�*/
uint8_t Serial_GetRxData(void);

/*��ӡ*/
void Serial_Printf(char *format, ...);

/*��������*/
void Serial_SendArray(int16_t *Array, uint16_t Length);

/*�����ַ���*/
void Serial_SendString(char *String);

/*��������*/
void Serial_SendNumber(int32_t Number, uint8_t Length);



#endif
