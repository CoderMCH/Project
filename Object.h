#pragma once

#include <glad/glad.h>
#include <math.h>

class Object {
public:
	Object();
	~Object();
	GLfloat* getVertices();
	int getVerticesSize();
	GLuint* getIndices();
	int getIndicesSize();

private:
	int pos[6] = {0, 0, 0, 0, 0, 0};
	GLfloat vertices[18] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,	// lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	// upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// inner down
	};
	GLuint indices[9] = {
		0, 3, 5,	// lower left triangle
		3, 2, 4,	// lower right triangle
		5, 4, 1		// upper triangle
	};
	int sound = 0;
};
