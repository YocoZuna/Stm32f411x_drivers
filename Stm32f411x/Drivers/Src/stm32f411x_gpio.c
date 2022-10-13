/*
 * stm32f411x_gpio.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Dawid Zadlo
 */
#include <stdint.h>

#include "stm32f411x_gpio.h"
/*
 * GPIOx_RegDef *pGPIOx GPIOx for example GPIA
 * on_off SET = on, RESET = off
 */
void GPIO_RCC(GPIOx_RegDef *pGPIOx, uint8_t on_off)
{
	if( GPIOA == pGPIOx && on_off == SET)
	{
		RCC_GPIOA_EN();
	}
	else if ((pGPIOx == GPIOB && on_off == RESET))
	{
		RCC_GPIOB_DS();
	}
	if(pGPIOx == GPIOB && on_off == SET)
	{
		RCC_GPIOB_EN();
	}
	else if ((pGPIOx == GPIOB && on_off == RESET))
	{
		RCC_GPIOB_DS();
	}
	if(pGPIOx == GPIOC && on_off == SET)
	{
		RCC_GPIOC_EN();
	}
	else if ((pGPIOx == GPIOC && on_off == RESET))
	{
		RCC_GPIOC_DS();
	}
	if(pGPIOx == GPIOD && on_off == SET)
	{
		RCC_GPIOD_EN();
	}
	else if ((pGPIOx == GPIOD && on_off == RESET))
	{
		RCC_GPIOD_DS();
	}
	if(pGPIOx == GPIOE && on_off == SET)
	{
		RCC_GPIOE_EN();
	}
	else if ((pGPIOx == GPIOE && on_off == RESET))
	{
		RCC_GPIOE_DS();
	}
	if(pGPIOx == GPIOH && on_off == SET)
	{
		RCC_GPIOH_EN();
	}
	else if ((pGPIOx == GPIOH && on_off == RESET))
	{
		RCC_GPIOH_DS();
	}
}

/*
 * GPIO initialization
 */
void GPIO_Init(GPIOx_Handle_t *GPIO)
{
	//1. Configuring mode of GPIO

}
void GPIO_DeInit(GPIOx_Handle_t *GPIO);

/*
 * Reading and sending to GPIO
 */
uint8_t GPIO_ReadPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber);
uint16_t GPIO_ReadPort(GPIOx_RegDef *pGPIOx);
void GPIO_SetPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber,uint8_t on_off);
void GPIO_Set_Port(GPIOx_RegDef *pGPIOx,uint16_t on_off);
void GPIO_TooglePin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber);

/*
 *	GPIO interrupts
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPiority,uint8_t on_off);
void GPIO_IRQHandler(uint8_t pinNumber);

