#include "MenuState.hpp"
#include "InSimulationState.hpp"

MenuState IGameState::menu;

MenuState::~MenuState(){}

void MenuState::HandleInput(Game& game, Input input)
{
	if (input == ENTER)
	{
		game.state = &IGameState::in_simulation;
	}
}

void MenuState::FixedUpdate(Game& game, float deltatime)
{
	(void)game;
	(void)deltatime;
}

void	MenuState::render(ViewPort& view, PhysicsState& state)
{
	(void)state;
	Render::DrawMenu(view);
}
