/**
 * @file timer_driver.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "timer_driver.h"

void sysTick_Handler(void)
{
	tickMsCounter++;
}

u32 getTickCounter(){
	return tickMsCounter;
}
