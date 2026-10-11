#include "PauseState.hpp"
#include "IGameState.hpp"
#include "InSimulationState.hpp"
#include "ServiceState.hpp"

PauseState IGameState::pause;

PauseState::~PauseState(){}

void PauseState::HandleInput(Game& game, Input input)
{
	if (input == TOGGLE_PAUSE)
	{
		if (IGameState::service.timer >= 0)
		{
			game.state = &IGameState::service;
			return;
		}
		game.state = &IGameState::in_simulation;
	}
}

void PauseState::FixedUpdate(Game& game, float deltatime)
{
	(void)game;
	(void)deltatime;
}

void PauseState::render(ViewPort& view, PhysicsState& state)
{
	Render::DrawPause(view, state);
}
