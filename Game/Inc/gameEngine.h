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
    NONE,      /**< No game */
    SNAKE_GAME /**< Snake game */
} games;

/**
 * @brief Different types for the items
 */
typedef enum itemtypes
{
    COLOR, 
    BITMAP,
	NUMBER
} itemtypes;

/**
 * @brief Structure for positions
 */
struct coordinate
{
    int x;
    int y;
};

typedef union sprite
{
	uint number;
    enum colors color;
    sprite_type sprite;
} sprite;

/**
 * @brief Structure of a item
 */
struct item
{
    struct coordinate position;   /**< Top left corner of the item. */
    struct coordinate size;       /**< Size of the item. */
    sprite item;           /**< Color of the item. */
    enum itemtypes item_type; /**< Type of item */
};

/**
 * @brief Structure of the things to render in the following frame.
 */
struct screen_updates
{
    unsigned int size;         /** Max size available for the items array*/
    unsigned int currentIndex; /** Current position of the item array*/
    struct item *items;    /** Sprite array */
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
 * @brief Add a number to render next frame.
 * @param posX the left corner of the number
 * @param posY the top corner of the number
 * @param number the number to render
 **/
void addNumberUpdate(int posX, int posY, int number);

/**
 * @brief Add a color to render next frame.
 * @param posX left corner of the item.
 * @param posY top corner of the item
 * @param sizeX width of the item.
 * @param sizeY height of the item.
 * @param color color of the item.
 **/
void addColorUpdate(int posX, int posY, int sizeX, int sizeY, colors color);


/**
 * @brief Add a sprite to render next frame.
 * @param posX left corner of the item.
 * @param posY top corner of the item.
 * @param sprite enum referencing a sprite.
 **/
void addSpriteUpdate(int posX, int posY, sprite_type sprite);
/**
 * @brief Reset the list of updates to render
 * @details Must be called after having render all the items.
 **/
void resetSpriteUpdate();

/**
 * @brief Render all the changes of a frame.
 **/
void render();

#endif
