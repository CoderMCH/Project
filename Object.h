#pragma once

#include <glad/glad.h>

class Object {
public:
	Object();
	~Object();
	GLfloat* getVertices();
	int getVerticesSize();

private:
	int pos[6] = {0, 0, 0, 0, 0, 0};
	GLfloat vertices[9] = {
		-0.5, 0.0, 0.0,
		0.5, 0.0, 0.0,
		0.0, 1.0, 0.0
	};
	int sound = 0;
};
