/*
 * lcd.h
 *
 *  Created on: 21 May 2022
 *      Author: talei
 */

#ifndef LCD_INC_LCD_H_
#define LCD_INC_LCD_H_

#include "common.h"
#include "image.h"
#include "main.h"

#define USE_HORIZONTAL		0
#define LCD_USE8BIT_MODEL   1

#define LCD_W 320
#define LCD_H 480

#define LCD_SET_X_CMD 0x2A
#define LCD_SET_Y_CMD 0x2B
#define LCD_WRITE_GRAM_CMD 0x2C

#define	LCD_CS_SET  LL_GPIO_SetOutputPin(LCD_CS_A3_GPIO_Port, LCD_CS_A3_Pin)
#define	LCD_RS_SET	LL_GPIO_SetOutputPin(LCD_RS_A2_GPIO_Port, LCD_RS_A2_Pin)
#define	LCD_RST_SET	LL_GPIO_SetOutputPin(LCD_RST_A4_GPIO_Port, LCD_RST_A4_Pin)
#define	LCD_WR_SET	LL_GPIO_SetOutputPin(LCD_WR_A1_GPIO_Port, LCD_WR_A1_Pin)
#define LCD_RD_SET  LL_GPIO_SetOutputPin(LCD_RD_A0_GPIO_Port, LCD_RD_A0_Pin)

#define	LCD_CS_CLR  LL_GPIO_ResetOutputPin(LCD_CS_A3_GPIO_Port, LCD_CS_A3_Pin)
#define	LCD_RS_CLR	LL_GPIO_ResetOutputPin(LCD_RS_A2_GPIO_Port, LCD_RS_A2_Pin)
#define	LCD_RST_CLR	LL_GPIO_ResetOutputPin(LCD_RST_A4_GPIO_Port, LCD_RST_A4_Pin)
#define	LCD_WR_CLR	LL_GPIO_ResetOutputPin(LCD_WR_A1_GPIO_Port, LCD_WR_A1_Pin)
#define LCD_RD_CLR  LL_GPIO_ResetOutputPin(LCD_RD_A0_GPIO_Port, LCD_RD_A0_Pin)

void SetDataOut(u8 data);
void LCDWrite(u8 data);
void LCDWrite16Bit(u16 data);
void LCDWriteCommand(u8 data);
void LCDWriteData(u8 data);
void LCDSetWindow(u16 xStart, u16 yStart, u16 xEnd, u16 yEnd);
void LCDBitmap(u16 sx, u16 sy, u16 ex, u16 ey, u16* bitmap);
void LCDFill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);
void LCDClear(u16 Color);
void LCDReset();
void LCDInit();

#endif /* LCD_INC_LCD_H_ */
