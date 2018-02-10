#pragma once
#include <iostream>
#include <fstream>
#include <string>
#ifndef __gl_h_
#include <glad/glad.h>
#endif

class Shader
{
public:
	GLuint id;

	Shader(std::string file, int type);
	~Shader();

	void dispose();
};
