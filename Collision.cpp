#include "header.hpp"

int	checkBallPaddleCollision(Ball& b, Paddle& p)
{
	// Pour savoir c'est quelle raquette
	float ball_border_pos = p.x > (WORLD_WIDTH / 2) ? b.x + b.radius : b.x - b.radius;

	return (
			ball_border_pos >= p.left_border &&
			ball_border_pos <= p.right_border &&
			b.y >= p.top_border &&
		 	b.y <= p.bot_border
		 );
}
