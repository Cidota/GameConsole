/**
 * @file timer.h
 * @brief Timer library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __TIMER_H__
#define __TIMER_H__
#define NB_MAX_TIMER 5

#include "time.h"
#include "log.h"
#include <stdbool.h>


/** @struct Timer
 *  @brief Timer structure
 *  @var Timer::index
 *  Member 'index' contains the index given with the timer.startTimer function
 *  @var Timer::endTick
 *  Member 'endTick' contains the last tick where the Timer isn't done.
 */
typedef struct {
	u8 index;
	u32 endTick;
} Timer;

/**
 * @brief Starts a timer.
 * @param count the time to count down in ms
 * @return 0 if no timer is free, and the index otherwise (index start from 1 and it's like an ID, store it)
 **/
u8 startTimer(u32 delayInMs);

/**
 * @brief Gets the status of the timer
 * @return True if the timer is done and false otherwise
 **/
bool isTimerDone(u8 index);

/**
 * @brief Reset a timer
 * @param the timer index
 **/
void resetTimer(u8 index);

/**
 * @brief Initialize all timers, must be called at the beginning before startTimer.
 **/
void initTimers();

/**
 * @brief Gets the number of timers used
 * @return The number of timers used
 **/
u8 getNbTimers(void);

#endif // __TIMER_H__
