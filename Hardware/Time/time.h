/**
 * @file time.h
 * @brief Time functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __TIME_H__
#define __TIME_H__

#include "common.h"

/**
 * @brief Gets the time from the last frame to the current one.
 * @return The time since the last frame in ms.
 **/
uint getDeltaTime();

#endif // __TIME_H__