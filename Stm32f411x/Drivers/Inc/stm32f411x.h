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
#include "stm32f411x_spi.h"
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
#define DRV_APB2_BASE_ADR				(0x40010000U)
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

/*
 * 						GPIO
 */

#define RCC_GPIOA_EN()		RCC->RCC_AHB1ENR |= (1<<0)
#define RCC_GPIOB_EN()		RCC->RCC_AHB1ENR |= (1<<1)
#define RCC_GPIOC_EN()		RCC->RCC_AHB1ENR |= (1<<2)
#define RCC_GPIOD_EN()		RCC->RCC_AHB1ENR |= (1<<3)
#define RCC_GPIOE_EN()		RCC->RCC_AHB1ENR |= (1<<4)
#define RCC_GPIOH_EN()		RCC->RCC_AHB1ENR |= (1<<7)
#define RCC_SYSCFG_EN()		RCC->RCC_APB2ENR |= (1<<14)


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
 * 											SPI
 **************************************************************************/

#define RCC_SPI1_EN()		RCC->RCC_APB2ENR |= (1<<12)
#define RCC_SPI2_EN()		RCC->RCC_APB1ENR |= (1<<14)
#define RCC_SPI3_EN()		RCC->RCC_APB1ENR |= (1<<15)
#define RCC_SPI4_EN()		RCC->RCC_APB2ENR |= (1<<13)



#define RCC_SPI1_DS()		RCC->RCC_AHB1ENR &=~ (1<<0)
#define RCC_SPI2_DS()		RCC->RCC_AHB1ENR &=~ (1<<14)
#define RCC_SPI3_DS()		RCC->RCC_AHB1ENR &=~ (1<<14)
#define RCC_SPI4_DS()		RCC->RCC_AHB1ENR &=~ (1<<3)


#define SPI1_REG_RESET() 	do { RCC->RCC_APB2RSTR |= (1<<12); (RCC->RCC_APB2RSTR &=~(1<<12));} while(0)
#define	SPI2_REG_RESET() 	do { RCC->RCC_APB1RSTR |= (1<<14); (RCC->RCC_APB1RSTR &=~(1<<14));} while(0)
#define SPI3_REG_RESET() 	do { RCC->RCC_APB1RSTR |= (1<<15); (RCC->RCC_APB1RSTR &=~(1<<15));} while(0)
#define SPI4_REG_RESET() 	do { RCC->RCC_APB2RSTR |= (1<<13); (RCC->RCC_APB2RSTR &=~(1<<13));} while(0)


/**************************************************************************
 * 										APB1
 **************************************************************************/
#define DRV_I2C1						(DRV_APB1_BASE_ADR+0x5400)
#define DRV_I2C2						(DRV_APB1_BASE_ADR+0x5800)
#define DRV_I2C3						(DRV_APB1_BASE_ADR+0x5C00)

#define DRV_USART2						(APB1_BASE_ADR+0x4400)

#define DRV_SPI3						(DRV_APB2_BASE_ADR+0x3C00)
#define DRV_SPI2						(DRV_APB1_BASE_ADR+0x3800)

/*
 * APB2
 */
#define DRV_USART1						(DRV_APB2_BASE_ADR+0x11000)
#define DRV_USART6						(DRV_APB2_BASE_ADR+0x1400)

#define DRV_SPI1						(DRV_APB2_BASE_ADR+0x3000)
#define DRV_SPI4						(DRV_APB2_BASE_ADR+0x3400)

#define DRV_EXTI						(DRV_APB2_BASE_ADR+0x3C00)
#define DRV_SYSCFG						(DRV_APB2_BASE_ADR+0x3800)


#define NVIC_ISER0						((uint32_t*)0xE000E100)
#define NVIC_ISER1						((uint32_t*)0xE000E104)
#define NVIC_ISER2						((uint32_t*)0xE000E108)
#define NVIC_ISER3						((uint32_t*)0xE000E10C)


#define NVIC_ICER0						((uint32_t*)0xE000E180)
#define NVIC_ICER1						((uint32_t*)0xE000E184)
#define NVIC_ICER2						((uint32_t*)0xE000E188)
#define NVIC_ICER3						((uint32_t*)0xE000E18C)

#define NVIC_IPR0						((uint32_t*)0xE000E400)
#define NVIC_IPR1						((uint32_t*)0xE000E404)
#define NVIC_IPR2						((uint32_t*)0xE000E408)
#define NVIC_IPR3						((uint32_t*)0xE000E40C)

#define WHICH_GPIO_PORT(x)				(	(x==GPIOA) ? PA :\
											(x==GPIOB) ? PB :\
											(x==GPIOC) ? PC :\
											(x==GPIOD) ? PD :\
											(x==GPIOE) ? PE :\
											(x==GPIOH) ? PH :0)




#define SET 1
#define RESET 0
#endif /* INC_STM32F411X_H_ */
