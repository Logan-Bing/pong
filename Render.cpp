#include "Render.hpp"
#include "World.hpp"

void	Render::DrawBorder(float width, float height, float borderXsize, float borderYsize)
{
	float world_width_scaled = WORLD_WIDTH * 


	DrawRectangle(0, 0, width, borderYsize, GRAY);
	DrawRectangle(0, borderYsize + w.scaleRatio(WORLD_HEIGHT), width, borderYsize, GRAY);
	DrawRectangle(0, 0, borderXsize, height, GRAY);
	DrawRectangle(borderXsize + w.scaleRatio(WORLD_WIDTH), 0, borderXsize, height, GRAY);
}
