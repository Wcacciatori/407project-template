#ifndef __IIC_H
#define __IIC_H


void MyIIC_Init(void);

void MyIIC_SendByte(uint8_t Byte);
uint8_t MyIIC_ReceiveByte(void);


#endif
