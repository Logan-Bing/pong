#ifndef __IMENUSTATE_HPP__
#define __IMENUSTATE_HPP__

#include "IGameState.hpp"
#include "Render.hpp"

class MenuState: public IGameState
{
	public:
		void HandleInput(Game &game, KeyboardKey key) override;
		void render() override;
};

#endif
