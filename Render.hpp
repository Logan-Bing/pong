#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include <iostream>
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
	  void	DrawOverlay(Game& game, float dt, Font& font);
	  void	DrawMenu();
};

std::string	GetOverlayInfos(Game& game, float dt);


#endif
