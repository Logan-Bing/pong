#include "Element.hpp"
#include "header.hpp"

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
	Game GAME;
	World w;

	GAME.InitGameElement();

	// Window init
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(SCREEN_W, SCREEN_H, "Pong");
    SetWindowMinSize(WORLD_WIDTH, WORLD_HEIGHT);
	SetTargetFPS(FPS);
	int serve_count = 1;
	int serve_dir = 1;

	while (!WindowShouldClose())
	{
		GAME.dt = GetFrameTime();
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

		updatePaddle(GAME.left_paddle, GAME.dt, p_left_move_dir);
		updatePaddle(GAME.right_paddle, GAME.dt, p_right_move_dir);

		GAME.ball.x += GAME.dt * GAME.ball.speed * GAME.ball.vx;
		GAME.ball.y += GAME.dt * GAME.ball.speed * GAME.ball.vy;

		if (checkBallPaddleCollision(GAME.ball, GAME.right_paddle))
			handlePaddleBallCollision(GAME.ball, GAME.right_paddle, -1);
		if (checkBallPaddleCollision(GAME.ball, GAME.left_paddle))
			handlePaddleBallCollision(GAME.ball, GAME.left_paddle, 1);

		if (GAME.ball.y <= 0 || GAME.ball.y >= WORLD_HEIGHT)
			GAME.ball.vy = -GAME.ball.vy;

		if (GAME.ball.x <= 0 || GAME.ball.x >= WORLD_WIDTH)
		{
			if (serve_count >= 2)
			{
				serve_dir = -serve_dir;
				serve_count = 0;
			}
			setBallService(GAME.ball, serve_dir);
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
			DrawCircle(w.scaleX(GAME.ball.x), w.scaleY(GAME.ball.y), w.scaleRatio(GAME.ball.radius), RED);
			DrawRectangle(w.scaleX(GAME.left_paddle.x - (GAME.left_paddle.width / 2)), w.scaleY((GAME.left_paddle.y - GAME.left_paddle.height / 2)), w.scaleRatio(GAME.left_paddle.width), w.scaleRatio(GAME.left_paddle.height), BLACK);
			DrawRectangle(w.scaleX(GAME.right_paddle.x - (GAME.right_paddle.width / 2)), w.scaleY((GAME.right_paddle.y - GAME.right_paddle.height / 2)), w.scaleRatio(GAME.right_paddle.width), w.scaleRatio(GAME.right_paddle.height), BLACK);

			// OVERLAY
			Vector2 v {0, 0};
			if (IsKeyDown(KEY_TAB))
			{
				DrawRectangle(0, 0, MeasureText(formatOverlayText(GAME.dt, GAME.left_paddle, GAME.right_paddle).c_str(), 16), 150, Fade(BLACK, 0.8f));
				DrawTextEx(LoadFont("./Montserrat-Medium.ttf"), formatOverlayText(GAME.dt, GAME.left_paddle, GAME.right_paddle).c_str(), v, 16, 1, WHITE);
			}

		EndDrawing();
	}
	CloseWindow();
}
