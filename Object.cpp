#include "Object.h"

Object::Object() {
	GLfloat a_vertices[] =
	{	//     COORDINATES     /        COLORS    / Texture Coor  
		-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f,		// Lower left corner
		-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f,		// Upper left corner
		 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f,		// Upper right corner
		 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f,		// Lower right corner
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
		0, 2, 1, // Upper triangle
		0, 3, 2 // Lower triangle
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
