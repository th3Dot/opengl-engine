#include "Renderer.h"


Renderer::Renderer() : vbos(new GLuint[3]), vaos(new GLuint[3])
{
}


Renderer::~Renderer()
{
	delete[] vaos;
	delete[] vbos;
}

void Renderer::init() {
	program = new Program();
	vertexShader = new Shader("vertex.shader", 0);
	fragmentShader = new Shader("fragment.shader", 1);

	prepareProgram();
	prepareVao();
}

void Renderer::dispose() {
	vertexShader->dispose();
	fragmentShader->dispose();

	delete program;
	delete vertexShader;
	delete fragmentShader;
}

void Renderer::draw() {
	program->use();
	glBindVertexArray(vaos[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Renderer::prepareProgram() {
	program->attach(vertexShader);
	program->attach(fragmentShader);
	program->link();
}

void Renderer::prepareVao() {
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	glGenVertexArrays(3, vaos);
	glGenBuffers(3, vbos);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(vaos[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}
