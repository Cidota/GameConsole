#include "snake.h"
#include "gameEngine.h"

struct coordinate *snake_head;
struct coordinate *snake_tail;
struct coordinate *next_position;
struct coordinate *apple;
struct coordinate *map_size;
struct snake_case **map;
directions lastDir;
int availablePositions = -1;
bool isGameRunning = false;

directions getReverseDirection(directions d) {
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

void generateApple() {
	if (map == NULL || map_size == NULL || map_size->x < 1 || map_size->y < 1) {
		logError("Snake game wasn't initialize correctly.\n");
		exit(1);
	}
	if (availablePositions < 0) {
		reset_snake_game();
		return;
	}
	unsigned int newPos = (unsigned int) (abs(rand()) % (availablePositions))
			+ 1;
	unsigned int cpt = 0;
	for (int i = 0; i < map_size->x * map_size->y; i++) {
		if (map[i]->type == VOID) {
			cpt++;
		}
		if (cpt == newPos) {
			addSpriteUpdate(i % map_size->x, i / map_size->x, tailleCaseTemp,
					tailleCaseTemp, RED);
			map[i]->type = APPLE;
			map[i]->direction = NO_DIRECTION;

			break;
		}
	}
	availablePositions--;
	printf("Available Positions = %d\n", availablePositions);
}

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

int getIndex(struct coordinate *pos) {
	if (map == NULL || pos == NULL) {
		logError("Null pointer in getIndex.\n");
		return -1;
	}
	return pos->x + pos->y * map_size->x;
}

directions assertDirection(directions d) {
	if (d == getReverseDirection(lastDir)) {
		return getReverseDirection(d);
	}
	return d;
}

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
	// Reset all the values. This function consider that map_size is well defined.
	 init_snake_variables();

	// TODO: mettre un délai après le reset pour que le joueur n'appui pas accidentilement.
}

void init_render(){
	addSpriteUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
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

sprite_type getSnakeHeadSprite(directions to){
	switch (to){
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

void update_snake_game() {
	// "Press a button to start" part.
	if (!isGameRunning){
		if (getCurrentDirection() == NO_DIRECTION){
			return;
		}
		else{
			setRenderNonGameElementsTrue();
			isGameRunning = true;
			init_render();
			return;
		}
	}
	directions direction = getCurrentDirection();
	if (direction == NO_DIRECTION) {
		direction = lastDir;
	}
	if (!(snake_tail->x == snake_head->x && snake_tail->y == snake_head->y)) {
		direction = assertDirection(direction);
	}
	lastDir = direction;
	getNextPosition(direction, snake_head, next_position);
	int indexNextPos = getIndex(next_position);
	int indexCurrentPos = getIndex(snake_head);
	if (next_position->x < 0 || next_position->x >= map_size->x
			|| next_position->y < 0 || next_position->y >= map_size->y
			|| (map[indexNextPos]->type == SNAKE
					&& indexNextPos != getIndex(snake_tail))) {
		reset_snake_game();
		return;
	}
	if (map[indexNextPos]->type == VOID || map[indexNextPos]->type == SNAKE) {
		int indexSnakeTail = getIndex(snake_tail);
		getNextPosition(map[indexSnakeTail]->direction, snake_tail,
				next_position);
		map[indexSnakeTail]->direction = NO_DIRECTION;
		map[indexSnakeTail]->type = VOID;
		addSpriteUpdate(snake_tail->x, snake_tail->y, tailleCaseTemp,
				tailleCaseTemp, WHITE);
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
			addSpriteUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
					tailleCaseTemp, GREEN);
		}
		snake_head->x = next_position->x;
		snake_head->y = next_position->y;
		addSpriteUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
				tailleCaseTemp, ORANGE);
	} else if (map[indexNextPos]->type == APPLE) {
		map[indexCurrentPos]->direction = direction;
		map[indexNextPos]->direction = NO_DIRECTION;
		map[indexNextPos]->type = SNAKE;
		addSpriteUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
				tailleCaseTemp, GREEN);
		addSpriteUpdate(next_position->x, next_position->y, tailleCaseTemp,
				tailleCaseTemp, ORANGE);
		snake_head->x = next_position->x;
		snake_head->y = next_position->y;
		generateApple();
	}
}
