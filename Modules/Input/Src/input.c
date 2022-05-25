/*
 * input.c
 *
 *  Created on: May 20, 2022
 *      Author: talei
 */

#include "input.h"

#include <stdbool.h>
#include <string.h>

static bool currentButtonState[NB_BUTTONS];
static bool bufferedButtonState[NB_BUTTONS];
static directions bufferedDirection = NO_DIRECTION;

void initInputs() {
	memset(&currentButtonState, 0, sizeof(currentButtonState));
	memset(&bufferedButtonState, 0, sizeof(bufferedButtonState));
	bufferedDirection = NO_DIRECTION;
}

void toggleButton(buttons button) {
	currentButtonState[button] = currentButtonState[button] ? false : true;
	if (currentButtonState[button])
		bufferedButtonState[button] = true;

	if (button == DIRECTION_UP && currentButtonState[button])
		bufferedDirection = UP;
	else if (button == DIRECTION_DOWN && currentButtonState[button])
		bufferedDirection = DOWN;
	else if (button == DIRECTION_RIGHT && currentButtonState[button])
		bufferedDirection = RIGHT;
	else if (button == DIRECTION_LEFT && currentButtonState[button])
		bufferedDirection = LEFT;
}

bool getButtonState(buttons button) {
	return currentButtonState[button];
}

bool getBufferedButtonState(buttons button) {
	return bufferedButtonState[button];
}

bool acceptBufferedButtonState(buttons button) {
	bool tmp = bufferedButtonState[button];
	bufferedButtonState[button] = false;
	return tmp;
}

directions getBufferedDirection() {
	return bufferedDirection;
}

directions acceptBufferedDirction() {
	directions tmp = bufferedDirection;
	bufferedDirection = NO_DIRECTION;
	return tmp;
}

