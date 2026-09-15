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

void	MenuState::render(Game& game, ViewPort& view)
{
	(void)game;
	(void)view;
	Render::DrawMenu();
}
