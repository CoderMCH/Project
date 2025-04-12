#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <Windows.h>

#include "Link.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

using namespace std;

class Rendering {
public:
	Rendering();
	Rendering(Link* link);
	~Rendering();

	void render();

private:
	Link* link = nullptr;
};
