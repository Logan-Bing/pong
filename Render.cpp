#include "Render.hpp"
#include "Game.hpp"
#include "ViewPort.hpp"
#include <raylib.h>
#include <string>

constexpr int	INT(float v)
{
	return static_cast<int>(v);
}

void	Render::DrawBorder(ViewPort& view)
{
	DrawRectangle(0, 0, INT(view.screenW), INT(view.offsetY), GRAY);
	DrawRectangle(0,INT(view.offsetY + WORLD_HEIGHT * view.ratio), INT(view.screenW), INT(view.offsetY), GRAY);
	// DrawRectangle(0, 0,INT(view.offsetX), INT(view.screenH), GRAY);
	// DrawRectangle(INT(view.offsetX + WORLD_WIDTH * view.ratio), 0, INT(view.offsetX), INT(view.screenH), GRAY);
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
			INT(view.scaleXElement(paddle.x - paddle.width / 2 )), 
			INT(view.scaleYElement(paddle.y - paddle.height / 2 )), 
			INT(view.scaleView(paddle.width)),
			INT(view.scaleView(paddle.height)),
			BLACK
		);
}

void	Render::DrawMenu()
{
	DrawRectangle(0, 0, SCREEN_W, SCREEN_H, BLACK);
	DrawText("Press enter to start the game", SCREEN_W / 2, SCREEN_H / 2, 20, WHITE);
}

std::string	GetOverlayInfos(Game& game, float dt)
{
	std::string infos;

	infos
		+= "FPS : "   + std::to_string(GetFPS()) + "\n" 
		+ "DT : "     + std::to_string(dt) + "\n"
		+ "BALL_X :" + std::to_string(game.ball.x) + "\n"
		+ "BALL_Y :" + std::to_string(game.ball.y) + "\n"
		+ "BALL_LEFT_BORDER :" + std::to_string(game.ball.left_border) + "\n"
		+ "BALL_RIGHT_BORDER :" + std::to_string(game.ball.right_border) + "\n"
		+ "BALL_TOP_BORDER :" + std::to_string(game.ball.top_border) + "\n"
		+ "BALL_BOT_BORDER :" + std::to_string(game.ball.bot_border) + "\n"
		+ "PL_TOP : " + std::to_string(game.left_paddle.top_border) + "\n"
		+ "PL_BOT : " + std::to_string(game.left_paddle.bot_border) + "\n"
		+ "PR_TOP : " + std::to_string(game.right_paddle.top_border) + "\n"
		+ "PR_BOT : " + std::to_string(game.right_paddle.bot_border);
	
	return infos;
}

void	Render::DrawOverlay(Game& game, float dt, Font& font)
{
	std::string infos(GetOverlayInfos(game, dt));

	Vector2 pos{0, 0};
	Vector2 size(MeasureTextEx(font, infos.c_str(), 16, 1));

	DrawRectangleV(pos, size, Fade(BLACK, 0.5f));
	DrawTextEx(font, infos.c_str(), pos, 16, 1, WHITE);
}
