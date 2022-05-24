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

void reset_snake_game() {
	printf("***\nGame over.\n***\n");
	printf(". S . .\n*** Reseting Snake Game***\n");
	// temp indicator that game is over
	drawRectangle(0, 0, 160, 320, RED);
	exit(1);
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
		map[i]->type = VOID;
		map[i]->direction = NO_DIRECTION;
	}
	srand(LL_RNG_ReadRandData32(RNG));
	snake_head->x = map_size->x / 2;
	snake_head->y = map_size->y / 2;
	snake_tail->x = snake_head->x;
	snake_tail->y = snake_head->y;
	map[getIndex(snake_head)]->direction = NO_DIRECTION;
	map[getIndex(snake_head)]->type = SNAKE;
	availablePositions = map_size->x * map_size->y - 1;
	lastDir = RIGHT;
	addSpriteUpdate(snake_head->x, snake_head->y, tailleCaseTemp,
			tailleCaseTemp, ORANGE);
	generateApple();
}

void update_snake_game() {
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
		// If the snake is size = 1, the previous position of the head should not be set as green.
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
	// print_map();
}