#include "Rendering.h"

using namespace std;

Rendering::Rendering() {
	cout << "Default Rendering" << endl;
};
Rendering::Rendering(Link* link) {
	cout << "Rendering created" << endl;
	this->link = link;
	cout << "obj has " << this->link->obj->getVerticesSize() << " vertices" << endl;
};
Rendering::~Rendering() {
	cout << "Rendering deleted" << endl;
};
void Rendering::render() {
	glfwInit();

	// openGL verion
	int ver_openGL = 4;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ver_openGL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ver_openGL);
	// core profile of openGL
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window
	int width = 800;
	int height = 800;
	const char* title = "Rendering";
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		cout << "window failed" << endl;
		glfwTerminate();
		return;
	}

	// set current window
	glfwMakeContextCurrent(window);

	// load openGL
	gladLoadGL();

	// set image to window size
	glViewport(0, 0, width, height);

	// get obj vertices
	int vertices_size = this->link->obj->getVerticesSize();
	void* vertices = this->link->obj->getVertices();
	int indeices_size = this->link->obj->getIndicesSize();
	void* indices = this->link->obj->getIndices();

	// Generate Shader object using default.ver and default .frag
	Shader shaderProgram("default.vert", "default.frag");

	// Generate vertex array object and binds it
	VAO VAO1;
	VAO1.bind();

	// Generate vertex buffer object and link to vertices
	VBO VBO1((GLfloat*)vertices, vertices_size * sizeof(GLfloat));
	// Generate element buffer object and link to indices
	EBO EBO1((GLfloat*)indices, indeices_size * sizeof(GLuint));

	// link VBO to VAO
	VAO1.linkVBO(VBO1, 0);
	VAO1.unbind();
	VBO1.unbind();
	EBO1.unbind();

	// rendering loop
	while (!glfwWindowShouldClose(window)) {
		// set color
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clean color buffer and assign new color
		glClear(GL_COLOR_BUFFER_BIT);

		// activate shader
		shaderProgram.activate();
		// bind VAO
		VAO1.bind();
		
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		// swap image into window
		glfwSwapBuffers(window);

		// take care of all glfw events
		glfwPollEvents();
	}

	// delete shader
	VAO1.deleteVAO();
	VBO1.deleteVBO();
	EBO1.deleteEBO();
	shaderProgram.deactivate();

	// terminate window before ending the programe
	glfwDestroyWindow(window);
	// terminate GLFW before ending the program
	glfwTerminate();
};
