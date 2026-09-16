#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include <math.h>
#include "ViewPort.hpp"
#include "raylib.h"

// (X, Y) défini le centre d'un objet

constexpr float BASE_BALL_SPEED = 350.0f;
constexpr float BASE_BALL_RADIUS = WORLD_HEIGHT / 48;
constexpr float BASE_BALL_X = (WORLD_WIDTH / 2);
constexpr float BASE_BALL_Y = (WORLD_HEIGHT / 2);
constexpr float BASE_BALL_LEFT_BORDER = BASE_BALL_X - BASE_BALL_RADIUS;
constexpr float BASE_BALL_RIGHT_BORDER = BASE_BALL_X + BASE_BALL_RADIUS;
constexpr float BASE_BALL_TOP_BORDER = BASE_BALL_Y - BASE_BALL_RADIUS;
constexpr float BASE_BALL_BOT_BORDER = BASE_BALL_Y + BASE_BALL_RADIUS;

constexpr float BASE_PADDLE_SPEED = 300.0f;
constexpr float BASE_PADDLE_HEIGHT = WORLD_HEIGHT / 6;
constexpr float BASE_PADDLE_WIDTH = WORLD_HEIGHT / 32;
constexpr float BASE_PADDLE_Y = WORLD_HEIGHT / 2;
constexpr float BASE_PADDLE_TOP_BORDER = BASE_PADDLE_Y - (BASE_PADDLE_HEIGHT / 2);
constexpr float BASE_PADDLE_BOT_BORDER = BASE_PADDLE_Y + (BASE_PADDLE_HEIGHT / 2);

constexpr float BASE_PADDLE_LEFT_X = WORLD_WIDTH / 16;
constexpr float BASE_PADDLE_LEFT_BORDER_LEFT = BASE_PADDLE_LEFT_X - (BASE_PADDLE_WIDTH / 2);
constexpr float BASE_PADDLE_LEFT_BORDER_RIGHT = BASE_PADDLE_LEFT_X + (BASE_PADDLE_WIDTH / 2);

constexpr float BASE_PADDLE_RIGHT_X = WORLD_WIDTH - BASE_PADDLE_LEFT_X;
constexpr float BASE_PADDLE_RIGHT_BORDER_LEFT = BASE_PADDLE_RIGHT_X - (BASE_PADDLE_WIDTH / 2);
constexpr float BASE_PADDLE_RIGHT_BORDER_RIGHT = BASE_PADDLE_RIGHT_X + (BASE_PADDLE_WIDTH / 2);

constexpr float ANGLE = 60 * static_cast<float>(M_PI) / 180;

struct Paddle
{
	float left_border, right_border;
	float top_border, bot_border;
	float x, y;
	float width;
	float height;
	float speed;
};

struct Ball
{
	float left_border, right_border;
	float top_border, bot_border;
	float x, y;
	float vx, vy;
	float radius;
	float speed;
};

struct PhysicsState
{
	Paddle	left_paddle;
	Paddle	right_paddle;
	Ball	ball;
};

typedef enum
{
	TOGGLE_PAUSE = KEY_TAB,
	ENTER = KEY_ENTER
} Input;

int	checkBallPaddleCollision(Ball& b, Paddle& p);

#endif
