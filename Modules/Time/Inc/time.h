/**
 * @file time.h
 * @brief Time functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __TIME_H__
#define __TIME_H__

#include "common.h"
#include "timer_driver.h"

/**
 * @brief Gets the time in ms.
 * @return system tick value
 **/
u32 getTimeMs(void);

/**
 * @brief Gets the interval in milliseconds from the last frame to the current one.
 * @return The deltaTime between last frame and the current one.
 **/
u32 getDeltaTime(void);

/**
 * @brief Need to be set at the beginning of the main infinite loop. Update the delta between the last and the current frame.
 **/
void updateFrameTime(void);

#endif // __TIME_H__
