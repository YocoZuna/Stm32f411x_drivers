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
	/*
	if( USART1 == xUSART && on_off == SET)
	{
		RCC_USART1_EN();
	}
	else if ((xUSART == USART1 && on_off == RESET))
	{
		RCC_USART1_DS();
	}
	*/
	if( USART2 == xUSART && on_off == SET)
	{
		RCC_USART2_EN();
	}
	else if ((xUSART == USART2 && on_off == RESET))
	{
		RCC_USART2_DS();
	}
	/*
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
	*/
}
void USART_Init(USARTx_Handle_t *xUSART)
{
    //Enable USART
	xUSART->pUSART->USART_CR1 |= (1<<13);
    
    /********************************************************************************************/
    /* Word length*/
    if (xUSART->USARTConfig.USART_Word_length == USART_WORD_8bit )
    {
        ;// Here we do not nothing because by default word length is 8bit 
    }
    else if  (xUSART->USARTConfig.USART_Word_length == USART_WORD_9bit )
    {
        xUSART->pUSART->USART_CR1 |= (1<<12);
    }
    /********************************************************************************************/
    /* Hardware control */
    if(xUSART->USARTConfig.USART_Hardware_Control == USART_CONTROL_NONE)
    {
        // None 

    }
    else if(xUSART->USARTConfig.USART_Hardware_Control ==USART_CONTROL_CTS)
    {
        xUSART->pUSART->USART_CR3 |= (1<<9);
    }
    else if(xUSART->USARTConfig.USART_Hardware_Control == USART_CONTROL_RTS)
    {
        xUSART->pUSART->USART_CR3 |= (1<<8);
    }
    else if (xUSART->USARTConfig.USART_Hardware_Control == USART_CONTROL_CTSRTS)
    {
        xUSART->pUSART->USART_CR3 |= (3<<8);
    }
    /********************************************************************************************/
    /* Parity*/
    if (xUSART->USARTConfig.USART_Parity == USART_PARITY_NONE)
    {
        ;// Here we dont nothing because by default parity is disabled
    }
    else if (xUSART->USARTConfig.USART_Parity==USART_PARITY_ODD )
    {
        xUSART->pUSART->USART_CR1 |= (1<<10);
        xUSART->pUSART->USART_CR1 |= (1<<9);
    }
    else if (xUSART->USARTConfig.USART_Parity==USART_PAITY_EVEN)
    {
        xUSART->pUSART->USART_CR1 |= (1<<10);
    }
    /********************************************************************************************/
    /* Stop bits*/
    if (xUSART->USARTConfig.USART_Stop_Bits == USART_STOP_05)
    {
        // stop bit 1
    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==USART_STOP_1)
    {
        xUSART->pUSART->USART_CR2 |= (1<<12);
    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==USART_STOP_15)
    {
        xUSART->pUSART->USART_CR2 |= (3<<12);
    }
    else if (xUSART->USARTConfig.USART_Stop_Bits ==USART_STOP_2)
    {
        xUSART->pUSART->USART_CR2 |= (1<<13);
    }
    /********************************************************************************************/
    // TODO Implement baudrate 
    // Should be smothing more smart than a simple if else if 8oip
    uint32_t sysclock  = 16000000;

    float baud = xUSART->USARTConfig.USART_Baudrate;
    float usartdiv = sysclock/(16*baud);
    float fraction_temp = usartdiv;

    uint32_t mantisa = usartdiv;
    uint8_t fraction = ((fraction_temp-mantisa)*16)+0.5; // +0.5 beacuse we have to round up number  for example 5.56+0.5 will be 6 as we want to 

    xUSART->pUSART->USART_BRR |= (xUSART->pUSART->USART_BRR&0xF000)|(mantisa<<4); // masking bits
    xUSART->pUSART->USART_BRR |= (xUSART->pUSART->USART_BRR&0xF0)|(fraction<<0); // masking bits

    /*Devie mode */ // We first chek for RXTX mode becuase this mode whill be used most offten
    if (xUSART->USARTConfig.USART_Mode == USART_MODE_ONLY_TXRX)
    {
        xUSART->pUSART->USART_CR1 |= (1<<3); //TX enable
        xUSART->pUSART->USART_CR1 |= (1<<2); // Rx enable
    }
    else if (xUSART->USARTConfig.USART_Mode == USART_MODE_ONLY_TX)
    {
        xUSART->pUSART->USART_CR1 |= (1<<3);
    }
    else if (xUSART->USARTConfig.USART_Mode == USART_MODE_ONLY_RX)
    {
        xUSART->pUSART->USART_CR1 |= (1<<2);
    }

}
void USART_DeInit(USARTx_RegDef *xUSART)
{
	//if( USART1 == xUSART)
	//{
	//	USART1_REG_RESET();
	//}
	if ( USART2 == xUSART)
	{
		USART2_REG_RESET();
	}
	//else if ( USART3 == xUSART)
	//{
	//	USART3_REG_RESET();
	//}
	//else if ( USART4 == xUSART)
	//{
	//	USART4_REG_RESET();
	//}

}
/*
void USART_Receive_Polling(USARTx_Handle_t *xUSART, uint8_t *RXbuffor,uint32_t length);
{
	;
}
*/
void USART_Send_Polling(USARTx_Handle_t *xUSART, uint8_t *TXbuffor,uint32_t length)
{

         //enable transmiter
        for (uint32_t i = 0; i < length;i++)
        {
        	while(!(xUSART->pUSART->USART_SR&0x0080)){
        	}
            xUSART->pUSART->USART_DR = (*TXbuffor);


            TXbuffor++;
        }
    

    
    while((xUSART->pUSART->USART_SR>>6)==1);

}

void USART_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void USART_IRQHandler(USARTx_Handle_t *pHandle);
void USART_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);

