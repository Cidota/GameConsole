/**
 * @file application.h
 * @brief Basic App Loop Functions.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __APP_H__
#define __APP_H__

/**
 * @brief Initialises the application. Will be called each time the application launches.
 **/
void init();

/**
 * @brief Updates the application.
 * @details This function is used to update the application state.
 **/
void update();

/**
 * @brief Draw the application to the main output.
 **/
void render();

/**
 * @brief Clean up used resources. Will be called each time the application closes.
 */
void cleanup();

#endif // __APP_H__