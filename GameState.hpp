#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "Game.hpp"

enum State
{
	STATE_MENU,
	STATE_INGAME,
	STATE_PAUSE,
	STATE_SERVICE,
	STATE_RESULT
};

class GameState
{
	public:
		virtual ~GameState();
		virtual void HandleInput(Game& game);
};

#endif
