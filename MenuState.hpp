#ifndef __IMENUSTATE_HPP__
#define __IMENUSTATE_HPP__

#include "IGameState.hpp"
#include "Render.hpp"

class MenuState: public IGameState
{
	public:
		~MenuState();
		void HandleInput(Game &game, KeyboardKey key) override;
		void FixedUpdate(Game& game, float deltatime) override;
		void render(Game& game, ViewPort& view) override;
};

#endif
