/**
 * @file tty_driver.h
 * @brief Teletypewriter driver functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef TTY_INC_TTY_DRIVER_H_
#define TTY_INC_TTY_DRIVER_H_

#include "common.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "stm32l4xx_ll_usart.h"

void tty_open();
void tty_write(char c);

#endif /* TTY_INC_TTY_DRIVER_H_ */
