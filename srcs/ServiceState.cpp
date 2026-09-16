#include "ServiceState.hpp"
#include "Element.hpp"
#include "IGameState.hpp"
#include "PauseState.hpp"
#include "InSimulationState.hpp"

ServiceState IGameState::service;
ServiceState::~ServiceState(){}

void ServiceState::HandleInput(Game& game, Input input)
{
	(void)game;
	(void)input;
}
 
void ServiceState::FixedUpdate(Game& game, float deltatime)
{
	timer -= deltatime;

	UpdatePaddle(game.current_state.left_paddle, deltatime, game.left_paddle_move_dir);
	UpdatePaddle(game.current_state.right_paddle, deltatime, game.right_paddle_move_dir);

	if (timer <= 0)
		game.state = &IGameState::in_simulation;
}

void	ServiceState::render(ViewPort& view, PhysicsState& state)
{
	Render::DrawGame(view, state);
}
