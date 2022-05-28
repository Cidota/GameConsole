/**
 * @file snake_game_image.h
 * @brief Snake game images.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __SNAKE_GAME_IMAGES_H__
#define __SNAKE_GAME_IMAGES_H__

#include "imageBase.h"

/** Width of the snake head image */
#define SNAKE_TILE_WIDTH 34
/** Height of the snake head image */
#define SNAKE_TILE_HEIGHT 34

/** Name of the solo snake head image oriented up */
#define SNAKE_HEAD_SOLO_UP "SNAKE_HEAD_SOLO_UP"
/** Name of the solo snake head image oriented down */
#define SNAKE_HEAD_SOLO_DOWN "SNAKE_HEAD_SOLO_DOWN"
/** Name of the solo snake head image oriented left */
#define SNAKE_HEAD_SOLO_LEFT "SNAKE_HEAD_SOLO_LEFT"
/** Name of the solo snake head image oriented right */
#define SNAKE_HEAD_SOLO_RIGHT "SNAKE_HEAD_SOLO_RIGHT"

/** Name of the snake head image oriented up */
#define SNAKE_HEAD_UP "SNAKE_HEAD_UP"
/** Name of the snake head image oriented down */
#define SNAKE_HEAD_DOWN "SNAKE_HEAD_DOWN"
/** Name of the snake head image oriented left */
#define SNAKE_HEAD_LEFT "SNAKE_HEAD_LEFT"
/** Name of the snake head image oriented right */
#define SNAKE_HEAD_RIGHT "SNAKE_HEAD_RIGHT"

/** Name of the snake tail image oriented up */
#define SNAKE_TAIL_UP "SNAKE_TAIL_UP"
/** Name of the snake tail image oriented down */
#define SNAKE_TAIL_DOWN "SNAKE_TAIL_DOWN"
/** Name of the snake tail image oriented left */
#define SNAKE_TAIL_LEFT "SNAKE_TAIL_LEFT"
/** Name of the snake tail image oriented right */
#define SNAKE_TAIL_RIGHT "SNAKE_TAIL_RIGHT"

/** Name of the snake body curved up left image */
#define SNAKE_BODY_CURVE_UP_LEFT "SNAKE_BODY_CURVE_UP_LEFT"
/** Name of the snake body curved up right image */
#define SNAKE_BODY_CURVE_UP_RIGHT "SNAKE_BODY_CURVE_UP_RIGHT"
/** Name of the snake body curved down left image */
#define SNAKE_BODY_CURVE_DOWN_LEFT "SNAKE_BODY_CURVE_DOWN_LEFT"
/** Name of the snake body curved down right image */
#define SNAKE_BODY_CURVE_DOWN_RIGHT "SNAKE_BODY_CURVE_DOWN_RIGHT"

/** Name of the snake body horizontal image */
#define SNAKE_BODY_HORIZONTAL "SNAKE_BODY_HORIZONTAL"
/** Name of the snake body vertical image */
#define SNAKE_BODY_VERTICAL "SNAKE_BODY_VERTICAL"
/** Name of the apple image */
#define SNAKE_APPLE "SNAKE_APPLE"

extern const tileMapTile snakeTiles[];
extern const tileMap snakeTilemap;
extern const u16 SnakeTilemap[];

#endif // __SNAKE_GAME_IMAGES_H__
