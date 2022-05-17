/**
 * @file input.h
 * @brief Input library.
 * @details See @ref index for further details.
 * @copyright Cidota. All rights reserved, 2022.
 **/

#ifndef __INPUT_H__
#define __INPUT_H__

/**
 * @brief Different buttons used by the games.
 **/
typedef enum
{
    /* buttons */
    A = 0,               /**< the A button */
    B = 1,               /**< the A button */
    DIRECTION_UP = 2,    /**< the UP button on the D-Pad */
    DIRECTION_DOWN = 3,  /**< the DOWN on the D-Pad */
    DIRECTION_RIGHT = 4, /**< the RIGHT button on the D-Pad */
    DIRECTION_LEFT = 5,  /**< the LEFT button on the D-Pad */
    START = 6,           /**< the START button */
    POWER = 7            /**< the POWER button */
} buttons;

/**
 * @brief Directions possible on the D-Pad.
 **/
typedef enum
{
    /* directions */
    UP = 0,    /**< up */
    DOWN = 1,  /**< down */
    LEFT = 2,  /**< left */
    RIGHT = 3, /**< right */
    NONE = 4   /**< no direction */
} directions;

/**
 * @brief Gets the state of a button.
 * @param buttons the button
 * @return true if the button is active, false otherwise
 **/
bool getButtonState(buttons button);

/**
 * @brief Gets the current direction if available.
 * @return a direction if available, NONE otherwise
 **/
directions getCurrentDirection();

#endif // __INPUT_H__