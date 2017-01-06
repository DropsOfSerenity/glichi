#ifndef GLICHI_SYSTEMS_H_
#define GLICHI_SYSTEMS_H_

#define UNUSED(x) (void)(x)

int glichi_systems_init();
int glichi_systems_should_close();
void glichi_systems_draw_begin();
void glichi_systems_draw_end();

#endif