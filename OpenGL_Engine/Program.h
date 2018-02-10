#pragma once
#include "Shader.h"

class Program
{
private:
	GLuint id;

public:
	Program();
	~Program();

	void attach(Shader* shader);
	void link();
	void use();
};
