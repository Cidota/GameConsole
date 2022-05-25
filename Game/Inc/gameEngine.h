/**
 * @file gameEngine.h
 * @brief Functions to run all games.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

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

/**
 * @brief Different games available.
 **/
typedef enum games
{
    NONE, /**< No game */
    SNAKE_GAME /**< Snake game */
} games;

/**
 * @brief Structure for positions
 */
struct coordinate
{
    int x;
    int y;
};

/**
 * @brief Structure of a sprite
 */
struct sprite
{
    struct coordinate position; /**< Top left corner of the sprite. */
    struct coordinate size;     /**< Size of the sprite. */
    enum colors sprite;          /**< Color of the sprite. */
};

/**
 * @brief Structure of the things to render in the following frame.
 */
struct screen_updates
{
    unsigned int size;         /** Max size available for the sprites array*/
    unsigned int currentIndex; /** Current position of the sprite array*/
    struct sprite *sprites;    /** Sprite array */
};

void setRenderNonGameElementsTrue();
/**
 * @brief Initialize the game engine.
 * @details Must be called only once.
 **/
void init();

/**
 * @brief Initialize a choosen game.
 * @param game game to initialize from the enum games.
 **/
void init_game(games game);

/**
 * @brief Update the game currently running.
 **/
void update();

/**
 * @brief Add a sprite/color to render next frame.
 * @param posX left corner of the sprite.
 * @param posY top corner of the sprite
 * @param sizeX width of the sprite.
 * @param sizeY height of the sprite.
 * @param sprite color/image of the sprite.
 **/
void addSpriteUpdate(int posX, int posY, int sizeX, int sizeY, colors sprite);

/**
 * @brief Reset the list of updates to render
 * @details Must be called after having render all the sprites.
 **/
void resetSpriteUpdate();

/**
 * @brief Render all the changes of a frame.
 **/
void render();

#endif
