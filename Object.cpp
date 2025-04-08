#include "Object.h"

Object::Object() {}
Object::~Object() {}
GLfloat* Object::getVertices() {
	return this->vertices;
}
int Object::getVerticesSize() {
	return sizeof(this->vertices)/sizeof(GLfloat);
}
