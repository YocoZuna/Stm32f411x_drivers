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
	SPI_RegDef *pSPIx;
	SPI_ConfigDef SPIConifg;
}SPIx_Handle_t;


#define SPI1 ((SPIx_RegDef*)DRV_SPI1)
#define SPI2 ((SPIx_RegDef*)DRV_SPI2)
#define SPI3 ((SPIx_RegDef*)DRV_SPI3)
#define SPI3 ((SPIx_RegDef*)DRV_SPI4)


void SPI_RCC(SPIx_RegDef *xSPI,uint8_t on_off);
void SPI_Init(SPIx_RegDef *xSPI);
void SPI_DeInit(SPIx_RegDef *xSPI);

void SPI_Receive_Polling(SPIx_RegDef *xSPI, uint8_t *RXbuffor,uint32_t length);
void SPI_Send_Polling(SPIx_RegDef *xSPI, uint8_t *TXbuffor,uint32_t length);

void SPI_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void SPI_IRQHandler(SPIx_Handle_t *pHandle);
void SPI_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
#endif
/* INC_STM32F411X_GPIO_H_*/
