/**
 * @file graphics.h
 * @brief Graphics library for displaying information.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <string.h>

#include "common.h"
#include "lcd.h"
#include "log.h"

#define CHARACTER_WIDTH 20
#define CHARACTER_HEIGHT 33

/**
 * @brief Get the screen height.
 * @return the height of the screen
 **/
uint getScreenHeight();

/**
 * @brief Get the screen width.
 * @return the width of the screen
 **/
uint getScreenWidth();

/**
 * @brief Draw a pixel.
 * @param x the x-coordinate of the pixel
 * @param y the x-coordinate of the pixel
 * @param color the color of the pixel
 * @pre @p x < display width
 * @pre @p y < display height
 **/
// void drawPixel(uint x, uint y, u16 color);

/**
 * @brief Draw a rectangle.
 * @details The rectangle's top left corner is the point (x, y) and is filled.
 * @param x the x-coordinate of the top left corner of the rectangle
 * @param y the x-coordinate of the top left corner of the rectangle
 * @param height the height of the rectangle
 * @param width the width of the rectangle
 * @param color the color of the rectangle
 * @pre @p x < display width
 * @pre @p y < display height
 **/
void drawRectangle(uint x, uint y, uint height, uint width, u16 color);

/**
 * @brief Draw a horizontal line.
 * @details The line starts at point (x, y) and extends horizontally to the right.
 * @param x the x-coordinate of the left end of the line
 * @param y the x-coordinate of the left end of the line
 * @param length the length of the line
 * @param color the color of the line
 * @pre @p x < display width
 * @pre @p y < display height
 **/
// void drawHorizontalLine(uint x, uint y, uint length, u16 color);

/**
 * @brief Draw a vertical line.
 * @details The line starts at point (x, y) and extends vertically downwards.
 * @param x the x-coordinate of the top end of the line
 * @param y the x-coordinate of the top end of the line
 * @param length the length of the line
 * @param color the color of the line
 * @pre @p x < display width
 * @pre @p y < display height
 **/
// void drawVerticalLine(uint x, uint y, uint length, u16 color);

/**
 * @brief Draw a bitmap image.
 * @details The images's top left corner is the point (x, y).
 * @param x the x-coordinate of the top left corner of the image
 * @param y the y-coordinate of the top left corner of the image
 * @param height the height of the image
 * @param width the width of the image
 * @param bitmap the image as a bitmap
 * @pre @p x < display width
 * @pre @p y < display height
 **/
void drawBitmap(uint x, uint y, uint height, uint width, u16 *bitmap);

/**
 * @brief Draw number.
 * @param x the x-coordinate of the top left corner of the number
 * @param y the y-coordinate of the top left corner of the number
 * @param number the number to draw
 * @param backgroundColor the background color of the number
 * @param numberColor the color of the number
 * @pre @p x < display width
 * @pre @p y < display height
 **/
void drawNumber(uint x, uint y, uint number, u16 backgroundColor, u16 numberColor);

#endif // __GRAPHICS_H__
