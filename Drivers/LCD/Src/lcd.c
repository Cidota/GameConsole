/*
 * lcd.c
 *
 *  Created on: 21 May 2022
 *      Author: talei
 */
#include "lcd.h"
#include "stm32l4xx_ll_gpio.h"

static u8 currentData;

void SetDataOut(u8 data) {
	if (data != currentData) {
		// Get first bit of data and set it
		if (data & 0x1)
			LL_GPIO_SetOutputPin(LDC_D0_D8_GPIO_Port, LDC_D0_D8_Pin);
		else
			LL_GPIO_ResetOutputPin(LDC_D0_D8_GPIO_Port, LDC_D0_D8_Pin);

		// Get second bit of data and set it
		if (data & 0x2)
			LL_GPIO_SetOutputPin(LCD_D1_D9_GPIO_Port, LCD_D1_D9_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D1_D9_GPIO_Port, LCD_D1_D9_Pin);

		// Get third bit of data and set it
		if (data & 0x4)
			LL_GPIO_SetOutputPin(LCD_D2_D2_GPIO_Port, LCD_D2_D2_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D2_D2_GPIO_Port, LCD_D2_D2_Pin);

		// Get fourth bit of data and set it
		if (data & 0x8)
			LL_GPIO_SetOutputPin(LCD_D3_D3_GPIO_Port, LCD_D3_D3_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D3_D3_GPIO_Port, LCD_D3_D3_Pin);

		// Get fifth bit of data and set it
		if (data & 0x10)
			LL_GPIO_SetOutputPin(LCD_D4_D4_GPIO_Port, LCD_D4_D4_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D4_D4_GPIO_Port, LCD_D4_D4_Pin);

		// Get sixth bit of data and set it
		if (data & 0x20)
			LL_GPIO_SetOutputPin(LCD_D5_D5_GPIO_Port, LCD_D5_D5_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D5_D5_GPIO_Port, LCD_D5_D5_Pin);

		// Get seventh bit of data and set it
		if (data & 0x40)
			LL_GPIO_SetOutputPin(LCD_D6_D6_GPIO_Port, LCD_D6_D6_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D6_D6_GPIO_Port, LCD_D6_D6_Pin);

		// Get eighth bit of data and set it
		if (data & 0x80)
			LL_GPIO_SetOutputPin(LCD_D7_D7_GPIO_Port, LCD_D7_D7_Pin);
		else
			LL_GPIO_ResetOutputPin(LCD_D7_D7_GPIO_Port, LCD_D7_D7_Pin);

		// update current data
		currentData = data;
	}
}

void LCDWrite(u8 data) {
	LCD_CS_CLR;
	SetDataOut(data);
	LCD_WR_CLR;
	LCD_WR_SET;
	LCD_CS_SET;
}

void LCDWrite16Bit(u16 data) {
	LCD_RS_SET;
	LCD_CS_CLR;
	SetDataOut(data);
	LCD_WR_CLR;
	LCD_WR_SET;
	SetDataOut(data >> 8);
	LCD_WR_CLR;
	LCD_WR_SET;
	LCD_CS_SET;
}

void LCDWriteCommand(u8 data) {
	LCD_RS_CLR;
	LCDWrite(data);
}

void LCDWriteData(u8 data) {
	LCD_RS_SET;
	LCDWrite(data);
}

void LCDSetWindow(u16 xStart, u16 yStart, u16 xEnd, u16 yEnd) {
	LCDWriteCommand(LCD_SET_X_CMD);
	LCDWriteData(xStart >> 8); // Start Column SC[15:8]
	LCDWriteData(0x00FF & xStart); // SC[7:0]
	LCDWriteData(xEnd >> 8); // End Column EC[15:8]
	LCDWriteData(0x00FF & xEnd); // EC[7:0]

	LCDWriteCommand(LCD_SET_Y_CMD);
	LCDWriteData(yStart >> 8); // Start Page SP[15:8]
	LCDWriteData(0x00FF & yStart); // SP[7:0]
	LCDWriteData(yEnd >> 8); // End Page EP[15:8]
	LCDWriteData(0x00FF & yEnd); // EP[7:0]

	LCDWriteCommand(LCD_WRITE_GRAM_CMD);
}

void LCDBitmap(u16 sx, u16 sy, u16 ex, u16 ey, u16 *bitmap) {
	u16 i, j;

	u16 width = ex - sx + 1;
	u16 height = ey - sy + 1;
	LCDSetWindow(sx, sy, ex, ey);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++)
			LCDWrite16Bit(bitmap[j + (i*width)]);
	}

	LCDSetWindow(0, 0, LCD_H - 1, LCD_W - 1);
}

void LCDFill(u16 sx, u16 sy, u16 ex, u16 ey, u16 color) {
	u16 i, j;

	u16 width = ex - sx + 1;
	u16 height = ey - sy + 1;
	LCDSetWindow(sx, sy, ex, ey);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++)
			LCDWrite16Bit(color);
	}
}

void LCDClear(u16 Color) {
	uint i;
	LCDSetWindow(0, 0, LCD_H - 1, LCD_W - 1);
	for (i = 0; i < LCD_W * LCD_H; i++)
		LCDWrite16Bit(Color);

}

void LCDReset() {
	LCD_RST_CLR;
	LL_mDelay(100);
	LCD_RST_SET;
	LL_mDelay(50);
}

void LCDInit() {
	LCDReset();
	LCD_RD_SET; // RD must be set high during most non-read operations
	//************* ILI9486**********//
	LCDWriteCommand(0xF1);
	LCDWriteData(0x36);
	LCDWriteData(0x04);
	LCDWriteData(0x00);
	LCDWriteData(0x3C);
	LCDWriteData(0X0F);
	LCDWriteData(0x8F);
	LCDWriteCommand(0xF2);
	LCDWriteData(0x18);
	LCDWriteData(0xA3);
	LCDWriteData(0x12);
	LCDWriteData(0x02);
	LCDWriteData(0XB2);
	LCDWriteData(0x12);
	LCDWriteData(0xFF);
	LCDWriteData(0x10);
	LCDWriteData(0x00);
	LCDWriteCommand(0xF8);
	LCDWriteData(0x21);
	LCDWriteData(0x04);
	LCDWriteCommand(0xF9);
	LCDWriteData(0x00);
	LCDWriteData(0x08);

	// Power Control 1
	LCDWriteCommand(0xC0);
	LCDWriteData(0x0d);
	LCDWriteData(0x0d);

	// Power Control 2
	LCDWriteCommand(0xC1);
	LCDWriteData(0x43);
	LCDWriteData(0x00);

	// Power Control 3
	LCDWriteCommand(0xC2);
	LCDWriteData(0x00);

	// Memory Access Control
	// Memory will be written left to right and BGH will be used instead of RGB
	LCDWriteCommand(0x36);
	LCDWriteData(0x08); //MY,MX,MV and ML = 0; BGR; MH = 0

	// Display Inversion Control
	// Disable Z-inversion
	LCDWriteCommand(0xB4);
	LCDWriteData(0x00); // DINV[1:0]

	// Display Function Control
	LCDWriteCommand(0xB6);
	LCDWriteData(0x02);
	LCDWriteData(0x02);
	LCDWriteData(0x3B);

	// VCOM Control
	LCDWriteCommand(0xC5);
	LCDWriteData(0x00);
	LCDWriteData(0x91);
	LCDWriteData(0x80);
	LCDWriteData(0x00);

	// PGAMCTRL(Positive Gamma Control)
	LCDWriteCommand(0xE0);
	LCDWriteData(0x0F);
	LCDWriteData(0x1F);
	LCDWriteData(0x1C);
	LCDWriteData(0x0C);
	LCDWriteData(0x0F);
	LCDWriteData(0x08);
	LCDWriteData(0x48);
	LCDWriteData(0x98);
	LCDWriteData(0x37);
	LCDWriteData(0x0A);
	LCDWriteData(0x13);
	LCDWriteData(0x04);
	LCDWriteData(0x11);
	LCDWriteData(0x0D);
	LCDWriteData(0x00);

	// NGAMCTRL(Negative Gamma Correction)
	LCDWriteCommand(0xE1);
	LCDWriteData(0x0F);
	LCDWriteData(0x32);
	LCDWriteData(0x2E);
	LCDWriteData(0x0B);
	LCDWriteData(0x0D);
	LCDWriteData(0x05);
	LCDWriteData(0x47);
	LCDWriteData(0x75);
	LCDWriteData(0x37);
	LCDWriteData(0x06);
	LCDWriteData(0x10);
	LCDWriteData(0x03);
	LCDWriteData(0x24);
	LCDWriteData(0x20);
	LCDWriteData(0x00);

	// Interface Pixel Format
	LCDWriteCommand(0x3A);
	LCDWriteData(0x55);

	// Memory Access Control
	LCDWriteCommand(0x36);
	LCDWriteData(0x28);

	// Sleep OUT
	LCDWriteCommand(0x11);

	LL_mDelay(120);

	// Display ON
	LCDWriteCommand(0x29);

	// Select orientation of screen
	// Landscape
	LCDWriteCommand(0x36);
	LCDWriteData(0x28);

	LCDClear(WHITE);
}
