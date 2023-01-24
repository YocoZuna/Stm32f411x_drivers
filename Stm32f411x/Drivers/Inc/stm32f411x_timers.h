/*
 * stm32f411x_timers.h
 *
 *  Created on: Jan 23, 2023
 *      Author: Dawid Zadlo
 */

#ifndef INC_STM32F411X_TIMERS_H_
#define INC_STM32F411X_TIMERS_H_
#include "stm32f411x.h"
#include <stdint.h>
#define CLEAR_SYSTEM_TIMER (*SYST_CSR  &=(uint32_t)0xFF000000)
#define RELOAD_SYSTEM_TIMER_VALUE(x) (*SYST_RVR = (*SYST_RVR & 0xFF000000U) | x )

typedef struct
{
	uint8_t enable;
	uint8_t ticinit;
	uint8_t clocksource;
}System_Timer_Config_TypeDef;

#define SYSTEM_TIMER_SOURCE_EXTERNAL 0
#define SYSTEM_TIMER_SOURCE_INTERNAL 1

#define SysTick  ((System_Timer_Config_TypeDef*)SYST_CSR)



void System_Delay(uint32_t ntime );

#endif /* INC_STM32F411X_TIMERS_H_ */
