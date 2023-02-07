/*
 * stm32f411x_timers.c
 *
 *  Created on: Jan 23, 2023
 *      Author: Dawid Zadlo
 */


#include <stdint.h>

#include "stm32f411x_timers.h"
#include "stm32f411x.h"
uint32_t delay;


static void System_TimerPreInit(uint32_t reload)
{
	/********************* Reloading value egister********************/
	uint32_t*temp = SYST_RVR;
	*temp = ((*temp & (uint32_t)0xFF000000) | reload);
	/*****************************************************************/
	/********************* Restart current value *********************/
	temp = SYST_CVR;
	*temp &= (uint32_t)0xFF000000;
	/*****************************************************************/
	/********Setting ISR enable lock source and enabling systick******/
	SysTick->enable |= 7;
	*NVIC_ISER0 = (1<<6);
	/*****************************************************************/
}



void System_Delay(uint32_t ntime)
{
	delay = ntime;
	uint32_t sysclock  = (16000000/1000)-1; // 1ms
	System_TimerPreInit(sysclock);
	while(delay);

}

static void decrement(uint32_t time)
{

	if(time)
		time--;
}
void SysTick_Handler(void)
{
  decrement(delay);
}
