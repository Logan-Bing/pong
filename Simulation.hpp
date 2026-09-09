#ifndef __SIMULATION_HPP__
#define __SIMULATION_HPP__

#include "Game.hpp"
#include <algorithm>
#include <iostream>

int		CheckBallPaddleCollision(Ball& ball, Paddle& paddle);
void	HandleBallPaddleCollision(Ball& b, Paddle& p, int dir);

int		CheckBallCeilingFloorCollision(Ball& ball);
void	HandleCeilingFloorCollision(Ball& ball);

int		CheckBallWallCollision(Game& game);
void	HandleBallWallCollision(Game& game);

void	UpdatePaddle(Paddle& paddle, float dt, int move_dir);
void	UpdateBall(Ball& ball, float dt);

#endif
