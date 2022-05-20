/**
 * @file image.h
 * @brief Image library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"
#include "snake_game_image.h"

/**
 * @brief Get an image bitmap from the name.
 **/
u16 *getImage(char *name);

/**
 * @brief Get an image height from the name.
 **/
u16 *getImageHeight(char *name);

/**
 * @brief Get an image width from the name.
 **/
u16 *getImageWidth(char *name);

#endif // __IMAGE_H__