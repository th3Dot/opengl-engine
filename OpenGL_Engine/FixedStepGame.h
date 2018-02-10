#pragma once
#include <GLFW/glfw3.h>
#include "Game.h"
class FixedStepGame final : public Game
{
private:
	int ups;
	int fps;
	
public:
	FixedStepGame(Window* window, int ups, int fps);
	~FixedStepGame();

	void gameLoop() override;
};
