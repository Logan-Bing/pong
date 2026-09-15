#include "Element.hpp"
#include "Render.hpp"
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
		view.screenW = GetScreenWidth();
		view.screenH = GetScreenHeight();
		view.UpdateRatioWorldScreen();

		float frameTime = GetFrameTime();
		frameTime = std::min(frameTime, FRAMETIME_LIMIT);

		accumulator += frameTime;

		while (accumulator >= FIXED_DT)
		{
			game.FixedUpdate(FIXED_DT);
			accumulator -= FIXED_DT;
		}

		Input current_key = static_cast<Input>(GetKeyPressed());

		if (current_key != 0)
			game.HandleInput(current_key);

		// draw
		BeginDrawing();

			ClearBackground(WHITE);

			game.render(view);

			// OVERLAY
			// if (IsKeyDown(KEY_TAB))
			// 	Render::DrawOverlay(game, frameTime, font);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
