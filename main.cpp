#include "header.hpp"

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

		// update
		int p_left_move_dir = 0;
		int p_right_move_dir = 0;

		if (IsKeyDown(KEY_W)) p_left_move_dir = 1;
		else if (IsKeyDown(KEY_S)) p_left_move_dir = -1;

		if (IsKeyDown(KEY_UP)) p_right_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) p_right_move_dir = -1;

		UpdatePaddle(game.left_paddle, dt, p_left_move_dir);
		UpdatePaddle(game.right_paddle, dt, p_right_move_dir);

		game.ball.x += dt * game.ball.speed * game.ball.vx;
		game.ball.y += dt * game.ball.speed * game.ball.vy;

		HandleBallPaddleCollision(game.ball, game.right_paddle, -1);
		HandleBallPaddleCollision(game.ball, game.left_paddle, 1);
		HandleCellingFloorCollision(game.ball);

		if (game.ball.x <= 0 || game.ball.x >= WORLD_WIDTH)
		{
			if (game.serve_count >= 2)
			{
				game.serve_dir = -game.serve_dir;
				game.serve_count = 0;
			}
			game.setBallService();
			game.serve_count++;
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
				Render::DrawOverlay(game, dt, font);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
