#include "Simulation.hpp"
#include "header.hpp"
#include <raylib.h>

// Créer un jeu de relfexe pour avoir un bonus

// Entities 
// 	Paddle
// 	Ball
// 	Player
//	Bonus

int main()
{
	// Game init
	Game game;
	ViewPort view;
	float accumulator = 0;

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
	Font font = LoadFont("./Montserrat-Medium.ttf");
    SetWindowMinSize(WORLD_WIDTH, WORLD_HEIGHT);
	SetTargetFPS(FPS);

	while (!WindowShouldClose())
	{
		float frameTime = GetFrameTime();
		view.screenW = GetScreenWidth();
		view.screenH = GetScreenHeight();
		view.UpdateRatioWorldScreen();

		game.left_paddle_move_dir = 0;
		game.right_paddle_move_dir = 0;

		if (IsKeyDown(KEY_W)) game.left_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_S)) game.left_paddle_move_dir = -1;

		if (IsKeyDown(KEY_UP)) game.right_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) game.right_paddle_move_dir = -1;

		accumulator += frameTime;

		// update
		while (accumulator >= FIXED_DT)
		{
			HandleBallPaddleCollision(game.ball, game.right_paddle, -1);
			HandleBallPaddleCollision(game.ball, game.left_paddle, 1);
			HandleCeilingFloorCollision(game.ball);
			HandleBallWallCollision(game);

			integrate(game, FIXED_DT);
			accumulator -= FIXED_DT;
		}


		// draw
		BeginDrawing();

			ClearBackground(WHITE);

			// Draw Border
			Render::DrawBorder(view);

			// Draw element
			Render::DrawBall(view, game);
			Render::DrawPaddle(view, game.left_paddle);
			Render::DrawPaddle(view, game.right_paddle);

			// OVERLAY
			if (IsKeyDown(KEY_TAB))
				Render::DrawOverlay(game, FIXED_DT, font);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
