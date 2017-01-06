#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "systems.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

GLFWwindow* window;
int should_close = 0;

void _glichi_systems_error_callback(int error, const char* description);
void _glichi_systems_close_callback(GLFWwindow* window);

int glichi_systems_init() {
	int result = glfwInit();
	if (!result) {
		// TODO(justin): handle failure
	}

	glfwSetErrorCallback(&_glichi_systems_error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(720, 480, "GLFW Setup", 0, 0);
	if (!window) {
		// TODO(justin): handle failure
	}
	glfwSetWindowCloseCallback(window, _glichi_systems_close_callback);

	// in order to use the opengl api context must be active.
	glfwMakeContextCurrent(window);
	glewInit();

	// TODO(justin): allow configuration of cursor mode setup.
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	GLICHI_INFO("*** OpenGL Version: %s ***\n", glGetString(GL_VERSION));

	return result;
}

int glichi_systems_should_close() {
	return should_close;
}

void glichi_systems_draw_begin() {
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void glichi_systems_draw_end() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void _glichi_systems_error_callback(int error, const char* description) {
	UNUSED(error);
	fprintf(stderr, "Error: %s\n", description);
}

void _glichi_systems_close_callback(GLFWwindow* window) {
	UNUSED(window);
	should_close = 1;
}