#include "Simulation.hpp"

int	CheckBallPaddleCollision(Ball& ball, Paddle& paddle)
{
	// Pour savoir c'est quelle raquette
	float ball_border_pos = paddle.x > (WORLD_WIDTH / 2) ? ball.right_border : ball.left_border;

	return (
			ball_border_pos >= paddle.left_border &&
			ball_border_pos <= paddle.right_border &&
			ball.y >= paddle.top_border &&
		 	ball.y <= paddle.bot_border
		 );
}

void	HandleBallPaddleCollision(Ball& b, Paddle& p, int dir)
{
	if (CheckBallPaddleCollision(b, p))
	{
		float ratio = (b.y - p.y) / (p.height / 2);
		float a = ANGLE * ratio;

		b.vx = cosf(a) * dir;
		b.vy = sinf(a) * dir;
	}
}

int	CheckBallCeilingFloorCollision(Ball& ball)
{
	return ball.top_border <= 0 || ball.bot_border >= WORLD_HEIGHT;
}

void	HandleCeilingFloorCollision(Ball& ball)
{
	if (CheckBallCeilingFloorCollision(ball))
	{
		ball.vy = -ball.vy;
	}
}

int	CheckBallWallCollision(Game& game)
{
	return (game.ball.left_border <= 0 || game.ball.right_border >= WORLD_WIDTH);
}

void	HandleBallWallCollision(Game& game)
{
	if (CheckBallWallCollision(game))
	{
		if (game.serve_count >= 2)
		{
			game.serve_dir = -game.serve_dir;
			game.serve_count = 0;
		}
		game.setBallService();
		game.serve_count++;
	}
}

void	UpdatePaddle(Paddle& paddle, float dt, int move_dir)
{
	float new_y = paddle.y - (dt * paddle.speed * move_dir);
	
	paddle.y = std::clamp(new_y, paddle.height / 2, WORLD_HEIGHT - (paddle.height / 2));
	paddle.top_border = paddle.y - (paddle.height / 2);
	paddle.bot_border = paddle.y + (paddle.height / 2);
}

void	UpdateBall(Ball& ball, float dt)
{
	ball.x += dt * ball.speed * ball.vx;
	ball.y += dt * ball.speed * ball.vy;
	ball.left_border = ball.x - ball.radius;
	ball.right_border = ball.x + ball.radius;
	ball.top_border = ball.y - ball.radius;
	ball.bot_border = ball.y + ball.radius;
}
