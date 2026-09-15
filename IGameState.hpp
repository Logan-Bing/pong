#ifndef __IGAMESTATE_HPP__
#define __IGAMESTATE_HPP__

#include "Game.hpp"
#include "raylib.h"

class MenuState;

class IGameState
{
	public:
		static	MenuState menu;

		virtual ~IGameState();
		virtual void HandleInput(Game& game, KeyboardKey key);
		virtual void render();
};

#endif
