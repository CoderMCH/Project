#include "Rendering.h"

using namespace std;

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

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

	// shader programe
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// get obj vertices
	int a_size = this->link->obj->getVerticesSize();
	void* a = this->link->obj->getVertices();
	// swap obj vertices into buffer
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, a_size * sizeof(GLfloat), a, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	// set color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// clean color buffer and assign new color
	glClear(GL_COLOR_BUFFER_BIT);

	// swap image into window
	glfwSwapBuffers(window);

	// rendering loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		// take care of all glfw events
		glfwPollEvents();
	}

	// delete shader
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// terminate window before ending the programe
	glfwDestroyWindow(window);
	// terminate GLFW before ending the program
	glfwTerminate();
};
