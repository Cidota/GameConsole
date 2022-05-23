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

// These functions are temp for writing to UART2

static bool create_stream = true;
static bool send_cr_after_nl = true;
static USART_TypeDef *uart_reg_base = USART2;
static uint16_t tx_buf_get_idx = 0;
static uint16_t tx_buf_put_idx = 0;
static char tx_buf[1024];

void tty_open();
void tty_write(char c);

#endif /* TTY_INC_TTY_DRIVER_H_ */
