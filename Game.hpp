#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Element.hpp"

class Game
{
	public:
	  Paddle	left_paddle;
	  Paddle	right_paddle;
	  Ball		ball;
	  int 		left_paddle_move_dir;
	  int 		right_paddle_move_dir;
	  float		serve_dir;
	  int		serve_count;
	  int		reset;

	  Game();
	  void	setBallService();
	  bool operator==(const Game& rhs) const;
};

#endif
