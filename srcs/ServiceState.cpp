#include "ServiceState.hpp"
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

	if (IsKeyDown(KEY_W)) game.left_paddle_move_dir = 1;
	else if (IsKeyDown(KEY_S)) game.left_paddle_move_dir = -1;
	else game.left_paddle_move_dir = 0;

	if (IsKeyDown(KEY_UP)) game.right_paddle_move_dir = 1;
	else if (IsKeyDown(KEY_DOWN)) game.right_paddle_move_dir = -1;
	else game.right_paddle_move_dir = 0;

	UpdatePaddle(game.current_state.left_paddle, deltatime, game.left_paddle_move_dir);
	UpdatePaddle(game.current_state.right_paddle, deltatime, game.right_paddle_move_dir);


	if (timer <= 0)
		game.state = &IGameState::in_simulation;
}

void	ServiceState::render(ViewPort& view, PhysicsState& state)
{
	Render::DrawGame(view, state);
}
