/**
 * @file tty_driver.h
 * @brief Teletypewriter driver functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef TTY_INC_TTY_DRIVER_H_
#define TTY_INC_TTY_DRIVER_H_

#include "common.h"

#include "stm32l4xx_ll_usart.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/**
 * @brief Opens the driver for use.
 **/
void tty_open();

/**
 * @brief Writes a character to the buffer.
 * @param c the character to write to the buffer
 **/
void tty_write(char c);

#endif /* TTY_INC_TTY_DRIVER_H_ */
