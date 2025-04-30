#pragma once

#include "stb/stb_image.h"
#include "Shader.h"

using namespace std;

class Texture {
public:
	Texture(const char* image, GLenum texType, GLenum slot, GLenum pixelType);
	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void bind();
	// Unbinds a texture
	void unbind();
	// Deletes a texture
	void deleteTex();

	GLuint ID;
	GLenum type;
};