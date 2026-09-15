#ifndef __INSIMULATIONSTATE_HPP__
#define __INSIMULATIONSTATE_HPP__

#include "IGameState.hpp"

class InSimulationState: public IGameState
{
	public:
		~InSimulationState();
		void HandleInput(Game &game, Input input) override;
		void render(Game& game, ViewPort& view) override;
		void FixedUpdate(Game& game, float deltatime) override;
};

#endif
