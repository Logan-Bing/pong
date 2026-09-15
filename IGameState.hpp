#ifndef __IGAMESTATE_HPP__
#define __IGAMESTATE_HPP__

#include "Game.hpp"
#include "raylib.h"

class MenuState;
class InSimulationState;

class IGameState
{
	public:
		static	MenuState 			menu;
		static	InSimulationState	in_simulation;

		virtual ~IGameState(){} ;
		virtual void HandleInput(Game& game, KeyboardKey key) = 0;
		virtual void FixedUpdate(Game& game, float deltatime) = 0;
		virtual void render(Game& game, ViewPort& view) = 0;
};

#endif
