#include "InSimulationState.hpp"
#include "PauseState.hpp"

InSimulationState IGameState::in_simulation;

InSimulationState::~InSimulationState(){}

void InSimulationState::HandleInput(Game &game, Input input)
{
	if (input == TOGGLE_PAUSE)
	{
		game.state = &IGameState::pause;
	}
}

void InSimulationState::FixedUpdate(Game& game, float deltatime)
{
	ResolveCollisions(game);
	Integrate(game, deltatime);
}

void InSimulationState::render(ViewPort& view, PhysicsState& state)
{
	Render::DrawGame(view, state);
}
