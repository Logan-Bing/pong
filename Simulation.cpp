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
		b.vy = sinf(a);
	}
}

int	CheckBallCeilingFloorCollision(Ball& ball)
{
	return ((ball.top_border <= 0 && ball.vy < 0) || (ball.bot_border >= WORLD_HEIGHT && ball.vy > 0));
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
		game.reset = 1;
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

void	UpdateBall(Game& game, float dt)
{
	if (game.reset)
	{
		game.setBallService();
		game.reset = 0;
	}

	game.ball.x += dt * game.ball.speed * game.ball.vx;
	game.ball.y += dt * game.ball.speed * game.ball.vy;
	game.ball.left_border = game.ball.x - game.ball.radius;
	game.ball.right_border = game.ball.x + game.ball.radius;
	game.ball.top_border = game.ball.y - game.ball.radius;
	game.ball.bot_border = game.ball.y + game.ball.radius;
}

void	DetectCollisions(Game& game)
{
	HandleBallPaddleCollision(game.ball, game.left_paddle, 1);
	HandleBallPaddleCollision(game.ball, game.right_paddle, -1);
	HandleCeilingFloorCollision(game.ball);
	HandleBallWallCollision(game);
}

void	integrate(Game& game, float dt)
{
		UpdatePaddle(game.left_paddle, dt, game.left_paddle_move_dir);
		UpdatePaddle(game.right_paddle, dt, game.right_paddle_move_dir);
		UpdateBall(game, dt);
}
