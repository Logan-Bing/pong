#include "MenuState.hpp"

MenuState IGameState::menu;

void MenuState::HandleInput(Game& game, KeyboardKey key)
{
	if (IsKeyPressed(key))
	{
		
	}
}

void	MenuState::render()
{
	Render::DrawMenu();
}
