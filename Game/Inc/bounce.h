/**
 * @file bounce.h
 * @brief Bounce game functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __BOUNCE_H__
#define __BOUNCE_H__

#include "common.h"
#include "gameEngine.h"
#include "graphics.h"
#include "input.h"
#include "time.h"

/**
 * @brief Initialize the game.
 * @details Sets variables to default values.
 **/
void init_bounce_game();

/**
 * @brief Update the game.
 * @details Update the game values using direction. Add elements for the game engine to update the screen.
 **/
void update_bounce_game();

/**
 * @brief Reset the game.
 * @details Reset the game to default values. Called to replay when a game is over. Must not be called before the initialization.
 **/
void reset_bounce_game();

/**
 * @brief Render the game UI.
 * @details Draw score, and map boundaries.
 **/
void render_snake_UI();

#endif
