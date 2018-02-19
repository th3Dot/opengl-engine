#include "Renderer.h"


Renderer::Renderer() : vbos(new GLuint[3]), vaos(new GLuint[3]), ebos(new GLuint[3])
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
	texture = new Texture2D("container.jpg");

	prepareProgram();
	prepareVao();

	texture->loadTexture();
	texture->setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture->setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	texture->setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture->setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Renderer::dispose() {
	vertexShader->dispose();
	fragmentShader->dispose();

	delete program;
	delete vertexShader;
	delete fragmentShader;
	delete texture;
}

void Renderer::draw() {
	program->use();
	glBindTexture(GL_TEXTURE_2D, texture->id);
	glBindVertexArray(vaos[0]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::prepareProgram() {
	program->attach(vertexShader);
	program->attach(fragmentShader);
	program->link();
}

void Renderer::prepareVao() {
	float vertices[] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(3, vaos);
	glGenBuffers(3, vbos);
	glGenBuffers(3, ebos);

	glBindVertexArray(vaos[0]);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebos[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}
