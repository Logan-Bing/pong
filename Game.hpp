#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Element.hpp"

class Game
{
	public:
	  Paddle	left_paddle;
	  Paddle	right_paddle;
	  Ball		ball;
	  float		dt;

	  void InitGameElement();
};

#endif
