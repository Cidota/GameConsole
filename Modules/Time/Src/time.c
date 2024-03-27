/**
 * @file time.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "time.h"


u32 lastFrameUpdate = 0;
u32 deltaTime = 0;

u32 getTimeMs(void)
{
    return getTickCounter();
}

void updateFrameTime(void){
	if(lastFrameUpdate != 0)
		deltaTime = getTimeMs() - lastFrameUpdate;
	lastFrameUpdate = getTimeMs();
}

u32 getDeltaTime(void){
	return deltaTime;
}
