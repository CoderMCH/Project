#include "Object.h"

Object::Object() {}
Object::~Object() {
	delete this->pos;
	delete this->vertices;
	delete this->indices;
}
GLfloat* Object::getVertices() {
	return this->vertices;
}
int Object::getVerticesSize() {
	return sizeof(this->vertices)/sizeof(GLfloat);
}
GLuint* Object::getIndices() {
	return this->indices;
}
int Object::getIndicesSize() {
	return sizeof(this->indices) / sizeof(GLuint);
}

