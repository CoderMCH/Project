#include "Object.h"

Object::Object() {
	GLfloat a_vertices[] = {
		//     COORD		     /        COLORS      /   TexCoord  //
		//  x ->, y^, -z = far from camera
		-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
		 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
		 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
		 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
	};

	stride = 8;
	offPos = 0;
	offCol = 3;
	offTex = 6;

	int len = sizeof(a_vertices) / sizeof(GLfloat);
	for (int i = 0; i < len; i++) {
		vertices.push_back(a_vertices[i]);
	}

	GLuint a_indices[] = {
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};

	len = sizeof(a_indices) / sizeof(GLuint);
	for (int i = 0; i < len; i++) {
		indices.push_back(a_indices[i]);
	}

	tex = string("resources//master_chef_helmet.jpg");
}
Object::~Object() {}

vector<GLfloat> Object::getVertices() {
	return vertices;
}
vector<GLuint> Object::getIndices() {
	return indices;
}
int Object::getStride() {
	return stride;
}
int Object::getOffPos() {
	return offPos;
}
int Object::getOffCol() {
	return offCol;
}
int Object::getOffTex() {
	return offTex;
}
string Object::getTex() {
	return tex;
}
