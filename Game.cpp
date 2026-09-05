#include "Game.hpp"

Game::Game()
{
	left_paddle =
	{
		.left_border = 	BASE_PADDLE_LEFT_BORDER_LEFT,
		.right_border = BASE_PADDLE_LEFT_BORDER_RIGHT,
		.top_border =	BASE_PADDLE_TOP_BORDER,
		.bot_border =	BASE_PADDLE_BOT_BORDER,
		.x	=			BASE_PADDLE_LEFT_X,
		.y =			BASE_PADDLE_Y,
		.width =		BASE_PADDLE_WIDTH,
		.height =	BASE_PADDLE_HEIGHT,
		.speed	=	BASE_PADDLE_SPEED,
	};

	right_paddle = 
	{
		.left_border = 	BASE_PADDLE_RIGHT_BORDER_LEFT,
		.right_border = BASE_PADDLE_RIGHT_BORDER_RIGHT,
		.top_border =	BASE_PADDLE_TOP_BORDER,
		.bot_border =	BASE_PADDLE_BOT_BORDER,
		.x	=			BASE_PADDLE_RIGHT_X,
		.y =			BASE_PADDLE_Y,
		.width =		BASE_PADDLE_WIDTH,
		.height =	BASE_PADDLE_HEIGHT,
		.speed	=	BASE_PADDLE_SPEED,
	};

	ball = 
	{
		.x =		BASE_BALL_X,
		.y = 		BASE_BALL_Y,
		.vx =		0.5,
		.vy =		0,
		.radius =	BASE_BALL_RADIUS,
		.speed =	BASE_BALL_SPEED
	};
}
