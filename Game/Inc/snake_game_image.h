/**
 * @file snake_game_image.h
 * @brief Snake game images.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __SNAKE_GAME_IMAGES_H__
#define __SNAKE_GAME_IMAGES_H__

#include "common.h"

/** Width of the snake tile image */
#define SNAKE_TILE_WIDTH 34
/** Height of the snake tile image */
#define SNAKE_TILE_HEIGHT 34
/** Width of the score text */
#define SNAKE_TEXT_SCORE_WIDTH 106
/** Height of the score text */
#define SNAKE_TEXT_SCORE_HEIGHT 33
/** Width of the press any button text */
#define SNAKE_TEXT_PAB_WIDTH 160
/** Height of the press any button text */
#define SNAKE_TEXT_PAB_HEIGHT 140
/** Width of the game over text */
#define SNAKE_TEXT_GO_WIDTH 160
/** Height of the game over text */
#define SNAKE_TEXT_GO_HEIGHT 70
/** Width of the high score text */
#define SNAKE_TEXT_HS_WIDTH 146
/** Height of the high score text */
#define SNAKE_TEXT_HS_HEIGHT 33


// I added this here to prevent a build error.
// As this will contain sprites from multiple games in the long run it will have to be moved.
typedef enum {
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
	SNAKE_APPLE,
	SNAKE_TEXT_SCORE,
	SNAKE_TEXT_PAB,
	SNAKE_TEXT_GO,
	SNAKE_TEXT_HS
} sprite_type;

typedef struct {
	uint x;
	uint y;
	sprite_type sprite;
} tileMapTile;

typedef struct {
	uint count;
	tileMapTile *tiles;
} tileMap;

extern const tileMapTile snakeTiles[];
extern const tileMap snakeTilemap;
extern const u16 SnakeTilemap[];
extern const u16 TextScoreBitmap[];
extern const u16 TextPressAnyButtonBitmap[];
extern const u16 TextGameOverBitmap[];
extern const u16 TextHiScoreBitmap[];

#endif // __SNAKE_GAME_IMAGES_H__
