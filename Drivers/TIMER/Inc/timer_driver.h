/**
 * @file timer_driver.h
 * @brief Timer driver functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef TIMER_INC_TIMER_DRIVER_H_
#define TIMER_INC_TIMER_DRIVER_H_

#include "common.h"

/**
 * @brief Current tick count
 */
static u32 tickMsCounter;

/**
 * @brief System tick interrupt handler.
 * @details This function is called from the SysTick_Handler().
 */
void sysTick_Handler(void);

u32 getTickCounter();

#endif /* TIMER_INC_TIMER_DRIVER_H_ */
