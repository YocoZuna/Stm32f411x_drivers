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
	uint8_t pinConfig = 0;
	//1. Configuring mode of GPIO
	if(GPIO->GPIO_PinConfig.pinMode <= GPIO_MODE_ANALOG)
	{
		// none interrupt mode
		/*
		 * 2*0 =  Ustawienia dla pinu 0 zerowy bait
		 * 2*1 = Ustawienia dla pinu numer 1 wpisane zostana w drugi bit
		 */
		pinConfig = (GPIO->GPIO_PinConfig.pinMode <<(2 *GPIO->GPIO_PinConfig.pinNumber));
		GPIO->pGPIOx->MODER  &=~(0x03<<pinConfig);
		GPIO->pGPIOx->MODER  |= pinConfig;

		pinConfig = 0;

		pinConfig = (GPIO->GPIO_PinConfig.pinSpeed <<(2 *GPIO->GPIO_PinConfig.pinNumber));
		GPIO->pGPIOx->OSPEEDR  &=~(0x03<<pinConfig);
		GPIO->pGPIOx->OSPEEDR  |= pinConfig;
		pinConfig = 0;


		pinConfig = (GPIO->GPIO_PinConfig.pinPuPd <<(2 *GPIO->GPIO_PinConfig.pinNumber));
		GPIO->pGPIOx->PUPDR  &=~(0x03<<pinConfig);
		GPIO->pGPIOx->PUPDR  |= pinConfig;
		pinConfig = 0;

		pinConfig = GPIO->GPIO_PinConfig.pinOType << GPIO->GPIO_PinConfig.pinNumber;
		GPIO->pGPIOx->OTYPER  &=~(0x03<<pinConfig);
		GPIO->pGPIOx->OTYPER  |= pinConfig;
		pinConfig = 0;



	}
	else
	{
		//interrupt mode
	}

	pinConfig = GPIO->GPIO_PinConfig.pinNumber/1;
	uint8_t altNumber = GPIO->GPIO_PinConfig.pinNumber%8;
		GPIO->pGPIOx->AFR[altNumber]  &=~(0xF<<(4 *GPIO->GPIO_PinConfig.pinNumber));
		GPIO->pGPIOx->AFR[altNumber]  |= (GPIO->GPIO_PinConfig.pinAltFun <<(4 *GPIO->GPIO_PinConfig.pinNumber));
		pinConfig = 0;
		altNumber = 0 ;

}

void GPIO_DeInit(GPIOx_RegDef *pGPIOx)
{
	if( GPIOA == pGPIOx)
	{
		GPIOA_REG_RESET();

	}


	if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();

	}

	if(pGPIOx == GPIOD )
	{
		GPIOD_REG_RESET();

	}

	if(pGPIOx == GPIOE )
	{
		GPIOE_REG_RESET();

	}

	if(pGPIOx == GPIOH )
	{
		GPIOH_REG_RESET();

	}

}

/*
 * Reading and sending to GPIO
 */
uint8_t GPIO_ReadPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber)
{
	uint8_t value  = ((pGPIOx->IDR>>pinNumber)&0x1);

	return value;
}
uint16_t GPIO_ReadPort(GPIOx_RegDef *pGPIOx)
{
	uint16_t value  = pGPIOx->IDR;

	return value;
}
void GPIO_SetPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber,uint8_t on_off)
{
	on_off == SET ? (pGPIOx->ODR|=(1<<pinNumber)) : (pGPIOx->ODR&=~(1<<pinNumber));
}
void GPIO_Set_Port(GPIOx_RegDef *pGPIOx,uint16_t value)
{
	pGPIOx->ODR=value;
}
void GPIO_TooglePin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber)
{
	pGPIOx->ODR ^= (1 << pinNumber);
}
/*
 *	GPIO interrupts
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPiority,uint8_t on_off);
void GPIO_IRQHandler(uint8_t pinNumber);

