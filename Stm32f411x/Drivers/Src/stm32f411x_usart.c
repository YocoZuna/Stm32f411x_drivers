/*
 * stm32f411x_usart.c
 *
 *  Created on: Feb 3, 2023
 *      Author: Dawid Zadlo
 */


#include "stm32f411x.h"
#include "stm32f411x_usart.h"
void USART_RCC(USARTx_RegDef *xUSART,uint8_t on_off)
{
	if( USART1 == xUSART && on_off == SET)
	{
		RCC_USART1_EN();
	}
	else if ((xUSART == USART1 && on_off == RESET))
	{
		RCC_USART1_DS();
	}
	if( USART2 == xUSART && on_off == SET)
	{
		RCC_USART2_EN();
	}
	else if ((xUSART == USART2 && on_off == RESET))
	{
		RCC_USART2_DS();
	}
	if( USART3 == xUSART && on_off == SET)
	{
		RCC_USART3_EN();
	}
	else if ((xUSART == USART3 && on_off == RESET))
	{
		RCC_USART3_DS();
	}
	if( USART4 == xUSART && on_off == SET)
	{
		RCC_USART4_EN();
	}
	else if ((xUSART == USART4 && on_off == RESET))
	{
		RCC_USART4_DS();
	}
}
void USART_Init(USARTx_Handle_t *xUSART)
{
    /*Devie mode */ // We first chek for RXTX mode becuase this mode whill be used most offten
    if (xUSART->USARTConfig.USART_Mode == 2)
    {
        
    }
    else if (xUSART->USARTConfig.USART_Mode == 1)
    {
        
    }
    else if (xUSART->USARTConfig.USART_Mode == 0)
    {
        
    }
    /********************************************************************************************/
    /* Word length*/
    if (xUSART->USARTConfig.USART_Word_length == 0 )
    {

    }
    else if  (xUSART->USARTConfig.USART_Word_length == 1 )
    {

    }
    /********************************************************************************************/
    /* Hardware control */
    if(xUSART->USARTConfig.USART_Hardware_Control == 0)
    {

    }
    else if(xUSART->USARTConfig.USART_Hardware_Control == 1)
    {

    }
    else if(xUSART->USARTConfig.USART_Hardware_Control == 2)
    {

    }
    else if (xUSART->USARTConfig.USART_Hardware_Control == 3)
    {

    }
    /********************************************************************************************/
    /* Parity*/
    if (xUSART->USARTConfig.USART_Parity == 0)
    {

    }
    else if (xUSART->USARTConfig.USART_Parity==1)
    {
        
    }
    else if (xUSART->USARTConfig.USART_Parity==2)
    {
        
    }
    /********************************************************************************************/
    /* Stop bits*/
    if (xUSART->USARTConfig.USART_Stop_Bits == 0)
    {

    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==1)
    {

    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==2)
    {

    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==3)
    {

    }
    /********************************************************************************************/
    // TODO Implement baudrate 
}
void USART_DeInit(USARTx_RegDef *xUSART)
{
	if( USART1 == xUSART)
	{
		USART1_REG_RESET();
	}
	else if ( USART2 == xUSART)
	{
		USART2_REG_RESET();
	}
	else if ( USART3 == xUSART)
	{
		USART3_REG_RESET();
	}
	else if ( USART4 == xUSART)
	{
		USART4_REG_RESET();
	}

}

void USART_Receive_Polling(USARTx_RegDef *xUSART, uint8_t *RXbuffor,uint32_t length);
void USART_Send_Polling(USARTx_RegDef *xUSART, uint8_t *TXbuffor,uint32_t length)
{
	while(length>0)
	{


		while(((xUSART->USART_SR)>>1)==0);
		if(xUSART->USART_CR1 & (1<11))
		{

			xUSART->USART_DR = *((uint16_t*)TXbuffor);


			length--;
			length--;
			(uint16_t*)TXbuffor++;
		}
		else
		{
			xUSART->USART_DR = *((uint8_t*)TXbuffor);
			length--;
			TXbuffor++;
		}
		}
}

void USART_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void USART_IRQHandler(USARTx_Handle_t *pHandle);
void USART_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);

