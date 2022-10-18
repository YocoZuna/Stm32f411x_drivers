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

/*
 * Interrupt port
 */
#define PA						0
#define PB 						1
#define PC 						2
#define PD 						3
#define PE 						4
#define PH 						5

 typedef struct
 {
 	volatile uint32_t	MODER;
 	volatile uint32_t	OTYPER;
 	volatile uint32_t	OSPEEDR;
 	volatile uint32_t	PUPDR;
 	volatile uint32_t 	IDR;
 	volatile uint32_t 	ODR;
 	volatile uint32_t 	BSRR;
 	volatile uint32_t 	LCKR;
 	volatile uint32_t 	AFR[2];

 }GPIOx_RegDef;

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
	GPIOx_RegDef *pGPIOx;
	GPIOx_PinConfig_t GPIO_PinConfig;
}GPIOx_Handle_t;

typedef struct
{
	 volatile uint32_t RCC_CR;
	 volatile uint32_t RCC_PLLCFGR;
	 volatile uint32_t RCC_CFGR;
	 volatile uint32_t RCC_CIR;
	 volatile uint32_t RCC_AHB1RSTR;
	 volatile uint32_t RCC_AHB2RSTR;
	 const uint32_t RESERVED[2];
	 volatile uint32_t RCC_APB1RSTR;
	 volatile uint32_t RCC_APB2RSTR;
	 const uint32_t RESERVED1[2];
	 volatile uint32_t RCC_AHB1ENR;
	 volatile uint32_t RCC_AHB2ENR;
	 const uint32_t RESERVED2[2];
	 volatile uint32_t RCC_APB1ENR;
	 volatile uint32_t RCC_APB2ENR;
}RCC_RegDef;

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef;

typedef struct
{
	volatile uint32_t MEMRRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTIR[4];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef;


#define GPIOA ((GPIOx_RegDef*)DRV_GPIOA)
#define GPIOB ((GPIOx_RegDef*)DRV_GPIOB)
#define GPIOC ((GPIOx_RegDef*)DRV_GPIOC)
#define GPIOD ((GPIOx_RegDef*)DRV_GPIOD)
#define GPIOE ((GPIOx_RegDef*)DRV_GPIOE)
#define GPIOH ((GPIOx_RegDef*)DRV_GPIOH)

#define RCC  ((RCC_RegDef*)DRV_RCC_BASE_ADR)

#define EXTI ((EXTI_RegDef*)DRV_EXTI)

#define SYSCFG  ((SYSCFG_RegDef*)DRV_SYSCFG)
/*
 * GIO clock
 */
void GPIO_RCC(GPIOx_RegDef *pGPIOx, uint8_t on_off);

/*
 * GPIO initialization
 */
void GPIO_Init(GPIOx_Handle_t *GPIO);
void GPIO_DeInit(GPIOx_RegDef *GPIO);

/*
 * Reading and sending to GPIO
 */
uint8_t GPIO_ReadPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber);
uint16_t GPIO_ReadPort(GPIOx_RegDef *pGPIOx);
void GPIO_SetPin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber,uint8_t on_off);
void GPIO_Set_Port(GPIOx_RegDef *pGPIOx,uint16_t value);
void GPIO_TooglePin(GPIOx_RegDef *pGPIOx,uint8_t pinNumber);

/*
 *	GPIO interrupts
 */
void GPIO_IRQ_IT_Config(uint8_t IRQNumber,uint8_t on_off);
void GPIO_IRQHandler(uint8_t pinNumber);
void GPIO_IRQ_Priority(uint8_t IRQNumber,uint8_t priority);
#endif
/* INC_STM32F411X_GPIO_H_*/
