#include "Rendering.h"

# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

Rendering::Rendering() {
	cout << "Default Rendering" << endl;
};
Rendering::Rendering(Link* link) {
	cout << "Rendering created" << endl;
	this->link = link;
	cout << "obj has " << this->link->obj->getVertices().size() << " vertices" << endl;
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
	vector<GLfloat> vertices = link->obj->getVertices();
	vector<GLuint> indices = link->obj->getIndices();
	int stride = link->obj->getStride();
	int offPos = link->obj->getOffPos();
	int offCol = link->obj->getOffCol();
	int offTex = link->obj->getOffTex();

	// Generate Shader object using default.ver and default .frag
	Shader shaderProgram("default.vert", "default.frag");

	// Generate vertex array object and binds it
	VAO VAO1;
	VAO1.bind();

	// Generate vertex buffer object and link to vertices
	VBO VBO1((GLfloat*)vertices.data(), vertices.size()* sizeof(GLfloat));
	// Generate element buffer object and link to indices
	EBO EBO1((GLfloat*)indices.data(), indices.size() * sizeof(GLuint));

	// link VBO to VAO
	int a_size = stride * sizeof(GLfloat);
	VAO1.linkAttrib(VBO1, 0, 3, GL_FLOAT, a_size, (void*)offPos);
	VAO1.linkAttrib(VBO1, 1, 3, GL_FLOAT, a_size, (void*)(offCol * sizeof(GLfloat)));
	VAO1.linkAttrib(VBO1, 2, 2, GL_FLOAT, a_size, (void*)(offTex * sizeof(GLfloat)));
	VAO1.unbind();
	VBO1.unbind();
	EBO1.unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	GLuint rad = glGetUniformLocation(shaderProgram.ID, "rad");

	// Texture
	string file = link->obj->getTex();
	Texture tex(file.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_UNSIGNED_BYTE);
	tex.texUnit(shaderProgram, "tex0", 0);

	// not render planes behind
	glEnable(GL_DEPTH_TEST);

	// set angular speed
	float angular_speed = -M_PI/ 360;
	float theta = 0.0;
	float param = 0.0;

	// rendering loop
	while (!glfwWindowShouldClose(window)) {
		// set background color
		glClearColor(0.07f, 0.13f, 0.17f, 0.0f);
		// clean color buffer and assign new color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// activate shader
		shaderProgram.activate();
		glUniform1f(uniID, 0.0);

		// rotate pryamid along Y-axis 
		if (theta < -M_PI) theta += M_PI;
		glUniform1f(rad, theta += angular_speed);
		glGetUniformfv(shaderProgram.ID, rad, &param);
		cout << "expected rad: " << theta << ", actual rad: " << theta << endl;
		// bind texture
		tex.bind();
		// bind VAO
		VAO1.bind();
		
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

		// swap image into window
		glfwSwapBuffers(window);

		// take care of all glfw events
		glfwPollEvents();
	}

	// delete shader
	VAO1.deleteVAO();
	VBO1.deleteVBO();
	EBO1.deleteEBO();
	tex.deleteTex();
	shaderProgram.deactivate();

	// terminate window before ending the programe
	glfwDestroyWindow(window);
	// terminate GLFW before ending the program
	glfwTerminate();
};
