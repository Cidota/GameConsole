/**
 * @file tty_driver.c
 * @details Author: Taleiven Kattan | Created on: 20th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "tty_driver.h"

// The circular buffer for the UART communication
static char txBuffer[1024];
// The position from which we will get the char
static u16 txBufferGetPos = 0;
// The position where we will place the char
static u16 txBufferPutPos = 0;

void tty_open() {
	// Initialise the buffer to 0
	memset(&txBuffer, 0, sizeof(txBuffer));

	// Enable USART2 and sets the interrupts and their priority
	LL_USART_EnableIT_TXE(USART2);
	NVIC_SetPriority(USART2_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
	NVIC_EnableIRQ(USART2_IRQn);
}

void tty_write(char c) {
	uint16_t nextPutIdx;

	// Get the next put id and check it is not greater then max value
	nextPutIdx = txBufferPutPos + 1;
	if (nextPutIdx >= 1024)
		nextPutIdx = 0; // Circle back to start if we have reached end of buffer

	// Return as we have filled the buffer and cannot add any more data
	while (nextPutIdx == txBufferGetPos) {
		return;
	}

	// Set the value in the buffer and the put pos
	txBuffer[txBufferPutPos] = c;
	txBufferPutPos = nextPutIdx;

	// Ensure the TX interrupt is enabled.
	if (USART2 != NULL) {
		__disable_irq();
		LL_USART_EnableIT_TXE(USART2);
		__enable_irq();
	}
}

static void ttys_interrupt(IRQn_Type irq_type) {
	u8 interruptStatusRegister;

	// If instance is not open, we should not get an interrupt, but for safety
	// just disable it.
	if (USART2 == NULL) {
		NVIC_DisableIRQ(irq_type);
		return;
	}

	interruptStatusRegister = USART2->ISR;

	// Can send a character.
	if (interruptStatusRegister & LL_USART_ISR_TXE) {
		// No characters to send, disable the interrupt.
		if (txBufferGetPos == txBufferPutPos) {
			LL_USART_DisableIT_TXE(USART2);
		} else {
			// Set the Transmit Data Resister with the character
			USART2->TDR = txBuffer[txBufferGetPos];
			if (txBufferGetPos < 1024 - 1) // Set new get value for the buffer
				txBufferGetPos++;
			else
				txBufferGetPos = 0; // Circle to start
		}
	}
	if (interruptStatusRegister
			& (LL_USART_ISR_ORE | LL_USART_ISR_NE | LL_USART_ISR_FE |
			LL_USART_ISR_PE)) {

		// Error conditions. To clear the bit, we need to read the data
		// register, but we don't use it.
		USART2->ICR = interruptStatusRegister & 0xf;
	}
}

void USART2_IRQHandler(void) {
	ttys_interrupt(USART2_IRQn);
}
