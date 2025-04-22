#pragma once

#include <glad/glad.h>
#include <math.h>
#include <vector>

using namespace std;

class Object {
public:
	Object();
	~Object();
	vector<GLfloat> getVertices();
	vector<GLuint> getIndices();

private:
	vector<GLfloat> vertices;
	vector<GLuint> indices;
};
