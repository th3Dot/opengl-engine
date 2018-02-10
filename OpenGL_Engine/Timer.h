#pragma once
#include <GLFW\glfw3.h>

class Timer
{
private:
	int fpsCount = 0;
	int upsCount = 0;
	int fps = 0;
	int ups = 0;
	double loopStart = 0;
	double lastUpdate = glfwGetTime();

	void update();

public:
	Timer();
	~Timer();

	void notifyRender();
	void notifyUpdate();
};
