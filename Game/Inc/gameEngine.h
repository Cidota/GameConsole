#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__
#include "snake.h"
#include "input.h"
#include "log.h"
#include "image.h"
#include "graphics.h"
#include "time.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define offset 160

typedef enum games
{
    NONE,
    SNAKE_GAME
} games;

struct coordinate
{
    int x;
    int y;
};

struct sprite
{
    struct coordinate position;
    struct coordinate size;
    enum color sprite;
};

struct screen_updates
{
    unsigned int size;
    struct sprite *sprites;
};

void init();

void init_game(games game);

void update();

void addSpriteUpdate(int posX, int posY, int sizeX, int sizeY, color sprite);

void resetSpriteUpdate();

void draw();

// void end_game();

#endif