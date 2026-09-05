#include "Render.hpp"
#include "Game.hpp"
#include "ViewPort.hpp"
#include <raylib.h>

constexpr int	INT(float v)
{
	return static_cast<int>(v);
}

void	Render::DrawBorder(ViewPort& view)
{
	DrawRectangle(0, 0, INT(view.screenW), INT(view.offsetY), GRAY);
	DrawRectangle(0,INT(view.offsetY + WORLD_HEIGHT * view.ratio), INT(view.screenW), INT(view.offsetY), GRAY);
	DrawRectangle(0, 0,INT(view.offsetX), INT(view.screenH), GRAY);
	DrawRectangle(INT(view.offsetX + WORLD_WIDTH * view.ratio), 0, INT(view.offsetX), INT(view.screenH), GRAY);
}

void	Render::DrawBall(ViewPort& view, Game& game)
{
	DrawCircle
		(
			INT(view.scaleXElement(game.ball.x)),
			INT(view.scaleYElement(game.ball.y)),
			view.scaleView(game.ball.radius),
			RED
		);
}

void	Render::DrawPaddle(ViewPort& view, Paddle& paddle)
{
	DrawRectangle
		(
			INT(view.scaleXElement(paddle.x) - (paddle.width / 2)), 
			INT(view.scaleYElement(paddle.y - paddle.height / 2)), 
			INT(view.scaleView(paddle.width)),
			INT(view.scaleView(paddle.height)),
			BLACK
		);
}
