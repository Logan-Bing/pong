#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include "raylib.h"
#include "ViewPort.hpp"
#include "Game.hpp"

namespace Render
{
	  /*
	   * @brief Draw the border of the world side that's not fully the screen side
	   */
	  void	DrawBorder(ViewPort& view);

	  void	DrawBall(ViewPort& view, Game& game);
	  void	DrawPaddle(ViewPort& view, Paddle& paddle);
};


#endif
