#include "Simulation.hpp"
#include "header.hpp"
#include <raylib.h>

// Créer un jeu de relfexe pour avoir un bonus
// Colorier les bordure de l'offset en noir

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

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
	Font font = LoadFont("./Montserrat-Medium.ttf");
    SetWindowMinSize(WORLD_WIDTH, WORLD_HEIGHT);
	SetTargetFPS(FPS);

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		view.screenW = GetScreenWidth();
		view.screenH = GetScreenHeight();
		view.UpdateRatioWorldScreen();

		game.left_paddle_move_dir = 0;
		game.right_paddle_move_dir = 0;

		if (IsKeyDown(KEY_W)) game.left_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_S)) game.left_paddle_move_dir = -1;

		if (IsKeyDown(KEY_UP)) game.right_paddle_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) game.right_paddle_move_dir = -1;

		// update
		integrate(game, dt);

		// modifie vitesse
		HandleBallPaddleCollision(game.ball, game.right_paddle, -1);
		HandleBallPaddleCollision(game.ball, game.left_paddle, 1);
		HandleCeilingFloorCollision(game.ball);
		HandleBallWallCollision(game);

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
				Render::DrawOverlay(game, dt, font);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
