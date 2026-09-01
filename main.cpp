#include <iostream>
#include "raylib.h"
#include "header.hpp"

// Entities 
// 	Paddle
// 	Ball
// 	Player
//	Bonus

int main()
{
	// Game init
	Paddle p_left { BASE_PADDLE_LEFT_X, BASE_PADDLE_Y, BASE_PADDLE_WIDTH, BASE_PADDLE_HEIGHT, BASE_PADDLE_SPEED};
	Paddle p_right {BASE_PADDLE_RIGHT_X, BASE_PADDLE_Y, BASE_PADDLE_WIDTH, BASE_PADDLE_HEIGHT, BASE_PADDLE_SPEED};
	Ball b { BASE_BALL_X, BASE_BALL_Y, 0, 0, BASE_BALL_RADIUS};

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
    SetWindowMinSize(320, 240);

	SetTargetFPS(FPS);


	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		int currentScreenWidth = GetScreenWidth();
		int currentScreenHeight = GetScreenHeight();

		// update
		float ratio = 0;
		float offset_x = 0;
		float offset_y = 0;
		float ratio_h = currentScreenHeight / TERRAIN_HEIGHT;
		float ratio_w = currentScreenWidth / TERRAIN_WIDTH;
		int w_full = 0;

		if (ratio_w < ratio_h)
		{
			ratio = ratio_w;
			offset_y = (currentScreenHeight - TERRAIN_HEIGHT * ratio) / 2;
			w_full = 1;
		}
		else
		{
			ratio = ratio_h;
			offset_x = (currentScreenWidth - TERRAIN_WIDTH * ratio) / 2;
		}


		// draw
		BeginDrawing();

			ClearBackground(WHITE);
			DrawCircle(b.x * ratio + offset_x, b.y * ratio + offset_y, b.radius * ratio, RED);
			DrawRectangle(p_left.x * ratio + offset_x, p_left.y * ratio + offset_y, p_left.width * ratio, p_left.height * ratio, BLACK);
			DrawRectangle(p_right.x * ratio + offset_x, p_right.y * ratio + offset_y, p_right.width * ratio, p_right.height * ratio, BLACK);
			DrawText(TextFormat("W: %d", currentScreenWidth ), 100, 100, 20, GRAY);
			DrawText(TextFormat("H: %d", currentScreenHeight), 100, 120, 20, GRAY);
			DrawText(TextFormat("W FULL: %d", w_full), 100, 140, 20, GRAY);
			DrawText(TextFormat("Ratio: %f", ratio), 100, 160, 20, GRAY);

		EndDrawing();
	}

	CloseWindow();
}
