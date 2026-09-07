#ifndef __SIMULATION_HPP__
#define __SIMULATION_HPP__

#include "Game.hpp"
#include <algorithm>
#include <iostream>

int		CheckBallPaddleCollision(Ball& ball, Paddle& paddle);
void	HandleBallPaddleCollision(Ball& b, Paddle& p, int dir);

int		CheckBallCellingFloorCollision(Ball& ball);
void	HandleCellingFloorCollision(Ball& b);

int		CheckBallWallCollision(Game& game);
void	HandleBallWallCollision(Game& game);

void	UpdatePaddle(Paddle& p, float dt, int move_dir);

#endif
