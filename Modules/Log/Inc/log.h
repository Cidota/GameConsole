/**
 * @file log.h
 * @brief Log functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __LOG_H__
#define __LOG_H__

#include <stdbool.h>

#include "common.h"

/**
 * @brief Different log levels possible.
 **/
typedef enum {
	LOG_OFF = 0, /**< no logs */
	LOG_ERROR = 1, /**< error logs only */
	LOG_DEBUG = 2, /**< error and debug logs */
	LOG_DEFAULT = LOG_ERROR /**< by default we have a log level of error */
} loglevel;

/**
 * @brief Toggles whether logging is active.
 **/
void toggleLog(void);

/**
 * @brief Gets the state of the the log.
 * @return true if the log is active or false otherwise
 **/
bool getLogActive(void);

/**
 * @brief Prints a log.
 * @details Function only to be used internally. Use the log_* functions instead, where * can be error or debug.
 * @param format the formatted string
 **/
void log_printf(const char *format, ...);

/**
 * @brief Log an error
 * @param fmt the formatted string
 **/
#define logError(fmt, ...)                          \
    do                                              \
    {                                               \
        if (log_active && log_level >= LOG_ERROR)    \
            log_printf("ERR  " fmt, ##__VA_ARGS__); \
    } while (0)
/**
 * @brief Log an debug message
 * @param fmt the formatted string
 **/
#define logDebug(fmt, ...)                          \
    do                                              \
    {                                               \
        if (log_active && log_level >= LOG_DEBUG)    \
            log_printf("DBG  " fmt, ##__VA_ARGS__); \
    } while (0)

// Following variable is global to allow efficient access by macros,
// but is considered private.
extern bool log_active;
extern loglevel log_level;

#endif // __LOG_H__
