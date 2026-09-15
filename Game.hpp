#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Element.hpp"
#include <raylib.h>

class IGameState;

class Game
{
	public:
	  IGameState *state;
	  Paddle	left_paddle;
	  Paddle	right_paddle;
	  Ball		ball;
	  float		serve_dir;
	  int 		left_paddle_move_dir;
	  int 		right_paddle_move_dir;
	  int		serve_count;
	  int		reset;

	  Game();
	  void	setBallService();
	  void	HandleInput(KeyboardKey key);
	  void	render();
	  bool operator==(const Game& rhs) const;
};

#endif
