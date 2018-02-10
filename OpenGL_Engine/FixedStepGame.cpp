#include "FixedStepGame.h"

double loopDuration(double& loopStart);

FixedStepGame::FixedStepGame(Window* window, int ups, int fps) : 
	Game(window), ups(ups), fps(fps)
{
}


FixedStepGame::~FixedStepGame()
{
}

void FixedStepGame::gameLoop() {
	double alpha = 0;
	double accumulator = 0;
	double dt = 1.0 / ups;
	double loopStart = glfwGetTime();
	
	while (!window->shouldClose())
	{
		accumulator += loopDuration(loopStart);

		while (accumulator >= dt) {
			accumulator -= dt;
			update();
		}

		alpha = accumulator / dt;

		render(alpha);
	}
}

double loopDuration(double& loopStart) {
	double duration = glfwGetTime() - loopStart;
	loopStart = loopStart + duration;
	return duration;
}
