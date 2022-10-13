/*
 * stm32f411x.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Dawid Zadlo
 */

#ifndef INC_STM32F411X_H_
#define INC_STM32F411X_H_
#include <stdint.h>
#include "stm32f411x_gpio.h"
/***************************************************************************
 *		 Macros for flash,SRAM and system memory, macros contain base adresses
 */
#define DRV_FLASH_BASE_ADR				0x0800000U
#define DRV_SRAM1_BASE_ADR				0x2000000U
#define DRV_SRAM_BASE_ADR				SRAM1_BASE_ADR //112kb
#define DRV_SYSTEM_BASE_ADR				0x1FFF0000U
#define DRV_SRAM2_BASE_ADR				0x20001C00U
#define DRV_RCC_BASE_ADR				0x40023800U

/***************************************************************************
 * 							Bus interfaces macros
 ***************************************************************************/

#define DRV_AHB2_BASE_ADR 				0x50000000U
#define DRV_AHB1_BASE_ADR				0x40020000U
#define DRV_APB2_BASE_ADR				0x40010000U
#define DRV_APB1_BASE_ADR				0x40000000U

/***************************************************************************
 *
 * 					Defines of GPIO and peripherial for buses
 * 							BUS_BASE_ADR + offset
 */

/****************************************************************************
 * 										AHB1
 ****************************************************************************/

#define DRV_GPIOA						(DRV_AHB1_BASE_ADR)// offset = 0
#define DRV_GPIOB						(DRV_AHB1_BASE_ADR+0x400)
#define DRV_GPIOC						(DRV_AHB1_BASE_ADR+0x800)
#define DRV_GPIOD						(DRV_AHB1_BASE_ADR+0xC00)
#define DRV_GPIOE						(DRV_AHB1_BASE_ADR+0x1000)
#define DRV_GPIOH						(DRV_AHB1_BASE_ADR+0x1C00)

typedef struct
{
	volatile uint32_t	MODER;
	volatile uint32_t	OTYPER;
	volatile uint32_t	OSPEEDR;
	volatile uint32_t	PUPDR;
	volatile uint32_t 	IDR:16;
	volatile uint32_t 	ODR:16;
	volatile uint32_t 	BSRR;
	volatile uint32_t 	LCKR:16;
	volatile uint32_t 	AFR[2];

}GPIOx_RegDef;

 GPIOx_RegDef *GPIOA    = ((GPIOx_RegDef*)DRV_GPIOA);
 GPIOx_RegDef *GPIOB	= ((GPIOx_RegDef*)DRV_GPIOB);
 GPIOx_RegDef *GPIOC	= ((GPIOx_RegDef*)DRV_GPIOC);
 GPIOx_RegDef *GPIOD	= ((GPIOx_RegDef*)DRV_GPIOD);
 GPIOx_RegDef *GPIOE	= ((GPIOx_RegDef*)DRV_GPIOE);
 GPIOx_RegDef *GPIOH	= ((GPIOx_RegDef*)DRV_GPIOH);


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
 }RCC_RegDef;


RCC_RegDef *RCC = (RCC_RegDef*)DRV_RCC_BASE_ADR;

#define RCC_GPIOA_EN()		RCC->RCC_AHB1ENR |= (1<<0)
#define RCC_GPIOB_EN()		RCC->RCC_AHB1ENR |= (1<<1)
#define RCC_GPIOC_EN()		RCC->RCC_AHB1ENR |= (1<<2)
#define RCC_GPIOD_EN()		RCC->RCC_AHB1ENR |= (1<<3)
#define RCC_GPIOE_EN()		RCC->RCC_AHB1ENR |= (1<<4)
#define RCC_GPIOH_EN()		RCC->RCC_AHB1ENR |= (1<<7)

#define RCC_GPIOA_DS()		RCC->RCC_AHB1ENR &=~ (1<<0)
#define RCC_GPIOB_DS()		RCC->RCC_AHB1ENR &=~ (1<<1)
#define RCC_GPIOC_DS()		RCC->RCC_AHB1ENR &=~ (1<<2)
#define RCC_GPIOD_DS()		RCC->RCC_AHB1ENR &=~ (1<<3)
#define RCC_GPIOE_DS()		RCC->RCC_AHB1ENR &=~ (1<<4)
#define RCC_GPIOH_DS()		RCC->RCC_AHB1ENR &=~ (1<<7)

#define GPIOA_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<0); (RCC->RCC_AHB1RSTR &=~(1<<0));} while(0)
#define GPIOB_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<1); (RCC->RCC_AHB1RSTR &=~(1<<1));} while(0)
#define GPIOC_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<2); (RCC->RCC_AHB1RSTR &=~(1<<2));} while(0)
#define GPIOD_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<3); (RCC->RCC_AHB1RSTR &=~(1<<3));} while(0)
#define GPIOE_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<4); (RCC->RCC_AHB1RSTR &=~(1<<4));} while(0)
#define GPIOH_REG_RESET() 	do { RCC->RCC_AHB1RSTR |= (1<<5); (RCC->RCC_AHB1RSTR &=~(1<<5));} while(0)
/**************************************************************************
 * 										APB1
 **************************************************************************/
#define DRV_I2C1						(DRV_APB1_BASE_ADR+0x5400)
#define DRV_I2C2						(DRV_APB1_BASE_ADR+0x5800)
#define DRV_I2C3						(DRV_APB1_BASE_ADR+0x5C00)

#define DRV_USART2						(APB1_BASE_ADR+0x4400)

#define DRV_SPI3						(DRV_APB2_BASE_ADR+0x3C00)
#define DRV_SPI2						(DRV_APB2_BASE_ADR+0x3400)

/*
 * APB2
 */
#define DRV_USART1						(DRV_APB2_BASE_ADR+0x11000)
#define DRV_USART6						(DRV_APB2_BASE_ADR+0x1400)

#define DRV_SPI1						(DRV_APB2_BASE_ADR+0x3000)
#define DRV_SPI4						(DRV_APB2_BASE_ADR+0x3400)

#define DRV_EXTI						(DRV_APB2_BASE_ADR+0x3C00)
#define DRV_SYSCFG						(DRV_APB2_BASE_ADR+0x3800)

#define SET 1
#define RESET 0
#endif /* INC_STM32F411X_H_ */
