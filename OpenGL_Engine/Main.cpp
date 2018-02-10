#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "FixedStepGame.h"

#include <iostream>

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	Game* game = new FixedStepGame(new Window(1200, 800), 120, 60);
	
	game->start();

	delete game;

	return 0;
}
