/*
 * input.c
 *
 *  Created on: May 20, 2022
 *      Author: talei
 */

#include "input.h"

#include <stdbool.h>
#include <string.h>

static bool buttonArray[NB_BUTTONS];
static directions dir = 0;

void initButtons()
{
	memset(&buttonArray, 0, sizeof(buttonArray));
	dir = NO_DIRECTION;
}

void toggleButton(buttons button)
{
	buttonArray[button] = buttonArray[button] ? false : true;

	if (button == DIRECTION_UP)
	{
		if (getButtonState(DIRECTION_UP))
		{
			dir = UP;
		}
	}
	else if (button == DIRECTION_DOWN)
	{
		if (getButtonState(DIRECTION_DOWN))
		{
			dir = DOWN;
		}
	}
	else if (button == DIRECTION_RIGHT)
	{
		if (getButtonState(DIRECTION_RIGHT))
		{
			dir = RIGHT;
		}
	}
	else if (button == DIRECTION_LEFT)
	{
		if (getButtonState(DIRECTION_LEFT))
		{
			dir = LEFT;
		}
	}
}

bool getButtonState(buttons button)
{
	return buttonArray[button];
}

directions getCurrentDirection()
{
	return dir;
}
