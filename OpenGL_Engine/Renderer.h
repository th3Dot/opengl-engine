#pragma once
#ifndef __gl_h_
#include <glad/glad.h>
#endif

#include "Shader.h"
#include "Program.h"
#include "Texture.h"

class Renderer
{
private:
	GLuint * vaos;
	GLuint * vbos;
	GLuint * ebos;
	Shader * vertexShader;
	Shader * fragmentShader;
	Program * program;
	Texture2D * texture;

public:
	Renderer();
	~Renderer();

	void init();
	void dispose();
	void draw();
	void prepareProgram();
	void prepareVao();
};
