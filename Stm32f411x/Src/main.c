/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include <stdint.h>
#include <string.h>
#include "stm32f411x.h"
#include "stm32f411x_gpio.h"
#include "stm32f411x_timers.h"

int main(void)
{

	/*

	*					Configuring GPIO for SPI alt function 5
	===================================================================================================
	*/


	RCC_GPIOA_EN();

	GPIOx_Handle_t LED;
	LED.pGPIOx = GPIOA;
	LED.GPIO_PinConfig.pinNumber = 5;
	LED.GPIO_PinConfig.pinMode = GPIO_MODE_OUT;
	LED.GPIO_PinConfig.pinOType = GPIO_OUTPUT_PP;
	LED.GPIO_PinConfig.pinPuPd = GPIO_PULL_NONE;
	LED.GPIO_PinConfig.pinSpeed = GPIO_SPEED_HIGH;


	GPIO_Init(&LED);




	while (1)
	{
		//SPI_Send_Polling(SPI2,(uint8_t*)userData,strlen(userData));
		GPIO_TooglePin(GPIOA, 5);
		System_Delay(5000);

	}



}
