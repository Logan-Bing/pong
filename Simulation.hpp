#ifndef __SIMULATION_HPP__
#define __SIMULATION_HPP__

#include "Game.hpp"
#include <algorithm>
#include <iostream>

constexpr float FIXED_DT = 0.01f;
constexpr float FRAMETIME_LIMIT = 0.25f;

int		CheckBallPaddleCollision(Ball& ball, Paddle& paddle);
void	HandleBallPaddleCollision(Ball& b, Paddle& p, int dir);

int		CheckBallCeilingFloorCollision(Ball& ball);
void	HandleCeilingFloorCollision(Ball& ball);

int		CheckBallWallCollision(Game& game);
void	HandleBallWallCollision(Game& game);

void	UpdatePaddle(Paddle& paddle, float dt, int move_dir);
void	UpdateBall(Game& game, float dt);

void	ResolveCollisions(Game& game);
void	Integrate(Game& game, float dt);

void	StepSimulation(Game& game);
void	RunSimulation(Game& game, float frameTime, float& accumulator);

#endif
