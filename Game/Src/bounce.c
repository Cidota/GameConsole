/*
 * bounce.c
 *
 *  Created on: June 26, 2022
 *      Author: Taleiven Kattan
 */

#include "bounce.h"

const int paddleHeight = 30;
const int paddleWidth = 50;
const int paddleY = 320 - paddleWidth;
const int paddleSpeed = 10;

const int ballHeight = 30;
const int ballWidth = 30;

int paddleX = (480 / 2) - (paddleWidth / 2);
int newPaddleX = offset;
int ballX = (480 / 2) - (ballWidth / 2);
int ballY = 320 - paddleHeight - ballHeight;
int ballSpeed = 10;
int ballDirection = 0;
int ballTravelDistance = 0;
u32 time = 0;
u32 newTime = 0;
u32 deltaTime = 0;

bool waitingForAnyButton = true;
bool waitingForRestartGame = false;

void init_bounce_game()
{
    // Initialize variables
    paddleX = (480 / 2) - (paddleWidth / 2);
    ballX = (480 / 2) - (ballWidth / 2);
    ballY = 320 - paddleHeight - ballHeight;

    // Render the UI and background
    setRenderNonGameElementsTrue();

    // Render the ball and paddle
    addColorUpdate(paddleX, paddleY, paddleWidth, paddleHeight, BLACK);
    addColorUpdate(ballX, ballY, ballWidth, ballHeight, BLACK);
}

void update_bounce_game()
{
    // Get the direction
    directions direction = acceptBufferedDirection();

    // Wait for restart game to be pressed
    if (waitingForRestartGame)
    {
        if (direction == NO_DIRECTION)
            return;
        else
        {
            reset_bounce_game();
            return;
        }
    }

    // Wait for any button to be pressed
    if (waitingForAnyButton)
    {
        if (direction == NO_DIRECTION)
            return;
        else
        {
            waitingForAnyButton = false;
            time = getTimeMS();
            // Calculate ball direction
        }
    }

    // Move the paddle
    if (direction == LEFT)
    {
        newPaddleX = paddleX - paddleSpeed;
        if (newPaddleX >= offset)
        {
            addColorUpdate(paddleX, paddleY, paddleWidth, paddleHeight, WHITE);
            addColorUpdate(newPaddleX, paddleY, paddleWidth, paddleHeight, BLACK);
            paddleX = newPaddleX;
        }
    }
    else if (direction == RIGHT)
    {
        newPaddleX = paddleX + paddleSpeed;
        if (newPaddleX + paddleWidth > getScreenWidth())
        {
            addColorUpdate(paddleX, paddleY, paddleWidth, paddleHeight, WHITE);
            addColorUpdate(newPaddleX, paddleY, paddleWidth, paddleHeight, BLACK);
            paddleX = newPaddleX;
        }
    }
    // Move the ball
    // Get delta time and use it to calculate the distance traveled
    newTime = getTimeMS();
    deltaTime = newTime - time;
    time = newTime;

    ballTravelDistance = (float)ballSpeed * ((float)deltaTime / 1000.0);

    // Get the new x and y of the ball
    // TODO: Implement sin and cos
    // pointX = x + distance * Math.cos(angle)
    // pointY = y + distance * Math.sin(angle)

    // Update ball

    // If ball is touching wall change direction
    // If ball is touching paddle change direction and increase score
    // If ball is touching ground end game
}

void reset_bounce_game();

void render_snake_Background()
{
    // Draw a white rectangle from the UI offset to end of the screen
    drawRectangle(offset, 0, getScreenHeight(), getScreenWidth() - offset, WHITE);
}

void render_snake_UI()
{
    // Draw a black rectangle as the background for the UI
    drawRectangle(0, 0, offset, getScreenHeight(), BLACK);
}
