/**
 * @file input.h
 * @brief Input library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __INPUT_H__
#define __INPUT_H__

#include "image.h"

#include <stdbool.h>

/**
 * @brief Different buttons used by the games.
 **/
typedef enum {
	/* buttons */
	A = 0, /**< the A button */
	B = 1, /**< the A button */
	DIRECTION_UP = 2, /**< the UP button on the D-Pad */
	DIRECTION_DOWN = 3, /**< the DOWN on the D-Pad */
	DIRECTION_RIGHT = 4, /**< the RIGHT button on the D-Pad */
	DIRECTION_LEFT = 5, /**< the LEFT button on the D-Pad */
	START = 6, /**< the START button */
	POWER = 7, /**< the POWER button */
	NB_BUTTONS /**< the number of buttons */
} buttons;

/**
 * @brief Directions possible on the D-Pad.
 **/
typedef enum {
	/* directions */
	UP = 0, /**< up */
	DOWN = 1, /**< down */
	LEFT = 2, /**< left */
	RIGHT = 3, /**< right */
	NO_DIRECTION = 4 /**< no direction */
} directions;

/**
 * @brief Initialises the inputs.
 **/
void initInputs();

/**
 * @brief Toggles a button.
 * @details Only to be used by interrupts.
 * @param button the button to toggle
 **/
void toggleButton(buttons button);

/**
 * @brief Gets the current state of a button.
 * @param buttons the button
 * @return true if the button is active, false otherwise
 **/
bool getButtonState(buttons button);

/**
 * @brief Gets the buffered state of a button.
 * @details Buffered state is a state that is not toggled off even if the button is released.
 * The button will not be toggled off after calling this function.
 * @param buttons the button
 * @return true if the button is active, false otherwise
 **/
bool getBufferedButtonState(buttons button);

/**
 * @brief Gets the buffered state of a button and sets it to false.
 * @details Buffered state is a state that is not toggled off even if the button is released.
 * Accepting the state ensures that the button state will be off after and should only be done if the input has been processed.
 * @param buttons the button
 * @return true if the button is active, false otherwise
 **/
bool acceptBufferedButtonState(buttons button);

/**
 * @brief Gets the buffered direction if available.
 * @details Buffered direction will contain the last direction button pressed and will not be set to NO_DIRECTION after.
 * @return a direction if available, NO_DIRECTION otherwise
 **/
directions getBufferedDirection();

/**
 * @brief Gets the buffered direction and sets direction to NO_DIRECTION.
 * @details Buffered direction will contain the last direction button pressed.
 * Accepting the direction ensures that it will be NO_DIRECTION after and should only be done if the input has been processed.
 * @return a direction if available, NO_DIRECTION otherwise
 **/
directions acceptBufferedDirction();

#endif // __INPUT_H__
