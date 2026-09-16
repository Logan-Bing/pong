#ifndef __IGAMESTATE_HPP__
#define __IGAMESTATE_HPP__

#include "Element.hpp"
#include "Game.hpp"
#include "Render.hpp"
#include "Simulation.hpp"
#include "raylib.h"

class MenuState;
class InSimulationState;
class PauseState;
class ServiceState;

class IGameState
{
	public:
		static	MenuState 			menu;
		static	InSimulationState	in_simulation;
		static	PauseState			pause;
		static	ServiceState		service;

		virtual ~IGameState(){} ;
		virtual void HandleInput(Game& game, Input input) = 0;
		virtual void FixedUpdate(Game& game, float deltatime) = 0;
		virtual void render(ViewPort& view, PhysicsState& state) = 0;
};

#endif
