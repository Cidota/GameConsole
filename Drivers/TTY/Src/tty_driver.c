/**
 * @file tty_driver.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "tty_driver.h"

static u16 tx_buf_get_idx = 0;
static u16 tx_buf_put_idx = 0;
static char tx_buf[1024];

void tty_open()
{
    memset(&tx_buf, 0, sizeof(tx_buf));
    LL_USART_EnableIT_TXE(USART2);
    NVIC_SetPriority(USART2_IRQn,
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(USART2_IRQn);
}

void tty_write(char c)
{
    uint16_t next_put_idx;

    next_put_idx = tx_buf_put_idx + 1;
    if (next_put_idx >= 1024)
        next_put_idx = 0;

    while (next_put_idx == tx_buf_get_idx)
    {
        return;
    }

    tx_buf[tx_buf_put_idx] = c;
    tx_buf_put_idx = next_put_idx;

    // Ensure the TX interrupt is enabled.
    if (USART2 != NULL)
    {
        __disable_irq();
        LL_USART_EnableIT_TXE(USART2);
        __enable_irq();
    }
}



static void ttys_interrupt(IRQn_Type irq_type)
{
    uint8_t sr;

    // If instance is not open, we should not get an interrupt, but for safety
    // just disable it.
    if (USART2 == NULL)
    {
        NVIC_DisableIRQ(irq_type);
        return;
    }

    sr = USART2->ISR;

    if (sr & LL_USART_ISR_TXE)
    {
        // Can send a character.
        if (tx_buf_get_idx == tx_buf_put_idx)
        {
            // No characters to send, disable the interrupt.
            LL_USART_DisableIT_TXE(USART2);
        }
        else
        {
        	USART2->TDR = tx_buf[tx_buf_get_idx];
            if (tx_buf_get_idx < 1024 - 1)
                tx_buf_get_idx++;
            else
                tx_buf_get_idx = 0;
        }
    }
    if (sr & (LL_USART_ISR_ORE | LL_USART_ISR_NE | LL_USART_ISR_FE |
              LL_USART_ISR_PE))
    {

        // Error conditions. To clear the bit, we need to read the data
        // register, but we don't use it.

    	USART2->ICR = sr & 0xf;
    }
}

void USART2_IRQHandler(void)
{
    ttys_interrupt(USART2_IRQn);
}
