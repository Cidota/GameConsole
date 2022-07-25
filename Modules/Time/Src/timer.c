/**
 * @file timer.c
 * @details Author: Dimitri Carlier | Created on: 25 juil. 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

Timer timerTab[NB_MAX_TIMER];
u8 nbTimerUsed = 0;

bool isTimerDone(u8 index){
	index = index-1; // index in the structure start from 1 allowing the return 0 at startTimer
	if(index < 0 || index >= nbTimerUsed){
		logDebug("Error in timer_driver.isTimerDone : index in parameters (%d) must be between 1 and %d.", index, nbTimerUsed);
		return false;
	}
	logDebug("endtick : %d | tickMsCounter : %d\n", timerTab[index].endTick, getTimeMs());
	return timerTab[index].endTick <= getTimeMs();
}

// resetTimer - reset a timer and if another one is used, let's switch with the last in the tab
void resetTimer(u8 index){
	index = index-1; // index in the structure start from 1 allowing the return 0 at startTimer
	if(index < 0 || index >= nbTimerUsed){
		logDebug("Error in timer_driver.resetTimer : index in parameters (%d) must be between 1 and %d.", index, nbTimerUsed);
		return;
	}
	if(nbTimerUsed != 0 && index != nbTimerUsed){
		timerTab[index].endTick = timerTab[nbTimerUsed].endTick;
		timerTab[index].index = timerTab[nbTimerUsed].index;
	}
	if(nbTimerUsed != 0)
		nbTimerUsed--;
}

u8 getNbTimers(void){
	return nbTimerUsed;
}

// Should return the timer index between 1 and NB_MAX_TIER
u8 startTimer(u32 delayInMs){
	if(nbTimerUsed >= NB_MAX_TIMER){
		logDebug("Error in timer_driver.startTimer : only %d timers can be used at the same time.", NB_MAX_TIMER);
		return 0;
	}

	u8 timerIndex = nbTimerUsed;
	timerTab[timerIndex].endTick = delayInMs + getTimeMs();
	timerTab[timerIndex].index = timerIndex;
	nbTimerUsed++;
	return nbTimerUsed;
}

void initTimers(){
	for(u8 i; i<NB_MAX_TIMER; i++){
		timerTab[i] = (Timer){i, 0};
	}
}
