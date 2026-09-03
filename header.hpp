#ifndef __HEADER_HPP__
#define __HEADER_HPP__


#include <math.h>

// (X, Y) défini le centre d'un objet

constexpr float FPS = 60;

constexpr float SCREEN_W = 800.0f;
constexpr float SCREEN_H = 400.0f;

constexpr float WORLD_WIDTH = 400.0f;
constexpr float WORLD_HEIGHT = 250.0f;

constexpr float BASE_BALL_SPEED = 350.0f;
constexpr float BASE_BALL_RADIUS = WORLD_HEIGHT / 48;
constexpr float BASE_BALL_X = (WORLD_WIDTH / 2);
constexpr float BASE_BALL_Y = (WORLD_HEIGHT / 2);

constexpr float BASE_PADDLE_SPEED = 300.0f;
constexpr float BASE_PADDLE_HEIGHT = WORLD_HEIGHT / 5;
constexpr float BASE_PADDLE_WIDTH = WORLD_HEIGHT / 24;
constexpr float BASE_PADDLE_Y = (WORLD_HEIGHT / 2);
constexpr float BASE_PADDLE_TOP_BORDER = BASE_PADDLE_Y - (BASE_PADDLE_HEIGHT / 2);
constexpr float BASE_PADDLE_BOT_BORDER = BASE_PADDLE_Y + (BASE_PADDLE_HEIGHT / 2);

constexpr float BASE_PADDLE_LEFT_X = WORLD_WIDTH / 16;
constexpr float BASE_PADDLE_LEFT_BORDER_LEFT = BASE_PADDLE_LEFT_X - (BASE_PADDLE_WIDTH / 2);
constexpr float BASE_PADDLE_LEFT_BORDER_RIGHT = BASE_PADDLE_LEFT_X + (BASE_PADDLE_WIDTH / 2);

constexpr float BASE_PADDLE_RIGHT_X = WORLD_WIDTH - BASE_PADDLE_LEFT_X;
constexpr float BASE_PADDLE_RIGHT_BORDER_LEFT = BASE_PADDLE_RIGHT_X - (BASE_PADDLE_WIDTH / 2);
constexpr float BASE_PADDLE_RIGHT_BORDER_RIGHT = BASE_PADDLE_RIGHT_X + (BASE_PADDLE_WIDTH / 2);

constexpr float ANGLE = 60 * M_PI / 180;

struct Paddle {
	float left_border, right_border;
	float top_border, bot_border;
	float x, y;
	float width;
	float height;
	float speed;
};

struct Ball {
	float x, y;
	float vx, vy;
	float radius;
	float speed;
};

#endif
