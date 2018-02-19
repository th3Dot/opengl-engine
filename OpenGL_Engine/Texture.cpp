#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D(std::string fileName): fileName(fileName)
{
}


Texture2D::~Texture2D()
{
}

void Texture2D::setParameter(GLenum parameter, GLint value)
{
	glTexParameteri(GL_TEXTURE_2D, parameter, value);
}

void Texture2D::setParameter(GLenum parameter, GLfloat* value) {
	glTexParameterfv(GL_TEXTURE_2D, parameter, value);
}

void Texture2D::loadTexture()
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
	if (data) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
