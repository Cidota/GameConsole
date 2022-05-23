/**
 * @file time.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "time.h"

u32 getTimeMs()
{
    return getTickCounter();
}
