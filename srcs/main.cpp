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

float AlphaCalcul(float current_value, float previous_value, const float alpha)
{
	return current_value * alpha + previous_value * (1.0f - alpha);
}

PhysicsState ApplyAlphaOnState(PhysicsState& current_state, PhysicsState& previous_state,const float alpha)
{
	PhysicsState state(current_state);

	state.left_paddle.x = AlphaCalcul(current_state.left_paddle.x, previous_state.left_paddle.x, alpha);
	state.left_paddle.y = AlphaCalcul(current_state.left_paddle.y, previous_state.left_paddle.y, alpha);
	state.right_paddle.x = AlphaCalcul(current_state.right_paddle.x, previous_state.right_paddle.x, alpha);
	state.right_paddle.y = AlphaCalcul(current_state.right_paddle.y, previous_state.right_paddle.y, alpha);
	state.ball.x = AlphaCalcul(current_state.ball.x, previous_state.ball.x, alpha);
	state.ball.y = AlphaCalcul(current_state.ball.y, previous_state.ball.y, alpha);

	return state;
}

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
			game.previous_state = game.current_state;
			game.FixedUpdate(FIXED_DT);
			accumulator -= FIXED_DT;
		}

		Input current_key = static_cast<Input>(GetKeyPressed());
		if (current_key != 0)
			game.HandleInput(current_key);

		const float alpha = accumulator / FIXED_DT;

		PhysicsState state = ApplyAlphaOnState(game.current_state, game.previous_state, alpha);

		// draw
		BeginDrawing();

			ClearBackground(WHITE);

			game.render(view, state);

		EndDrawing();
	}
	UnloadFont(font);
	CloseWindow();
}
