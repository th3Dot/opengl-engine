#pragma once
#include <GLFW\glfw3.h>

class Window
{
private:
	unsigned int windowHeight;
	unsigned int windowWidth;
	GLFWwindow* window;

public:
	Window(const unsigned int windowWidth, const unsigned int windowHeight);
	~Window() {
	};

	bool init();
	bool shouldClose();
	void processInput();
	void render();
	void terminate();
};
