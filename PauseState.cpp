#include "PauseState.hpp"
#include "InSimulationState.hpp"

PauseState IGameState::pause;

PauseState::~PauseState(){}

void PauseState::HandleInput(Game& game, Input input)
{
	if (input == TOGGLE_PAUSE)
	{
		game.state = &IGameState::in_simulation;
	}
}

void PauseState::FixedUpdate(Game& game, float deltatime)
{
	(void)game;
	(void)deltatime;
}

void PauseState::render(Game& game, ViewPort& view)
{
	Render::DrawPause(game, view);
}
