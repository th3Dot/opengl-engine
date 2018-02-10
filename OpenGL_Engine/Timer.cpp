#include "Timer.h"
#include <iostream>


Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::notifyUpdate() {
	ups = upsCount++;
	update();
}

void Timer::notifyRender() {
	fps = fpsCount++;
	update();
}

void Timer::update() {
	double currentTime = glfwGetTime();
	if (currentTime - lastUpdate >= 1) {
		fps = fpsCount;
		ups = upsCount;

		fpsCount = 0;
		upsCount = 0;

		lastUpdate = currentTime;

		std::cout << "FPS: " << fps << " UPS: " << ups << std::endl;
	}
}
