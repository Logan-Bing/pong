#include "raylib.h"
#include <iostream>
#include "header.hpp"
#include "World.hpp"

// Créer un jeu de relfexe pour avoir un bonus
// Colorier les bordure de l'offset en noir

// Entities 
// 	Paddle
// 	Ball
// 	Player
//	Bonus


void	DrawScreenInfo(float height, World& w, float x, float y, float dt)
{
	DrawText(TextFormat(
					"SCREEN_H: %f\nWORLD_HEIGHT: %f\nDT: %f\n",
				height, WORLD_HEIGHT * w.ratio, dt), x, y, 20, RED);
}

void	DrawPaddleInfo(Paddle& p, float x, float y)
{
	DrawText(TextFormat(
				"top_border : %f\nbot_border : %f\n", 
				p.top_border, p.bot_border), x, y, 20, RED);
}

void	updatePaddle(Paddle& p, float dt, int move_dir)
{
	float new_y = p.y - (dt * p.speed * move_dir);
	if (new_y <= p.height / 2)
		p.y = p.height / 2;
	else if (new_y >= WORLD_HEIGHT - (p.height / 2))
		p.y = WORLD_HEIGHT - (p.height / 2);
	else
		p.y = new_y;
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

int main()
{
	// Game init
	World w;

	Paddle p_left
	{
		BASE_PADDLE_LEFT_BORDER_LEFT,
		BASE_PADDLE_LEFT_BORDER_RIGHT,
		BASE_PADDLE_TOP_BORDER,
		BASE_PADDLE_BOT_BORDER,
		BASE_PADDLE_LEFT_X,
		BASE_PADDLE_Y,
	BASE_PADDLE_WIDTH,
	BASE_PADDLE_HEIGHT,
	BASE_PADDLE_SPEED,
	};

	Paddle p_right
	{
		BASE_PADDLE_RIGHT_BORDER_LEFT,
		BASE_PADDLE_RIGHT_BORDER_RIGHT,
		BASE_PADDLE_TOP_BORDER,
		BASE_PADDLE_BOT_BORDER,
		BASE_PADDLE_RIGHT_X,
		BASE_PADDLE_Y,
	BASE_PADDLE_WIDTH,
	BASE_PADDLE_HEIGHT,
	BASE_PADDLE_SPEED,
	};

	Ball b 
	{
		BASE_BALL_X,
		BASE_BALL_Y,
		0.5,
		0,
		BASE_BALL_RADIUS,
		BASE_BALL_SPEED
	};

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
    SetWindowMinSize(WORLD_WIDTH, WORLD_HEIGHT);
	SetTargetFPS(FPS);
	int serve_count = 1;
	int serve_dir = 1;

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		float currentScreenWidth = GetScreenWidth();
		float currentScreenHeight = GetScreenHeight();
		w.updateWorldRatio(currentScreenWidth, currentScreenHeight);

		// update
		int p_left_move_dir = 0;
		int p_right_move_dir = 0;

		if (IsKeyDown(KEY_W)) p_left_move_dir = 1;
		else if (IsKeyDown(KEY_S)) p_left_move_dir = -1;

		if (IsKeyDown(KEY_UP)) p_right_move_dir = 1;
		else if (IsKeyDown(KEY_DOWN)) p_right_move_dir = -1;

		updatePaddle(p_left, dt, p_left_move_dir);
		updatePaddle(p_right, dt, p_right_move_dir);

		b.x += dt * b.speed * b.vx;
		b.y += dt * b.speed * b.vy;

		if (checkBallPaddleCollision(b, p_right))
			handlePaddleBallCollision(b, p_right, -1);
		if (checkBallPaddleCollision(b, p_left))
			handlePaddleBallCollision(b, p_left, 1);

		if (b.y <= 0 || b.y >= WORLD_HEIGHT)
			b.vy = -b.vy;

		if (b.x <= 0 || b.x >= WORLD_WIDTH)
		{
			if (serve_count >= 2)
			{
				serve_dir = -serve_dir;
				serve_count = 0;
			}
			setBallService(b, serve_dir);
			serve_count++;
		}

		// draw
		BeginDrawing();

			ClearBackground(WHITE);

			// Draw Border
			DrawRectangle(0, 0, currentScreenWidth, w.offset_y, GRAY);
			DrawRectangle(0, w.offset_y + w.scaleRatio(WORLD_HEIGHT), currentScreenWidth, w.offset_y , GRAY);
			DrawRectangle(0, 0, w.offset_x, currentScreenHeight, GRAY);
			DrawRectangle(w.offset_x + w.scaleRatio(WORLD_WIDTH), 0, w.offset_x, currentScreenHeight, GRAY);

			// Draw element
			DrawCircle(w.scaleX(b.x), w.scaleY(b.y), w.scaleRatio(b.radius), RED);
			DrawRectangle(w.scaleX(p_left.x - (p_left.width / 2)), w.scaleY((p_left.y - p_left.height / 2)), w.scaleRatio(p_left.width), w.scaleRatio(p_left.height), BLACK);
			DrawRectangle(w.scaleX(p_right.x - (p_right.width / 2)), w.scaleY((p_right.y - p_right.height / 2)), w.scaleRatio(p_right.width), w.scaleRatio(p_right.height), BLACK);

			// Debug
			// DrawPaddleInfo(p_right, 20, 20);
			// DrawScreenInfo(currentScreenHeight, w, 40, 80, dt);

		EndDrawing();
	}
	CloseWindow();
}
