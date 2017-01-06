#include <GLFW/glfw3.h>
#include "io.h"
#include "log.h"
#include <stdbool.h>

bool keys[GLICHI_KEY_LAST] = { 0 };
bool keys_pressed[GLICHI_KEY_LAST] = { 0 };
bool keys_released[GLICHI_KEY_LAST] = { 0 };

extern GLFWwindow* window;

void _glichi_io_handle_key(int glichi_key, int key);

void glichi_io_update() {
	_glichi_io_handle_key(GLICHI_KEY_Z, GLFW_KEY_Z);
	_glichi_io_handle_key(GLICHI_KEY_X, GLFW_KEY_X);
	_glichi_io_handle_key(GLICHI_KEY_UP, GLFW_KEY_UP);
	_glichi_io_handle_key(GLICHI_KEY_LEFT, GLFW_KEY_LEFT);
	_glichi_io_handle_key(GLICHI_KEY_RIGHT, GLFW_KEY_RIGHT);
	_glichi_io_handle_key(GLICHI_KEY_DOWN, GLFW_KEY_DOWN);
}

void _glichi_io_handle_key(int glichi_key, int gl_key) {
	int state = glfwGetKey(window, gl_key);
	if (state != GLFW_RELEASE && keys[glichi_key] == false) {
		// key was not released, and it's state is false
		// this means key was just pressed
		keys_pressed[glichi_key] = true;
		keys_released[glichi_key] = false;
		GLICHI_INFO("%s Just pressed", glichi_key_str(glichi_key));
	}

	if (state == GLFW_RELEASE && keys[glichi_key] == true) {
		keys_pressed[glichi_key] = false;
		keys_released[glichi_key] = true;
		GLICHI_INFO("%s Just released", glichi_key_str(glichi_key));
	}

	keys[glichi_key] = state != GLFW_RELEASE;
}