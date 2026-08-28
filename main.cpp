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
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// update
		float dt = GetFrameTime();
		ClearBackground(WHITE);

		// draw
		BeginDrawing();
			DrawText("Hello World", SCREEN_W / 2, SCREEN_H / 2, 20, GRAY);
			DrawText("hello", 10, 10, 20, GRAY);
		EndDrawing();
	}
}
