/*
 * snake.c
 *
 *  Created on: May 16, 2022
 *      Author: Charles Martin
 */

#include "snake.h"
#include "gameEngine.h"

struct coordinate *snake_head;
struct coordinate *snake_tail;
struct coordinate *apple;
struct coordinate *next_position;
struct coordinate *map_size;
struct snake_case **map;
directions lastDir;
int availablePositions = -1; /**< Available positions for apples */
int score = 0;
bool isGameRunning = false;

directions getOppositeDirection(directions d) {
	switch (d) {
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	case LEFT:
		return RIGHT;
	case RIGHT:
		return LEFT;
	default:
		return NO_DIRECTION;
	}
}

/**
 * @brief Find a random empty space and set an apple there.
 */
void generateApple() {
	if (map == NULL || map_size == NULL || map_size->x < 1 || map_size->y < 1) {
		logError("Snake game wasn't initialize correctly, apple couldn't be set.\n");
		exit(1);
	}
	if (availablePositions < 0) {
		reset_snake_game();
		return;
	}
	unsigned int newPos = (unsigned int) (abs(rand()) % (availablePositions)) + 1;
	unsigned int cpt = 0;
	for (int i = 0; i < map_size->x * map_size->y; i++) {
		if (map[i]->type == VOID) {
			cpt++;
		}
		if (cpt == newPos) {
			addSpriteUpdate(i % map_size->x, i / map_size->x, SNAKE_APPLE);
			map[i]->type = APPLE;
			map[i]->direction = NO_DIRECTION;
			break;
		}
	}
	availablePositions--;
	logDebug("Available Positions = %d\n", availablePositions);
}

/**
 * @brief Update next_pos fields with the position following current_pos in direction d.
 */
void getNextPosition(directions d, struct coordinate *current_pos,
		struct coordinate *next_pos) {
	if (current_pos == NULL || next_pos == NULL) {
		logError("Null pointer in getNextPosition.\n");
	}
	switch (d) {
	case RIGHT:
		next_pos->x = current_pos->x + 1;
		next_pos->y = current_pos->y;
		break;
	case LEFT:
		next_pos->x = current_pos->x - 1;
		next_pos->y = current_pos->y;
		break;
	case UP:
		next_pos->x = current_pos->x;
		next_pos->y = current_pos->y - 1;
		break;
	case DOWN:
		next_pos->x = current_pos->x;
		next_pos->y = current_pos->y + 1;
		break;
	default:
		next_pos->x = current_pos->x;
		next_pos->y = current_pos->y;
		break;
	}
}

/**
 * @brief Get index from a position.
 */
int getIndex(struct coordinate *pos) {
	if (map == NULL || pos == NULL) {
		logError("Null pointer in getIndex.\n");
		return -1;
	}
	return pos->x + pos->y * map_size->x;
}

/**
 * @brief Assert correct direction.
 * @details Verify that the direction isn't the opposite of lastDir avoiding that the snake can't bite itself from an 180° turn.
 */
directions assertDirection(directions d) {
	if (d == getOppositeDirection(lastDir)) {
		return getOppositeDirection(d);
	}
	return d;
}

/**
 * @brief Free the game memory.
 */ 
void destroy_snake_game() {
	printf("\n*** Destroying Snake Game ***\n");
	if (snake_head != NULL) {
		free(snake_head);
	}
	if (snake_tail != NULL) {
		free(snake_tail);
	}
	if (map_size != NULL) {
		free(map_size);
	}
	if (apple != NULL) {
		free(apple);
	}
	if (next_position != NULL) {
		free(next_position);
	}
	if (map != NULL) {
		for (int i = 0; i < map_size->x * map_size->y; i++) {
			if (map[i] != NULL) {
				free(map[i]);
			}
		}
		free(map);
	}
	exit(0);
}

void init_snake_variables(){
	isGameRunning = false;
	snake_head->x = map_size->x / 2;
	snake_head->y = map_size->y / 2;
	snake_tail->x = snake_head->x;
	snake_tail->y = snake_head->y;
	for (int i = 0; i < map_size->x * map_size->y; i++) {
		map[i]->type = VOID;
		map[i]->direction = NO_DIRECTION;
	}
	map[getIndex(snake_head)]->type = SNAKE;
	map[getIndex(snake_head)]->direction = NO_DIRECTION;
	availablePositions = map_size->x * map_size->y - 1;
}

void reset_snake_game() {
	logDebug("***Game over.***\n");
	logDebug("*** Reseting Snake Game***\n");
	isGameRunning = false;
	// temp indicator that game is over
	drawRectangle(0, 0, 160, 320, RED);
	// Reset all the values. This function consider that map_size is well defined and that the memory is allocated.
	 init_snake_variables();
	// TODO: mettre un délai après le reset pour que le joueur n'appui pas accidentilement.
}

void init_render(){
	addColorUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
			tailleCaseTemp, ORANGE);
	generateApple();
}

void render_snake_UI(){
	drawRectangle(0, 0, 160, 320, BLACK);
	drawRectangle(480 - 14, 0, 14, 320, BLACK);
	drawRectangle(160, 320 - 14, 480 - 160, 14, BLACK);
}

void render_snake_Background(){
	drawRectangle(
		offset,0,tailleCaseTemp*9,tailleCaseTemp*9, WHITE);
}

void init_snake_game(int x, int y) {
	snake_head = malloc(sizeof(struct coordinate));
	snake_tail = malloc(sizeof(struct coordinate));
	map_size = malloc(sizeof(struct coordinate));
	apple = malloc(sizeof(struct coordinate));
	next_position = malloc(sizeof(struct coordinate));
	if (snake_head == NULL || snake_tail == NULL || map_size == NULL
			|| apple == NULL || next_position == NULL) {
		logError("Memory limit exceeded.\n");
		destroy_snake_game();
	}
	map_size->x = x;
	map_size->y = y;
	map = malloc(sizeof(struct snake_case*) * map_size->x * map_size->y);
	if (map == NULL) {
		logError("Memory limit exceeded.\n");
		destroy_snake_game();
	}
	for (int i = 0; i < map_size->x * map_size->y; i++) {
		map[i] = malloc(sizeof(struct snake_case));
		if (map[i] == NULL) {
			logError("Memory limit exceeded.\n");
			destroy_snake_game();
		}
	}	
	srand(LL_RNG_ReadRandData32(RNG));
	lastDir = RIGHT;
	init_snake_variables();
}

sprite_type getSnakeHeadSprite(directions direction){
	switch (direction){
		case UP:
			return SNAKE_HEAD_UP;
		case RIGHT:
			return SNAKE_HEAD_RIGHT;
		case DOWN:
			return SNAKE_HEAD_DOWN;
		case LEFT:
			return SNAKE_HEAD_LEFT;
		default:
			return SNAKE_HEAD_DOWN;
	}
}

// From is the previous direction choosen, to is the next one.
// Exemple : If from = UP and to = RIGHT, the snake is moving from up to right.
sprite_type getSnakeBodySprite(directions from, directions to){
	if (from == to){
		if (from == RIGHT || from == LEFT){
			return SNAKE_BODY_HORIZONTAL;
		}
		else{
			return SNAKE_BODY_VERTICAL;
		}
	}
	else{
		if ((from == UP && to == RIGHT) || (from == LEFT && to == DOWN)){
			return SNAKE_BODY_CURVE_DOWN_RIGHT;
		}
		else if ((from ==RIGHT && to == DOWN) || (from == UP && to == LEFT)){
			return SNAKE_BODY_CURVE_DOWN_LEFT;
		}		
		else if ((from ==DOWN && to == LEFT) || (from == RIGHT && to == UP)){
			return SNAKE_BODY_CURVE_UP_LEFT;
		}		
		else if ((from ==LEFT && to == UP) || (from == DOWN && to == RIGHT)){
			return SNAKE_BODY_CURVE_DOWN_RIGHT;
		}
		else{
			logDebug("Couldn't find the curve of the snake\n");
		}
	}
}

sprite_type getSnakeTailSprite(directions direction){
	switch(direction){
		case UP:
			return SNAKE_TAIL_UP;
		case DOWN:
			return SNAKE_TAIL_DOWN;
		case LEFT:
			return SNAKE_TAIL_LEFT;
		case RIGHT:
			return SNAKE_TAIL_RIGHT;
		default:
			logDebug("Couldn't render the tail of the snake.\n");
	}
}

sprite_type getSnakeHeadSoloSprite(directions direction){
		switch (direction){
		case UP:
			return SNAKE_HEAD_SOLO_UP;
		case RIGHT:
			return SNAKE_HEAD_SOLO_RIGHT;
		case DOWN:
			return SNAKE_HEAD_SOLO_DOWN;
		case LEFT:
			return SNAKE_HEAD_SOLO_LEFT;
		default:
			return SNAKE_HEAD_SOLO_DOWN;
	}
}

void update_snake_game() {
	directions direction = acceptBufferedDirction();
	// "Press a button to start" part.
	if (!isGameRunning){
		if (direction == NO_DIRECTION){
			return;
		}
		else{
			setRenderNonGameElementsTrue();
			isGameRunning = true;
			init_render();
			lastDir = direction;
			return;
		}
	}
	// Fetch the direction.
	if (direction == NO_DIRECTION) {
		direction = lastDir;
	}
	// If snake size != 1 verify that the snake isn't doing a 180° turn. 
	if (!(snake_tail->x == snake_head->x && snake_tail->y == snake_head->y)) {
		direction = assertDirection(direction);
	}
	getNextPosition(direction, snake_head, next_position);
	int indexNextPos = getIndex(next_position);
	int indexCurrentPos = getIndex(snake_head);
	// End condition. (snake out of map or biting itself)
	if (next_position->x < 0 || next_position->x >= map_size->x
			|| next_position->y < 0 || next_position->y >= map_size->y
			|| (map[indexNextPos]->type == SNAKE
					&& indexNextPos != getIndex(snake_tail))) {
		reset_snake_game();
		return;
	}
	// If the next position is not apple 3 steps:
	// 1. Remove the tail and set it as blank.
	// 2. Set the head position as green
	// 3. Set the next position of the head as red.
	if (map[indexNextPos]->type == VOID || map[indexNextPos]->type == SNAKE) {
		int indexSnakeTail = getIndex(snake_tail);
		getNextPosition(map[indexSnakeTail]->direction, snake_tail,
				next_position);
		map[indexSnakeTail]->direction = NO_DIRECTION;
		map[indexSnakeTail]->type = VOID;
		addColorUpdate(snake_tail->x, snake_tail->y, tailleCaseTemp,
				tailleCaseTemp, WHITE);
		// size = 1, tail should be in the same spot as the head.
		if (snake_tail->x == snake_head->x && snake_tail->y == snake_head->y) {
			getNextPosition(direction, snake_head, next_position);
			snake_tail->x = next_position->x;
			snake_tail->y = next_position->y;
		} else {
			snake_tail->x = next_position->x;
			snake_tail->y = next_position->y;
		}
		getNextPosition(direction, snake_head, next_position);
		map[indexCurrentPos]->direction = direction;
		map[indexNextPos]->direction = NO_DIRECTION;
		map[indexNextPos]->type = SNAKE;
		// If the snake size = 1, the previous position of the head should not be set as green.
		// Otherwise the previous position of the head set as red should now be green.
		if (!(next_position->x == snake_tail->x && next_position->y == snake_tail->y)){
			addSpriteUpdate(snake_tail->x,snake_tail->y,getSnakeBodySprite(lastDir,direction));
		}
		addSpriteUpdate(snake_tail->x,snake_tail->y,getSnakeTailSprite(lastDir,direction));
		snake_head->x = next_position->x;
		snake_head->y = next_position->y;
		// Snake len = 1, head should be round.
		if (!(next_position->x == snake_tail->x && next_position->y == snake_tail->y)){
			addSpriteUpdate(snake_head->x, snake_head->y,getSnakeHeadSoloSprite(direction));
		}
		else{
			addSpriteUpdate(snake_head->x, snake_head->y,getSnakeHeadSprite(direction));
		}
	// If the next head position is an apple, 3 steps:
	// 1. set the head as green.
	// 2. move the head and set the new position as red.
	// 3. generate a new apple.
	} else if (map[indexNextPos]->type == APPLE) {
		map[indexCurrentPos]->direction = direction;
		map[indexNextPos]->direction = NO_DIRECTION;
		map[indexNextPos]->type = SNAKE;
		addSpriteUpdate(snake_head->x, snake_head->y, getSnakeBodySprite());
		addSpriteUpdate(next_position->x, next_position->y, getSnakeHeadSprite());
		snake_head->x = next_position->x;
		snake_head->y = next_position->y;
		generateApple();
	}
	lastDir = direction;
}
