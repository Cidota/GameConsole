/*
 * graphics.c
 *
 *  Created on: May 20, 2022
 *      Author: Taleiven Kattan
 */
#include "graphics.h"
#include <stdio.h>


uint getScreenHeight(){
	return LCD_H;
}

uint getScreenWidth(){
	return LCD_W;
}

void drawRectangle(uint x, uint y, uint height, uint width, u16 color){
	LCDFill(x, y, x+height-1, y+width-1, color);
}

void drawBitmap(uint x, uint y, uint height, uint width, u16 *bitmap){
	LCDBitmap(x, y, x+width-1, y+height-1, bitmap);
}
