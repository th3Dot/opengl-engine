#include <iostream>
#include "Game.h"

Game::Game(Window* window) : window(window), timer(new Timer()), renderer(new Renderer())
{
}

Game::~Game()
{
	delete timer;
	delete renderer;
	delete window;
}

void Game::init() {
	if (!window->init()) {
		std::cout << "Failed to initialize Window" << std::endl;
		exit(-1);
	}

	renderer->init();
}

void Game::dispose() {
	window->terminate();
	renderer->dispose();
}

void Game::render(double alpha) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer->draw();

	window->render();
	timer->notifyRender();
}

void Game::update() {
	window->processInput();
	timer->notifyUpdate();
}

void Game::start() {
	init();
	gameLoop();
	dispose();
}
