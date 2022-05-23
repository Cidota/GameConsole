/*
 * tty.c
 *
 *  Created on: May 20, 2022
 *      Author: talei
 */

#include "tty.h"

int _write(int file, char *ptr, int len)
{
    if (file != 1)
    {
        return -1;
    }

    for (int idx = 0; idx < len; idx++)
    {
        char c = *ptr++;
        tty_write(c);
        if (c == '\n' && send_cr_after_nl)
        {
        	tty_write('\r');
        }
    }
    return len;
}
