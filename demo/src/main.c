#include <glichi/systems.h>
#include <glichi/io.h>
#include <stdio.h>

int main() {
	glichi_systems_init();

	int running = 1;

	while(running) {
		glichi_io_update();

		glichi_systems_draw_begin();
		glichi_systems_draw_end();
		running = !glichi_systems_should_close();
	}

	return 0;
}