#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include "Simulation.hpp"
#include "utils.hpp"
#include "Element.hpp"
#include "ViewPort.hpp"

void	ResetPaddlePos(Paddle& paddle)
{
	paddle.y = BASE_PADDLE_HEIGHT / 2;
	paddle.top_border = 0;
	paddle.bot_border = BASE_PADDLE_HEIGHT;
}

int	CompFloat(float a, float b, float diff)
{
	return fabs(a - b) < diff;
}

void	PrintTestTilte(const std::string& str)
{
	std::cout << BOLD_BLACK << BG_WHITE << "----" + str + "----" << RESET << std::endl;
}

int	TestElapsedTime()
{
	int ret = 0;

	Paddle paddle
	{
		.left_border = 	0,
		.right_border = 0,
		.top_border =	0,
		.bot_border =	BASE_PADDLE_HEIGHT,
		.x	=			0,
		.y =			BASE_PADDLE_HEIGHT / 2,
		.width =		BASE_PADDLE_WIDTH,
		.height =		BASE_PADDLE_HEIGHT,
		.speed	=		BASE_PADDLE_SPEED
	};

	PrintTestTilte("ELAPSED TIME");

	std::vector<float> dts =
	{
		1.0f/30, 
		1.0f/60, 
		1.0f/120, 
		1.0f/240
	};
	std::vector<float> times;

	int count = 0;
	for (auto iter = dts.begin(); iter != dts.end(); iter++)
	{
		while (paddle.bot_border != WORLD_HEIGHT)
		{
			UpdatePaddle(paddle, *iter, -1);
			count++;
		}
		times.push_back(count * (*iter));
		ResetPaddlePos(paddle);
		count = 0;
	}

	for (std::size_t i = 1; i < times.size(); i++)
	{
		if (!CompFloat(times[i - 1], times[i], dts.front()))
		{
			std::cout << RED << "FAILED: ";
			std::cout << times[i - 1] << "!=" << times[i] << std::endl;
			ret = 1;
		}
		else
		{
			std::cout << GREEN << "SUCCESS: ";
			std::cout << times[i - 1] << " == " << times[i] << std::endl;
		}
		std::cout << RESET;
	}

	return (ret);
}

int	TestFloorCeilingCollision()
{
	Game game;
	int boundary_touch = 0;
	int hit_ceiling = 0;
	int hit_floor = 0;

	game.ball.vx = 0;
	game.ball.vy = -1;

	PrintTestTilte("FLOOR - CELLING COLLISION");

	while (boundary_touch < 1000)
	{
		UpdateBall(game.ball, 1.0f/60);
		if (game.ball.top_border <= 0)
		{
			hit_ceiling++;
			hit_floor = 0;
			boundary_touch++;
		}
		if (game.ball.bot_border >= WORLD_HEIGHT)
		{
			hit_floor++;
			hit_ceiling = 0;
			boundary_touch++;
		}
		if (hit_floor > 1 || hit_ceiling > 1)
		{
			std::string err = hit_floor > 1 ? "FLOOR get hit more than once" : "CEILING get hit more than once";
			std::cout << RED << "ERROR: " << err << RESET << std::endl;
			return 1;
		}
		HandleCeilingFloorCollision(game.ball);
	}

	std::cout << GREEN << "SUCCESS" << RESET << std::endl;
	return 0;
}

int main()
{
	return (TestElapsedTime() || TestFloorCeilingCollision());
}
