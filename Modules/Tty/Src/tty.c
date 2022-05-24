/**
 * @file tty.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "tty.h"

int _write(int file, char *ptr, int len) {
	// For the moment we only manage 1 as we only have one UART connected
	if (file != 1) {
		return -1;
	}

	for (int idx = 0; idx < len; idx++) {
		char c = *ptr++;
		tty_write(c);
		if (c == '\n') // We automatically add an \r after \n as the only use of write is to log via tty for the moment
			tty_write('\r');
	}
	return len;
}
