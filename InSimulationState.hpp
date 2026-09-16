#ifndef __INSIMULATIONSTATE_HPP__
#define __INSIMULATIONSTATE_HPP__

#include "IGameState.hpp"

class InSimulationState: public IGameState
{
	public:
		~InSimulationState();
		void HandleInput(Game &game, Input input) override;
		void FixedUpdate(Game& game, float deltatime) override;
		void render(ViewPort& view, PhysicsState& state) override;
};

#endif
