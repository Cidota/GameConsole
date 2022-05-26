/*
 * gameEngine.c
 *
 *  Created on: May 21, 2022
 *      Author: Charles Martin
 */

#include "gameEngine.h"

struct screen_updates *screen_updates;
games currentGame = NONE;
bool renderNonGameElements = true;

void addColorUpdate(int posX, int posY, int sizeX, int sizeY, colors color) {
	screen_updates->items[screen_updates->currentIndex].position.x = posX;
	screen_updates->items[screen_updates->currentIndex].position.y = posY;
	screen_updates->items[screen_updates->currentIndex].size.x = sizeX;
	screen_updates->items[screen_updates->currentIndex].size.y = sizeY;
	screen_updates->items[screen_updates->currentIndex].item_type = COLOR;
	screen_updates->items[screen_updates->currentIndex].item.color = color;	
	screen_updates->currentIndex += 1;
}

void resetSpriteUpdate() {
	for (int i = 0; i < screen_updates->size; i++) {
		screen_updates->items[i].position.x = 0;
		screen_updates->items[i].position.y = 0;
		screen_updates->items[i].size.x = 0;
		screen_updates->items[i].size.y = 0;
		screen_updates->items[i].item.color = BLACK;
		screen_updates->items[i].item_type = COLOR;
	}
	screen_updates->currentIndex = 0;
}

void init() {
	init_game(SNAKE_GAME);
}

void init_game(games game) {
	currentGame = game;
	renderNonGameElements = true;
	if (currentGame == NONE) {
		printf("GameEngine couldn't find any game to update.\n");
		exit(1);
	}
	screen_updates = malloc(sizeof(struct screen_updates));
	if (screen_updates == NULL) {
		logError("Memory limit exceeded.\n");
	}
	screen_updates->currentIndex = 0;
	switch (currentGame) {
	case SNAKE_GAME:
		screen_updates->size = 3;
		break;
	default:
		screen_updates->size = 0;
		break;
	}
	screen_updates->items = malloc(
			screen_updates->size * sizeof(struct item));
	if (screen_updates->items == NULL) {
		logError("Memory limit exceeded.\n");
	}
	switch (currentGame) {
	case SNAKE_GAME:
		init_snake_game(9, 9);
		break;
	default:
		printf("Couldn't initialize any game.\n");
		exit(1);
		break;
	}

}

//temp
bool getDeltaTime(int t) {
	static u32 last_ms = 0;
	u32 now_ms = getTimeMs();

	// Fast exit if time has not changed.
	if (now_ms == last_ms)
		return false;

	if (now_ms - last_ms >= t) {
		last_ms = now_ms;
		return true;
	} else {
		return false;
	}
}

void update() {
	resetSpriteUpdate();
	switch (currentGame) {
	case SNAKE_GAME:
		if (getDeltaTime(500))
			update_snake_game(screen_updates);
		break;
	default:
		break;
	}
}

void setRenderNonGameElementsTrue(){
	renderNonGameElements = true;
}


void render(){
	if (renderNonGameElements){
		switch (currentGame) {
		case SNAKE_GAME:
			render_snake_UI();
			render_snake_Background();
			break;
		default:
			break;
		}
		renderNonGameElements = false;
	}
	if (screen_updates != NULL && screen_updates->currentIndex != 0) {
		for (int i = 0; i < screen_updates->currentIndex ; i++) {
			switch(screen_updates->items[i].item_type){
				case COLOR:
					drawRectangle(
					offset + (screen_updates->items[i].position.x * tailleCaseTemp),
					tailleCaseTemp * screen_updates->items[i].position.y,
							screen_updates->items[i].size.x,
							screen_updates->items[i].size.y,
							screen_updates->items[i].item.color);
					break;
				case BITMAP:
				//drawBitmap(
				//	offset + (screen_updates->items[i].position.x * tailleCaseTemp),
				//  tailleCaseTemp * screen_updates->items[i].position.y, uint y, uint height, uint width, u16 bitmap[]);
					break;
				default:
					break;
			}
		}
	}
}
