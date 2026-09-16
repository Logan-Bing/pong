#include "Game.hpp"
#include "Element.hpp"
#include "MenuState.hpp"
#include "InSimulationState.hpp"
#include "ServiceState.hpp"
#include "ViewPort.hpp"

Game::Game():
	state(&IGameState::menu),
	current_state
	(
		{
			 .left_paddle = 
			{
				.left_border = 	BASE_PADDLE_LEFT_BORDER_LEFT,
				.right_border = BASE_PADDLE_LEFT_BORDER_RIGHT,
				.top_border =	BASE_PADDLE_TOP_BORDER,
				.bot_border =	BASE_PADDLE_BOT_BORDER,
				.x	=			BASE_PADDLE_LEFT_X,
				.y =			BASE_PADDLE_Y,
				.width =		BASE_PADDLE_WIDTH,
				.height =	BASE_PADDLE_HEIGHT,
				.speed	=	BASE_PADDLE_SPEED
			},
			.right_paddle = 
			{
				.left_border = 	BASE_PADDLE_RIGHT_BORDER_LEFT,
				.right_border = BASE_PADDLE_RIGHT_BORDER_RIGHT,
				.top_border =	BASE_PADDLE_TOP_BORDER,
				.bot_border =	BASE_PADDLE_BOT_BORDER,
				.x	=			BASE_PADDLE_RIGHT_X,
				.y =			BASE_PADDLE_Y,
				.width =		BASE_PADDLE_WIDTH,
				.height =	BASE_PADDLE_HEIGHT,
				.speed	=	BASE_PADDLE_SPEED
			},
			.ball = 
			{
				.left_border = BASE_BALL_LEFT_BORDER,
				.right_border = BASE_BALL_RIGHT_BORDER,
				.top_border = BASE_BALL_TOP_BORDER,
				.bot_border = BASE_BALL_BOT_BORDER,
				.x =		BASE_BALL_X,
				.y = 		BASE_BALL_Y,
				.vx =		1,
				.vy =		0,
				.radius =	BASE_BALL_RADIUS,
				.speed =	BASE_BALL_SPEED
			}
		}
	),
	previous_state(current_state),
	serve_dir(1.0f),
	left_paddle_move_dir(0),
	right_paddle_move_dir(0),
	serve_count(1),
	reset(0)
{}

void	Game::setBallService()
{
	IGameState::service.timer = 2.0f;
	state = &IGameState::service;
	current_state.ball.x = BASE_BALL_X;
	current_state.ball.y = BASE_BALL_Y;
	current_state.ball.vx = serve_dir;
	current_state.ball.vy = 0;
}

void	Game::HandleInput(Input input)
{
	state->HandleInput(*this, input);
}

void	Game::FixedUpdate(float deltatime)
{
	state->FixedUpdate(*this, deltatime);
}

void	Game::render(ViewPort& view, PhysicsState& physics_state)
{
	state->render(view, physics_state);
}

bool Game::operator==(const Game& rhs) const
{
	return current_state.ball.x == rhs.current_state.ball.x && current_state.ball.y == rhs.current_state.ball.y;
}
