#ifndef __PAUSESTATE_HPP__
#define __PAUSESTATE_HPP__

#include "IGameState.hpp"

class PauseState: public IGameState
{
	public:
		float timer = 0;
		~PauseState(void);
		void HandleInput(Game& game, Input input);
		void FixedUpdate(Game& game, float deltatime);
		void render(ViewPort& view, PhysicsState& state);
};

#endif
