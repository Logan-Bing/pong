#include "Render.hpp"
#include "Element.hpp"
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

void	Render::DrawBall(ViewPort& view, PhysicsState& state)
{
	DrawCircle
		(
			INT(view.scaleXElement(state.ball.x)),
			INT(view.scaleYElement(state.ball.y)),
			view.scaleView(state.ball.radius),
			RED
		);
}

void	Render::DrawPaddle(ViewPort& view, PhysicsState& state)
{
	DrawRectangle
	(
		INT(view.scaleXElement(state.left_paddle.x - state.left_paddle.width / 2 )), 
		INT(view.scaleYElement(state.left_paddle.y - state.left_paddle.height / 2 )), 
		INT(view.scaleView(state.left_paddle.width)),
		INT(view.scaleView(state.left_paddle.height)),
		BLACK
	);
	DrawRectangle
	(
		INT(view.scaleXElement(state.right_paddle.x - state.right_paddle.width / 2 )), 
		INT(view.scaleYElement(state.right_paddle.y - state.right_paddle.height / 2 )), 
		INT(view.scaleView(state.right_paddle.width)),
		INT(view.scaleView(state.right_paddle.height)),
		BLACK
	);
}

void	Render::DrawGame(ViewPort& view, PhysicsState& state)
{
	Render::DrawBorder(view);
	Render::DrawBall(view, state);
	Render::DrawPaddle(view, state);
}

void	Render::DrawMenu()
{
	DrawRectangle(0, 0, INT(SCREEN_W), INT(SCREEN_H), BLACK);
	DrawText("Press enter to start the game", INT(SCREEN_W / 2), INT(SCREEN_H / 2), 20, WHITE);
}

void	Render::DrawPause(ViewPort& view, PhysicsState& state)
{
	Render::DrawGame(view, state);
	DrawRectangle(0, 0, INT(SCREEN_W), INT(SCREEN_H), Fade(BLACK, 0.2f));
}

std::string	GetOverlayInfos(PhysicsState& state, float dt)
{
	std::string infos;

	infos
		+= "FPS : "   + std::to_string(GetFPS()) + "\n" 
		+ "DT : "     + std::to_string(dt) + "\n"
		+ "BALL_X :" + std::to_string(state.ball.x) + "\n"
		+ "BALL_Y :" + std::to_string(state.ball.y) + "\n"
		+ "BALL_LEFT_BORDER :" + std::to_string(state.ball.left_border) + "\n"
		+ "BALL_RIGHT_BORDER :" + std::to_string(state.ball.right_border) + "\n"
		+ "BALL_TOP_BORDER :" + std::to_string(state.ball.top_border) + "\n"
		+ "BALL_BOT_BORDER :" + std::to_string(state.ball.bot_border) + "\n"
		+ "PL_TOP : " + std::to_string(state.left_paddle.top_border) + "\n"
		+ "PL_BOT : " + std::to_string(state.left_paddle.bot_border) + "\n"
		+ "PR_TOP : " + std::to_string(state.right_paddle.top_border) + "\n"
		+ "PR_BOT : " + std::to_string(state.right_paddle.bot_border);
	
	return infos;
}

void	Render::DrawOverlay(PhysicsState& state, float dt, Font& font)
{
	std::string infos(GetOverlayInfos(state, dt));

	Vector2 pos{0, 0};
	Vector2 size(MeasureTextEx(font, infos.c_str(), 16, 1));

	DrawRectangleV(pos, size, Fade(BLACK, 0.5f));
	DrawTextEx(font, infos.c_str(), pos, 16, 1, WHITE);
}
