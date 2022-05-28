/*
 * imageBase.h
 *
 *  Created on: 26 May 2022
 *      Author: talei
 */

#ifndef INC_IMAGEBASE_H_
#define INC_IMAGEBASE_H_

#include "common.h"

typedef struct {
	uint x;
	uint y;
	char* name;
}tileMapTile;

typedef struct {
	uint count;
	tileMapTile* tiles;
}tileMap;

#endif /* INC_IMAGEBASE_H_ */
