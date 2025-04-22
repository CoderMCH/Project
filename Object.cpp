#include "Object.h"

Object::Object() {
	GLfloat a_vertices[] =
	{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
	};

	int len = sizeof(a_vertices) / sizeof(GLfloat);
	for (int i = 0; i < len; i++) {
		vertices.push_back(a_vertices[i]);
	}

	GLuint a_indices[] = {
		0, 3, 5,	// lower left triangle
		3, 2, 4,	// lower right triangle
		5, 4, 1		// upper triangle
	};

	len = sizeof(a_indices) / sizeof(GLuint);
	for (int i = 0; i < len; i++) {
		indices.push_back(a_indices[i]);
	}
}
Object::~Object() {}

vector<GLfloat> Object::getVertices() {
	return vertices;
}
vector<GLuint> Object::getIndices() {
	return indices;
}
