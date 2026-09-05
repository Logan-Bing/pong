#ifndef __VIEWPORT_HPP__
#define __VIEWPORT_HPP__

constexpr float FPS = 60;
constexpr float SCREEN_W = 800.0f;
constexpr float SCREEN_H = 400.0f;

constexpr float WORLD_WIDTH = 400.0f;
constexpr float WORLD_HEIGHT = 250.0f;

class ViewPort
{
  public:
	 ViewPort();
	/**
	 * @brief Update the ratio depending on ScreenW and ScreenH
	 */
	float UpdateRatioWorldScreen();

	/**
	 * @brief Apply the scale ratio
	 */
	float scaleView(float value);

	/**
	 * @brief Apply ratio and offset (X) on value. (WORLD/u -> SCREEN/px)
	 */
	float	scaleXElement(float value);

	/**
	 * @brief Apply ratio and offset (Y) on value. (WORLD/u -> SCREEN/px)
	 */
	float	scaleYElement(float value);

	float screenW;
	float screenH;
	float ratio;
	float offsetX;
	float offsetY;

  private:
};

#endif
