/**
 * @file timer.h
 * @brief Timer library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __TIMER_H__
#define __TIMER_H__

/**
 * @brief Starts a timer.
 * @param count the time to count down in ms
 **/
void startTimer(int count);

/**
 * @brief Gets the status of the timer
 * @return True if the timer is done and false otherwise
 **/
bool getTimerDone();

#endif // __TIMER_H__