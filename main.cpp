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


		if (IsKeyDown(KEY_W)) game.left_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_S)) game.left_paddle_move_dir = -1;
		else game.left_paddle_move_dir = 0;

		if (IsKeyDown(KEY_UP)) game.right_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) game.right_paddle_move_dir = -1;
		else game.right_paddle_move_dir = 0;

		RunSimulation(game, frameTime, accumulator);

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
				Render::DrawOverlay(game, frameTime, font);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
