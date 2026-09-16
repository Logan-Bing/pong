#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include <iostream>
#include "Element.hpp"
#include "raylib.h"
#include "ViewPort.hpp"
#include "Game.hpp"


namespace Render
{
	  /*
	   * @brief Draw the border of the world side that's not fully the screen side
	   */
	  void	DrawBorder(ViewPort& view);
	  void	DrawBall(ViewPort& view, PhysicsState& state);
	  void	DrawPaddle(ViewPort& view, PhysicsState& state);
	  void	DrawGame(ViewPort& view, PhysicsState& state);

	  void	DrawOverlay(PhysicsState& state, float dt, Font& font);

	  void	DrawMenu(ViewPort& view);
	  void	DrawPause(ViewPort& view, PhysicsState& state);
};

std::string	GetOverlayInfos(Game& game, float dt);


#endif
