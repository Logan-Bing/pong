#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Element.hpp"
#include "ViewPort.hpp"
#include <raylib.h>

class IGameState;

class Game
{
	public:
	  IGameState *state;

	  PhysicsState current_state;
	  PhysicsState previous_state;

	  // Paddle	left_paddle;
	  // Paddle	right_paddle;
	  // Ball		ball;

	  float		serve_dir;
	  int 		left_paddle_move_dir;
	  int 		right_paddle_move_dir;
	  int		serve_count;
	  int		reset;

	  Game();
	  void	setBallService();
	  void	HandleInput(Input input);
	  void	FixedUpdate(float deltatime);
	  void	render(ViewPort& view, PhysicsState& physics_state);
	  bool operator==(const Game& rhs) const;
};

#endif
