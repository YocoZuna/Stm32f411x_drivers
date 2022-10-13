/*
 * stm32f411x_gpio.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Dawid Zadlo
 */
#ifndef INC_STM32F411X_GPIO_H_
#define INC_STM32F411X_GPIO_H_
#include <stdint.h>
#include "stm32f411x.h"

/*
 * Modes of GPIO
 */
#define GPIO_MODE_INPUT  	 	0
#define GPIO_MODE_OUT 		 	1
#define GPIO_MODE_ALF		 	2
#define GPIO_MODE_ANALOG 	 	3
#define GPIO_MODE_IT_FALLING 	4
#define GPIO_MODE_IT_RISING  	5
#define GPIO_MODE_IT_FT_TRIGGER 6

/*
 * Output configuration
 */
#define GPIO_OUTPUT_PP			0
#define GPIO_OUTPUT_OD			1

/*
 * GPIO speed
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*
 * Pull Up-Down configuration
 */
#define GPIO_PULL_NONE			0
#define GPIO_PULL_HIGH			1
#define GPIO_PULL_LOW			2

typedef struct
{
	uint8_t pinNumber;
	uint8_t pinMode;
	uint8_t pinSpeed;
	uint8_t pinPuPd;
	uint8_t pinOType;
	uint8_t pinAltFun;
}GPIOx_PinConfig_t;

typedef struct
{
	GPIOx_RegDef* pGPIOx;
	GPIOx_PinConfig_t GPIO_PinConfig;
}GPIOx_Handle_t;


/*
 * GIO clock
 */
void GPIO_RCC(GPIOx_RegDef *pGPIOx, uint8_t on_off);

/*
 * GPIO initialization
 */
void GPIO_Init(GPIOx_Handle_t *GPIO);
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

#endif
/* INC_STM32F411X_GPIO_H_*/
