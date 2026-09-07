#include "Simulation.hpp"

int	CheckBallPaddleCollision(Ball& ball, Paddle& paddle)
{
	// Pour savoir c'est quelle raquette
	float ball_border_pos = paddle.x > (WORLD_WIDTH / 2) ? ball.x + ball.radius : ball.x - ball.radius;

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

int	CheckBallCellingFloorCollision(Ball& ball)
{
	return ball.y <= 0 || ball.y >= WORLD_HEIGHT;
}

void	HandleCellingFloorCollision(Ball& ball)
{
	if (CheckBallCellingFloorCollision(ball))
	{
		ball.vy = -ball.vy;
	}
}

int	CheckBallWallCollision(Game& game)
{
	return (game.ball.x <= 0 || game.ball.x >= WORLD_WIDTH);
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

void	UpdatePaddle(Paddle& p, float dt, int move_dir)
{
	float new_y = p.y - (dt * p.speed * move_dir);
	
	p.y = std::clamp(new_y, p.height / 2, WORLD_HEIGHT - (p.height / 2));
	p.top_border = p.y - (p.height / 2);
	p.bot_border = p.y + (p.height / 2);
}
