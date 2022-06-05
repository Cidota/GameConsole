/**
 * @file log.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "log.h"

#include <stdarg.h>
#include <stdio.h>

#include "time.h"

bool log_active = true;

/**
 * @brief The current log level, will affect what logs are printed.
 **/
loglevel log_level = LOG_DEBUG;

void toggleLog(void) {
	log_active = log_active ? false : true;
}

bool getLogActive(void) {
	return log_active;
}

void log_printf(const char *format, ...) {
	va_list args;
	u32 ms = getTimeMs();

	printf("%lu.%03lu ", ms / 1000U, ms % 1000U);
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
