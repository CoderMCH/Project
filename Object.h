#pragma once

#include <glad/glad.h>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Object {
public:
	Object();
	~Object();
	vector<GLfloat> getVertices();
	vector<GLuint> getIndices();
	int getStride();
	int getOffPos();
	int getOffCol();
	int getOffTex();
	string getTex();

private:
	vector<GLfloat> vertices;
	vector<GLuint> indices;
	int stride, offPos, offCol, offTex;
	string tex;
};
