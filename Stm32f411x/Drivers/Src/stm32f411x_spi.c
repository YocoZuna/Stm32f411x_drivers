/*
 * stm32f411x+spi.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Dawid Zadlo
 */
#include "stm32f411x.h"















void SPI_RCC(SPIx_RegDef *xSPI,uint8_t on_off)
{
	if( SPI1 == xSPI && on_off == SET)
	{
		RCC_SPI1_EN();
	}
	else if ((xSPI == SPI1 && on_off == RESET))
	{
		RCC_SPI1_DS();
	}
	if( SPI2 == xSPI && on_off == SET)
	{
		RCC_SPI2_EN();
	}
	else if ((xSPI == SPI2 && on_off == RESET))
	{
		RCC_SPI2_DS();
	}
	if( SPI3 == xSPI && on_off == SET)
	{
		RCC_SPI3_EN();
	}
	else if ((xSPI == SPI3 && on_off == RESET))
	{
		RCC_SPI3_DS();
	}
	if( SPI4 == xSPI && on_off == SET)
	{
		RCC_SPI4_EN();
	}
	else if ((xSPI == SPI4 && on_off == RESET))
	{
		RCC_SPI4_DS();
	}
}
void SPI_Init(SPIx_RegDef *xSPI);
void SPI_DeInit(SPIx_RegDef *xSPI)
{
	if( SPI1 == xSPI)
	{
		SPI1_REG_RESET();
	}
	else if ( SPI2 == xSPI)
	{
		SPI2_REG_RESET();
	}
	else if ( SPI3 == xSPI)
	{
		SPI3_REG_RESET();
	}
	else if ( SPI4 == xSPI)
	{
		SPI4_REG_RESET();
	}
}

void SPI_Receive_Polling(SPIx_RegDef *xSPI, uint8_t *RXbuffor,uint32_t length);
void SPI_Send_Polling(SPIx_RegDef *xSPI, uint8_t *TXbuffor,uint32_t length);

void SPI_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void SPI_IRQHandler(SPIx_Handle_t *pHandle);
void SPI_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
