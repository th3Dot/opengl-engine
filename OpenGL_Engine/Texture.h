#pragma once

#include <string>
#include <GLFW\glfw3.h>
#include <glad/glad.h>
#include <iostream>

class Texture2D
{
private:
	std::string fileName;

public:
	GLuint id;
	int width, height, nrChannels;
	unsigned char* data;

	Texture2D(std::string fileName);
	~Texture2D();

	void setParameter(GLenum parameter, GLint value);
	void setParameter(GLenum paramter, GLfloat * value);
	void loadTexture();
};
