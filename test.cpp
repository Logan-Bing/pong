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

int main()
{
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

	std::cout << BOLD_BLACK << BG_WHITE << "---- ELAPSED TIME TEST ----" << RESET << std::endl;

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
		}
		else
		{
			std::cout << GREEN << "SUCCESS: ";
			std::cout << times[i - 1] << " == " << times[i] << std::endl;
		}
		std::cout << RESET;
	}
}
