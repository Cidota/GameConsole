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
u32 getTimeMs();

#endif // __TIME_H__