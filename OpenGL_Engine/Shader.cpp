#include "Shader.h"



Shader::Shader(std::string file, int type)
{
	std::ifstream shaderFile (file);
	std::string contents((std::istreambuf_iterator<char>(shaderFile)),
		std::istreambuf_iterator<char>()
	);

	const char * shaderSource = contents.c_str();
	shaderFile.close();

	if (type == 0) {
		id = glCreateShader(GL_VERTEX_SHADER);
	}
	else {
		id = glCreateShader(GL_FRAGMENT_SHADER);
	}
	
	glShaderSource(id, 1, &shaderSource, NULL);
	glCompileShader(id);

	int success;
	char infoLog[512];

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

Shader::~Shader()
{
}

void Shader::dispose() {
	glDeleteShader(id);
}
