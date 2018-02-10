#pragma once
#ifndef __gl_h_
#include <glad/glad.h>
#endif

#include "Shader.h"
#include "Program.h"

class Renderer
{
private:
	GLuint * vaos;
	GLuint * vbos;
	Shader * vertexShader;
	Shader * fragmentShader;
	Program * program;
public:
	Renderer();
	~Renderer();

	void init();
	void dispose();
	void draw();
	void prepareProgram();
	void prepareVao();
};
