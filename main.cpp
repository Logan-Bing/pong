#include "Element.hpp"
#include "Game.hpp"
#include "Render.hpp"
#include "ViewPort.hpp"
#include "header.hpp"
#include <raylib.h>

// Créer un jeu de relfexe pour avoir un bonus
// Colorier les bordure de l'offset en noir

// Entities 
// 	Paddle
// 	Ball
// 	Player
//	Bonus

void	updatePaddle(Paddle& p, float dt, int move_dir)
{
	float new_y = p.y - (dt * p.speed * move_dir);
	
	p.y = std::clamp(new_y, p.height / 2, WORLD_HEIGHT - (p.height / 2));
	p.top_border = p.y - (p.height / 2);
	p.bot_border = p.y + (p.height / 2);
}

void	setBallService(Ball& b, int dir)
{
	b.x = BASE_BALL_X;
	b.y = BASE_BALL_Y;
	b.vx = dir;
	b.vy = 0;
}

void	handlePaddleBallCollision(Ball& b, Paddle& p, int dir)
{
	// (min - v) / (max - min)
	float ratio = (b.y - p.y) / (p.height / 2);
	float a = ANGLE * ratio;

	// float d = a * 180 / M_PI;
	b.vx = cosf(a) * dir;
	b.vy = sinf(a) * dir;
}

std::string  formatOverlayText(float dt, Paddle& pl, Paddle& pr)
{
	std::string format;

	format
		+= "FPS : "   + std::to_string(GetFPS()) + "\n" 
		+ "DT : "     + std::to_string(dt) + "\n"
		+ "PL_TOP : " + std::to_string(pl.top_border) + "\n"
		+ "PL_BOT : " + std::to_string(pl.bot_border) + "\n"
		+ "PR_TOP : " + std::to_string(pr.top_border) + "\n"
		+ "PR_BOT : " + std::to_string(pr.bot_border);;

	return format;
}

int main()
{
	// Game init
	Game Game;
	ViewPort view;

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
    SetWindowMinSize(WORLD_WIDTH, WORLD_HEIGHT);
	SetTargetFPS(FPS);
	Font font = LoadFont("./Montserrat-Medium.ttf");
	int serve_count = 1;
	int serve_dir = 1;

	while (!WindowShouldClose())
	{
		Game.dt = GetFrameTime();
		view.screenW = GetScreenWidth();
		view.screenH = GetScreenHeight();
		view.UpdateRatioWorldScreen();

		// update
		int p_left_move_dir = 0;
		int p_right_move_dir = 0;

		if (IsKeyDown(KEY_W)) p_left_move_dir = 1;
		else if (IsKeyDown(KEY_S)) p_left_move_dir = -1;

		if (IsKeyDown(KEY_UP)) p_right_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) p_right_move_dir = -1;

		updatePaddle(Game.left_paddle, Game.dt, p_left_move_dir);
		updatePaddle(Game.right_paddle, Game.dt, p_right_move_dir);

		Game.ball.x += Game.dt * Game.ball.speed * Game.ball.vx;
		Game.ball.y += Game.dt * Game.ball.speed * Game.ball.vy;

		if (checkBallPaddleCollision(Game.ball, Game.right_paddle))
			handlePaddleBallCollision(Game.ball, Game.right_paddle, -1);
		if (checkBallPaddleCollision(Game.ball, Game.left_paddle))
			handlePaddleBallCollision(Game.ball, Game.left_paddle, 1);

		if (Game.ball.y <= 0 || Game.ball.y >= WORLD_HEIGHT)
			Game.ball.vy = -Game.ball.vy;

		if (Game.ball.x <= 0 || Game.ball.x >= WORLD_WIDTH)
		{
			if (serve_count >= 2)
			{
				serve_dir = -serve_dir;
				serve_count = 0;
			}
			setBallService(Game.ball, serve_dir);
			serve_count++;
		}

		// draw
		BeginDrawing();

			ClearBackground(WHITE);

			// Draw Border
			Render::DrawBorder(view);

			// Draw element
			Render::DrawBall(view, Game);
			Render::DrawPaddle(view, Game.left_paddle);
			Render::DrawPaddle(view, Game.right_paddle);
			// OVERLAY
			Vector2 v {0, 0};
			if (IsKeyDown(KEY_TAB))
			{
				// MeasureTextEx(font, formatOverlayText(Game.dt, ,), float fontSize, float spacing)
				DrawRectangle(0, 0, MeasureText(formatOverlayText(Game.dt, Game.left_paddle, Game.right_paddle).c_str(), 16), 150, Fade(BLACK, 0.8f));
				DrawTextEx(font, formatOverlayText(Game.dt, Game.left_paddle, Game.right_paddle).c_str(), v, 16, 1, WHITE);
			}

		EndDrawing();
	}
	CloseWindow();
	UnloadFont(font);
}
