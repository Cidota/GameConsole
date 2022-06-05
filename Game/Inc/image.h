/**
 * @file image.h
 * @brief Image library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"
#include "snake_game_image.h"
#include "log.h"

#define BM_BLACK   0x0000
#define BM_BLUE    0x1818
#define BM_RED     0xE0E0
#define BM_GREEN   0x0707
#define BM_CYAN    0x7777
#define BM_MAGENTA 0xF8F8
#define BM_YELLOW  0xE7E7
#define BM_WHITE   0xFFFF
#define BM_LIGHT_GREY  0xB5B5
#define BM_DARK_GREY   0x6B6B
#define BM_PINK    0xF4F4
#define BM_ORANGE  0xE4E4

typedef enum colors
{
    BLACK = BM_BLACK,
    WHITE = BM_WHITE,
    YELLOW = BM_YELLOW,
    BLUE = BM_BLUE,
    RED = BM_RED,
    GREEN = BM_GREEN,
    ORANGE = BM_ORANGE,
    PINK = BM_PINK
} colors;

/**
 * @brief Get an image bitmap from the name.
 **/
u16 *getImage(sprite_type sprite);

/**
 * @brief Get an image height from the name.
 **/
uint getImageHeight(sprite_type sprite);

/**
 * @brief Get an image width from the name.
 **/
uint getImageWidth(sprite_type sprite);

#endif // __IMAGE_H__
