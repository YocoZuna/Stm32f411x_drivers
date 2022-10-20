/*
 * stm32f411x+spi.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Dawid Zadlo
 */

void SPI_RCC(SPIx_RegDef *xSPI,uint8_t on_off);
void SPI_Init(SPIx_RegDef *xSPI);
void SPI_DeInit(SPIx_RegDef *xSPI);

void SPI_Receive_Polling(SPIx_RegDef *xSPI, uint8_t *RXbuffor,uint32_t length);
void SPI_Send_Polling(SPIx_RegDef *xSPI, uint8_t *TXbuffor,uint32_t length);

void SPI_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void SPI_IRQHandler(SPIx_Handle_t *pHandle);
void SPI_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
