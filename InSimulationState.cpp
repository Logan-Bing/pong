#include "InSimulationState.hpp"
#include "MenuState.hpp"
#include "Render.hpp"
#include "Simulation.hpp"
#include "ViewPort.hpp"
#include <raylib.h>

InSimulationState IGameState::in_simulation;

InSimulationState::~InSimulationState(){}

void InSimulationState::HandleInput(Game &game, KeyboardKey key)
{
	if (key == KEY_TAB)
	{
		// Changer par le menu pause
		game.state = &IGameState::menu;
	}
}

void InSimulationState::FixedUpdate(Game& game, float deltatime)
{
	if (IsKeyDown(KEY_W)) game.left_paddle_move_dir = 1;
	else if (IsKeyDown(KEY_S)) game.left_paddle_move_dir = -1;
	else game.left_paddle_move_dir = 0;

	if (IsKeyDown(KEY_UP)) game.right_paddle_move_dir = 1;
	else if (IsKeyDown(KEY_DOWN)) game.right_paddle_move_dir = -1;
	else game.right_paddle_move_dir = 0;

	ResolveCollisions(game);
	Integrate(game, deltatime);
}

void InSimulationState::render(Game& game, ViewPort& view)
{
	Render::DrawGame(game, view);
}
