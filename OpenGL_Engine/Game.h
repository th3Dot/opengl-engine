#pragma once
#include "Window.h"
#include "Timer.h"
#include "Renderer.h"

class Game
{
private:
	Timer* timer;

	void init();
	void dispose();

protected:
	Window* window;
	Renderer* renderer;

	Game(Window* window);

	void render(double alpha);
	void update();

	virtual void gameLoop() = 0;
public:
	void start();
	virtual ~Game();
};
