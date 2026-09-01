#ifndef __HEADER_HPP__
#define __HEADER_HPP__

#define FPS 60

#define SCREEN_W 1280.0f
#define SCREEN_H 900.0f

#define TERRAIN_WIDTH 800.0f
#define TERRAIN_HEIGHT 400.0f

#define BASE_BALL_SPEED 400.0f
#define BASE_BALL_RADIUS TERRAIN_HEIGHT / 48
#define BASE_BALL_X (TERRAIN_WIDTH / 2)
#define BASE_BALL_Y (TERRAIN_HEIGHT / 2)

#define BASE_PADDLE_SPEED 300.0f
#define BASE_PADDLE_HEIGHT TERRAIN_HEIGHT / 6
#define BASE_PADDLE_WIDTH TERRAIN_HEIGHT / 24
#define BASE_PADDLE_Y TERRAIN_HEIGHT / 2 - (BASE_PADDLE_HEIGHT / 2)
#define BASE_PADDLE_LEFT_X TERRAIN_WIDTH / 12
#define BASE_PADDLE_RIGHT_X TERRAIN_WIDTH - BASE_PADDLE_LEFT_X
struct Paddle {
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
