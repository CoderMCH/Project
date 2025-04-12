#pragma once

#include <glad/glad.h>

class EBO
{
public:
	GLuint ID;
	EBO(GLfloat* indices, GLsizeiptr size);

	void bind();
	void unbind();
	void deleteEBO();
};
