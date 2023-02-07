/*
 * stm32f411x_gpio.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Dawid Zadlo
 */
#ifndef INC_STM32F411X_SPI_H_
#define INC_STM32F411X_SPI_H_
#include <stdint.h>
#include "stm32f411x.h"

typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCPR;
	volatile uint32_t SPI_TXCPR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPIx_RegDef;

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_CLKSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPIx_ConfigDef;

typedef struct
{
	SPIx_RegDef *pSPIx;
	SPIx_ConfigDef SPIConifg;
}SPIx_Handle_t;

/*
 * Device mode
 */
#define SPI_DEVICE_MODE_MASTER	1
#define SPI_DEVICE_MODE_SLAVE 	0

/*
 * Busconfig
 */
#define SPI_BUSCONFIG_FULL		0
#define SPI_BUSCONFIG_HALF		1
#define SPI_BUSCONFIG_TX_ONLY	2
#define SPI_BUSCONFIG_RX_ONLY	3
/*
 * Clock speed of SPI
 */
#define SPI_SPEED_2				0
#define SPI_SPEED_4				1
#define SPI_SPEED_8				2
#define SPI_SPEED_16			3
#define SPI_SPEED_32			4
#define SPI_SPEED_64			5
#define SPI_SPEED_128			7
#define SPI_SPEED_4257			7

/*
 *  Bit size
 */
#define SPI_DFF_8bit			0
#define SPI_DFF_16bit			1

/*
 * CPOL
 */
#define SPI_CPOL_RISING			1
#define SPI_CPOL_FALLING		0

/*
 * CPHA
 */
#define SPI_CPHA_First			0
#define SPI_CPHA_Second			1

/*
 * NSS menagment
 */
#define SPI_NSS_SOFTWARE 		1
#define SPI_NSS_HARDWARE		0

#define SPI1 ((SPIx_RegDef*)DRV_SPI1)
#define SPI2 ((SPIx_RegDef*)DRV_SPI2)
#define SPI3 ((SPIx_RegDef*)DRV_SPI3)
#define SPI4 ((SPIx_RegDef*)DRV_SPI4)


void SPI_RCC(SPIx_RegDef *xSPI,uint8_t on_off);
void USART_Init(SPIx_Handle_t *xSPI);
void SPI_DeInit(SPIx_RegDef *xSPI);

void USART_Receive_Polling(SPIx_RegDef *xSPI, uint8_t *RXbuffor,uint32_t length);
void SPI_Send_Polling(SPIx_RegDef *xSPI, uint8_t *TXbuffor,uint32_t length);

void SPI_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void SPI_IRQHandler(SPIx_Handle_t *pHandle);
void SPI_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
#endif
/* INC_STM32F411X_GPIO_H_*/
