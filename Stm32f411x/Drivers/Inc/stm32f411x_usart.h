/*
 * stm32f411x_usart.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Dawid Zadlo
 */

#ifndef INC_STM32F411X_USART_H_
#define INC_STM32F411X_USART_H_

#include "stm32f411x.h"
#include "stm32f411x_gpio.h"
#include "stdint.h"

typedef struct
{
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GTPR;
} USARTx_RegDef;

typedef struct
{
	uint32_t USART_Baudrate;
	uint8_t USART_Mode;
	uint8_t USART_Parity;
	uint8_t USART_Stop_Bits;
	uint8_t USART_Hardware_Control;
	uint8_t USART_Word_length;
} USARTx_ConfigDef;

typedef struct
{
	USARTx_ConfigDef USARTConfig;
	USARTx_RegDef *pUSART;
	// Here we have a pointer because it should have to point to specific place
	// in msemory, i think that is correct thinking.
} USARTx_Handle_t;

/**********************************Baudrate*******************/
#define USART_BAUDRATE_1200		1200
#define USART_BAUDRATE_2400		2400
#define USART_BAUDRATE_9600		9600
#define USART_BAUDRATE_19200	19200
#define USART_BAUDRATE_38400	38400
#define USART_BAUDRATE_57600	57600
#define USART_BAUDRATE_115200	115200
#define USART_BAUDRATE_230400	230400
#define USART_BAUDRATE_460800	460800
/**********************************Mode*******************/
#define USART_MODE_ONLY_TX		1
#define USART_MODE_ONLY_RX		0
#define USART_MODE_ONLY_TXRX	2
/**********************************Parity*******************/
#define USART_PARITY_NONE		0
#define USART_PARITY_ODD 		1
#define USART_PAITY_EVEN    	2
/**********************************Stopbits*******************/
#define USART_STOP_05	1
#define USART_STOP_1	0
#define USART_STOP_15	2
#define USART_STOP_2	3
/**********************************hARDWARE*******************/
#define USART_CONTROL_NONE		0
#define USART_CONTROL_CTS		1
#define USART_CONTROL_RTS		2
#define USART_CONTROL_CTSRTS	3
/**********************************Word length*******************/
#define USART_WORD_8bit			0
#define USART_WORD_9bit			1

#define USART2 ((USARTx_RegDef*)DRV_USART2)
/********************************Prototypes**********************/


void USART_RCC (USARTx_RegDef * USART,uint8_t on_off);
void USART_Init (USARTx_Handle_t * USART);
void USART_DeInit(USARTx_RegDef * USART);

void USART_Receive_Polling (USARTx_RegDef * USART, uint8_t *RXbuffor,uint32_t length);
void USART_Send_Polling (USARTx_RegDef * USART, uint8_t *TXbuffor,uint32_t length);

void USART_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void USART_IRQHandler (USARTx_Handle_t *pHandle);
void USART_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
#endif /* INC_STM32F411X_USART_H_ */
