#ifndef __IMENUSTATE_HPP__
#define __IMENUSTATE_HPP__

#include "IGameState.hpp"

class MenuState: public IGameState
{
	public:
		~MenuState();
		void HandleInput(Game &game, Input input) override;
		void FixedUpdate(Game& game, float deltatime) override;
		void render(ViewPort& view, PhysicsState& state) override;
};

#endif
