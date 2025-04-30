#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum pixelType) {
	type = texType;

	int imgWidth, imgHeight, imgColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* imgBytes = stbi_load(image, &imgWidth, &imgHeight, &imgColCh, 0);

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	// Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configures the way the texture repeats (if it does at all)
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
	// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	int GL_COL_CH = 0;
	switch (imgColCh)
	{
	case 3:
		GL_COL_CH = GL_RGB;
		break;
	case 4:
		GL_COL_CH = GL_RGBA;
		break;
	default:
		cout << "col channel break" << endl;
		return;
	}
	glTexImage2D(texType, 0, GL_COL_CH, imgWidth, imgHeight, 0, GL_COL_CH, pixelType, imgBytes);
	glGenerateMipmap(texType);

	stbi_image_free(imgBytes);
	glBindTexture(texType, 0);
}
// Assigns a texture unit to a texture
void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.activate();
	// Sets the value of the uniform
	glUniform1i(texUni, unit);
}
// Binds a texture
void Texture::bind() {
	glBindTexture(type, ID);
}
// Unbinds a texture
void Texture::unbind() {
	glBindTexture(type, 0);
}
// Deletes a texture
void Texture::deleteTex() {
	glDeleteTextures(1, &ID);
}