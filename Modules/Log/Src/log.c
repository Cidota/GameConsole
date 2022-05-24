/**
 * @file log.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "log.h"

#include <stdarg.h>
#include <stdio.h>

#include "time.h"

bool logActive = true;

void toggleLog(void)
{
    logActive = logActive ? false : true;
}

bool getLogActive(void)
{
    return logActive;
}

void log_printf(const char *format, ...)
{
    va_list args;
    u32 ms = getTimeMs();

    printf("%lu.%03lu ", ms / 1000U, ms % 1000U);
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
