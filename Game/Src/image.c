/**
 * @file image.c
 * @details Author: Taleiven Kattan | Created on: 26th May 2022
 * @copyright Cidota. All rights reserved, 2022.
 **/

#include "image.h"

#include <stdlib.h>

u16 snakeTile[1156];

u16* getImage(sprite_type sprite) {
	int c;
	for (c = 0; c < snakeTilemap.count; ++c) {
		if (snakeTilemap.tiles[c].sprite == sprite)
			break;
	}

	if (c >= snakeTilemap.count)
		return NULL;
	else {
		int i = snakeTilemap.tiles[c].x;
		int j = snakeTilemap.tiles[c].y;
		int y = 0;
		int x = 0;
		for (y = 0; y < 34; y++, j++)
			for (x = 0, i = snakeTilemap.tiles[c].x; x < 34; x++, i++)
				snakeTile[(y * 34) + x] = SnakeTilemap[(j * 136) + i];
	}

	return &snakeTile[0];
}

uint getImageHeight(sprite_type sprite) {
	if (sprite <= 18)
		return SNAKE_TILE_HEIGHT;
	else
		return 0;
}

/**
 * @brief Get an image width from the name.
 **/
uint getImageWidth(sprite_type sprite) {
	if (sprite <= 18)
		return SNAKE_TILE_WIDTH;
	else
		return 0;
}
