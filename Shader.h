#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

using namespace std;

string getFileContents(const char* filename);

class Shader {
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);

	void activate();
	void deactivate();
};
