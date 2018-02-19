#include "Program.h"

Program::Program()
{
	id = glCreateProgram();
}


Program::~Program()
{
}

void Program::attach(Shader* shader) {
	glAttachShader(id, shader->id);
}

void Program::link() {
	glLinkProgram(id);

	int success;
	char infoLog[512];

	glGetProgramiv(id, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

void Program::use() {
	glUseProgram(id);
}
