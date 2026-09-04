#ifndef __WORLD_HPP__
#define __WORLD_HPP__

constexpr float WORLD_WIDTH = 400.0f;
constexpr float WORLD_HEIGHT = 250.0f;

class World
{
  public:
	 World();
	/**
	 * @brief Changing the ratio depending on ScreenW and ScreenH
	 */
	void	updateWorldRatio(float width, float height);

	/**
	 * @brief Apply the scale ratio
	 */
	float scaleRatio(float value);

	/**
	 * @brief Apply ratio and offset (X) on value. (WORLD/u -> SCREEN/px)
	 */
	float	scaleX(float value);

	/**
	 * @brief Apply ratio and offset (Y) on value. (WORLD/u -> SCREEN/px)
	 */
	float	scaleY(float value);

	float ratio;
	float offset_x;
	float offset_y;

  private:
};

#endif
