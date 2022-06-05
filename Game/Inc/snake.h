/**
 * @file snake.h
 * @brief Snake game functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "gameEngine.h"
#include "image.h"
#include "input.h"
#include "log.h"
#include "input.h"
#include <stdbool.h>
#include "stm32l4xx_ll_rng.h"

/**
 * @brief Different types for the map squares.
 **/

typedef enum
{
    VOID = 0,   /**< Empty square */
    SNAKE = 1,  /**< Snake in the square */
    APPLE = 2   /**< Apple in the square */
} case_type;

/**
 * @struct snake_case
 * @brief Structure used for the map squares.
 **/
struct snake_case
{
    directions direction; /**< Direction if snake whithin square*/ 
    case_type type;       /**< Type of the square*/
};

#define tailleCaseTemp 34

/**
 * @brief Initialize the game.
 * @details Sets the map size and the variables to default values. This function must be called after having render the UI and the background.
 * @param x the width of the map
 * @param y the height of the map
 **/
void init_snake_game(int x, int y);

/**
 * @brief Update the game.
 * @details Update the game values using direcion. Add elements for the game engine to update the screen.
 **/
void update_snake_game();

/**
 * @brief Reset the game.
 * @details Reset the game to default values. Called to replay when a game is over. Must not be called before the initialization.
 **/
void reset_snake_game();

//Temporary memory desallocation.
void destroy_snake_game();

/**
 * @brief Render the game UI.
 * @details Draw score, and map boundries.
 **/
void render_snake_UI();

/**
 * @brief Render the game background.
 * @details Draw a white rectangle background for the map.
 **/
void render_snake_Background();

#endif
