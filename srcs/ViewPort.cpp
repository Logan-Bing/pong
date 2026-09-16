#include "ViewPort.hpp"

ViewPort::ViewPort(): ratio(0), offsetX(0), offsetY(0){}

float ViewPort::UpdateRatioWorldScreen()
{
	float height_ratio = screenH / WORLD_HEIGHT;
	float width_ratio = screenW / WORLD_WIDTH;

	offsetX = 0;
	offsetY = 0;

	if (width_ratio < height_ratio)
	{
		ratio = width_ratio;
		offsetY = (screenH - WORLD_HEIGHT * ratio) / 2;
	}
	else
	{
		ratio = height_ratio;
		offsetX = (screenW - WORLD_WIDTH * ratio) / 2;
	}
	return ratio;
}

float ViewPort::scaleView(float value)
{
	return (value * ratio);
}

float	ViewPort::scaleXElement(float value)
{
	return value * ratio + offsetX;
}

float	ViewPort::scaleYElement(float value)
{
	return value * ratio + offsetY;
}
