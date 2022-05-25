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

void addSpriteUpdate(int posX, int posY, int sizeX, int sizeY, colors sprite) {
	screen_updates->sprites[screen_updates->currentIndex].position.x = posX;
	screen_updates->sprites[screen_updates->currentIndex].position.y = posY;
	screen_updates->sprites[screen_updates->currentIndex].size.x = sizeX;
	screen_updates->sprites[screen_updates->currentIndex].size.y = sizeY;
	screen_updates->sprites[screen_updates->currentIndex].sprite = sprite;
	screen_updates->currentIndex += 1;
}
void resetSpriteUpdate() {
	for (int i = 0; i < screen_updates->size; i++) {
		screen_updates->sprites[i].position.x = 0;
		screen_updates->sprites[i].position.y = 0;
		screen_updates->sprites[i].size.x = 0;
		screen_updates->sprites[i].size.y = 0;
		screen_updates->sprites[i].sprite = BLACK;
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
	screen_updates->sprites = malloc(
			screen_updates->size * sizeof(struct sprite));
	if (screen_updates->sprites == NULL) {
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
			drawRectangle(
			offset + (screen_updates->sprites[i].position.x * tailleCaseTemp),
			tailleCaseTemp * screen_updates->sprites[i].position.y,
					screen_updates->sprites[i].size.x,
					screen_updates->sprites[i].size.y,
					screen_updates->sprites[i].sprite);
		}
	}
}
