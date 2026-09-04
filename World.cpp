#include "World.hpp"

World::World(): ratio(0), offset_x(0), offset_y(0){}

void	World::updateWorldRatio(float width, float height)
{
	float height_ratio = height / WORLD_HEIGHT;
	float width_ratio = width / WORLD_WIDTH;

	offset_x = 0;
	offset_y = 0;

	if (width_ratio < height_ratio)
	{
		ratio = width_ratio;
		offset_y = (height - WORLD_HEIGHT * ratio) / 2;
	}
	else
	{
		ratio = height_ratio;
		offset_x = (width - WORLD_WIDTH * ratio) / 2;
	}
}

float World::scaleRatio(float value)
{
	return (value * ratio);
}

float	World::scaleX(float value)
{
	return value * ratio + offset_x;
}

float	World::scaleY(float value)
{
	return value * ratio + offset_y;
}
