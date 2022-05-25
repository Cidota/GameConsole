#ifndef __SNAKE_H__
#define __SNAKE_H__
#include "gameEngine.h"
#include "image.h"
#include "input.h"
#include "log.h"
#include "input.h"
#include <stdbool.h>
#include "stm32l4xx_ll_rng.h"

typedef enum
{
    VOID = 0,
    SNAKE = 1,
    APPLE = 2
} case_type;

struct snake_case
{
    directions direction;
    case_type type;
};

#define tailleCaseTemp 34

void init_snake_game();

void update_snake_game();

void reset_snake_game();

void destroy_snake_game();

void render_snake_UI();

void render_snake_Background();

#endif
