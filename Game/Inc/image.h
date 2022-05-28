/**
 * @file image.h
 * @brief Image library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"
#include "imageBase.h"
#include "snake_game_image.h"

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


typedef enum sprite_type
{   
    SNAKE_HEAD_UP,
    SNAKE_HEAD_DOWN,
    SNAKE_HEAD_RIGHT,
    SNAKE_HEAD_LEFT,
    SNAKE_BODY_CURVE_UP_LEFT,
    SNAKE_BODY_CURVE_UP_RIGHT,
    SNAKE_BODY_CURVE_DOWN_LEFT,
    SNAKE_BODY_CURVE_DOWN_RIGHT,
    SNAKE_BODY_HORIZONTAL,
    SNAKE_BODY_VERTICAL,
    SNAKE_TAIL_LEFT,
    SNAKE_TAIL_RIGHT,
    SNAKE_TAIL_UP,
    SNAKE_TAIL_DOWN,
    SNAKE_HEAD_SOLO_DOWN,
    SNAKE_HEAD_SOLO_UP,
    SNAKE_HEAD_SOLO_RIGHT,
    SNAKE_HEAD_SOLO_LEFT,
    SNAKE_APPLE
} sprite_type;
/**
 * @brief Get an image bitmap from the name.
 **/
u16 *getImage(char *name);

/**
 * @brief Get an image height from the name.
 **/
uint getImageHeight(char *name);

/**
 * @brief Get an image width from the name.
 **/
uint getImageWidth(char *name);

#endif // __IMAGE_H__
