#ifndef __ISERVICESTATE_HPP__
#define __ISERVICESTATE_HPP__

#include "IGameState.hpp"

class ServiceState: public IGameState
{
	public:
		float timer = 0;
		~ServiceState();
		void HandleInput(Game &game, Input input) override;
		void FixedUpdate(Game& game, float deltatime) override;
		void render(ViewPort& view, PhysicsState& state) override;
};

#endif
